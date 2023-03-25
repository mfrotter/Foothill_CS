// The following comments are settings for various linters
// Not sure if a reported error matters? Look it up at http://linterrors.com/js
/*global console: false, window: false, document: false*/

/*jslint es5: true */
/*jslint node: false*/
/*jslint browser: true*/
/*jslint devel: true*/
/*jslint plusplus: true */

/*jshint es5: true */
/*jshint globalstrict: true*/
/*jshint jquery: true*/
/*jshint node: false*/
/*jshint browser: true*/
/*jshint devel: true*/

/*eslint-env jquery */
/*eslint-env browser*/
/*eslint no-console: 0*/

var main = function() {
	"use strict";
	// TODO: Put all your code BELOW this line in this 'main' function

	function Computer(speed, hdspace, ram) {
		this.speed = speed;
		this.hdspace = hdspace;
		this.ram = ram;
	}
	
	
	function getPrice(objectComputer){
		var thePrice = 500;
		objectComputer.speed === "4Ghz" ?  thePrice += 300 : thePrice += 100;
		objectComputer.hdspace === "1TB" ?  thePrice += 150 : thePrice += 80;
		objectComputer.ram === "16GB" ?  thePrice += 200 : thePrice += 100;
		return thePrice;
	}
	
	Computer.prototype.price = function() {
  		return getPrice(this);
	};
	
	var workComputer = new Computer("3.4Ghz", "500GB", "4GB");
	var homeComputer = new Computer("4Ghz", "1TB", "16GB");
	var laptop = new Computer("2.93Ghz", "250GB", "8GB");
	// TODO: Put all your code ABOVE this line in this 'main' function
	// Build an object/hash table/associative array of the Computer objects you were supposed to create
	// with user friendly key names using an object literal.
	var computers = {
		"Work Computer": workComputer,
		"Home Computer": homeComputer,
		Laptop: laptop
	};
	
	// Append the prices of each property in the computers object/hash
	// table/associative array
	for (var compName in computers) {
		$("#content").append("<h3>" + compName + "'s features:</h3>");
		for (var propName in computers[compName]) {
			if (propName != "price") {
				$("#content").append(
					propName + ": " + computers[compName][propName] + "<br />"
				);
			}
		}
		$("#content").append(
			"<strong>price</strong>: $" + computers[compName].price() + "<br />"
		);
	}

	$("#content").append("<br/>");
};

// Bind the main function to the window.onload event
window.onload = main;
