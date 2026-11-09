// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_try_b894a2da96c86c7e.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
using namespace Ogre;
namespace Ogre {
class VisualEngine {
    char reserved[0xcc];
    MeshPtr mMesh;
public:
    void setMesh(MeshPtr mesh);
};
void VisualEngine::setMesh(MeshPtr mesh) { mMesh = mesh; }
}
