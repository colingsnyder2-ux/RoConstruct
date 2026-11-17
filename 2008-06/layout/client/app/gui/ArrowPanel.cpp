// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 2008-06 native RBX::ArrowPanel / RBX::ArrowButton unit (inactive): 00656bf0..00657c00.
// Layout and addresses in native-headers/gui/ArrowPanel.h; verified by tests/record_native_widget.py.
#include "gui/ArrowPanel.h"

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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class G3D::ReferenceCountedPointer<RBX::TextureProxyBase>;

namespace RBX {
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

