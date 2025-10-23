# 📺 YouTube Videos Admin Guide - Complete Setup

## 🎯 Backend Admin Interface - Complete Setup Guide

Your SharXathon backend already has **full YouTube video management capabilities**. Here's how to use it:

---

## 🚀 Step 1: Access Django Admin

### Start the Backend Server

```bash
cd "/Users/vishaljha/Desktop/neosharx/Backend flow"
python manage.py runserver
```

### Go to Admin Panel

- **URL**: `http://localhost:8001/admin/`
- **Login**: Use your Django admin credentials

---

## 🎬 Step 2: Add YouTube Videos

### Navigate to YouTube Videos Section

1. **In Admin Dashboard**, find **YouTube Videos** under Authentication app
2. Click **"Add YouTube Video"** button (top right)

### Fill in the Video Form

#### Required Fields:

- **Title**: Video title (e.g., "SharXathon 2025 Kickoff")
- **YouTube URL**: Full URL from YouTube
  - Format: `https://www.youtube.com/watch?v=VIDEO_ID`
  - Or: `https://youtu.be/VIDEO_ID`
  - Or: `https://youtube.com/shorts/VIDEO_ID`

#### Key Fields to Set:

**Video Details Section:**

- **Video Type**: Select "video" or "short"
- **Category**: Choose from dropdown
  - tech_talks
  - tutorials
  - startup_stories
  - **hackathons** (for SharXathon videos)
  - events
  - interviews
  - demos
  - other

**Display Settings:**

- **Is Featured**: ✓ Check to highlight on homepage
- **Is Published**: ✓ Check to make visible to users
- **Display Order**: Number (lower = first)
  - 0 = first position
  - 1 = second position
  - etc.
- **Autoplay**: ✓ Check to auto-play on homepage

**Optional Fields:**

- **Tags**: Comma-separated tags (e.g., "hackathon,education,tips")
- **Duration**: Video length (e.g., "12:34")
- **Thumbnail URL**: Custom thumbnail (leave blank to auto-fetch)

### Auto-Generated Fields (Do NOT Edit):

These are automatically filled:

- **Video ID**: Extracted from YouTube URL
- **Embed URL**: Generated for embedding
- **Auto Thumbnail**: Fetched from YouTube
- **Slug**: Auto-generated from title
- **Created At**: Auto-set timestamp
- **Updated At**: Auto-updated timestamp

### Save Video

Click **"Save"** button at bottom right

✅ Video ID and embed URL will be auto-extracted and generated!

---

## 🔗 Step 3: Link Videos to SharXathon Hackathons

### Navigate to SharXathons

1. In Admin Dashboard, find **SharXathons** under Authentication app
2. Click on an existing hackathon or create a new one

### Link Videos to Hackathon

1. **Scroll down** to **Media Content** section
2. Find the **Videos** field with a filter horizontal widget
3. **Select videos** from the available list:
   - Click on video to select
   - Use search to find videos quickly
   - Can select multiple videos
4. Arrange in desired order (if supported by field)
5. Click **"Save"** to save hackathon

### Your Videos are Now Live!

✅ Videos will now appear on the hackathon detail page automatically!

---

## 📊 Step 4: Manage Videos

### List View - See All Videos

**In YouTube Videos section:**

Columns shown:

- **Title**: Video name
- **Type**: video or short
- **Category**: Classification
- **Featured**: Star icon if featured
- **Published**: Eye icon if published
- **Autoplay**: Enabled/disabled
- **Display Order**: Position
- **Internal Views**: Views on your platform
- **Created**: When added

### Search Videos

- Use **search box** to find by:
  - Title
  - Description
  - Tags
  - Video ID

### Filter Videos

- **By Type**: video vs short
- **By Category**: Choose category
- **By Status**: Featured, Published
- **By Autoplay**: Enabled/disabled
- **By Date**: Created date range

### Bulk Actions

Select multiple videos and:

1. Choose action from dropdown:
   - **Mark as featured** - Highlight these videos
   - **Remove from featured** - Unhighlight
   - **Publish** - Make visible
   - **Unpublish** - Hide from users
2. Click **Go** button

---

## ✏️ Step 5: Edit Videos

### To Edit Existing Video:

1. In YouTube Videos list
2. Click video title
3. Edit fields as needed
4. Click **"Save"** (auto-processing if URL changed)

### To Change Which Hackathons Use This Video:

1. Edit video
2. In the video detail page, look for **"Related SharXathons"** section (if available)
3. Or edit the hackathon to add/remove this video

---

## 🗑️ Step 6: Delete Videos

### To Delete Video:

1. In YouTube Videos list
2. Click video to open
3. Click **"Delete"** button (bottom left)
4. Confirm deletion

⚠️ **Warning**: Deleting will remove from all linked hackathons!

---

## 📱 Advanced Features

### Bulk Update Display Order

**Use case**: Change which videos appear first

