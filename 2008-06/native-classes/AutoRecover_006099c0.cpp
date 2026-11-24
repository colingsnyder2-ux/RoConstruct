// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/PVInstance.h"

namespace RBX
{
	void PVInstance::setControllerType(Controller::ControllerType _control)
	{
		if (controllerType != _control) {
			controllerType = _control;

			onChildControllerChanged();
			onParentControllerChanged();

			raisePropertyChanged(prop_ControllerType);
		}
	}
}
