let http = require('http');
let fs = require('fs');
let path = require('path');

let mimeTypes = {
    '.html': 'text/html',
    '.js': 'text/javascript',
    '.mjs': 'text/javascript',
    '.css': 'text/css',
    '.wasm': 'application/wasm',
    '.data': 'application/octet-stream',
    '.svg': 'image/svg+xml'
};

let server = http.createServer((req, res) => {
    res.setHeader('Cross-Origin-Opener-Policy', 'same-origin');
    res.setHeader('Cross-Origin-Embedder-Policy', 'require-corp');

    let filePath = path.join(__dirname, req.url == '/' ? 'index.html' : req.url);
    let ext = path.extname(filePath);

    let cacheControl;
    if (req.url.startsWith('/docs/'))
        cacheControl = 'public, max-age=31536000, immutable';
    else if (ext == '.html')
        cacheControl = 'no-cache';
    else
        cacheControl = 'public, max-age=31536000, immutable';

    fs.readFile(filePath, (error, data) => {
        if (error) {
            res.writeHead(404);
            res.end('Not found');
            return;
        }
        res.writeHead(200, { 'Content-Type': mimeTypes[ext] || 'application/octet-stream', 'Cache-Control': cacheControl });
        res.end(data);
    });
});

server.listen(8000, () => {
    console.log('Server running at http://localhost:8000');
});