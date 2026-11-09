// from server: 100% by auto
// roc 2010-06 0065f4b0  unit: RBX::VPlayerMouse::?$FactoryProduct  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0065f4b0
//
// 0065f4b0  56                   push esi
// 0065f4b1  8bf1                 mov esi, ecx
// 0065f4b3  833e00               cmp dword ptr [esi], 0
// 0065f4b6  57                   push edi
// 0065f4b7  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 0065f4bd  7502                 jne 0x65f4c1
// 0065f4bf  ffd7                 call edi
// 0065f4c1  8b4604               mov eax, dword ptr [esi + 4]
// 0065f4c4  80783100             cmp byte ptr [eax + 0x31], 0
// 0065f4c8  7405                 je 0x65f4cf
// 0065f4ca  ffd7                 call edi
// 0065f4cc  5f                   pop edi
// 0065f4cd  5e                   pop esi
// 0065f4ce  c3                   ret 
// 0065f4cf  8b4808               mov ecx, dword ptr [eax + 8]
// 0065f4d2  80793100             cmp byte ptr [ecx + 0x31], 0
// 0065f4d6  7518                 jne 0x65f4f0
// 0065f4d8  8b01                 mov eax, dword ptr [ecx]
// 0065f4da  80783100             cmp byte ptr [eax + 0x31], 0
// 0065f4de  750a                 jne 0x65f4ea
// 0065f4e0  8bc8                 mov ecx, eax
// 0065f4e2  8b01                 mov eax, dword ptr [ecx]
// 0065f4e4  80783100             cmp byte ptr [eax + 0x31], 0
// 0065f4e8  74f6                 je 0x65f4e0
// 0065f4ea  5f                   pop edi
// 0065f4eb  894e04               mov dword ptr [esi + 4], ecx
// 0065f4ee  5e                   pop esi
// 0065f4ef  c3                   ret 
// 0065f4f0  8b4004               mov eax, dword ptr [eax + 4]
// 0065f4f3  80783100             cmp byte ptr [eax + 0x31], 0
// 0065f4f7  751d                 jne 0x65f516
// 0065f4f9  8da42400000000       lea esp, [esp]
// 0065f500  8b4e04               mov ecx, dword ptr [esi + 4]
// 0065f503  3b4808               cmp ecx, dword ptr [eax + 8]
// 0065f506  750e                 jne 0x65f516
// 0065f508  894604               mov dword ptr [esi + 4], eax
// 0065f50b  8bd0                 mov edx, eax
// 0065f50d  8b4204               mov eax, dword ptr [edx + 4]
// 0065f510  80783100             cmp byte ptr [eax + 0x31], 0
// 0065f514  74ea                 je 0x65f500
// 0065f516  5f                   pop edi
// 0065f517  894604               mov dword ptr [esi + 4], eax
// 0065f51a  5e                   pop esi
// 0065f51b  c3                   ret 
// standard library set<pod36> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
