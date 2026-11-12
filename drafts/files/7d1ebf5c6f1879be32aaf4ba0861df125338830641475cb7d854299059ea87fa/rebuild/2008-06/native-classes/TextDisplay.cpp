// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// TextDisplay | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 90141bbd | roc native-status --write
#include "gui/Gui.h"

namespace RBX
{
	// 005735e0: original GUI dimensions, font, colors and left alignment.
	__declspec(noinline) void TextDisplay::init()
	{
		setGuiSize(G3D::Vector2(180.0f, 30.0f));
		fontSize = 18;
		fontColor = G3D::Color3::purple();
		borderColor = G3D::Color4::zero();
		align = Adorn::XALIGN_LEFT;
	}

	// 005744a0: the label is default-constructed before init, then assigned.
	TextDisplay::TextDisplay(const std::string& name, const std::string& text)
	{
		init();
		setName(name);
		label = text;
	}

	// 00574580: copy the retained label string at +0x144.
	std::string TextDisplay::getLabel() const
	{
		return label;
	}

	// 00573670: getLabel is virtual; label2d owns the placement and font query.
	void TextDisplay::render2d(Adorn* adorn)
	{
		label2d(adorn, getLabel(), fontColor, borderColor, align);
	}

	// Independently verified against 2008-06 address 00574570; inactive provider.
	int TextDisplay::getFontSize() const
	{
		return fontSize;
	}
}
