// from server: 100% by auto
// roc 2007-08 004d08e0  unit: RBX::View::PartChunk  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d08e0
//
// 004d08e0  56                   push esi
// 004d08e1  8bf1                 mov esi, ecx
// 004d08e3  833e00               cmp dword ptr [esi], 0
// 004d08e6  57                   push edi
// 004d08e7  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 004d08ed  7502                 jne 0x4d08f1
// 004d08ef  ffd7                 call edi
// 004d08f1  8b4604               mov eax, dword ptr [esi + 4]
// 004d08f4  80782900             cmp byte ptr [eax + 0x29], 0
// 004d08f8  7405                 je 0x4d08ff
// 004d08fa  ffd7                 call edi
// 004d08fc  5f                   pop edi
// 004d08fd  5e                   pop esi
// 004d08fe  c3                   ret 
// 004d08ff  8b4808               mov ecx, dword ptr [eax + 8]
// 004d0902  80792900             cmp byte ptr [ecx + 0x29], 0
// 004d0906  7518                 jne 0x4d0920
// 004d0908  8b01                 mov eax, dword ptr [ecx]
// 004d090a  80782900             cmp byte ptr [eax + 0x29], 0
// 004d090e  750a                 jne 0x4d091a
// 004d0910  8bc8                 mov ecx, eax
// 004d0912  8b01                 mov eax, dword ptr [ecx]
// 004d0914  80782900             cmp byte ptr [eax + 0x29], 0
// 004d0918  74f6                 je 0x4d0910
// 004d091a  5f                   pop edi
// 004d091b  894e04               mov dword ptr [esi + 4], ecx
// 004d091e  5e                   pop esi
// 004d091f  c3                   ret 
// 004d0920  8b4004               mov eax, dword ptr [eax + 4]
// 004d0923  80782900             cmp byte ptr [eax + 0x29], 0
// 004d0927  751d                 jne 0x4d0946
// 004d0929  8da42400000000       lea esp, [esp]
// 004d0930  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d0933  3b4808               cmp ecx, dword ptr [eax + 8]
// 004d0936  750e                 jne 0x4d0946
// 004d0938  894604               mov dword ptr [esi + 4], eax
// 004d093b  8bd0                 mov edx, eax
// 004d093d  8b4204               mov eax, dword ptr [edx + 4]
// 004d0940  80782900             cmp byte ptr [eax + 0x29], 0
// 004d0944  74ea                 je 0x4d0930
// 004d0946  5f                   pop edi
// 004d0947  894604               mov dword ptr [esi + 4], eax
// 004d094a  5e                   pop esi
// 004d094b  c3                   ret 
// standard library set<string> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
