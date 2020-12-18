// const fs = require('fs');

// fs.open('./img.jpg', err => {
//   if (err) throw err;
//   console.log("successfully opened img.jpg");

//   fs.close(1, err => {
//     if (err) throw err;
//     console.log("successfully closed img.jpg");
//   })
// });

const faceDetector = require('./build/Release/faces.node');

faceDetector.faces();



