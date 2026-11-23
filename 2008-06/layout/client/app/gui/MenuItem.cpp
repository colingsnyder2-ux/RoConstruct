// =============================================================================
// MenuItem.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/gui/MenuItem.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
