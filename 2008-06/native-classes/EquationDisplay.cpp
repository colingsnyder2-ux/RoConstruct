// 2008-06 native RBX::EquationDisplay unit (inactive): 00656a50..00656bf0.
// Layout and addresses in native-headers/gui/EquationDisplay.h; verified by tests/record_native_widget.py.
// >>> native-status (generated) -- do not edit >>>
// EquationDisplay | 2008-06 | linked
// 1/1 exact by name (100%) | 1/1 exact bodies | no strings | verified 2026-11-07| by king_originala (deepseek:deepseek-flash)
// <<< native-status | src 58fcdfbf | roc native-status --write
#include "gui/EquationDisplay.h"

namespace RBX
{
	EquationDisplay::EquationDisplay(const std::string& name, const std::string& equation)
		: TextDisplay(name, name),
		  equation(equation)
	{
	}
}
