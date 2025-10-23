# 📱 YouTube Videos - Quick Reference Card

## 🎯 One-Page Cheat Sheet

---

## ⚡ Quick Start (5 minutes)

### 1. Start Backend

```bash
cd "/Users/vishaljha/Desktop/neosharx/Backend flow"
python manage.py runserver
```

### 2. Go to Admin

- URL: `http://localhost:8001/admin/`
- Login with your credentials

### 3. Add YouTube Video

- Click: **YouTube Videos** → **Add YouTube Video**
- Paste YouTube URL: `https://www.youtube.com/watch?v=VIDEO_ID`
- Set: **Category** = "hackathons"
- Check: **Is Published** ✓
- Save

### 4. Link to Hackathon

- Click: **SharXathons** → Select your hackathon
- Scroll: **Media Content** section
- Select: Your video in **Videos** field
- Save

### 5. View on Frontend

- Open hackathon detail page
- Scroll to **"Hackathon Videos"** section
- Click **Preview** or **Watch**

---

## 📋 Admin Quick Commands

| Task                | Steps                                                     |
| ------------------- | --------------------------------------------------------- |
| **Add Video**       | YouTube Videos → Add → Paste URL → Set Published ✓ → Save |
| **Link Video**      | SharXathons → Edit → Media Content → Select Video → Save  |
| **Publish Video**   | YouTube Videos → Edit → Is Published ✓ → Save             |
| **Unpublish Video** | YouTube Videos → Edit → Is Published ☐ → Save             |
| **Feature Video**   | YouTube Videos → Edit → Is Featured ✓ → Save              |
| **Delete Video**    | YouTube Videos → Select → Delete button                   |
| **Change Order**    | YouTube Videos → Edit → Display Order → Save              |

---

## 🔗 API Endpoints

```
GET /api/auth/youtube-videos/                    # All videos
GET /api/auth/youtube-videos/featured/           # Featured only
GET /api/auth/youtube-videos/type/video/         # Video type
GET /api/auth/youtube-videos/{slug}/             # Specific video
GET /api/auth/hackathons/{slug}/videos/          # Hackathon videos
```

**Base URL**: `http://localhost:8001/api/auth/`

---

## 🎬 Frontend Functions

```javascript
// Open preview modal
openVideoModal(videoId, embedUrl);

// Close modal
closeVideoModal();

// Render videos
renderVideos();
```

---

## 📊 Field Quick Reference

| Field     | Admin Name    | Purpose        | Example                           |
| --------- | ------------- | -------------- | --------------------------------- |
| Title     | Title         | Video name     | "SharXathon Kickoff"              |
| URL       | YouTube URL   | Source video   | `https://youtube.com/watch?v=...` |
| Type      | Video Type    | video or short | "video"                           |
| Category  | Category      | Organization   | "hackathons"                      |
| Published | Is Published  | Visible?       | ✓ Checked                         |
| Featured  | Is Featured   | Homepage?      | ✓ Checked                         |
| Order     | Display Order | Position       | 0, 1, 2...                        |

---

## ❌ Common Issues & Quick Fixes

| Issue                       | Fix                                                                       |
| --------------------------- | ------------------------------------------------------------------------- |
| **Videos not showing**      | Check: Published ✓, Linked to hackathon, Browser cache cleared            |
| **URL not auto-processing** | Paste full URL with https://, click Save                                  |
| **Thumbnail broken**        | Edit video, manual URL: `https://img.youtube.com/vi/ID/maxresdefault.jpg` |
| **Modal won't play**        | Check embed URL format (should be `/embed/ID` not `/watch?v=ID`)          |
| **API returns 404**         | Check URL slug matches, video published, migration ran                    |
| **Admin fields missing**    | Restart Django server, clear cache                                        |

---

## 🧪 Test This Right Now

### Backend Test

```bash
curl http://localhost:8001/api/auth/youtube-videos/
# Should return JSON with videos
```

### Frontend Test

```javascript
// Open browser console (F12)
fetch("http://localhost:8001/api/auth/youtube-videos/featured/")
  .then((r) => r.json())
  .then((d) => console.log(d));
// Should show videos
```

### Admin Test

1. Go to `http://localhost:8001/admin/`
2. See **YouTube Videos** section
3. See **SharXathons** with **Media Content**

---

## 📁 Key Files

