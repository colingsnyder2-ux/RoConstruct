// from server: 100% by auto
// roc 2008-06 00671c20  unit: RBX::AdornRbxGfx  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00671c20
//
// 00671c20  6aff                 push -1
// 00671c22  6828d97b00           push 0x7bd928
// 00671c27  64a100000000         mov eax, dword ptr fs:[0]
// 00671c2d  50                   push eax
// 00671c2e  64892500000000       mov dword ptr fs:[0], esp
// 00671c35  83ec0c               sub esp, 0xc
// 00671c38  56                   push esi
// 00671c39  8bf1                 mov esi, ecx
// 00671c3b  89742404             mov dword ptr [esp + 4], esi
// 00671c3f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00671c42  8b0e                 mov ecx, dword ptr [esi]
// 00671c44  8b10                 mov edx, dword ptr [eax]
// 00671c46  50                   push eax
// 00671c47  51                   push ecx
// 00671c48  52                   push edx
// 00671c49  51                   push ecx
// 00671c4a  8d442418             lea eax, [esp + 0x18]
// 00671c4e  50                   push eax
// 00671c4f  8bce                 mov ecx, esi
// 00671c51  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00671c59  e8d2fbffff           call 0x671830
// 00671c5e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00671c61  51                   push ecx
// 00671c62  e813ea0200           call 0x6a067a
// 00671c67  8b16                 mov edx, dword ptr [esi]
// 00671c69  52                   push edx
// 00671c6a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00671c71  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00671c78  e8fde90200           call 0x6a067a
// 00671c7d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00671c81  83c408               add esp, 8
// 00671c84  5e                   pop esi
// 00671c85  64890d00000000       mov dword ptr fs:[0], ecx
// 00671c8c  83c418               add esp, 0x18
// 00671c8f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
