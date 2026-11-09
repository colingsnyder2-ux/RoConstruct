// from server: 100% by auto
// roc 2009-06 006d3ce0  unit: RBX::Block  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d3ce0
//
// 006d3ce0  6aff                 push -1
// 006d3ce2  68485e8500           push 0x855e48
// 006d3ce7  64a100000000         mov eax, dword ptr fs:[0]
// 006d3ced  50                   push eax
// 006d3cee  64892500000000       mov dword ptr fs:[0], esp
// 006d3cf5  83ec0c               sub esp, 0xc
// 006d3cf8  56                   push esi
// 006d3cf9  8bf1                 mov esi, ecx
// 006d3cfb  89742404             mov dword ptr [esp + 4], esi
// 006d3cff  8b4618               mov eax, dword ptr [esi + 0x18]
// 006d3d02  8b0e                 mov ecx, dword ptr [esi]
// 006d3d04  8b10                 mov edx, dword ptr [eax]
// 006d3d06  50                   push eax
// 006d3d07  51                   push ecx
// 006d3d08  52                   push edx
// 006d3d09  51                   push ecx
// 006d3d0a  8d442418             lea eax, [esp + 0x18]
// 006d3d0e  50                   push eax
// 006d3d0f  8bce                 mov ecx, esi
// 006d3d11  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006d3d19  e892fbffff           call 0x6d38b0
// 006d3d1e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006d3d21  51                   push ecx
// 006d3d22  e80b4d0400           call 0x718a32
// 006d3d27  8b16                 mov edx, dword ptr [esi]
// 006d3d29  52                   push edx
// 006d3d2a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006d3d31  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006d3d38  e8f54c0400           call 0x718a32
// 006d3d3d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006d3d41  83c408               add esp, 8
// 006d3d44  5e                   pop esi
// 006d3d45  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3d4c  83c418               add esp, 0x18
// 006d3d4f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
