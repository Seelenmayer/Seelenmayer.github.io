const projects = {
	"OpenGL Graphics": { title: "OpenGL Graphics", description: "This project explores advanced rendering techniques using OpenGL, including shaders, lighting models, and real-time rendering optimizations.", image: "Assets/project.jpg" },
	"ThreeJS Website": { title: "ThreeJS Website", description: "Hello World", image: "Assets/project.jpg" },
	"Bridge Project": { title: "Bridge Project", description: "Hello World", image: "Assets/project.jpg" },
	"Blender Modeling": { title: "Blender Modeling", description: "Hello World", image: "Assets/project.jpg" },
	"Virtualized Networks": { title: "Virtualized Networks", description: "Hello World", image: "Assets/project.jpg" },
	"Compilers and Process Scheduling": { title: "Compilers and Process Scheduling", description: "Hello World", image: "Assets/project.jpg" },
	"Render Textures": { title: "Render Textures", description: "Hello World", image: "Assets/project.jpg" },
	"Godot Project": { title: "Godot Project", description: "Hello World", image: "Assets/project.jpg" },
	"Magic Squares": { title: "Magic Squares", description: "Hello World", image: "Assets/project.jpg" },
	"Jamfest": { title: "Jamfest", description: "Hello World", image: "Assets/project.jpg" },
	"Cinematic Camera": { title: "Cinematic Camera", description: "Hello World", image: "Assets/project.jpg" },
	"Miscellaneous": { title: "Miscellaneous", description: "<TODO: produce, pints, vr, logger, gameboy, unity tree, honours>", image: "Assets/project.jpg" },
};

let currentPage = 0;
const projectsPerPage = 4;
const projectKeys = Object.keys(projects);

// Function to render the current page of projects
function renderProjects() {
	const nav = document.querySelector('nav ul');
	nav.innerHTML = ''; // Clear existing projects
	const startIndex = currentPage * projectsPerPage;
	const endIndex = Math.min(startIndex + projectsPerPage, projectKeys.length);

	for (let i = startIndex; i < endIndex; i++) {
		const projectKey = projectKeys[i];
		const project = projects[projectKey];
		nav.innerHTML += `
			<div class="navproject">
				<a href="#" onclick="showProjectDetails('${projectKey}'); return false;">
					<img src="${project.image}" alt="[Project Image]" class="projectimage">
					<span class="navprojectoverlay">${project.title}</span>
				</a>
			</div>
		`;
	}
}

// Function to handle page navigation
function changePage(direction) {
	if (direction === 'up' && currentPage > 0) {
		currentPage--;
	} else if (direction === 'down' && (currentPage + 1) * projectsPerPage < projectKeys.length) {
		currentPage++;
	}
	renderProjects();
	updatePageIndicator();
}

// Function to update the page number indicator to show "Page X out of Y"
function updatePageIndicator() {
	const totalPages = Math.ceil(projectKeys.length / projectsPerPage); // Calculate total pages
	const pageIndicator = document.querySelector('.page-indicator');
	pageIndicator.textContent = `Page ${currentPage + 1} out of ${totalPages}`;
}

// Initialize the first page of projects and the page indicator on load
window.onload = () => {
	renderProjects();
	updatePageIndicator();
};

// Function to update the main content based on selected project
function showProjectDetails(projectName) {
	const project = projects[projectName];
	const mainContent = document.querySelector('main');
	mainContent.innerHTML = `
		<div>
			<h1>${project.title}</h1>
			<img src="${project.image}" alt="${project.title}" style="max-width: 100%; height: auto;">
			<p>${project.description}</p>
		</div>
	`;
}
