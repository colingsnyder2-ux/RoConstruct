// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: mfc-9.0-shared-rtm roc_unit_38a66487c88049f6.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#define _AFXDLL
#include <afxwin.h>
#include <atlbase.h>
using namespace ATL;
HRESULT __stdcall addTermDirect(_ATL_MODULE* pModule, _ATL_TERMFUNC* pFunc, DWORD_PTR dw)
{
	if (pModule == NULL)
		return E_INVALIDARG;
	HRESULT hr = S_OK;
	_ATL_TERMFUNC_ELEM* pNew = NULL;
	ATLTRY(pNew = new _ATL_TERMFUNC_ELEM);
	if (pNew == NULL)
		hr = E_OUTOFMEMORY;
	else
	{
		pNew->pFunc = pFunc;
		pNew->dw = dw;
		hr = pModule->m_csStaticDataInitAndTypeInfo.Lock();
		if (SUCCEEDED(hr))
		{
			pNew->pNext = pModule->m_pTermFuncs;
			pModule->m_pTermFuncs = pNew;
			pModule->m_csStaticDataInitAndTypeInfo.Unlock();
		}
		else
			delete pNew;
	}
	return hr;
}
HRESULT __stdcall addTermScoped(_ATL_MODULE* pModule, _ATL_TERMFUNC* pFunc, DWORD_PTR dw)
{
	if (pModule == NULL)
		return E_INVALIDARG;
	HRESULT hr = S_OK;
	_ATL_TERMFUNC_ELEM* pNew = NULL;
	ATLTRY(pNew = new _ATL_TERMFUNC_ELEM);
	if (pNew == NULL)
		return E_OUTOFMEMORY;
	pNew->pFunc = pFunc;
	pNew->dw = dw;
	{
		CComCritSecLock<CComCriticalSection> lock(pModule->m_csStaticDataInitAndTypeInfo, false);
		hr = lock.Lock();
		if (SUCCEEDED(hr))
		{
			pNew->pNext = pModule->m_pTermFuncs;
			pModule->m_pTermFuncs = pNew;
		}
		else
			delete pNew;
	}
	return hr;
}
