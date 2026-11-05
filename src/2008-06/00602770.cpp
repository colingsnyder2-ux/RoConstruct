// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_guimenuaccessorcount6054553ba0d6e8b9.cpp

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
#include "v8datamodel/GuiBuilder.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "gui/Gui.h"
#include "gui/MenuItem.h"
namespace RBX
{
	Verb* GuiBuilder::getVerb(const std::string& name)
	{
		Verb* verb = workspace->getVerb(name);
		return verb;
	}

	boost::shared_ptr<TopMenuBar> GuiBuilder::buildMenu()
	{
		Layout panelLayout;
		panelLayout.xLocation = Rect::LEFT;
		panelLayout.yLocation = Rect::TOP;
		panelLayout.layoutStyle = Layout::HORIZONTAL;
		panelLayout.backdropColor = GuiItem::translucentBackdrop();
		boost::shared_ptr<RelativePanel> panel = Creatable<Instance>::create<RelativePanel>(panelLayout);
		panel->setName("MainMenu");

		panel->addGuiItem(Creatable<Instance>::create<MenuItem>(getVerb("TogglePlayMode"), "Tools"));
		panel->addGuiItem(Creatable<Instance>::create<MenuItem>(getVerb("ToggleToolbox"), "Insert"));
		panel->addGuiItem(Creatable<Instance>::create<MenuItem>(getVerb("ToggleFullScreen"), "Fullscreen"));
		panel->addGuiItem(Creatable<Instance>::create<MenuItem>(getVerb("Help"), "Help..."));
		panel->addGuiItem(Creatable<Instance>::create<MenuItem>(getVerb("Exit"), "   Exit"));

		for (size_t i = 0; i < (panel->getChildren() ? panel->getChildren()->size() : 0); ++i)
		{
			if (GuiItem* guiItem = panel->getGuiItem((int)i))
			{
				guiItem->setGuiSize(G3D::Vector2(100.0f, 20.0f));
			}
		}

		return panel;
	}
}
