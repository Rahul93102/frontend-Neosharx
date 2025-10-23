# 🧪 Events System - Quick Test Guide

## Prerequisites

- Backend server running on port 8000
- Frontend server running on port 3000
- Sample events created in database

## Quick Start

### 1. Check Backend Status

```bash
# Test API is responding
curl http://localhost:8000/api/auth/events/ | python -m json.tool | head -50

# Count events by type
echo "Upcoming:" && curl -s http://localhost:8000/api/auth/events/type/upcoming/ | python -m json.tool | grep -c '"id"'
echo "Recent:" && curl -s http://localhost:8000/api/auth/events/type/recent/ | python -m json.tool | grep -c '"id"'
echo "Past:" && curl -s http://localhost:8000/api/auth/events/type/past/ | python -m json.tool | grep -c '"id"'
```

### 2. Test Frontend

```bash
# Open in default browser
open http://localhost:3000/index.html

# Or using curl to check page loads
curl -I http://localhost:3000/index.html
```

### 3. Manual Testing Checklist

#### Backend API Tests ✅

- [ ] GET /api/auth/events/ returns list of events
- [ ] GET /api/auth/events/type/upcoming/ returns only upcoming events
- [ ] GET /api/auth/events/type/recent/ returns only recent events
- [ ] GET /api/auth/events/type/past/ returns only past events
- [ ] GET /api/auth/events/featured/ returns only featured events
- [ ] GET /api/auth/events/{slug}/ returns single event details
- [ ] GET /api/auth/events/categories/ returns category list
- [ ] Response includes all required fields (name, date, location, benefits, etc.)

#### Frontend Visual Tests ✅

- [ ] Events section visible on homepage
- [ ] Three columns: Past | Recent | Upcoming
- [ ] Each column shows carousel with events
- [ ] Past events have grayscale images
- [ ] Upcoming events have blue glow border
- [ ] Event cards show: image, name, date, location

#### Carousel Functionality ✅

- [ ] Left arrow navigates to previous event
- [ ] Right arrow navigates to next event
- [ ] Mouse drag scrolls carousel horizontally
- [ ] Pagination dots appear below carousel
- [ ] Active dot is highlighted
- [ ] Clicking dot navigates to that event
- [ ] Smooth scroll animations

#### Hover Effects ✅

- [ ] Card scales up on hover (1.02x)
- [ ] Shadow increases on hover
- [ ] Cursor changes to 'grab' over carousel
- [ ] Cursor changes to 'grabbing' when dragging
- [ ] Hover button appears with text:
  - Past: "Watch Highlights"
  - Recent: "View Photos / Replay"
  - Upcoming: "Register Now" (no hover, always visible)

#### Details Expansion ✅

- [ ] Clicking "View Details" opens overlay
- [ ] Overlay shows event benefits list
- [ ] Overlay shows full event details
- [ ] Overlay shows location
- [ ] Close button (X) dismisses overlay
- [ ] Smooth fade in/out animation

#### Responsive Design ✅

- [ ] Desktop view: 3 columns side-by-side
- [ ] Tablet view: Columns stack properly
- [ ] Mobile view: Full-width columns
- [ ] Images maintain aspect ratio
- [ ] Text is readable at all sizes

## API Test Commands

### Test All Event Types

```bash
# Upcoming events
curl -s "http://localhost:8000/api/auth/events/type/upcoming/" | python -m json.tool

# Recent events
curl -s "http://localhost:8000/api/auth/events/type/recent/" | python -m json.tool

# Past events
curl -s "http://localhost:8000/api/auth/events/type/past/" | python -m json.tool
```

### Test Filtering

```bash
# Featured events only
curl -s "http://localhost:8000/api/auth/events/?featured=true" | python -m json.tool

# Filter by category
curl -s "http://localhost:8000/api/auth/events/?category=conference" | python -m json.tool

# Pagination
curl -s "http://localhost:8000/api/auth/events/?page=1&page_size=3" | python -m json.tool
```

### Test Single Event

```bash
# Get first event slug
SLUG=$(curl -s "http://localhost:8000/api/auth/events/" | python -c "import sys, json; print(json.load(sys.stdin)['results'][0]['slug'])")

# Get event details
curl -s "http://localhost:8000/api/auth/events/$SLUG/" | python -m json.tool
```

