// from server: 100% by auto
// roc 2009-06 006b6850  unit: RBX::ArrowTool  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b6850
//
// 006b6850  56                   push esi
// 006b6851  8bf1                 mov esi, ecx
// 006b6853  833e00               cmp dword ptr [esi], 0
// 006b6856  57                   push edi
// 006b6857  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 006b685d  7502                 jne 0x6b6861
// 006b685f  ffd7                 call edi
// 006b6861  8b4604               mov eax, dword ptr [esi + 4]
// 006b6864  80781100             cmp byte ptr [eax + 0x11], 0
// 006b6868  7405                 je 0x6b686f
// 006b686a  ffd7                 call edi
// 006b686c  5f                   pop edi
// 006b686d  5e                   pop esi
// 006b686e  c3                   ret 
// 006b686f  8b4808               mov ecx, dword ptr [eax + 8]
// 006b6872  80791100             cmp byte ptr [ecx + 0x11], 0
// 006b6876  7518                 jne 0x6b6890
// 006b6878  8b01                 mov eax, dword ptr [ecx]
// 006b687a  80781100             cmp byte ptr [eax + 0x11], 0
// 006b687e  750a                 jne 0x6b688a
// 006b6880  8bc8                 mov ecx, eax
// 006b6882  8b01                 mov eax, dword ptr [ecx]
// 006b6884  80781100             cmp byte ptr [eax + 0x11], 0
// 006b6888  74f6                 je 0x6b6880
// 006b688a  5f                   pop edi
// 006b688b  894e04               mov dword ptr [esi + 4], ecx
// 006b688e  5e                   pop esi
// 006b688f  c3                   ret 
// 006b6890  8b4004               mov eax, dword ptr [eax + 4]
// 006b6893  80781100             cmp byte ptr [eax + 0x11], 0
// 006b6897  751d                 jne 0x6b68b6
// 006b6899  8da42400000000       lea esp, [esp]
// 006b68a0  8b4e04               mov ecx, dword ptr [esi + 4]
// 006b68a3  3b4808               cmp ecx, dword ptr [eax + 8]
// 006b68a6  750e                 jne 0x6b68b6
// 006b68a8  894604               mov dword ptr [esi + 4], eax
// 006b68ab  8bd0                 mov edx, eax
// 006b68ad  8b4204               mov eax, dword ptr [edx + 4]
// 006b68b0  80781100             cmp byte ptr [eax + 0x11], 0
// 006b68b4  74ea                 je 0x6b68a0
// 006b68b6  5f                   pop edi
// 006b68b7  894604               mov dword ptr [esi + 4], eax
// 006b68ba  5e                   pop esi
// 006b68bb  c3                   ret 
// standard library set<ptr> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
