/**
  @file ASM_Shader_Demo/main.cpp

  This program demonstrates how to use assembly-level shaders with 
  G3D::VertexProgram and G3D::PixelProgram.  This API is provided for 
  backwards compatibility only; consider using high-level shaders
  with G3D::Shader.

  This demo also shows how to intialize G3D without the GApp framework.

  The OpenGL ARB Vertex Program specification is located at
  http://oss.sgi.com/projects/ogl-sample/registry/ARB/vertex_program.txt

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2003-04-10
  @edited  2006-01-29
 */ 

#include <G3DAll.h>
#ifdef _MSC_VER
  #include <direct.h>
#endif

class Model {

    VAR         varVertex;
    VAR         varNormal;

    Array<uint32>   index;
    Array<Vector3>  vertex;
    Array<Vector3>  normal;

public:

    Model(const std::string& filename);
    virtual ~Model() {}
    void render(const CoordinateFrame& c, 
                const LightingParameters& lighting) const;
};

class App : public GApp {
protected:
    void main();
public:

    GApplet* applet;

    App(const GAppSettings& settings);

    ~App() {
        delete applet;
    }
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
    SkyRef                  sky;

    Model*                  model;
    GameTime                gameTime;

    VertexProgramRef        distort;

    Demo(App* app);

    virtual ~Demo() {}

    virtual void onInit();

    virtual void onLogic();

    virtual void onSimulation(RealTime rdt, SimTime sdt, SimTime idt);

    virtual void onGraphics(RenderDevice*);

};


static App* globalApp = NULL;


Demo::Demo(App* _app) : GApplet(_app), app(_app) {
}


void Demo::onInit() {
    
    model        = new Model(app->dataDir + "ifs/cow.ifs");

    app->debugController.setMoveRate(1);

    app->debugController.setPosition(Vector3(2, 0.2f, -2));
    app->debugController.lookAt(Vector3(-2,0,2));
    app->renderDevice->setColorClearValue(Color3(.1f, .5f, 1));

    std::string p = "ASM_Shader_Demo/";
    if (! fileExists(p + "twist.vp")) {
        p = "../" + p;
    }
    distort = VertexProgram::fromFile(p + "twist.vp");

}


void Demo::onSimulation(RealTime rdt, SimTime sdt, SimTime idt) {
    // Simulation
    app->debugController.doSimulation(max(0.1, min(0.0, rdt)));
    app->debugCamera.setCoordinateFrame(app->debugController.getCoordinateFrame());
}


void Demo::onGraphics(RenderDevice* rd) {
    rd->setAmbientLightColor(Color3::white() * .5);
    rd->clear(true, true, true);

    rd->pushState();
        rd->setProjectionAndCameraMatrix(app->debugCamera);
        double angle = cos(System::getTick()) / 2;
        glProgramLocalParameter4fARB(GL_VERTEX_PROGRAM_ARB, 0, cos(angle), 1, sin(angle), 1);

        rd->setVertexProgram(distort);

        // Set depth buffer
        rd->disableColorWrite();
        model->render(CoordinateFrame(), LightingParameters(G3D::toSeconds(11,00,00,AM)));
        rd->enableColorWrite();
    
        // Draw translucent
        rd->setDepthTest(RenderDevice::DEPTH_ALWAYS_PASS);
        rd->disableDepthWrite();
        rd->setBlendFunc(RenderDevice::BLEND_ONE, RenderDevice::BLEND_ONE);
        model->render(CoordinateFrame(), LightingParameters(G3D::toSeconds(11,00,00,AM)));

        // Wireframe
        rd->setBlendFunc(RenderDevice::BLEND_ONE, RenderDevice::BLEND_ZERO);
        rd->setRenderMode(RenderDevice::RENDER_WIREFRAME);
//        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        rd->setPolygonOffset(-.25);
        rd->setColor(Color3::black());
        rd->setDepthTest(RenderDevice::DEPTH_LEQUAL);
        model->render(CoordinateFrame(), LightingParameters(G3D::toSeconds(11,00,00,AM)));
        rd->setRenderMode(RenderDevice::RENDER_SOLID);
//        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    rd->popState();
    
    Draw::axes(rd);
}


