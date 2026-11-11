#pragma once
// >>> native-status (generated) -- do not edit >>>
// HealthHud | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 9db5cbce | roc native-status --write
// 2008-06 native RBX::HealthHud (inactive). Shape after the donor tools/rbxgs gui/HealthHud.h. Read from the binary
// (tests/record_native_widget.py checks it):
//   HealthHud  vtable 0084bdcc .?AVHealthHud@RBX@@ -> GuiItem -> Instance (+ GuiTarget +0x130). Constructor 00656490:
//              GuiItem() 005739d0, the 11 vtables, visit (+0x144/+0x148, boost::shared_ptr) empty, guiSize (+0x13c) =
//              (10.0f 00827490, 100.0f 008163a4). Size 0x14c (00602414 allocates 0x14c). Destructor 006565a0 (release
//              visit, ~GuiItem 00411540), deleting destructor 00656620. render2d 00656690 (slot 24; fills visit from
//              ServiceProvider::find<Visit> 00656640 and draws the local Humanoid's health; not attempted).
//              .?AVVisit@RBX@@ is in the binary's RTTI.
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
		virtual void render2d(Adorn*);                               // slot 24, 00656690 (not attempted)
	public:
		HealthHud();                                                 // 00656490
		friend struct ::NativeWidgetLayout;
	};
}
