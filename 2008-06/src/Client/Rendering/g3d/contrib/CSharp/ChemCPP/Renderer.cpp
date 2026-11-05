#include "StdAfx.h"
#include ".\renderer.h"

#include <G3DAll.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include <iostream>





static std::vector<AtomStruct> atoms;
static std::vector<BondStruct> bonds;

// Some G3D variables which we need for all the rendering;
// We define these here becaues we get link errors if we try to make them
// member data of the renderer. -sab
G3D::SkyRef sky;
G3D::GFontRef font;

Renderer::Renderer(bool createDebugMolecule)
{
	_yRotation = 0; 
	_camera = new G3D::GCamera();
 
}

Renderer::~Renderer(void)
{
}

void
Renderer::initHWND(HWND hwnd, int width, int height) 
{
	G3D::GWindowSettings settings;
	settings.width = width;
	settings.height = height;
	// Turn on antialiasing for nice high-quality smooth look
	settings.fsaaSamples = 8; 
	_gWindow = G3D::Win32Window::create(settings, hwnd); 
	_rd = new RenderDevice();
	_rd->init(_gWindow);
	font = G3D::GFont::fromFile(_rd, "C:/libraries/g3d-6_06/data/font/arial.fnt");
	resetScene();
}

void
Renderer::renderScene() 
{
	// Render with calls to RenderDevice!!!
	_rd->beginFrame();
	_rd->clear();

	_rd->setProjectionAndCameraMatrix(*_camera);

	// Set up camera and lighting
	G3D::LightingParameters lightParams(G3D::toSeconds(11, 00, 00, AM));
	_rd->setAmbientLightColor(lightParams.ambient);
	_rd->setLight(0, GLight::directional(lightParams.lightDirection, lightParams.lightColor));
	_rd->setLight(1, GLight::directional(-lightParams.lightDirection, Color3::white() * .4));

	// The sky does its own lighting; leave lighting disabled when drawing the sky
	sky->render(_rd, lightParams);

	// Enable lighting before drawing elements in the scene
	_rd->enableLighting();

	if (!atoms.empty()) {
		drawBonds();
		drawArrows();
		drawAtoms();
		drawLabels();
		drawOverlay();
	} else {
		G3D::Sphere carbon(Vector3(-3, 0, 0), 1.0);
		G3D::Draw::sphere(carbon, _rd, Color3::random(), Color4::clear());
		carbon.center = Vector3(0, 0, 0);
		G3D::Draw::sphere(carbon, _rd, Color3::random(), Color4::clear());
		carbon.center = Vector3(3, 0, 0);
		G3D::Draw::sphere(carbon, _rd, Color3::random(), Color4::clear());
	}
	_rd->endFrame();

}

void Renderer::resetScene() 
{
	clearModel();
	sky = G3D::Sky::fromFile(_rd, "C:/libraries/g3d-6_06/data/sky/");
	_camera->setPosition(Vector3(0, 0, getCameraZPos()));
    _camera->lookAt(Vector3(0, 0, 0));
	_yRotation = 0; 
	spinY(0);
}

float
Renderer::getCameraZPos() {
	// TODO: get bounds of molecule

	return 5.0f;
}

void Renderer::clearModel()
{
	atoms.clear();
	bonds.clear();
}

void Renderer::spinY(float radians)
{
	_yRotation += radians;

	// Calculate x-z position of camera, and make it look at origin
	double distanceToOrigin = getCameraZPos(); // hardcoded to be reasonable
	double x = distanceToOrigin * sin(_yRotation);
	double z = distanceToOrigin * cos(_yRotation);

	_camera->setPosition(Vector3(x, 0, z)); 
	_camera->lookAt(Vector3(0,0,0));
}


void Renderer::addAtom(AtomStruct atom) 
{

	atoms.insert(atoms.end(), atom);
	int numAtoms = atoms.size();
}

void Renderer::addBond(BondStruct bond) 
{
	bonds.insert(bonds.end(), bond);
}

