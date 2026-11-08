// 2008-06 native RBX::HealthHud unit (inactive): 00656490..00656940.
// Layout and addresses in native-headers/gui/HealthHud.h; verified by tests/record_native_widget.py.
#include "gui/HealthHud.h"

namespace RBX
{
	HealthHud::HealthHud()
	{
		setGuiSize(G3D::Vector2(10.0f, 100.0f));
	}
}
