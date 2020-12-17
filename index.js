const fs = require('fs');

fs.open('./img.jpg', err => {
  if (err) throw err;
  console.log("successfully opened img.jpg");

  fs.close(1, err => {
    if (err) throw err;
    console.log("successfully closed img.jpg");
  })
});

const greetModule = require('./build/Release/greet.node');

console.log('exports: ', greetModule);
console.log();

console.log('greetModule.greetHello(): ', greetModule.greetHello());
console.log();