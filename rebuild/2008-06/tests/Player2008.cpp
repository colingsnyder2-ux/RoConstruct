#include <Ogre.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>

#include <windows.h>
extern "C" int LoadPlace(const char* text);
extern "C" void GetPartPosition(float* x, float* y, float* z);
extern "C" void MovePart();
extern "C" void StepEngine(float dt);
extern "C" void ClosePlace();

static std::string readPlace(const char* path)
{
    std::ifstream f(path, std::ios::binary);
    if (!f) return "";
    std::ostringstream ss;
    ss << f.rdbuf();
    return ss.str();
}

int main(int argc, char** argv)
{
    std::string placeText;
    // default place
    placeText = "<roblox version=\"4\"><Item class=\"Workspace\"><Properties></Properties>"
        "<Item class=\"Part\" referent=\"RBX1\"><Properties>"
        "<string name=\"Name\">Brick</string><bool name=\"Anchored\">true</bool>"
        "<CoordinateFrame name=\"CFrame\"><X>0</X><Y>0</Y><Z>0</Z>"
        "<R00>1</R00><R01>0</R01><R02>0</R02><R10>0</R10><R11>1</R11><R12>0</R12><R20>0</R20><R21>0</R21><R22>1</R22>"
        "</CoordinateFrame></Properties></Item></Item></roblox>";
    if (argc > 1) {
        std::string loaded = readPlace(argv[1]);
        if (!loaded.empty()) placeText = loaded;
        else std::printf("could not read %s; using default place\n", argv[1]);
    }

    if (LoadPlace(placeText.c_str()) != 0) { std::printf("place load failed\n"); return 1; }

    Ogre::Root* root = new Ogre::Root("", "", "player.log");
    if (!root) { std::printf("root failed\n"); ClosePlace(); return 2; }
    try { root->loadPlugin("rgdx.dll"); } catch (...) { std::printf("load plugin failed\n"); }
    Ogre::RenderSystem* rs = NULL;
    Ogre::RenderSystemList* rlist = root->getAvailableRenderers();
    for (size_t i = 0; i < rlist->size(); ++i) {
        if ((*rlist)[i]->getName().find("Direct3D9") != std::string::npos) rs = (*rlist)[i];
    }
    if (!rs) { std::printf("no d3d9 renderer\n"); delete root; ClosePlace(); return 3; }
    root->setRenderSystem(rs);
    rs->setConfigOption("Full Screen", "No");
    rs->setConfigOption("Video Mode", "320 x 240 @ 32-bit colour");
    Ogre::RenderWindow* win = root->initialise(true, "Player2008");
    if (!win) { std::printf("window failed\n"); delete root; ClosePlace(); return 4; }
    Ogre::SceneManager* sm = root->createSceneManager(Ogre::ST_GENERIC, "sm");
    Ogre::Camera* cam = sm->createCamera("cam");
    cam->setPosition(0, 0, 8);
    cam->lookAt(0, 0, 0);
    cam->setNearClipDistance(0.1f);
    Ogre::Viewport* vp = win->addViewport(cam);
    vp->setBackgroundColour(Ogre::ColourValue(1, 0, 1));

    Ogre::ManualObject* mo = sm->createManualObject("cube");
    mo->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);
    float s = 0.5f;
    mo->position(-s,-s,s); mo->colour(1,0,0);
    mo->position(s,-s,s); mo->colour(1,0,0);
    mo->position(s,s,s); mo->colour(1,0,0);
    mo->position(-s,-s,s); mo->colour(1,0,0);
    mo->position(s,s,s); mo->colour(1,0,0);
    mo->position(-s,s,s); mo->colour(1,0,0);
    mo->end();
    Ogre::SceneNode* node = sm->getRootSceneNode()->createChildSceneNode();
    node->attachObject(mo);
    {
        float x,y,z; GetPartPosition(&x,&y,&z);
        node->setPosition(x,y,z);
    }

    bool quick = (getenv("ROC_BUILD") != NULL);
    bool captured1 = false, captured2 = false;
    bool moved = false;
    if (quick) {
        // render two frames then exit
        root->renderOneFrame(); win->update(); win->writeContentsToFile("frame1.png"); std::printf("frame1 written\n");
        MovePart();
        { float x,y,z; GetPartPosition(&x,&y,&z); node->setPosition(x,y,z); }
        root->renderOneFrame(); win->update(); win->writeContentsToFile("frame2.png"); std::printf("frame2 written\n");
    } else {
        Ogre::Timer timer;
        unsigned long last = timer.getMilliseconds();
        while (!win->isClosed()) {
        unsigned long now = timer.getMilliseconds();
        float dt = (now - last) / 1000.0f;
        if (dt <= 0) dt = 1.0f/60.0f;
        last = now;

        // manual camera input
        Ogre::Vector3 camMove(0,0,0);
        if (GetAsyncKeyState('A') & 0x8000) camMove.x -= 1;
        if (GetAsyncKeyState('D') & 0x8000) camMove.x += 1;
        if (GetAsyncKeyState('W') & 0x8000) camMove.z -= 1;
        if (GetAsyncKeyState('S') & 0x8000) camMove.z += 1;
        if (GetAsyncKeyState('Q') & 0x8000) camMove.y += 1;
        if (GetAsyncKeyState('E') & 0x8000) camMove.y -= 1;
        cam->moveRelative(camMove * dt * 5.0f);
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;

        if (!moved) {
            // capture first frame before move
            if (!captured1) {
                root->renderOneFrame();
                win->update();
                win->writeContentsToFile("frame1.png");
                std::printf("frame1 written\n");
                captured1 = true;
                MovePart();
                moved = true;
            }
        }
        // step physics
        StepEngine(dt);
        {
            float x,y,z; GetPartPosition(&x,&y,&z);
            node->setPosition(x,y,z);
        }
        if (moved && !captured2) {
            root->renderOneFrame();
            win->update();
            win->writeContentsToFile("frame2.png");
            std::printf("frame2 written\n");
            captured2 = true;
        }

        root->renderOneFrame();
        win->update();
    } // while
    } // else

    delete root;
    ClosePlace();
    return 0;
}