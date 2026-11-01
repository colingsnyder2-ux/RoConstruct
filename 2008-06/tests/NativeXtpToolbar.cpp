#include <afxwin.h>
#include <afxole.h>
#include <afxcmn.h>
#include <afxext.h>
#include <afxmt.h>
#include <XTToolkitPro.h>
// Existing XTPToolBar.cpp body, compiled separately for verification.
void CXTPToolBar::EnableDocking(DWORD flags) { ASSERT(m_pCommandBars); m_dwFlags = flags; }
