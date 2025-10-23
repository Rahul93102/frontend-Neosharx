# 🔌 YouTube API Integration Guide - Complete Developer Reference

## 📌 Overview

Your SharXathon backend provides **complete REST API endpoints** for YouTube video management. This guide covers:

- All available endpoints
- Request/response formats
- Authentication requirements
- Error handling
- Integration examples

---

## 🔗 API Base URL

```
http://localhost:8001/api/auth/
```

Change `localhost:8001` based on your environment:

- **Development**: `http://localhost:8001/`
- **Production**: `https://yourdomain.com/`
- **Staging**: `https://staging.yourdomain.com/`

---

## 🎬 YouTube Videos Endpoints

### 1. List All Published Videos

**Endpoint**:

```
GET /api/auth/youtube-videos/
```

**Description**: Get all published YouTube videos with pagination

**Query Parameters**:

```
?video_type=video          # Filter by type: "video" or "short"
?category=hackathons       # Filter by category
?featured=true             # Get only featured videos
?limit=10                  # Items per page (default: 20)
?offset=0                  # Pagination offset
?search=query              # Search title/description
```

**Response** (200 OK):

```json
{
  "count": 15,
  "next": "http://localhost:8001/api/auth/youtube-videos/?offset=20",
  "previous": null,
  "results": [
    {
      "id": 1,
      "title": "SharXathon 2025 Kickoff",
      "slug": "sharxathon-2025-kickoff",
      "description": "Join us for the launch event...",
      "video_type": "video",
      "category": "hackathons",
      "youtube_url": "https://www.youtube.com/watch?v=dQw4w9WgXcQ",
      "video_id": "dQw4w9WgXcQ",
      "embed_url": "https://www.youtube.com/embed/dQw4w9WgXcQ",
      "thumbnail_url": "https://img.youtube.com/vi/dQw4w9WgXcQ/maxresdefault.jpg",
      "duration": "15:32",
      "is_featured": true,
      "is_published": true,
      "autoplay": false,
      "display_order": 0,
      "tags": "hackathon,education,tips",
      "created_at": "2025-01-15T10:30:00Z",
      "updated_at": "2025-01-15T10:30:00Z",
      "internal_views": 145
    }
    // ... more videos
  ]
}
```

---

### 2. Get Featured Videos

**Endpoint**:

```
GET /api/auth/youtube-videos/featured/
```

**Description**: Get only featured videos (highlighted on homepage)

**Query Parameters**:

```
?limit=6                   # Usually set to 6 for homepage
?video_type=video          # Optional: filter by type
```

**Response** (200 OK):

```json
{
  "count": 3,
  "next": null,
  "previous": null,
  "results": [
    {
      "id": 1,
      "title": "SharXathon 2025 Kickoff"
      // ... full video object (see list endpoint)
    }
    // ... more featured videos
  ]
}
```

---

### 3. Get Videos by Type

**Endpoint**:

```
GET /api/auth/youtube-videos/type/{video_type}/
```

**Description**: Filter videos by type (video or short)

**Parameters**:

- `{video_type}`: Either `"video"` or `"short"`

**Example**:

```
GET /api/auth/youtube-videos/type/video/
GET /api/auth/youtube-videos/type/short/
```

**Query Parameters**:

```
?category=hackathons       # Optional: also filter by category
?featured=true             # Optional: featured only
?limit=20                  # Optional: items per page
```

**Response** (200 OK):

```json
{
  "count": 8,
  "next": null,
  "previous": null,
  "results": [
    // ... videos of specified type
  ]
}
```

---

### 4. Get Specific Video

**Endpoint**:

```
GET /api/auth/youtube-videos/{slug}/
```

**Description**: Get detailed information about one video

**Parameters**:

- `{slug}`: Video slug (auto-generated from title)

**Example**:

```
GET /api/auth/youtube-videos/sharxathon-2025-kickoff/
```

