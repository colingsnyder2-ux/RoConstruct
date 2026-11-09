// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_45bf34bb8168b481.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
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
#define private public
#include "util/RunStateOwner.h"
#undef private
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
#define tempMetric tempMetric; bool exeFlag
#include "v8datamodel/Lighting.h"
#define initializeContents() initializeContents(bool start)
#include "v8datamodel/DataModel.h"
#undef initializeContents
#undef tempMetric
#include "v8datamodel/TimeState.h"
#define profileRun profileRun; double exeLoadTime; double exeParseTime; double exeJoinTime
#include "v8datamodel/Workspace.h"
#undef profileRun
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

#include "v8xml/SerializerV2.h"
#include <G3D/System.h>
namespace RBX
{
	template<> ContentProvider* ServiceProvider::create<ContentProvider>() const;

	void DataModel::loadContent(ContentId contentId)
	{
		G3D::RealTime start = G3D::System::time();
		std::auto_ptr<std::istream> stream = ServiceProvider::create<ContentProvider>(this)->getContent(contentId);
		G3D::RealTime loaded = G3D::System::time();
		StandardOut::singleton()->print(MESSAGE_INFO, "DataModel Loading %s", contentId.c_str());

		SerializerV2 serializer;
		serializer.load(*stream, this);
		G3D::RealTime parsed = G3D::System::time();

		workspace->joinAllHack();
		G3D::RealTime joined = G3D::System::time();

		workspace->exeLoadTime = loaded - start;
		workspace->exeParseTime = parsed - loaded;
		workspace->exeJoinTime = joined - parsed;
	}
}
