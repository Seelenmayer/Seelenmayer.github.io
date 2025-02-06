const projects = {
	"OpenGL Graphics": {
		title: "OpenGL Graphics",
		image: "Content/Portfolio/OpenGL Graphics/banner.jpg",
		customHTML: `
			<div>
				<h1>OpenGL Graphics</h1>
				<p>This project contains samples of my OpenGL work during my computer graphics class apprenticeship with former Nintendo developer Mike K.</p>
				<p>It showcases my procedurally generated tree, a particle system along a smooth curve, a ray-tracer demo, and a simple fun video for last.</p>
				<div class="separator"></div>
				<p>I loved this L-systems tree with all my heart. This program reads in an input string from a file to describe draw instructions for a tree. It uses a context-free-grammar data-structure to procedurally generate a fractal like tree to simulate natural growth. A simple change to the input can altar the tree that's generated and allow for a great range of variety. I then take the lines drawn and instead render them as cylinders whose girth interpolates from the base of the tree to a point source and whose end-faces are XZ-planar.</p>
				<p>This demo also reveals capturing the user's pointer's screen space coordinates and utilizing the rotation-about-an-arbitrary-axis matrix to rotate the scene view. An arena is loaded with a texture applied, as well as various lighting created around the scene.</p>
				<p>The following is a video demonstration that shows the tree with each iteration of the algorithm, as well as its environment.
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/OpenGL Graphics/tree.mp4" target="_blank">
						<video class="displaymedia" poster="Content/Portfolio/OpenGL Graphics/tree_poster.jpg" preload="metadata" loading="lazy" controls muted loop>
							<source src="Content/Portfolio/OpenGL Graphics/tree.mp4" type="video/mp4">
							Your browser does not support the video tag.
						</video>
					</a>
					<div class="displaymediadescription">tree.mp4</div>
				</div>
				<p>The following 4 images show the first 4 iterations of this algorithm, followed by a polished wallpaper.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/OpenGL Graphics/tree1.jpg" target="_blank">
							<img src="Content/Portfolio/OpenGL Graphics/tree1.jpg" alt="[OpenGL Tree]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">tree1.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/OpenGL Graphics/tree2.jpg" target="_blank">
							<img src="Content/Portfolio/OpenGL Graphics/tree2.jpg" alt="[OpenGL Tree]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">tree2.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/OpenGL Graphics/tree3.jpg" target="_blank">
							<img src="Content/Portfolio/OpenGL Graphics/tree3.jpg" alt="[OpenGL Tree]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">tree3.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/OpenGL Graphics/tree4.jpg" target="_blank">
							<img src="Content/Portfolio/OpenGL Graphics/tree4.jpg" alt="[OpenGL Tree]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">tree4.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/OpenGL Graphics/tree.jpg" target="_blank">
							<img src="Content/Portfolio/OpenGL Graphics/tree.jpg" alt="[OpenGL Tree]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">tree.jpg</div>
				</div>
				<p>Here you can view the project source code.</p>
				<div class="scriptcontainer">
					<a href="https://github.com/Seelenmayer/Seelenmayer.github.io/tree/main/Content/Portfolio/OpenGL%20Graphics/Context%20Free%20Grammar%20Tree" id="downloadLink" target="_blank">
						<img src="Assets/script.png" alt="[Script Directory]">
					</a>
					<p>Context Free Grammar Tree</p>
				</div>
				<div class="separator"></div>
				<p>This project uses a circular array of 8 control points to create 8 quadratic bezier curves where the particle emitter will linearly-interpolate along. The particles themselves linearly-interpolate outward at regular intervals while linearly interpolating the colour along a texture map.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/OpenGL Graphics/particle.jpg" target="_blank">
							<img src="Content/Portfolio/OpenGL Graphics/particle.jpg" alt="[OpenGL Particles]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">particle.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/OpenGL Graphics/particle.mp4" target="_blank">
						<video class="displaymedia" poster="Content/Portfolio/OpenGL Graphics/particle_poster.jpg" preload="metadata" loading="lazy" controls muted loop>
							<source src="Content/Portfolio/OpenGL Graphics/particle.mp4" type="video/mp4">
							Your browser does not support the video tag.
						</video>
					</a>
					<div class="displaymediadescription">particle.mp4</div>
				</div>
				<p>Here you can view the project source code.</p>
				<div class="scriptcontainer">
					<a href="https://github.com/Seelenmayer/Seelenmayer.github.io/tree/main/Content/Portfolio/OpenGL%20Graphics/Context%20Free%20Grammar%20Tree" id="downloadLink" target="_blank">
						<img src="Assets/script.png" alt="[Script Directory]">
					</a>
					<p>Particle Emitter & Bezier Curves</p>
				</div>
				<div class="separator"></div>
				<p>This short demo briefly demonstrates a ray-tracer that utilizes the phong-reflection model. It describes how a pixel should be coloured by casting a ray into the scene and back-tracing a sample colour from each surface reflected. The reflection is a relationship between the specular lighting in the scene, diffuse lighting off of the object, and ambient lighting from the environment. You can see the two scene lights in the reflections of the faces of these spheres.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/OpenGL Graphics/raytrace.jpg" target="_blank">
							<img src="Content/Portfolio/OpenGL Graphics/raytrace.jpg" alt="[OpenGL Raytracer]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">raytrace.jpg</div>
				</div>
				<div class="separator"></div>
				<p>This short demo just reveals an icosohedron rotating along 2 axis based on cosine waves before a colour changing light.</p>
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/OpenGL Graphics/icosahedron.mp4" target="_blank">
						<video class="displaymedia" poster="Content/Portfolio/OpenGL Graphics/icosahedron_poster.jpg" preload="metadata" loading="lazy" controls muted loop>
							<source src="Content/Portfolio/OpenGL Graphics/icosahedron.mp4" type="video/mp4">
							Your browser does not support the video tag.
						</video>
					</a>
					<div class="displaymediadescription">icosahedron.mp4</div>
				</div>
			</div>
		`
	},
	"Cinematic Camera": {
		title: "Cinematic Camera",
		image: "Content/Portfolio/Cinematic Camera/banner.jpg",
		customHTML: `
			<div>
				<h1>Cinematic Camera</h1>
				<p>This project showcases my camera controller milestone for a Unity game that I was working on. A user can intuitively and smoothly drag the camera with them, visually burning any obstructions that get in the way! This controller was inspired by platformer genres with Klonoa as reference.</p>
				<p>The developer defines three splines: the player spline, the camera spline, and the camera look-at target spline. As the player moves along their spline, reaching an interval’s end pushes the upper bound forward, while the lower bound follows at a fixed distance. The camera remains idle within this interval until pushed forward by the lower bound, interpolating along its spline while its look-at target progresses along its own. This updates the camera’s rotation matrix each frame.</p>
				<p>If a marked object gets too close to the camera, a shader gradually burns it away to prevent obstruction. When in range, a noise texture map generated in GIMP is randomly assigned to guide the burn effect’s interpolation. Once the camera moves far enough away, the object regenerates, reversing the burn effect.</p>
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/Cinematic Camera/camera.mp4" target="_blank">
						<video class="displaymedia" poster="Content/Portfolio/Cinematic Camera/camera_poster.jpg" preload="metadata" loading="lazy" controls muted loop>
							<source src="Content/Portfolio/Cinematic Camera/camera.mp4" type="video/mp4">
							Your browser does not support the video tag.
						</video>
					</a>
					<div class="displaymediadescription">camera.mp4</div>
				</div>
				<p>The first part of writing this GLSL shader was to capture the user's screen space coordinates by navigating the existing libraries. I coloured the X-axis red, and Y-axis green. You can see that the top-left pixel available to be drawn is green, and the bottom-right is red. Since these pixels aren't at the literal edge of the viewport, they aren't full saturated as seen on the bottom-left which would appear as solid black (as opposed to grey), or top-right which would appear as yellow (as opposed to orange).</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Cinematic Camera/shader1.png" target="_blank">
							<img src="Content/Portfolio/Cinematic Camera/shader1.png" alt="[Shader Demo 1]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">shader1.png</div>
				</div>
				<p>Now that I had control of the screen coordinates, I was able to overlay the randomly assigned noise texture map from Gimp as depicted in blue.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Cinematic Camera/shader2.png" target="_blank">
							<img src="Content/Portfolio/Cinematic Camera/shader2.png" alt="[Shader Demo 2]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">shader2.png</div>
				</div>
				<p>I wanted to include the following image as it demonstrated a slight visual iregularily where the burn appears to be hard-edged. This was an example of when not to confuse multiplied-alpha with premultiplied-alpha, which can result from incorrectly associating multiplication. Premultiplied alpha refers to the practice of storing the color values already multiplied by the alpha transparency value. The advantage of this is that rendering is faster since the math for compositing is simplified.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Cinematic Camera/shader3.png" target="_blank">
							<img src="Content/Portfolio/Cinematic Camera/shader3.png" alt="[Shader Demo 3]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">shader3.png</div>
				</div>
				<p>Here’s the final result! However, one major oversight emerged during this project where objects with this shader weren’t casting shadows. Fixing this became complex, requiring me to integrate my code into Unity’s existing HDRP "Lit" shader to inherit its natural lighting properties. This meant combing through Unity’s shader scripts to resolve namespace issues with screen space coordinates and determining the correct render pass for the glow effect. I chose to render it in the forward pass while deliberately avoiding deferred rendering. Forward rendering, a simpler technique, processes lighting per object in a single pass, whereas deferred rendering separates geometry and lighting calculations but struggles with transparency without significant design overhauls.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Cinematic Camera/shader4.png" target="_blank">
							<img src="Content/Portfolio/Cinematic Camera/shader4.png" alt="[Shader Demo 4]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">shader4.png</div>
				</div>
			</div>
		`
	},
	"Game Jams": {
		title: "Game Jams",
		image: "Content/Portfolio/Game Jams/banner.jpg",
		customHTML: `
			<div>
				<h1>Game Jams</h1>
				<p>This section showcases all of my game jam projects and community involvements with Global Game Jam, Pirate Software, and the VIGD Discord server.<p>
				<div class="separator"></div>
				<p>I entered Pirate Software's Game Jam (January 2025) and was able to form a team of 4 others! In just a few hours, I was able to prototype the team's ideas.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Game Jams/piratedemo.png" target="_blank">
							<img src="Content/Portfolio/Game Jams/piratedemo.png" alt="[Pirate Demo]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">piratedemo.png</div>
				</div>
				<p>By the end of the week, we were able to build a functioning online multiplayer chess and card game! A client can join a host via. a generated code. This project also allowed me to utilize Unity's built in version control.</p>
				<p>
					<a href="https://batmenzdw.itch.io/sorcererschess" target="_blank" rel="noopener noreferrer">
						Click here to see the game submission.
					</a>
				</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Game Jams/pirate16a.bmp" target="_blank">
							<img src="Content/Portfolio/Game Jams/pirate16a.bmp" alt="[Pirate Demo]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">pirate16a.bmp</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Game Jams/pirate16b.bmp" target="_blank">
							<img src="Content/Portfolio/Game Jams/pirate16b.bmp" alt="[Pirate Demo]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">pirate16b.bmp</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Game Jams/pirate16c.bmp" target="_blank">
							<img src="Content/Portfolio/Game Jams/pirate16c.bmp" alt="[Pirate Demo]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">pirate16c.bmp</div>
				</div>
				<div class="separator"></div>
				<p>Global Game Jam 2025 was so much fun! I was able to achieve my goal of integrating Llama into Unity and making a pet daycare simulator. I decided to not officially publish this game as I was also competing in Pirate Software's game jam. I was also having too much fun assisting the other developers on their projects!</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Game Jams/ggj2025.png" target="_blank">
							<img src="Content/Portfolio/Game Jams/ggj2025.png" alt="[Game Jam]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">ggj2025.png</div>
				</div>
				<div class="separator"></div>
				<p>Back in the summer of 2024, Sheldon, Dan, and I participated in the Global Game Jam 2024 event. Sheldon was in charge of music, Dan setup the Github version control systems and playtested, and I developed the game Jamfest in Unity. Within 48 hours, I was able to design and create this split-screen racing game where players summon terrain to block eachother from the finish line.</p>
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/Global Game Jam 2024/Jamfest.mp4" target="_blank">
						<video class="displaymedia" poster="Content/Portfolio/Game Jams/Jamfest_poster.jpg" preload="metadata" loading="lazy" controls muted loop>
							<source src="Content/Portfolio/Game Jams/Jamfest.mp4" type="video/mp4">
							Your browser does not support the video tag.
						</video>
					</a>
					<div class="displaymediadescription">Jamfest.mp4</div>
				</div>
				<p>I put a lot of thought into the design of this game, and I'd like to explain how it came together. Initially, I planned a multiplayer game, but due to time constraints, I opted for a split-screen, linear racing format. After creating a simple floor, I decided to use a basic tree model from the Unity TreeGen package, which I ended up reworking into rocks to avoid geometry collision. These rocks would spawn in a controlled, linear fashion.</p>
				<p>For the gameplay, I wanted to avoid players getting stuck, so I added a 2-second digging mechanic to clear obstacles. To prevent spamming commands, I implemented a universal cooldown system, with a particle effect for visual polish. I also balanced speed, gravity, terrain, and placement. A catch-up mechanic was added, giving players in last place a hidden speed boost, but only enough to catch up without overtaking.</p>
				<p>I also made adjustments to prevent players from falling off the map and fine-tuned slopes to avoid unrealistic movement. To optimize performance, I deleted terrain behind the camera, and created clever environmental design by reusing objects like trees and bushes. After testing, I made players transparent for better visibility.</p>
				<p>During a demonstration, the second player, initially behind, managed to catch up and leap over the terrain blocking the finish line, leading to an incredible reaction from the audience. The mechanics had worked perfectly, allowing players to redeem themselves in a surprising and satisfying way.</p>
				<p>
					<a href="https://globalgamejam.org/games/2024/jamfest-1" target="_blank" rel="noopener noreferrer">
						Click here to see the Global Game Jam website.
					</a>
				</p>
				<p>
					<a href="https://seelenmayer.itch.io/jamfest" target="_blank" rel="noopener noreferrer">
						Click here to see the itch.io upload and play for yourself!
					</a>
				</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Game Jams/jamfest1.jpg" target="_blank">
							<img src="Content/Portfolio/Game Jams/jamfest1.jpg" alt="[Jamfest Menu]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">jamfest1.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Game Jams/jamfest2.jpg" target="_blank">
							<img src="Content/Portfolio/Game Jams/jamfest2.jpg" alt="[Jamfest Gameplay]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">jamfest2.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Game Jams/jamfest3.jpg" target="_blank">
							<img src="Content/Portfolio/Game Jams/jamfest3.jpg" alt="[Jamfest Credits]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">jamfest3.jpg</div>
				</div>
				<div class="separator"></div>
				<p>I wanted to give a special thanks to the VIGD group for hosting all of our wonderful gatherings.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Game Jams/ggj2025.jpg" target="_blank">
							<img src="Content/Portfolio/Game Jams/ggj2025.jpg" alt="[GGJ]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">ggj2025.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Game Jams/ggj2025_2.jpg" target="_blank">
							<img src="Content/Portfolio/Game Jams/ggj2025_2.jpg" alt="[GGJ]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">ggj2025_2.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Game Jams/vigd.jpg" target="_blank">
							<img src="Content/Portfolio/Game Jams/vigd.jpg" alt="[VIGD]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">vigd.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Game Jams/vigd2.jpg" target="_blank">
							<img src="Content/Portfolio/Game Jams/vigd2.jpg" alt="[VIGD]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">vigd2.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Game Jams/vigd3.jpg" target="_blank">
							<img src="Content/Portfolio/Game Jams/vigd3.jpg" alt="[VIGD]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">vigd3.jpg</div>
				</div>
			</div>
		`
	},
	"Blender Modeling": {
		title: "Blender Modeling",
		image: "Content/Portfolio/Blender Modeling/banner.jpg",
		customHTML: `
			<div>
				<h1>Blender Modeling</h1>
				<p>Here is a brief summary of my Blender projects. I followed Blender Guru's guide in constructing, molding, and generating my first donut. I then modeled my own character where I then experimented with the Sapling Tree Gen package and made a scene of my own.</p>
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/Blender Modeling/donut.png" target="_blank">
						<div class="displaymediawrapper">
							<img src="Content/Portfolio/Blender Modeling/donut.png" alt="[Donut]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</div>
					</a>
					<div class="displaymediadescription">donut.png</div>
				</div>
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/Blender Modeling/character.jpg" target="_blank">
						<div class="displaymediawrapper">
							<img src="Content/Portfolio/Blender Modeling/character.jpg" alt="[Character]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</div>
					</a>
					<div class="displaymediadescription">character.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/Blender Modeling/tree.jpg" target="_blank">
						<div class="displaymediawrapper">
							<img src="Content/Portfolio/Blender Modeling/tree.jpg" alt="[Tree]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</div>
					</a>
					<div class="displaymediadescription">tree.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/Blender Modeling/scene.jpg" target="_blank">
						<div class="displaymediawrapper">
							<img src="Content/Portfolio/Blender Modeling/scene.jpg" alt="[Scene]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</div>
					</a>
					<div class="displaymediadescription">scene.jpg</div>
				</div>
			</div>
		`
	},
	"Assembly and Hardware": {
		title: "Assembly and Hardware",
		image: "Content/Portfolio/Assembly and Hardware/banner.jpg",
		customHTML: `
			<div>
				<h1>Assembly and Hardware</h1>
				<p>This project demonstrates my experiements with the M86HC11E architecture, SSBC architecture, and verilog hardware simulations of state machines, and latches. I've also included samples of hardware maintenance.</p>
				<div class="separator"></div>
				<div>
					<p>The file "Wave.s" is a program designed to be ran on the M86HC11E architecture to demonstrate the use of working on the physical board CME11-E9-EVBU (with the PW link HACK) with the intention of producing a 30% high square wave form and display its output on an oscilloscope. It demonstrates the use of physical assembly architecture and with an interupt service routine.</p>
					<div class="scriptcontainer">
						<a href="Content/Portfolio/Assembly and Hardware/HC11/Wave.s" id="downloadLink" target="_blank">
							<img src="Assets/script.png" alt="[Script]">
						</a>
						<p>Wave.s</p>
					</div>
					<p>
						<a href="https://www.nxp.com/docs/en/reference-manual/M68HC11ERG.pdf" target="_blank" rel="noopener noreferrer">
							Click here to see the M86HC11E manual.
						</a>
					</p>
					<div class="displaymediacontainer">
						<div class="displaymediawrapper">
							<a href="Content/Portfolio/Assembly and Hardware/HC11/M86HC11E.jpg" target="_blank">
								<img src="Content/Portfolio/Assembly and Hardware/HC11/M86HC11E.jpg" alt="[HC11 Diagram]" class="displaymedia">
								<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
							</a>
						</div>
						<div class="displaymediadescription">M86EHC11.jpg</div>
					</div>
				</div>
				<div class="separator"></div>
				<div>
					<p>The file "Doubling.ssbc" is a program designed to test the programmable SSBC assembly language machine created by Peter W. It demonstrates the usage of direct memory mapping and setting up recursive subroutine calls by reading in an input "n" from one port and assigning "f(n)" to another.</p>
					<p>Furthermore, "Doubling.cpp" is a c++ program with equivalent behaviour to help better understand the behaviour of the SSBC machine.</p>
					<div class="scriptcontainer">
						<a href="Content/Portfolio/Assembly and Hardware/SSBC/Doubling.ssbc" id="downloadLink" target="_blank">
							<img src="Assets/script.png" alt="[Script]">
						</a>
						<p>Doubling.ssbc</p>
					</div>
					<div class="scriptcontainer">
						<a href="Content/Portfolio/Assembly and Hardware/SSBC/Doubling.cpp" id="downloadLink" target="_blank">
							<img src="Assets/script.png" alt="[Script]">
						</a>
						<p>Doubling.cpp</p>
					</div>
					<p>
						<a href="https://github.com/Babakanoosh/Visual-SSBC" target="_blank" rel="noopener noreferrer">
							Click here to see the SSBC source repository and web interpreter.
						</a>
					</p>
					<div class="displaymediacontainer">
						<div class="displaymediawrapper">
							<a href="Content/Portfolio/Assembly and Hardware/SSBC/SSBCvisualized.jpg" target="_blank">
								<img src="Content/Portfolio/Assembly and Hardware/SSBC/SSBCvisualized.jpg" alt="[SSBC Visualized]" class="displaymedia">
								<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
							</a>
						</div>
						<div class="displaymediadescription">SSBCvisualized.jpg</div>
					</div>
				</div>
				<div class="separator"></div>
				<div>
					<p>This experiment demonstrates the usage of different finite state machines written in verilog. Mealy designs output based on their transition, while Moore types output based on their state.</p>
					<p>The file FSM.v contains the implementations for creating the specific finite state machines.</p>
					<div class="scriptcontainer">
						<a href="Content/Portfolio/Assembly and Hardware/Verilog/Finite State Machines/FSM.v" id="downloadLink" target="_blank">
							<img src="Assets/script.png" alt="[Script]">
						</a>
						<p>FSM.v</p>
					</div>
					<p>The file FSM_tb.v communicates test data information to GTKWave to demonstrate the usage of these finite state machines by displaying meaningful waveform information.</p>
					<div class="scriptcontainer">
						<a href="Content/Portfolio/Assembly and Hardware/Verilog/Finite State Machines/FSM_tb.v" id="downloadLink" target="_blank">
							<img src="Assets/script.png" alt="[Script]">
						</a>
						<p>FSM_tb.v</p>
					</div>
					<div class="displaymediacontainer">
						<div class="displaymediawrapper">
							<a href="Content/Portfolio/Assembly and Hardware/Verilog/Finite State Machines/FSM Descriptions/MealyType.jpg" target="_blank">
								<img src="Content/Portfolio/Assembly and Hardware/Verilog/Finite State Machines/FSM Descriptions/MealyType.jpg" alt="[Mealy Diagram]" class="displaymedia">
								<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
							</a>
						</div>
						<div class="displaymediadescription">MealyType.jpg</div>
					</div>
					<div class="displaymediacontainer">
						<div class="displaymediawrapper">
							<a href="Content/Portfolio/Assembly and Hardware/Verilog/Finite State Machines/Wave Outputs/MealyTypeWave.jpg" target="_blank">
								<img src="Content/Portfolio/Assembly and Hardware/Verilog/Finite State Machines/Wave Outputs/MealyTypeWave.jpg" alt="[Mealy Wave Diagram]" class="displaymedia">
								<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
							</a>
						</div>
						<div class="displaymediadescription">MealyTypeWave.jpg</div>
					</div>
						<div class="displaymediacontainer">
						<div class="displaymediawrapper">
							<a href="Content/Portfolio/Assembly and Hardware/Verilog/Finite State Machines/FSM Descriptions/MooreType.jpg" target="_blank">
								<img src="Content/Portfolio/Assembly and Hardware/Verilog/Finite State Machines/FSM Descriptions/MooreType.jpg" alt="[Moore Diagram]" class="displaymedia">
								<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
							</a>
						</div>
						<div class="displaymediadescription">MooreType.jpg</div>
					</div>
					<div class="displaymediacontainer">
						<div class="displaymediawrapper">
							<a href="Content/Portfolio/Assembly and Hardware/Verilog/Finite State Machines/Wave Outputs/MooreTypeWave.jpg" target="_blank">
								<img src="Content/Portfolio/Assembly and Hardware/Verilog/Finite State Machines/Wave Outputs/MooreTypeWave.jpg" alt="[Moore Wave Diagram]" class="displaymedia">
								<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
							</a>
						</div>
						<div class="displaymediadescription">MooreTypeWave.jpg</div>
					</div>
				</div>
				<div class="separator"></div>
				<div>
					<p>This experiment demonstrates the usage of different data latches written in verilog, namely D-flip-flop with reset, and Johnson counter. This experiment also serves as a demonstration into using multiple instantiations of data latches in creating larger, more sophisticated data storage methods.</p>
					<p>The file Latches.v contains the implementations for creating the data-latch structure.</p>
					<div class="scriptcontainer">
						<a href="Content/Portfolio/Assembly and Hardware/Verilog/Latches/Latches.v" id="downloadLink" target="_blank">
							<img src="Assets/script.png" alt="[Script]">
						</a>
						<p>Latches.v</p>
					</div>
					<p>The file Latches_tb.v communicates test data information to GTKWave to demonstrate the usage of these data latches by displaying meaningful waveform information.</p>
					<div class="scriptcontainer">
						<a href="Content/Portfolio/Assembly and Hardware/Verilog/Latches/Latches_tb.v" id="downloadLink" target="_blank">
							<img src="Assets/script.png" alt="[Script]">
						</a>
						<p>Latches_tb.v</p>
					</div>
					<div class="displaymediacontainer">
						<div class="displaymediawrapper">
							<a href="Content/Portfolio/Assembly and Hardware/Verilog/Latches/Wave Outputs/D_Flip_Flop.jpg" target="_blank">
								<img src="Content/Portfolio/Assembly and Hardware/Verilog/Latches/Wave Outputs/D_Flip_Flop.jpg" alt="[D Flip Flop Wave]" class="displaymedia">
								<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
							</a>
						</div>
						<div class="displaymediadescription">D_Flip_Flop.jpg</div>
					</div>
					<div class="displaymediacontainer">
						<div class="displaymediawrapper">
							<a href="Content/Portfolio/Assembly and Hardware/Verilog/Latches/Wave Outputs/Johnson_Counter.jpg" target="_blank">
								<img src="Content/Portfolio/Assembly and Hardware/Verilog/Latches/Wave Outputs/Johnson_Counter.jpg" alt="[Johnson Counter Wave]" class="displaymedia">
								<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
							</a>
						</div>
						<div class="displaymediadescription">Johnson_Counter.jpg</div>
					</div>
				</div>
				<div class="separator"></div>
				<div>
					<p>This experiment demonstrates computer maintenance by cleaning and restoring the thermal paste on an NVidia ASUS ROG STRIX GTX 1080 GPU graphics card and Intel CPU (LGA 1151 socket).</p>
					<p>Here I disassemble the backplate of my GPU, reapply thermal, and reassemble.</p>
					<div class="displaymediacontainer">
						<div class="displaymediawrapper">
							<a href="Content/Portfolio/Assembly and Hardware/Maintenance/GPUPasting.jpg" target="_blank">
								<img src="Content/Portfolio/Assembly and Hardware/Maintenance/GPUPasting.jpg" alt="[GPU repasting]" class="displaymedia">
								<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
							</a>
						</div>
					</div>
					<div class="displaymediadescription">GPUPasting.jpg</div>
					<div class="displaymediacontainer">
						<div class="displaymediawrapper">
							<a href="Content/Portfolio/Assembly and Hardware/Maintenance/GPUBuilt.jpg" target="_blank">
								<img src="Content/Portfolio/Assembly and Hardware/Maintenance/GPUBuilt.jpg" alt="[GPU repasting]" class="displaymedia">
								<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
							</a>
						</div>
					</div>
					<div class="displaymediadescription">GPUBuilt.jpg</div>
					<p>Here I unmount the water cooling system on my Intel LGA 1151 socket so that I can reapply thermal paste to my CPU.</p>
					<div class="displaymediacontainer">
						<div class="displaymediawrapper">
							<a href="Content/Portfolio/Assembly and Hardware/Maintenance/CPUPasting.jpg" target="_blank">
								<img src="Content/Portfolio/Assembly and Hardware/Maintenance/CPUPasting.jpg" alt="[GPU repasting]" class="displaymedia">
								<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
							</a>
						</div>
					</div>
					<div class="displaymediadescription">CPUPasting.jpg</div>
					<div class="displaymediacontainer">
						<div class="displaymediawrapper">
							<a href="Content/Portfolio/Assembly and Hardware/Maintenance/CPUBuilt.jpg" target="_blank">
								<img src="Content/Portfolio/Assembly and Hardware/Maintenance/CPUBuilt.jpg" alt="[GPU repasting]" class="displaymedia">
								<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
							</a>
						</div>
					</div>
					<div class="displaymediadescription">CPUBuilt.jpg</div>
				</div>
			</div>
		`
	},
	"Virtual Machines and Networks": {
		title: "Virtual Machines and Networks",
		image: "Content/Portfolio/Virtual Machines and Networks/banner.jpg",
		customHTML: `
			<div>
				<h1>Virtual Machines and Networks</h1>
				<p>These projects showcases some of my basic IT work, operating system installation, and networking setup. In these images you'll find that I was able to create virtual machines that run both Arch Linux, and TinyCore Linux operating systems. I also developed a file transfer application for both client and server to allow for image downloading.</p>
				<div class="separator"></div>
				<p>This project demonstrates how a web client communicates with a web server by requesting an HTTP webpage. The process begins when the client sends a DHCP request to obtain an IP address and network configuration from a DHCP server. The server responds with an offer that includes the client IP and the DNS server address. The client confirms the offer, and the DHCP server finalizes the lease. Once the client has the necessary network settings, it uses the provided DNS server to resolve domain names. When the client enters a URL in the browser, it sends a DNS query to the server to find the corresponding IP address. The DNS server either returns the cached IP or performs a lookup to resolve the domain.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Virtual Machines and Networks/arch.jpg" target="_blank">
							<img src="Content/Portfolio/Virtual Machines and Networks/arch.jpg" alt="[Arch Linux]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">arch.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Virtual Machines and Networks/tiny.png" target="_blank">
							<img src="Content/Portfolio/Virtual Machines and Networks/tiny.png" alt="[Tiny Core]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">tiny.png</div>
				</div>
				<div class="separator"></div>
				<p>Leveraging Berkeley sockets and RFC 5905, I developed a system for reliable file download communication between the client and server. This implementation demonstrates proficiency in network programming and low-level socket management.</p>
				<a href="https://beej.us/guide/bgnet/" target="_blank">
					<p>If you wish to find out more about Berkley sockets, please check out Beej's guide here.</p>
				</a>
				<a href="https://www.rfc-editor.org/rfc/rfc5905" target="_blank">
					<p>This program complies with the specifications outlined in RFC 5905 as seen here.</p>
				</a>
				<p>I'd like to go over just one of the many processes involved in the making of these applications, namely the server side function enteringIntoPassive. This should give an example of the type of work involved in the making of this project.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Virtual Machines and Networks/ftp.jpg" target="_blank">
							<img src="Content/Portfolio/Virtual Machines and Networks/ftp.jpg" alt="[FTP Code]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">ftp.jpg</div>
				</div>
				<p>This enteringIntoPassive function is part of an FTP server implementation that handles the process of transitioning the server into passive mode for data transfer. The function first attempts to start a listener for incoming data connections using the startPassiveListener function. It uses a flag to determine whether this operation was successful. The server creates a response message using createPassiveSuccessResponse, which includes information like the port number where the server is listening for data connections and is sent to the client over the control connection using the sendToRemote function. The server checks if the listener socket is ready to accept a connection by calling isListenerSocketReady, which also handles timeout and error states. If the listener is ready to accept a connection, the server accepts the incoming connection using acceptClientConnection. The passive listener is stopped using stopPassiveListener, and a success response is prepared.</p>
				<p>While there are certainly many additional processes involved, this should provide a sufficient understanding of the work involved.</p>
			</div>
		`
	},
	"Compilers and Processes": {
		title: "Compilers and Processes",
		image: "Content/Portfolio/Compilers and Processes/banner.jpg",
		customHTML: `
			<div>
				<h1>Compilers and Processes</h1>
				<p>This exercise covers essential concepts for effectively using an operating system, including key processes that run within it. I demonstrate various CPU process schedulers used in time-sharing algorithms and explore semaphores in asynchronous programs for managing overlapping memory and ensuring coherence. I also showcase a self-made Linux shell. Additionally, I discuss my Oracle database management system, as well as a compiler parser I developed. Finally, I include a custom Bash script I created to automate console commands.</p>
				<div class="separator"></div>
				<p>This screenshot highlights five scheduling algorithms used to determine when operating system processes access hardware resources such as CPU cores or GPU buses.</p>
				<p>The algorithms showcased include first-come-first-serve, shortest-job-first, highest-priority-first, round-robin, and priority-round-robin. Round-robin is a preemptive scheduling algorithm that assigns each process a fixed time slice to execute. Once the time slice expires, the process moves to the back of the queue, and the next process begins execution. In priority round-robin, the process is reinserted into the queue based on its priority, ensuring higher-priority tasks are scheduled ahead of lower-priority ones.</p>
				<p>You can interpret the terminal output in the format "[Task Name] [Priority] [Remaining_Time]" for a closer examination.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Compilers and Processes/schedule.png" target="_blank">
							<img src="Content/Portfolio/Compilers and Processes/schedule.png" alt="[Process Scheduler]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">schedule.png</div>
				</div>
				<div class="separator"></div>
				<p>This example demonstrates how two threads (represented by teaching assistants 1 and 2) handle 10 jobs (represented by students 1 through 10). Each student is assigned a random programming duration before needing assistance from a TA again.</p>
				<p>The primary takeaway from this project is the importance of locking conditionals that check memory-sensitive information. When accessing memory, it's essential to lock it before viewing and unlock it when done. This concept forms the foundation of multi-threaded programming.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Compilers and Processes/semaphore.png" target="_blank">
							<img src="Content/Portfolio/Compilers and Processes/semaphore.png" alt="[Multi-Threading]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">semaphore.png</div>
				</div>
				<div class="separator"></div>
				<p>This program functions as a Linux shell, intercepting user commands and manipulating them before passing them to the system.</p>
				<p>Here, I demonstrate functionality for automated compilation and execution to boot the shell. Commands include "pwd" to print the working directory, "!!" to repeat the last command, "ls" to list all items in the current directory, "ls > output.txt" to redirect the output to a file, "cat output.txt | sort -r" to display the file contents in reverse-sorted order, "history" to track the last 10 commands, and "exit" to safely close the shell.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Compilers and Processes/shell.png" target="_blank">
							<img src="Content/Portfolio/Compilers and Processes/shell.png" alt="[Linux Shell]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">shell.png</div>
				</div>
				<div class="separator"></div>
				<p>I also worked on an Oracle-based relational database management system. This database management served as an application for an inexperienced user to be able to communicate to the Oracle database service through prepared SQL statements. </p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Compilers and Processes/database1.jpg" target="_blank">
							<img src="Content/Portfolio/Compilers and Processes/database1.jpg" alt="[Database Prompt]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">database1.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Compilers and Processes/database2.jpg" target="_blank">
							<img src="Content/Portfolio/Compilers and Processes/database2.jpg" alt="[Database Prepared Statement]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">database2.jpg</div>
				</div>
				<p>You can view the source code for my project here on Github. The source code has not been maintained since 2017.</p>
				<div class="scriptcontainer">
					<a href="https://github.com/Seelenmayer/Seelenmayer.github.io/tree/main/Content/Portfolio/Compilers%20and%20Processes/DBMS" id="downloadLink" target="_blank">
						<img src="Assets/script.png" alt="[Script Directory]">
					</a>
					<p>Database Management System</p>
				</div>
				<div class="separator"></div>
				<p>Next I'll talk about the compiler parser that I wrote for my C-styled language.</p>
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/Compilers and Processes/compilerdemo.mp4" target="_blank">
						<video class="displaymedia" poster="Content/Portfolio/Compilers and Processes/compilerdemo_poster.jpg" preload="metadata" loading="lazy" controls loop>
							<source src="Content/Portfolio/Compilers and Processes/compilerdemo.mp4" type="video/mp4">
							Your browser does not support the video tag.
						</video>
					</a>
					<div class="displaymediadescription">compilerdemo.mp4</div>
				</div>
				<div class="separator"></div>
				<p>This photo provides a glimpse into my laboratory work environment, featuring various open terminal windows and VIM, my preferred IDE.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Compilers and Processes/station.jpg" target="_blank">
							<img src="Content/Portfolio/Compilers and Processes/station.jpg" alt="[Linux Shell]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">station.png</div>
				</div>
				<p>Here is the bash script I wrote to help automate certain frequently used terminal commands, namely git submissions.</p>
				<div class="scriptcontainer">
					<a href="Content/Portfolio/Compilers and Processes/myBash.sh" id="downloadLink" target="_blank">
						<img src="Assets/script.png" alt="[Script]">
					</a>
					<p>myBash.sh</p>
				</div>
			</div>
		`
	},
	"Datastructures and Algorithms": {
		title: "Datastructures and Algorithms",
		image: "Content/Portfolio/Datastructures and Algorithms/banner.jpg",
		customHTML: `
			<div>
				<h1>Datastructures and Algorithms</h1>
				<p>This project demonstrates a strong understanding of datastructures, and algorithm analysis. First I reveal my Conway's Game of Life demo in OpenGL where I discuss a bit about emergent properties. Then I'll go over various algorithms and datastructures of increasing complexity until we reach the discussion point of big-O notation and "P=NP".</p>
				<div class="separator"></div>
				<p>This short demo briefly demonstrates the simple rule-set of Conway's Game of Life cellular automata where a cell survives only if exactly 2 or 3 adjacent cells were alive. This demo appears chaotic, but with a change in initial conditions, these instructions can be used to create some fascinating patterns from glider guns to digital clocks!</p>
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/Datastructures and Algorithms/conway.mp4" target="_blank">
						<video class="displaymedia" poster="Content/Portfolio/Datastructures and Algorithms/conway_poster.jpg" preload="metadata" loading="lazy" controls muted loop>
							<source src="Content/Portfolio/Datastructures and Algorithms/conway.mp4" type="video/mp4">
							Your browser does not support the video tag.
						</video>
					</a>
					<div class="displaymediadescription">conway.mp4</div>
				</div>
				<p>I'll include a fun paper I wrote that briefly suggests the idea of combining emergences of different patterns. The main take-away that I want to give is that I demonstrated an underlying understanding about turing machines.</p>
				<div class="pdfcontainer">
					<a href="Content/Portfolio/Datastructures and Algorithms/Cellular Automata & Procedural Generation.pdf" id="downloadLink" target="_blank">
						<img src="Assets/pdf.png" alt="[Magic Squares Download]">
					</a>
					<p>Cellular Automata & Procedural Generation.pdf</p>
				</div>
				<div class="separator"></div>
				<p>This next section briefly mentions some of the datastructures I've implemented such as stack, set, dictionary, and red-black trees. I avoid revealing too many implementation details.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Datastructures and Algorithms/stack.jpg" target="_blank">
							<img src="Content/Portfolio/Datastructures and Algorithms/stack.jpg" alt="[Stack Header]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">stack.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Datastructures and Algorithms/set.jpg" target="_blank">
							<img src="Content/Portfolio/Datastructures and Algorithms/set.jpg" alt="[Set Header]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">set.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Datastructures and Algorithms/dictionary.jpg" target="_blank">
							<img src="Content/Portfolio/Datastructures and Algorithms/dictionary.jpg" alt="[Dictionary Header]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">dictionary.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Datastructures and Algorithms/redblacktree.jpg" target="_blank">
							<img src="Content/Portfolio/Datastructures and Algorithms/redblacktree.jpg" alt="[RedBlackTree Example]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">redblacktree.jpg</div>
				</div>
				<div class="separator"></div>
				<p>This next particular exersize was just too cool to not reveal in its entirety. It serves as a demonstration for a deep understanding in recursive functions and inductive proofs.</p>
				<p>Given a 2^n by 2^n grid, you can select any particular square, and tesellate L-shaped trimono blocks around it that fill the containing grid.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Datastructures and Algorithms/QuadTreeTesselation.png" target="_blank">
							<img src="Content/Portfolio/Datastructures and Algorithms/QuadTreeTesselation.png" alt="[QuadTreeTesselation]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">QuadTreeTesselation.png</div>
				</div>
				<div class="scriptcontainer">
					<a href="https://github.com/Seelenmayer/Seelenmayer.github.io/tree/main/Content/Portfolio/Datastructures%20and%20Algorithms/Quad%20Tree%20Tesselation" id="downloadLink" target="_blank">
						<img src="Assets/script.png" alt="[Script Directory]">
					</a>
					<p>Quad Tree Tesselation</p>
				</div>
				<a href="https://undergroundmathematics.org/divisibility-and-induction/triominoes/solution" target="_blank">
					<p>You can view a more rigorous proof here!</p>
				</a>
				<div class="separator"></div>
				<p>This next algorithm is called the "Minimal Bump Lexicographic Linear Extension of Partially Ordered Sets" and will serve as my demonstration of more advanced C++ vector datastructures and implementation of a partially ordered set datastructure.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Datastructures and Algorithms/lexbump.jpg" target="_blank">
							<img src="Content/Portfolio/Datastructures and Algorithms/lexbump.jpg" alt="[Minimal Bump Example]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">lexbump.jpg</div>
				</div>
				<div class="scriptcontainer">
					<a href="https://github.com/Seelenmayer/Seelenmayer.github.io/tree/main/Content/Portfolio/Datastructures%20and%20Algorithms/Minimal%20Bump%20Lexicographic%20Linear%20Extension%20of%20Partially%20Ordered%20Sets" id="downloadLink" target="_blank">
						<img src="Assets/script.png" alt="[Script]">
					</a>
					<p>Minimal Bump Lexicographic Linear Extension of Partially Ordered Sets</p>
				</div>
				<div class="separator"></div>
				<p>In this next section we will delve into more advanced levels of algorithm analysis and dynamic programming, namely the chain matrix association problem!</p>
				<p>When we try multiplying matrices of differing dimensions, we find that the way we associate the matrix multiplications has an impact on the number of calculations we need to compute based solely on their dimensions. Now we can finally begin to discuss running time efficiency and so this solution that I've implemented runs in the big-O of n-cubed, denoted as O(n^3). This means that as the number of matrices increases, the complexity grows cubically in complexity!</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Datastructures and Algorithms/chainmatrix.jpg" target="_blank">
							<img src="Content/Portfolio/Datastructures and Algorithms/chainmatrix.jpg" alt="[Chain Matrix Association]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">chainmatrix.jpg</div>
				</div>
				<a href="https://cs.wmich.edu/gupta/teaching/cs4310/lectureNotes_cs4310/chainMatrixMultiplication%20from%20Dekai_AT_HKUST.pdf" target="_blank">
					<p>Click here to see Dekai's notes in case you want more insight on this particular solution.</p>
				</a>
				<a href="https://youtu.be/prx1psByp7U?si=8iq6SBVS5sNGsmmL" target="_blank">
					<p>Need a video to help explain? Don't worry, I got you!</p>
				</a>
				<p>Believe it or not, we can actually do much better than O(n^3)! I was able to uncover this paper by T.C. Hu and M.T. Shing.</p>
				<a href="http://i.stanford.edu/pub/cstr/reports/cs/tr/81/875/CS-TR-81-875.pdf" target="_blank">
					<p>Click here to see how we can solve the chain matrix association problem in an impressive O(nlogn) time!</p>
				</a>
				<p>If we consider a convex polygon whose edges represent the matrices, and whose vertices represent the shared integer dimension, this problem of chain matrix association reduces to that of polygon disection, which we know to run in O(nlogn).</p>
				<p>Its this type of thinking that allows us to compare and understand algorithms which lets us come closer to refining our understanding of the mythical problem "P=NP".</p>
			</div>
		`
	},
	"Bridge Project": {
		title: "Bridge Project",
		image: "Content/Portfolio/Bridge Project/banner.jpg",
		customHTML: `
			<div>
				<h1>Bridge Project</h1>
				<p>This project highlights my achievement in competing in Vancouver Island University's Bridge Building Competition of 2016 as well as the completion of VIU's Fundamentals of Engineering certification.</p>
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/Bridge Project/bridgedemo.mp4" target="_blank">
						<video class="displaymedia" poster="Content/Portfolio/Bridge Project/bridgedemo_poster.jpg" preload="metadata" loading="lazy" controls loop>
							<source src="Content/Portfolio/Bridge Project/bridgedemo.mp4" type="video/mp4">
							Your browser does not support the video tag.
						</video>
					</a>
					<div class="displaymediadescription">bridgedemo.mp4</div>
				</div>
				<p>My role in this project was to develop the electronic systems used in operating this bridge. There were many criteria to be met such as time, costs, span, weight, alloted load, clearance, speed limitations, traffic light controllers, and detection for civillians, vehicles, and ship traffic.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Bridge Project/bridge1.jpg" target="_blank">
							<img src="Content/Portfolio/Bridge Project/bridge1.jpg" alt="[Bridge]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">bridge1.jpg</div>
				</div>
				<p>My 3 teammates in this project took initiative on proposal writeups, drafting, construction, and gear ratio architectures. There were many times in which we had to work together to integrate new sensors, or accomodate for speed limitations. The idea of a gearbox came to be when we found that our bridge lifted too fast. Neither lowering the DC-motors analog voltage, nor using pulse-width modulation was sufficient, so we implemented a gear box instead. A worm-gear was used to prevent gravity from working against the DC-motor.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Bridge Project/bridge2.jpg" target="_blank">
							<img src="Content/Portfolio/Bridge Project/bridge2.jpg" alt="[Bridge]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">bridge2.jpg</div>
				</div>
				<p>One design consideration that came to be was the usage of an 8-bit shift-register. My original design began utilizing too many pins on the Arduino board, and so a shift register was implemented to convert 3 pins into a data, clock, and latch, which would manage 8 more output pins, effectively allowing for control over 5 more, if not many more devices. As cost restrictions became apparent, this technology was disposed of.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Bridge Project/electronics.jpg" target="_blank">
							<img src="Content/Portfolio/Bridge Project/electronics.jpg" alt="[Electronics]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">electronics.jpg</div>
				</div>
				<ul>
					<li>
						<strong>Vehicle and Ship Detection:</strong>
						<ul>
							<p>Used an ultrasonic sensor to issue sound waves and measure the return time.</p>
							<p>Calculated object distance by dividing the return time by the speed of sound.</p>
							<p>Checked for consecutive detections to mitigate external noise and improve accuracy.</p>
							<p>Incremented or decremented the object count when a vehicle or ship passed the detection threshold.</p>
						</ul>
					</li>
					<li>
						<strong>Civilian Detection and Double-Bascule Bridge States:</strong>
						<ul>
							<p>Used conductive pads on cushioned materials to complete an electrical connection.</p>
							<p>Employed a polling system (as opposed to an interrupt service routine) to take over operations when the connection was detected.</p>
						</ul>
					</li>
					<li>
						<strong>Motor Management:</strong>
						<ul>
							<p>Signaled an H-bridge chip to reverse polarity and control the bridge's motion.</p>
						</ul>
					</li>
					<li>
						<strong>Traffic Signal Management:</strong>
						<ul>
							<p>Used 4 LEDs to represent various traffic light signals.</p>
							<p>Each LED blinked and responded based on specific criteria.</p>
						</ul>
					</li>
				</ul>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Bridge Project/bridge3.jpg" target="_blank">
							<img src="Content/Portfolio/Bridge Project/bridge3.jpg" alt="[Bridge]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">bridge3.jpg</div>
				</div>
				<div class="scriptcontainer">
					<a href="Content/Portfolio/Bridge Project/BridgeController.txt" id="downloadLink" target="_blank">
						<img src="Assets/script.png" alt="[Script]">
					</a>
					<p>BridgeController.txt</p>
				</div>
			</div>
		`
	},
	"Virtual Reality": {
		title: "Virtual Reality",
		image: "Content/Portfolio/Virtual Reality/banner.jpg",
		customHTML: `
			<div>
				<h1>Virtual Reality</h1>
				<p>This project outlines some of my experiences working with virtual reality systems.</p>
				<p>For starters, I helped Cloudhead Games playtest Pistol Whip while it was still in prototyping. Later, I setup my HTC Vive and coordinated it within the Unity environment using their XR plugins.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Virtual Reality/demo1.png" target="_blank">
							<img src="Content/Portfolio/Virtual Reality/demo1.png" alt="[Virtual Reality Demo]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">demo1.jpg</div>
				</div>
				<p>I later helped a team develop a VR scenario. My task was to implement dynamic level loading over a network using JSON files as descriptors, create a wrapper to utilize the Obi Rope library, assist artists in using Unity's shader graph and Perforce version control, and more. I helped lead in playtesting and carefully documented everything in as few runs as possible.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Virtual Reality/demo2.png" target="_blank">
							<img src="Content/Portfolio/Virtual Reality/demo2.png" alt="[Virtual Reality Demo Scene]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">demo2.png</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Virtual Reality/demo3.png" target="_blank">
							<img src="Content/Portfolio/Virtual Reality/demo3.png" alt="[Virtual Reality Demo Scene]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">demo3.png</div>
				</div>
				<p>I'm particularily proud of this scene as it shows the use of my wrapper to the Obi Rope library in placing these pipes. It also shows careful attention to lighting. I created a light in the sky that is occluded by the manhole. I also created two lights on the floor; one that is occluded by the scene, and another that is not. These 3 lights show a strong understanding of the phong reflection model which describe lighting as a composition of specular, diffuse, and ambient lighting.</p>
				<p>Lastly, I helped develop an Unreal Engine plugin that used computer vision and AI to predict scene placement through a Python environment on AWS. It encorporated 3rd party widgets such as video-to-3d-model, texture-recommendation, text-to-voice, and text-translation. The last image was generated from the prompt "jungle" with a folder of office assets.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Virtual Reality/demo4.png" target="_blank">
							<img src="Content/Portfolio/Virtual Reality/demo4.png" alt="[Virtual Reality Demo Scene]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">demo4.png</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Virtual Reality/demo5.png" target="_blank">
							<img src="Content/Portfolio/Virtual Reality/demo5.png" alt="[Virtual Reality Demo Scene]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">demo5.png</div>
				</div>
			</div>
		`
	},
	"Miscellaneous": {
		title: "Miscellaneous",
		image: "Content/Portfolio/Miscellaneous/banner.jpg",
		customHTML: `
			<div>
				<h1>Miscellaneous</h1>
				<p>This project is a collection of small but noteworthy exercises. It features a project for using render textures to make a portal in Unity, a console organizer which demonstrates meta-programming, a group game project with shaders in Godot, a brief showcase of ThreeJS for displaying 3D renderings in a browser, render textures simulating a portal effect, and image downscaling techniques for a memory-limited Game Boy ROM game.</p>
				<div class="separator"></div>
				<p>This project demonstrates my first group game project, Bailey's Catastrophe, which was cut short due to the pandemic lockdown. It was my first experience in the Godot engine where I worked on the background, shaders, level loading systems, and version control management. I was particularily proud of my pixelization shader which allowed us to render 3d objects in a 2d 32bit pixelated way. This went hand-in-hand with our tile-based level design structure which paved a way for generative level branching.</p>
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/Miscellaneous/BaileysCatastrophe1.mp4" target="_blank">
						<video class="displaymedia" poster="Content/Portfolio/Miscellaneous/BaileysCatastrophe1_poster.jpg" preload="metadata" loading="lazy" controls muted loop>
							<source src="Content/Portfolio/Miscellaneous/BaileysCatastrophe1.mp4" type="video/mp4">
							Your browser does not support the video tag.
						</video>
					</a>
					<div class="displaymediadescription">BaileysCatastrophe1.mp4</div>
				</div>
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/Miscellaneous/BaileysCatastrophe2.mp4" target="_blank">
						<video class="displaymedia" poster="Content/Portfolio/Miscellaneous/BaileysCatastrophe2_poster.jpg" preload="metadata" loading="lazy" controls muted loop>
							<source src="Content/Portfolio/Miscellaneous/BaileysCatastrophe2.mp4" type="video/mp4">
							Your browser does not support the video tag.
						</video>
					</a>
					<div class="displaymediadescription">BaileysCatastrophe2.mp4</div>
				</div>
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/Miscellaneous/BaileysCatastrophe3.mp4" target="_blank">
						<video class="displaymedia" poster="Content/Portfolio/Miscellaneous/BaileysCatastrophe3_poster.jpg" preload="metadata" loading="lazy" controls muted loop>
							<source src="Content/Portfolio/Miscellaneous/BaileysCatastrophe3.mp4" type="video/mp4">
							Your browser does not support the video tag.
						</video>
					</a>
					<div class="displaymediadescription">BaileysCatastrophe3.mp4</div>
				</div>
				<div class="separator"></div>
				<p>This demo demonstrates how a camera's render can be used as a texture and applied to a material in real-time, creating the illusion of looking through a portal. On the right side of the screen, you can experience the effect from the intended perspective, while the left side provides an external view where the illusion is broken. This contrast offers an intuitive understanding of how the effect is achieved.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Miscellaneous/RenderImg.jpg" target="_blank">
							<img src="Content/Portfolio/Miscellaneous/RenderImg.jpg" alt="[Render Textures Example]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">RenderImg.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/Miscellaneous/Render.mp4" target="_blank">
						<video class="displaymedia" poster="Content/Portfolio/Miscellaneous/Render_poster.jpg" preload="metadata" loading="lazy" controls muted loop>
							<source src="Content/Portfolio/Miscellaneous/Render.mp4" type="video/mp4">
							Your browser does not support the video tag.
						</video>
					</a>
					<div class="displaymediadescription">Render.mp4</div>
				</div>
				<div class="separator"></div>
				<p>Based on the DrowzyFox logger, I implemented a Unity console logger that allows users to print arbitrary objects to the console in colour. It later serverd on a proprietary project as a tool for various users on the same project to filter between eachothers logs. This creation demonstrates an understanding and utilization of lambda functions in abstract meta-programming.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Miscellaneous/Consolelogger.jpg" target="_blank">
							<img src="Content/Portfolio/Miscellaneous/Consolelogger.jpg" alt="[Console Demo]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">Consolelogger.jpg</div>
				</div>
				<div class="scriptcontainer">
					<a href="Content/Portfolio/Miscellaneous/Logger.cs" id="downloadLink" target="_blank">
						<img src="Assets/script.png" alt="[Script]">
					</a>
					<p>Logger.cs</p>
				</div>
				<div class="separator"></div>
				<p>The MobiusArt project was a website where users could login and upload or download zipped 3d-models from a MySQL database through PHP scripts and be displayed interactively using the ThreeJS library with trackball controls with mobile accessibility in consideration.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Miscellaneous/MobiusArt.jpg" target="_blank">
							<img src="Content/Portfolio/Miscellaneous/MobiusArt.jpg" alt="[Website]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">MobiusArt.jpg</div>
				</div>
				<a href="https://github.com/Seelenmayer/Seelenmayer.github.io/tree/main" target="_blank">
					<p>For more web developer related work, you can view this very website that you're reading's source code on Github here.</p>
				</a>
				<div class="separator"></div>
				<p>Here are a few screenshots of a Nintendo Gameboy ROM game that I built. The main take-away that I found from this project was utilizing the limited available RAM in rendering the on screen textures. The scene is composed of several sprites neatly put together as rendering one full image was beyond memory limitations. The scenes themselves were designed by downscaling the resolution and colour pallete of existing images.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Miscellaneous/Gameboy1.png" target="_blank">
							<img src="Content/Portfolio/Miscellaneous/Gameboy1.png" alt="[Gameboy Game 1]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">Gameboy1.png</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Miscellaneous/Gameboy2.png" target="_blank">
							<img src="Content/Portfolio/Miscellaneous/Gameboy2.png" alt="[Gameboy Game 2]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">Gameboy2.png</div>
				</div>
			</div>
		`
	},
	"Magic Squares": {
		title: "Magic Squares",
		image: "Content/Portfolio/Magic Squares/banner.jpg",
		customHTML: `
			<div>
				<h1>Magic Squares</h1>
				<p>This was my first academic paper, written during the pandemic lockdown. It represents my initial experience with coding in LaTeX and reflects the level of mathematics I had studied at the time. Focused on linear algebra, it explores concepts closely tied to graphics development. Notably, this is the only paper I can publicly release while adhering to academic integrity guidelines.</p>
				<div class="pdfcontainer">
					<a href="Content/Portfolio/Magic Squares/Magic Squares.pdf" id="downloadLink" target="_blank">
						<img src="Assets/pdf.png" alt="[Magic Squares Download]">
					</a>
					<p>Magic Squares.pdf</p>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Magic Squares/magic.jpg" target="_blank">
							<img src="Content/Portfolio/Magic Squares/magic.jpg" alt="[Magic Squares Cover]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">magic.jpg</div>
				</div>
			</div>
		`
	},
	"Japanese": {
		title: "Japanese",
		image: "Content/Portfolio/Japanese/banner.jpg",
		customHTML: `
			<div>
				<h1>Japanese</h1>
				<p>Here contains my works from my Japanese language proficiency courses. It shows a short cultural paper that I wrote comparing video game cultures, and includes my journal entries written in Japanese.</p>
				<div class="pdfcontainer">
					<a href="Content/Portfolio/Japanese/Japanese American Influence on Video Game Development.pdf" id="downloadLink" target="_blank">
						<img src="Assets/pdf.png" alt="[Japanese American Influence on Video Game Development]">
					</a>
					<p>Japanese American Influence on Video Game Development.pdf</p>
				</div>
				<div class="separator"></div>
				<div class="pdfcontainer">
					<a href="Content/Portfolio/Japanese/Japanese Journal 7 - Holiday (Translated).pdf" id="downloadLink" target="_blank">
						<img src="Assets/pdf.png" alt="[Holiday]">
					</a>
					<p>Japanese Journal 7 - Holiday (Translated).pdf</p>
				</div>
				<div class="pdfcontainer">
					<a href="Content/Portfolio/Japanese/Japanese Journal 6 - Casual Entries (Translated).pdf" id="downloadLink" target="_blank">
						<img src="Assets/pdf.png" alt="[Casual Entires (Translated)]">
					</a>
					<p>Japanese Journal 6 - Casual Entries (Translated).pdf</p>
				</div>
				<div class="pdfcontainer">
					<a href="Content/Portfolio/Japanese/Japanese Journal 5 - Day Off.pdf" id="downloadLink" target="_blank">
						<img src="Assets/pdf.png" alt="[Day Off]">
					</a>
					<p>Japanese Journal 5 - Day Off.pdf</p>
				</div>
				<div class="pdfcontainer">
					<a href="Content/Portfolio/Japanese/Japanese Journal 4 - Hometown.pdf" id="downloadLink" target="_blank">
						<img src="Assets/pdf.png" alt="[Hometown]">
					</a>
					<p>Japanese Journal 4 - Hometown.pdf</p>
				</div>
				<div class="pdfcontainer">
					<a href="Content/Portfolio/Japanese/Japanese Journal 3 - Time with Friends.pdf" id="downloadLink" target="_blank">
						<img src="Assets/pdf.png" alt="[Time with Friends]">
					</a>
					<p>Japanese Journal 3 - Time with Friends.pdf</p>
				</div>
				<div class="pdfcontainer">
					<a href="Content/Portfolio/Japanese/Japanese Journal 2 - Favourite Place.pdf" id="downloadLink" target="_blank">
						<img src="Assets/pdf.png" alt="[Favourite Place]">
					</a>
					<p>Japanese Journal 2 - Favourite Place.pdf</p>
				</div>
				<div class="pdfcontainer">
					<a href="Content/Portfolio/Japanese/Japanese Journal 1 - Favourite Movie.pdf" id="downloadLink" target="_blank">
						<img src="Assets/pdf.png" alt="[Favourite Movie]">
					</a>
					<p>Japanese Journal 1 - Favourite Movie.pdf</p>
				</div>
			</div>
		`
	},
	"Maxs Mushrooms": {
		title: "Maxs Mushrooms",
		image: "Content/Portfolio/Maxs Mushrooms/banner.jpg",
		customHTML: `
			<div>
				<h1>Maxs Mushrooms</h1>
				<p>This section is a throwback to the family produce business that I helped work on the frontlines for over many years. My job was to intake customer orders, place order requests with suppliers, help plan routes, and organize the truck in an efficient and logical manner for ease of delivery. This job essentially derives itself from the NP-c traveling salesman problem and box packing problem.</p>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Maxs Mushrooms/max1.jpg" target="_blank">
							<img src="Content/Portfolio/Maxs Mushrooms/max1.jpg" alt="[Max]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">max1.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Maxs Mushrooms/max2.jpg" target="_blank">
							<img src="Content/Portfolio/Maxs Mushrooms/max2.jpg" alt="[Max]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">max2.jpg</div>
				</div>
				<div class="displaymediacontainer">
					<div class="displaymediawrapper">
						<a href="Content/Portfolio/Maxs Mushrooms/roger.jpg" target="_blank">
							<img src="Content/Portfolio/Maxs Mushrooms/roger.jpg" alt="[Roger]" class="displaymedia">
							<img src="Assets/imageoverlay.png" class="displaymediaoverlay">
						</a>
					</div>
					<div class="displaymediadescription">roger.jpg</div>
				</div>
			</div>
		`
	},
	"Music": {
		title: "Music",
		image: "Content/Portfolio/Music/banner.jpg",
		customHTML: `
			<div>
				<h1>Music</h1>
				<p>I love playing music in my spare time. I spent most of my life playing percussion, but along the way found many other fascinating instruments ranging from 6 or 12 string electric and acoustic guitars, 4 or 5 string basses, piano, xylophone, or even a pan flute!</p>
				<p>In this section, I wanted to showcase some of my few available recordings. Starting from Diablo's "Tristram" town theme on guitar, then Maplestory's "Ellinia" town theme on piano, and lastly, Maplestory's "Orbis" town theme on xylophone.</p>
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/Music/tristram.mp4" target="_blank">
						<video class="displaymedia" poster="Content/Portfolio/Music/tristram_poster.jpg" preload="metadata" loading="lazy" controls loop>
							<source src="Content/Portfolio/Music/tristram.mp4" type="video/mp4">
							Your browser does not support the video tag.
						</video>
					</a>
					<div class="displaymediadescription">tristram.mp4</div>
				</div>
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/Music/ellinia.mp4" target="_blank">
						<video class="displaymedia" poster="Content/Portfolio/Music/ellinia_poster.jpg" preload="metadata" loading="lazy" controls loop>
							<source src="Content/Portfolio/Music/ellinia.mp4" type="video/mp4">
							Your browser does not support the video tag.
						</video>
					</a>
					<div class="displaymediadescription">ellinia.mp4</div>
				</div>
				<div class="displaymediacontainer">
					<a href="Content/Portfolio/Music/orbis.mp4" target="_blank">
						<video class="displaymedia" poster="Content/Portfolio/Music/orbis_poster.jpg" preload="metadata" loading="lazy" controls loop>
							<source src="Content/Portfolio/Music/orbis.mp4" type="video/mp4">
							Your browser does not support the video tag.
						</video>
					</a>
					<div class="displaymediadescription">orbis.mp4</div>
				</div>
			</div>
		`
	},
};

let currentPage = 0;
const projectsPerPage = 4;
const projectKeys = Object.keys(projects);

// Function to render the current page of projects
function renderProjects() {
	const nav = document.querySelector('nav ul');
	nav.innerHTML = '';
	const startIndex = currentPage * projectsPerPage;
	const endIndex = Math.min(startIndex + projectsPerPage, projectKeys.length);

	for (let i = startIndex; i < endIndex; i++) {
		const projectKey = projectKeys[i];
		const project = projects[projectKey];
		nav.innerHTML += `
			<div class="navprojectcontainer">
				<div class="navproject">
					<a href="#" onclick="showProjectDetails('${projectKey}'); return false;">
						<img src="${project.image}" alt="[Project Image]" class="projectimage">
						<span class="navprojectoverlay">${project.title}</span>
					</a>
				</div>
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
	const totalPages = Math.ceil(projectKeys.length / projectsPerPage);
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
		${project.customHTML}
		<div class="separator"></div>
	`;
}