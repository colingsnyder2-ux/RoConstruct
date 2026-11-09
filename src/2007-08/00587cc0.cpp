// from server: 100% by auto
// roc 2007-08 00587cc0  unit: RBX::Reflection::EnumDescriptor  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00587cc0
//
// 00587cc0  56                   push esi
// 00587cc1  8bf1                 mov esi, ecx
// 00587cc3  833e00               cmp dword ptr [esi], 0
// 00587cc6  57                   push edi
// 00587cc7  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 00587ccd  7502                 jne 0x587cd1
// 00587ccf  ffd7                 call edi
// 00587cd1  8b4604               mov eax, dword ptr [esi + 4]
// 00587cd4  80781900             cmp byte ptr [eax + 0x19], 0
// 00587cd8  7405                 je 0x587cdf
// 00587cda  ffd7                 call edi
// 00587cdc  5f                   pop edi
// 00587cdd  5e                   pop esi
// 00587cde  c3                   ret 
// 00587cdf  8b4808               mov ecx, dword ptr [eax + 8]
// 00587ce2  80791900             cmp byte ptr [ecx + 0x19], 0
// 00587ce6  7518                 jne 0x587d00
// 00587ce8  8b01                 mov eax, dword ptr [ecx]
// 00587cea  80781900             cmp byte ptr [eax + 0x19], 0
// 00587cee  750a                 jne 0x587cfa
// 00587cf0  8bc8                 mov ecx, eax
// 00587cf2  8b01                 mov eax, dword ptr [ecx]
// 00587cf4  80781900             cmp byte ptr [eax + 0x19], 0
// 00587cf8  74f6                 je 0x587cf0
// 00587cfa  5f                   pop edi
// 00587cfb  894e04               mov dword ptr [esi + 4], ecx
// 00587cfe  5e                   pop esi
// 00587cff  c3                   ret 
// 00587d00  8b4004               mov eax, dword ptr [eax + 4]
// 00587d03  80781900             cmp byte ptr [eax + 0x19], 0
// 00587d07  751d                 jne 0x587d26
// 00587d09  8da42400000000       lea esp, [esp]
// 00587d10  8b4e04               mov ecx, dword ptr [esi + 4]
// 00587d13  3b4808               cmp ecx, dword ptr [eax + 8]
// 00587d16  750e                 jne 0x587d26
// 00587d18  894604               mov dword ptr [esi + 4], eax
// 00587d1b  8bd0                 mov edx, eax
// 00587d1d  8b4204               mov eax, dword ptr [edx + 4]
// 00587d20  80781900             cmp byte ptr [eax + 0x19], 0
// 00587d24  74ea                 je 0x587d10
// 00587d26  5f                   pop edi
// 00587d27  894604               mov dword ptr [esi + 4], eax
// 00587d2a  5e                   pop esi
// 00587d2b  c3                   ret 
// standard library set<double> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@QAEXXZ)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
