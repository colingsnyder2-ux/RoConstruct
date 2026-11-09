// from server: 100% by auto
// roc 2008-06 0068d1a0  unit: Ogre::VShadowCameraSetup::?$SharedPtr  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068d1a0
//
// 0068d1a0  56                   push esi
// 0068d1a1  8bf1                 mov esi, ecx
// 0068d1a3  833e00               cmp dword ptr [esi], 0
// 0068d1a6  57                   push edi
// 0068d1a7  8b3d90288000         mov edi, dword ptr [0x802890]
// 0068d1ad  7502                 jne 0x68d1b1
// 0068d1af  ffd7                 call edi
// 0068d1b1  8b4604               mov eax, dword ptr [esi + 4]
// 0068d1b4  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0068d1b8  7405                 je 0x68d1bf
// 0068d1ba  ffd7                 call edi
// 0068d1bc  5f                   pop edi
// 0068d1bd  5e                   pop esi
// 0068d1be  c3                   ret 
// 0068d1bf  8b4808               mov ecx, dword ptr [eax + 8]
// 0068d1c2  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0068d1c6  7518                 jne 0x68d1e0
// 0068d1c8  8b01                 mov eax, dword ptr [ecx]
// 0068d1ca  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0068d1ce  750a                 jne 0x68d1da
// 0068d1d0  8bc8                 mov ecx, eax
// 0068d1d2  8b01                 mov eax, dword ptr [ecx]
// 0068d1d4  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0068d1d8  74f6                 je 0x68d1d0
// 0068d1da  5f                   pop edi
// 0068d1db  894e04               mov dword ptr [esi + 4], ecx
// 0068d1de  5e                   pop esi
// 0068d1df  c3                   ret 
// 0068d1e0  8b4004               mov eax, dword ptr [eax + 4]
// 0068d1e3  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0068d1e7  751d                 jne 0x68d206
// 0068d1e9  8da42400000000       lea esp, [esp]
// 0068d1f0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0068d1f3  3b4808               cmp ecx, dword ptr [eax + 8]
// 0068d1f6  750e                 jne 0x68d206
// 0068d1f8  894604               mov dword ptr [esi + 4], eax
// 0068d1fb  8bd0                 mov edx, eax
// 0068d1fd  8b4204               mov eax, dword ptr [edx + 4]
// 0068d200  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0068d204  74ea                 je 0x68d1f0
// 0068d206  5f                   pop edi
// 0068d207  894604               mov dword ptr [esi + 4], eax
// 0068d20a  5e                   pop esi
// 0068d20b  c3                   ret 
// standard library set<pod32> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
