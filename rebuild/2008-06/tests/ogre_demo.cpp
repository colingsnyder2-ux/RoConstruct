// Standalone: real rgmain/rggl and recovered RbxSceneManager.
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
#include "OgreRbx/RbxSceneManager2008.h"
#include "OgreRbx/VisualEngine2008.h"
#include "OgreRbxNode/TwoDManager2008.h"
#include <GLG3D/LightingParameters.h>
#include <windows.h>
#include <cmath>
#include <cstdio>

float zoom=42;
WNDPROC previousProc;
// Demo ManualObjects need the stock caster query; the recovered query expects
// Roblox's aggregate RbxEntity beneath rbxroot, which this small driver lacks.
class DemoSceneManager : public Ogre::RbxSceneManager {
public:
    DemoSceneManager(const Ogre::String& name):Ogre::RbxSceneManager(name) {}
    void skyLighting(Ogre::VisualEngine* engine,const G3D::LightingParameters& lighting) {
        mRbxSky->setLighting(engine,lighting);
    }
    const ShadowCasterList& findShadowCastersForLight(const Ogre::Light* light,const Ogre::Camera* camera) {
        return Ogre::SceneManager::findShadowCastersForLight(light,camera);
    }
};
class DemoFactory : public Ogre::RbxSceneManagerFactory {
public:
    Ogre::SceneManager* createInstance(const Ogre::String& name) { return new DemoSceneManager(name); }
};
LRESULT CALLBACK demoProc(HWND hwnd,UINT msg,WPARAM w,LPARAM l) {
    if(msg==WM_MOUSEWHEEL) {
        zoom*=GET_WHEEL_DELTA_WPARAM(w)>0 ? 0.9f:1.1f;
        zoom=std::max(18.0f,std::min(zoom,85.0f));
        return 0;
    }
    return CallWindowProc(previousProc,hwnd,msg,w,l);
}

// Batched flat-shaded geometry; no textures or overlays.
struct Builder {
    Ogre::ManualObject* object;
    unsigned index;
    Builder(Ogre::SceneManager* scene,const char* name,Ogre::ColourValue colour,bool glow=false):index(0) {
        Ogre::MaterialPtr material=Ogre::MaterialManager::getSingleton().create(name,"General");
        material->setDiffuse(colour); material->setAmbient(colour);
        if(glow) { material->setSelfIllumination(colour); material->setReceiveShadows(false); }
        object=scene->createManualObject(name);
        object->begin(name,Ogre::RenderOperation::OT_TRIANGLE_LIST);
    }
    void quad(Ogre::Vector3 a,Ogre::Vector3 b,Ogre::Vector3 c,Ogre::Vector3 d) {
        Ogre::Vector3 normal=(b-a).crossProduct(c-a).normalisedCopy();
        object->position(a); object->normal(normal);
        object->position(b); object->normal(normal);
        object->position(c); object->normal(normal);
        object->position(d); object->normal(normal);
        object->quad(index,index+1,index+2,index+3); index+=4;
    }
    void box(float x,float y,float z,float w,float h,float depth) {
        Ogre::Vector3 a(x-w/2,y-h/2,z-depth/2),b(x+w/2,y-h/2,z-depth/2);
        Ogre::Vector3 c(x+w/2,y+h/2,z-depth/2),d(x-w/2,y+h/2,z-depth/2);
        Ogre::Vector3 e(x-w/2,y-h/2,z+depth/2),f(x+w/2,y-h/2,z+depth/2);
        Ogre::Vector3 g(x+w/2,y+h/2,z+depth/2),k(x-w/2,y+h/2,z+depth/2);
        quad(a,d,c,b); quad(e,f,g,k); quad(a,e,k,d);
        quad(b,c,g,f); quad(d,k,g,c); quad(a,b,f,e);
    }
    void tower(float x,float z,float radius,float bottom,float top,float tipRadius=-1) {
        if(tipRadius<0) tipRadius=radius;
        for(int i=0;i<12;++i) {
            float a=i*Ogre::Math::TWO_PI/12,b=(i+1)*Ogre::Math::TWO_PI/12;
            Ogre::Vector3 p(x+radius*cos(a),bottom,z+radius*sin(a));
            Ogre::Vector3 q(x+radius*cos(b),bottom,z+radius*sin(b));
            Ogre::Vector3 r(x+tipRadius*cos(b),top,z+tipRadius*sin(b));
            Ogre::Vector3 s(x+tipRadius*cos(a),top,z+tipRadius*sin(a));
            quad(q,p,s,r);
            quad(Ogre::Vector3(x,top,z),r,s,Ogre::Vector3(x,top,z));
        }
    }
    void finish(Ogre::SceneManager* scene) {
        object->end();
        scene->getRootSceneNode()->createChildSceneNode()->attachObject(object);
    }
};

