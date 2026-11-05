// XTP module test: the colour manager (XTPColorManager.cpp) answers system colours after MFC is initialised.
#include <afxwin.h>
#include <XTToolkitPro.h>
#include <stdio.h>

int main()
{
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
		return 2;
	COLORREF window = XTPColorManager()->GetColor(COLOR_WINDOW);
	printf("xtp window colour %06x\n", (unsigned)window);
	return window == ::GetSysColor(COLOR_WINDOW) ? 0 : 1;
}
