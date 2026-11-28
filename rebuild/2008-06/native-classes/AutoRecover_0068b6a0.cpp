// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/OgreLightInline /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#include "OgreRbx/RbxSceneManager2008.h"

namespace Ogre {

// INFERRED: derived helper accesses protected nested SceneMgrQueuedRenderableVisitor
// and triggers emission of its 38-byte scalar deleting destructor (??_G).
// Note: function-files.json records 0068b6a0 as ??_E (the vtable slot alias in the
// 2008 link), while MSVC emits ??_G (38 bytes identical); delete[] forces ??_E with a vector loop.
struct Local_0068b6a0_Access : public RbxSceneManager {
    static void touch();
};

void Local_0068b6a0_Access::touch()
{
    SceneMgrQueuedRenderableVisitor* v = new SceneMgrQueuedRenderableVisitor();
    delete v;
}

}
