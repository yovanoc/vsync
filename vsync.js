const vsync = require('./index');

let ret;

setTimeout(() => {
  ret = "pass";
}, 100);

while (ret === undefined) {
  console.log('wait');
  vsync.sleep(10);
}

console.log(ret);