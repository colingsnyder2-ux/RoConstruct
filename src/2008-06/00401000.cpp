// from server: 100% by tester
typedef long HRESULT;

__declspec(noreturn) void __stdcall AfxThrowMemoryException();
__declspec(noreturn) void __stdcall AfxThrowOleException(HRESULT sc);

namespace ATL {
void __stdcall AtlThrowImpl(HRESULT hr)
{
    if (hr == 0x8007000EL)
        AfxThrowMemoryException();
    AfxThrowOleException(hr);
}
}