**Response** (200 OK):

```json
{
  "id": 1,
  "title": "SharXathon 2025 Kickoff",
  "slug": "sharxathon-2025-kickoff",
  "description": "Join us for the launch event of SharXathon 2025...",
  "video_type": "video",
  "category": "hackathons",
  "youtube_url": "https://www.youtube.com/watch?v=dQw4w9WgXcQ",
  "video_id": "dQw4w9WgXcQ",
  "embed_url": "https://www.youtube.com/embed/dQw4w9WgXcQ",
  "thumbnail_url": "https://img.youtube.com/vi/dQw4w9WgXcQ/maxresdefault.jpg",
  "duration": "15:32",
  "is_featured": true,
  "is_published": true,
  "autoplay": false,
  "display_order": 0,
  "tags": "hackathon,education,tips",
  "created_at": "2025-01-15T10:30:00Z",
  "updated_at": "2025-01-15T10:30:00Z",
  "internal_views": 145,
  "related_sharxathons": [
    {
      "id": 1,
      "name": "SharXathon 2025",
      "slug": "sharxathon-2025"
    }
  ]
}
```

---

### 5. Get Videos by Category

**Endpoint**:

```
GET /api/auth/youtube-videos/category/{category}/
```

**Description**: Get videos in specific category

**Parameters**:

- `{category}`: One of:
  - `tech_talks`
  - `tutorials`
  - `startup_stories`
  - `hackathons` ← **For SharXathon videos**
  - `events`
  - `interviews`
  - `demos`
  - `other`

**Example**:

```
GET /api/auth/youtube-videos/category/hackathons/
```

**Response** (200 OK):

```json
{
  "count": 5,
  "next": null,
  "previous": null,
  "results": [
    // ... videos in hackathons category
  ]
}
```

---

## 🏆 SharXathon Hackathon Endpoints

### 6. Get Hackathon Videos

**Endpoint**:

```
GET /api/auth/hackathons/{slug}/videos/
```

**Description**: Get all videos linked to a specific hackathon

**Parameters**:

- `{slug}`: Hackathon slug (e.g., "sharxathon-2025")

**Example**:

```
GET /api/auth/hackathons/sharxathon-2025/videos/
```

**Response** (200 OK):

```json
{
  "hackathon_name": "SharXathon 2025",
  "hackathon_slug": "sharxathon-2025",
  "video_count": 3,
  "videos": [
    {
      "id": 1,
      "title": "SharXathon 2025 Kickoff",
      "slug": "sharxathon-2025-kickoff"
      // ... full video object
    },
    {
      "id": 2,
      "title": "Winning Projects Showcase"
      // ... more videos
    }
  ]
}
```

**Error Response** (404 Not Found):

```json
{
  "detail": "Hackathon not found"
}
```

---

### 7. Get Hackathon Details (With Videos)

**Endpoint**:

```
GET /api/auth/hackathons/{slug}/
```

**Description**: Get complete hackathon information including linked videos

**Parameters**:

- `{slug}`: Hackathon slug

**Response** (200 OK):

```json
{
  "id": 1,
  "name": "SharXathon 2025",
  "slug": "sharxathon-2025",
  "description": "...",
  "start_date": "2025-02-01T00:00:00Z",
  "end_date": "2025-02-03T23:59:59Z",
  "location": "Virtual",
  "is_published": true,
  "theme": "Sustainable Tech",
  "max_team_members": 4,

  // Videos section (NEW!)
  "videos": [
    {
      "id": 1,
      "title": "SharXathon 2025 Kickoff",
      "video_id": "dQw4w9WgXcQ",
      "embed_url": "https://www.youtube.com/embed/dQw4w9WgXcQ",
      "thumbnail_url": "https://img.youtube.com/vi/dQw4w9WgXcQ/maxresdefault.jpg"
    }
  ],

  "judges": [
    {
      "id": 1,
      "name": "Judge Name",
      "title": "CTO"
    }
  ],
  "winners": [
    {
      "id": 1,
      "team_name": "Winning Team",
      "position": 1
    }
  ]
}
```

