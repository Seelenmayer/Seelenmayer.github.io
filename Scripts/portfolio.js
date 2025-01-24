const projects = {
	"Virtual Reality": {
		title: "Virtual Reality",
		image: "Content/Portfolio/Virtual Reality/banner.jpg",
		page: 0
	},
	"OpenGL Graphics": {
		title: "OpenGL Graphics",
		image: "Content/Portfolio/OpenGL Graphics/banner.jpg",
		page: 0
	},
	"Cinematic Camera": {
		title: "Cinematic Camera",
		image: "Content/Portfolio/Cinematic Camera/banner.jpg",
		page: 0
	},
	"Game Jams": {
		title: "Game Jams",
		image: "Content/Portfolio/Game Jams/banner.jpg",
		page: 0
	},
	"Assembly and Hardware": {
		title: "Assembly and Hardware",
		image: "Content/Portfolio/Assembly and Hardware/banner.jpg",
		page: 1
	},
	"Virtual Machines and Networks": {
		title: "Virtual Machines and Networks",
		image: "Content/Portfolio/Virtual Machines and Networks/banner.jpg",
		page: 1
	},
	"Compilers and Processes": {
		title: "Compilers and Processes",
		image: "Content/Portfolio/Compilers and Processes/banner.jpg",
		page: 1
	},
	"Datastructures and Algorithms": {
		title: "Datastructures and Algorithms",
		image: "Content/Portfolio/Datastructures and Algorithms/banner.jpg",
		page: 1
	},
	"Blender Modeling": {
		title: "Blender Modeling",
		image: "Content/Portfolio/Blender Modeling/banner.jpg",
		page: 2
	},
	"Miscellaneous": {
		title: "Miscellaneous",
		image: "Content/Portfolio/Miscellaneous/banner.jpg",
		page: 2
	},
	"Bridge Project": {
		title: "Bridge Project",
		image: "Content/Portfolio/Bridge Project/banner.jpg",
		page: 2
	},
	"Magic Squares": {
		title: "Magic Squares",
		image: "Content/Portfolio/Magic Squares/banner.jpg",
		page: 2
	},
	"Japanese": {
		title: "Japanese",
		image: "Content/Portfolio/Japanese/banner.jpg",
		page: 3
	},
	"Maxs Mushrooms": {
		title: "Maxs Mushrooms",
		image: "Content/Portfolio/Maxs Mushrooms/banner.jpg",
		page: 3
	},
	"Music": {
		title: "Music",
		image: "Content/Portfolio/Music/banner.jpg",
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
						<img src="${project.image}" alt="[Project Image]" class="projectimage">
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
