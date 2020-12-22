'use strict';

const fs = require('fs');
const faceDetector = require('bindings')('faces');
const path = require('path');

// console.log(faceDetector.detectFaces('img.jpg'));

fs.readFile('./img.jpg', (err, data) => {
  if (err) throw err;

  const size = data.length;
  const path2cascades = path.join('/usr', 'local', 'share', 'opencv4', 'haarcascades', 'haarcascade_frontalface_alt.xml');

  console.log("data.length: ", data.length);
  console.log("bytes per element: ", data.BYTES_PER_ELEMENT);
  console.log("Buffer.byteLength(data): ", Buffer.byteLength(data));

  faceDetector.detectFaces(data, size, path2cascades);
});






