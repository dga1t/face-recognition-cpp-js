'use strict';

const fs = require('fs');
const faceDetector = require('bindings')('faces');

// console.log(faceDetector.detectFaces('img.jpg'));

fs.readFile('./img.jpg', (err, data) => {
  if (err) throw err;

  const buffer = Buffer.from(data);

  console.log(buffer);
  console.log(Buffer.byteLength(buffer));

  faceDetector.detectFaces(buffer);
});






