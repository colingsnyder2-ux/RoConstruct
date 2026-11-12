// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// TextDisplay::getFontSize (00574570) - native 2008-06.
// Independently verified against 2008-06 address 00574570.
// >>> native-status (generated) -- do not edit >>>
// TextDisplay | 2008-06 | draft (byte proof at 00574570)
// 1/1 mapped addresses byte-exact | no mapped strings | by colin
// <<< native-status | src 90141bbd | roc native-status --write
#include "gui/Gui.h"

namespace RBX
{
	int TextDisplay::getFontSize() const
	{
		return fontSize;
	}
}
