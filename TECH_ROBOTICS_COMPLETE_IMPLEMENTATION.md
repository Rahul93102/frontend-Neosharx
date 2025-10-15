# 🚀 TECH NEWS & ROBOTICS NEWS - COMPLETE IMPLEMENTATION

## ✅ EXACT FORMAT AS TALKS-DYNAMIC.HTML & NEO-DYNAMIC.HTML

### 📋 Overview

- **Format**: Matching talks-dynamic.html and neo-dynamic.html exactly
- **Header**: Simple title only (NO BLACK BACKGROUND)
- **Featured Section**: Auto-rotating slider with split layout (image + content)
- **Cards**: Grid layout with hover effects
- **Comments**: Professional system with nested replies, show/hide, read more/less
- **Navigation**: Consistent across all pages

---

## 📁 FILE 1: tech-news.html

### Key Features:

- ✅ Simple header: "Tech News" (no black background)
- ✅ Featured slider matching talks-dynamic.html format
- ✅ Split card layout (50% image, 50% content)
- ✅ Auto-rotation every 17 seconds
- ✅ Filter & sort options
- ✅ Professional card grid
- ✅ Links to tech-detail.html
- ✅ API: `http://127.0.0.1:8000/tech-news/`

### Structure:

```
Navigation (fixed)
↓
Simple Header
  - "Tech News" (h1, bold, centered)
  - Subtitle (gray text)
↓
Featured Slider Container
  - Split card (image left, content right)
  - Navigation arrows
  - Dots indicator
↓
Filters
  - Category dropdown
  - Sort dropdown
↓
Cards Grid (3 columns)
  - Hover effects
  - Click to detail page
```

---

## 📁 FILE 2: robotics-news.html

### Key Features:

- ✅ Simple header: "RoboSharX" (no black background)
- ✅ Same layout as tech-news.html
- ✅ API: `http://127.0.0.1:8000/robotics-news/`
- ✅ Data structure: `data.results` (not `data.articles`)
- ✅ Categories: ai_robotics, MEDICAL, INDUSTRIAL, CONSUMER, RESEARCH
- ✅ Links to robotics-detail.html

---

## 📁 FILE 3: robotics-detail.html

### Key Features:

- ✅ Copy of tech-detail.html
- ✅ API: `http://127.0.0.1:8000/robotics-news/{slug}/`
- ✅ Back link: robotics-news.html
- ✅ Professional comment system
- ✅ Nested replies with show/hide
- ✅ Read more/less for long comments
- ✅ Like functionality

---

## 🎨 DESIGN SPECIFICATIONS

### Colors (Black/Gray/White Only):

```css
--black: #000000;
--gray-50: #f9fafb;
--gray-100: #f3f4f6;
--gray-200: #e5e7eb;
--gray-300: #d1d5db;
--gray-400: #9ca3af;
--gray-500: #6b7280;
--gray-600: #4b5563;
--gray-700: #374151;
--gray-800: #1f2937;
--gray-900: #111827;
--white: #ffffff;
```

### Featured Slider Specs:

- Container: White background, rounded corners (1rem), border (1px solid gray-200)
- Split layout: `grid-template-columns: 1fr 1fr`
- Media section: Min height 360px
- Content section: Padding 2.5rem, gray-50 background
- Badge: Black background, white text, top-left absolute position
- Navigation: Circular buttons, white background with hover
- Dots: Bottom center, active dot is elongated
- Auto-rotation: 17 seconds interval

### Card Specs:

- Grid: 3 columns on desktop, 1 on mobile
- Background: White with border (1px solid gray-200)
- Border radius: 1rem
- Image: 250px height, object-fit cover
- Hover: translateY(-4px), box-shadow increase
- Padding: 1.5rem
- Category badge: Gray background, uppercase, small font
- Title: Bold, gray-900, 1.25rem
- Excerpt: Gray-600, 0.95rem, 1.6 line height
- Meta: Border-top, flex layout, icons + text

### Comment System Specs:

