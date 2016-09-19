(function() {
'use strict';

angular.module('storm')

.component('dash', {
	templateUrl: 'static/dash/dash.component.html',
	controller: [DashController],
	controllerAs: 'dash'
});

function DashController() {
	
}

})();