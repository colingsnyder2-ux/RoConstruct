// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5-dll roc_espclaude_66d95e9814d0fd44.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
#include <d3d9.h>
#include <stdexcept>
#include <stdio.h>

namespace Ogre {
class RbxSceneManager : public SceneManager {
public:
    RbxSceneManager(const String& name);
    ~RbxSceneManager();
    const String& getTypeName(void) const;
};
class RbxSceneManagerFactory : public SceneManagerFactory {
protected:
    void initMetaData(void) const;
public:
    RbxSceneManagerFactory() {}
    ~RbxSceneManagerFactory() {}
    SceneManager* createInstance(const String& instanceName);
    void destroyInstance(SceneManager* instance);
};
class Listener {
    char data[0x58];
public:
    Listener();
    void configure(SceneManager* scene, RenderWindow* window, int priority, bool first, bool second);
};
}

using namespace Ogre;

extern Root* root;
void cleanupRoot();
unsigned int getVideoMemory();

class RbxOgreView {
public:
    void* unknown0;
    RbxSceneManager* sceneManager;
    Camera* camera;
    RenderWindow* window;
    Viewport* viewport;
    Listener* listener;
    char unknown18[0x7f0 - 0x18];
    unsigned int vidMemSize;
    bool useLargeVertexBuffer;
    bool useLargeIndexBuffer;
    int vertexBufferMode;
    int zbufferBits;
    int antialiasing;
    bool softwareVertexProcessing;
    bool textureSquareOnly;
    bool supportDepthBias;
    void initialize(int api, HWND hwnd, int width, int height, int antialiasMode, std::string logFile);
};

static __forceinline bool has32BitMode(ConfigOptionMap& options)
{
    ConfigOptionMap::iterator it = options.find("Video Mode");
    if (it == options.end())
        return false;
    ConfigOption& option = it->second;
    for (int i = 0; i < (int)option.possibleValues.size(); ++i)
        if (StringUtil::match(option.possibleValues[i], "*32-bit*", false))
            return true;
    return false;
}

