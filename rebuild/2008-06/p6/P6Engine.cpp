// Hosts the recovered player's engine in a window owned by the MFC client.
// Reuses Player2008.cpp's helpers unchanged; only its console main is unused.
#define main PlayerHarnessMain
#include "../tests/p2-recovered/Player2008.cpp"
#undef main
#include "P6Engine.h"

extern "C" int P6DataCamera(float* values);
extern "C" int P6DataSave(const char* path);

static Ogre::Root* g_root;
static Ogre::RenderWindow* g_window;
static Ogre::Camera* g_camera;
static Ogre::Viewport* g_viewport;
static Ogre::Timer* g_timer;
static unsigned long g_last;
static int g_frames;
static bool g_placeOpen;
static bool g_play;

static void syncEditCamera()
{
    float pose[12];
    if (P6DataCamera(pose)) {
        g_camera->setPosition(0, 10, 30);
        g_camera->lookAt(0, 0, 0);
        return;
    }
    g_camera->setPosition(pose[9], pose[10], pose[11]);
    g_camera->setOrientation(Ogre::Quaternion(Ogre::Matrix3(pose[0], pose[1], pose[2], pose[3], pose[4], pose[5], pose[6], pose[7], pose[8])));
}

static std::string moduleRoot()
{
    char path[MAX_PATH];
    GetModuleFileNameA(0, path, sizeof(path));
    return std::string(path).substr(0, std::string(path).find_last_of("\\/"));
}

extern "C" int P6EngineReadable(const char* path)
{
    return !readPlace(path).empty();
}

extern "C" int P6EngineOpen(void* window, const char* path, int width, int height, int play)
{
    if (g_root) return 1;
    std::string content = moduleRoot() + "/Content";
    if (!getenv("ROC_TEXTURE_STRIP")) _putenv(("ROC_TEXTURE_STRIP=" + content + "/textures/SurfacesStrip.png").c_str());
    if (!getenv("ROC_SKY_SPHERE")) _putenv(("ROC_SKY_SPHERE=" + content + "/sky/skyspheremap.jpg").c_str());
    if (ConfigureContentRoot(content.c_str())) return 2;
    std::string place = readPlace(path);
    if (place.empty() || LoadPlace(place.c_str())) return 3;
    g_placeOpen = true;
    g_play = play != 0;
    if (g_play) {
        if (AttachPlayerController(1)) return 4;
        float pose[15];
        if (GetPlayerCameraPose(pose)) return 5;
        StartPlay();
    }

    g_root = new Ogre::Root("", "", "player.log");
    g_root->loadPlugin("rgdx.dll");
    Ogre::RenderSystem* system = NULL;
    Ogre::RenderSystemList* list = g_root->getAvailableRenderers();
    for (size_t i = 0; i < list->size(); ++i)
        if ((*list)[i]->getName().find("Direct3D9") != std::string::npos) system = (*list)[i];
    if (!system) return 6;
    g_root->setRenderSystem(system);
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation(content, "FileSystem", "General");
    system->setConfigOption("Floating-point mode", "Consistent");
    g_root->initialise(false);
    Ogre::NameValuePairList params;
    params["externalWindowHandle"] = Ogre::StringConverter::toString((size_t)window);
    g_window = g_root->createRenderWindow("P6", width > 0 ? width : 320, height > 0 ? height : 240, false, &params);
    Ogre::SceneManager* scene = g_root->createSceneManager(Ogre::ST_GENERIC, "sm");
    scene->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_MODULATIVE);
    scene->setShadowColour(Ogre::ColourValue(0.55f, 0.55f, 0.55f));
    scene->setShadowFarDistance(300.0f);
    g_sceneManager = scene;
    g_camera = scene->createCamera("cam");
    g_camera->setNearClipDistance(0.1f);
    g_viewport = g_window->addViewport(g_camera);
    if (g_play) {
        if (!SyncPlayerCamera(g_camera, g_viewport)) return 7;
    } else syncEditCamera();
    PlayerSkybox::apply(*scene, content);
    if (SceneAttach()) return 8;
    g_timer = new Ogre::Timer;
    g_last = g_timer->getMilliseconds();
    return 0;
}

extern "C" int P6EngineFrame(void)
{
    if (!g_timer) return 0;
    unsigned long now = g_timer->getMilliseconds();
    if (now - g_last < 16) { // ponytail: fixed 60 Hz cap, original deadline loop 00555190 replaces it
        Sleep(1);
        return 1;
    }
    float dt = (now - g_last) / 1000.0f;
    g_last = now;
    if (g_play) {
        StepEngine(dt);
        if (!SyncPlayerCamera(g_camera, g_viewport)) return 0;
    } else syncEditCamera();
    drawModels();
    g_root->renderOneFrame();
    ++g_frames;
    return 1;
}

extern "C" int P6EngineFrames(void)
{
    return g_frames;
}

extern "C" void P6EngineReport(void)
{
    float x = 0, y = 0, z = 0;
    if (g_play) {
        if (g_timer && !GetActorTorsoPosition(&x, &y, &z)) std::printf("p6: actor %g %g %g\n", x, y, z);
    } else if (PartAlive()) {
        GetPartPosition(&x, &y, &z);
        std::printf("p6: part %g %g %g\n", x, y, z);
    }
}

extern "C" int P6EnginePlay(void)
{
    if (!g_timer || g_play) return 1;
    if (AttachPlayerController(1)) return 2;
    float pose[15];
    if (GetPlayerCameraPose(pose)) return 3;
    StartPlay();
    g_play = true;
    return 0;
}

extern "C" int P6EngineIsOpen(void)
{
    return g_timer != NULL;
}

extern "C" int P6EngineScript(const char* command)
{
    return ExecutePlayerScript(command);
}

extern "C" int P6EngineSave(const char* path)
{
    return P6DataSave(path);
}

extern "C" int P6EngineCapture(const char* path)
{
    return g_window && writeBackbuffer(g_window, path);
}

extern "C" void P6EngineResize(void)
{
    if (g_window) g_window->windowMovedOrResized();
}

extern "C" void P6EngineClose(void)
{
    if (g_timer) {
        delete g_timer;
        g_timer = NULL;
        SceneDetach();
        drawModels();
        PlayerBlockMesh::flushUnused();
        std::printf("mesh cleanup: levels=%u refs=%u backends=%u spheres=%u\n", PlayerBlockMesh::liveLevels(), PlayerBlockMesh::activeReferences(), PlayerMeshBackend::liveMeshes(), PlayerSphereCache::size());
    }
    g_window = NULL;
    g_camera = NULL;
    g_viewport = NULL;
    g_sceneManager = NULL;
    delete g_root;
    g_root = NULL;
    if (g_placeOpen) ClosePlace();
    g_placeOpen = false;
}
