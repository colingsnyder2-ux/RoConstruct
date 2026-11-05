/**
  @file ArticulatedModel/demo.cpp

  Uses G3D: http://g3d-cpp.sf.net
  Compiles for Win32 and Linux

  @author Morgan McGuire, matrix@graphics3d.com
 */

#include <G3DAll.h>

#if G3D_VER < 60900
    #error Requires G3D 6.09
#endif

#include "App.h"

// When not in the same directory, you can #include these files 
// from the G3D distribution as:
#include "../all.h"


GApp* app = NULL; 

/**
 This simple demo applet uses the debug mode as the regular
 rendering mode so you can fly around the scene.
 */
class Demo : public GApplet {
private:

    void generateShadowMap(const GLight& light, const Array<PosedModelRef>& shadowCaster);

    ToneMap                     toneMap;

    TextureRef                  shadowMap;
    Matrix4                     lightMVP;

    TextureRef                  logo;

public:

    // Add state that should be visible to this applet.
    // If you have multiple applets that need to share
    // state, put it in the App.

    class App*					app;

    Demo(App* app);    

    virtual void onInit();

    virtual void doSimulation(RealTime dt);

    virtual void onUserInput(UserInput* ui);

    virtual void onGraphics(RenderDevice* rd);

};


/**
 Width and height of shadow map.
 */
int shadowMapSize = 512;

Demo::Demo(App* _app) : GApplet(_app), app(_app) {

    if (beginsWith(GLCaps::vendor(), "ATI")) {
        // On ATI cards, large shadow maps cause terrible performance during the
        // copy from the back buffer on recent drivers.
        shadowMapSize = 64;
    }

    if (GLCaps::supports_GL_ARB_shadow()) {        
        shadowMap = Texture::createEmpty(shadowMapSize, shadowMapSize, "Shadow map", TextureFormat::depth(),
            Texture::CLAMP, Texture::BILINEAR_NO_MIPMAP, Texture::DIM_2D, Texture::DEPTH_LEQUAL, 1);  
    }

    logo = Texture::fromFile("G3D-logo-tiny-alpha.tga", TextureFormat::AUTO, Texture::CLAMP);
}


void Demo::onInit()  {
	// Called before Demo::run() beings
    app->debugCamera.setPosition(Vector3(0, 0, 10));
    app->debugCamera.lookAt(Vector3(0, 0, 0));
}


void Demo::doSimulation(RealTime dt) {
}


void Demo::onUserInput(UserInput* ui) {
    if (ui->keyPressed(SDLK_ESCAPE)) {
        // Even when we aren't in debug mode, quit on escape.
        endApplet = true;
        app->endProgram = true;
    }

    if (ui->keyPressed(' ')) {
        toneMap.setEnabled(! toneMap.enabled());
    }
}


bool debugShadows = false;

void Demo::generateShadowMap(const GLight& light, const Array<PosedModelRef>& shadowCaster) {
    debugAssert(GLCaps::supports_GL_ARB_shadow()); 

    Rect2D rect = Rect2D::xywh(0, 0, shadowMapSize, shadowMapSize);
    
    app->renderDevice->pushState();

        const double lightProjX = 12, lightProjY = 12, lightProjNear = 1, lightProjFar = 40;

        // Construct a projection and view matrix for the camera so we can 
        // render the scene from the light's point of view

        // Since we're working with a directional light, 
        // we want to make the center of projection for the shadow map
        // be in the direction of the light but at a finite distance 
        // to preserve z precision.
        Matrix4 lightProjectionMatrix(Matrix4::orthogonalProjection(-lightProjX, lightProjX, -lightProjY, lightProjY, lightProjNear, lightProjFar));

        CoordinateFrame lightCFrame;
        lightCFrame.translation = light.position.xyz() * 20;

        // The light will never be along the z-axis
        lightCFrame.lookAt(Vector3::zero(), Vector3::unitZ());

        debugAssert(shadowMapSize < app->renderDevice->getHeight());
        debugAssert(shadowMapSize < app->renderDevice->getWidth());

        app->renderDevice->setColorClearValue(Color3::white());
        app->renderDevice->clear(debugShadows, true, false);

        app->renderDevice->enableDepthWrite();
        app->renderDevice->setViewport(rect);

	    // Draw from the light's point of view
        app->renderDevice->setCameraToWorldMatrix(lightCFrame);
        app->renderDevice->setProjectionMatrix(lightProjectionMatrix);

        // Flip the Y-axis to account for the upside down Y-axis on read back textures
        lightMVP = lightProjectionMatrix * lightCFrame.inverse();

        if (! debugShadows) {
            app->renderDevice->disableColorWrite();
        }

        // Avoid z-fighting
        app->renderDevice->setPolygonOffset(2);

        app->renderDevice->setAlphaTest(RenderDevice::ALPHA_GREATER, 0.5);
        for (int s = 0; s < shadowCaster.size(); ++s) {
            shadowCaster[s]->render(app->renderDevice);
        }
   
    app->renderDevice->popState();
    
    debugAssert(shadowMap.notNull());
    shadowMap->copyFromScreen(rect);
    
}