---

## 🔐 Authentication

### Public Endpoints

All YouTube video endpoints are **PUBLIC** (no authentication required):

- ✅ List all videos
- ✅ Get featured videos
- ✅ Get specific video
- ✅ Get hackathon videos
- ✅ Get hackathon details

### Private Endpoints

To create/edit/delete videos (backend admin only):

- Use Django admin panel
- Or use token authentication for programmatic access

**Token Authentication**:

```
Authorization: Token YOUR_AUTH_TOKEN
```

---

## 💻 Integration Examples

### Example 1: Display Featured Videos on Homepage

```javascript
// Fetch featured videos
fetch("http://localhost:8001/api/auth/youtube-videos/featured/?limit=6")
  .then((response) => response.json())
  .then((data) => {
    // Create video cards
    data.results.forEach((video) => {
      const card = `
        <div class="video-card">
          <img src="${video.thumbnail_url}" alt="${video.title}">
          <h3>${video.title}</h3>
          <button onclick="watchVideo('${video.video_id}')">Watch</button>
        </div>
      `;
      document.getElementById("videos-container").innerHTML += card;
    });
  });
```

---

### Example 2: Get Videos for Specific Hackathon

```javascript
// Fetch videos for a hackathon
const hackathonSlug = "sharxathon-2025";
fetch(`http://localhost:8001/api/auth/hackathons/${hackathonSlug}/videos/`)
  .then((response) => response.json())
  .then((data) => {
    console.log(`Found ${data.video_count} videos`);

    data.videos.forEach((video) => {
      console.log(`${video.title}: ${video.embed_url}`);
    });
  });
```

---

### Example 3: Filter Videos by Category

```javascript
// Get only hackathon videos
fetch(
  "http://localhost:8001/api/auth/youtube-videos/?category=hackathons&featured=true"
)
  .then((response) => response.json())
  .then((data) => {
    // Use in carousel, grid, etc.
    displayVideos(data.results);
  });
```

---

### Example 4: Embed Video in Modal

```javascript
function openVideoModal(videoId, embedUrl) {
  const modal = document.getElementById("video-modal");
  const iframe = modal.querySelector("iframe");

  // Set embed URL (removes watch?v= and uses embed format)
  iframe.src = embedUrl;

  // Show modal
  modal.style.display = "flex";
}

function closeVideoModal() {
  const modal = document.getElementById("video-modal");
  const iframe = modal.querySelector("iframe");

  // Stop video by removing src
  iframe.src = "";

  // Hide modal
  modal.style.display = "none";
}
```

---

### Example 5: Python Backend Integration

```python
import requests

BASE_URL = 'http://localhost:8001/api/auth/'

# Get featured videos
response = requests.get(f'{BASE_URL}youtube-videos/featured/')
videos = response.json()['results']

for video in videos:
    print(f"Title: {video['title']}")
    print(f"Embed URL: {video['embed_url']}")
    print(f"Thumbnail: {video['thumbnail_url']}")
    print("---")
