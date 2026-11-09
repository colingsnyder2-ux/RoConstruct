// 2008-06 native RBX::ArrowPanel / RBX::ArrowButton unit (inactive): 00656bf0..00657c00.
// Layout and addresses in native-headers/gui/ArrowPanel.h; verified by tests/record_native_widget.py.
#include "gui/ArrowPanel.h"
#include "v8datamodel/DataModel.h"
#include "util/RunStateOwner.h"

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
	bool ArrowButton::isEnabled()
	{
		return dataModel->create<RunService>()->getRunState() == RS_RUNNING;
	}
}
