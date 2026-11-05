// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espclaude_383daa97a665c867.cpp

// Candidate translation unit (score above; library headers required).
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
#define AbstractFactoryProduct GuidItem<Instance>, public AbstractFactoryProduct
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
#include "util/StateStack.h"
namespace RBX { template<class T> class __declspec(novtable) StateStackStub { public: virtual void setDirty(bool) = 0; virtual bool isDirty() const = 0; size_t getStackSize() const; }; }
#define StateStack StateStackStub
#include "v8tree/Verb.h"
#undef StateStack
#include <boost/scoped_ptr.hpp>
namespace RBX { class TimeState; }
namespace boost { template<> class scoped_ptr<RBX::TimeState> { public: RBX::TimeState* operator->() const; RBX::TimeState* get() const; }; }
#define tempMetric tempMetric; public: void exeStep(float); void exeDoStep(float); private: bool exeFlag0; bool exeFlag
#include "v8datamodel/Lighting.h"
#include "v8datamodel/DataModel.h"
#undef tempMetric
#include "v8datamodel/TimeState.h"
#define render3dSelect(a, b) render3dSelect(a, b) { return; } void exeCheckCamera(); void exeUnusedSelect(a, b)
#define profileWorkspaceStep exeProfilePad[10]; boost::scoped_ptr<Profiling::CodeProfiler> profileWorkspaceStepExe
#include "v8datamodel/Workspace.h"
#undef profileWorkspaceStep
#undef render3dSelect
#include "v8datamodel/Hopper.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/JointsService.h"
#include "v8datamodel/LocalBackpack.h"
#include "v8datamodel/GuiBuilder.h"
#include "script/ScriptContext.h"
#include "gui/GUI.h"
#include "util/Log.h"
#include "util/IMetric.h"
#include "util/standardout.h"
#include "util/Http.h"
#include "util/Sound.h"

namespace RBX
{
	class ExeMark
	{
		Profiling::CodeProfiler& section;
		Profiling::CodeProfiler* enclosingSection;
		G3D::int64 startTime;
		bool frameTick;
	public:
		ExeMark(Profiling::CodeProfiler& sectionSet, bool frameTickSet);
		~ExeMark();
	};

	void DataModel::exeStep(float timeInterval)
	{
		if (exeFlag)
		{
			ExeMark mark(*workspace->profileWorkspaceStepExe.get(), true);
			exeDoStep(timeInterval);
			workspace->getCamera()->onHeartbeat();
			localBackpack->onHeartbeat();
		}
	}
}