1. Edit each video
2. Change "Display Order" number
3. Save

Lower numbers appear first in UI.

### Set as Featured for Homepage

1. **Is Featured**: ✓ Check box
2. **Is Published**: ✓ Check box
3. **Display Order**: Set to 0-2 (first positions)
4. Save

Homepage will show featured videos prominently.

### Create Video Categories

Videos are automatically organized by:

- Type (video vs short)
- Category (hackathons, tutorials, etc.)
- Featured status

Use these when:

- Filtering videos in admin
- Building frontend displays
- Organizing by hackathon type

---

## 🔍 API Endpoints (For Integration)

Your backend provides these endpoints:

### Get All Published Videos

```
GET /api/auth/youtube-videos/
```

Optional Parameters:

- `?video_type=video` - Filter by type
- `?category=hackathons` - Filter by category
- `?featured=true` - Get featured only
- `?limit=10` - Limit results

### Get Featured Videos

```
GET /api/auth/youtube-videos/featured/
```

### Get Videos by Type

```
GET /api/auth/youtube-videos/type/video/
```

### Get Specific Video

```
GET /api/auth/youtube-videos/<slug>/
```

### Get Hackathon Videos

```
GET /api/auth/hackathons/<slug>/videos/
```

---

## 📋 Checklist for YouTube Setup

### Basic Setup

- [ ] Django admin server running
- [ ] Logged into admin at localhost:8001/admin
- [ ] Accessed YouTube Videos section
- [ ] Created at least one test video

### Video Management

- [ ] Added video title and YouTube URL
- [ ] Video ID auto-extracted
- [ ] Embed URL auto-generated
- [ ] Thumbnail auto-fetched
- [ ] Set category and type
- [ ] Marked as published
- [ ] Saved successfully

### Linking to Hackathons

- [ ] Opened a SharXathon
- [ ] Found Media Content section
- [ ] Selected video from list
- [ ] Saved hackathon
- [ ] Video appears on frontend

### Verification

- [ ] Visit hackathon detail page
- [ ] Scroll to "Hackathon Videos"
- [ ] See video card with thumbnail
- [ ] Click Watch button (opens YouTube)
- [ ] Click Preview button (embedded modal)
- [ ] Modal plays video correctly
- [ ] Close modal (X or click outside)

---

## 🐛 Troubleshooting

### Problem: Video ID not extracting

**Solution**:

- Paste full YouTube URL (including https://)
- Check format is correct
- Supported: youtube.com/watch?v=ID, youtu.be/ID, youtube.com/shorts/ID

### Problem: Thumbnail not showing

**Solution**:

- YouTube thumbnail auto-fetches
- If broken, upload custom thumbnail URL
- Make sure video ID is correct

### Problem: Video not appearing on frontend

**Solution**:

- Check "Is Published" is ✓ checked
- Check hackathon is "Is Published" ✓ checked
- Refresh browser (Ctrl+Shift+R hard refresh)
- Check video count on hackathon (Media Content)

### Problem: Embed URL blank

**Solution**:

- Auto-generates when you save video
- Make sure YouTube URL is in correct format
- URL is saved and processed on save

### Problem: Can't link video to hackathon

**Solution**:

- Video must be created first
- Video should be published
- Hackathon must exist
- Refresh admin page if list empty

---

## 🎨 Frontend Integration

When you add videos via admin:

1. They appear on hackathon detail page
2. In "Hackathon Videos" section
3. As beautiful cards with thumbnails
4. Click Watch → YouTube
5. Click Preview → Embedded modal

**The frontend automatically updates when you:**

- Add new video
- Link to hackathon
- Change published status
- Update display order

No code changes needed! Just admin updates.

---

## 📚 Additional Resources

- **API Documentation**: Check urls.py for all YouTube endpoints
- **Model Fields**: models.py has YouTubeVideo model definition
- **Serializer**: serializers.py has YouTubeVideoSerializer
- **Views**: views.py has youtube*videos*\* functions

---

## 🔐 Security Notes

- Only Django admin users can add/edit/delete videos
- Users can only see published videos
- Unpublished videos hidden from everyone
- All URLs validated before saving
- YouTube iframe properly sandboxed

---

## ✨ Tips & Tricks

1. **Use consistent display order** (0, 1, 2, etc.) for predictable ordering
2. **Feature important videos** so they show on homepage
3. **Use descriptive titles** for easy searching
4. **Add helpful tags** for categorization
5. **Set duration** so users know video length
6. **Use categories** to organize by type

---

## 🚀 You're All Set!

Your YouTube video backend admin is fully functional:

- ✅ Add/edit/delete videos
- ✅ Auto-process YouTube URLs
- ✅ Link to hackathons
- ✅ Manage display settings
- ✅ Bulk operations
- ✅ Search & filter

**Start adding videos now!**

---

**Backend Admin Version**: 1.0.0  
**Date**: October 19, 2025  
**Status**: ✅ PRODUCTION READY
