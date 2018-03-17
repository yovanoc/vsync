const vsync = require('./index');
const axios = require("axios");

// let x = -1;

// setTimeout(() => x = 42, 100);

// while (x === -1) {
//   console.log('wait');
//   vsync.sleep(15);
// }

// console.log(x);

const sync = {
  _vsync: vsync,
  _done: false,
  do: function (callback, sleep = 300) {
    this._done = false;
    callback();
    this._vsync.loopWhile(() => {
      console.log(Date.now());
      return !this._done;
    });
    // while (!this._done) {
    //   console.log(Date.now());
    //   this._vsync.sleep(sleep);
    // }
  },
  done: function () {
    this._done = true;
  }
}

async function test() {
  const res = await axios.get('https://swapi.co/api/people/1');
  console.log(res.data.name);
}

console.log(`FIRST: ${Date.now()}`);
// test();
sync.do(() => test().then(() => sync.done()));
console.log(`LAST: ${Date.now()}`);