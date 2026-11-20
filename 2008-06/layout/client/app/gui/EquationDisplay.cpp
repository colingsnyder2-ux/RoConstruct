// 2008-06 native RBX::EquationDisplay unit (inactive): 00656a50..00656bf0.
// Layout and addresses in native-headers/gui/EquationDisplay.h; verified by tests/record_native_widget.py.
#include "gui/EquationDisplay.h"

namespace RBX
{
	EquationDisplay::EquationDisplay(const std::string& name, const std::string& equation)
		: TextDisplay(name, name),
		  equation(equation)
	{
	}
}
