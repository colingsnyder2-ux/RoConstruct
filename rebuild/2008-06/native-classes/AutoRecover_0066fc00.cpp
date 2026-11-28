// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#include "RbxGraphics/AdornRbxGfx2008.h"
#include <OgreSceneNode.h>
#include <OgreMatrix3.h>
#include <OgreMatrix4.h>
#include <OgreQuaternion.h>
#include <OgreVector3.h>
#include "util/Utilities.h"

namespace RBX
{
    // 0097da58: counter shared with finishRenderPass (defined in AdornRbxGfx.cpp)
    extern int nameCounter;

    std::string AdornRbxGfx::uniqueName()
    {
        int local = 0;
        local = nameCounter;
        nameCounter = local + 1;
        // INFERRED: StringConverter<int> is declared via util/Utilities.h
        return StringConverter<int>::convertToString(local);
    }
}
