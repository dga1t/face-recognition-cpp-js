const fs = require('fs');
const faceDetector = require('./build/Release/faces.node');

fs.open('./img.jpg', 'r', (err, f) => {
  if (err) throw err;

  faceDetector.detectFaces(f);

  fs.close(f, err => {
    if (err) throw err;
  })
});






