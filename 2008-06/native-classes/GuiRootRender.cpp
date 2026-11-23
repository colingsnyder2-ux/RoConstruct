// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::GuiRoot::render2d (placeholder func_00573c00, 167 B, `ret 4`), inactive; the GUI.cpp unit range
// beside GuiRoot() 00573b10. Identity: slot 24 of the GuiRoot vtable 0082f9fc (RTTI .?AVGuiRoot@RBX@@). Body: Adorn
// getHeight (+0x18) / getWidth (+0x14) through Vector2int16 into the GuiRoot::canvasSize static 00974d78 / 00974d7c
// (setCanvasSize has no out-of-line copy), then for each child (numChildren 0048ae20, children +0x108)
// dynamic_cast<GuiItem*> and the render2d slot (+0x60). Statement shape of the 2007 analog (gui/GUI.cpp); flags from
// the sibling gui unit GuiPanels.cpp without its widget-rect profile (no Rect use here).
#include "gui/Gui.h"
#include "RbxGraphics/Adorn.h"

namespace RBX
{
	// INFERRED: setCanvasSize is inline in the 2008 header (stores at 00573c3a / 00573c40, no out-of-line copy); the
	// read-only gui/Gui.h only declares it. Proposal: make it inline there.
	inline void GuiRoot::setCanvasSize(const G3D::Vector2& size)
	{
		canvasSize = size;
	}

	// 00573c00
	void GuiRoot::render2d(Adorn* adorn)
	{
		setCanvasSize(G3D::Vector2(G3D::Vector2int16(adorn->getWidth(), adorn->getHeight())));

		for (unsigned int i = 0; i < numChildren(); ++i)
		{
			Instance* instance = getChild(i);   // native Instance.h: (*children)[i].get()
			GuiItem* item = dynamic_cast<GuiItem*>(instance);

			if (item != NULL)
				item->render2d(adorn);
		}
	}
}
