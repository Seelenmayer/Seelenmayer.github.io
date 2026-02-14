function loadHTML(id, file) {
	fetch(file)
		.then(r => r.text())
		.then(html => {
			document.getElementById(id).innerHTML = html;
		});
}