## Browser DevTools Testing

### Check API Calls

1. Open browser DevTools (F12)
2. Go to Network tab
3. Reload page
4. Filter by XHR/Fetch
5. Should see:
   - `/api/auth/events/type/past/`
   - `/api/auth/events/type/recent/`
   - `/api/auth/events/type/upcoming/`
6. Click each request to inspect:
   - Status should be 200 OK
   - Response should contain JSON with events
   - Response time should be < 1s

### Check Console for Errors

1. Open Console tab
2. Should see:
   - "🎉 Initializing NeoSharX Events..."
   - "✅ Loaded X past events"
   - "✅ Loaded X recent events"
   - "✅ Loaded X upcoming events"
   - "🚀 NeoSharX Events initialized successfully!"
3. Should NOT see:
   - CORS errors
   - 404 errors
   - JavaScript errors

### Check Elements

1. Open Elements tab
2. Find `#events-carousel-section`
3. Expand to see three `<div>` columns
4. Each column should have:
   - `.scroll-container` with event cards
   - `.carousel-prev` and `.carousel-next` buttons
   - `.pagination` with dots
5. Event cards should have data-event-id attribute

## Performance Tests

### Load Time

```bash
# Measure page load time
time curl -s http://localhost:3000/index.html > /dev/null

# Should be < 1 second
```

### API Response Time

```bash
# Measure API response time
time curl -s http://localhost:8000/api/auth/events/ > /dev/null

# Should be < 500ms
```

### Image Loading

- Check that images use `loading="lazy"` attribute
- Verify thumbnails load first (400px), not full images (1200px)
- Images should appear as you scroll

## Common Issues & Fixes

### Issue: Events not loading

**Symptoms**: Empty carousels or "No events available"
**Check**:

```bash
# Verify backend is running
curl http://localhost:8000/api/auth/events/

# Verify events exist in database
cd "/Users/vishaljha/neosharx/Backend flow"
python manage.py shell -c "from authentication.models import Event; print(f'Total events: {Event.objects.count()}')"
```

**Fix**: Run `python create_sample_events.py` to create sample data

### Issue: CORS errors

**Symptoms**: Console shows "blocked by CORS policy"
**Check**: Browser DevTools Console
**Fix**: Add to `Backend flow/backend/settings.py`:

```python
CORS_ALLOWED_ORIGINS = [
    "http://localhost:3000",
]
```

### Issue: Images not loading

**Symptoms**: Broken image icons
**Check**: Image URLs in database
**Fix**: Verify image URLs are accessible (Unsplash links should work)

### Issue: Carousel not scrolling

**Symptoms**: Arrow buttons don't work, can't drag
**Check**: Browser DevTools Console for JavaScript errors
**Fix**: Verify `events-dynamic.js` is loaded (check Network tab)

### Issue: Hover effects not working

**Symptoms**: No scale or shadow on hover
**Check**: CSS is loaded properly
**Fix**: Clear browser cache, verify styles in `<style>` tag

## Automated Test Script

Run comprehensive tests:

```bash
cd "/Users/vishaljha/neosharx/Backend flow"
python test_events_api.py
```

Expected output:

```
🚀 NEOSHARX EVENTS API - COMPREHENSIVE TEST SUITE
✅ Status: 200
✅ PAST: X events
✅ RECENT: X events
✅ UPCOMING: X events
✅ Featured events: X
✅ Categories: X
✅ Retrieved event: [event name]
✅ All tests passed!
```

## Sign-Off Checklist

Before marking as complete, verify:

- [x] Backend server running on port 8000
- [x] Frontend server running on port 3000
- [x] 7 sample events created
- [x] All API endpoints working
- [x] Frontend displaying all events
- [x] Carousel navigation working
- [x] Hover effects working
- [x] Details expansion working
- [x] No console errors
- [x] No CORS errors
- [x] Images loading properly
- [x] Responsive on mobile/tablet/desktop
- [x] Admin can add/edit/delete events
- [x] Documentation complete

---

**Status**: ✅ ALL SYSTEMS OPERATIONAL

Access the events at: http://localhost:3000/index.html (scroll to "NeoSharX Events" section)
