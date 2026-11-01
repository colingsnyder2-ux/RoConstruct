#include <afxwin.h>
#include <afxole.h>
#include <afxcmn.h>
#include <afxext.h>
#include <afxmt.h>
#include <XTToolkitPro.h>
BOOL CXTPCommandBar::SetPopuped(int nPopuped, BOOL bKeyboard)
{
	if (m_nPopuped == nPopuped)
		return FALSE;

	if (m_nPopuped != -1)
	{
		CXTPControl* pControl = GetControl(m_nPopuped);
		m_nPopuped = -1;
		pControl->OnSetPopup(FALSE);
	}

	if (nPopuped != -1)
	{
		CXTPControl* pControl = GetControl(nPopuped);
		if (!pControl || !pControl->GetEnabled())
		{
			return FALSE;
		}

		m_nPopuped = nPopuped;
		SetTrackingMode(TRUE_POPUP, FALSE, bKeyboard);
		SetSelected(nPopuped, bKeyboard);

		if (!pControl->OnSetPopup(TRUE))
		{
			m_nPopuped = -1;
			return FALSE;
		}

		CXTPCommandBars* pCommandBars = GetCommandBars();
		if (pCommandBars && pCommandBars->GetCommandBarsOptions()->bShowFullAfterDelay && m_hWnd)
		{
			SetTimer(XTP_TID_EXPANDED_POPUP, s_nExpandDelay, NULL);
		}

	}

	return TRUE;
}
