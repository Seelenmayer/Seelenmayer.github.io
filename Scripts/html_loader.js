function loadHTML(id, file) {
	return fetch(file)
		.then(r => r.text())
		.then(html => {
			document.getElementById(id).innerHTML = html;
		});
}

document.addEventListener("DOMContentLoaded", () => {
	loadHTML("tabs", "tabs.html");
});

document.addEventListener("DOMContentLoaded", () => {
	loadHTML("socials-block", "socials.html");
});