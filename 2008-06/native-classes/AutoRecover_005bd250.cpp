// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/Sound.h"

// INFERRED: the vtable stores come from the compiler. The trailing call through the
// global at 0x973e8c (vtable slot 3, args this+0x14 and &bool) is read here as
// propArchivable.setValue(this, false), following the 2007 analog.
StockSound::StockSound()
{
	propArchivable.setValue(this, false);
}
