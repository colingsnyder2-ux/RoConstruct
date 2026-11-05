// from server: 100% by auto
// roc 2009-12 004b2000  unit: Ogre::TextureCompositor  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b2000
//
// 004b2000  6aff                 push -1
// 004b2002  68888f9400           push 0x948f88
// 004b2007  64a100000000         mov eax, dword ptr fs:[0]
// 004b200d  50                   push eax
// 004b200e  64892500000000       mov dword ptr fs:[0], esp
// 004b2015  83ec0c               sub esp, 0xc
// 004b2018  56                   push esi
// 004b2019  8bf1                 mov esi, ecx
// 004b201b  89742404             mov dword ptr [esp + 4], esi
// 004b201f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b2022  8b0e                 mov ecx, dword ptr [esi]
// 004b2024  8b10                 mov edx, dword ptr [eax]
// 004b2026  50                   push eax
// 004b2027  51                   push ecx
// 004b2028  52                   push edx
// 004b2029  51                   push ecx
// 004b202a  8d442418             lea eax, [esp + 0x18]
// 004b202e  50                   push eax
// 004b202f  8bce                 mov ecx, esi
// 004b2031  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004b2039  e802fcffff           call 0x4b1c40
// 004b203e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004b2041  51                   push ecx
// 004b2042  e813183400           call 0x7f385a
// 004b2047  8b16                 mov edx, dword ptr [esi]
// 004b2049  52                   push edx
// 004b204a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004b2051  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004b2058  e8fd173400           call 0x7f385a
// 004b205d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004b2061  83c408               add esp, 8
// 004b2064  5e                   pop esi
// 004b2065  64890d00000000       mov dword ptr fs:[0], ecx
// 004b206c  83c418               add esp, 0x18
// 004b206f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
