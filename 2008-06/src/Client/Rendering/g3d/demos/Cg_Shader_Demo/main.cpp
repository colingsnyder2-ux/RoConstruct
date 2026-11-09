/**
  @file Cg_Shader_Demo/main.cpp

  This demo shows how to use NVIDIA's Cg shading language
  with VertexProgram and PixelProgram.  The Visual Studio
  workspace has been configured to compile the *.cg files
  to OpenGL assembly.

  Consider using the newer G3D::Shader interface that allows
  you to write shaders in GLSL instead of Cg, eliminating
  the compilation step.

  The effect shown is an implementation of parallax
  bump mapping with per-pixel shading and normal maps.

  @author Morgan McGuire, matrix@graphics3d.com
  @created 2004-02-04
  @edited  2004-09-16
 */

#include <G3DAll.h>
#ifdef G3D_WIN32
    #include <direct.h>
    #define _chdir chdir
#else
    #include <unistd.h>
#endif
#include "Mesh.h"

class App : public GApp {
protected:
    void main();
public:
    SkyRef              sky;

    App(const GAppSettings& settings);
};


/**
 This simple demo applet uses the debug mode as the regular
 rendering mode so you can fly around the scene.
 */
class Demo : public GApplet {
public:

    // Add state that should be visible to this applet.
    // If you have multiple applets that need to share
    // state, put it in the App.

    class App*              app;

    Demo(App* app);
    virtual ~Demo(){}

    Mesh                    model;

    TextureRef              texture;

    /**
     Tangent space normal map with the bump map in 
     the alpha channel.
     */
    TextureRef              normalMap;

    PixelProgramRef         parallaxPP;
    VertexProgramRef        parallaxVP;

    virtual void onInit();

    virtual void onUserInput(UserInput*);

    virtual void onGraphics(RenderDevice*);
};



Demo::Demo(App* _app) : GApplet(_app), app(_app) {

    if (! fileExists("texture.jpg")) {
        // Go into the right directory
        chdir("Cg_Shader_Demo");
    }

    texture = Texture::fromFile("texture.jpg");

    CImage bump("bump.jpg");
    CImage normal;

    computeNormalMap(bump, normal);

    normalMap = Texture::fromGImage("Normal Map", normal);

    parallaxPP = PixelProgram::fromFile("parallaxPP.pp");
    parallaxVP = VertexProgram::fromFile("parallaxVP.vp");
}


void Demo::onInit()  {
    // Called before Demo::run() beings
    app->debugCamera.setPosition(Vector3(0, 4, 3));
    app->debugCamera.lookAt(Vector3(0, 1, 0));
}

void Demo::onUserInput(UserInput* ui) {
    if (ui->keyPressed(SDLK_ESCAPE)) {
        // Even when we aren't in debug mode, quit on escape.
        endApplet = true;
        app->endProgram = true;
    }

	// Add other key handling here
}


void Demo::onGraphics(RenderDevice* rd) {

    LightingParameters lighting(G3D::toSeconds(2, 00, 00, AM), false);
    rd->setProjectionAndCameraMatrix(app->debugCamera);

    // Cyan background
    rd->setColorClearValue(Color3(0.1f, 0.5f, 1.0f));

    rd->clear(app->sky.isNull(), true, true);
    if (app->sky.notNull()) {
        app->sky->render(lighting);
    }

    // Create a light 
    Vector4 wsLight(1.0f, 2.5f, 2.0f, 1.0f);
//    Vector4 wsLight(0,1,0,0);

    // Setup lighting
    rd->enableLighting();
		rd->setLight(0, GLight::directional(lighting.lightDirection, lighting.lightColor));
		rd->setAmbientLightColor(lighting.ambient);

        CoordinateFrame cframe;
        // Rotate the quad
        cframe.rotation = Matrix3::fromAxisAngle(Vector3::unitY(), System::getTick() * .1);

        rd->pushState();
            GPUProgram::ArgList vertexArgs;

            rd->setObjectToWorldMatrix(cframe);

            // Take the light to object space
            Vector4 osLight = cframe.toObjectSpace(wsLight);

            // Take the viewer to object space
            Vector3 osEye = cframe.pointToObjectSpace(app->debugCamera.getCoordinateFrame().translation);

            vertexArgs.set("MVP", rd->getModelViewProjectionMatrix());
            vertexArgs.set("osLight", osLight);
            vertexArgs.set("osEye", osEye);
            rd->setVertexProgram(parallaxVP, vertexArgs);

            GPUProgram::ArgList pixelArgs;
            pixelArgs.set("texture", texture);
            pixelArgs.set("normalMap", normalMap);
            rd->setPixelProgram(parallaxPP, pixelArgs);

            model.render(rd);
        rd->popState();


    rd->disableLighting();

    Draw::sphere(Sphere(wsLight.xyz(), .1f), rd, Color3::white(), Color4::clear());

    if (app->sky.notNull()) {
        app->sky->renderLensFlare(lighting);
    }

    rd->push2D();
        app->debugFont->draw2D("The surface is a single quad textured with parallax bump mapping and per-pixel shading.", Vector2(10, 10), 10, Color3::white(), Color3::black());
        app->debugFont->draw2D("Press TAB to toggle to first person camera controls.", Vector2(10, 30), 10, Color3::white(), Color3::black());
    rd->pop2D();
}


void App::main() {
	setDebugMode(true);
	debugController.setActive(false);

    // Load objects here
    sky = Sky::create(renderDevice, dataDir + "sky/");
    debugShowRenderingStats = false;

    Demo(this).run();
}


App::App(const GAppSettings& settings) : GApp(settings) {
    renderDevice->setCaption("Cg Demo");
}


int main(int argc, char** argv) {
    GAppSettings settings;
    settings.window.width = 800;
    settings.window.height = 600;
    App(settings).run();
    return 0;
}
