/**
  @file demos/main.cpp

  This is a sample main.cpp to get you started with G3D.  It is
  designed to make writing an application easy.  Although the
  GApp/GApplet infrastructure is helpful for most projects,
  you are not restricted to using it-- choose the level of
  support that is best for your project (see the G3D Map in the
  documentation).

  @author Morgan McGuire, matrix@graphics3d.com
 */

#include <G3DAll.h>

#if G3D_VER <= 60400
    #error Requires G3D 6.04
#endif

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
private:

    // Add state that should be visible to this applet.
    // If you have multiple applets that need to share
    // state, put it in the App.

    class App*          app;

    GMaterial           letterMaterial;
    GMaterial           numberMaterial;
    GMaterial           gearMaterial;

    IFSModelRef         MG;
    IFSModelRef         M3;
    IFSModelRef         MD;
    IFSModelRef         Mgear;

    ShaderRef           outlineShader;
    ShaderRef           cartoonShader;
    ShaderRef           generateShader;

    /** Texture that is black where the logo is and has the depth in the G channel */
    TextureRef          silhouette;

    CoordinateFrame     cframe;

    /** Generates outline (in R channel) and depth (in G channel) texture */
    void generateSilhouette();

public:

    Demo(App* app);    

    virtual void init();

    virtual void doLogic();

	virtual void doNetwork();

    virtual void doSimulation(SimTime dt);

    virtual void doGraphics();

    virtual void cleanup();

};


Demo::Demo(App* _app) : GApplet(_app), app(_app) {
    Vector3 scale(1,0.8,1);

    MG    = IFSModel::create("G.ifs", scale,       CoordinateFrame(Vector3(-1.3, 1.0, 0.0)));
    M3    = IFSModel::create("3.ifs", scale * 1.4, CoordinateFrame(Vector3(-0.1, 0.7, 0.1)));
    MD    = IFSModel::create("D.ifs", scale,       CoordinateFrame(Vector3( 1.3, 1.0, 0.0)));

    Matrix3 R = Matrix3::fromAxisAngle(Vector3::UNIT_X, -G3D_HALF_PI);
    Mgear = IFSModel::create("halfgear.ifs", Vector3(2, 2, 2), CoordinateFrame(R, Vector3(0,-1,0)));


    letterMaterial.color = Color3::fromARGB(0xFFFFDD6F);
    letterMaterial.specularCoefficient = 0.5;

    numberMaterial.color = Color3::fromARGB(0xFF019FF8);
    numberMaterial.specularCoefficient = 0.7;

    gearMaterial.color = Color3::fromARGB(0xFFFF9620);
    gearMaterial.specularCoefficient = 0;

    silhouette = Texture::createEmpty(app->window()->width(), app->window()->height(), "Silhouette", 
        TextureFormat::RGBA8, Texture::CLAMP, 
        Texture::BILINEAR_NO_MIPMAP, Texture::DIM_2D_RECT);

    cframe.lookAt(Vector3(0.5,-2.5,-2));
    cframe.rotation = cframe.rotation * Matrix3::fromAxisAngle(Vector3::unitZ(), toRadians(-10));

    std::string sp =
        "uniform sampler2DRect silhouette;\n"
        "void main(void) {\n"
        "   float sum = 81.0;\n"
        "   int s = 4;                     \n"
        "   for (int x = -s; x <= s; ++x) {\n" 
        "     for (int y = -s; y <= s; ++y) {\n"
        "        sum -= texture2DRect(silhouette, vec2(x, y) + gl_FragCoord.xy).r;\n"
        "     }\n"
        "   }\n"
        "   float c = 1.0 - sum;\n"
        "   gl_FragColor.rgb = vec3(c, c, c);\n"
        "}\n";

    outlineShader = Shader::fromStrings("", sp);

    generateShader = Shader::fromStrings("",
        "void main(void) {\n"
        "   gl_FragColor.r = gl_Color;\n"
        "   gl_FragColor.g = gl_FragCoord.z;\n"
        "   gl_FragColor.b = 0.0;\n"
        "}\n");

    cartoonShader = Shader::fromFiles("toon.vrt", "toon.frg");
}


void Demo::generateSilhouette() {
    app->renderDevice->setColorClearValue(Color3::white());
    app->renderDevice->clear(true, true, true);

    PosedModelRef posed;
    
    app->renderDevice->setShader(generateShader);
    app->renderDevice->setColor(Color3::black());
    posed = MG->pose(cframe);
    posed->render(app->renderDevice);

    posed = M3->pose(cframe);
    posed->render(app->renderDevice);

    posed = MD->pose(cframe);
    posed->render(app->renderDevice);

    posed = Mgear->pose(cframe);
    posed->render(app->renderDevice);
    app->renderDevice->setShader(NULL);

    silhouette->copyFromScreen(Rect2D::xywh(0,0,app->window()->width(), app->window()->height()));
}


