# NeoSharX Frontend

A modern, responsive web application for the NeoSharX platform featuring tech news, startup stories, hackathons, and community features.

## 🚀 Quick Start

### Prerequisites
- Node.js (v14 or higher)
- npm (v6 or higher)
- Python 3 (for local server)

### Installation

1. Clone the repository and navigate to the frontend directory:
```bash
cd frontend
```

2. Install dependencies:
```bash
npm install
```

3. Build the CSS:
```bash
npm run build-css-prod
```

4. Start the development server:
```bash
npm start
```

The application will be available at `http://localhost:8000`

## 📦 Deployment

### Production Build

1. Create a production build:
```bash
npm run build
```

2. Deploy the `dist/` folder to your web server or hosting platform.

### Deployment Options

#### Static Hosting (Recommended)
- **Netlify**: Drag and drop the `dist/` folder
- **Vercel**: Connect your repository and set build command to `npm run build`
- **GitHub Pages**: Upload the `dist/` folder contents
- **AWS S3**: Upload the `dist/` folder and enable static website hosting

#### Traditional Web Server
- Upload the `dist/` folder contents to your web server's public directory
- Ensure your server can serve static files
- Configure proper MIME types for CSS and JS files

## 🛠️ Development

### Available Scripts

- `npm start` - Start development server on port 8000
- `npm run dev` - Build CSS and start development server
- `npm run build` - Create production build
- `npm run build-css` - Build CSS in watch mode
- `npm run build-css-prod` - Build minified CSS for production
- `npm run clean` - Clean the dist directory
- `npm run deploy` - Alias for build command

### Project Structure

```
frontend/
├── src/
│   └── input.css          # Tailwind CSS source
├── dist/
│   └── output.css         # Compiled CSS
├── assets/                # Images and static assets
├── auth/                  # Authentication pages
├── *.html                 # HTML pages
├── *.js                   # JavaScript files
├── *.css                  # Additional stylesheets
├── package.json           # Dependencies and scripts
├── tailwind.config.js     # Tailwind configuration
└── build-files.json       # Build configuration
```

## 🔧 Configuration

### Environment Variables
The application uses the following API endpoints (configurable in JS files):
- Backend API: `http://localhost:8001/api/`
- Authentication: `http://localhost:8001/api/auth/`

### Tailwind CSS
The project uses Tailwind CSS for styling. Configuration is in `tailwind.config.js`.

## 🌐 Features

- **Responsive Design**: Works on desktop, tablet, and mobile
- **Dark/Light Mode**: Automatic theme switching
- **Authentication**: Google and LinkedIn OAuth integration
- **Dynamic Content**: API-driven content loading
- **Modern UI**: Clean, professional interface
- **SEO Optimized**: Proper meta tags and structure

## 📱 Browser Support

- Chrome (latest)
- Firefox (latest)
- Safari (latest)
- Edge (latest)

## 🔒 Security

- HTTPS recommended for production
- Secure authentication token handling
- CORS configuration required for API access

## 📞 Support

For deployment issues or questions, please check the documentation or contact the development team.

## 📄 License

MIT License - see LICENSE file for details.