void Demo::onGraphics(RenderDevice* rd) {
    LightingRef        lighting      = toneMap.prepareLighting(app->lighting);
    LightingParameters skyParameters = toneMap.prepareLightingParameters(app->skyParameters);

    if (! GLCaps::supports_GL_ARB_shadow() && (lighting->shadowedLightArray.size() > 0)) {
        // We're not going to be able to draw shadows, so move the shadowed lights into
        // the unshadowed category.
        lighting->lightArray.append(lighting->shadowedLightArray);
        lighting->shadowedLightArray.clear();
    }

    // Pose all
    Array<PosedModel2DRef> posed2D;
    Array<PosedModelRef> posedModels, opaqueAModel, otherOpaque, transparent;

    for (int e = 0; e < app->entityArray.size(); ++e) {
        static RealTime t0 = System::time();
        RealTime t = (System::time() - t0) * 10;
        app->entityArray[e]->pose.cframe.set("Top", 
            CoordinateFrame(Matrix3::fromAxisAngle(Vector3::unitY(), t),
                            Vector3::zero()));

        app->entityArray[e]->pose.cframe.set("Clouds", 
            CoordinateFrame(Matrix3::fromAxisAngle(Vector3::unitY(), t/1000),
                            Vector3::zero()));

        app->entityArray[e]->model->pose(posedModels, app->entityArray[e]->cframe, app->entityArray[e]->pose);
    }

    // Get any GModule models
    getPosedModel(posedModels, posed2D);

    if (GLCaps::supports_GL_ARB_shadow() && (lighting->shadowedLightArray.size() > 0)) {     
        // Generate shadow map
        generateShadowMap(lighting->shadowedLightArray[0], posedModels);
    }

    // Separate and sort the models
    ArticulatedModel::extractOpaquePosedAModels(posedModels, opaqueAModel);
    PosedModel::sort(opaqueAModel, app->debugCamera.getCoordinateFrame().lookVector(), opaqueAModel);
    PosedModel::sort(posedModels, app->debugCamera.getCoordinateFrame().lookVector(), otherOpaque, transparent);

    /////////////////////////////////////////////////////////////////////

    if (debugShadows) {
        return;
    }

    rd->setProjectionAndCameraMatrix(app->debugCamera);
    rd->setObjectToWorldMatrix(CoordinateFrame());

    app->debugPrintf("%d opt opaque, %d opaque, %d transparent\n", opaqueAModel.size(), otherOpaque.size(), transparent.size());

    toneMap.beginFrame(rd);

    // Cyan background
    rd->setColorClearValue(Color3(.1f, .5f, 1));

    rd->clear(app->sky.notNull(), true, true);
    if (app->sky.notNull()) {
        app->sky->render(skyParameters);
    }

    // Opaque unshadowed
    ArticulatedModel::renderNonShadowed(opaqueAModel, rd, lighting);
    for (int m = 0; m < otherOpaque.size(); ++m) {
        otherOpaque[m]->renderNonShadowed(rd, lighting);
    }

    // Opaque shadowed
    if (lighting->shadowedLightArray.size() > 0) {
        ArticulatedModel::renderShadowMappedLightPass(opaqueAModel, rd, lighting->shadowedLightArray[0], lightMVP, shadowMap);
        for (int m = 0; m < otherOpaque.size(); ++m) {
            otherOpaque[m]->renderShadowMappedLightPass(rd, lighting->shadowedLightArray[0], lightMVP, shadowMap);
        }
    }

    // Transparent
    for (int m = 0; m < transparent.size(); ++m) {
        transparent[m]->renderNonShadowed(rd, lighting);
        if (lighting->shadowedLightArray.size() > 0) {
            transparent[m]->renderShadowMappedLightPass(rd, lighting->shadowedLightArray[0], lightMVP, shadowMap);
        }
    }

    if (app->sky.notNull()) {
        app->sky->renderLensFlare(skyParameters);
    }

    toneMap.endFrame(rd);

    app->debugPrintf("Tone Map %s\n", toneMap.enabled() ? "On" : "Off");
    app->debugPrintf("%s Profile %s\n", toString(ArticulatedModel::profile()),
        #ifdef _DEBUG
                "(DEBUG mode)"
        #else
                ""
        #endif
        );

    if (beginsWith(GLCaps::vendor(), "ATI")) {
        app->debugPrintf("\nWARNING: Demo is flakey on ATI cards.");
    } else {
        rd->push2D();
        rd->setTexture(0, logo);
        rd->setBlendFunc(RenderDevice::BLEND_SRC_ALPHA, RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA);
        Draw::rect2D(
            Rect2D::xywh(rd->getWidth() - 96,rd->getHeight() - 96, 64, 64), 
            rd, Color4(1,1,1,0.7f));
        rd->pop2D();
    }

    app->debugPrintf("\n");
    app->debugPrintf("TAB to control camera\n");
    app->debugPrintf("SPACE to toggle ToneMap\n");
    app->debugPrintf("ESC to quit\n");

    app->debugPrintf("%s\n", System::mallocPerformance().c_str());
    app->debugPrintf("%s\n", System::mallocStatus().c_str());

}


void App::main() {
	setDebugMode(true);
	debugController.setActive(false);

    loadScene();

    Demo(this).run();
}


App::App(const GAppSettings& settings) : GApp(settings) {
    ::app = this;
    debugShowRenderingStats = true;

    window()->setCaption("ArticulatedModel & SuperShader Demo");

    sky = Sky::create(renderDevice, dataDir + "sky/");//"D:/games/data/sky/", "majestic/majestic512_*.jpg");
}


int main(int argc, char** argv) {
    GAppSettings settings;
    settings.window.depthBits = 16;
    settings.window.stencilBits = 8;
    settings.window.alphaBits = 0;
    settings.window.rgbBits = 8;
    settings.window.fsaaSamples = 1;
    settings.window.width = 800;
    settings.window.height = 600;
    settings.window.fullScreen = false;
	settings.useNetwork = false;
    App(settings).run();
    return 0;
}
