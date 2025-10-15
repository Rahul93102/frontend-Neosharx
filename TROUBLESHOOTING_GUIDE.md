# Quick Troubleshooting Guide 🔧

## Problem: UI Not Displaying Events/Videos

### Step 1: Is Backend Running? ✅

**Check Terminal:**

```bash
# You should see this:
Starting development server at http://127.0.0.1:8000/
Quit the server with CONTROL-C.
```

**If NOT running:**

```bash
cd "/Users/vishaljha/neosharx/Backend flow"
python manage.py runserver 8000
```

---

### Step 2: Test API Directly ✅

**Open in browser:**

```
http://127.0.0.1:8000/api/auth/events/
```

**Should see JSON like:**

```json
{
  "results": [
    {"id": 12, "name": "AI Hackathon 2025", ...}
  ],
  "count": 12
}
```

**If you see HTML login page** ❌:

- This means Django REST framework is requiring authentication
- Go to `Backend flow/authentication/views.py`
- Check that views have `@permission_classes([AllowAny])`

**If you see JSON** ✅:

- Backend is working!
- Continue to next step

---

### Step 3: Check Browser Console ✅

**Open homepage:**

```bash
open "/Users/vishaljha/neosharx/frontend/index.html"
```

**Press F12 to open Console**

**Look for these logs:**

```
✅ Initializing backend connections...
✅ API Base URL: http://127.0.0.1:8000/api/auth
✅ Fetching events from backend...
✅ Response status: 200 200 200
✅ Events loaded successfully!
✅ Fetching YouTube videos from backend...
✅ YouTube videos response status: 200
✅ YouTube videos loaded successfully!
```

**If you see errors instead:**

#### Error: "Failed to fetch"

**Cause**: Backend not running or wrong URL
**Fix**:

1. Start backend server
2. Check API_BASE_URL in index.html (line 1139)

#### Error: "CORS policy"

**Cause**: CORS not configured
**Fix**: Check `Backend flow/backend/settings.py`:

```python
INSTALLED_APPS = [
    ...
    'corsheaders',
]

MIDDLEWARE = [
    'corsheaders.middleware.CorsMiddleware',  # Must be first
    ...
]

CORS_ALLOW_ALL_ORIGINS = True  # For development
```

#### Error: "NetworkError" or "ERR_CONNECTION_REFUSED"

**Cause**: Backend server stopped or port changed
**Fix**:

1. Restart backend on port 8000
2. Check firewall isn't blocking localhost

---

### Step 4: Check HTML Elements ✅

**Open Console and run:**

```javascript
// Check if containers exist
console.log(
  "Events section:",
  document.getElementById("events-carousel-section")
);
console.log(
  "Videos container:",
  document.getElementById("youtube-videos-container")
);

// Both should NOT be null
```

**If null:**

- HTML structure might be broken
- Check index.html for these IDs

---

### Step 5: Test with api-test.html ✅

**Open test page:**

```bash
open "/Users/vishaljha/neosharx/frontend/api-test.html"
```

**This page will:**

- Auto-test all APIs
- Show detailed responses
- Display errors clearly

**Look for:**

- ✅ Green boxes = Working
- ❌ Red boxes = Errors
- ⏳ Yellow boxes = Loading

---

## Common Fixes

### Fix 1: Restart Everything

```bash
# Kill backend
lsof -ti:8000 | xargs kill -9

# Start fresh
cd "/Users/vishaljha/neosharx/Backend flow"
python manage.py runserver 8000

# Open frontend
open "/Users/vishaljha/neosharx/frontend/index.html"
```

### Fix 2: Clear Browser Cache

```
Mac: Cmd + Shift + R
Windows: Ctrl + Shift + R
```

### Fix 3: Check Data is Published

```
1. Open http://127.0.0.1:8000/admin/
2. Login
3. Check Authentication → Events
4. Verify "Is published" is checked ✅
5. Check Authentication → Youtube Videos
6. Verify "Is published" is checked ✅
```

### Fix 4: Verify API Responses

```bash
# Test events
curl http://127.0.0.1:8000/api/auth/events/

# Test videos
curl http://127.0.0.1:8000/api/auth/youtube-videos/
```

---

## Still Not Working?

### Checklist:

- [ ] Backend server running (terminal shows "Starting development server")
- [ ] Port 8000 is accessible (try http://127.0.0.1:8000/admin/)
- [ ] Browser console shows no errors
- [ ] API returns JSON (not HTML login page)
- [ ] Data exists and is published in admin
- [ ] CORS is configured in settings.py
- [ ] Frontend HTML has correct container IDs
- [ ] API_BASE_URL matches backend address

### Debug Command Sequence:

```bash
# 1. Check backend status
curl http://127.0.0.1:8000/api/auth/events/

# 2. If that works, check from browser console:
fetch('http://127.0.0.1:8000/api/auth/events/')
  .then(r => r.json())
  .then(d => console.log('Events:', d))
  .catch(e => console.error('Error:', e));

# 3. Check server logs for requests
# Terminal running Django server should show:
# [12/Oct/2025 08:18:23] "GET /api/auth/events/ HTTP/1.1" 200
```

---

## Expected Behavior

### When Everything Works:

1. **Backend Terminal:**

   ```
   [12/Oct/2025] "GET /api/auth/events/type/past/ HTTP/1.1" 200
   [12/Oct/2025] "GET /api/auth/events/type/recent/ HTTP/1.1" 200
   [12/Oct/2025] "GET /api/auth/events/type/upcoming/ HTTP/1.1" 200
   [12/Oct/2025] "GET /api/auth/youtube-videos/ HTTP/1.1" 200
   ```

2. **Browser Console:**

   ```
   Initializing backend connections...
   Fetching events from backend...
   Past events: {count: 3, results: Array(3)}
   Recent events: {count: 2, results: Array(2)}
   Upcoming events: {count: 7, results: Array(7)}
   Events loaded successfully!
   Fetching YouTube videos from backend...
   Displaying 5 videos
   YouTube videos loaded successfully!
   ```

3. **Homepage Display:**
   - Events section has 3 carousels
   - Each carousel shows event cards
   - Videos section shows grid of videos
   - Videos are autoplaying (muted)
   - All images/thumbnails load

---

## Quick Reference

### Backend URLs:

```
Server:    http://127.0.0.1:8000/
Admin:     http://127.0.0.1:8000/admin/
Events:    http://127.0.0.1:8000/api/auth/events/
Videos:    http://127.0.0.1:8000/api/auth/youtube-videos/
```

### Frontend Files:

```
Main Page:  /Users/vishaljha/neosharx/frontend/index.html
Test Page:  /Users/vishaljha/neosharx/frontend/api-test.html
```

### Important Code Locations:

```
API Base URL:       index.html line 1139
Fetch Events:       index.html line 1326
Fetch Videos:       index.html line 1395
Events Container:   index.html line 940
Videos Container:   index.html line 1126
```

---

_Quick Troubleshooting Guide - October 12, 2025_
