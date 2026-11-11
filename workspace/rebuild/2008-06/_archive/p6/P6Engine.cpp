// Hosts the recovered player's engine in a window owned by the MFC client.
// Reuses Player2008.cpp's helpers unchanged; only its console main is unused.
#define main PlayerHarnessMain
#include "../tests/p2-recovered/Player2008.cpp"
#undef main
#include "P6Engine.h"
#include <OgreOverlayManager.h>
#include <OgreOverlayContainer.h>
#include <OgreTextAreaOverlayElement.h>
#include <OgreFontManager.h>
#include <OgreMaterialManager.h>

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
static bool g_running;
static bool g_started;

// Edit camera orbits a focus point; the first frame frames every model.
static float g_yaw = 0.6f, g_pitch = 0.45f, g_distance = 30;
static Ogre::Vector3 g_focus(0, 0, 0);
static bool g_framed;
static Ogre::SceneNode* g_selected;

static void frameModels()
{
    int count = SceneModelCount();
    if (!count) return;
    Ogre::AxisAlignedBox bounds;
    for (int i = 0; i < count; ++i) {
        SceneModel model;
        if (SceneModelGet(i, &model)) continue;
        Ogre::Vector3 center(model.position[0], model.position[1], model.position[2]);
        Ogre::Vector3 half(model.size[0] / 2, model.size[1] / 2, model.size[2] / 2);
        bounds.merge(center - half);
        bounds.merge(center + half);
    }
    g_focus = bounds.getCenter();
    g_distance = std::max(4.0f, bounds.getSize().length() * 1.6f);
    g_framed = true;
}

// In-view strip: the original draws Fonts\\comics.fnt through G3D over a grey bar.
// ponytail: system comic.ttf stands in until comics.fnt is located.
static void createStrip()
{
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation("C:/Windows/Fonts", "FileSystem", "General");
    Ogre::FontPtr font = Ogre::FontManager::getSingleton().create("P6Comic", "General");
    font->setType(Ogre::FT_TRUETYPE);
    font->setSource("comic.ttf");
    font->setTrueTypeSize(13);
    font->setTrueTypeResolution(96);
    font->load();
    Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create("P6Strip", "General");
    Ogre::Pass* pass = material->getTechnique(0)->getPass(0);
    pass->setLightingEnabled(false);
    pass->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);
    pass->setDepthWriteEnabled(false);
    pass->setDiffuse(0.55f, 0.55f, 0.55f, 0.55f);
    pass->setAmbient(0.55f, 0.55f, 0.55f);
    pass->setVertexColourTracking(Ogre::TVC_NONE);
    pass->createTextureUnitState()->setColourOperationEx(Ogre::LBX_SOURCE1, Ogre::LBS_MANUAL, Ogre::LBS_CURRENT, Ogre::ColourValue(0.55f, 0.55f, 0.55f));
    pass->getTextureUnitState(0)->setAlphaOperation(Ogre::LBX_SOURCE1, Ogre::LBS_MANUAL, Ogre::LBS_CURRENT, 0.55f);
    Ogre::OverlayManager& manager = Ogre::OverlayManager::getSingleton();
    Ogre::Overlay* overlay = manager.create("P6Strip");
    Ogre::OverlayContainer* bar = static_cast<Ogre::OverlayContainer*>(manager.createOverlayElement("Panel", "P6StripBar"));
    bar->setMetricsMode(Ogre::GMM_PIXELS);
    bar->setDimensions(500, 20);
    bar->setMaterialName("P6Strip");
    static const char* const items[] = {"Tools", "Insert", "Fullscreen", "Help...", "Exit"};
    for (int i = 0; i < 5; ++i) {
        Ogre::TextAreaOverlayElement* text = static_cast<Ogre::TextAreaOverlayElement*>(manager.createOverlayElement("TextArea", std::string("P6StripText") + items[i]));
        text->setMetricsMode(Ogre::GMM_PIXELS);
        text->setPosition(i * 100.0f + 28, 3);
        text->setDimensions(90, 16);
        text->setFontName("P6Comic");
        text->setCharHeight(15);
        text->setColour(i < 2 ? Ogre::ColourValue(0.3f, 0.3f, 0.3f, 0.6f) : Ogre::ColourValue(0.1f, 0.1f, 0.1f));
        text->setCaption(items[i]);
        bar->addChild(text);
    }
    overlay->add2D(bar);
    overlay->show();
}

static void syncEditCamera()
{
    float pose[13];
    float fov = P6DataCamera(pose) ? 1.2f : pose[12];
    Ogre::Vector3 offset(std::sin(g_yaw) * std::cos(g_pitch), std::sin(g_pitch), std::cos(g_yaw) * std::cos(g_pitch));
    g_camera->setPosition(g_focus + offset * g_distance);
    g_camera->lookAt(g_focus);
    if (g_viewport->getActualWidth() > 0 && g_viewport->getActualHeight() > 0) {
        float aspect = float(g_viewport->getActualWidth()) / float(g_viewport->getActualHeight());
        g_camera->setAspectRatio(aspect);
        g_camera->setFOVy(Ogre::Radian(float(2.0 * atan(tan(fov * .5) / aspect))));
    }
}

static std::string moduleRoot()
{
    char path[MAX_PATH];
    GetModuleFileNameA(0, path, sizeof(path));
    return std::string(path).substr(0, std::string(path).find_last_of("\\/"));
}

