// from server: 100% by auto
// roc 2009-06 0048f940  unit: Ogre::TextureCompositor  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048f940
//
// 0048f940  6aff                 push -1
// 0048f942  68485e8500           push 0x855e48
// 0048f947  64a100000000         mov eax, dword ptr fs:[0]
// 0048f94d  50                   push eax
// 0048f94e  64892500000000       mov dword ptr fs:[0], esp
// 0048f955  83ec0c               sub esp, 0xc
// 0048f958  56                   push esi
// 0048f959  8bf1                 mov esi, ecx
// 0048f95b  89742404             mov dword ptr [esp + 4], esi
// 0048f95f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048f962  8b0e                 mov ecx, dword ptr [esi]
// 0048f964  8b10                 mov edx, dword ptr [eax]
// 0048f966  50                   push eax
// 0048f967  51                   push ecx
// 0048f968  52                   push edx
// 0048f969  51                   push ecx
// 0048f96a  8d442418             lea eax, [esp + 0x18]
// 0048f96e  50                   push eax
// 0048f96f  8bce                 mov ecx, esi
// 0048f971  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0048f979  e8d2fcffff           call 0x48f650
// 0048f97e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0048f981  51                   push ecx
// 0048f982  e8ab902800           call 0x718a32
// 0048f987  8b16                 mov edx, dword ptr [esi]
// 0048f989  52                   push edx
// 0048f98a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0048f991  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0048f998  e895902800           call 0x718a32
// 0048f99d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048f9a1  83c408               add esp, 8
// 0048f9a4  5e                   pop esi
// 0048f9a5  64890d00000000       mov dword ptr fs:[0], ecx
// 0048f9ac  83c418               add esp, 0x18
// 0048f9af  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
