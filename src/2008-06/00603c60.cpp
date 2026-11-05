// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_e84ed7184b496457.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <boost/shared_ptr.hpp>
#include <map>
#include "util/Name.h"
#define private public
#define protected public
#include "util/Object.h"
#undef protected
#undef private
namespace RBX
{
	template<typename Class, typename Parameter1>
	boost::shared_ptr<Class> exeCreate(Parameter1 p1)
	{
		return boost::shared_ptr<Class>(new Class(p1), Creatable<Instance>::Deleter());
	}
	template<typename Class, typename Parameter1, typename Parameter2>
	boost::shared_ptr<Class> exeCreate(Parameter1 p1, Parameter2 p2)
	{
		return boost::shared_ptr<Class>(new Class(p1, p2), Creatable<Instance>::Deleter());
	}
	template<typename Class, typename Parameter1, typename Parameter2, typename Parameter3>
	boost::shared_ptr<Class> exeCreate(Parameter1 p1, Parameter2 p2, Parameter3 p3)
	{
		return boost::shared_ptr<Class>(new Class(p1, p2, p3), Creatable<Instance>::Deleter());
	}
}
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
#include "v8world/Controller.h"
namespace RBX
{
	class DataModel;
	class ArrowPanel : public TopMenuBar
	{
	protected:
		DataModel* dataModel;
		Controller::ControllerType controller;
	public:
		ArrowPanel(Adorn* adorn, DataModel* dataModel, Controller::ControllerType controller);
		virtual bool isVisible() const;
		virtual G3D::Vector2 getSize() const;
	};
}
namespace RBX
{
	boost::shared_ptr<TopMenuBar> GuiBuilder::buildControlHud(Adorn* adorn, int yOffset)
	{
		Layout panelLayout;
		panelLayout.offset.y = yOffset;
		panelLayout.xLocation = Rect::RIGHT;
		panelLayout.yLocation = Rect::TOP;
		panelLayout.layoutStyle = Layout::VERTICAL;
		boost::shared_ptr<RelativePanel> panel = exeCreate<RelativePanel>(panelLayout);
		panel->setName("ControlHud");

		panel->addGuiItem(exeCreate<ArrowPanel>(adorn, dataModel, Controller::PRIMARY_CONTROLLER));
		panel->addGuiItem(exeCreate<MenuSpacer>(5.0f, 5.0f));
		panel->addGuiItem(exeCreate<ArrowPanel>(adorn, dataModel, Controller::SECONDARY_CONTROLLER));

		return panel;
	}
}
