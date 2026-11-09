// from server: 100% by auto
// roc 2009-06 0063ea10  unit: RBX::Accoutrement  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063ea10
//
// 0063ea10  56                   push esi
// 0063ea11  8bf1                 mov esi, ecx
// 0063ea13  833e00               cmp dword ptr [esi], 0
// 0063ea16  57                   push edi
// 0063ea17  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 0063ea1d  7502                 jne 0x63ea21
// 0063ea1f  ffd7                 call edi
// 0063ea21  8b4604               mov eax, dword ptr [esi + 4]
// 0063ea24  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0063ea28  7405                 je 0x63ea2f
// 0063ea2a  ffd7                 call edi
// 0063ea2c  5f                   pop edi
// 0063ea2d  5e                   pop esi
// 0063ea2e  c3                   ret 
// 0063ea2f  8b4808               mov ecx, dword ptr [eax + 8]
// 0063ea32  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0063ea36  7518                 jne 0x63ea50
// 0063ea38  8b01                 mov eax, dword ptr [ecx]
// 0063ea3a  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0063ea3e  750a                 jne 0x63ea4a
// 0063ea40  8bc8                 mov ecx, eax
// 0063ea42  8b01                 mov eax, dword ptr [ecx]
// 0063ea44  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0063ea48  74f6                 je 0x63ea40
// 0063ea4a  5f                   pop edi
// 0063ea4b  894e04               mov dword ptr [esi + 4], ecx
// 0063ea4e  5e                   pop esi
// 0063ea4f  c3                   ret 
// 0063ea50  8b4004               mov eax, dword ptr [eax + 4]
// 0063ea53  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0063ea57  751d                 jne 0x63ea76
// 0063ea59  8da42400000000       lea esp, [esp]
// 0063ea60  8b4e04               mov ecx, dword ptr [esi + 4]
// 0063ea63  3b4808               cmp ecx, dword ptr [eax + 8]
// 0063ea66  750e                 jne 0x63ea76
// 0063ea68  894604               mov dword ptr [esi + 4], eax
// 0063ea6b  8bd0                 mov edx, eax
// 0063ea6d  8b4204               mov eax, dword ptr [edx + 4]
// 0063ea70  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0063ea74  74ea                 je 0x63ea60
// 0063ea76  5f                   pop edi
// 0063ea77  894604               mov dword ptr [esi + 4], eax
// 0063ea7a  5e                   pop esi
// 0063ea7b  c3                   ret 
// standard library set<pod32> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
