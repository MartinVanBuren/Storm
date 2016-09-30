(function() {
'use strict';

angular.module('storm', ['ngComponentRouter'])

.config(function($locationProvider) {
	$locationProvider.html5Mode(true);
})

.value('$routerRootComponent', 'storm')

.component('storm', {
	templateUrl: 'static/storm.component.html',
	$routeConfig: [
		{ path: '/', name: 'Dash', component: 'dash', useAsDefault: true },
		{ path: '/test', name: 'Test', component: 'test' }
	],
	controller: [NavController],
	controllerAs: 'nav'
});

function NavController() {
	
}
	

})();