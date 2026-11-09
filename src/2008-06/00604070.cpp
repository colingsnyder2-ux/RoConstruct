// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_a308dcb0634c0895.cpp

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
#include "v8datamodel/GuiBuilder.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "gui/Gui.h"
namespace RBX
{
	boost::shared_ptr<TopMenuBar> GuiBuilder::buildRightPalette(Adorn* adorn)
	{
		Layout panelLayout;
		panelLayout.xLocation = Rect::RIGHT;
		panelLayout.yLocation = Rect::BOTTOM;
		panelLayout.layoutStyle = Layout::VERTICAL;
		boost::shared_ptr<RelativePanel> panel = Creatable<Instance>::create<RelativePanel>(panelLayout);
		panel->setName("RightPalette");

		buildRightPaletteItems(adorn, panel);

		return panel;
	}
}
