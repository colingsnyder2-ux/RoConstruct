// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_c54f6b9686a5fbf3.cpp

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
#include "v8datamodel/SafeChat.h"
#include "gui/ChatWidget.h"
#include <boost/lexical_cast.hpp>
namespace RBX
{
	void GuiBuilder::buildChatMenu(ChatOption* parentOption, std::string parentCode, boost::shared_ptr<UnifiedWidget> parentGui)
	{
		for (size_t i = 0; i < parentOption->children.size(); ++i)
		{
			ChatOption* option = parentOption->children[i];
			std::string code = parentCode + " " + boost::lexical_cast<std::string>(i);

			boost::shared_ptr<ChatWidget> button = Creatable<Instance>::create<ChatWidget>(option->text, code);
			parentGui->addGuiItem(button);

			buildChatMenu(option, code, button);
		}
	}
}
