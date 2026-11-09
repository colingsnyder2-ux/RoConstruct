// from server: 100% by auto
// roc 2007-08 00569530  unit: RBX::ModelInstance  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00569530
//
// 00569530  56                   push esi
// 00569531  8bf1                 mov esi, ecx
// 00569533  833e00               cmp dword ptr [esi], 0
// 00569536  57                   push edi
// 00569537  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 0056953d  7502                 jne 0x569541
// 0056953f  ffd7                 call edi
// 00569541  8b4604               mov eax, dword ptr [esi + 4]
// 00569544  80783100             cmp byte ptr [eax + 0x31], 0
// 00569548  7405                 je 0x56954f
// 0056954a  ffd7                 call edi
// 0056954c  5f                   pop edi
// 0056954d  5e                   pop esi
// 0056954e  c3                   ret 
// 0056954f  8b4808               mov ecx, dword ptr [eax + 8]
// 00569552  80793100             cmp byte ptr [ecx + 0x31], 0
// 00569556  7518                 jne 0x569570
// 00569558  8b01                 mov eax, dword ptr [ecx]
// 0056955a  80783100             cmp byte ptr [eax + 0x31], 0
// 0056955e  750a                 jne 0x56956a
// 00569560  8bc8                 mov ecx, eax
// 00569562  8b01                 mov eax, dword ptr [ecx]
// 00569564  80783100             cmp byte ptr [eax + 0x31], 0
// 00569568  74f6                 je 0x569560
// 0056956a  5f                   pop edi
// 0056956b  894e04               mov dword ptr [esi + 4], ecx
// 0056956e  5e                   pop esi
// 0056956f  c3                   ret 
// 00569570  8b4004               mov eax, dword ptr [eax + 4]
// 00569573  80783100             cmp byte ptr [eax + 0x31], 0
// 00569577  751d                 jne 0x569596
// 00569579  8da42400000000       lea esp, [esp]
// 00569580  8b4e04               mov ecx, dword ptr [esi + 4]
// 00569583  3b4808               cmp ecx, dword ptr [eax + 8]
// 00569586  750e                 jne 0x569596
// 00569588  894604               mov dword ptr [esi + 4], eax
// 0056958b  8bd0                 mov edx, eax
// 0056958d  8b4204               mov eax, dword ptr [edx + 4]
// 00569590  80783100             cmp byte ptr [eax + 0x31], 0
// 00569594  74ea                 je 0x569580
// 00569596  5f                   pop edi
// 00569597  894604               mov dword ptr [esi + 4], eax
// 0056959a  5e                   pop esi
// 0056959b  c3                   ret 
// standard library set<pod36> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
