/**
 @file VAR_Demo/main.cpp

 Demonstration of begin/end style rendering and VAR (Vertex Arrays) for higher
 performance.  This demo predates the GApp infrastructure; consider
 using it instead of intializing RenderDevice yourself.

 @maintainer Morgan McGuire, matrix@graphics3d.com
 @created 2002-10-22
 @edited  2006-01-29
 */

#include <G3DAll.h>
  
/**
 Number of planes
 */
const int                   N = 50;

/**
 Change this to change the model being rendered.
 */
const std::string modelName = "p51-mustang.ifs";

enum RenderMethod {TRIANGLES = 0, VARSTREAM, VARSTATIC, NUM_RENDER_METHODS} renderMethod;


/**
 See also G3D::IFSModel and G3D::MD2Model.  This demo uses neither
 in order to demonstrate the use of vertex arrays explicitly, 
 but you can save yourself a lot of coding
 by using the built-in classes (which are optimized for dynamic
 var usage).
 */
class Model {
private:
    VAR             varVertex;
    VAR             varNormal;

    Array<uint32>   index;
    Array<Vector3>  vertex;
    Array<Vector3>  normal;

public:

    Model(const std::string&, VARAreaRef);

    virtual ~Model() {}

    void render(RenderDevice*, const CoordinateFrame&,
        const LightingParameters&, VARAreaRef) const;
    
    int numPolys() const {
        return index.size() / 3;
    }
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

    VARAreaRef              varStream;
    VARAreaRef              varStatic;
    Model*                  model;
    GameTime                gameTime;

    Demo(App* app);

    virtual ~Demo() {}

    virtual void onInit();

    virtual void onUserInput(UserInput*);

    virtual void onSimulation(RealTime rdt, SimTime sdt, SimTime idt);

    virtual void onGraphics(RenderDevice*);

    virtual void onCleanup();

};


Demo::Demo(App* _app) : GApplet(_app), app(_app) {
    // Allocate the two VARAreas used in this demo
    varStatic = VARArea::create(1024 * 640 * 5, VARArea::WRITE_ONCE);
    varStream = VARArea::create(1024 * 1280 * 5, VARArea::WRITE_EVERY_FRAME);
    debugAssertGLOk();    
    debugAssert(varStatic.notNull());
    debugAssert(varStream.notNull());
}


void Demo::onInit()  {
    // Called before Demo::run() beings
    app->debugCamera.setPosition(Vector3(0, 2, 10));
    app->debugCamera.lookAt(Vector3(0, 2, 0));

    model        = new Model(app->dataDir + "ifs/" + modelName, varStatic);
    gameTime     = G3D::toSeconds(8, 00, 00, AM);
    renderMethod = VARSTATIC;

    sky          = Sky::create(app->renderDevice, app->dataDir + "sky/");

    app->debugController.setPosition(Vector3(-25, 2, 0));
    app->debugController.lookAt(Vector3(-20, 2.5, 1));
}


void Demo::onCleanup() {
    varStatic->reset();

    app->debugLog->printf("Static VAR peak size was  %d bytes.\n",
                     varStatic->peakAllocatedSize());
    app->debugLog->printf("Streaming VAR peak size was %d bytes.\n", 
                     varStream->peakAllocatedSize());

    delete model;
    sky = NULL;
}


void Demo::onSimulation(RealTime rdt, SimTime sdt, SimTime idt) {
	// Add physical simulation here
    gameTime += 20;
}


void Demo::onUserInput(UserInput* ui) {
    if (ui->keyPressed(SDLK_ESCAPE)) {
        // Even when we aren't in debug mode, quit on escape.
        endApplet = true;
        app->endProgram = true;
    }

    if (ui->keyPressed(' ')) {
        renderMethod =
          (RenderMethod)((renderMethod + 1) % NUM_RENDER_METHODS);
    }
}


