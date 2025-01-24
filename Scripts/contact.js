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
			// Create a mailto link and display it
			const email = emailParts[0] + '@' + emailParts[1] + '.' + emailParts[2];
			document.getElementById(id).innerHTML = `<a href="mailto:${email}">${email}</a>`;
		}
	}, 1000);
}
// Start timer
window.onload = function() {
	const emails = [
		['Seelenmayer', 'live', 'com'],
	];
	revealEmail('email1', emails[0]);
};