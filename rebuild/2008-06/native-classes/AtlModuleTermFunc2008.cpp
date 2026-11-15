// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native AtlModuleTermFunc2008 (inactive): ATL 7.x-style AtlModuleAddTermFunc (004038f0) with a raw critical section, built under MFC (ATLTRY -> CException::Delete).
// INFERRED: hr = S_OK placement between the pNext read and head store reproduces the original codegen; no behavioural difference.
#include <afxwin.h>
#include <atlbase.h>

extern "C" HRESULT __stdcall AtlModuleAddTermFunc70(_ATL_MODULE* pM, _ATL_TERMFUNC* pFunc, DWORD_PTR dw)
{
    if (pM == NULL)
        return E_INVALIDARG;
    HRESULT hr;
    _ATL_TERMFUNC_ELEM* pNew = NULL;
    ATLTRY(pNew = new _ATL_TERMFUNC_ELEM);
    if (pNew == NULL)
        hr = E_OUTOFMEMORY;
    else {
        pNew->pFunc = pFunc;
        pNew->dw = dw;
        EnterCriticalSection(&pM->m_csStaticDataInitAndTypeInfo.m_sec);
        pNew->pNext = pM->m_pTermFuncs;
        hr = S_OK;
        pM->m_pTermFuncs = pNew;
        LeaveCriticalSection(&pM->m_csStaticDataInitAndTypeInfo.m_sec);
    }
    return hr;
}
