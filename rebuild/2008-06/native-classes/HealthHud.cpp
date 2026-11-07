// 2008-06 native RBX::HealthHud unit (inactive): 00656490..00656940.
// Layout and addresses in native-headers/gui/HealthHud.h; verified by tests/record_native_widget.py.
// >>> native-status (generated) -- do not edit >>>
// HealthHud | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 2ea2df9b | roc native-status --write
#include "gui/HealthHud.h"

namespace RBX
{
	HealthHud::HealthHud()
	{
		setGuiSize(G3D::Vector2(10.0f, 100.0f));
	}
}