void Demo::onLogic() {

    if (app->userInput->keyPressed(SDLK_ESCAPE)) {
        app->endProgram = true;
        endApplet = true;
    }
}


void App::main() {
    
    if (!renderDevice->supportsVertexProgram()) {
        error ("Critical Error", "This demo requires a graphics card and driver with OpenGL Vertex programs.", true);
        endProgram = true;
    }

    renderDevice->setCaption("G3D Vertex Program Demo");

	setDebugMode(true);
	debugController.setActive(true);

    applet = new Demo(this);

    applet->run();
}


App::App(const GAppSettings& settings) : GApp(settings) {
    globalApp = this;
}


Model::Model(const std::string& filename) {
    // file := 
    //    fileheader +
    //    vertexheader +
    //    vertex* +
    //    triheader +
    //    tri*
    //
    //  fileheader   := (string32) "IFS" + (float32)1.0 + (string32)modelname
    //  vertexheader := (string32) "VERTICES" + (uint32)numVertices
    //  vertex       := (float32)x + (float32)y + (float32)z
    //  triheader    := (string32)"TRIANGLES" + (uint32)numFaces
    //  tri          := (uint32)v0 + (uint32)v1 + (uint32)v2

    globalApp->debugLog->println(std::string("Loading ") + filename);

    BinaryInput b(filename, G3D_LITTLE_ENDIAN);

    std::string fmt         = b.readString32();
    float       version     = b.readFloat32();
    (void)version;
    std::string name        = b.readString32();

    debugAssert(fmt     == "IFS");
    debugAssert(version == 1.0);

    std::string vertexHeader = b.readString32();

    // Load the vertices
    vertex.resize(b.readUInt32());

    for (int v = 0; v < vertex.size(); ++v) {
        vertex[v] = b.readVector3() * 5;
    }

    // Per-vertex normals
    normal.resize(vertex.size());

    // Load the triangles
    std::string triHeader   = b.readString32();

    int numTris = b.readUInt32();

    for (int t = 0; t < numTris; ++t) {
        int v0 = b.readUInt32();
        int v1 = b.readUInt32();
        int v2 = b.readUInt32();

        // Compute the non-unit face normal
        Vector3 faceNormal = 
          (vertex[v1] - vertex[v0]).cross( 
           (vertex[v2] - vertex[v0]));

        normal[v0] += faceNormal;
        normal[v1] += faceNormal;
        normal[v2] += faceNormal;

        // Record the indices
        index.append(v0, v1, v2);
    }

    // Rescale the normals to unit length
    for (int n = 0; n < normal.size(); ++n) {
        normal[n] = normal[n].direction();
    }
}


void Model::render(const CoordinateFrame& c,
                   const LightingParameters& lighting) const {


    globalApp->renderDevice->setObjectToWorldMatrix(c);

    globalApp->renderDevice->pushState();

        // Setup lighting
        globalApp->renderDevice->enableLighting();
        globalApp->renderDevice->setLight(0, GLight::directional(lighting.lightDirection, lighting.lightColor));
        globalApp->renderDevice->setLight(1, GLight::directional(-lighting.lightDirection, Color3::white() * .25));

        globalApp->renderDevice->setShadeMode(RenderDevice::SHADE_SMOOTH);
        globalApp->renderDevice->setAmbientLightColor(lighting.ambient);
        globalApp->renderDevice->setColor(Color3::white());

        // Draw the model

        globalApp->renderDevice->beginPrimitive(RenderDevice::TRIANGLES);
        {
            for (int i = 0; i < index.size(); ++i) {
                globalApp->renderDevice->setNormal(normal[index[i]]);
                globalApp->renderDevice->sendVertex(vertex[index[i]]);
            }
        }
        globalApp->renderDevice->endPrimitive();

    globalApp->renderDevice->popState();
}


int main(int argc, char** argv) {

   GAppSettings settings;

   App(settings).run();

    return 0;
}
