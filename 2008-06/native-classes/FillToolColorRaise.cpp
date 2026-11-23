// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// 2008-06 native Notifier<FillToolColor, BrickColor>::raise(event, listener) of the CMainFrame translation unit
// (inactive). Flags: the CMainFrame*.cpp document profile with std-noinline-string: the CMainFrame-unit copy
// 004305f0 calls the MSVCP90 c_str import inside its catch, where an inline-string build matches only the World
// AutoJoin COMDAT twin 005e95c0 (moved here from NotifierRaiseTemplatesB2008.cpp).
//   004305f0 (registry placeholder func_004305f0, 176 B, ret 8): the read-only util/Events.h raise(event, listener)
//   body (listener->onEvent(this, event) in try; catch std::exception -> StandardOut "Exception caught in onEvent. %s"
//   0080b9c4); its caller is raise(BrickColor) 00430e10.
#include "v8datamodel/ToolsPart.h"

namespace RBX
{
	template void Notifier<FillToolColor, BrickColor>::raise(BrickColor, Listener<FillToolColor, BrickColor>*) const;
}
