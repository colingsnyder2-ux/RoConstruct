// from server: 100% by auto
// roc 2007-08 00627240  unit: RBX::SeparateStage  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00627240
//
// 00627240  56                   push esi
// 00627241  8bf1                 mov esi, ecx
// 00627243  833e00               cmp dword ptr [esi], 0
// 00627246  57                   push edi
// 00627247  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 0062724d  7502                 jne 0x627251
// 0062724f  ffd7                 call edi
// 00627251  8b4604               mov eax, dword ptr [esi + 4]
// 00627254  80781100             cmp byte ptr [eax + 0x11], 0
// 00627258  7405                 je 0x62725f
// 0062725a  ffd7                 call edi
// 0062725c  5f                   pop edi
// 0062725d  5e                   pop esi
// 0062725e  c3                   ret 
// 0062725f  8b4808               mov ecx, dword ptr [eax + 8]
// 00627262  80791100             cmp byte ptr [ecx + 0x11], 0
// 00627266  7518                 jne 0x627280
// 00627268  8b01                 mov eax, dword ptr [ecx]
// 0062726a  80781100             cmp byte ptr [eax + 0x11], 0
// 0062726e  750a                 jne 0x62727a
// 00627270  8bc8                 mov ecx, eax
// 00627272  8b01                 mov eax, dword ptr [ecx]
// 00627274  80781100             cmp byte ptr [eax + 0x11], 0
// 00627278  74f6                 je 0x627270
// 0062727a  5f                   pop edi
// 0062727b  894e04               mov dword ptr [esi + 4], ecx
// 0062727e  5e                   pop esi
// 0062727f  c3                   ret 
// 00627280  8b4004               mov eax, dword ptr [eax + 4]
// 00627283  80781100             cmp byte ptr [eax + 0x11], 0
// 00627287  751d                 jne 0x6272a6
// 00627289  8da42400000000       lea esp, [esp]
// 00627290  8b4e04               mov ecx, dword ptr [esi + 4]
// 00627293  3b4808               cmp ecx, dword ptr [eax + 8]
// 00627296  750e                 jne 0x6272a6
// 00627298  894604               mov dword ptr [esi + 4], eax
// 0062729b  8bd0                 mov edx, eax
// 0062729d  8b4204               mov eax, dword ptr [edx + 4]
// 006272a0  80781100             cmp byte ptr [eax + 0x11], 0
// 006272a4  74ea                 je 0x627290
// 006272a6  5f                   pop edi
// 006272a7  894604               mov dword ptr [esi + 4], eax
// 006272aa  5e                   pop esi
// 006272ab  c3                   ret 
// standard library set<ptr> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
