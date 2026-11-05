// from server: 100% by auto
// roc 2007-08 00545430  unit: RBX::VDebugSettings::?$GlobalSettingsItem  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00545430
//
// 00545430  56                   push esi
// 00545431  8bf1                 mov esi, ecx
// 00545433  833e00               cmp dword ptr [esi], 0
// 00545436  57                   push edi
// 00545437  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 0054543d  7502                 jne 0x545441
// 0054543f  ffd7                 call edi
// 00545441  8b4604               mov eax, dword ptr [esi + 4]
// 00545444  80783d00             cmp byte ptr [eax + 0x3d], 0
// 00545448  7405                 je 0x54544f
// 0054544a  ffd7                 call edi
// 0054544c  5f                   pop edi
// 0054544d  5e                   pop esi
// 0054544e  c3                   ret 
// 0054544f  8b4808               mov ecx, dword ptr [eax + 8]
// 00545452  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 00545456  7518                 jne 0x545470
// 00545458  8b01                 mov eax, dword ptr [ecx]
// 0054545a  80783d00             cmp byte ptr [eax + 0x3d], 0
// 0054545e  750a                 jne 0x54546a
// 00545460  8bc8                 mov ecx, eax
// 00545462  8b01                 mov eax, dword ptr [ecx]
// 00545464  80783d00             cmp byte ptr [eax + 0x3d], 0
// 00545468  74f6                 je 0x545460
// 0054546a  5f                   pop edi
// 0054546b  894e04               mov dword ptr [esi + 4], ecx
// 0054546e  5e                   pop esi
// 0054546f  c3                   ret 
// 00545470  8b4004               mov eax, dword ptr [eax + 4]
// 00545473  80783d00             cmp byte ptr [eax + 0x3d], 0
// 00545477  751d                 jne 0x545496
// 00545479  8da42400000000       lea esp, [esp]
// 00545480  8b4e04               mov ecx, dword ptr [esi + 4]
// 00545483  3b4808               cmp ecx, dword ptr [eax + 8]
// 00545486  750e                 jne 0x545496
// 00545488  894604               mov dword ptr [esi + 4], eax
// 0054548b  8bd0                 mov edx, eax
// 0054548d  8b4204               mov eax, dword ptr [edx + 4]
// 00545490  80783d00             cmp byte ptr [eax + 0x3d], 0
// 00545494  74ea                 je 0x545480
// 00545496  5f                   pop edi
// 00545497  894604               mov dword ptr [esi + 4], eax
// 0054549a  5e                   pop esi
// 0054549b  c3                   ret 
// standard library set<pod48> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
