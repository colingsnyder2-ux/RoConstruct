// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_74d006487e31440b.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#undef _DEBUG
#define _DLL
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
#define undoState undoState()
#include "v8datamodel/MouseCommand.h"
#undef undoState
#include "util/Name.h"
#include "tool/RunDragger.h"
#include "tool/MegaDragger.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"

namespace RBX
{
	extern const char* sPartDragTool;

	class PartDragTool : public Named<MouseCommand, &sPartDragTool>
	{
	private:
		std::auto_ptr<RunDragger> runDragger;
		std::auto_ptr<MegaDragger> megaDragger;
		boost::shared_ptr<Instance> exeShared;
		G3D::Vector2 downPoint;
		bool dragging;
		G3D::Vector3 hitWorld;

	public:
		virtual MouseCommand* onMouseDown(const UIEvent& uiEvent);
		virtual void onMouseIdle(const UIEvent& uiEvent);
		virtual void onMouseMove(const UIEvent&);
		virtual void onMouseDelta(const UIEvent& uiEvent);
		virtual MouseCommand* onMouseUp(const UIEvent& uiEvent);
		virtual MouseCommand* onKeyDown(const UIEvent& uiEvent);
		virtual void render3dAdorn(Adorn* adorn);

		virtual const std::string getCursorName() const
		{
			return dragging ? "GrabRotateCursor" : "DragCursor";
		}

		PartDragTool(PartInstance* mousePart, const G3D::Vector3& hitPointWorld, Workspace* workspace, boost::shared_ptr<Instance> exeArg);
		virtual ~PartDragTool();
	};

	PartDragTool::PartDragTool(PartInstance* mousePart, const G3D::Vector3& hitPointWorld, Workspace* workspace, boost::shared_ptr<Instance> exeArg)
		: Base(workspace),
		  exeShared(exeArg),
		  hitWorld(hitPointWorld),
		  dragging(false)
	{
		RBXASSERT(mousePart);
		runDragger.reset(new RunDragger);

		std::vector<PVInstance*> pvInstances;
		pvInstances.push_back(mousePart);

		megaDragger.reset(new MegaDragger(mousePart, pvInstances, (RootInstance*)workspace));
	}
}
