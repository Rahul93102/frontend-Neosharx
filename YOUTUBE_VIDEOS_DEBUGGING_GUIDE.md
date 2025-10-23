# 🔧 YouTube Videos - Troubleshooting Guide (Videos Not Showing UI)

## Issue: Backend Shows Videos But Frontend UI is Empty

### Symptoms

- ✅ Django admin shows YouTube videos
- ✅ Videos are linked to hackathon in admin
- ✅ Videos are marked as "Published"
- ✅ API endpoint works when tested with curl
- ❌ Videos section on frontend shows "No videos available yet"

---

## Step 1: Check Browser Console (F12)

### Open Browser DevTools

1. **Press**: `F12` (Windows/Linux) or `Cmd+Option+I` (Mac)
2. **Go to**: "Console" tab
3. **Look for**: Debug messages starting with 📡, ✅, or ❌

### Expected Console Output

```
📡 Fetching hackathon details from API...
URL: http://localhost:8001/api/auth/hackathons/sharxathon-2025/
✅ API response received:
Videos in response: [{id: 1, title: "Video 1", ...}, ...]
Full response data: {id: 1, name: "SharXathon", videos: [...], ...}
🎬 renderVideos() called
Videos data: [{...}, {...}]
```

### If You See This

```
⚠️ No videos found
```

**Then**: Videos array is empty - go to Step 2

---

## Step 2: Verify Backend is Working

### Test 1: Check if Videos Exist

```bash
cd "/Users/vishaljha/Desktop/neosharx/Backend flow"
python manage.py shell

>>> from authentication.models import YouTubeVideo, SharXathon
>>> YouTubeVideo.objects.count()
# Should return > 0

>>> YouTubeVideo.objects.filter(is_published=True).count()
# Should return > 0

>>> sh = SharXathon.objects.get(slug='sharxathon-2025')
>>> sh.videos.count()
# Should return > 0

>>> sh.videos.filter(is_published=True).count()
# Should return > 0
```

### Test 2: Check API Directly

```bash
# In terminal, run:
curl "http://localhost:8001/api/auth/hackathons/sharxathon-2025/" | python -m json.tool | grep -A 50 "videos"

# Should show array of videos with this structure:
{
  "id": 1,
  "title": "Video Title",
  "video_id": "dQw4w9WgXcQ",
  "embed_url": "https://www.youtube.com/embed/...",
  "thumbnail_url": "https://img.youtube.com/vi/...",
  "is_published": true,
  ...
}
```

---

## Step 3: Verify Frontend is Receiving Data

### Option A: Check Network Tab

1. **F12** → **Network** tab
2. **Refresh** page (F5)
3. **Look for**: Request to `/api/auth/hackathons/...`
4. **Click** on it
5. **Go to**: "Response" tab
6. **Check**: If `"videos": [...]` array exists and has items

### Option B: Console Commands

Paste into browser console (F12 → Console):

```javascript
// Check if hackathonData has videos
console.log("hackathonData.videos:", hackathonData.videos);
console.log(
  "Video count:",
  hackathonData.videos ? hackathonData.videos.length : 0
);

// Check if videos grid element exists
console.log("VideosGrid element:", document.getElementById("videosGrid"));

// Check if videos are being rendered
console.log("Video cards:", document.querySelectorAll(".video-card").length);

// Manually call render to see if it works
renderVideos();
```

---

## Common Issues & Fixes

### Issue 1: Videos Exist in Admin but API Returns Empty Array

**Symptoms**:

- Admin shows videos
- `curl` API shows videos in response
- But `hackathonData.videos` is empty in console

**Cause**: Videos not linked to hackathon

**Fix**:

1. Go to Django admin
2. **SharXathons** → Edit your hackathon
3. **Media Content** section → **Videos** field
4. **Select** videos from the list
5. **Save**

**Verify**:

```bash
python manage.py shell
>>> sh = SharXathon.objects.get(slug='sharxathon-2025')
>>> sh.videos.count()  # Should be > 0
```

---

### Issue 2: Videos Linked but API Returns Unpublished Videos

**Symptoms**:

- Admin shows videos linked
- API returns videos
- But `is_published: false` in response

**Cause**: Videos not marked as published

**Fix**:

1. Go to Django admin
2. **YouTube Videos** → Select each video
3. Check **Is Published** ✓
4. **Save**

**Verify**:

```bash
python manage.py shell
>>> YouTubeVideo.objects.filter(is_published=True).count()  # Should be > 0
```

---

### Issue 3: Videos Published and Linked but Not Showing in UI

**Cause**: Frontend not rendering correctly

**Fix**: Add videos using admin and watch console

```javascript
// In browser console:
console.log("Current hackathonData.videos:", hackathonData.videos);

// Manually render:
renderVideos();

// Check for errors:
document.getElementById("videosGrid").innerHTML;
```

---

## Step 4: Quick Fix Checklist

✅ **Backend Verification**:

