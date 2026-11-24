// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// ATL::AtlThrowImpl: throws CMemoryException for E_OUTOFMEMORY, else COleException.
// Callee names come from the 2008 disassembly (AfxThrowMemoryException / AfxThrowOleException).

typedef long HRESULT;

void __stdcall AfxThrowMemoryException();
void __stdcall AfxThrowOleException(long sc);

namespace ATL {
void __stdcall AtlThrowImpl(long hr)
{
    if (hr == (long)0x8007000e) // E_OUTOFMEMORY
        AfxThrowMemoryException();
    AfxThrowOleException(hr);
}
}
