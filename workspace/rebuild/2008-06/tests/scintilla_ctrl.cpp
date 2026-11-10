// Scintilla module test: the MFC wrapper links and a control object constructs and destructs.
#include <afxwin.h>
#include <afxext.h>
#include <afxcmn.h>
#include <afxpriv.h>
#include "Platform.h"
#include "Scintilla.h"
#include "SciLexer.h"
#include "ScintillaCtrl.h"
#include <stdio.h>

int main()
{
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
		return 2;
	CScintillaCtrl* ctrl = new CScintillaCtrl;
	printf("scintilla ctrl %s\n", ctrl->GetSafeHwnd() == NULL ? "unattached" : "attached");
	delete ctrl;
	return 0;
}
