// =============================================================================
// HealthHud.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/gui/HealthHud.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "gui/Gui.h"

struct NativeWidgetLayout;

namespace RBX
{
	class Visit;

	class HealthHud : public GuiItem
	{
	private:
		boost::shared_ptr<Visit> visit;                              // +0x144

	private:
		virtual void render2d(Adorn*);                               // slot 24, 00656690
	public:
		HealthHud();                                                 // 00656490
		friend struct ::NativeWidgetLayout;
	};
}
