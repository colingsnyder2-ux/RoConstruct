#include "gui/WidgetMenuItem.h"

namespace RBX
{
	void MenuItem::render2d(Adorn* adorn)
	{
		if (widgetState == HOVER || widgetState == DOWN_OVER)
			adorn->rect2d(getMyRect2D(), GuiItem::menuSelect());

		bool enabled = isEnabled();
		const G3D::Color4& fontColor = isEnabled() ? GuiItem::menuEnabledFill() : GuiItem::menuDisabledFill();
		label2d(adorn, (getVerb() && getVerb()->isChecked()) ? "x " + getTitle() : getTitle(), fontColor,
				G3D::Color4::clear(), Adorn::XALIGN_LEFT);

		if (accelerator.size() > 0)
			label2d(adorn, accelerator, isEnabled() ? GuiItem::menuEnabledFill() : GuiItem::menuDisabledFill(),
					G3D::Color4::clear(), Adorn::XALIGN_RIGHT);
	}
}

namespace RBX
{
	MenuItem::MenuItem(Verb* verb, const std::string& title)
		: VerbWidget(verb)
	{
		setName(title);
		setGuiSize(G3D::Vector2(200.0f, 24.0f));
	}

	bool MenuItem::canLoseFocus()
	{
		return true;
	}
}