// Application-wide setup; the document no longer repeats it per open.
extern "C" int P6EngineStartup(void)
{
    std::string content = moduleRoot() + "/Content";
    if (!getenv("ROC_TEXTURE_STRIP")) _putenv(("ROC_TEXTURE_STRIP=" + content + "/textures/SurfacesStrip.png").c_str());
    if (!getenv("ROC_SKY_SPHERE")) _putenv(("ROC_SKY_SPHERE=" + content + "/sky/skyspheremap.jpg").c_str());
    return ConfigureContentRoot(content.c_str());
}

extern "C" int P6EngineReadable(const char* path)
{
    return !readPlace(path).empty();
}

extern "C" int P6EngineOpen(void* window, const char* path, int width, int height, int play)
{
    if (g_root) return 1;
    std::string content = moduleRoot() + "/Content";
    std::string place = readPlace(path && *path ? path : (moduleRoot() + "/Places/default.rbxl").c_str());
    if (place.empty() || LoadPlace(place.c_str())) return 3;
    g_placeOpen = true;
    g_play = play != 0;
    g_running = false;
    g_started = g_play;
    g_framed = false;
    g_selected = NULL;
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
    createStrip();
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
    if (g_play || g_running) StepEngine(dt);
    if (g_play) {
        if (!SyncPlayerCamera(g_camera, g_viewport)) return 0;
    } else syncEditCamera();
    drawModels();
    if (!g_play && !g_framed) {
        frameModels();
        syncEditCamera();
    }
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
    if (!g_started) StartPlay();
    g_started = g_play = true;
    return 0;
}

// Toolbar 137 Run and Pause: simulate without a character.
extern "C" void P6EngineSetRunning(int running)
{
    if (!g_timer) return;
    if (running && !g_started) StartPlay();
    g_started = g_started || running != 0;
    g_running = running != 0;
}

extern "C" int P6EngineRunning(void)
{
    return g_play || g_running;
}

extern "C" int P6EngineIsOpen(void)
{
    return g_timer != NULL;
}

extern "C" void P6EngineHoldW(int down)
{
    SetPlayerTestKey(down);
}

extern "C" int P6EngineScript(const char* command)
{
    return ExecutePlayerScript(command);
}

extern "C" int P6EngineSave(const char* path)
{
    return P6DataSave(path);
}

extern "C" void P6EngineOrbit(float yaw, float pitch)
{
    g_yaw += yaw;
    g_pitch = std::min(1.5f, std::max(-1.5f, g_pitch + pitch));
}

extern "C" void P6EngineZoom(float factor)
{
    g_distance = std::max(1.0f, g_distance * factor);
}

// Ray against each model's oriented box; x and y are 0..1 over the viewport.
extern "C" void* P6EnginePick(float x, float y)
{
    if (!g_timer) return NULL;
    Ogre::Ray ray = g_camera->getCameraToViewportRay(x, y);
    float nearest = 1e30f;
    SceneModel best;
    best.id = NULL;
    int count = SceneModelCount();
    for (int i = 0; i < count; ++i) {
        SceneModel model;
        if (SceneModelGet(i, &model)) continue;
        Ogre::Matrix3 rotation(model.rotation[0], model.rotation[1], model.rotation[2], model.rotation[3], model.rotation[4],
                               model.rotation[5], model.rotation[6], model.rotation[7], model.rotation[8]);
        Ogre::Matrix3 inverse = rotation.Transpose();
        Ogre::Vector3 center(model.position[0], model.position[1], model.position[2]);
        Ogre::Vector3 origin = inverse * (ray.getOrigin() - center);
        Ogre::Vector3 direction = inverse * ray.getDirection();
        Ogre::Vector3 half(model.size[0] / 2, model.size[1] / 2, model.size[2] / 2);
        std::pair<bool, Ogre::Real> hit = Ogre::Ray(origin, direction).intersects(Ogre::AxisAlignedBox(-half, half));
        if (hit.first && hit.second < nearest) {
            nearest = hit.second;
            best = model;
        }
    }
    if (g_selected) g_selected->showBoundingBox(false);
    g_selected = NULL;
    if (!best.id) return NULL;
    std::map<const void*, DrawEntry>::iterator entry = g_drawn.find(best.id);
    if (entry != g_drawn.end() && entry->second.node) {
        g_selected = entry->second.node;
        g_selected->showBoundingBox(true);
    }
    return P6DataPartAt(best.position[0], best.position[1], best.position[2]);
}

static void* g_drag;
static float g_dragStart[3];
static Ogre::Vector3 g_dragOrigin;

static bool dragPoint(float x, float y, Ogre::Vector3& point)
{
    Ogre::Ray ray = g_camera->getCameraToViewportRay(x, y);
    std::pair<bool, Ogre::Real> hit = ray.intersects(Ogre::Plane(Ogre::Vector3::UNIT_Y, g_dragStart[1]));
    if (!hit.first) return false;
    point = ray.getPoint(hit.second);
    return true;
}

// Drags on the Part's horizontal plane, snapping to whole studs.
extern "C" void* P6EngineDragBegin(float x, float y, float* start)
{
    g_drag = P6EnginePick(x, y);
    if (!g_drag || P6DataGetPosition(g_drag, g_dragStart) || !dragPoint(x, y, g_dragOrigin)) {
        g_drag = NULL;
        return NULL;
    }
    for (int i = 0; i < 3; ++i) start[i] = g_dragStart[i];
    return g_drag;
}

extern "C" int P6EngineDragTo(float x, float y)
{
    Ogre::Vector3 point;
    if (!g_drag || !dragPoint(x, y, point)) return 0;
    Ogre::Vector3 delta = point - g_dragOrigin;
    float position[3] = {g_dragStart[0] + floorf(delta.x + .5f), g_dragStart[1], g_dragStart[2] + floorf(delta.z + .5f)};
    return !P6DataSetPosition(g_drag, position);
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
    g_selected = NULL;
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
