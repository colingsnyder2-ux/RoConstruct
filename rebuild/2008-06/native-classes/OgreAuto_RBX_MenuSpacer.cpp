// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../native-headers/gui/Gui.h"

namespace RBX {
MenuSpacer::MenuSpacer(float a, float b)
{
	setGuiSize(G3D::Vector2(a, b));
}
}
