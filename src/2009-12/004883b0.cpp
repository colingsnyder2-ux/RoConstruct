// from server: 100% by auto
// roc 2009-12 004883b0  unit: Ogre::GfxClustererPart  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004883b0
//
// 004883b0  6aff                 push -1
// 004883b2  68888f9400           push 0x948f88
// 004883b7  64a100000000         mov eax, dword ptr fs:[0]
// 004883bd  50                   push eax
// 004883be  64892500000000       mov dword ptr fs:[0], esp
// 004883c5  83ec0c               sub esp, 0xc
// 004883c8  56                   push esi
// 004883c9  8bf1                 mov esi, ecx
// 004883cb  89742404             mov dword ptr [esp + 4], esi
// 004883cf  8b4618               mov eax, dword ptr [esi + 0x18]
// 004883d2  8b0e                 mov ecx, dword ptr [esi]
// 004883d4  8b10                 mov edx, dword ptr [eax]
// 004883d6  50                   push eax
// 004883d7  51                   push ecx
// 004883d8  52                   push edx
// 004883d9  51                   push ecx
// 004883da  8d442418             lea eax, [esp + 0x18]
// 004883de  50                   push eax
// 004883df  8bce                 mov ecx, esi
// 004883e1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004883e9  e8e2fcffff           call 0x4880d0
// 004883ee  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004883f1  51                   push ecx
// 004883f2  e863b43600           call 0x7f385a
// 004883f7  8b16                 mov edx, dword ptr [esi]
// 004883f9  52                   push edx
// 004883fa  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00488401  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00488408  e84db43600           call 0x7f385a
// 0048840d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00488411  83c408               add esp, 8
// 00488414  5e                   pop esi
// 00488415  64890d00000000       mov dword ptr fs:[0], ecx
// 0048841c  83c418               add esp, 0x18
// 0048841f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
