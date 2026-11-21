// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_0045b0d0 (placeholder name for 0045b0d0 from the identity tier): when the main frame's stateF8 (fullscreen) flag is set, posts ID 0x80f4 (toggle fullscreen); body byte-proved
#include "../native-headers/CMainFrame.h"

void sub_0045b0d0()
{
	CMainFrame* frame = static_cast<CMainFrame*>(AfxGetApp()->m_pMainWnd);
	if (frame->stateF8)
		frame->PostMessage(WM_COMMAND, 0x80f4);
}
