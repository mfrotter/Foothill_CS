// The following comments are settings for various linters
// Not sure if a reported error matters? Look it up at http://linterrors.com/js
/*global console: false, window: false, document: false, Modernizr:false, DEBUG:true, $:false */

/*jslint jquery: true*/
/*jslint node: false*/
/*jslint browser: true*/
/*jslint devel: true*/
/*jslint plusplus: true */

/*jshint globalstrict: true*/
/*jshint jquery: true*/
/*jshint node: false*/
/*jshint browser: true*/
/*jshint devel: true*/
/*exported processFormData */
/*exported form */

/*eslint-env es5*/
/*eslint-env jquery: true*/
/*eslint-env browser*/
/*eslint no-console: 0*/

"use strict";
//This 'flag' variable controls if we output debugging info to the console or not
var DEBUG = true;

// Setup variables for using the intlTelInput plugin:
// Since version 14, intlTelInput removed the jQuery dependency, so select the
// HTML Element with the id of "phone" withOUT using jQuery
var telInput = document.querySelector("#phone");
// jQuery WILL be used to hide and show the error message and valid message HTML
// Elements, so select them both using jQuery
var errorMsg = $("#error-msg");
var validMsg = $("#valid-msg");
// The following errorMap array maps to the error code returned from
// getValidationError - see the intlTelInput plugin readme
var errorMap = [
	"Invalid number",
	"Invalid country code",
	"Too short",
	"Too long",
	"Invalid number"
];

// TODO: initialize intlTelInput plugin to use the utilsScript to load Google's
// libphonenumber utility
// (use the following path
// js/vendor/intl-tel-input-master/build/js/utils.js ).
// See in this project:
// js/vendor/intl-tel-input-master/examples/gen/is-valid-number.html
// Initialize intlTelInput
var iti = window.intlTelInput(telInput, {
  utilsScript: "../js/vendor/intl-tel-input-master/build/js/utils.js"
});


// TODO: In the functions below, use the following documentation page,
// BUT make sure you use jQuery's show & hide methods INSTEAD of removing and
// adding "error" and "hide" css-classes!
// See in this project:
// js/vendor/intl-tel-input-master/examples/gen/is-valid-number.html
var reset = function() { 
	errorMsg.hide();
	validMsg.hide();
};
// TODO: on blur: validate telInput
// if valid: show validMsg
// if there is an error: show errorMsg
telInput.addEventListener("blur", function() {
	reset();
	if (telInput.value.trim()) {
		if (iti.isValidNumber()) {
			validMsg.show();
		} else {
			var errorCode = iti.getValidationError();
			errorMsg.innerHTML = errorMap[errorCode];
			errorMsg.show();
		}
	}
}, false);

// TODO: use addEventListener to bind telInput's keyup & change events to call reset
telInput.addEventListener('change', reset);
telInput.addEventListener('keyup', reset);

// The purpose of processFormData is to do final validation checks,
// and to stop the form from submitting,
// but you can also use it to help with debugging
var processFormData = function(event) {
	// prevent the default behavior of the form submit event
	event.preventDefault();
	if (DEBUG) {
		console.log(event);
		console.log(this);
		var form = document.forms.post_plant;
		console.log(form);
	}

	var $form = $("#post_plant");
	/*jshint unused: vars */
	var submitOnlyIfValid = function(form) {
		var errmsg = "";
		// Check if the form is valid
		if ($form.valid()) {
			$("div.error").hide();
		} else {
			// not valid
			$("div.error").show("slow");
			errmsg = "form was considered NOT valid and form submission is cancelled";
			if (DEBUG) {
				console.log(errmsg);
			}
			alert(errmsg);
			return false;
		}
		// Also check with the non-jQuery intlTelInput validation
		if (telInput && iti) {
			// intlTelInput exists so see if it is valid
			if (telInput.value.trim()) {
				if (!iti.isValidNumber()) {
					// Don't submit the form since intlTelInput is
					// not valid
					$("div.error span").html("Phone number is not valid");
					$("div.error").show("slow");
					errmsg =
						"intlTelInput was considered NOT valid and form submission is cancelled";
					if (DEBUG) {
						console.log(errmsg);
					}
					alert(errmsg);
					return false;
				}
			}
		}
		if (DEBUG) {
			console.log(
				"Form was considered valid and normally would have been submitted"
			);
		}
		alert("Form was considered valid and normally would have been submitted.");
		return true;
	};

	// Validate the form
	$form.validate({
		rules: {
			// TODO: Make sure the planting date has been set by the
			// user and is in dateISO format.
			// Input will be in 24 hour format but the display in modern
			// browsers will be use AM/PM formatting.
			// See: http://jqueryvalidation.org/dateISO-method/
			/* TODO: Make sure you check in browser consoles that the result of
			$("#planting_date").val() is something like "2022-06-08"
			and NOT something like "06/08/2022" and NOT like "22-06-08"
			*/
			field: {
				required: true,
				dateISO: true
			}
		},
		invalidHandler: function(event, validator) {
			// Inside this function 'this' refers to the form
			var errors = validator.numberOfInvalids();
			if (errors) {
				var message =
					errors === 1
						? "You missed 1 field. It has been highlighted"
						: "You missed " + errors + " fields. They have been highlighted";
				$("div.error span").html(message);
				$("div.error").show("slow");
			} else {
				$("div.error").hide();
			}
		},
		submitHandler: submitOnlyIfValid
	});

	// If the form is valid hide div.error
	if ($form.valid()) {
		$("div.error").hide();
	}
	
	//console.log($("#planting_date").val());

	// returning false also stops the form from submitting
	return submitOnlyIfValid($form);
};

// If the browser supports the date input type, don't do anything
// This code is cribbed from
// http://code.tutsplus.com/tutorials/quick-tip-cross-browser-datepickers-within-minutes--net-20236
var initDatePicker = function() {
	// Modernizr (https://modernizr.com/) gives you the ability to detect
	// whether the browser supports native datepickers.
	if (DEBUG) {
		console.log("Modernizr.inputtypes.date:", Modernizr.inputtypes.date);
	}
	if (!Modernizr.inputtypes.date) {
		/* TODO: The browser doesn't support native datepickers,
		so use the jQuery UI Date Picker on the planting date input element.
		Initialize the datepicker with the dateFormat option set to 'yy-mm-dd'
		which will make the date have a 4 digit year
		(confusingly for jQuery UI y means a 2 digit year
		and yy means a 4 digit year), and have 2 digit months and days.
		See: https://api.jqueryui.com/datepicker/#option-dateFormat
		*/
		$("#planting_date").datepicker({
			dateFormat : "yy-mm-dd", stepMonths: 1, changeMonth: true, changeYear: true
}); 
	}
};
// Initialize the jQuery UI plugin's DatePicker plugin for the planting time
initDatePicker();

// TODO: Initialize the jquery-timepicker plugin for the planting time
// See in this project the Basic Example at: timepickerexample.html
$("#planting_time").timepicker();
