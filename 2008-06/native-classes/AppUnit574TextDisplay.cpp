// 2008-06 native TextDisplay members of the gui/GUI.cpp translation unit (00573130..00574f0c), inactive. Verified by
// tests/record_native_app_unit574.py against the committed gui/Gui.h (read-only; layout cited there):
//   * TextDisplay(const std::string& name, const std::string& label) 005744a0: GuiItem() 005739d0, the TextDisplay
//     vtables 0082fce4.. (RTTI .?AVTextDisplay@RBX@@), label +0x144, init() 005735e0, setName(name) 0055af90, then
//     label = text;
//   * getFontSize() const 00574570 (fontSize +0x160) and getLabel() const 00574580 (copy of label +0x144);
//   * the implicit ~TextDisplay 00574630, its ??_G 00574680 and the ??_E adjustor thunks 005745b0..00574620 that the
//     constructor's vtables reference.
#include "gui/Gui.h"

namespace RBX
{
	TextDisplay::TextDisplay(const std::string& name, const std::string& text)
	{
		init();
		setName(name);
		label = text;
	}

	int TextDisplay::getFontSize() const
	{
		return fontSize;
	}

	std::string TextDisplay::getLabel() const
	{
		return label;
	}
}
