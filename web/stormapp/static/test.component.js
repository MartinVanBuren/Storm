(function() {
'use strict';

angular.module('storm')

.component('test', {
	templateUrl: 'static/test.component.html',
	controller: [TestController],
	controllerAs: 'test'
});

function TestController() {
	
}

})();