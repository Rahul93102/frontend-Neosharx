# 🎯 Quick Start Guide - Events & YouTube Videos

## ⚡ Instant Access

### Backend Server:

```bash
cd "Backend flow"
python manage.py runserver
```

✅ Running at: `http://127.0.0.1:8000`

### Admin Panel:

```
URL: http://127.0.0.1:8000/admin/
```

### Homepage:

```
File: frontend/index.html
Open in browser to see events & videos
```

---

## 📝 Add Content (Admin)

### Add Event:

1. Go to Admin → Events → Add Event
2. Enter: name, description, date, location
3. Paste image URL
4. Choose type: past/recent/upcoming
5. Toggle: "Published" ✅
6. Save

### Add Video:

1. Go to Admin → YouTube Videos → Add Video
2. Enter: title, description
3. Paste YouTube URL (e.g., `https://youtube.com/watch?v=ABC123`)
4. Enter video ID (e.g., `ABC123`)
5. Choose type: video/short
6. Toggle: "Published" ✅, "Autoplay" ✅
7. Save

---

## 🎬 Video Details

### Get Video ID:

```
YouTube URL: https://www.youtube.com/watch?v=dQw4w9WgXcQ
Video ID: dQw4w9WgXcQ (copy this part)

Short URL: https://youtube.com/shorts/ABC123
Video ID: ABC123 (copy this part)
```

### Video Types:

- **Video**: Regular YouTube videos
- **Short**: YouTube Shorts (vertical format)

---

## 🔍 Test Everything

### Test APIs:

```bash
# Test Events
curl http://127.0.0.1:8000/api/auth/events/

# Test Videos
curl http://127.0.0.1:8000/api/auth/youtube-videos/
```

### Test Frontend:

```
Open: frontend/backend-test.html
Auto-tests all APIs
Shows results
```

---

## ✅ Checklist

### Backend Running:

- [ ] Server started on port 8000
- [ ] Admin accessible
- [ ] APIs responding
- [ ] Sample data loaded

### Frontend Working:

- [ ] index.html opens
- [ ] Events load from backend
- [ ] Videos load and autoplay
- [ ] All cards same size
- [ ] Professional UI maintained

---

## 🆘 Troubleshooting

### Server Not Running:

```bash
cd "Backend flow"
python manage.py runserver
```

### Port Already in Use:

```bash
# Use different port
python manage.py runserver 8001

# Update frontend API_BASE_URL to match
```

### Videos Not Autoplaying:

- Autoplay requires mute (already set)
- Check browser allows autoplay
- Try different browser

### No Data Showing:

```bash
# Run test script to add sample data
cd "Backend flow"
python test_events_and_videos.py
```

---

## 📊 What You See

### Events Section:

```
Past Events → Grayscale images
Recent Events → Color images
Upcoming Events → Blue backgrounds
All in carousel format
```

### Videos Section:

```
Grid layout (3 columns desktop)
All cards same rectangular size
Videos autoplay (muted)
Type badges (Video/Short)
View counts displayed
```

---

## 🎨 Customization

### Change Video Order:

```
Admin → Videos → Edit display_order field
Lower number = appears first
```

### Feature Content:

```
Admin → Edit item
Toggle "Is Featured" checkbox
Save
```

### Hide Content:

```
Admin → Edit item
Uncheck "Is Published"
Save
```

---

## 📱 Responsive Design

- **Mobile**: 1 video per row
- **Tablet**: 2 videos per row
- **Desktop**: 3 videos per row

All automatic, no config needed!

---

## 🚀 Deploy to Production

1. Update API URL in frontend/index.html:

```javascript
const API_BASE_URL = "https://your-domain.com/api/auth";
```

2. Configure Django for production
3. Set up HTTPS (required for autoplay)
4. Deploy and test

---

## 💡 Tips

✅ **Always publish content** - Check "Is Published" box
✅ **Set display order** - Control appearance order
✅ **Use high-quality images** - Better user experience
✅ **Test on mobile** - Ensure responsive design
✅ **Monitor views** - Track engagement

---

## 📞 Key URLs

| Purpose    | URL                                            |
| ---------- | ---------------------------------------------- |
| Backend    | http://127.0.0.1:8000                          |
| Admin      | http://127.0.0.1:8000/admin/                   |
| Events API | http://127.0.0.1:8000/api/auth/events/         |
| Videos API | http://127.0.0.1:8000/api/auth/youtube-videos/ |
| Homepage   | frontend/index.html                            |
| Test Page  | frontend/backend-test.html                     |

---

## ✨ Features Summary

### Events:

- ✅ 3 types (past/recent/upcoming)
- ✅ Dynamic loading
- ✅ Carousel navigation
- ✅ Registration links
- ✅ Admin editable

### Videos:

- ✅ YouTube integration
- ✅ Autoplay (muted)
- ✅ Uniform card sizes
- ✅ Videos + Shorts support
- ✅ Admin editable

---

## 🎊 You're All Set!

Everything is working and ready to use:

- ✅ Backend configured
- ✅ Admin accessible
- ✅ Frontend integrated
- ✅ Professional UI
- ✅ Autoplay enabled
- ✅ Responsive design

**Start adding your content!**

---

_Quick Start Guide - NeoSharX Platform_
_October 12, 2025_
