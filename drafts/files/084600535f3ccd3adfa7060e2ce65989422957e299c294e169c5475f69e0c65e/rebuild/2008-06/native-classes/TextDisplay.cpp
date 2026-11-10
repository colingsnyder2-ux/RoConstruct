// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /DNOMINMAX
// 2008-06 native RBX::TextDisplay unit (inactive): 005735e0..00574699.
// Layout, member offsets and addresses in native-headers/gui/Gui.h (class TextDisplay, declared after
// UnifiedWidget). Verified by rebuild/2008-06/tests/native_check_runner.py against the batch
// work/2008-06/shared-layouts/text-display-batch.json: init 005735e0, render2d 00573670, ctor 005744a0,
// getFontSize 00574570, getLabel 00574580, ~TextDisplay 00574630, scalar deleting destructor 00574680 and
// the eight subobject deleting-destructor thunks 005745b0..00574620.
#include "gui/Gui.h"

namespace RBX
{
	void TextDisplay::init()
	{
		setGuiSize(G3D::Vector2(180.0f, 30.0f));
		fontSize = 18;
		fontColor = G3D::Color4(G3D::Color3::purple());
		borderColor = G3D::Color4::clear();
		align = Adorn::XALIGN_LEFT;
	}

	TextDisplay::TextDisplay(const std::string& name, const std::string& label)
	{
		init();
		setName(name);
		this->label = label;
	}

	int TextDisplay::getFontSize() const
	{
		return fontSize;
	}

	std::string TextDisplay::getLabel() const
	{
		return label;
	}

	void TextDisplay::render2d(Adorn* adorn)
	{
		label2d(adorn, getLabel(), fontColor, borderColor, align);
	}
}
