// from server: 100% by auto
// roc 2007-03 00618630  unit: seg_00610000  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00618630
//
// 00618630  56                   push esi
// 00618631  8bf1                 mov esi, ecx
// 00618633  833e00               cmp dword ptr [esi], 0
// 00618636  57                   push edi
// 00618637  8b3d44e97700         mov edi, dword ptr [0x77e944]
// 0061863d  7502                 jne 0x618641
// 0061863f  ffd7                 call edi
// 00618641  8b4604               mov eax, dword ptr [esi + 4]
// 00618644  80780e00             cmp byte ptr [eax + 0xe], 0
// 00618648  7405                 je 0x61864f
// 0061864a  ffd7                 call edi
// 0061864c  5f                   pop edi
// 0061864d  5e                   pop esi
// 0061864e  c3                   ret 
// 0061864f  8b4808               mov ecx, dword ptr [eax + 8]
// 00618652  80790e00             cmp byte ptr [ecx + 0xe], 0
// 00618656  7518                 jne 0x618670
// 00618658  8b01                 mov eax, dword ptr [ecx]
// 0061865a  80780e00             cmp byte ptr [eax + 0xe], 0
// 0061865e  750a                 jne 0x61866a
// 00618660  8bc8                 mov ecx, eax
// 00618662  8b01                 mov eax, dword ptr [ecx]
// 00618664  80780e00             cmp byte ptr [eax + 0xe], 0
// 00618668  74f6                 je 0x618660
// 0061866a  5f                   pop edi
// 0061866b  894e04               mov dword ptr [esi + 4], ecx
// 0061866e  5e                   pop esi
// 0061866f  c3                   ret 
// 00618670  8b4004               mov eax, dword ptr [eax + 4]
// 00618673  80780e00             cmp byte ptr [eax + 0xe], 0
// 00618677  751d                 jne 0x618696
// 00618679  8da42400000000       lea esp, [esp]
// 00618680  8b4e04               mov ecx, dword ptr [esi + 4]
// 00618683  3b4808               cmp ecx, dword ptr [eax + 8]
// 00618686  750e                 jne 0x618696
// 00618688  894604               mov dword ptr [esi + 4], eax
// 0061868b  8bd0                 mov edx, eax
// 0061868d  8b4204               mov eax, dword ptr [edx + 4]
// 00618690  80780e00             cmp byte ptr [eax + 0xe], 0
// 00618694  74ea                 je 0x618680
// 00618696  5f                   pop edi
// 00618697  894604               mov dword ptr [esi + 4], eax
// 0061869a  5e                   pop esi
// 0061869b  c3                   ret 
// standard library set<char> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@QAEXXZ)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
