// from server: 87% by EspClaude
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /MD
// roc-lib: xtp-13.2.1 roc_espclaude_0be4b2c57f2d17c7.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _DLL
#define _DLL
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <afxwin.h>
#include <afxcomctl32.h>
BOOL (CComCtlWrapper::*g_pfGetImageInfo)(HIMAGELIST,int,IMAGEINFO*) = &CComCtlWrapper::_ImageList_GetImageInfo;
