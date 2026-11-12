// from server: 100% by EspClaude
// from server: 53% by Intel
// from server: 48% by espeon_1
// roc-lang: cpp
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: boost-1.34.1 roc_claude_b2f202f089de4a52.cpp

// Candidate translation unit (score above; library headers required).
// 0x00467c40: CComObject<CWorkspace> vtable slot 14 (RTTI .?AV?$CComObject@VCWorkspace@@@ATL@@, COL offset 0):
// a COM method (stdcall, ret 4) doing AFX_MANAGE_STATE(AfxGetStaticModuleState()) and calling the
// member at 0x467470 on this, returning S_OK. MFC 8.0 declarations below are copied from
// atlmfc/include afxstat_.h / afxwin1.inl / afxcomctl32.h (_AFXDLL layout: prev state +0,
// thread state +4, cookie +8, valid flag +0xc; _AFX_THREAD_STATE::m_pModuleState at +4).
#ifndef _DLL
#define _DLL
#endif
#ifndef _MT
#define _MT
#endif
#ifndef _CPPUNWIND
#define _CPPUNWIND
#endif
#include <windows.h>

#define AFXAPI __stdcall

class AFX_MODULE_STATE;

class CNoTrackObject
{
public:
	virtual ~CNoTrackObject() { }
};

class _AFX_THREAD_STATE : public CNoTrackObject
{
public:
	_AFX_THREAD_STATE();
	virtual ~_AFX_THREAD_STATE();

	// override for m_pModuleState in _AFX_APP_STATE
	AFX_MODULE_STATE* m_pModuleState;
	AFX_MODULE_STATE* m_pPrevModuleState;
};

AFX_MODULE_STATE* AFXAPI AfxGetStaticModuleState();
BOOL AFXAPI AfxDeactivateActCtx(DWORD dwFlags, ULONG_PTR ulCookie);

struct AFX_MAINTAIN_STATE2
{
	explicit AFX_MAINTAIN_STATE2(AFX_MODULE_STATE* pModuleState) throw();
	~AFX_MAINTAIN_STATE2();

protected:
	AFX_MODULE_STATE* m_pPrevModuleState;
	_AFX_THREAD_STATE* m_pThreadState;

	ULONG_PTR m_ulActCtxCookie;
	BOOL m_bValidActCtxCookie;
};

inline AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2()
{
	// Not a good place to report errors here, so just be safe
	if(m_pThreadState)
	{
		m_pThreadState->m_pModuleState = m_pPrevModuleState;
	}

	if (m_bValidActCtxCookie)
	{
		BOOL bRet;
		bRet = AfxDeactivateActCtx(0, m_ulActCtxCookie);
	}
}

class CWorkspace
{
public:
	HRESULT __stdcall Method14();
	void func();
};

HRESULT __stdcall CWorkspace::Method14()
{
	AFX_MAINTAIN_STATE2 _ctlState(AfxGetStaticModuleState());
	func();
	return S_OK;
}
