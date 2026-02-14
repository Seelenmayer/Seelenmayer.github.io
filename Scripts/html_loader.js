function loadHTML(id, file) {
	return fetch(file)
		.then(r => r.text())
		.then(html => {
			document.getElementById(id).innerHTML = html;
		});
}

document.addEventListener("DOMContentLoaded", () => {
	loadHTML("navigation-block", "./navigation.html");
});
