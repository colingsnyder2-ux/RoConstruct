// roc 2009-12 008f39a0  unit: CXTWindowMap  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f39a0
//
// 008f39a0  56                   push esi
// 008f39a1  57                   push edi
// 008f39a2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008f39a6  57                   push edi
// 008f39a7  8bf1                 mov esi, ecx
// 008f39a9  e8f2feffff           call 0x8f38a0
// 008f39ae  85c0                 test eax, eax
// 008f39b0  7417                 je 0x8f39c9
// 008f39b2  8b10                 mov edx, dword ptr [eax]
// 008f39b4  8bc8                 mov ecx, eax
// 008f39b6  8b421c               mov eax, dword ptr [edx + 0x1c]
// 008f39b9  6a00                 push 0
// 008f39bb  ffd0                 call eax
// 008f39bd  57                   push edi
// 008f39be  8bce                 mov ecx, esi
// 008f39c0  e8dbfeffff           call 0x8f38a0
// 008f39c5  85c0                 test eax, eax
// 008f39c7  75e9                 jne 0x8f39b2
// 008f39c9  5f                   pop edi
// 008f39ca  5e                   pop esi
// 008f39cb  c20400               ret 4
// copied from an identical function in another client (function ?Remove@CXTWindowMap@ns_ROCX000003@ns_ROCX000049@@QAEXH@Z)

namespace ns_ROCX000003 {
struct B_func_00808ad0 { virtual ~B_func_00808ad0(); };
struct S_func_00808ad0 : B_func_00808ad0 { ~S_func_00808ad0(); };
S_func_00808ad0::~S_func_00808ad0()
{
}
}
