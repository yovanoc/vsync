const vsync = require('./index');

let x = -1;

setTimeout(() => x = 42, 100);

while (x === -1) {
  console.log('wait');
  vsync.sleep(15);
}

console.log(x);