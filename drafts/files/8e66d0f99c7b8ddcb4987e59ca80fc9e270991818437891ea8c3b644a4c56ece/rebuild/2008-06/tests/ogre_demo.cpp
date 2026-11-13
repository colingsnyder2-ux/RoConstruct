#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
#include "OgreRbx/RbxSceneManager2008.h"
#include <windows.h>
#include <cstdio>

int main(int argc, char** argv)
{
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);
    try {
        Ogre::RbxSceneManagerFactory factory;
        Ogre::Root root("", "", "ogre_demo.log");
        root.loadPlugin(argc > 1 ? argv[1] : "rggl.dll");
        Ogre::RenderSystemList* systems = root.getAvailableRenderers();
        if (systems->empty()) return 2;
        root.setRenderSystem(systems->front());
        root.initialise(false);
        Ogre::RenderWindow* window = root.createRenderWindow("Recovered Roblox Ogre demo", 640, 480, false);
        root.addSceneManagerFactory(&factory);
        Ogre::SceneManager* scene = root.createSceneManager("RbxSceneManager", "demo");
        puts("native scene created"); fflush(stdout);
        Ogre::Camera* camera = scene->createCamera("camera");
        camera->setPosition(0, 0, 5);
        camera->lookAt(0, 0, 0);
        camera->setNearClipDistance(0.1f);
        camera->setAspectRatio(640.0f / 480.0f);
        window->addViewport(camera)->setBackgroundColour(Ogre::ColourValue(0.12f, 0.16f, 0.22f));
        scene->setAmbientLight(Ogre::ColourValue(0.5f, 0.5f, 0.5f));
        scene->createLight("light")->setPosition(3, 4, 5);
        Ogre::Entity* sphere = scene->createEntity("sphere", Ogre::SceneManager::PT_SPHERE);
        Ogre::SceneNode* node = scene->getRootSceneNode()->createChildSceneNode();
        node->setScale(0.02f, 0.02f, 0.02f);
        node->attachObject(sphere);
        Ogre::WindowEventUtilities::messagePump();
        if (!root.renderOneFrame()) return 3;
        window->writeContentsToFile("ogre_demo.png");
        puts("rendered one frame: ogre_demo.png"); fflush(stdout);
        root.destroySceneManager(scene);
        root.removeSceneManagerFactory(&factory);
        return 0;
    } catch (const Ogre::Exception& e) {
        fprintf(stderr, "%s\n", e.getFullDescription().c_str());
        return 1;
    }
}
