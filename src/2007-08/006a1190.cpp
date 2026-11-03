// from server: 95% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-11.2.2-vc8-shared-mfc roc_espclaude_76e8a05d1aa4f57f.cpp

// Candidate translation unit (score above; library headers required).
// 2007-08 CXTPDockBar::OnPrintClient: older XTP also prints visible children (PRF_CHILDREN).
#include "stdafx.h"
LRESULT CXTPDockBar::OnPrintClient(WPARAM wParam, LPARAM lParam)
{
	CDC* pDC = CDC::FromHandle((HDC)wParam);
	if (pDC)
	{
		m_pCommandBars->GetPaintManager()->FillDockBar(pDC, this);

		if (lParam & PRF_CHILDREN)
		{
			CWnd* pWnd = GetWindow(GW_CHILD);
			while (pWnd)
			{
				if (pWnd->IsWindowVisible())
				{
					CRect rc;
					GetWindowRect(&rc);
					pWnd->ScreenToClient(&rc);
					pDC->SetViewportOrg(-rc.left, -rc.top);
					pWnd->SendMessage(WM_PRINT, (WPARAM)pDC->m_hDC, lParam);
				}
				pWnd = pWnd->GetWindow(GW_HWNDNEXT);
			}
		}
	}

	return TRUE;
}