int main(int argc,char** argv) {
    SetErrorMode(SEM_FAILCRITICALERRORS|SEM_NOGPFAULTERRORBOX);
    try {
        bool smoke=argc>2 && std::string(argv[2])=="--smoke";
        DemoFactory factory;
        Ogre::Root root("","","ogre_demo.log");
        root.loadPlugin(argc>1 ? argv[1]:"rggl.dll");
        root.setRenderSystem(root.getAvailableRenderers()->front());
        root.initialise(false);
        Ogre::RenderWindow* window=root.createRenderWindow("CASTLE ISLAND | Drag: orbit | Wheel: zoom | Space: auto orbit | R: reset | Esc: exit",1100,760,false);
        root.addSceneManagerFactory(&factory);
        Ogre::SceneManager* scene=root.createSceneManager("RbxSceneManager","castle");
        Ogre::Camera* camera=scene->createCamera("camera");
        camera->setNearClipDistance(0.2f); camera->setFarClipDistance(10000);
        camera->setAspectRatio(1100.0f/760);
        window->addViewport(camera)->setBackgroundColour(Ogre::ColourValue(0.055f,0.075f,0.13f));
        scene->setAmbientLight(Ogre::ColourValue(0.43f,0.43f,0.5f));
        Ogre::Light* sun=scene->createLight("sun");
        sun->setType(Ogre::Light::LT_DIRECTIONAL); sun->setDirection(-0.5f,-1,-0.4f);
        sun->setDiffuseColour(1,0.86f,0.68f);
        scene->setShadowTechnique(Ogre::SHADOWTYPE_TEXTURE_MODULATIVE);
        scene->setShadowTextureSettings(2048,1);
        scene->setShadowColour(Ogre::ColourValue(0.72f,0.74f,0.8f));
        scene->setShadowFarDistance(120);

        Ogre::ResourceGroupManager::getSingleton().addResourceLocation("assets","FileSystem","General");
        Ogre::MaterialPtr skyMaterial=Ogre::MaterialManager::getSingleton().create("Original Roblox sky","General");
        skyMaterial->setLightingEnabled(false);
        skyMaterial->setReceiveShadows(false);
        skyMaterial->getTechnique(0)->getPass(0)->createTextureUnitState()->setCubicTextureName("null_plainsky512.jpg",false);
        scene->setSkyBox(true,"Original Roblox sky",5000,true);
        Ogre::VisualEngine skyContext;
        skyContext.viewport=window->getViewport(0);
        skyContext.sceneManager=scene;
        skyContext.camera=camera;
        G3D::LightingParameters lighting(15*3600.0,false);
        static_cast<DemoSceneManager*>(scene)->skyLighting(&skyContext,lighting);
        Ogre::TwoDManager hud;
        hud.setup(scene,window,Ogre::RENDER_QUEUE_OVERLAY,true,false);
        Ogre::FrameHistory history;

        Builder rock(scene,"Basalt",Ogre::ColourValue(0.18f,0.21f,0.28f));
        rock.tower(0,0,14,-5,-1,11.5f); rock.tower(0,0,6,-10,-5,14); rock.finish(scene);
        rock.object->setCastShadows(false);
        Builder grass(scene,"Moss",Ogre::ColourValue(0.24f,0.43f,0.29f));
        grass.tower(0,0,11.6f,-1,0); grass.finish(scene);
        grass.object->setCastShadows(false);
        Builder stone(scene,"Sandstone",Ogre::ColourValue(0.69f,0.66f,0.58f));
        stone.box(0,1,0,15,2,13);
        stone.box(-6,4,0,1.4f,6,12); stone.box(6,4,0,1.4f,6,12);
        stone.box(0,4,-5.5f,12,6,1.4f);
        stone.box(-4.5f,4,5.5f,3,6,1.4f); stone.box(4.5f,4,5.5f,3,6,1.4f);
        stone.box(0,6.5f,5.5f,6,1.2f,1.4f); stone.box(0,5,-1,6,8,5);
        for(int x=-1;x<=1;x+=2) for(int z=-1;z<=1;z+=2) {
            stone.tower(x*6,z*5.5f,2,1,9);
            for(int i=0;i<8;++i) {
                float a=i*Ogre::Math::TWO_PI/8;
                stone.box(x*6+1.6f*cos(a),9.4f,z*5.5f+1.6f*sin(a),0.65f,0.8f,0.65f);
            }
        }
        for(int i=-5;i<=5;i+=2) {
            stone.box(i,7.3f,-5.5f,0.9f,1,1.6f);
            stone.box(-6,7.3f,i,1.6f,1,0.9f); stone.box(6,7.3f,i,1.6f,1,0.9f);
        }
        stone.finish(scene);
        Builder roof(scene,"Copper roofs",Ogre::ColourValue(0.17f,0.42f,0.45f));
        roof.tower(0,-1,4.5f,9,13,0); roof.finish(scene);
        Builder wood(scene,"Drawbridge",Ogre::ColourValue(0.33f,0.19f,0.105f));
        for(int i=0;i<11;++i) wood.box(0,1,7+i*0.65f,3.6f,0.25f,0.55f);
        wood.box(-1.9f,1.5f,9.5f,0.18f,0.18f,7); wood.box(1.9f,1.5f,9.5f,0.18f,0.18f,7);
        wood.finish(scene);
        Builder dark(scene,"Windows",Ogre::ColourValue(0.055f,0.08f,0.12f));
        for(int x=-2;x<=2;x+=2) dark.box(x,6.5f,1.52f,0.6f,1.7f,0.08f);
        dark.box(0,3,5.52f,2.6f,4,0.12f); dark.finish(scene);
        Builder gold(scene,"Flags",Ogre::ColourValue(1,0.61f,0.12f));
        gold.box(0,14,-1,0.14f,3,0.14f); gold.box(1,14.8f,-1,2,1.1f,0.08f); gold.finish(scene);
        Builder trees(scene,"Pines",Ogre::ColourValue(0.12f,0.29f,0.25f));
        for(int i=0;i<9;++i) {
            float a=(i+1)*Ogre::Math::TWO_PI/11;
            trees.tower(9*cos(a),9*sin(a),1.1f,0,4+(i%3),0);
        }
        trees.finish(scene);

        HWND hwnd=0; window->getCustomAttribute("WINDOW",&hwnd);
        previousProc=reinterpret_cast<WNDPROC>(SetWindowLongPtr(hwnd,GWLP_WNDPROC,reinterpret_cast<LONG_PTR>(demoProc)));
        float yaw=0.65f,pitch=0.48f;
        bool orbit=false,lastSpace=false,dragging=false;
        bool hudVisible=true,wireframe=false,shadows=true,cycle=false;
        bool lastKeys[5]={};
        float hour=15;
        float elapsed=0;
        POINT previous={}; DWORD last=GetTickCount();
        for(int frame=0;!window->isClosed() && (!smoke || frame<45);++frame) {
            Ogre::WindowEventUtilities::messagePump();
            if(window->isClosed() || (GetForegroundWindow()==hwnd && (GetAsyncKeyState(VK_ESCAPE)&0x8000))) break;
            DWORD now=GetTickCount(); float dt=(now-last)*0.001f; last=now;
            bool focused=GetForegroundWindow()==hwnd;
            bool space=focused && (GetAsyncKeyState(VK_SPACE)&0x8000);
            if(space && !lastSpace) orbit=!orbit;
            lastSpace=space;
            POINT mouse; GetCursorPos(&mouse);
            bool down=focused && (GetAsyncKeyState(VK_LBUTTON)&0x8000);
            if(down && dragging) { yaw-=(mouse.x-previous.x)*0.008f; pitch+=(mouse.y-previous.y)*0.008f; }
            previous=mouse; dragging=down;
            const int keys[5]={'H','W','S','D','T'};
            for(int k=0;k<5;++k) {
                bool pressed=focused && (GetAsyncKeyState(keys[k])&0x8000);
                if(pressed && !lastKeys[k]) {
                    if(k==0) hudVisible=!hudVisible;
                    if(k==1) { wireframe=!wireframe; camera->setPolygonMode(wireframe?Ogre::PM_WIREFRAME:Ogre::PM_SOLID); }
                    if(k==2) { shadows=!shadows; scene->setShadowTechnique(shadows?Ogre::SHADOWTYPE_TEXTURE_MODULATIVE:Ogre::SHADOWTYPE_NONE); }
                    if(k==3) cycle=!cycle;
                    if(k==4) hour=fmod(hour+3,24.0f);
                }
                lastKeys[k]=pressed;
            }
            elapsed+=dt;
            if(cycle) hour=fmod(hour+dt*0.4f,24.0f);
            if(smoke && frame==25) hour=22;
            lighting.setTime(hour*3600);
            static_cast<DemoSceneManager*>(scene)->skyLighting(&skyContext,lighting);
            scene->setAmbientLight(Ogre::ColourValue(lighting.ambient.r,lighting.ambient.g,lighting.ambient.b));
            sun->setDirection(-lighting.lightDirection.x,-lighting.lightDirection.y,-lighting.lightDirection.z);
            sun->setDiffuseColour(lighting.lightColor.r,lighting.lightColor.g,lighting.lightColor.b);
            Ogre::FrameHistory::Frame record;
            record.time=dt*1000;
            history.push(record);
            if(hudVisible) {
                hud.addQuad("castle_hud.png",G3D::Color4(1,1,1,1),24,736,624,600,0,0,1,1);
                for(int i=1;i<std::min(history.getCount(),100);++i) {
                    float a=std::min(history.get(i)->time,50.0f);
                    float b=std::min(history.get(i-1)->time,50.0f);
                    hud.outlineRectangle(28+(100-i)*2,580+a,30+(100-i)*2,580+b,G3D::Color4(0.35f,0.9f,0.75f,0.9f));
                }
            }
            if(orbit && !down) yaw+=dt*0.22f;
            if(focused && (GetAsyncKeyState('R')&0x8000)) { yaw=0.65f; pitch=0.48f; zoom=42; }
            pitch=std::max(0.12f,std::min(pitch,1.35f));
            camera->setPosition(zoom*cos(pitch)*sin(yaw),3+zoom*sin(pitch),zoom*cos(pitch)*cos(yaw));
            camera->lookAt(0,3,0);
            // Direct DLL render-target update fixes the trial's black-frame path.
            window->Ogre::RenderTarget::update();
            // This standalone scene has no Ogre Overlay to populate queue 100.
            // Flush the native listener explicitly when the queue stayed empty.
            bool repeatHud=false;
            hud.renderQueueEnded(Ogre::RENDER_QUEUE_OVERLAY,"",repeatHud);
            if(frame==20) window->writeContentsToFile("castle_island.png");
            if(smoke && frame==44) window->writeContentsToFile("castle_night.png");
            if(frame%30==0) {
                char title[240];
                sprintf(title,"CASTLE ISLAND | %.1f h | median %.1f ms | Drag orbit / Wheel zoom | H HUD / W wire / S shadows / D day cycle / T +3h",hour,history.median(std::min(history.getCount(),20)));
                SetWindowTextA(hwnd,title);
            }
            window->swapBuffers(false);
            Sleep(10);
        }
        if(!window->isClosed()) SetWindowLongPtr(hwnd,GWLP_WNDPROC,reinterpret_cast<LONG_PTR>(previousProc));
        scene->removeRenderQueueListener(&hud);
        skyContext.viewport=0; skyContext.sceneManager=0; skyContext.camera=0;
        root.destroySceneManager(scene); root.removeSceneManagerFactory(&factory);
        return 0;
    } catch(const Ogre::Exception& e) {
        fprintf(stderr,"%s\n",e.getFullDescription().c_str()); return 1;
    }
}
