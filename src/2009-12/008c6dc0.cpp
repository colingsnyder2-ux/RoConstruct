// roc 2009-12 008c6dc0  unit: VCEdit::?$CXTMaskEditT  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c6dc0
//
// 008c6dc0  56                   push esi
// 008c6dc1  8bf1                 mov esi, ecx
// 008c6dc3  8b869c000000         mov eax, dword ptr [esi + 0x9c]
// 008c6dc9  85c0                 test eax, eax
// 008c6dcb  743b                 je 0x8c6e08
// 008c6dcd  8b4020               mov eax, dword ptr [eax + 0x20]
// 008c6dd0  6a00                 push 0
// 008c6dd2  6a00                 push 0
// 008c6dd4  50                   push eax
// 008c6dd5  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008c6ddb  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 008c6de1  85c9                 test ecx, ecx
// 008c6de3  7419                 je 0x8c6dfe
// 008c6de5  8b11                 mov edx, dword ptr [ecx]
// 008c6de7  8b8290000000         mov eax, dword ptr [edx + 0x90]
// 008c6ded  ffd0                 call eax
// 008c6def  85c0                 test eax, eax
// 008c6df1  750b                 jne 0x8c6dfe
// 008c6df3  8b8e9c000000         mov ecx, dword ptr [esi + 0x9c]
// 008c6df9  e804cef2ff           call 0x7f3c02
// 008c6dfe  c786ac00000001000000 mov dword ptr [esi + 0xac], 1
// 008c6e08  5e                   pop esi
// 008c6e09  c3                   ret 
// copied from an identical function in another client (function ?Invalidate@CXTMaskEditT@ns_ROCX000030@ns_ROCX00004e@@QAEXXZ)

namespace ns_ROCX000030 {
struct B_func_0076d0e0 { virtual ~B_func_0076d0e0(); };
struct S_func_0076d0e0 : B_func_0076d0e0 { ~S_func_0076d0e0(); };
S_func_0076d0e0::~S_func_0076d0e0()
{
}
}
