// from server: 100% by auto
// roc 2009-12 007c9700  unit: RBX::ScoreHud  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c9700
//
// 007c9700  6aff                 push -1
// 007c9702  68888f9400           push 0x948f88
// 007c9707  64a100000000         mov eax, dword ptr fs:[0]
// 007c970d  50                   push eax
// 007c970e  64892500000000       mov dword ptr fs:[0], esp
// 007c9715  83ec0c               sub esp, 0xc
// 007c9718  56                   push esi
// 007c9719  8bf1                 mov esi, ecx
// 007c971b  89742404             mov dword ptr [esp + 4], esi
// 007c971f  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c9722  8b0e                 mov ecx, dword ptr [esi]
// 007c9724  8b10                 mov edx, dword ptr [eax]
// 007c9726  50                   push eax
// 007c9727  51                   push ecx
// 007c9728  52                   push edx
// 007c9729  51                   push ecx
// 007c972a  8d442418             lea eax, [esp + 0x18]
// 007c972e  50                   push eax
// 007c972f  8bce                 mov ecx, esi
// 007c9731  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 007c9739  e852efffff           call 0x7c8690
// 007c973e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007c9741  51                   push ecx
// 007c9742  e813a10200           call 0x7f385a
// 007c9747  8b16                 mov edx, dword ptr [esi]
// 007c9749  52                   push edx
// 007c974a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 007c9751  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007c9758  e8fda00200           call 0x7f385a
// 007c975d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007c9761  83c408               add esp, 8
// 007c9764  5e                   pop esi
// 007c9765  64890d00000000       mov dword ptr fs:[0], ecx
// 007c976c  83c418               add esp, 0x18
// 007c976f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
