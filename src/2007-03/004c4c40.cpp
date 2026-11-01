// from server: 100% by auto
// roc 2007-03 004c4c40  unit: seg_004c0000  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004c4c40
//
// 004c4c40  56                   push esi
// 004c4c41  8bf1                 mov esi, ecx
// 004c4c43  833e00               cmp dword ptr [esi], 0
// 004c4c46  57                   push edi
// 004c4c47  8b3d44e97700         mov edi, dword ptr [0x77e944]
// 004c4c4d  7502                 jne 0x4c4c51
// 004c4c4f  ffd7                 call edi
// 004c4c51  8b4604               mov eax, dword ptr [esi + 4]
// 004c4c54  80782900             cmp byte ptr [eax + 0x29], 0
// 004c4c58  7405                 je 0x4c4c5f
// 004c4c5a  ffd7                 call edi
// 004c4c5c  5f                   pop edi
// 004c4c5d  5e                   pop esi
// 004c4c5e  c3                   ret 
// 004c4c5f  8b4808               mov ecx, dword ptr [eax + 8]
// 004c4c62  80792900             cmp byte ptr [ecx + 0x29], 0
// 004c4c66  7518                 jne 0x4c4c80
// 004c4c68  8b01                 mov eax, dword ptr [ecx]
// 004c4c6a  80782900             cmp byte ptr [eax + 0x29], 0
// 004c4c6e  750a                 jne 0x4c4c7a
// 004c4c70  8bc8                 mov ecx, eax
// 004c4c72  8b01                 mov eax, dword ptr [ecx]
// 004c4c74  80782900             cmp byte ptr [eax + 0x29], 0
// 004c4c78  74f6                 je 0x4c4c70
// 004c4c7a  5f                   pop edi
// 004c4c7b  894e04               mov dword ptr [esi + 4], ecx
// 004c4c7e  5e                   pop esi
// 004c4c7f  c3                   ret 
// 004c4c80  8b4004               mov eax, dword ptr [eax + 4]
// 004c4c83  80782900             cmp byte ptr [eax + 0x29], 0
// 004c4c87  751d                 jne 0x4c4ca6
// 004c4c89  8da42400000000       lea esp, [esp]
// 004c4c90  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c4c93  3b4808               cmp ecx, dword ptr [eax + 8]
// 004c4c96  750e                 jne 0x4c4ca6
// 004c4c98  894604               mov dword ptr [esi + 4], eax
// 004c4c9b  8bd0                 mov edx, eax
// 004c4c9d  8b4204               mov eax, dword ptr [edx + 4]
// 004c4ca0  80782900             cmp byte ptr [eax + 0x29], 0
// 004c4ca4  74ea                 je 0x4c4c90
// 004c4ca6  5f                   pop edi
// 004c4ca7  894604               mov dword ptr [esi + 4], eax
// 004c4caa  5e                   pop esi
// 004c4cab  c3                   ret 
// standard library set<string> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
