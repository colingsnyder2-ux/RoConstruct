// roc 2012-06 009d11b0  unit: CXTPControls  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d11b0
//
// 009d11b0  8b442404             mov eax, dword ptr [esp + 4]
// 009d11b4  6a00                 push 0
// 009d11b6  6a00                 push 0
// 009d11b8  50                   push eax
// 009d11b9  6a00                 push 0
// 009d11bb  e830e0ffff           call 0x9cf1f0
// 009d11c0  c20400               ret 4
// copied from an identical function in another client (function ?sub_0067c5e0@ns_ROCX00002d@@YGHH@Z)

namespace ns_ROCX00002d {
extern "C" int __stdcall sub_0067a6c0(int, int, int, int);

int __stdcall sub_0067c5e0(int arg)
{
    return sub_0067a6c0(0, arg, 0, 0);
}
}
