// from server: 100% by auto
// roc 2009-12 00538580  unit: RBX::Network::Replicator  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00538580
//
// 00538580  56                   push esi
// 00538581  8bf1                 mov esi, ecx
// 00538583  833e00               cmp dword ptr [esi], 0
// 00538586  57                   push edi
// 00538587  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 0053858d  7502                 jne 0x538591
// 0053858f  ffd7                 call edi
// 00538591  8b4604               mov eax, dword ptr [esi + 4]
// 00538594  80781900             cmp byte ptr [eax + 0x19], 0
// 00538598  7405                 je 0x53859f
// 0053859a  ffd7                 call edi
// 0053859c  5f                   pop edi
// 0053859d  5e                   pop esi
// 0053859e  c3                   ret 
// 0053859f  8b4808               mov ecx, dword ptr [eax + 8]
// 005385a2  80791900             cmp byte ptr [ecx + 0x19], 0
// 005385a6  7518                 jne 0x5385c0
// 005385a8  8b01                 mov eax, dword ptr [ecx]
// 005385aa  80781900             cmp byte ptr [eax + 0x19], 0
// 005385ae  750a                 jne 0x5385ba
// 005385b0  8bc8                 mov ecx, eax
// 005385b2  8b01                 mov eax, dword ptr [ecx]
// 005385b4  80781900             cmp byte ptr [eax + 0x19], 0
// 005385b8  74f6                 je 0x5385b0
// 005385ba  5f                   pop edi
// 005385bb  894e04               mov dword ptr [esi + 4], ecx
// 005385be  5e                   pop esi
// 005385bf  c3                   ret 
// 005385c0  8b4004               mov eax, dword ptr [eax + 4]
// 005385c3  80781900             cmp byte ptr [eax + 0x19], 0
// 005385c7  751d                 jne 0x5385e6
// 005385c9  8da42400000000       lea esp, [esp]
// 005385d0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005385d3  3b4808               cmp ecx, dword ptr [eax + 8]
// 005385d6  750e                 jne 0x5385e6
// 005385d8  894604               mov dword ptr [esi + 4], eax
// 005385db  8bd0                 mov edx, eax
// 005385dd  8b4204               mov eax, dword ptr [edx + 4]
// 005385e0  80781900             cmp byte ptr [eax + 0x19], 0
// 005385e4  74ea                 je 0x5385d0
// 005385e6  5f                   pop edi
// 005385e7  894604               mov dword ptr [esi + 4], eax
// 005385ea  5e                   pop esi
// 005385eb  c3                   ret 
// standard library set<double> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@QAEXXZ)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
