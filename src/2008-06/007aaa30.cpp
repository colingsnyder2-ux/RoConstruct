// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_1a5d26efebba0026.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <G3D/Array.h>
#include <G3D/ReferenceCount.h>
namespace G3D { class GModule : public ReferenceCountedObject { public: virtual ~GModule(); }; }
namespace Ogre {
class MaterialPtr { public: __declspec(dllimport) virtual ~MaterialPtr(); void* pRep; void* pUseCount; };
class MeshPtr { public: __declspec(dllimport) virtual ~MeshPtr(); void* pRep; void* pUseCount; };
class SceneNode;
class SceneManager;
class Node {
public:
    virtual ~Node();
    __declspec(dllimport) const std::string& getName() const;
};
}
namespace RBX {
namespace Render {
class RenderSurface { public: ~RenderSurface(); int x; };
}
namespace RenderNew {
struct NodeContainer {
    virtual void nv0();
};
struct RootNode {
    virtual void rn0();
    virtual void rn1();
    virtual void rn2();
    virtual void rn3();
    virtual void rn4();
    virtual void rn5();
    virtual void rn6();
    virtual void rn7();
    virtual void rn8();
    virtual void rn9();
    virtual void rn10();
    virtual void rn11();
    virtual void rn12();
    virtual void rn13();
    virtual void rn14();
    virtual void rn15();
    virtual void rn16();
    virtual void rn17();
    virtual void rn18();
    virtual void rn19();
    virtual void rn20();
    virtual void rn21();
    virtual void rn22();
    virtual void rn23();
    virtual void rn24();
    virtual void rn25();
    virtual void rn26();
    virtual void rn27();
    virtual void rn28();
    virtual void rn29();
    virtual void rn30();
    virtual void rn31();
    virtual void rn32();
    virtual void rn33();
    virtual void rn34();
    virtual void rn35();
    virtual void rn36();
    virtual void rn37();
    virtual void rn38();
    virtual void rn39();
    virtual void rn40();
    virtual void rn41();
    virtual void rn42();
    virtual void rn43();
    virtual void rn44();
    virtual void rn45();
    virtual void rn46();
    virtual void rn47();
    virtual void rn48();
    virtual void rn49();
    virtual void rn50();
    virtual void rn51();
    virtual void rn52();
    virtual void rn53();
    virtual void rn54();
    virtual void rn55();
    virtual void removeAndDestroyChild(const std::string& name);
};
struct Creator {
    virtual void cr0();
    virtual void cr1();
    virtual void cr2();
    virtual void cr3();
    virtual void cr4();
    virtual void cr5();
    virtual void cr6();
    virtual void cr7();
    virtual void cr8();
    virtual void cr9();
    virtual void cr10();
    virtual void cr11();
    virtual void cr12();
    virtual void cr13();
    virtual void cr14();
    virtual void cr15();
    virtual void cr16();
    virtual void cr17();
    virtual void cr18();
    virtual void cr19();
    virtual void cr20();
    virtual void cr21();
    virtual void cr22();
    virtual void cr23();
    virtual void cr24();
    virtual void cr25();
    virtual void cr26();
    virtual void cr27();
    virtual void cr28();
    virtual void cr29();
    virtual void cr30();
    virtual void cr31();
    virtual void cr32();
    virtual void cr33();
    virtual void cr34();
    virtual void cr35();
    virtual void cr36();
    virtual void cr37();
    virtual void cr38();
    virtual void cr39();
    virtual void cr40();
    virtual void cr41();
    virtual void cr42();
    virtual void cr43();
    virtual void cr44();
    virtual RootNode* getRootSceneNode();
};
class SceneNodeEx : public Ogre::Node {
public:
    char pad[0x1d0];
    Creator* creator;
};
class RenderBase {
public:
    virtual ~RenderBase() {}
    int x4;
    G3D::Array<G3D::ReferenceCountedPointer<G3D::GModule> > modules;
};
class Obj { public: virtual ~Obj(); };
class RCObj : public G3D::ReferenceCountedObject { public: virtual ~RCObj(); };
class RenderScene : public RenderBase {
public:
    char pad0[0x268 - 0x14];
    SceneNodeEx* sceneNode;
    Obj* obj;
    Ogre::MaterialPtr material;
    Ogre::MeshPtr mesh;
    G3D::Array<Render::RenderSurface> surfacesA;
    G3D::Array<int*> listA;
    G3D::Array<int*> listB;
    G3D::Array<int*> listC;
    G3D::Array<Render::RenderSurface> surfacesB;
    G3D::Array<G3D::ReferenceCountedPointer<G3D::GModule> > modules2;
    G3D::ReferenceCountedPointer<RCObj> refA;
    char pad1[0x1c];
    G3D::ReferenceCountedPointer<RCObj> refB;
    char pad2[0x14];
    G3D::ReferenceCountedPointer<RCObj> refC;
    G3D::ReferenceCountedPointer<RCObj> refD;
    char pad3[8];
    G3D::Array<int> indices;
    virtual ~RenderScene();
};
}
}
RBX::RenderNew::RenderScene::~RenderScene()
{
    if (sceneNode) {
        sceneNode->creator->getRootSceneNode()->removeAndDestroyChild(sceneNode->getName());
        delete sceneNode;
    }
    delete obj;
}
