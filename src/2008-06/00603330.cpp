// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_fb5eba5bc7902a07.cpp

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
#include "gui/ChatOutput.h"
namespace RBX
{
	boost::shared_ptr<TopMenuBar> GuiBuilder::buildChatHud()
	{
		Layout panelLayout;
		panelLayout.offset.x = 25;
		panelLayout.offset.y = 100;
		panelLayout.xLocation = Rect::LEFT;
		panelLayout.yLocation = Rect::TOP;
		panelLayout.layoutStyle = Layout::VERTICAL;
		boost::shared_ptr<RelativePanel> panel = Creatable<Instance>::create<RelativePanel>(panelLayout);
		panel->setName("ChatHud");

		panel->addGuiItem(Creatable<Instance>::create<ChatOutput>());

		return panel;
	}

}