void Demo::init()  {
    // Called before Demo::run() beings
    app->debugCamera.setPosition(Vector3(0, 0, 5.5));
    app->debugCamera.lookAt(Vector3(0, 0, 0));
}


void Demo::cleanup() {
    // Called when Demo::run() exits
}


void Demo::doNetwork() {
	// Poll net messages here
}


void Demo::doSimulation(SimTime dt) {
	// Add physical simulation here
}


void Demo::doLogic() {
    if (app->userInput->keyPressed(SDLK_ESCAPE)) {
        // Even when we aren't in debug mode, quit on escape.
        endApplet = true;
        app->endProgram = true;
    }

	// Add other key handling here
}


void Demo::doGraphics() {

    LightingParameters lighting(G3D::toSeconds(11, 00, 00, AM));
    app->renderDevice->setProjectionAndCameraMatrix(app->debugCamera);


    generateSilhouette();

    app->renderDevice->setColorClearValue(Color3::white());
    app->renderDevice->clear(false, true, true);


    // Draw outline
    app->renderDevice->push2D();
        outlineShader->args.set("silhouette", silhouette);
        app->renderDevice->setShader(outlineShader);
        Draw::rect2D(Rect2D::xywh(0,0,app->window()->width(), app->window()->height()), app->renderDevice);
    app->renderDevice->pop2D();

    /*if (! app->sky.isNull()) {
        app->sky->render(lighting);
    }
    */

    // Setup lighting
    app->renderDevice->enableLighting();
    // Colors are ignored
        lighting.lightColor=Color3(.6,1,.7);
        lighting.ambient = Color3::white() - lighting.lightColor;
		app->renderDevice->setLight(0, GLight::directional(lighting.lightDirection, lighting.lightColor));
		app->renderDevice->setAmbientLightColor(lighting.ambient);

        CoordinateFrame cframe;
        cframe.lookAt(Vector3(0.5,-2.5,-2));
        cframe.rotation = cframe.rotation * Matrix3::fromAxisAngle(Vector3::unitZ(), toRadians(-10));

        PosedModelRef posed;
        
        cartoonShader->args.set("depth", silhouette);
        cartoonShader->args.set("bright", Color3::fromARGB(0xFFFFDD6F));
        cartoonShader->args.set("dim", Color3::fromARGB(0xFFA67D2B));
        app->renderDevice->setShader(cartoonShader);

        posed = MG->pose(cframe, letterMaterial);
        posed->render(app->renderDevice);

        posed = MD->pose(cframe, letterMaterial);
        posed->render(app->renderDevice);

        cartoonShader->args.set("bright", Color3::fromARGB(0xFF049FF9));
        cartoonShader->args.set("dim", Color3::fromARGB(0xFF026CA8));

        posed = M3->pose(cframe, numberMaterial);
        posed->render(app->renderDevice);

        app->renderDevice->setShader(NULL);

        // Gear
        lighting.lightColor=Color3::white() * 0.70;
        lighting.ambient = Color3::white() * 0.40;
		app->renderDevice->setLight(0, GLight::directional(lighting.lightDirection, lighting.lightColor));
		app->renderDevice->setAmbientLightColor(lighting.ambient);
        posed = Mgear->pose(cframe, gearMaterial, false);
        // Push back so the wireframe can show through
        app->renderDevice->setPolygonOffset(1);
        posed->render(app->renderDevice);
        app->renderDevice->setPolygonOffset(0);

        // Wireframe
        app->renderDevice->pushState();
            app->renderDevice->setLineWidth(2.5);
            app->renderDevice->setBlendFunc(RenderDevice::BLEND_SRC_ALPHA, RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA);
            app->renderDevice->setColor(Color3::black());
            app->renderDevice->setSpecularCoefficient(0);
            app->renderDevice->setRenderMode(RenderDevice::RENDER_WIREFRAME);

            posed = Mgear->pose(cframe, false);
            posed->render(app->renderDevice);
        app->renderDevice->popState();

    app->renderDevice->disableLighting();

}


void App::main() {
	setDebugMode(false);
	debugController.setActive(false);
    debugCamera.setFarPlaneZ(-15);
    debugCamera.setNearPlaneZ(-1);
    debugCamera.setFieldOfView(toRadians(40));

    // Load objects here
//    sky = Sky::create(renderDevice, dataDir + "sky/");
    
    Demo(this).run();
}


App::App(const GAppSettings& settings) : GApp(settings) {
}


int main(int argc, char** argv) {
    GAppSettings settings;
    settings.window.width = 1024;
    settings.window.height = 768;
    settings.window.fsaaSamples = 8;
    App(settings).run();
    return 0;
}
