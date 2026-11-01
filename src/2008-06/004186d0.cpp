// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: mfc-9.0-shared-rtm roc_unit_5826c6564e5bbc0e.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#define _AFXDLL
#include <afxwin.h>
#include <atlbase.h>
#include <atlcom.h>
using namespace ATL;
struct __declspec(uuid("6E9B6B4E-0000-0000-0000-000000000001")) IRocFirst : IUnknown { virtual HRESULT __stdcall first() = 0; };
struct __declspec(uuid("6E9B6B4E-0000-0000-0000-000000000002")) IRocSecond : IUnknown { virtual HRESULT __stdcall second() = 0; };
class ATL_NO_VTABLE RocContent : public IRocFirst, public IRocSecond, public CComObjectRootEx<CComSingleThreadModel>
{
public:
    RocContent();
    HRESULT __stdcall first();
    HRESULT __stdcall second();
    char storage[48];
    DECLARE_PROTECT_FINAL_CONSTRUCT()
    BEGIN_COM_MAP(RocContent)
        COM_INTERFACE_ENTRY(IRocFirst)
        COM_INTERFACE_ENTRY(IRocSecond)
    END_COM_MAP()
};
template<class T> void rocSink(T);
void rocRefs() { rocSink(&CComCreator<CComObject<RocContent> >::CreateInstance); }
