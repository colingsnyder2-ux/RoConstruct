// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::BackpackItem::render2d 005d05d0 (inactive), a row of the Hopper unit (class in the read-only
// native v8datamodel/Hopper.h: guiImageDraw +0x148, textureId +0x180; Widget::widgetState +0x144).
// Evidence (original 005d05d0, 830 bytes):
//   ServiceProvider::find<Workspace>(this) 00491e50; when it is set and its int at +0x43c (the native Workspace.h
//   imageServerViewHack, after the five CodeProfiler scoped_ptrs at +0x428..+0x438) is non-zero, the item fills the
//   canvas (Rect(GuiRoot::canvasSize 00974d78), low = Vector2::zero 00509ba0) and the backdrop is skipped; otherwise
//   getMyRect 00573310. GuiRoot::normalizedFontSize(12) 00573770; the number square is fromLowSize(low.x + 2,
//   high.y - 2 - side) with side = size().x * 0.2f (008249f8), as in LocalBackpackItem::render2d 005fb900.
//   Unless hacked: rect2d (Adorn slot 0x2c) of the item with translucentBackdrop 00573290. When isEnabled (slot 0x78):
//   rect2d of the number square in Color3::gray (00514a20, ICF with Vector3::minFinite), then drawFont2D (slot 0x34) of
//   StringConverter<int>::convertToString 005bdef0 of getParent()->findChildIndex(this) + 1 (00558ac0 on parent +0x104,
//   -1 without a parent) at the square centre, Color4(Color3::white 00514a60), Color4::clear 007baf10, XALIGN_CENTER,
//   YALIGN_CENTER, PROPORTIONAL_SPACING. drawSelected (slot 0x80) -> outlineRect2d (slot 0x28) 3.0f (0081e380)
//   Color3::green 005148e0. guiImageDraw.setImage(adorn, textureId) 00642750 -> GuiDrawImage::render2d 00642de0 with
//   isEnabled() || hacked and the rect inset by the font size; else Widget::render2d 00642520.
// PENDING: Instance::findChildIndex(const Instance*) const (00558ac0) is not declared by the core native
// v8tree/Instance.h (same blocker and proposal as LocalBackpackItem::render2d in LocalBackpack2008.cpp), so the body
// builds only with NATIVE_BACKPACK_ITEM_PENDING against a header carrying that declaration.
#include "v8datamodel/Hopper.h"
#include "v8datamodel/Workspace.h"
#include "util/Utilities.h"

namespace RBX
{
#ifdef NATIVE_BACKPACK_ITEM_PENDING
	// 005d05d0. PARKED: a trial build with the findChildIndex declaration gave 840 of 830 bytes with the same calls,
	// branches and arithmetic; only the frame (0x8c vs 0x84) and the slots of rect / the getMyRect temporary differ
	// (tried the ternary with the flag set inside it and the flag set by a separate if: identical code).
	void BackpackItem::render2d(Adorn* adorn)
	{
		bool imageServerViewHack = false;
		Workspace* workspace = ServiceProvider::find<Workspace>(this);
		if (workspace && workspace->imageServerViewHack)
			imageServerViewHack = true;
		Rect rect = imageServerViewHack ? Rect(GuiRoot::getCanvasSize()) : getMyRect();

		int fontSize = GuiRoot::normalizedFontSize(12);
		float side = rect.size().x * 0.2f;
		Rect numberRect = Rect::fromLowSize(G3D::Vector2(rect.low.x + 2.0f, rect.high.y - 2.0f - side), G3D::Vector2(side, side));

		if (!imageServerViewHack)
			adorn->rect2d(rect.toRect2D(), translucentBackdrop());

		if (isEnabled())
		{
			adorn->rect2d(numberRect.toRect2D(), G3D::Color3::gray());
			G3D::Color4 fontColor(G3D::Color3::white());
			int number = getParent()->findChildIndex(this) + 1;
			adorn->drawFont2D(StringConverter<int>::convertToString(number), numberRect.center(), fontSize, fontColor,
							  G3D::Color4::clear(), Adorn::XALIGN_CENTER, Adorn::YALIGN_CENTER, Adorn::PROPORTIONAL_SPACING);
		}

		if (drawSelected())
			adorn->outlineRect2d(rect.toRect2D(), 3.0f, G3D::Color3::green());

		if (guiImageDraw.setImage(adorn, textureId))
		{
			Rect imageRect(rect.low.x + fontSize, rect.low.y + fontSize, rect.high.x - fontSize, rect.high.y - fontSize);
			guiImageDraw.render2d(adorn, isEnabled() || imageServerViewHack, imageRect, widgetState);
		}
		else
		{
			Widget::render2d(adorn);
		}
	}
#endif
}
