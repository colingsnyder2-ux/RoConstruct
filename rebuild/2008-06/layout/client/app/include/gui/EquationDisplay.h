#pragma once
#include "gui/Gui.h"

struct NativeWidgetLayout;

namespace RBX
{
	class EquationDisplay : public TextDisplay
	{
	private:
		std::string equation;                                        // +0x188

	protected:
		virtual std::string getLabel() const;                        // slot 25, 00656940 (not attempted)
	public:
		EquationDisplay(const std::string&, const std::string&);     // 00656a50
		friend struct ::NativeWidgetLayout;
	};
}