void Renderer::drawAtoms() {
	Sphere atomSphere; 
	Color4 atomColor = Color3::white();

	int numAtoms = atoms.size();

	for (int i=0; i < atoms.size(); i++) {
		AtomStruct atom = atoms[i];
		Color4 atomColor = Color3::white();
		
		// Position the sphere at the atom's location
		atomSphere.center = Vector3(atom.x, atom.y, atom.z);

		
		// Set the sphere's color and radius to match the element 
		// it represents.
		// Note: we're not looking up correct atomic radii and standard colors yet.

		atomSphere.radius = 0.2;
		
		float scaleFactor = 3.0; 

		if (atom.elementNumber == 1)  {
			atomColor = Color3::white();
			atomSphere.radius = scaleFactor * 0.1000;
		} else if (atom.elementNumber == 8) {
			atomColor = Color3::red();
			atomSphere.radius = scaleFactor * 0.1520;
		} else if (atom.elementNumber == 6) {
			atomColor = Color3::gray();
			atomSphere.radius = scaleFactor * 0.1700;
		} else {
			atomSphere.radius = scaleFactor * 0.1700;
			atomColor = Color3::purple(); 
		}

		//Log::common()->printf("drawAtoms: atom: %d, x=%f, y=%f, z=%f, elem=%d, id=%d\n", 
		//	i, atom.x, atom.y, atom.z, atom.elementNumber, atom.ID);
		G3D::Draw::sphere(atomSphere, _rd, atomColor, Color4::clear());
	
		// Just for fun -- draw transparent spheres representing the outer electron clouds
		atomSphere.radius = atomSphere.radius * 2;
		atomColor.a = 0.2;
		G3D::Draw::sphere(atomSphere, _rd, atomColor, Color4::clear());

	}

}

void Renderer::drawBonds() {
	Color4 bondColor = Color3::white();
	Color4 wireColor = Color4::clear();
	float radius = 0.05; // radius of a bond -- just a guess. 
	

	for (int i=0; i < bonds.size(); i++) {
	
		// find the center of atom at one end of bond
		Vector3 p1 = findAtomPosition(bonds[i].atomIndex1);
		
		// find the center of atom at the other end of bond
		Vector3 p2 = findAtomPosition(bonds[i].atomIndex2);

		// set the capsule to be from one end to the other
		G3D::Capsule bondCapsule(p1, p2, radius);

		// draw the capsule
		G3D::Draw::capsule(bondCapsule, _rd, bondColor, wireColor);
	}
}


/// <summary>Draw some test strings, to demonstrate how to draw text.
void Renderer::drawLabels() 
{
	std::string labelText;
	G3D::Vector3 labelPosition;
	G3D::CoordinateFrame cframe;
	G3D::Vector3 offsetFromAtom(0.05, -0.05, 0);

	double flipAngle = G3D::pi();
	Matrix3 yFlipRot = Matrix3::fromAxisAngle(Vector3::UNIT_Y, flipAngle);

	for (int i=0; i < atoms.size(); i++) {
		// Move the label a bit away from the atom's center
		// Note that the label position specifies the top, right-hand corner of the text
		labelPosition = findAtomPosition(i) + offsetFromAtom; 
		cframe.translation = labelPosition;
		labelText = G3D::format("%d", i);
		cframe.lookAt(
			_camera->getCoordinateFrame().translation,
			G3D::Vector3::UNIT_Y);
		// Rotate the text so the camera sees its frontside, not its backside.
		cframe.rotation = cframe.rotation * yFlipRot;
		font->draw3D(labelText, cframe);
	}
			
}

void 
Renderer::drawArrows() 
{
	Vector3 start = findAtomPosition(3);
	Vector3 end = findAtomPosition(4);
	Vector3 direction = start - end;
	G3D::Draw::arrow(end, direction, _rd);
}

void
Renderer::drawOverlay() 
{
	std::string overlayText = "Cats like chemistry.";
	_rd->push2D();
	font->draw2D(overlayText, Vector2(10, 40), 20);
	_rd->pop2D();
}

G3D::Vector3 
Renderer::findAtomPosition(int atomID) 
{
	for (int i=0; i < atoms.size(); i++) {
		if (atoms[i].ID == atomID) 
			return Vector3(atoms[i].x, atoms[i].y, atoms[i].z);
	}
	G3D::Log::common()->printf("No atom found for id %d", atomID);
	return Vector3(0, 0, 0);
}

extern "C" CHEMCPP_API Renderer* CreateCppInternals() 
{
	return new Renderer(false);
}

extern "C" CHEMCPP_API void DeleteCppInternals(Renderer * instance)
{
	delete instance;
}

extern "C" CHEMCPP_API void InitHWND(Renderer * instance, HWND hwnd, int width, int height)
{
	instance->initHWND(hwnd, width, height);
}

extern "C" CHEMCPP_API void RenderScene(Renderer * instance) 
{
	instance->renderScene();
}

extern "C" CHEMCPP_API void ClearModel(Renderer * instance)
{
	instance->clearModel();
}

extern "C" CHEMCPP_API void AddAnAtom(Renderer * instance, AtomStruct atom) 
{
	instance->addAtom(atom);
}

extern "C" CHEMCPP_API void AddBond(Renderer * instance, BondStruct bond)
{
	instance->addBond(bond);
}

extern "C" CHEMCPP_API void SpinY(Renderer * instance, float radians)
{
	instance->spinY(radians);
}
