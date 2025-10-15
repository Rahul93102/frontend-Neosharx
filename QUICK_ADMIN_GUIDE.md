# Quick Admin Guide - Events & Videos 🚀

## 🎯 Quick Access

### Django Admin

```
URL: http://localhost:8000/admin/
```

### Edit From Frontend

1. Open homepage: `http://localhost:5500/index.html`
2. Hover over any event or video card
3. Click the blue "Edit" button

---

## 📝 Edit Events

### From Homepage

- Scroll to Events section
- Hover over any event card
- Click blue "Edit" button
- Redirects to Django admin

### From Admin Panel

- Navigate to `http://localhost:8000/admin/`
- Click **Authentication** → **Events**
- Select event to edit or click "Add Event"

### What You Can Edit

- ✅ Name, description, dates
- ✅ Location and venue details
- ✅ Images and banners
- ✅ Registration settings
- ✅ Pricing and tickets
- ✅ Featured/Published status
- ✅ Delete events

---

## 🎥 Edit YouTube Videos

### From Homepage

- Scroll to YouTube Videos section
- Hover over any video card
- Click blue "Edit" button
- Redirects to Django admin

### From Admin Panel

- Navigate to `http://localhost:8000/admin/`
- Click **Authentication** → **YouTube Videos**
- Select video to edit or click "Add YouTube Video"

### What You Can Edit

- ✅ Title and description
- ✅ YouTube URL (auto-extracts video ID)
- ✅ Video type and category
- ✅ Thumbnail image
- ✅ Autoplay/Mute/Loop settings
- ✅ Featured/Published status
- ✅ Display order
- ✅ Delete videos

---

## 🧭 Navigation

### Pages with Navigation

✅ All main pages (index, hackathon, startup, talks, tech, neo, robosharx)  
✅ All detail pages (story, tech, hackathon, neo, project, robotics, talks)

### Pages without Navigation (By Design)

❌ Login, Signup, Dashboard, Forgot Password

---

## 🔧 Quick Commands

### Start Backend Server

```bash
cd Backend\ flow
python manage.py runserver
```

### Access Admin

```
http://localhost:8000/admin/
```

### View Frontend

```
http://localhost:5500/index.html
```

---

## ✅ Features

| Feature           | Status       |
| ----------------- | ------------ |
| Edit Events       | ✅ Working   |
| Delete Events     | ✅ Working   |
| Edit Videos       | ✅ Working   |
| Delete Videos     | ✅ Working   |
| Auto-play Videos  | ✅ Enabled   |
| Static Navigation | ✅ All Pages |
| Clickable Cards   | ✅ Working   |
| Edit Buttons      | ✅ Working   |

---

## 📚 Full Documentation

See `NAVIGATION_AND_ADMIN_COMPLETE.md` for:

- Detailed implementation guide
- Testing checklist
- Architecture diagram
- Troubleshooting tips
- Complete page coverage

---

_Last Updated: October 11, 2024_ ✅
