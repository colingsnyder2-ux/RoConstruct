// from server: 100% by auto
// roc 2009-12 007cae20  unit: RBX::ScoreHud  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cae20
//
// 007cae20  6aff                 push -1
// 007cae22  68888f9400           push 0x948f88
// 007cae27  64a100000000         mov eax, dword ptr fs:[0]
// 007cae2d  50                   push eax
// 007cae2e  64892500000000       mov dword ptr fs:[0], esp
// 007cae35  83ec0c               sub esp, 0xc
// 007cae38  56                   push esi
// 007cae39  8bf1                 mov esi, ecx
// 007cae3b  89742404             mov dword ptr [esp + 4], esi
// 007cae3f  8b4618               mov eax, dword ptr [esi + 0x18]
// 007cae42  8b0e                 mov ecx, dword ptr [esi]
// 007cae44  8b10                 mov edx, dword ptr [eax]
// 007cae46  50                   push eax
// 007cae47  51                   push ecx
// 007cae48  52                   push edx
// 007cae49  51                   push ecx
// 007cae4a  8d442418             lea eax, [esp + 0x18]
// 007cae4e  50                   push eax
// 007cae4f  8bce                 mov ecx, esi
// 007cae51  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 007cae59  e832ebffff           call 0x7c9990
// 007cae5e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007cae61  51                   push ecx
// 007cae62  e8f3890200           call 0x7f385a
// 007cae67  8b16                 mov edx, dword ptr [esi]
// 007cae69  52                   push edx
// 007cae6a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 007cae71  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007cae78  e8dd890200           call 0x7f385a
// 007cae7d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007cae81  83c408               add esp, 8
// 007cae84  5e                   pop esi
// 007cae85  64890d00000000       mov dword ptr fs:[0], ecx
// 007cae8c  83c418               add esp, 0x18
// 007cae8f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
