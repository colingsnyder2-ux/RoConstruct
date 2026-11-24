// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "GuiHud2008/GuiBuilder2008.h"

// INFERRED: GuiBuilder2008.h does not declare ArrowPanel or Controller, so
// minimal file-local declarations are provided. The enum values come from the
// pushed constants: 1 for the first ArrowPanel and 2 for the second.
namespace RBX
{
	class Controller
	{
	public:
		enum ControllerType
		{
			NO_CONTROLLER = 0,
			PRIMARY_CONTROLLER = 1,
			SECONDARY_CONTROLLER = 2
		};
	};

	// INFERRED: ArrowPanel derives from GuiItem.
	class ArrowPanel : public GuiItem
	{
	public:
		ArrowPanel(Adorn* adorn, DataModel* dataModel, Controller::ControllerType type);
	};
}

// INFERRED: Creatable<Instance>::create<ArrowPanel, Adorn*, DataModel*, ControllerType>
// takes three parameters. The header's Creatable only supports up to two, so the
// 0x00602650 instantiation is called directly. It writes the result through the
// hidden pointer and returns that pointer in eax.
extern "C" boost::shared_ptr<RBX::ArrowPanel>* fn_00602650(
	boost::shared_ptr<RBX::ArrowPanel>* ret,
	RBX::Adorn* adorn,
	RBX::DataModel* dataModel,
	int controllerType);

namespace RBX
{
	boost::shared_ptr<TopMenuBar> GuiBuilder::buildControlHud(Adorn* adorn, int offset)
	{
		Layout layout;
		layout.xLocation = Rect::RIGHT;
		layout.yLocation = Rect::TOP;
		layout.offset.y = offset;
		layout.layoutStyle = Layout::VERTICAL;

		boost::shared_ptr<RelativePanel> hud = Creatable<Instance>::create<RelativePanel>(layout);
		hud->setName("ControlHud");

		{
			boost::shared_ptr<ArrowPanel> tmp;
			hud->addGuiItem(*fn_00602650(&tmp, adorn, dataModel, Controller::PRIMARY_CONTROLLER));
		}

		hud->addGuiItem(Creatable<Instance>::create<MenuSpacer>(5.0f, 5.0f));

		{
			boost::shared_ptr<ArrowPanel> tmp;
			hud->addGuiItem(*fn_00602650(&tmp, adorn, dataModel, Controller::SECONDARY_CONTROLLER));
		}

		return hud;
	}
}
