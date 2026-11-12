#include "gui/ArrowPanel.h"

#include "gui/Button.h"
#include "util/RunStateOwner.h"
#include "util/object.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8tree/Service.h"

namespace RBX {

// SIZE 0x158
// PORT: ArrowButton is already declared in the 2008 header.

// PORT: donor-only size annotation omitted.

// FUNCTION: ROBLOX 0x0065f910
G3D::Vector2 ArrowPanel::getSize() const
{
	if (isVisible()) {
		return TopMenuBar::getSize();
	}

	return G3D::Vector2::zero();
}

// FUNCTION: ROBLOX 0x0065fad0
bool ArrowPanel::isVisible() const
{
	return dataModel->getWorkspace()->getControllersUsed().hasController(controller);
}

// FUNCTION: ROBLOX 0x0065fdc0
ArrowButton::ArrowButton(
	Adorn* adorn, const std::string& image, SDLKey key, Controller::ControllerType controller, DataModel* dataModel
)
	: ImageKeyButton(adorn, image, key), dataModel(dataModel), controller(controller)
{
}

// FUNCTION: ROBLOX 0x0065ff20
void ArrowPanel::init(
	Adorn* adorn,
	const std::string& image,
	const std::string& forward,
	const std::string& backward,
	const std::string& left,
	const std::string& right,
	SDLKey forwardKey,
	SDLKey backwardKey,
	SDLKey leftKey,
	SDLKey rightKey
)
{
	boost::shared_ptr<TopMenuBar> leftPanel = Creatable<Instance>::create<TopMenuBar>("LeftPanel", Layout::VERTICAL);
	leftPanel->addGuiItem(Creatable<Instance>::create<ImageWidget>(adorn, image));
	leftPanel->addGuiItem(Creatable<Instance>::create<ArrowButton>(adorn, left, leftKey, controller, dataModel));

	boost::shared_ptr<TopMenuBar> forwardBackPanel =
		Creatable<Instance>::create<TopMenuBar>("ForwardBackPanel", Layout::VERTICAL);
	forwardBackPanel->addGuiItem(
		Creatable<Instance>::create<ArrowButton>(adorn, forward, forwardKey, controller, dataModel)
	);
	forwardBackPanel->addGuiItem(
		Creatable<Instance>::create<ArrowButton>(adorn, backward, backwardKey, controller, dataModel)
	);

	boost::shared_ptr<TopMenuBar> rightPanel = Creatable<Instance>::create<TopMenuBar>(right, Layout::VERTICAL);
	rightPanel->addGuiItem(Creatable<Instance>::create<MenuSpacer>(32.0f, 32.0f));
	rightPanel->addGuiItem(Creatable<Instance>::create<ArrowButton>(adorn, right, rightKey, controller, dataModel));

	addGuiItem(leftPanel);
	addGuiItem(forwardBackPanel);
	addGuiItem(rightPanel);
}

// FUNCTION: ROBLOX 0x00660460
ArrowPanel::ArrowPanel(Adorn* adorn, DataModel* dataModel, Controller::ControllerType controller)
	: TopMenuBar("ArrowPanel", Layout::HORIZONTAL, false), dataModel(dataModel), controller(controller)
{
	switch (controller) {
	case Controller::PLAYER_CONTROLLER:
		init(adorn, "Character", "W_key", "S_key", "A_key", "D_key", SDLK_w, SDLK_s, SDLK_a, SDLK_d);
		break;
	case Controller::PRIMARY_CONTROLLER:
		init(adorn, "Controller1", "U_key", "J_key", "H_key", "K_key", SDLK_u, SDLK_j, SDLK_h, SDLK_k);
		break;
	case Controller::SECONDARY_CONTROLLER:
		init(adorn, "Controller2", "W_key", "S_key", "A_key", "D_key", SDLK_w, SDLK_s, SDLK_a, SDLK_d);
		break;
	}
}

// FUNCTION: ROBLOX 0x006608d0
bool ArrowButton::isEnabled()
{
	return dataModel->create<RunService>()->getRunState() == RS_RUNNING;
}

} // namespace RBX
