const projects = {
	"Virtual Reality": {
		title: "Virtual Reality",
		image: "Content/Portfolio/Virtual_Reality/tinybanner.jpg",
		page: 0
	},
	"OpenGL Graphics": {
		title: "OpenGL Graphics",
		image: "Content/Portfolio/OpenGL_Graphics/tinybanner.jpg",
		page: 0
	},
	"Cinematic Camera": {
		title: "Cinematic Camera",
		image: "Content/Portfolio/Cinematic_Camera/tinybanner.jpg",
		page: 0
	},
	"Game Jams": {
		title: "Game Jams",
		image: "Content/Portfolio/Game_Jams/tinybanner.jpg",
		page: 0
	},
	"Assembly and Hardware": {
		title: "Assembly and Hardware",
		image: "Content/Portfolio/Assembly_and_Hardware/tinybanner.jpg",
		page: 1
	},
	"Virtual Machines and Networks": {
		title: "Virtual Machines and Networks",
		image: "Content/Portfolio/Virtual_Machines_and_Networks/tinybanner.jpg",
		page: 1
	},
	"Compilers and Processes": {
		title: "Compilers and Processes",
		image: "Content/Portfolio/Compilers_and_Processes/tinybanner.jpg",
		page: 1
	},
	"Datastructures and Algorithms": {
		title: "Datastructures and Algorithms",
		image: "Content/Portfolio/Datastructures_and_Algorithms/tinybanner.jpg",
		page: 1
	},
	"Blender Modeling": {
		title: "Blender Modeling",
		image: "Content/Portfolio/Blender_Modeling/tinybanner.jpg",
		page: 2
	},
	"Web Development": {
		title: "Web Development",
		image: "Content/Portfolio/Web_Development/tinybanner.jpg",
		page: 2
	},
	"Mathematics": {
		title: "Mathematics",
		image: "Content/Portfolio/Mathematics/tinybanner.jpg",
		page: 3
	}
	"Bridge Project": {
		title: "Bridge Project",
		image: "Content/Portfolio/Bridge_Project/tinybanner.jpg",
		page: 2
	},
,	"Miscellaneous": {
		title: "Miscellaneous",
		image: "Content/Portfolio/Miscellaneous/tinybanner.jpg",
		page: 2
	},
	"Japanese": {
		title: "Japanese",
		image: "Content/Portfolio/Japanese/tinybanner.jpg",
		page: 3
	},
	"Maxs Mushrooms": {
		title: "Maxs Mushrooms",
		image: "Content/Portfolio/Maxs_Mushrooms/tinybanner.jpg",
		page: 3
	},
	"Music": {
		title: "Music",
		image: "Content/Portfolio/Music/tinybanner.jpg",
		page: 3
	},
};

const projectsPerPage = 4;	// Hardcoded solution - requires changing the projects const page field.
const projectKeys = Object.keys(projects);
let currentPage = getLastViewedPage();

// Render Project List
function renderProjects() {
	const nav = document.querySelector('nav ul');
	nav.innerHTML = '';
	const startIndex = currentPage * projectsPerPage;
	const endIndex = Math.min(startIndex + projectsPerPage, projectKeys.length);

	for (let i = startIndex; i < endIndex; i++) {
		const projectKey = projectKeys[i];
		const project = projects[projectKey];
		const projectPage = `${projectKey.replace(/\s+/g, '-').toLowerCase()}.html`;

		nav.innerHTML += `
			<div class="navprojectcontainer">
				<div class="navproject">
					<a href="${projectPage}" onclick="setLastViewedPage(${project.page});">
						<img src="${project.image}" alt="${project.title} project banner" class="projectimage">
						<span class="navprojectoverlay">${project.title}</span>
					</a>
				</div>
			</div>
		`;
	}
}

// Set Last Page
function setLastViewedPage(pageNumber) {
	sessionStorage.setItem('lastViewedPage', pageNumber);
}

// Get Last Page
function getLastViewedPage() {
	const savedPage = sessionStorage.getItem('lastViewedPage');
	return savedPage ? parseInt(savedPage, 10) : 0;
}

// Change Page
function changePage(direction) {
	if (direction === 'up' && currentPage > 0) {
		currentPage--;
	} else if (direction === 'down' && (currentPage + 1) * projectsPerPage < projectKeys.length) {
		currentPage++;
	}
	renderProjects();
	updatePageIndicator();
}

// Page Indicators
function updatePageIndicator() {
	const totalPages = Math.ceil(projectKeys.length / projectsPerPage);
	const pageIndicator = document.querySelector('.page-indicator');
	pageIndicator.textContent = `Page ${currentPage + 1} out of ${totalPages}`;
}

// Window Initialize
window.onload = () => {
	renderProjects();
	updatePageIndicator();
};