```

---

## 📊 Response Field Reference

### Video Object Fields

| Field                 | Type     | Description            | Example                           |
| --------------------- | -------- | ---------------------- | --------------------------------- |
| `id`                  | integer  | Unique video ID        | 1                                 |
| `title`               | string   | Video title            | "SharXathon Kickoff"              |
| `slug`                | string   | URL-friendly slug      | "sharxathon-kickoff"              |
| `description`         | string   | Long description       | "Join us for..."                  |
| `video_type`          | string   | "video" or "short"     | "video"                           |
| `category`            | string   | Video category         | "hackathons"                      |
| `youtube_url`         | string   | YouTube watch URL      | "https://youtube.com/watch?v=..." |
| `video_id`            | string   | YouTube video ID       | "dQw4w9WgXcQ"                     |
| `embed_url`           | string   | YouTube embed URL      | "https://youtube.com/embed/..."   |
| `thumbnail_url`       | string   | YouTube thumbnail      | "https://img.youtube.com/vi/..."  |
| `duration`            | string   | Video length           | "15:32"                           |
| `is_featured`         | boolean  | Featured on homepage   | true                              |
| `is_published`        | boolean  | Visible to users       | true                              |
| `autoplay`            | boolean  | Auto-play on load      | false                             |
| `display_order`       | integer  | Sort position          | 0                                 |
| `tags`                | string   | Comma-separated tags   | "hackathon,tips"                  |
| `created_at`          | datetime | Creation timestamp     | "2025-01-15T10:30:00Z"            |
| `updated_at`          | datetime | Last update timestamp  | "2025-01-15T10:30:00Z"            |
| `internal_views`      | integer  | Views on your platform | 145                               |
| `related_sharxathons` | array    | Linked hackathons      | [...]                             |

---

## ❌ Error Handling

### Common Errors

**404 Not Found**:

```json
{
  "detail": "Not found."
}
```

- Check slug is correct
- Check video/hackathon is published

**400 Bad Request**:

```json
{
  "detail": "Invalid query parameters"
}
```

- Check category name is valid
- Check limit/offset are numbers

**500 Server Error**:

- Backend server down
- Database connection issue
- Check logs: `tail -f /path/to/backend/logs`

---

## 🔄 Pagination

For endpoints returning lists, use pagination:

```
?limit=20                  # Items per page (default: 20)
?offset=0                  # Start position (default: 0)
```

**Response includes**:

```json
{
  "count": 50,             // Total items available
  "next": "...?offset=20", // Next page URL
  "previous": null,        // Previous page URL
  "results": [...]         // Current page items
}
```

**Example - Get next page**:

```javascript
let nextUrl = data.next;
if (nextUrl) {
  fetch(nextUrl).then(response => response.json())...
}
```

---

## 🚀 Performance Tips

1. **Use pagination** - Don't fetch all videos at once
2. **Use featured endpoint** - Faster for homepage (fewer results)
3. **Filter by category** - Reduces data transfer
4. **Cache responses** - Videos don't change frequently
5. **Use thumbnails** - Faster loading than full videos

---

## 📱 Mobile Considerations

- **Responsive embeds**: Use CSS to scale iframes
- **Thumbnail size**: Optimized (maxresdefault 1280×720)
- **Mobile URLs**: YouTube auto-detects device
- **Data saving**: Show thumbnails, load video on click

---

## 🔒 Data Privacy

- Video URLs are publicly available (to show videos)
- YouTube handles video streaming (not your server)
- Create/edit/delete restricted to Django admin
- No personal data required to view videos
- Views counter is internal (not sent to YouTube)

---

## 📞 Support

For API issues:

1. Check Django admin - verify video exists and is published
2. Check URL format - use correct base URL for environment
3. Check network - ensure backend server is running
4. Check logs - review backend error logs
5. Verify video_id - should be extracted correctly

---

## 📚 Related Documentation

- **Admin Guide**: YOUTUBE_BACKEND_ADMIN_GUIDE.md
- **Frontend Guide**: hackathon-detail.html
- **Models**: Backend flow/authentication/models.py
- **Views**: Backend flow/authentication/views.py
- **Serializers**: Backend flow/authentication/serializers.py

---

## ✨ API Status

- ✅ All YouTube video endpoints functional
- ✅ Hackathon video endpoints functional
- ✅ Pagination working
- ✅ Filtering working
- ✅ Search working
- ✅ Authentication integrated
- ✅ CORS configured
- ✅ Error handling implemented

---

**API Version**: 1.0.0  
**Date**: October 19, 2025  
**Status**: ✅ PRODUCTION READY

For the latest API changes, check the backend repository.
