// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 exact CChatPrompt destructor.
#include <afxext.h>
#include "CChatPrompt.h"
#include "ChatEnter.h"
#include "v8datamodel/DataModel.h"

CChatPrompt::~CChatPrompt()
{
	bind(NULL, NULL);
}
