# 🚀 Hackathon Pages - Quick Start Guide

## ⚡ Instant Testing

### 1. Start Backend (Terminal 1)

```bash
cd /Users/vishaljha/neosharx/backend
python manage.py runserver
```

### 2. Open Pages (Browser)

```
Listing: http://127.0.0.1:5500/frontend/hackathon.html
Detail:  http://127.0.0.1:5500/frontend/hackathon-detail.html?slug=example
```

---

## 📋 30-Second Checklist

### Hackathon Listing Page:

- [ ] Header shows "SharXathons" (simple, centered, NO black background)
- [ ] Featured slider auto-rotates every 17 seconds
- [ ] Filter tabs work (All, Live, Upcoming, Completed)
- [ ] Cards display in 3-column grid (desktop)
- [ ] Hover on cards: lifts 4px with shadow
- [ ] Click card → navigates to detail page
- [ ] Status badges show: LIVE (green), UPCOMING (black), COMPLETED (gray)

### Hackathon Detail Page:

- [ ] Back link returns to hackathon.html
- [ ] Countdown timer updates (for upcoming events)
- [ ] Register button works or shows "Event Ended"
- [ ] Comment system loads at bottom
- [ ] Related hackathons show (3 cards)

---

## 🎨 Design Verification

### Colors (Black/Gray/White ONLY):

✅ NO blue colors (#007fff)
✅ NO gradients
✅ NO animated backgrounds
✅ Black text on white background
✅ Gray for secondary text
✅ Green ONLY for LIVE status badge

### Typography:

✅ Newsreader font (NOT Inter)
✅ 3rem (48px) page title
✅ Consistent sizing with other pages

### Layout:

✅ Featured slider: 50% image | 50% content
✅ Cards: 3 columns desktop, 1 column mobile
✅ Border-radius: 1rem (16px)
✅ Gaps: 1.5rem (24px)

---

## 🔍 Quick Fixes

### Issue: API not loading

```bash
# Check backend is running
curl http://127.0.0.1:8000/hackathons/

# Should return JSON with hackathons array
```

### Issue: Featured slider not rotating

```javascript
// Check browser console for errors
// Should see no JavaScript errors
// Slider should rotate every 17 seconds
```

### Issue: Filter tabs not working

```javascript
// Click each tab
// Grid should filter immediately
// Active tab: black background, white text
```

### Issue: Detail page 404

```javascript
// Verify slug in URL
// Check API endpoint: /hackathons/{slug}/
// Ensure slug exists in database
```

---

## 📁 Files Reference

### Created/Updated:

```
frontend/hackathon.html              (23KB, 785 lines)
frontend/hackathon-detail.html       (20KB, 586 lines)
frontend/hackathon.html.backup-redesign (31KB, backup)
```

### Documentation:

```
HACKATHON_REDESIGN_COMPLETE.md       (Complete specs)
HACKATHON_BEFORE_AFTER.md            (Visual comparison)
HACKATHON_QUICK_START.md             (This file)
```

---

## 🎯 What Changed

### Removed ❌:

- Animated hero section
- Blue colors (#007fff)
- Gradient backgrounds
- Animated patterns
- Inter font
- Custom hero styling
- Multiple animations
- Decorative effects

### Added ✅:

- Simple "SharXathons" header
- Featured slider (50/50 split)
- 17-second auto-rotation
- Filter tabs (4 options)
- Professional card grid
- Status system (Live/Upcoming/Completed)
- Countdown timer
- Detail page (complete)
- Comment system
- Related hackathons
- Newsreader font
- Black/gray/white colors

---

## 🔗 Navigation Check

```
From: hackathon.html
  ↓
To: hackathon-detail.html?slug=...
  ↓
Back: hackathon.html

From: navigation.html
  ↓
To: hackathon.html
```

---

## ✅ Success Criteria

Page is ready when:

1. ✅ No blue colors anywhere
2. ✅ Header is simple centered text (no black background)
3. ✅ Featured slider rotates automatically
4. ✅ Filter tabs change card display
5. ✅ Cards hover with lift effect
6. ✅ Detail page loads with countdown
7. ✅ Comment system works
8. ✅ Design matches talks-dynamic.html
9. ✅ Font is Newsreader throughout
10. ✅ Responsive on mobile

---

## 🆘 Troubleshooting

### Colors still blue?

- Clear browser cache (Cmd+Shift+R)
- Check you're viewing NEW hackathon.html (not backup)

### Font wrong (Inter instead of Newsreader)?

- Check Google Fonts link in `<head>`
- Verify Tailwind config has `fontFamily: { display: ["Newsreader"] }`

### Slider not rotating?

- Check browser console for JavaScript errors
- Verify `startSliderAutoRotation()` is called
- Should rotate every 17000ms (17 seconds)

### Cards not filtering?

- Check filter tab click events are attached
- Verify `applyFilters()` function runs
- Console should show no errors

---

## 📊 API Data Structure

### List Endpoint: `/hackathons/`

```json
{
  "hackathons": [
    {
      "slug": "ai-robotics-2024",
      "title": "AI & Robotics Hackathon",
      "description": "Full description...",
      "tagline": "Short tagline",
      "image": "url",
      "banner_image": "url",
      "category": "Online",
      "start_date": "2024-01-15T00:00:00Z",
      "end_date": "2024-01-17T23:59:59Z",
      "prize_pool": "$10,000",
      "participants_count": 150,
      "featured": true
    }
  ]
}
```

### Detail Endpoint: `/hackathons/{slug}/`

```json
{
  "slug": "ai-robotics-2024",
  "title": "AI & Robotics Hackathon",
  "tagline": "Build the future...",
  "description": "<p>Full HTML description...</p>",
  "banner_image": "url",
  "category": "Online",
  "start_date": "2024-01-15T00:00:00Z",
  "end_date": "2024-01-17T23:59:59Z",
  "prize_pool": "$10,000",
  "prizes": [
    { "rank": "1st Place", "amount": "$5,000" },
    { "rank": "2nd Place", "amount": "$3,000" }
  ],
  "participants_count": 150,
  "registration_link": "https://...",
  "eligibility": "Open to all...",
  "rules": "Teams of 2-4...",
  "organizer": "Company Name"
}
```

---

## 🎉 You're Done!

The hackathon pages are now:

- ✅ Professional and clean
- ✅ Consistent with all other pages
- ✅ Industry-ready
- ✅ Fully functional
- ✅ Ready to test

**Open the pages and enjoy the clean, professional design! 🚀**

---

## 📞 Quick Links

- **Main Page**: `hackathon.html`
- **Detail Page**: `hackathon-detail.html`
- **Backup**: `hackathon.html.backup-redesign`
- **Full Docs**: `HACKATHON_REDESIGN_COMPLETE.md`
- **Comparison**: `HACKATHON_BEFORE_AFTER.md`

**Happy Testing! 🎯✨**
