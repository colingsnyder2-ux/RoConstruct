// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// The one CRobloxApp object (MFC's AfxGetApp / WinMain find it through its CWinApp base). The Dec 2007 client
// defines it the same way (OpenRBX Client/win/Roblox.cpp: `CRobloxApp theApp;`); 2008 address not mapped yet.
#include "CRobloxApp.h"

CRobloxApp theApp;
