// =============================================================================
// ArrowPanel.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/gui/ArrowPanel.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "gui/ArrowPanel.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "util/RunStateOwner.h"

namespace RBX
{
	bool ArrowButton::isEnabled()
	{
		return dataModel->create<RunService>()->getRunState() == RS_RUNNING;
	}

	bool ArrowPanel::isVisible() const
	{
		return dataModel->getWorkspace()->getControllersUsed().hasController(controller);
	}

	void ArrowPanel::init(Adorn* adorn, const std::string& title, const std::string& up, const std::string& down,
						  const std::string& left, const std::string& right, SDLKey upKey, SDLKey downKey, SDLKey leftKey,
						  SDLKey rightKey)
	{
		boost::shared_ptr<TopMenuBar> leftPanel = Creatable<Instance>::create<TopMenuBar>("LeftPanel", Layout::VERTICAL);
		leftPanel->addGuiItem(Creatable<Instance>::create<ImageWidget>(adorn, title));
		leftPanel->addGuiItem(Creatable<Instance>::create<ArrowButton>(adorn, left, leftKey, controller, dataModel));

		boost::shared_ptr<TopMenuBar> forwardBackPanel =
			Creatable<Instance>::create<TopMenuBar>("ForwardBackPanel", Layout::VERTICAL);
		forwardBackPanel->addGuiItem(Creatable<Instance>::create<ArrowButton>(adorn, up, upKey, controller, dataModel));
		forwardBackPanel->addGuiItem(Creatable<Instance>::create<ArrowButton>(adorn, down, downKey, controller, dataModel));

		boost::shared_ptr<TopMenuBar> rightPanel = Creatable<Instance>::create<TopMenuBar>(right, Layout::VERTICAL);
		rightPanel->addGuiItem(Creatable<Instance>::create<MenuSpacer>(32.0f, 32.0f));
		rightPanel->addGuiItem(Creatable<Instance>::create<ArrowButton>(adorn, right, rightKey, controller, dataModel));

		addGuiItem(leftPanel);
		addGuiItem(forwardBackPanel);
		addGuiItem(rightPanel);
	}

#ifdef NATIVE_GUIWIDGETS_PENDING
	ArrowPanel::ArrowPanel(Adorn* adorn, DataModel* dataModel, Controller::ControllerType controller)
		: TopMenuBar("ArrowPanel", Layout::HORIZONTAL)
	{
		this->dataModel = dataModel;
		this->controller = controller;
		switch (controller)
		{
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
#endif

	template boost::shared_ptr<ImageWidget> Creatable<Instance>::create<ImageWidget, Adorn*, std::string>(Adorn*, std::string);
	template boost::shared_ptr<TopMenuBar> Creatable<Instance>::create<TopMenuBar, std::string, Layout::Style>(std::string, Layout::Style);
}

template class boost::shared_ptr<RBX::ImageWidget>;

namespace RBX
{
	G3D::Vector2 ArrowPanel::getSize() const
	{
		if (isVisible())
			return TopMenuBar::getSize();
		else
			return G3D::Vector2::zero();
	}

	ArrowButton::ArrowButton(Adorn* adorn, const std::string& name, SDLKey key, Controller::ControllerType controller,
							 DataModel* dataModel)
		: ImageKeyButton(adorn, name, key),
		  dataModel(dataModel),
		  controller(controller)
	{
	}
}

template class G3D::ReferenceCountedPointer<RBX::TextureProxyBase>;

namespace RBX
{
ArrowPanel::ArrowPanel(Adorn* adorn, DataModel* model, Controller::ControllerType type)
	: TopMenuBar("ArrowPanel", Layout::HORIZONTAL, false)
{
	dataModel = model;
	controller = type;
	switch (type) {
	case Controller::PLAYER_CONTROLLER:
		this->ArrowPanel::init(adorn, "Character", "W_key", "S_key", "A_key", "D_key", SDLK_w, SDLK_s, SDLK_a, SDLK_d);
		break;
	case Controller::PRIMARY_CONTROLLER:
		this->ArrowPanel::init(adorn, "Controller1", "U_key", "J_key", "H_key", "K_key", SDLK_u, SDLK_j, SDLK_h, SDLK_k);
		break;
	case Controller::SECONDARY_CONTROLLER:
		this->ArrowPanel::init(adorn, "Controller2", "W_key", "S_key", "A_key", "D_key", SDLK_w, SDLK_s, SDLK_a, SDLK_d);
		break;
	}
}
}
