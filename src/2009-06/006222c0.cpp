// from server: 100% by auto
// roc 2009-06 006222c0  unit: RBX::RootInstance  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006222c0
//
// 006222c0  56                   push esi
// 006222c1  8bf1                 mov esi, ecx
// 006222c3  833e00               cmp dword ptr [esi], 0
// 006222c6  57                   push edi
// 006222c7  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 006222cd  7502                 jne 0x6222d1
// 006222cf  ffd7                 call edi
// 006222d1  8b4604               mov eax, dword ptr [esi + 4]
// 006222d4  80781900             cmp byte ptr [eax + 0x19], 0
// 006222d8  7405                 je 0x6222df
// 006222da  ffd7                 call edi
// 006222dc  5f                   pop edi
// 006222dd  5e                   pop esi
// 006222de  c3                   ret 
// 006222df  8b4808               mov ecx, dword ptr [eax + 8]
// 006222e2  80791900             cmp byte ptr [ecx + 0x19], 0
// 006222e6  7518                 jne 0x622300
// 006222e8  8b01                 mov eax, dword ptr [ecx]
// 006222ea  80781900             cmp byte ptr [eax + 0x19], 0
// 006222ee  750a                 jne 0x6222fa
// 006222f0  8bc8                 mov ecx, eax
// 006222f2  8b01                 mov eax, dword ptr [ecx]
// 006222f4  80781900             cmp byte ptr [eax + 0x19], 0
// 006222f8  74f6                 je 0x6222f0
// 006222fa  5f                   pop edi
// 006222fb  894e04               mov dword ptr [esi + 4], ecx
// 006222fe  5e                   pop esi
// 006222ff  c3                   ret 
// 00622300  8b4004               mov eax, dword ptr [eax + 4]
// 00622303  80781900             cmp byte ptr [eax + 0x19], 0
// 00622307  751d                 jne 0x622326
// 00622309  8da42400000000       lea esp, [esp]
// 00622310  8b4e04               mov ecx, dword ptr [esi + 4]
// 00622313  3b4808               cmp ecx, dword ptr [eax + 8]
// 00622316  750e                 jne 0x622326
// 00622318  894604               mov dword ptr [esi + 4], eax
// 0062231b  8bd0                 mov edx, eax
// 0062231d  8b4204               mov eax, dword ptr [edx + 4]
// 00622320  80781900             cmp byte ptr [eax + 0x19], 0
// 00622324  74ea                 je 0x622310
// 00622326  5f                   pop edi
// 00622327  894604               mov dword ptr [esi + 4], eax
// 0062232a  5e                   pop esi
// 0062232b  c3                   ret 
// standard library set<double> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@QAEXXZ)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
