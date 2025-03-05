document.addEventListener('DOMContentLoaded', function () {
	document.getElementById('downloadLink').addEventListener('click', function(event) {
		event.preventDefault();
		var link = document.createElement('a');
		link.href = 'Clayton Seelenmayer Resume.pdf';
		link.download = 'Clayton Seelenmayer Resume.pdf';
		link.click();
	});

	// Function to reveal email after the timer
	function revealEmail(id, emailParts) {
		let seconds = 7;
		document.getElementById(id).textContent = `This email will display itself in ${seconds} seconds.`;
		// Countdown
		const countdown = setInterval(() => {
			document.getElementById(id).textContent = `This email will display itself in ${seconds} seconds.`;
			seconds--;
			if (seconds < 0) {
				clearInterval(countdown);
				// Display
				const email = emailParts[0] + '@' + emailParts[1] + '.' + emailParts[2];
				document.getElementById(id).innerHTML = `<a href="mailto:${email}">${email}</a>`;
			}
		}, 1000);
	}

	// Start timer
	const emails = [
		['example', 'gmail', 'com']
		['example', 'gmail', 'com'],
		['example', 'gmail', 'com'],
	];
	//revealEmail('email1', emails[0]);
	//revealEmail('email2', emails[1]);
	//revealEmail('email3', emails[2]);
});
