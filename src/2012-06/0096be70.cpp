// from server: 100% by Xemicl
// roc 2012-06 0096be70  unit: RBX::ContactStage  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0096be70
//
// 0096be70  8b442404             mov eax, dword ptr [esp + 4]
// 0096be74  833801               cmp dword ptr [eax], 1
// 0096be77  0f94c0               sete al
// 0096be7a  c21000               ret 0x10
// copied from an identical function in another client (function ?IsDeviceAcceptable@@YG_NPBUD3DCAPS9@@W4D3DFORMAT@@1_N@Z)

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