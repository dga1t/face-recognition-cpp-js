'use strict';

const fs = require('fs');
const faceDetector = require('bindings')('faces');

// console.log(faceDetector.detectFaces('img.jpg'));

fs.readFile('./img.jpg', (err, buf) => {
  if (err) throw err;

  const base64data = Buffer.from(buf, 'base64');

  console.log(base64data);

  faceDetector.detectFaces(base64data);
});






