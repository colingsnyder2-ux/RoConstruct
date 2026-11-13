// 2008-06 native RBX::ArrowPanel / RBX::ArrowButton unit (inactive): 00656bf0..00657c00.
// Layout and addresses in native-headers/gui/ArrowPanel.h; verified by tests/record_native_widget.py.
// >>> native-status (generated) -- do not edit >>>
// ArrowPanel | 2008-06 | 2 byte-exact, inactive (not link-selected)
// 2/4 mapped addresses byte-exact | 2 unproved | no mapped strings | by colin (+2) (mixed 3)
// <<< native-status | src 6a0f45d9 | roc native-status --write
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
