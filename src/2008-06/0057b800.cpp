// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espclaude_f56d7036539cbcb8.cpp

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
#include "util/StateStack.h"
namespace RBX { template<class T> class __declspec(novtable) StateStackStub { public: virtual void setDirty(bool) = 0; virtual bool isDirty() const = 0; size_t getStackSize() const; }; }
#define StateStack StateStackStub
#include "v8tree/Verb.h"
#undef StateStack
#include <boost/scoped_ptr.hpp>
namespace RBX { class TimeState; }
namespace boost { template<> class scoped_ptr<RBX::TimeState> { public: RBX::TimeState* operator->() const; RBX::TimeState* get() const; }; }
#define tempMetric tempMetric; bool exeFlag
#define endRunThread(x) endRunThread(x); void exeRequestStop(); void exeJoinThread()
#include "util/RunStateOwner.h"
#undef endRunThread
#include "v8datamodel/Lighting.h"
#include "v8datamodel/DataModel.h"
#undef tempMetric
#include "v8datamodel/TimeState.h"
#include "v8datamodel/Workspace.h"
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
#pragma warning (push)
#pragma warning (disable : 4355)
	DataModel::DataModel()
		: VerbContainer(NULL),
		  workspace(Creatable::create<Workspace>(this)),
		  guiRoot(Creatable::create<GuiRoot>()),
		  guiHooks(Creatable::create<GuiRoot>()),
		  mutex(new boost::recursive_mutex),
		  guiTarget(NULL),
		  forceArrowCursor(true),
		  exeFlag(false),
		  dirty(false),
		  drawId(0)
	{
		setName("Level");
	}
#pragma warning (pop)
}

namespace RBX
{
	extern const char* sChangeHistoryService;
	class ChangeHistoryService : public DescribedNonCreatable<ChangeHistoryService, Instance, &sChangeHistoryService>, public Service
	{
	public:
		void setEnabled(bool);
	};

	static Reflection::SignalDesc<DataModel, void(void)> event_Closing("Close");

	inline void DataModel::raiseClose()
	{
		Notifier<ServiceProvider, Closing>::raise(Closing());
		event_Closing.fire(this);
	}

	void DataModel::closeDataModel(boost::shared_ptr<DataModel> dataModel, bool joinRunThread)
	{
		boost::shared_ptr<RunService> runService;
		{
			DataModel::Lock lock(dataModel);
			if (ChangeHistoryService* changeHistory = ServiceProvider::find<ChangeHistoryService>(dataModel.get()))
				changeHistory->setEnabled(false);
			dataModel->dirty = false;
			runService = dataModel->runService;
			runService->exeRequestStop();
		}

		if (joinRunThread && runService)
			runService->exeJoinThread();

		{
		DataModel::Lock lock(dataModel);

		dataModel->raiseClose();

		dataModel->clearContents();
		dataModel->removeAllChildren();
		dataModel->clearServices();
		}
	}
}
