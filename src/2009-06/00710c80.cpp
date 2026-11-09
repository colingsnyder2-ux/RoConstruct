// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
enum D3DDEVTYPE { D3DDEVTYPE_HAL = 1, D3DDEVTYPE_REF = 2 };
enum D3DFORMAT { D3DFMT_UNKNOWN = 0 };
struct D3DCAPS9 { D3DDEVTYPE DeviceType; unsigned AdapterOrdinal; };

bool __stdcall IsDeviceAcceptable(const D3DCAPS9* pCaps, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat, bool bWindowed)
{
    if (pCaps->DeviceType != D3DDEVTYPE_HAL) return false;
    return true;
}