- Container: Max-width 1200px, auto margin
- Comment box: White background, rounded (12px), border (1px solid gray-200)
- Hover effect: Box shadow, border color change
- Avatar: Circular gradient (purple), initials centered
- Reply indentation: Margin-left 3rem, gray background
- Show/Hide button: Gray background, rounded, hover effect
- Read More button: Blue text (#3b82f6), underline on hover
- Like button: Gray-500, hover to gray-900
- Max comment height: 4.5em (3 lines), overflow hidden
- Nested replies: Up to 3 levels deep

---

## 📊 API ENDPOINTS

### Tech News:

- **List**: `GET http://127.0.0.1:8000/tech-news/`
- **Detail**: `GET http://127.0.0.1:8000/tech-news/{slug}/`
- **Response**: `{ articles: [...] }`
- **Categories**: AI_ML, BLOCKCHAIN, CYBERSECURITY, FUNDING, PRODUCT_LAUNCH

### Robotics News:

- **List**: `GET http://127.0.0.1:8000/robotics-news/`
- **Detail**: `GET http://127.0.0.1:8000/robotics-news/{slug}/`
- **Response**: `{ results: [...] }` ⚠️ Note: Different from tech-news!
- **Categories**: ai_robotics, MEDICAL, INDUSTRIAL, CONSUMER, RESEARCH

### Comments:

- **List**: `GET http://localhost:8000/api/auth/comments/?content_type={type}&content_slug={slug}`
- **Post**: `POST http://localhost:8000/api/auth/comments/`
- **Like**: `POST http://localhost:8000/api/auth/comments/{id}/like/`
- **Delete**: `DELETE http://localhost:8000/api/auth/comments/{id}/`

---

## 🔧 JAVASCRIPT FUNCTIONS

### Featured Slider:

```javascript
// Auto-rotation
let sliderInterval = setInterval(() => {
  nextSlide();
}, 17000); // 17 seconds

// Navigation
function nextSlide() {
  currentIndex = (currentIndex + 1) % featured.length;
  renderFeatured();
}

function prevSlide() {
  currentIndex = (currentIndex - 1 + featured.length) % featured.length;
  renderFeatured();
}

// Reset on manual navigation
function resetSlider() {
  clearInterval(sliderInterval);
  sliderInterval = setInterval(() => nextSlide(), 17000);
}
```

### Comment System:

```javascript
// Show/Hide Replies
function toggleReplies(commentId) {
  const repliesContainer = document.getElementById(`replies-${commentId}`);
  const button = document.getElementById(`toggle-btn-${commentId}`);

  if (repliesContainer.style.display === "none") {
    repliesContainer.style.display = "block";
    button.textContent = "Hide Replies ▲";
  } else {
    repliesContainer.style.display = "none";
    button.textContent = `Show ${replyCount} Replies ▼`;
  }
}

// Read More/Less
function toggleReadMore(commentId) {
  const textEl = document.getElementById(`text-${commentId}`);
  const button = document.getElementById(`readmore-${commentId}`);

  if (textEl.classList.contains("truncated")) {
    textEl.classList.remove("truncated");
    textEl.style.maxHeight = "none";
    button.textContent = "Read Less";
  } else {
    textEl.classList.add("truncated");
    textEl.style.maxHeight = "4.5em";
    button.textContent = "Read More";
  }
}
```

---

## 🧪 TESTING CHECKLIST

### Navigation:

- [ ] Click "Tech News" → goes to tech-news.html
- [ ] Click "RoboSharX" → goes to robotics-news.html
- [ ] Active page highlighted in navigation
- [ ] Navigation looks same on all pages
- [ ] Mobile menu works correctly

### Tech News Page:

- [ ] Title shows "Tech News" (no black background)
- [ ] Featured slider loads and auto-rotates (17s)
- [ ] Can click prev/next arrows
- [ ] Can click dots to navigate
- [ ] Cards grid displays (3 columns desktop)
- [ ] Category filter works
- [ ] Sort filter works
- [ ] Click card → goes to tech-detail.html
- [ ] Hover effects work on cards
- [ ] Responsive on mobile (1 column)

### Robotics News Page:

- [ ] Title shows "RoboSharX" (no black background)
- [ ] Featured slider auto-rotates
- [ ] Cards load from /robotics-news/ endpoint
- [ ] Uses `data.results` not `data.articles`
- [ ] Categories: ai_robotics, MEDICAL, etc.
- [ ] Click card → goes to robotics-detail.html
- [ ] Same design as tech-news page

### Tech Detail Page:

- [ ] Loads article from slug parameter
- [ ] Shows hero image
- [ ] Shows title, category, content
- [ ] Back button → tech-news.html
- [ ] Comment section loads
- [ ] Can see nested replies
- [ ] Show/Hide replies button works
- [ ] Read More/Less works for long comments
- [ ] Like button works
- [ ] Reply button works (if logged in)

### Robotics Detail Page:

- [ ] Loads from /robotics-news/{slug}/
- [ ] Back button → robotics-news.html
- [ ] All comment features work
- [ ] Same design as tech-detail page

### Comment System:

- [ ] Comments load correctly
- [ ] Nested replies indented (gray background)
- [ ] Show/Hide button shows reply count
- [ ] Clicking Show reveals replies
- [ ] Clicking Hide collapses replies
- [ ] Long comments (>3 lines) truncated
- [ ] Read More button appears for long comments
- [ ] Read More expands full text
- [ ] Read Less collapses back
- [ ] Like button increments count
- [ ] Avatar shows first letter of username
- [ ] Time shows relative format ("2 hours ago")
- [ ] Can post new comment (if logged in)
- [ ] Login prompt shows if not logged in

---

## 🎯 IMPLEMENTATION STEPS

### Step 1: Create tech-news.html

```bash
cd /Users/vishaljha/neosharx/frontend
# Create file with featured slider format
# Use talks-dynamic.html as template
# Change title to "Tech News"
# API: /tech-news/
# Links: tech-detail.html
```

### Step 2: Create robotics-news.html

```bash
# Copy tech-news.html
# Change title to "RoboSharX"
# API: /robotics-news/
# Change data.articles → data.results
# Change categories
# Links: robotics-detail.html
```

### Step 3: Create robotics-detail.html

```bash
# Copy tech-detail.html
# API: /robotics-news/{slug}/
# Back link: robotics-news.html
# data-page="robotics-detail"
# Keep comment system
```

### Step 4: Test Everything

```bash
# Open in browser
# Test all navigation links
# Test sliders
# Test comments
# Test filters
# Test responsive design
```

---

## 📝 QUICK REFERENCE

### File Locations:

- `frontend/tech-news.html` - Tech news listing
- `frontend/robotics-news.html` - Robotics news listing
- `frontend/tech-detail.html` - Tech article detail
- `frontend/robotics-detail.html` - Robotics article detail
- `frontend/navigation.html` - Site navigation
- `frontend/comment-system.js` - Comment functionality

### Navigation Links:

- Tech News: `href="tech-news.html" data-page="tech"`
- RoboSharX: `href="robotics-news.html" data-page="robotics"`

### Data Pages:

- tech-news.html: `data-page="tech"`
- robotics-news.html: `data-page="robotics"`
- tech-detail.html: `data-page="tech-detail"`
- robotics-detail.html: `data-page="robotics-detail"`

---

## ✅ SUCCESS CRITERIA

1. **Visual Match**: Pages look exactly like talks-dynamic.html and neo-dynamic.html
2. **No Black Headers**: Only simple text titles, no fixed black background sections
3. **Featured Slider**: Split layout (image/content), auto-rotation, navigation arrows
4. **Professional Comments**: Nested replies, show/hide, read more/less, like buttons
5. **Consistent Navigation**: Same navigation bar on all pages with active highlighting
6. **Responsive**: Works on desktop (3 columns) and mobile (1 column)
7. **Working Links**: All navigation and detail page links functional
8. **API Integration**: Correctly fetches from Django endpoints

---

## 🎉 COMPLETION STATUS

- [🔄] tech-news.html - Creating now
- [⏳] robotics-news.html - Pending
- [⏳] robotics-detail.html - Pending
- [✅] navigation.html - Already updated
- [⏳] Comment system integration - Pending
- [⏳] Testing - Pending

---

**Let's implement this step by step!** 🚀
