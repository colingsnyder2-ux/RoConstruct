/**
 @file BumpMapViewer/Viewer.cpp
 @maintainer Morgan McGuire, matrix@graphics3d.com
 @created 2004-06-25
 @edited  2004-06-25
 */


#include "header.h"

Viewer::Viewer(App* _app) : GApplet(_app), app(_app) {
    bumpEffect = BumpEffect::create();
}


void Viewer::init()  {
    // Called before Viewer::run() beings
    app->debugCamera.setPosition(Vector3(0, 0, 4));
    app->debugCamera.lookAt(Vector3(0, 0, 0));

	entityArray.append(Entity::create(Mesh::quad(), CoordinateFrame()));
//	entityArray.last()->cframe.translation.x = -3;

	bumpEffect->load(app->fileArray[0]);
	bumpEffect->light = Vector4(0,1,1,1);
    bumpEffect->environmentMap = app->sky->getEnvironmentMap();
}


void Viewer::cleanup() {
    // Called when Viewer::run() exits
}


void Viewer::doSimulation(SimTime dt) {
	double t = System::getTick();
	for (int e = 0; e < entityArray.size(); ++e) {
		EntityRef& entity = entityArray[e];

		double a = t + e;

		Vector3 target =
			entity->cframe.translation +
			Vector3(cos(a) * .5, -1, -1 + sin(a) * .5);

		entity->cframe.lookAt(target);
	}
}


void Viewer::doLogic() {
    if (app->userInput->keyPressed(SDLK_ESCAPE)) {
        // Even when we aren't in debug mode, quit on escape.
        endApplet = true;
        app->endProgram = true;
    }

	if (app->userInput->keyPressed('p')) {
		// Toggle parallax
		if (bumpEffect->bumpScale > 0) {
			bumpEffect->bumpScale = 0.0;
		} else {
			bumpEffect->bumpScale = 0.04;
		}
	}
	// Add other key handling here
}


void Viewer::doGraphics() {

    LightingParameters lighting(G3D::toSeconds(11, 00, 00, AM));
    app->renderDevice->setProjectionAndCameraMatrix(app->debugCamera);

    // Cyan background
    app->renderDevice->setColorClearValue(Color3(.1, .5, 1));

    app->renderDevice->clear(app->sky.isNull(), true, true);
    if (! app->sky.isNull()) {
        app->sky->render(lighting);
    }

    // Setup lighting
    app->renderDevice->enableLighting();
		app->renderDevice->setLight(0, GLight::directional(lighting.lightDirection, lighting.lightColor));
		app->renderDevice->setAmbientLightColor(lighting.ambient);

		if (bumpEffect->light.w != 0) {
			Draw::sphere(Sphere(bumpEffect->light.xyz(), .10), app->renderDevice, Color3::WHITE);
		}

        app->renderDevice->setShader(bumpEffect);
		for (int e = 0; e < entityArray.size(); ++e) {
			entityArray[e]->render(app->renderDevice);
		}
        app->renderDevice->setShader(NULL);

    app->renderDevice->disableLighting();

    if (! app->sky.isNull()) {
        app->sky->renderLensFlare(lighting);
    }
}


//////////////////////////////////////////

EntityRef Entity::create(const MeshRef& m, const CoordinateFrame& c) {
	return new Entity(m, c);
}


Entity::Entity(const MeshRef& m, const CoordinateFrame& c) : mesh(m), cframe(c) {
}


void Entity::render(RenderDevice* rd) {
	rd->pushState();
		rd->setObjectToWorldMatrix(cframe);
		mesh->render(rd);
	rd->popState();
}


