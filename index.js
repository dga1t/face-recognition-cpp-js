'use strict';

const fs = require('fs');
const faceDetector = require('bindings')('faces');
const path = require('path');

fs.readFile('./img.jpg', (err, data) => {
  if (err) throw err;

  const size = data.length;
  const path2cscds = path.join('/usr', 'local', 'share', 'opencv4', 'haarcascades', 'haarcascade_frontalface_alt.xml');

  faceDetector.detectFaces(data.buffer, size, path2cscds);
});






