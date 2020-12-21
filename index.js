'use strict';

const fs = require('fs');
const faceDetector = require('bindings')('faces');

console.log(faceDetector.detectFaces('img.jpg'));

// fs.open('./img.jpg', 'r', (err, f) => {
//   if (err) throw err;

//   faceDetector.detectFaces(f);

//   fs.close(f, err => {
//     if (err) throw err;
//   })
// });






