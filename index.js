const vsyncRequire = require('bindings')('vsync');

function vsync(fn) {
	return function () {
		let done = false;
		let args = Array.prototype.slice.apply(arguments).concat(cb);
		let err;
		let res;

		fn.apply(this, args);
		module.exports.loopWhile(() => {
			return !done;
		});
		if (err)
			throw err;

		return res;

		function cb(e, r) {
			err = e;
			res = r;
			done = true;
		}
	}
}

module.exports = vsync;

module.exports.sleep = vsync((timeout, done) => {
	setTimeout(done, timeout);
});

module.exports.runLoopOnce = () => {
	process._tickCallback();
	vsyncRequire.run();
};

module.exports.loopWhile = (pred) => {
	while (pred()) {
		process._tickCallback();
		if (pred()) vsyncRequire.run();
	}
};