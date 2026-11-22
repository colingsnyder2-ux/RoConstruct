// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/widget-rect-2008
// 2008-06 native RelativePanel / PercentPanel and Rect positioning helpers (inactive). TopMenuBar::render2d 00574050
// moved to UnifiedWidgetLayout.cpp (the original GUI.cpp unit beside GuiItem::getMyRect 00573310).
// Layouts: native-headers/gui/Gui.h (TopMenuBar backdropColor +0x144, layoutStyle +0x154; RelativePanel xLocation
// +0x15c, yLocation +0x160, offset +0x164; PercentPanel position +0x164) and util/Rect.h. GuiTarget::process 005732d0
// and TopMenuBar::isVisible 00573e00 are inline in-class bodies already (gui/GuiEvent.h, gui/Gui.h).
#include "gui/Gui.h"

namespace RBX
{
	// 00573480: setName("RelativePanel") through the Instance vtable, then the Layout fields in this order.
	void RelativePanel::init(const Layout& layout)
	{
		setName("RelativePanel");
		layoutStyle = layout.layoutStyle;
		backdropColor = layout.backdropColor;
		xLocation = layout.xLocation;
		yLocation = layout.yLocation;
		offset = layout.offset;
	}

	// 005737e0: canvas Rect(GuiRoot::canvasSize) inset by offset, positionChild 005cef60 of Rect(getSize()).
	// PARKED (225 of 241 bytes): the original copies the canvasSize temporary into canvas.high before getSize and
	// reads the inset from that copy; this build forwards the temporary. Tried: the chained inset(...).positionChild
	// expression, the two-argument Rect(Vector2::zero(), size) form (identical code), and insetting before getSize.
	G3D::Vector2 RelativePanel::getPosition() const
	{
		Rect canvas(GuiRoot::getCanvasSize());
		Rect me(getSize());
		canvas = canvas.inset(offset);
		return canvas.positionChild(me, xLocation, yLocation).low;
	}

	// 005738e0: GuiRoot::toPixelSize 005736f0 of position, then Rect::positionPoint 005cef00.
	G3D::Vector2 PercentPanel::getPosition() const
	{
		Rect canvas(GuiRoot::getCanvasSize());
		G3D::Vector2 pixelPosition = GuiRoot::toPixelSize(position);
		return canvas.positionPoint(pixelPosition, xLocation, yLocation);
	}
	// Rect::positionPoint 005cef00 / positionChild 005cef60 live in RectPositioning.cpp (their own original unit).
}

namespace RBX {
PercentPanel::PercentPanel(Rect::Location xLoc, Rect::Location yLoc, const G3D::Vector2 pos)
	: TopMenuBar(), xLocation(xLoc), yLocation(yLoc), position(pos)
{
}
}

