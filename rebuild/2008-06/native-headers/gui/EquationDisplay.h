#pragma once
// 2008-06 native RBX::EquationDisplay (inactive). Shape after the donor tools/rbxgs gui/EquationDisplay.h. Read from the
// binary (tests/record_native_widget.py checks it):
//   EquationDisplay  vtable 0084becc .?AVEquationDisplay@RBX@@ -> TextDisplay -> GuiItem. Constructor 00656a50
//                    (const std::string& name, const std::string& equation; ret 8): TextDisplay(name, name) 005744a0,
//                    the 11 vtables, equation +0x188 copy-constructed. Destructor 00656b80 (~std::string, ~TextDisplay
//                    00574630); its evidence extent also covers the deleting destructor 00656bd0 (bounds). getLabel
//                    00656940 (slot 25; not attempted). Size 0x1a4 (006025a0.. allocation).
//                    The donor's three-string constructor has no 2008 evidence and is left out.
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
