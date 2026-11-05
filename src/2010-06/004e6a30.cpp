// from server: 100% by auto
// roc 2010-06 004e6a30  unit: RBX::Network::Replicator  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e6a30
//
// 004e6a30  56                   push esi
// 004e6a31  8bf1                 mov esi, ecx
// 004e6a33  833e00               cmp dword ptr [esi], 0
// 004e6a36  57                   push edi
// 004e6a37  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 004e6a3d  7502                 jne 0x4e6a41
// 004e6a3f  ffd7                 call edi
// 004e6a41  8b4604               mov eax, dword ptr [esi + 4]
// 004e6a44  80781900             cmp byte ptr [eax + 0x19], 0
// 004e6a48  7405                 je 0x4e6a4f
// 004e6a4a  ffd7                 call edi
// 004e6a4c  5f                   pop edi
// 004e6a4d  5e                   pop esi
// 004e6a4e  c3                   ret 
// 004e6a4f  8b4808               mov ecx, dword ptr [eax + 8]
// 004e6a52  80791900             cmp byte ptr [ecx + 0x19], 0
// 004e6a56  7518                 jne 0x4e6a70
// 004e6a58  8b01                 mov eax, dword ptr [ecx]
// 004e6a5a  80781900             cmp byte ptr [eax + 0x19], 0
// 004e6a5e  750a                 jne 0x4e6a6a
// 004e6a60  8bc8                 mov ecx, eax
// 004e6a62  8b01                 mov eax, dword ptr [ecx]
// 004e6a64  80781900             cmp byte ptr [eax + 0x19], 0
// 004e6a68  74f6                 je 0x4e6a60
// 004e6a6a  5f                   pop edi
// 004e6a6b  894e04               mov dword ptr [esi + 4], ecx
// 004e6a6e  5e                   pop esi
// 004e6a6f  c3                   ret 
// 004e6a70  8b4004               mov eax, dword ptr [eax + 4]
// 004e6a73  80781900             cmp byte ptr [eax + 0x19], 0
// 004e6a77  751d                 jne 0x4e6a96
// 004e6a79  8da42400000000       lea esp, [esp]
// 004e6a80  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e6a83  3b4808               cmp ecx, dword ptr [eax + 8]
// 004e6a86  750e                 jne 0x4e6a96
// 004e6a88  894604               mov dword ptr [esi + 4], eax
// 004e6a8b  8bd0                 mov edx, eax
// 004e6a8d  8b4204               mov eax, dword ptr [edx + 4]
// 004e6a90  80781900             cmp byte ptr [eax + 0x19], 0
// 004e6a94  74ea                 je 0x4e6a80
// 004e6a96  5f                   pop edi
// 004e6a97  894604               mov dword ptr [esi + 4], eax
// 004e6a9a  5e                   pop esi
// 004e6a9b  c3                   ret 
// standard library set<double> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@QAEXXZ)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
