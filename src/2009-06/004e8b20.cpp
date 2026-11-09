// from server: 100% by auto
// roc 2009-06 004e8b20  unit: RBX::JointsService  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e8b20
//
// 004e8b20  6aff                 push -1
// 004e8b22  68485e8500           push 0x855e48
// 004e8b27  64a100000000         mov eax, dword ptr fs:[0]
// 004e8b2d  50                   push eax
// 004e8b2e  64892500000000       mov dword ptr fs:[0], esp
// 004e8b35  83ec0c               sub esp, 0xc
// 004e8b38  56                   push esi
// 004e8b39  8bf1                 mov esi, ecx
// 004e8b3b  89742404             mov dword ptr [esp + 4], esi
// 004e8b3f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e8b42  8b0e                 mov ecx, dword ptr [esi]
// 004e8b44  8b10                 mov edx, dword ptr [eax]
// 004e8b46  50                   push eax
// 004e8b47  51                   push ecx
// 004e8b48  52                   push edx
// 004e8b49  51                   push ecx
// 004e8b4a  8d442418             lea eax, [esp + 0x18]
// 004e8b4e  50                   push eax
// 004e8b4f  8bce                 mov ecx, esi
// 004e8b51  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004e8b59  e8d2faffff           call 0x4e8630
// 004e8b5e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004e8b61  51                   push ecx
// 004e8b62  e8cbfe2200           call 0x718a32
// 004e8b67  8b16                 mov edx, dword ptr [esi]
// 004e8b69  52                   push edx
// 004e8b6a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004e8b71  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004e8b78  e8b5fe2200           call 0x718a32
// 004e8b7d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004e8b81  83c408               add esp, 8
// 004e8b84  5e                   pop esi
// 004e8b85  64890d00000000       mov dword ptr fs:[0], ecx
// 004e8b8c  83c418               add esp, 0x18
// 004e8b8f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
