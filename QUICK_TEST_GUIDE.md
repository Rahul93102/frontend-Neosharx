# Quick Test Guide - Featured Screens

## 🚀 Fast Testing Instructions

### Step 1: Start All Servers (3 Terminals)

**Terminal 1 - Main Backend (Port 8000):**
```bash
cd "/Users/vishaljha/neosharx/Backend flow"
python3 manage.py runserver
```

**Terminal 2 - Tech News Backend (Port 8001):**
```bash
cd "/Users/vishaljha/neosharx/Backend flow"
python3 manage.py runserver 8001
```

**Terminal 3 - Frontend (Port 3000):**
```bash
cd /Users/vishaljha/neosharx/frontend
python3 -m http.server 3000
```

---

## Step 2: Add Test Data (5 minutes)

### Option A: Via Django Admin (Recommended)

1. **Open Admin Panel:**
   - Main: http://localhost:8000/admin/
   - Tech News: http://localhost:8001/admin/

2. **Add Featured Screen to Tech News:**
   - Go to "Tech News" section
   - Click on any article (or create new)
   - Scroll to "Featured Screen" section
   - Paste this JSON:
   ```json
   {"url": "https://images.unsplash.com/photo-1677442136019-21780ecad995", "type": "image", "is_featured": true}
   ```
   - Click "Save"

3. **Add Featured Screen to Startup Story:**
   - Go to http://localhost:8000/admin/
   - Go to "Startup Stories" section
   - Click on any story (or create new)
   - Paste this JSON:
   ```json
   {"url": "https://images.unsplash.com/photo-1559136555-9303baea8ebd", "type": "image", "is_featured": true}
   ```
   - Click "Save"

4. **Add Featured Screen to Hackathon:**
   - In "Hackathons" section
   - Click on any hackathon
   - Paste this JSON:
   ```json
   {"url": "https://images.unsplash.com/photo-1504384308090-c894fdcc538d", "type": "image", "is_featured": true}
   ```
   - Click "Save"

### Option B: Quick Test with Any Image
```json
{"url": "https://via.placeholder.com/800x400/000000/ffffff?text=Featured+Content", "type": "image", "is_featured": true}
```

### Option C: YouTube Video Test
```json
{"url": "https://www.youtube.com/watch?v=dQw4w9WgXcQ", "type": "video", "is_featured": true}
```

---

## Step 3: Test Frontend (2 minutes)

### Tech News Page:
1. Open: http://localhost:3000/tech-dynamic.html
2. ✓ Check navigation loads
3. ✓ Check featured slider appears (if data exists)
4. ✓ Test prev/next buttons
5. ✓ Test dot navigation
6. ✓ Click "Read More" → should go to tech-detail.html

### Startup Stories Page:
1. Open: http://localhost:3000/startup.html
2. ✓ Check featured slider appears
3. ✓ Test controls
4. ✓ Test filters (Industry, Stage, Sort)
5. ✓ Verify slider updates with filters

### Hackathon Page:
1. Open: http://localhost:3000/hackathon.html
2. ✓ Check navigation loads
3. ✓ Check featured slider appears
4. ✓ Test tabs (Overview, Rules, Judges, Winners)
5. ✓ Test prev/next/dots

---

## Step 4: Verify Everything Works

### Console Check (F12):
- No red errors
- No "Failed to fetch" errors
- Navigation loads successfully

### Visual Check:
- ✓ Featured slider has black border
- ✓ "Featured" badge in top-left
- ✓ Black prev/next buttons
- ✓ Gray/black dots at bottom
- ✓ Image/video displays correctly
- ✓ "Read More" button is black

### Navigation Check:
- ✓ Logo appears
- ✓ All 8 links present:
  * Home
  * NeoSharX Talks
  * Startup Stories
  * Neo Stories
  * Neo Projects
  * SharXathon
  * RoboSharX
  * What's up Tech
- ✓ "Join NeoSharX" button

---

## 🐛 Troubleshooting

### Problem: Featured Slider Doesn't Appear
**Solution:**
1. Check if data has `is_featured: true` in JSON
2. Verify API returns data (check console Network tab)
3. Confirm JSON format is correct

### Problem: Navigation Doesn't Load
**Solution:**
1. Check navigation.html exists in frontend folder
2. Verify fetch() is not blocked by CORS
3. Check console for errors

### Problem: Images Don't Load
**Solution:**
1. Use HTTPS URLs (not HTTP)
2. Verify image URL is accessible
3. Check CORS policy of image host

### Problem: Videos Don't Play
**Solution:**
1. Use full YouTube URL format
2. Check if YouTube embedding is allowed
3. Try different video URL

---

## 📊 Expected Results

### If NO Data with featured_screen:
- Pages load normally
- No featured slider appears
- Articles/stories display as before

### If Data with featured_screen Exists:
- Featured slider appears at top
- Image or video displays on left
- Content (title, description, category) on right
- Prev/next buttons work
- Dots show number of featured items
- Click dot to jump to that item
- "Read More" links to detail page

---

## ✅ Quick Verification Checklist

**Backend:**
- [ ] Main server running on :8000
- [ ] Tech news server running on :8001
- [ ] No migration errors
- [ ] Admin panel accessible

**Frontend:**
- [ ] HTTP server running on :3000
- [ ] tech-dynamic.html loads
- [ ] startup.html loads
- [ ] hackathon.html loads
- [ ] No console errors

**Data:**
- [ ] At least 1 tech news with featured_screen
- [ ] At least 1 startup story with featured_screen
- [ ] At least 1 hackathon with featured_screen
- [ ] JSON format correct

**Featured Screens:**
- [ ] Slider appears on pages with data
- [ ] Images load correctly
- [ ] Videos embed correctly (if used)
- [ ] Prev/Next buttons work
- [ ] Dot navigation works
- [ ] "Read More" links work

**Navigation:**
- [ ] Shared navigation loads on all pages
- [ ] All links work
- [ ] Logo displays
- [ ] Consistent styling

---

## 🎯 Success Criteria

You'll know everything works when:
1. ✅ All 3 servers running without errors
2. ✅ All 3 pages load with navigation
3. ✅ Featured sliders appear (if data exists)
4. ✅ All interactive controls work
5. ✅ No console errors
6. ✅ Links navigate correctly

**Total Testing Time: ~10 minutes**

---

## 🔗 Quick Links

- Main Admin: http://localhost:8000/admin/
- Tech Admin: http://localhost:8001/admin/
- Tech News: http://localhost:3000/tech-dynamic.html
- Startups: http://localhost:3000/startup.html
- Hackathons: http://localhost:3000/hackathon.html
- Talks: http://localhost:3000/talks-dynamic.html
- Neo Stories: http://localhost:3000/neo-dynamic.html
- Neo Projects: http://localhost:3000/neo-projects.html
- RoboSharX: http://localhost:3000/robosharx.html

---

**Ready to test! Follow steps 1-4 above.** 🚀
