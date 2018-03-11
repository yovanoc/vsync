const vsyncRequire = require('bindings')('vsync');

function osync(fn) {
	return function () {
		var done = false;
		var args = Array.prototype.slice.apply(arguments).concat(cb);
		var err;
		var res;

		fn.apply(this, args);
		module.exports.loopWhile(function () {
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

module.exports = osync;

module.exports.sleep = osync(function (timeout, done) {
	setTimeout(done, timeout);
});

module.exports.runLoopOnce = function () {
	process._tickCallback();
	vsyncRequire.run();
};

module.exports.loopWhile = function (pred) {
	while (pred()) {
		process._tickCallback();
		if (pred()) vsyncRequire.run();
	}
};