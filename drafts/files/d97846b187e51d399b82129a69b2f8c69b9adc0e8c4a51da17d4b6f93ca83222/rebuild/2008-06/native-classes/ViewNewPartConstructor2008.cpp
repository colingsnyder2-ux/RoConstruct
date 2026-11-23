// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/partchunk-profile /I{headers}/part-embedded /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Original 004ebcc0: PartChunk construction, sleeping queue, listener and outfit signal.
// The target inlines the devirtualized Chunk::getSortValue / setSortValue (fld [esi+0x14] / fstp [esi+0x14]), so this
// unit takes the inline form of RenderLib/AggregateChunk2008.h (CHUNK_HEADER_INLINES_SORT_VALUE; SceneManager2008.cpp
// still holds the out-of-line 004e5b60 / 004e5b70 copies). Rejected earlier: direct `sortValue` access (419 B, the
// compares fold the field into fcomp memory operands).
#undef OGRE_NONCLIENT_BUILD
#define CHUNK_HEADER_INLINES_SORT_VALUE
#define NOMINMAX
#include "ViewNew/PartChunk.h"
#include "RenderLib/ViewBase2008.h"
#include "v8datamodel/PartInstance.h"
#include <boost/bind.hpp>

namespace RBX { namespace ViewNew {
Part::Part(const boost::shared_ptr<PartInstance>& partInstance, ViewBase* view)
    : PartChunk(0.0f, partInstance, view)
{
    if (partInstance->getCanAggregate()) {
        view->sceneManager->setSleeping(this, true);
        if (getSortValue() < 1.0f) setSortValue(0.0f);
    } else if (getSortValue() < 0.5f) setSortValue(0.5f);
    if (partInstance) partInstance->Notifier<PartInstance, CanAggregateChanged>::addListener(this);
    connection = PartInstance::event_OutfitChanged.connect(partInstance.get(), boost::bind(&Part::invalidate, this), 10);
    invalidateMesh();
    invalidateMaterial();
}
} }