void Demo::onGraphics(RenderDevice* rd) {

    app->renderDevice->clear(sky == NULL, true, false);
    app->renderDevice->setProjectionAndCameraMatrix(app->debugCamera);
    LightingParameters lighting(gameTime, false);

    if (sky.notNull()) {
       sky->render(lighting);
    }
                    
    app->renderDevice->pushState();
        // Setup lighting
        app->renderDevice->setSpecularCoefficient(1);
        app->renderDevice->setShininess(64);
        debugAssertGLOk();
        app->renderDevice->enableLighting();
        app->renderDevice->setLight(0, GLight::directional(lighting.lightDirection, lighting.lightColor));
        app->renderDevice->setLight(1, GLight::directional(-lighting.lightDirection, Color3::white() * .25, false));
        app->renderDevice->setAmbientLightColor(lighting.ambient);

        app->renderDevice->setShadeMode(RenderDevice::SHADE_SMOOTH);

        static const Color3 color[] = {Color3::black(), Color3::white(), Color3::orange(), Color3::blue()};
        double  t[2];
        Vector3 c[2];

        t[0] = System::getTick();
        t[1] = t[0] + 0.01;

		// Draw the planes
        for (int x = 0; x < N; ++x) {

            for (int i = 0; i < 2; ++i) {
                double a = x + t[i] + 2; 
                double a2 = t[i] * (x + 1) * .01 + 1005.1;
                c[i] = Vector3(cos(a) * (10 + x / 2.0), sin(a2) * 10, sin(a) * 15);
            }

            CoordinateFrame cframe(c[0]);

            double a = t[0] * (x + 1) * .1; 
            cframe.lookAt(c[1], Vector3(cos(a), 3, sin(a)).direction());


            app->renderDevice->setColor(color[x % 4]);
            model->render(app->renderDevice, cframe, lighting, varStream);
        }
    app->renderDevice->popState();


    if (sky.notNull()) {
        sky->renderLensFlare(lighting);
    }
    
    app->renderDevice->push2D();
        char* str = NULL;
        switch (renderMethod) {
        case TRIANGLES:
            str = "Using begin/end (SPACE to change)";
            break;

        case VARSTREAM:
            str = "Using streaming vertex array (SPACE to change)";
            break;

        case VARSTATIC:
            str = "Using static vertex array (SPACE to change)";
            break;

        default:;
        }

       app->debugFont->draw2D(str, Vector2(10, app->renderDevice->getHeight() - 40), 20, Color3::yellow(), Color3::black());

    app->renderDevice->pop2D();

    debugAssertGLOk();    
    varStream->reset();
}


void App::main() {
	setDebugMode(true);
	debugController.setActive(true);

    applet = new Demo(this);

    applet->run();
}


App::App(const GAppSettings& settings) : GApp(settings) {
}


int main(int argc, char** argv) {
    GAppSettings settings;
    settings.useNetwork = false;
    settings.debugFontName = "dominant.fnt";
    settings.window.depthBits = 16;
    settings.window.stencilBits = 0;
    settings.window.alphaBits = 0;
    settings.window.fsaaSamples = 1;
    settings.window.rgbBits = 0;
    
    App(settings).run();
    return 0;
}


Model::Model(const std::string& filename, VARAreaRef varStatic) {
    // This loads an IFS file.  Note that we could have used G3D::IFSModel::load to
    // parse the file for us.

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

    Log::common()->println(std::string("Loading ") + filename);

    BinaryInput b(filename, G3D_LITTLE_ENDIAN);

    std::string fmt         = b.readString32();
    float       version     = b.readFloat32();
    (void) version;
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

    varVertex = VAR(vertex, varStatic);
    varNormal = VAR(normal, varStatic);
    debugAssertGLOk();    
}


void Model::render(    
    RenderDevice*               renderDevice,
    const CoordinateFrame&      c,
    const LightingParameters&   lighting,
    VARAreaRef                  varStream) const {

    renderDevice->setObjectToWorldMatrix(c);

    // Draw the model
    switch (renderMethod) {
    case TRIANGLES:
        renderDevice->beginPrimitive(RenderDevice::TRIANGLES);
        {
            for (int i = 0; i < index.size(); ++i) {
                renderDevice->setNormal(normal[index[i]]);
                renderDevice->sendVertex(vertex[index[i]]);
            }
        }
        renderDevice->endPrimitive();
        break;


    case VARSTREAM:
        renderDevice->beginIndexedPrimitives();

        // This implementation would work fine for a number of *different*
        // models.  We happen to keep uploading the same model every time
        // because it is a test.

        {
            if (varStream->freeSize() < normal.size() * sizeof(Vector3) * 2) {
                // There isn't enough head room left, so reset.
                varStream->reset();
            }
            VAR n(normal, varStream);
            VAR v(vertex, varStream);

            renderDevice->setNormalArray(n);
            renderDevice->setVertexArray(v);
            renderDevice->sendIndices(RenderDevice::TRIANGLES, index);
        }
        renderDevice->endIndexedPrimitives();
        break;


    case VARSTATIC:
        renderDevice->beginIndexedPrimitives();
        {
            renderDevice->setNormalArray(varNormal);
            renderDevice->setVertexArray(varVertex);
            renderDevice->sendIndices(RenderDevice::TRIANGLES, index);
        }
        renderDevice->endIndexedPrimitives();
        break;

    default:;
    }

}

