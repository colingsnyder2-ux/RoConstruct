// 2008-06 native RBX::HealthHud unit (inactive): 00656490..00656940.
// Layout and addresses in native-headers/gui/HealthHud.h; verified by tests/record_native_widget.py.
// >>> native-status (generated) -- do not edit >>>
// HealthHud | 2008-06 | linked
// 1/1 exact by name (100%) | 1/1 exact bodies | no strings | verified 2026-11-07| by EspClaude (roc repair)
// <<< native-status | src 2ea2df9b | roc native-status --write
#include "gui/HealthHud.h"

namespace RBX
{
	HealthHud::HealthHud()
	{
		setGuiSize(G3D::Vector2(10.0f, 100.0f));
	}
}
