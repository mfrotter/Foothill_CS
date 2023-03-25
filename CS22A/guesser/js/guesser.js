// The following comments are settings for various linters
/*jslint es6: true*/ // Causes an "Unexpected 'es6'." warning in JSLint that you should ignore.
/*jshint globalstrict: true*/
/*jshint esversion: 6 */
/*jshint jquery: false*/
/*jshint node: false*/
/*jshint browser: true*/
/*jshint devel: true*/
/*eslint-env es6*/
/*eslint-env jquery: false*/
/*eslint-env browser*/
/*eslint no-console: 0*/

/*
 * INSTRUCTIONS:
 * Make a guessing game where the computer guesses what the human user's
 * number is between 0 and 100 (inclusive). Do NOT use Arrays,
 * do NOT use a linear search algorithm, and do NOT use the prompt functions!
 * Use if-else and confirm("some question") inside the while-loop.
 * The human is expected to click the cancel button to indicate No
 * (and thus the confirm function retuns false)
 * or the OK button to indicate Yes (confirm function returns true).
 * Do NOT change the line "guess = Math.round((min + max) / 2);"
 * because the computer is supposed to guess efficiently by
 * asking the human if their number is higher, lower, or equal to
 * the computer's current guess.
 * Do NOT use break or continue. You can use the "return;" statement inside
 * the while-loop to get the computer to leave the guesser function.
 * For info on how while loops work see:
 * https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/while
 * For info on how return works see:
 * https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/return
 */
const guesser = event => {
	let min = 0;
	let max = 100;
	let guess;
	// If this guesser function was called correctly both event.currentTarget
	// and this should be the window object. If event is undefined you probably
	// changed the code at the end of this file even though you are not allowed to.
	console.log("this:", this);
	if(event) console.log("event.currentTarget:", event.currentTarget);

	alert("Think of a number between " + min + " and " + max + ".");
	
	while (min <= max) {
		guess = Math.round((min + max) / 2);

		// Prompts user if the guess is correct, OK means true and therefore the number is guessed. Function returns.
		if(confirm("Is your number " + guess + "?\n" + "Press 'OK' if yes or 'Cancel' if no") === true) {
			
			
			alert("I guessed your number!");
			return;
		}
		

		// Here is the binary search algorithm. The guess becomes the new min or max. The number of answers always halves as you go through algorithm.

		if(confirm("Is your number higher or lower than " + guess + "?\nPress 'OK' if higher or 'Cancel' if lower") === true) {
			min = guess + 1; // added + 1 to min if lower so while loop can converge
		}
		else {
			max = guess - 1; // added - 1 to max if higher so while loop can converge
		}

	}

	// while loop finishes, which means a guess was not found
	alert("I could not guess your number. I think you are cheating!"); // TODO: Keep and use this line instead of calculating maxIteration
};

window.onload = guesser;
