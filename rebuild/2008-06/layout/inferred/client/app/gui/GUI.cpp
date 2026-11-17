#include "gui/Gui.h"
#include "util/Name.h"

namespace RBX {

void __thiscall UnifiedWidget::setMenuState(UnifiedWidget::MenuState state)
{
	if (menuState != state)
	{
		menuState = state;
		onMenuStateChanged();
	}
}

}

namespace RBX
{
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
