// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_c9fe5d271c384dfe.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#undef _DEBUG
#define _DLL
#define lineSegment(a, b, c) lineSegment(a, b, c) = 0; virtual void exeAdornExtra()
#include "RbxGraphics/Adorn.h"
#undef lineSegment
#define private public
#include "util/IRenderable.h"
#undef private
#include "util/Object.h"
#define hasListeners() hasListeners() const { return listeners.size() > 0; } bool hasListenersEmpty()
#include "util/Events.h"
#undef hasListeners
namespace RBX { template<class T> class GuidItem { public: virtual ~GuidItem() {} char guidPad[0xc]; }; }
namespace RBX { template<class T> class GuidAFP : public AbstractFactoryProduct<T> { protected: virtual void onGuidChanged() {} }; }
#define AbstractFactoryProduct GuidItem<Instance>, public GuidAFP
#include "util/Guid.h"
namespace RBX { class GuidStub { public: typedef Guid::Data Data; void assign(const Data&) {} operator const Guid&() const { return *(const Guid*)0; } }; }
#define Guid GuidStub
#include "v8tree/Instance.h"
#undef Guid
#undef AbstractFactoryProduct
#include "v8datamodel/PVInstance.h"
#define candidatePrimaryPart candidatePrimaryPart; std::vector<boost::shared_ptr<PartInstance> > exeModelVector
#include "v8datamodel/ModelInstance.h"
#undef candidatePrimaryPart
#include "v8datamodel/RootInstance.h"
#include "v8datamodel/Stats.h"
#include "v8tree/Verb.h"
#include "script/Script.h"
#include "v8world/IMoving.h"
#include "gui/GuiEvent.h"
#include "util/RunStateOwner.h"
#include "util/ContentProvider.h"
#include "util/Profiling.h"
#include "util/UIEvent.h"
#define render3dSelect(a, b) render3dSelect(a, b) { return; } void exeCheckCamera(); void exeUnusedSelect(a, b)
#include "v8datamodel/Workspace.h"
#undef render3dSelect
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/Selection.h"

#include "reflection/reflection.h"
namespace RBX { namespace Reflection {
template void BoundFuncDesc<Workspace, boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >(ContentId), 1>::call<boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >(Workspace*, Value&, Value&) const;
} }
