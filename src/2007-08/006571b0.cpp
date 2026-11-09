// from server: 91% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MD
// roc-lib: xtp-11.2.2-vc8-shared-mfc roc_espclaude_a6eed87ecfb3051d.cpp

// Candidate translation unit (score above; library headers required).
// 2007-08 CXTPReportControl::CReportDropTarget::OnDragLeave (older XTP: OnDragOver at vtable 0x1e0)
#include <afxwin.h>
#include <afxole.h>
class CXTPReportControl : public CWnd
{
	DECLARE_DYNAMIC(CXTPReportControl)
public:
	virtual void exePad0();
	virtual void exePad1();
	virtual void exePad2();
	virtual void exePad3();
	virtual void exePad4();
	virtual void exePad5();
	virtual void exePad6();
	virtual void exePad7();
	virtual void exePad8();
	virtual void exePad9();
	virtual void exePad10();
	virtual void exePad11();
	virtual void exePad12();
	virtual void exePad13();
	virtual void exePad14();
	virtual void exePad15();
	virtual void exePad16();
	virtual void exePad17();
	virtual void exePad18();
	virtual void exePad19();
	virtual void exePad20();
	virtual void exePad21();
	virtual void exePad22();
	virtual void exePad23();
	virtual void exePad24();
	virtual void exePad25();
	virtual void exePad26();
	virtual void exePad27();
	virtual void exePad28();
	virtual void exePad29();
	virtual void exePad30();
	virtual void exePad31();
	virtual void exePad32();
	virtual void exePad33();
	virtual void exePad34();
	virtual void exePad35();
	virtual void exePad36();
	virtual void exePad37();
	virtual void exePad38();
	virtual void exePad39();
	virtual void exePad40();
	virtual DROPEFFECT OnDragOver(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point);
	class CReportDropTarget;
};
class CXTPReportControl::CReportDropTarget : public COleDropTarget
{
public:
	virtual void OnDragLeave(CWnd* pWnd);
};
void CXTPReportControl::CReportDropTarget::OnDragLeave(CWnd* pWnd)
	{
		CXTPReportControl* pReport = DYNAMIC_DOWNCAST(CXTPReportControl, pWnd);

		if (pReport)
		{
			pReport->OnDragOver(NULL, 0, CPoint(-1, -1));
		}
	}
