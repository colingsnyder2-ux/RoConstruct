// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/partchunk-profile /I{headers}/part-embedded /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 2008-06 native RBX::ViewNew::PartChunk::onChildRemoved 004e73b0 (inactive), a row of the original ViewNew Part unit.
// Identity: ViewNew/PartChunk.h (the PartChunk ctor 004eaae0 binds slot 004e73b0 to Instance::event_childRemoved
// 00973c6c into childRemovedConnection +0x6c, see ViewNewPartChunkRecovery2008.cpp). Thiscall, ret 8 (shared_ptr by
// value): child.get() against specialShape +0xd4, then scoped_connection +0xa8 disconnect 00595230, specialShape =
// NULL and invalidateMesh 004e6740. Flags and includes follow ViewNewPartChunkRecovery2008.cpp, which defines the
// sibling slots (that file is not this task's, so this row has its own unit). Shape: 2007 openrbx
// Client/RbxView/Part.cpp PartChunk::onChildRemoved.
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
#include "ViewNew/PartChunk.h"
#include "v8datamodel/SpecialShape.h"

namespace RBX { namespace ViewNew {
// 004e73b0
void PartChunk::onChildRemoved(boost::shared_ptr<Instance> child)
{
    if (child.get() == specialShape) {
        shapePropertyChangedConnection.disconnect();
        specialShape = NULL;
        invalidateMesh();
    }
}
} }