void RbxOgreView::initialize(int api, HWND hwnd, int width, int height, int antialiasMode, std::string logFile)
{
    try {
        if (!root) {
            root = new Root("", "", logFile);
            static RbxSceneManagerFactory factory;
            root->addSceneManagerFactory(&factory);
            ResourceGroupManager::getSingleton().initialiseResourceGroup("General");
            ResourceGroupManager::getSingleton().addResourceLocation(".", "FileSystem", "General");
            if (api == 0) {
                try {
                    root->loadPlugin("rgdx.dll");
                } catch (std::exception& e) {
                    LogManager::getSingleton().logMessage("Error loading DX9 render system.\n");
                    cleanupRoot();
                    throw std::runtime_error(std::string("Cannot initialize graphics; installation error likely. Error: ") + e.what());
                }
            } else if (api == 1) {
                try {
                    root->loadPlugin("rggl.dll");
                } catch (...) {
                    LogManager::getSingleton().logMessage("Error loading OGL render system.\n");
                    cleanupRoot();
                    throw std::runtime_error("Cannot initialize graphics; installation error likely.");
                }
            }
            try {
                root->loadPlugin("rgpar.dll");
            } catch (...) {
                LogManager::getSingleton().logMessage("Error loading particle system.\n");
                cleanupRoot();
                throw std::runtime_error("Cannot initialize gfx component; installation error likely.");
            }
            RenderSystemList* renderers = root->getAvailableRenderers();
            root->setRenderSystem(*renderers->begin());
            ConfigOptionMap& config = Root::getSingleton().getRenderSystem()->getConfigOptions();
            ConfigOptionMap::iterator fp = config.find("Floating-point mode");
            if (fp != config.end() && fp->second.currentValue != "Consistent") {
                fp->second.currentValue = "Consistent";
                LogManager::getSingleton().logMessage("NOTE forcing Floating-point mode to be Consistent");
            }
            root->initialise(false);
        }

        vidMemSize = getVideoMemory();
        ConfigOptionMap& options = Root::getSingleton().getRenderSystem()->getConfigOptions();

        static int windowCount = 0;
        char name[8];
        _snprintf(name, 8, "win%d", windowCount++);

        NameValuePairList params;
        params["externalWindowHandle"] = StringConverter::toString((unsigned long)hwnd);

        bool found = false;
        ConfigOptionMap::iterator vm = options.find("Video Mode");
        if (vm != options.end()) {
            ConfigOption& option = vm->second;
            for (int i = 0; i < (int)option.possibleValues.size(); ++i)
                if (StringUtil::match(option.possibleValues[i], "*32-bit*", false)) {
                    found = true;
                    break;
                }
        }
        if (!found) {
            params["colourDepth"] = 16;
            LogManager::getSingleton().logMessage("RBX warning 16-bit color");
        }

        if (antialiasMode == 0 || antialiasMode == 1) {
            ConfigOptionMap::iterator aa = options.find("Anti aliasing");
            int best = -1;
            if (aa != options.end()) {
                StringVector& values = aa->second.possibleValues;
                for (int i = 0; i < (int)values.size(); ++i) {
                    if (values[i] == "NonMaskable 1") {
                        if (best < 1) best = 1;
                    } else if (values[i] == "NonMaskable 2") {
                        if (best < 2) best = 2;
                    } else if (values[i] == "NonMaskable 3") {
                        if (best < 3) best = 3;
                    } else if (values[i] == "NonMaskable 4") {
                        if (best < 4) best = 4;
                    }
                }
            }
            if (best >= 4) {
                params["FSAA"] = "1";
                params["FSAAQuality"] = "0";
                LogManager::getSingleton().logMessage("RBX antiliasing is on\n");
                antialiasing = 1;
            } else {
                LogManager::getSingleton().logMessage("RBX antiliasing is off\n");
                antialiasing = 2;
            }
        } else if (antialiasMode == 2) {
            antialiasing = 2;
        }

        try {
            window = root->createRenderWindow(name, width, height, false, &params);
        } catch (...) {
            LogManager::getSingleton().logMessage("Error createRenderWindow.\n");
            throw std::runtime_error("Cannot open window.");
        }

        if (api == 0) {
            try {
                IDirect3DSurface9* surface;
                window->getCustomAttribute("D3DZBUFFER", &surface);
                D3DSURFACE_DESC desc;
                if (SUCCEEDED(surface->GetDesc(&desc))) {
                    switch (desc.Format) {
                    case D3DFMT_D16_LOCKABLE:
                    case D3DFMT_D16:
                        zbufferBits = 16;
                        break;
                    case D3DFMT_D15S1:
                        zbufferBits = 15;
                        break;
                    case D3DFMT_D32:
                    case D3DFMT_D32F_LOCKABLE:
                        zbufferBits = 32;
                        break;
                    case D3DFMT_D24S8:
                    case D3DFMT_D24X8:
                    case D3DFMT_D24X4S4:
                    case D3DFMT_D24FS8:
                        zbufferBits = 24;
                        break;
                    default:
                        zbufferBits = 32;
                        LogManager::getSingleton().logMessage("RBX unknown zbuffer format");
                        break;
                    }
                } else {
                    zbufferBits = 24;
                }
            } catch (...) {
                zbufferBits = 24;
            }
        } else {
            zbufferBits = -1;
        }
        LogManager::getSingleton().logMessage("RBX zbuffer bits " + StringConverter::toString(zbufferBits));

        unsigned int maxVertexIndex = (unsigned int)-1;
        softwareVertexProcessing = false;
        textureSquareOnly = false;
        supportDepthBias = true;
        if (api == 0) {
            try {
                IDirect3DDevice9* device;
                window->getCustomAttribute("D3DDEVICE", &device);
                D3DCAPS9 caps;
                device->GetDeviceCaps(&caps);
                maxVertexIndex = caps.MaxVertexIndex;
                LogManager::getSingleton().logMessage("RBX maxVertexIndex=" + StringConverter::toString(maxVertexIndex));
                softwareVertexProcessing = device->GetSoftwareVertexProcessing() != 0;
                LogManager::getSingleton().logMessage("RBX softwareVertexProcessing=" + StringConverter::toString(softwareVertexProcessing));
                bool& squareOnly = textureSquareOnly;
                squareOnly = ((BYTE)caps.TextureCaps & D3DPTEXTURECAPS_SQUAREONLY) != 0;
                LogManager::getSingleton().logMessage("RBX textureSquareOnly=" + StringConverter::toString(textureSquareOnly));
                bool& depthBias = supportDepthBias;
                depthBias = (caps.RasterCaps & D3DPRASTERCAPS_DEPTHBIAS) != 0;
                LogManager::getSingleton().logMessage("RBX supportDepthBias=" + StringConverter::toString(supportDepthBias));
            } catch (...) {
            }
        }

        ConfigOptionMap::const_iterator rd = options.find("Rendering Device");
        String deviceName;
        if (rd != options.end())
            deviceName = rd->second.currentValue;
        else
            deviceName = "Unknown";
        LogManager::getSingleton().logMessage("RBX device=" + deviceName);
        LogManager::getSingleton().logMessage("RBX vidMemSize=" + StringConverter::toString(vidMemSize));

        bool smallBuffers = maxVertexIndex < 0x10000
            || StringUtil::match(deviceName, "*Intel*", false)
            || StringUtil::match(deviceName, "*GeForce*MX*", false)
            || vidMemSize / (1024 * 1024) < 32;
        if (smallBuffers) {
            LogManager::getSingleton().logMessage("RBX useLargeVertexBuffer=false");
            useLargeIndexBuffer = false;
            useLargeVertexBuffer = false;
        } else {
            LogManager::getSingleton().logMessage("RBX useLargeVertexBuffer=true");
            useLargeIndexBuffer = true;
            useLargeVertexBuffer = true;
        }
        if (vertexBufferMode == 0) {
            useLargeIndexBuffer = false;
            useLargeVertexBuffer = false;
        } else if (vertexBufferMode == 1) {
            useLargeIndexBuffer = true;
            useLargeVertexBuffer = true;
        }

        if (StringUtil::match(deviceName, "*Savage*") && !textureSquareOnly) {
            LogManager::getSingleton().logMessage("RBX Savage lies");
            textureSquareOnly = true;
        }

        static int sceneCount = 0;
        String sceneName = String("sm") + StringConverter::toString(sceneCount++);
        sceneManager = dynamic_cast<RbxSceneManager*>(root->createSceneManager("RbxSceneManager", sceneName));
        camera = sceneManager->createCamera("Camera");
        camera->setAutoAspectRatio(true);
        camera->setNearClipDistance(5.0f);
        viewport = window->addViewport(camera);
        viewport->setBackgroundColour(ColourValue(0, 0, 0));
        camera->setAspectRatio(Real(width) / height);
        ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
        if (vidMemSize > 0)
            TextureManager::getSingleton().setMemoryBudget(vidMemSize);
        listener = new Listener();
        listener->configure(sceneManager, window, 100, true, false);
    } catch (Ogre::Exception& e) {
        throw std::runtime_error(e.getDescription().c_str());
    }
}
