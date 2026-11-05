// from server: 100% by auto
// roc 2008-06 004139b0  unit: CopyVerb  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004139b0
//
// 004139b0  56                   push esi
// 004139b1  8bf1                 mov esi, ecx
// 004139b3  833e00               cmp dword ptr [esi], 0
// 004139b6  57                   push edi
// 004139b7  8b3d90288000         mov edi, dword ptr [0x802890]
// 004139bd  7502                 jne 0x4139c1
// 004139bf  ffd7                 call edi
// 004139c1  8b4604               mov eax, dword ptr [esi + 4]
// 004139c4  80784500             cmp byte ptr [eax + 0x45], 0
// 004139c8  7405                 je 0x4139cf
// 004139ca  ffd7                 call edi
// 004139cc  5f                   pop edi
// 004139cd  5e                   pop esi
// 004139ce  c3                   ret 
// 004139cf  8b4808               mov ecx, dword ptr [eax + 8]
// 004139d2  80794500             cmp byte ptr [ecx + 0x45], 0
// 004139d6  7518                 jne 0x4139f0
// 004139d8  8b01                 mov eax, dword ptr [ecx]
// 004139da  80784500             cmp byte ptr [eax + 0x45], 0
// 004139de  750a                 jne 0x4139ea
// 004139e0  8bc8                 mov ecx, eax
// 004139e2  8b01                 mov eax, dword ptr [ecx]
// 004139e4  80784500             cmp byte ptr [eax + 0x45], 0
// 004139e8  74f6                 je 0x4139e0
// 004139ea  5f                   pop edi
// 004139eb  894e04               mov dword ptr [esi + 4], ecx
// 004139ee  5e                   pop esi
// 004139ef  c3                   ret 
// 004139f0  8b4004               mov eax, dword ptr [eax + 4]
// 004139f3  80784500             cmp byte ptr [eax + 0x45], 0
// 004139f7  751d                 jne 0x413a16
// 004139f9  8da42400000000       lea esp, [esp]
// 00413a00  8b4e04               mov ecx, dword ptr [esi + 4]
// 00413a03  3b4808               cmp ecx, dword ptr [eax + 8]
// 00413a06  750e                 jne 0x413a16
// 00413a08  894604               mov dword ptr [esi + 4], eax
// 00413a0b  8bd0                 mov edx, eax
// 00413a0d  8b4204               mov eax, dword ptr [edx + 4]
// 00413a10  80784500             cmp byte ptr [eax + 0x45], 0
// 00413a14  74ea                 je 0x413a00
// 00413a16  5f                   pop edi
// 00413a17  894604               mov dword ptr [esi + 4], eax
// 00413a1a  5e                   pop esi
// 00413a1b  c3                   ret 
// standard library map_str<string> (function ?_Inc@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
