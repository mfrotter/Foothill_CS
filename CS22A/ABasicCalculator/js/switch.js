//Names: Mitchell Rotter-Sieren & Brandon Cunnane
// The following comments are settings for various linters
// Not sure if a reported error matters? Look it up at http://linterrors.com/js
/*global math: false, calc: false, console: false, eval: false */

/*jslint es5: true */
/*jslint node: false*/
/*jslint browser: true*/
/*jslint devel: true*/
/*jslint plusplus: true */
/*jslint evil: true */

/*jshint es5: true */
/*jshint globalstrict: true*/
/*jshint jquery: false*/
/*jshint node: false*/
/*jshint browser: true*/
/*jshint devel: true*/

/*eslint-env jquery: false*/
/*eslint-env browser*/
/*eslint no-console: 0*/

// CS22A: A Basic Calculator Part 2 - calcu() function with switch
//////////////////////////////////////////////////////////////////////////////////////////////
// The value from the HTML page is passed through calcu() as a parameter argument,
// e.g., calcu('1') which takes the place of 'calcValue' entering the function below
// which is then passed to the switch for comparison. If the value of calcValue equals
// '1' then the first case of the switch will be true and the value of the output text
// box will be a '1' with the += concatenating this value every time the button is pressed.
// The math.eval() function at the bottom turns all the concatenated string into an arithmetic
// equation that can be evaluated, thus allowing the calculator to produce a viable answer.
//////////////////////////////////////////////////////////////////////////////////////////////

var calcu = function(calcValue) {
	"use strict";
	console.log(calcValue);
	switch (calcValue) {
		case "  C  ":
			calc.reset();
			break;
			
		case "  =  ":
			// use the math.eval() function from the Math.js math library to parse and evaluate the String with mathematics in it
			calc.output.value = math.eval(calc.output.value);
			break;
			
		case "  x  ":
			calc.output.value += "*"; //had to make special case because x doesn't work in math.eval
			break;
			
		case "÷":
			calc.output.value += "/"; //had to make special case because ÷ doesn't work in math.eval
			break;
			
		default:
			calc.output.value += calcValue.replace(/\s/g,''); //removes spaces from this.value
			break;
	}
};
