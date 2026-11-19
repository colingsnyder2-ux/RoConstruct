#include "gui/EquationDisplay.h"

namespace RBX
{
	EquationDisplay::EquationDisplay(const std::string& name, const std::string& equation)
		: TextDisplay(name, name),
		  equation(equation)
	{
	}
}