- [ ] Django admin loads: http://localhost:8001/admin
- [ ] YouTube Videos section shows videos
- [ ] Videos marked as "Published" (checkbox checked)
- [ ] Videos linked to hackathon (in Media Content)
- [ ] `curl` API call shows videos in response

✅ **Frontend Verification**:

- [ ] Page URL has correct slug: `...?slug=sharxathon-2025`
- [ ] Browser console shows no red errors
- [ ] Console logs show videos in API response
- [ ] `renderVideos()` is called
- [ ] `hackathonData.videos` has items

✅ **Rendering**:

- [ ] Open F12 → Console
- [ ] Type: `renderVideos()`
- [ ] Press Enter
- [ ] Videos should appear

---

## Step 5: Nuclear Option - Full Reset

### If Nothing Works:

**1. Restart Django Server**

```bash
cd "/Users/vishaljha/Desktop/neosharx/Backend flow"
# Kill any existing server: Ctrl+C
python manage.py runserver
```

**2. Clear Frontend Cache**

```
Ctrl+Shift+Delete  (Windows/Linux)
Cmd+Shift+Delete   (Mac)
Or: Cmd+Shift+R to hard refresh
```

**3. Re-migrate Database**

```bash
python manage.py migrate
python manage.py migrate --run-syncdb
```

**4. Create Test Video**

1. Admin → YouTube Videos → Add
2. Title: "Test Video"
3. URL: `https://www.youtube.com/watch?v=dQw4w9WgXcQ`
4. Check: Is Published ✓
5. Save

**5. Link to Hackathon**

1. Admin → SharXathons → Edit
2. Media Content → Videos → Select "Test Video"
3. Save

**6. Check Frontend**

1. Refresh page: F5
2. Open console: F12
3. Check if videos appear

---

## Console Debug Commands

Copy and paste these into browser console (F12 → Console):

```javascript
// Check everything
console.log("=== VIDEO DEBUG ===");
console.log("1. hackathonData exists:", !!hackathonData);
console.log("2. hackathonData.videos exists:", !!hackathonData.videos);
console.log("3. Videos array:", hackathonData.videos);
console.log(
  "4. Video count:",
  hackathonData.videos ? hackathonData.videos.length : "N/A"
);
console.log(
  "5. VideosGrid element exists:",
  !!document.getElementById("videosGrid")
);
console.log(
  "6. Video cards rendered:",
  document.querySelectorAll(".video-card").length
);
console.log("=== END DEBUG ===");

// If videos exist, try rendering
if (hackathonData.videos && hackathonData.videos.length > 0) {
  console.log("✅ Videos exist, attempting render...");
  renderVideos();
}
```

---

## API Response Verification

### Expected JSON Structure

```json
{
  "id": 1,
  "name": "SharXathon 2025",
  "slug": "sharxathon-2025",
  "videos": [
    {
      "id": 1,
      "title": "Kickoff Video",
      "video_id": "dQw4w9WgXcQ",
      "embed_url": "https://www.youtube.com/embed/dQw4w9WgXcQ",
      "thumbnail_url": "https://img.youtube.com/vi/dQw4w9WgXcQ/maxresdefault.jpg",
      "youtube_url": "https://www.youtube.com/watch?v=dQw4w9WgXcQ",
      "is_published": true,
      "category": "hackathons",
      "video_type": "video",
      "duration": "5:30",
      "description": "Welcome to SharXathon!",
      "display_order": 0
    }
  ],
  "other_fields": "..."
}
```

### If Missing Videos Field

**Problem**: `"videos": []` or `"videos"` field missing

**Solution**:

1. Check backend serializer: is `get_videos()` method there?
2. Run migration: `python manage.py migrate`
3. Restart Django: `python manage.py runserver`

---

## LinkedIn Issues (Separate Problem)

The "LinkedIn Network Will Be Back Soon" error is a LinkedIn API issue, typically caused by:

1. **LinkedIn API is down** - Try again in a few minutes
2. **Invalid credentials** - Re-authenticate with LinkedIn
3. **Rate limiting** - Wait and retry
4. **OAuth token expired** - Logout and login again

**Temporary Fix**: Clear browser cache and login again

```
F12 → Application → Local Storage → Clear All
```

---

## Getting Help

If still not working, provide:

1. **Browser Console Output** (F12 → Copy all logs)
2. **API Response** (from Network tab or curl)
3. **Django Shell Results** (from Step 2)
4. **Admin Screenshots** (showing videos and linking)
5. **URL** of your hackathon page

---

## Final Verification

**Everything is working when**:

- ✅ Backend admin shows videos
- ✅ Videos are published
- ✅ Videos are linked to hackathon
- ✅ API returns videos in JSON
- ✅ Browser console shows no errors
- ✅ Frontend displays video cards
- ✅ Thumbnails load
- ✅ Preview modal works

**If all above are true**: System is working correctly! 🎉

---

**Created**: October 19, 2025
**Last Updated**: October 19, 2025
**Status**: ✅ Ready to Use
