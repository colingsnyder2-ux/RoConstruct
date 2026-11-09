// from server: 100% by auto
// roc 2008-06 005b7250  unit: RBX::Soundscape::VSoundService::?$FactoryProduct  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b7250
//
// 005b7250  56                   push esi
// 005b7251  8bf1                 mov esi, ecx
// 005b7253  833e00               cmp dword ptr [esi], 0
// 005b7256  57                   push edi
// 005b7257  8b3d90288000         mov edi, dword ptr [0x802890]
// 005b725d  7502                 jne 0x5b7261
// 005b725f  ffd7                 call edi
// 005b7261  8b4604               mov eax, dword ptr [esi + 4]
// 005b7264  80781900             cmp byte ptr [eax + 0x19], 0
// 005b7268  7405                 je 0x5b726f
// 005b726a  ffd7                 call edi
// 005b726c  5f                   pop edi
// 005b726d  5e                   pop esi
// 005b726e  c3                   ret 
// 005b726f  8b4808               mov ecx, dword ptr [eax + 8]
// 005b7272  80791900             cmp byte ptr [ecx + 0x19], 0
// 005b7276  7518                 jne 0x5b7290
// 005b7278  8b01                 mov eax, dword ptr [ecx]
// 005b727a  80781900             cmp byte ptr [eax + 0x19], 0
// 005b727e  750a                 jne 0x5b728a
// 005b7280  8bc8                 mov ecx, eax
// 005b7282  8b01                 mov eax, dword ptr [ecx]
// 005b7284  80781900             cmp byte ptr [eax + 0x19], 0
// 005b7288  74f6                 je 0x5b7280
// 005b728a  5f                   pop edi
// 005b728b  894e04               mov dword ptr [esi + 4], ecx
// 005b728e  5e                   pop esi
// 005b728f  c3                   ret 
// 005b7290  8b4004               mov eax, dword ptr [eax + 4]
// 005b7293  80781900             cmp byte ptr [eax + 0x19], 0
// 005b7297  751d                 jne 0x5b72b6
// 005b7299  8da42400000000       lea esp, [esp]
// 005b72a0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b72a3  3b4808               cmp ecx, dword ptr [eax + 8]
// 005b72a6  750e                 jne 0x5b72b6
// 005b72a8  894604               mov dword ptr [esi + 4], eax
// 005b72ab  8bd0                 mov edx, eax
// 005b72ad  8b4204               mov eax, dword ptr [edx + 4]
// 005b72b0  80781900             cmp byte ptr [eax + 0x19], 0
// 005b72b4  74ea                 je 0x5b72a0
// 005b72b6  5f                   pop edi
// 005b72b7  894604               mov dword ptr [esi + 4], eax
// 005b72ba  5e                   pop esi
// 005b72bb  c3                   ret 
// standard library set<double> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@QAEXXZ)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
