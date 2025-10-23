# 🚀 Quick Start: YouTube Videos for SharXathon

## 5-Minute Setup Guide

### Step 1: Apply Database Migration

```bash
cd "/Users/vishaljha/Desktop/neosharx/Backend flow"
python manage.py migrate
```

### Step 2: Add YouTube Videos via Django Admin

1. **Start Django server:**

   ```bash
   python manage.py runserver
   ```

2. **Go to:** `http://localhost:8001/admin/`

3. **Navigate to:** YouTube Videos

4. **Click "Add YouTube Video"** and fill:
   - Title: "SharXathon Kickoff"
   - YouTube URL: `https://www.youtube.com/watch?v=<your-video-id>`
   - Category: "hackathons"
   - Type: "video"
   - ✅ Check "Is Published"
   - ✅ Check "Is Featured" (optional)
   - Click **Save**

### Step 3: Link Videos to Hackathon

1. **Go to SharXathons** (in Django Admin)

2. **Open any hackathon** (or create a new one)

3. **Scroll to "Media Content"** section

4. **Under Videos:** Select the video you just created

5. **Click Save**

### Step 4: View on Frontend

1. **Open:** `http://localhost:8000/frontend/hackathon-detail.html?slug=<hackathon-slug>`

2. **Scroll down** to "Hackathon Videos" section

3. **You should see:**
   - Video thumbnail
   - Video title
   - Category badge (HACKATHONS)
   - Watch & Preview buttons
   - Smooth hover effects

### Step 5: Preview Video

- Click **"Preview"** button to see video in embedded modal
- Click **"Watch"** to open on YouTube
- Click **X** or outside modal to close

---

## ✅ What You'll See

### Admin Panel

```
Django Admin
├── YouTube Videos
│   ├── Add/Edit Videos
│   ├── Set as Featured
│   ├── Publish/Unpublish
│   └── Bulk Actions
└── SharXathons
    ├── Media Content (NEW)
    └── Select Videos for Hackathon
```

### Frontend

```
Hackathon Detail Page
├── Hero Section
├── About
├── Judges & Mentors
├── Winners & Prizes
├── Hackathon Videos ← NEW SECTION
│   ├── Video Card 1 [Thumbnail] [Title] [Watch] [Preview]
│   ├── Video Card 2 [Thumbnail] [Title] [Watch] [Preview]
│   └── Video Card 3 [Thumbnail] [Title] [Watch] [Preview]
└── Comments Section
```

---

## 🎬 API Endpoints (For Testing)

Get videos for a hackathon:

```
GET http://localhost:8001/api/auth/hackathons/sharxathon-2025/videos/
```

Response includes:

```json
{
  "hackathon_id": 1,
  "hackathon_name": "SharXathon 2025",
  "videos": [
    {
      "id": 1,
      "title": "Video Title",
      "embed_url": "https://www.youtube.com/embed/...",
      "category": "hackathons",
      "video_type": "video"
    }
  ]
}
```

---

## 🎨 Features

✅ **Video Management**

- Add/Edit/Delete videos via Django admin
- Auto-extract video ID from YouTube URL
- Auto-generate embed URL
- Auto-fetch YouTube thumbnail
- Custom thumbnail support

✅ **Display Control**

- Mark as Featured/Published
- Set display order (lower = first)
- Enable autoplay
- Category and type classification

✅ **Frontend UI**

- Responsive video grid (1-3 columns)
- Beautiful cards with hover effects
- Red play button overlay
- Video metadata badges
- Embedded preview modal
- Direct YouTube link

✅ **Real-Time Updates**

- Changes in Django admin appear on next page load
- API always serves latest data
- No page refresh needed for new videos

---

## 🔧 Customization

### Change Number of Columns

Edit `hackathon-detail.html` line ~825:

```html
<!-- Change this: -->
<div
  id="videosGrid"
  class="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-6"
>
  <!-- To: -->
  <div
    id="videosGrid"
    class="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-6"
  ></div>
</div>
```

### Change Video Card Styling

Edit CSS in `hackathon-detail.html` around line 700-800

### Change API Base URL

If your API is on different port, edit `hackathon-detail.html`:

```javascript
// Find and replace:
http://localhost:8001/api/auth/
```

---

## 📱 Responsive Design

- **Mobile (< 768px)**: 1 column
- **Tablet (768px - 1024px)**: 2 columns
- **Desktop (> 1024px)**: 3 columns

Cards automatically resize and maintain aspect ratio!

---

## 🐞 Quick Fixes

### Videos not showing?

1. Check video is **Published** ✓ in Django admin
2. Check hackathon is **Published** ✓ in Django admin
3. Refresh browser (Ctrl+Shift+R for hard refresh)
4. Check browser console for errors (F12)

### Thumbnails broken?

- Auto-thumbnail uses: `https://img.youtube.com/vi/{video_id}/hqdefault.jpg`
- If broken, upload custom thumbnail in Django admin

### Preview modal not working?

- Make sure embed URL is correct
- Check YouTube settings allow embedding
- Try different YouTube video

---

## 📊 Database Check

Verify many-to-many relationship:

```bash
python manage.py dbshell

# SQLite:
SELECT * FROM authentication_sharxathon_videos;

# PostgreSQL:
SELECT * FROM authentication_sharxathon_videos;
```

---

## 🔐 Permissions

Only Django admin users can:

- Add/Edit/Delete videos
- Link videos to hackathons
- Set featured/published status

Regular users can:

- View published videos
- Watch on YouTube
- Preview in embedded modal
- Like and comment (if enabled)

---

## 📞 Need Help?

1. **Check full docs:** `HACKATHON_YOUTUBE_VIDEOS_COMPLETE.md`
2. **API Response:** Use browser DevTools Network tab
3. **Django Logs:** Check terminal for Python errors
4. **Database:** Run `python manage.py shell` to debug

---

## ✨ You're All Set!

Your SharXathon now has:

- ✅ YouTube video support
- ✅ Beautiful card UI
- ✅ Admin management
- ✅ Real-time updates
- ✅ Fully responsive design
- ✅ Complete documentation

**Next Steps:**

1. Add more videos via Django admin
2. Link to multiple hackathons
3. Customize styling to match brand
4. Share with team!

---

**Happy Video Managing! 🎬**
