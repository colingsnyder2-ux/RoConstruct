// from server: 100% by auto
// roc 2008-06 0068dfa0  unit: Ogre::VRbxSky::?$SharedPtr  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068dfa0
//
// 0068dfa0  56                   push esi
// 0068dfa1  8bf1                 mov esi, ecx
// 0068dfa3  833e00               cmp dword ptr [esi], 0
// 0068dfa6  57                   push edi
// 0068dfa7  8b3d90288000         mov edi, dword ptr [0x802890]
// 0068dfad  7502                 jne 0x68dfb1
// 0068dfaf  ffd7                 call edi
// 0068dfb1  8b4604               mov eax, dword ptr [esi + 4]
// 0068dfb4  80781500             cmp byte ptr [eax + 0x15], 0
// 0068dfb8  7405                 je 0x68dfbf
// 0068dfba  ffd7                 call edi
// 0068dfbc  5f                   pop edi
// 0068dfbd  5e                   pop esi
// 0068dfbe  c3                   ret 
// 0068dfbf  8b4808               mov ecx, dword ptr [eax + 8]
// 0068dfc2  80791500             cmp byte ptr [ecx + 0x15], 0
// 0068dfc6  7518                 jne 0x68dfe0
// 0068dfc8  8b01                 mov eax, dword ptr [ecx]
// 0068dfca  80781500             cmp byte ptr [eax + 0x15], 0
// 0068dfce  750a                 jne 0x68dfda
// 0068dfd0  8bc8                 mov ecx, eax
// 0068dfd2  8b01                 mov eax, dword ptr [ecx]
// 0068dfd4  80781500             cmp byte ptr [eax + 0x15], 0
// 0068dfd8  74f6                 je 0x68dfd0
// 0068dfda  5f                   pop edi
// 0068dfdb  894e04               mov dword ptr [esi + 4], ecx
// 0068dfde  5e                   pop esi
// 0068dfdf  c3                   ret 
// 0068dfe0  8b4004               mov eax, dword ptr [eax + 4]
// 0068dfe3  80781500             cmp byte ptr [eax + 0x15], 0
// 0068dfe7  751d                 jne 0x68e006
// 0068dfe9  8da42400000000       lea esp, [esp]
// 0068dff0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0068dff3  3b4808               cmp ecx, dword ptr [eax + 8]
// 0068dff6  750e                 jne 0x68e006
// 0068dff8  894604               mov dword ptr [esi + 4], eax
// 0068dffb  8bd0                 mov edx, eax
// 0068dffd  8b4204               mov eax, dword ptr [edx + 4]
// 0068e000  80781500             cmp byte ptr [eax + 0x15], 0
// 0068e004  74ea                 je 0x68dff0
// 0068e006  5f                   pop edi
// 0068e007  894604               mov dword ptr [esi + 4], eax
// 0068e00a  5e                   pop esi
// 0068e00b  c3                   ret 
// standard library set<pod8> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
