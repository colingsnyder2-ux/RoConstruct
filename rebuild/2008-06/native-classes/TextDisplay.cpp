// >>> native-status (generated) -- do not edit >>>
// TextDisplay | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 338e0edf | roc native-status --write
#include "gui/Gui.h"

namespace RBX
{
	// Independently verified against 2008-06 address 00574570; inactive provider.
	int TextDisplay::getFontSize() const
	{
		return fontSize;
	}
}

namespace RBX {
std::string TextDisplay::getLabel() const
{
	return label;
}
}

// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
namespace RBX {
void TextDisplay::render2d(Adorn* adorn)
	{
		label2d(adorn, getLabel(), fontColor, borderColor, align);
	}
}

namespace RBX {
__declspec(noinline) void TextDisplay::init()
	{
		setGuiSize(G3D::Vector2(180.0f, 30.0f));
		fontSize = 18;
		fontColor = G3D::Color3::purple();
		borderColor = G3D::Color4::zero();
		align = Adorn::XALIGN_LEFT;
	}
}

namespace RBX {
TextDisplay::TextDisplay(const std::string& name, const std::string& text)
	{
		init();
		setName(name);
		label = text;
	}
}
