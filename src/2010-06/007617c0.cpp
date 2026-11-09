// from server: 100% by auto
// roc 2010-06 007617c0  unit: RBX::TreeStage  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007617c0
//
// 007617c0  56                   push esi
// 007617c1  8bf1                 mov esi, ecx
// 007617c3  833e00               cmp dword ptr [esi], 0
// 007617c6  57                   push edi
// 007617c7  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 007617cd  7502                 jne 0x7617d1
// 007617cf  ffd7                 call edi
// 007617d1  8b4604               mov eax, dword ptr [esi + 4]
// 007617d4  80781100             cmp byte ptr [eax + 0x11], 0
// 007617d8  7405                 je 0x7617df
// 007617da  ffd7                 call edi
// 007617dc  5f                   pop edi
// 007617dd  5e                   pop esi
// 007617de  c3                   ret 
// 007617df  8b4808               mov ecx, dword ptr [eax + 8]
// 007617e2  80791100             cmp byte ptr [ecx + 0x11], 0
// 007617e6  7518                 jne 0x761800
// 007617e8  8b01                 mov eax, dword ptr [ecx]
// 007617ea  80781100             cmp byte ptr [eax + 0x11], 0
// 007617ee  750a                 jne 0x7617fa
// 007617f0  8bc8                 mov ecx, eax
// 007617f2  8b01                 mov eax, dword ptr [ecx]
// 007617f4  80781100             cmp byte ptr [eax + 0x11], 0
// 007617f8  74f6                 je 0x7617f0
// 007617fa  5f                   pop edi
// 007617fb  894e04               mov dword ptr [esi + 4], ecx
// 007617fe  5e                   pop esi
// 007617ff  c3                   ret 
// 00761800  8b4004               mov eax, dword ptr [eax + 4]
// 00761803  80781100             cmp byte ptr [eax + 0x11], 0
// 00761807  751d                 jne 0x761826
// 00761809  8da42400000000       lea esp, [esp]
// 00761810  8b4e04               mov ecx, dword ptr [esi + 4]
// 00761813  3b4808               cmp ecx, dword ptr [eax + 8]
// 00761816  750e                 jne 0x761826
// 00761818  894604               mov dword ptr [esi + 4], eax
// 0076181b  8bd0                 mov edx, eax
// 0076181d  8b4204               mov eax, dword ptr [edx + 4]
// 00761820  80781100             cmp byte ptr [eax + 0x11], 0
// 00761824  74ea                 je 0x761810
// 00761826  5f                   pop edi
// 00761827  894604               mov dword ptr [esi + 4], eax
// 0076182a  5e                   pop esi
// 0076182b  c3                   ret 
// standard library set<ptr> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
