# 🔧 YouTube Videos - Complete Troubleshooting & Testing Guide

## 🎯 Quick Self-Diagnosis

Before diving into detailed troubleshooting, run this quick check:

```bash
# 1. Backend running?
curl http://localhost:8001/api/auth/youtube-videos/

# 2. Videos exist?
# Should return JSON with "count" > 0 if videos exist

# 3. Frontend loading?
# Open http://localhost:3000/hackathon-detail-sharxathon-2025 (or your URL)
# Check browser console (F12) for errors
```

---

## 📋 Complete Troubleshooting Guide

### ❌ Issue 1: Backend Returns 404 Not Found

**Error Message**:

```json
{
  "detail": "Not found."
}
```

**Causes & Solutions**:

#### 1a. Django app not migrated

```bash
cd "/Users/vishaljha/Desktop/neosharx/Backend flow"

# Check if migration applied
python manage.py showmigrations authentication | grep 0030

# If not applied, run:
python manage.py migrate
```

#### 1b. YouTube app not installed

```bash
# Edit settings.py, check INSTALLED_APPS includes:
# 'authentication'
# 'rest_framework'

# Restart server after changes
python manage.py runserver
```

#### 1c. URL patterns not configured

```bash
# Check urls.py has YouTube routes:
# path('youtube-videos/', views.youtube_videos_list, ...)
# path('hackathons/<slug>/videos/', views.get_sharxathon_videos, ...)

# Restart server
python manage.py runserver
```

---

### ❌ Issue 2: Backend Returns 500 Server Error

**Error Message**:

```
Internal Server Error (500)
```

**Diagnose**:

```bash
# Check backend logs (while running server):
tail -f /path/to/backend/logs.txt

# Or run with verbose output:
python manage.py runserver --verbosity 2

# Check database connection
python manage.py dbshell
```

**Solutions**:

#### 2a. Database not initialized

```bash
python manage.py makemigrations
python manage.py migrate
```

#### 2b. Missing dependencies

```bash
pip install djangorestframework
pip install django-cors-headers
pip install requests  # For thumbnail fetching
```

#### 2c. Invalid serializer

```bash
# Test serializer directly:
python manage.py shell

>>> from authentication.models import YouTubeVideo
>>> from authentication.serializers import YouTubeVideoSerializer
>>> videos = YouTubeVideo.objects.all()
>>> serializer = YouTubeVideoSerializer(videos, many=True)
>>> serializer.data
# Should show video data without errors
```

---

### ❌ Issue 3: Videos Not Appearing on Frontend

**Symptom**: Videos section shows "No videos" or is completely empty

**Check Points**:

#### 3a. Videos published in admin?

```bash
# Django shell test:
python manage.py shell

>>> from authentication.models import YouTubeVideo
>>> YouTubeVideo.objects.filter(is_published=True).count()
# Should return > 0

>>> YouTubeVideo.objects.filter(is_published=True).values_list('title', 'video_id')
# Should show your videos
```

#### 3b. Hackathon published?

```bash
python manage.py shell

>>> from authentication.models import SharXathon
>>> sh = SharXathon.objects.get(slug='sharxathon-2025')
>>> sh.is_published
# Should be True

>>> sh.videos.count()
# Should be > 0

>>> sh.videos.filter(is_published=True).count()
# Should be > 0 (same as above)
```

#### 3c. Frontend fetching correctly?

```javascript
// Open browser console (F12 → Console tab)
// Run this:

fetch("http://localhost:8001/api/auth/hackathons/sharxathon-2025/videos/")
  .then((r) => r.json())
  .then((data) => {
    console.log("Video count:", data.video_count);
    console.log("Videos:", data.videos);
    console.log("Full response:", data);
  });

// Should show videos in console
```

#### 3d. Frontend rendering correctly?

```javascript
// In browser console:

// Check if videos loaded into page:
document.querySelectorAll(".video-card").length;
// Should be > 0

// Check video grid element:
document.getElementById("videosGrid");
// Should exist and show cards

// Check for JavaScript errors:
// Any red errors in console = frontend issue
```

**Solutions**:

**Solution A - Publish videos**:

1. Go to Django admin
2. YouTube Videos section
3. Open video
4. Check "Is Published" ✓
5. Save

**Solution B - Publish hackathon**:

1. Go to Django admin
2. SharXathons section
3. Open hackathon
4. Check "Is Published" ✓
5. Save

**Solution C - Link videos to hackathon**:

1. Go to Django admin
2. SharXathons section
3. Open hackathon
4. Scroll to "Media Content"
5. Select videos in "Videos" field
6. Save

**Solution D - Clear browser cache**:

```
Ctrl+Shift+Delete (Windows/Linux)
Cmd+Shift+Delete (Mac)
Or: Cmd+Shift+R for hard refresh
```