| File                    | Purpose                         |
| ----------------------- | ------------------------------- |
| `models.py`             | SharXathon, YouTubeVideo models |
| `serializers.py`        | Video data serialization        |
| `admin.py`              | Admin interface                 |
| `views.py`              | API endpoints                   |
| `urls.py`               | URL routing                     |
| `hackathon-detail.html` | Frontend display                |

---

## 🚀 Deployment Checklist

- [ ] All migrations applied
- [ ] Videos added to admin
- [ ] Videos published
- [ ] Videos linked to hackathons
- [ ] Frontend tested
- [ ] API endpoints working
- [ ] Thumbnails showing
- [ ] Modal playing videos
- [ ] Real-time updates working

---

## 📞 Emergency Fixes

### Videos not showing?

```bash
# 1. Restart backend
cd "/Users/vishaljha/Desktop/neosharx/Backend flow"
python manage.py runserver

# 2. Clear frontend cache
# Browser: Ctrl+Shift+Delete

# 3. Check admin
# Verify: Published ✓, Linked to hackathon
```

### API error?

```bash
# Test API directly
curl http://localhost:8001/api/auth/youtube-videos/

# Check migrations
python manage.py migrate

# Check database
python manage.py dbshell
```

### Admin missing fields?

```bash
# Restart server
python manage.py runserver

# Clear browser cache
# Ctrl+Shift+Delete
```

---

## 💡 Pro Tips

1. **Use display order 0-10** for consistent sorting
2. **Always publish before linking** (avoids confusion)
3. **Feature 3-6 videos** for homepage (optimal for UI)
4. **Use categories** to organize by type
5. **Test with 1 video first** before adding many
6. **Backup admin settings** before bulk changes

---

## 📊 Status Indicators

| Status            | Meaning                   |
| ----------------- | ------------------------- |
| ✓ Published       | Visible to users          |
| ☐ Unpublished     | Hidden from users         |
| ⭐ Featured       | Shows on homepage         |
| 👁️ Internal Views | Platform statistics       |
| 🔗 Linked         | Associated with hackathon |

---

## 🎯 Most Common Workflows

### Workflow 1: Add Single Video

1. Admin → YouTube Videos → Add
2. Paste URL + Set Published ✓
3. Save
4. Admin → SharXathons → Select hackathon
5. Media Content → Select video
6. Save
   **Time**: 2 minutes ⏱️

### Workflow 2: Create Video Showcase

1. Create 3-5 videos (all with Published ✓)
2. Set 1 as Featured ⭐
3. Link all to hackathon
4. Frontend auto-updates
   **Time**: 5 minutes ⏱️

### Workflow 3: Update Video Order

1. Admin → YouTube Videos → Edit each
2. Change "Display Order" (0, 1, 2...)
3. Save each
4. Frontend auto-updates
   **Time**: 3 minutes ⏱️

---

## 🔍 How to Verify Setup

```bash
# Step 1: Check migrations
python manage.py showmigrations authentication | grep 0030
# Output: [X] 0030_sharxathon_videos

# Step 2: Check API
curl http://localhost:8001/api/auth/youtube-videos/
# Output: {"count": N, "results": [...]}

# Step 3: Check admin
# Visit: http://localhost:8001/admin/
# Look for: YouTube Videos, SharXathons with Media Content
```

✅ All three working = System ready!

---

## 📚 Full Documentation Files

| Doc                                | Purpose           | Audience                 |
| ---------------------------------- | ----------------- | ------------------------ |
| `YOUTUBE_BACKEND_ADMIN_GUIDE.md`   | Admin panel usage | Admins, Content managers |
| `YOUTUBE_API_INTEGRATION_GUIDE.md` | API reference     | Developers               |
| `YOUTUBE_TROUBLESHOOTING_GUIDE.md` | Problem solving   | Everyone                 |
| `YOUTUBE_VIDEOS_QUICK_START.md`    | Quick setup       | New users                |
| This file                          | Quick reference   | Everyone                 |

**Start with this card, then reference full docs as needed!**

---

## ✨ Quick Links

- **Django Admin**: http://localhost:8001/admin/
- **API Base**: http://localhost:8001/api/auth/
- **Hackathon Detail**: http://localhost:3000/hackathon-detail
- **YouTube Videos List**: http://localhost:8001/api/auth/youtube-videos/

---

**Card Version**: 1.0.0  
**Last Updated**: October 19, 2025  
**Status**: ✅ Ready to Use

**💾 Save this file and bookmark it!**
