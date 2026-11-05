// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espclaude_e4881bf5769c947f.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include "G3D/ReferenceCount.h"
#include "G3D/Array.h"

namespace RBX {
namespace Render {

class SceneObject : public G3D::ReferenceCountedObject {
};
typedef G3D::ReferenceCountedPointer<SceneObject> SceneObjectRef;

struct ObjectList {
    char data[0xc];
    ~ObjectList();
};

struct Group {
    char data[0xc];
    ~Group();
};

class SceneBase {
public:
    virtual ~SceneBase() {}
    int flags;
    Group group;
    char pad[0x268 - 0x14];
};

class RenderScene : public SceneBase {
public:
    virtual ~RenderScene();

    ObjectList list1;
    G3D::Array<int> array1;
    G3D::Array<int> array2;
    G3D::Array<int> array3;
    ObjectList list2;
    Group group2;
    SceneObjectRef ref1;
    char pad1[0x1c];
    SceneObjectRef ref2;
    char pad2[0x14];
    SceneObjectRef ref3;
    SceneObjectRef ref4;
    char pad3[8];
    G3D::Array<int> array4;
    int value;
    SceneObjectRef ref5;
};

RenderScene::~RenderScene()
{
}

}
}