---

### ❌ Issue 4: YouTube URL Not Auto-Processing

**Symptom**: Video ID field empty, Embed URL field empty

**Causes**:

#### 4a. Invalid URL format

**Valid formats**:

- ✅ `https://www.youtube.com/watch?v=VIDEO_ID`
- ✅ `https://youtu.be/VIDEO_ID`
- ✅ `https://youtube.com/shorts/VIDEO_ID`
- ✅ `http://youtu.be/VIDEO_ID` (without https)

**Invalid formats** ❌:

- ❌ `youtube.com/watch?v=VIDEO_ID` (missing https://)
- ❌ `https://youtube.com/watch?v=` (no video ID)
- ❌ `https://youtu.be/` (incomplete URL)

**Solution**:

1. Copy full URL from YouTube (including https://)
2. Paste into YouTube URL field in admin
3. Click Save
4. Video ID should populate automatically

#### 4b. Save didn't trigger

**Solution**:

1. Fill "YouTube URL" field
2. Make sure cursor leaves the field (click elsewhere)
3. Click "Save" button
4. Wait a few seconds
5. Refresh page
6. Fields should be populated

#### 4c. Backend auto-processing failed

```bash
# Check regex pattern
python manage.py shell

import re

url = "https://www.youtube.com/watch?v=dQw4w9WgXcQ"

# Pattern from admin
patterns = [
    r'youtube\.com/watch\?v=([a-zA-Z0-9_-]{11})',
    r'youtu\.be/([a-zA-Z0-9_-]{11})',
    r'youtube\.com/shorts/([a-zA-Z0-9_-]{11})'
]

for pattern in patterns:
    match = re.search(pattern, url)
    if match:
        print(f"Match found: {match.group(1)}")
        break
```

---

### ❌ Issue 5: Thumbnail Not Showing

**Symptom**: Video card shows broken image icon

**Causes**:

#### 5a. Auto-fetch failed

```bash
# Check if URL is correct format
# YouTube thumbnail format:
# https://img.youtube.com/vi/{VIDEO_ID}/maxresdefault.jpg

# Test URL in browser - should show thumbnail
```

**Solution**:

1. Edit video in admin
2. Manual thumbnail URL:
   ```
   https://img.youtube.com/vi/dQw4w9WgXcQ/maxresdefault.jpg
   ```
3. (Replace VIDEO_ID with actual ID)
4. Save
5. Refresh frontend

#### 5b. Image URL has typo

```bash
# Verify VIDEO_ID is exactly 11 characters
# Valid: dQw4w9WgXcQ (11 chars)
```

---

### ❌ Issue 6: Embed Not Playing in Modal

**Symptom**: Modal opens but video doesn't play or shows blank

**Diagnose**:

```javascript
// Open browser console
// Paste this:

const iframe = document.querySelector('iframe[src*="youtube"]');
console.log("iframe src:", iframe?.src);
console.log("iframe exists:", !!iframe);

// Should show YouTube embed URL
```

**Causes**:

#### 6a. Wrong iframe src

**Correct format**:

```
https://www.youtube.com/embed/VIDEO_ID
```

**Incorrect format** ❌:

```
https://www.youtube.com/watch?v=VIDEO_ID  ← Won't embed!
```

**Solution**:

1. Edit video in admin
2. Check "Embed URL" field
3. Should be: `https://www.youtube.com/embed/VIDEO_ID`
4. If blank, make sure YouTube URL saved correctly
5. If wrong format, delete and re-add video

#### 6b. iframe blocked

```javascript
// Check browser console for errors like:
// "Refused to load..."
// "Blocked by CORS..."
```

**Solution**:

```bash
# Check CORS settings in settings.py:
CORS_ALLOWED_ORIGINS = [
    "http://localhost:3000",
    "http://localhost:8000",
]

# Restart server after changes
python manage.py runserver
```

#### 6c. YouTube restricts embed

Some videos can't be embedded (privacy setting on YouTube)

**Solution**:

1. Go to YouTube video settings
2. Allow embedding
3. Update in admin (delete and re-add)

---

### ❌ Issue 7: API Returns Empty List

**Symptom**: `"results": []` or `"video_count": 0`

**Causes**:

#### 7a. No videos created yet

```bash
python manage.py shell

>>> from authentication.models import YouTubeVideo
>>> YouTubeVideo.objects.count()
# Returns 0 = no videos exist

# Need to create videos in admin first!
```

#### 7b. All videos unpublished

```bash
python manage.py shell

>>> from authentication.models import YouTubeVideo
>>> YouTubeVideo.objects.all().count()
# Returns > 0 = videos exist

>>> YouTubeVideo.objects.filter(is_published=True).count()
# Returns 0 = all unpublished

# Publish videos in admin!
```

#### 7c. Wrong hackathon slug

```bash
python manage.py shell

>>> from authentication.models import SharXathon
>>> [sh.slug for sh in SharXathon.objects.all()]
# Returns list of valid slugs

# Use correct slug in API!
```

---

### ❌ Issue 8: Admin Fields Missing

**Symptom**: Can't see "Media Content" section or "Videos" field in SharXathon admin

**Causes**:

#### 8a. Admin not customized

```bash
# Check sharxathon_admin.py exists
# Check authentication/admin.py imports it:
# from .sharxathon_admin import SharXathonAdmin

# File should have:
# fieldsets = (
#   ("Media Content", {...})
# )
```

#### 8b. Settings not updated

```bash
# In authentication/admin.py:
admin.site.register(SharXathon, SharXathonAdmin)
admin.site.register(YouTubeVideo, YouTubeVideoAdmin)

# Not:
admin.site.register(SharXathon)  # ← Wrong!
admin.site.register(YouTubeVideo)  # ← Wrong!
```

**Solution**:

1. Update admin.py
2. Restart Django server
3. Clear browser cache
4. Refresh admin page

---

## ✅ Testing Checklist

### Backend Testing

- [ ] **Database migrations applied**

  ```bash
  python manage.py migrate
  python manage.py showmigrations authentication | grep 0030
  ```

- [ ] **Models have correct fields**

  ```bash
  python manage.py shell
  >>> from authentication.models import YouTubeVideo, SharXathon
  >>> YouTubeVideo._meta.get_fields()
  # Should include: youtube_url, video_id, embed_url, etc.
  ```

- [ ] **Serializers work**

  ```bash
  python manage.py shell
  >>> from authentication.serializers import YouTubeVideoSerializer
  >>> from authentication.models import YouTubeVideo
  >>> videos = YouTubeVideo.objects.all()
  >>> serializer = YouTubeVideoSerializer(videos, many=True)
  >>> len(serializer.data)
  # Should return number without errors
  ```

- [ ] **Views work**

  ```bash
  curl http://localhost:8001/api/auth/youtube-videos/
  # Should return JSON
  ```

- [ ] **Admin interface accessible**
  - Go to http://localhost:8001/admin
  - Check "YouTube Videos" section exists
  - Check "SharXathons" shows Media Content fieldset

### Data Testing

- [ ] **Create test video**

  1. Admin → YouTube Videos → Add
  2. Fill title and YouTube URL
  3. Save
  4. Check ID and Embed URL auto-populated

- [ ] **Publish video**

  1. Edit video
  2. Check "Is Published"
  3. Save

- [ ] **Link to hackathon**

  1. Admin → SharXathons → Edit
  2. Media Content → Videos → Select video
  3. Save

- [ ] **Verify via API**
  ```bash
  curl http://localhost:8001/api/auth/hackathons/sharxathon-2025/videos/
  # Should show your video
  ```

### Frontend Testing

- [ ] **Page loads**

  - Navigate to hackathon detail page
  - No JavaScript errors (F12 → Console)

- [ ] **Videos section renders**

  - "Hackathon Videos" heading visible
  - Video cards show with thumbnails

- [ ] **Interaction works**

  - Click "Watch" button → Opens YouTube
  - Click "Preview" button → Shows modal
  - Click close button → Modal closes

- [ ] **Responsive design**

  - Desktop: Videos in grid (check layout)
  - Tablet: Responsive columns
  - Mobile: Single column, full width

- [ ] **Real-time updates**
  - Add video in admin
  - Refresh frontend
  - New video appears

---

## 🧪 Advanced Testing

### Test with Real YouTube Video

```javascript
// Recommended test videos:
const testVideos = [
  {
    url: "https://www.youtube.com/watch?v=dQw4w9WgXcQ",
    title: "Rick Astley - Never Gonna Give You Up",
  },
  {
    url: "https://youtu.be/jNQXAC9IVRw",
    title: "YouTube's first uploaded video",
  },
];

// Test in admin:
// 1. Copy URL above
// 2. Paste into YouTube URL field
// 3. Save
// 4. Check video_id populated
// 5. Check thumbnail shows
// 6. Go to frontend
// 7. Verify video displays
```

---

### Load Testing

```bash
# Test API with multiple requests
for i in {1..10}; do
  curl http://localhost:8001/api/auth/youtube-videos/featured/
  echo "Request $i completed"
  sleep 1
done

# Should all succeed without errors
```

---

### Browser DevTools Testing

**F12 → Network Tab**:

1. Open hackathon detail page
2. Look for requests to:
   - `/api/auth/hackathons/*/videos/` ✅ Should be 200
   - YouTube thumbnail URLs ✅ Should be 200
   - YouTube embed (if preview clicked) ✅ Should be embedded

**F12 → Console Tab**:

1. Check for red errors ❌ (should be none)
2. Check for warnings ⚠️ (okay, usually)
3. Test JavaScript:
   ```javascript
   // Should not throw errors:
   renderVideos();
   openVideoModal("VIDEO_ID", "EMBED_URL");
   ```

---

## 🔍 Debug Commands

### Backend Debug Script

```bash
# Create debug_youtube.py in Backend flow/

python manage.py shell << 'EOF'
from authentication.models import YouTubeVideo, SharXathon

print("=== YouTube Videos Debug ===")
print(f"Total videos: {YouTubeVideo.objects.count()}")
print(f"Published videos: {YouTubeVideo.objects.filter(is_published=True).count()}")

for video in YouTubeVideo.objects.all()[:5]:
    print(f"\nVideo: {video.title}")
    print(f"  ID: {video.video_id}")
    print(f"  Published: {video.is_published}")
    print(f"  Embed URL: {video.embed_url}")
    print(f"  Hackathons: {video.sharxathons.count()}")

print("\n=== SharXathons Debug ===")
for sh in SharXathon.objects.all()[:5]:
    print(f"\nHackathon: {sh.name}")
    print(f"  Published: {sh.is_published}")
    print(f"  Videos: {sh.videos.filter(is_published=True).count()}")
EOF
```

---

### Frontend Debug Script

```javascript
// Paste into browser console:

async function debugVideos() {
  console.log("=== Frontend YouTube Debug ===");

  try {
    const response = await fetch(
      "http://localhost:8001/api/auth/hackathons/sharxathon-2025/videos/"
    );
    const data = await response.json();

    console.log("API Response:", data);
    console.log("Video count:", data.video_count);

    if (data.videos.length > 0) {
      console.log("First video:", data.videos[0]);
      console.log("Embed URL:", data.videos[0].embed_url);
    } else {
      console.log("⚠️ No videos returned!");
    }
  } catch (error) {
    console.error("Fetch error:", error);
  }

  // Check DOM elements
  console.log("DOM Videos Grid:", document.getElementById("videosGrid"));
  console.log("Video Cards:", document.querySelectorAll(".video-card").length);
}

debugVideos();
```

---

## 📊 Common Scenarios

### Scenario 1: Added video in admin but not showing on frontend

**Checklist**:

1. [ ] Video is published (`is_published` = True)
2. [ ] Hackathon is published (`is_published` = True)
3. [ ] Video is linked to hackathon (in Media Content section)
4. [ ] Correct hackathon slug in frontend URL
5. [ ] Browser cache cleared (Ctrl+Shift+Delete)
6. [ ] API endpoint returns video (test with curl)

---

### Scenario 2: Videos show but thumbnails broken

**Checklist**:

1. [ ] Video ID is exactly 11 characters
2. [ ] Thumbnail URL format correct:
   ```
   https://img.youtube.com/vi/{VIDEO_ID}/maxresdefault.jpg
   ```
3. [ ] YouTube thumbnail image exists (test URL in browser)
4. [ ] Not manually entered with typo

---

### Scenario 3: Preview modal doesn't show embedded player

**Checklist**:

1. [ ] Embed URL is correct format:
   ```
   https://www.youtube.com/embed/{VIDEO_ID}
   ```
   (NOT `/watch?v=...`)
2. [ ] JavaScript openVideoModal() function called
3. [ ] iframe element exists in HTML
4. [ ] CORS not blocking (check console errors)
5. [ ] Video allows embedding on YouTube

---

## 📞 Emergency Contacts

**If nothing works**:

1. **Check server running**:

   ```bash
   ps aux | grep python
   ps aux | grep node
   ```

2. **Restart backend**:

   ```bash
   cd "/Users/vishaljha/Desktop/neosharx/Backend flow"
   python manage.py runserver
   ```

3. **Restart frontend**:

   ```bash
   cd "/Users/vishaljha/Desktop/neosharx/frontend"
   npm start
   ```

4. **Check logs**:

   ```bash
   # Backend errors
   tail -f backend.log

   # Browser console
   # F12 → Console tab
   ```

5. **Reset database** (development only):
   ```bash
   python manage.py flush
   python manage.py migrate
   ```

---

## ✨ Verification Checklist

- ✅ Backend server running
- ✅ Frontend server running
- ✅ Database migrations applied
- ✅ Admin interface accessible
- ✅ At least one test video created
- ✅ Video published
- ✅ Video linked to hackathon
- ✅ API returns videos
- ✅ Frontend displays videos
- ✅ Preview modal works
- ✅ Watch button opens YouTube

**If all checked**: System is fully functional! 🎉

---

**Document Version**: 1.0.0  
**Date**: October 19, 2025  
**Status**: ✅ PRODUCTION READY
