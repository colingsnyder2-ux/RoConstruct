// Renderer integration diagnostic. Replaced by the actual castle entry once the
// browser renderer works; this does not satisfy the castle delivery milestone.
#include "Ogre.h"
#include "OgreGLPlugin.h"
#include <emscripten/emscripten.h>
#include <cstdio>

Ogre::Root* root;
Ogre::RenderWindow* window;
namespace Ogre { void registerBrowserImageCodecs(); }

void frame(void*)
{
    window->Ogre::RenderTarget::update();
}

int main()
{
    try {
        root = new Ogre::Root("", "", "browser.log");
        Ogre::registerBrowserImageCodecs();
        root->installPlugin(new Ogre::GLPlugin);
        root->setRenderSystem(root->getAvailableRenderers()->at(0));
        window = root->initialise(true, "Castle browser renderer diagnostic");
        Ogre::SceneManager* scene = root->createSceneManager(Ogre::ST_GENERIC);
        Ogre::Camera* camera = scene->createCamera("DiagnosticCamera");
        camera->setPosition(0, 2, 8);
        camera->lookAt(0, 0, 0);
        camera->setNearClipDistance(0.1f);
        camera->setAspectRatio(960.0f / 640.0f);
        window->addViewport(camera)->setBackgroundColour(Ogre::ColourValue(0.06f, 0.15f, 0.25f));
        Ogre::ResourceGroupManager::getSingleton().addResourceLocation("assets", "FileSystem", "General");
        Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create("Browser diagnostic", "General");
        material->setAmbient(0.3f, 0.8f, 0.3f);
        material->setDiffuse(0.3f, 0.8f, 0.3f, 1);
        material->getTechnique(0)->getPass(0)->createTextureUnitState("moon.jpg");
        Ogre::Entity* cube = scene->createEntity("Diagnostic cube", Ogre::SceneManager::PT_CUBE);
        cube->setMaterialName(material->getName());
        Ogre::SceneNode* node = scene->getRootSceneNode()->createChildSceneNode();
        node->setScale(0.025f, 0.025f, 0.025f);
        node->attachObject(cube);
        scene->setAmbientLight(Ogre::ColourValue(0.25f, 0.25f, 0.25f));
        Ogre::Light* light = scene->createLight("Diagnostic sun");
        light->setType(Ogre::Light::LT_DIRECTIONAL);
        light->setDirection(-1, -1, -1);
        std::puts("Browser Ogre renderer initialized");
        emscripten_set_main_loop_arg(frame, 0, 0, true);
    } catch (const Ogre::Exception& error) {
        std::fprintf(stderr, "Ogre bootstrap failed: %s\n", error.getFullDescription().c_str());
        return 1;
    }
}
