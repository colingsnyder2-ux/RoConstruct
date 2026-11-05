// from server: 100% by auto
// roc 2008-06 0055cb20  unit: RBX::MD5HasherImpl  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055cb20
//
// 0055cb20  56                   push esi
// 0055cb21  8bf1                 mov esi, ecx
// 0055cb23  833e00               cmp dword ptr [esi], 0
// 0055cb26  57                   push edi
// 0055cb27  8b3d90288000         mov edi, dword ptr [0x802890]
// 0055cb2d  7502                 jne 0x55cb31
// 0055cb2f  ffd7                 call edi
// 0055cb31  8b4604               mov eax, dword ptr [esi + 4]
// 0055cb34  80783d00             cmp byte ptr [eax + 0x3d], 0
// 0055cb38  7411                 je 0x55cb4b
// 0055cb3a  8b4008               mov eax, dword ptr [eax + 8]
// 0055cb3d  894604               mov dword ptr [esi + 4], eax
// 0055cb40  80783d00             cmp byte ptr [eax + 0x3d], 0
// 0055cb44  745b                 je 0x55cba1
// 0055cb46  ffd7                 call edi
// 0055cb48  5f                   pop edi
// 0055cb49  5e                   pop esi
// 0055cb4a  c3                   ret 
// 0055cb4b  8b08                 mov ecx, dword ptr [eax]
// 0055cb4d  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 0055cb51  751e                 jne 0x55cb71
// 0055cb53  8b4108               mov eax, dword ptr [ecx + 8]
// 0055cb56  80783d00             cmp byte ptr [eax + 0x3d], 0
// 0055cb5a  750f                 jne 0x55cb6b
// 0055cb5c  8d642400             lea esp, [esp]
// 0055cb60  8bc8                 mov ecx, eax
// 0055cb62  8b4108               mov eax, dword ptr [ecx + 8]
// 0055cb65  80783d00             cmp byte ptr [eax + 0x3d], 0
// 0055cb69  74f5                 je 0x55cb60
// 0055cb6b  5f                   pop edi
// 0055cb6c  894e04               mov dword ptr [esi + 4], ecx
// 0055cb6f  5e                   pop esi
// 0055cb70  c3                   ret 
// 0055cb71  8b4004               mov eax, dword ptr [eax + 4]
// 0055cb74  80783d00             cmp byte ptr [eax + 0x3d], 0
// 0055cb78  751b                 jne 0x55cb95
// 0055cb7a  8d9b00000000         lea ebx, [ebx]
// 0055cb80  8b4e04               mov ecx, dword ptr [esi + 4]
// 0055cb83  3b08                 cmp ecx, dword ptr [eax]
// 0055cb85  750e                 jne 0x55cb95
// 0055cb87  894604               mov dword ptr [esi + 4], eax
// 0055cb8a  8bd0                 mov edx, eax
// 0055cb8c  8b4204               mov eax, dword ptr [edx + 4]
// 0055cb8f  80783d00             cmp byte ptr [eax + 0x3d], 0
// 0055cb93  74eb                 je 0x55cb80
// 0055cb95  8b4e04               mov ecx, dword ptr [esi + 4]
// 0055cb98  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 0055cb9c  75a8                 jne 0x55cb46
// 0055cb9e  894604               mov dword ptr [esi + 4], eax
// 0055cba1  5f                   pop edi
// 0055cba2  5e                   pop esi
// 0055cba3  c3                   ret 
// standard library map_str<pod20> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<pod20>
struct E { int v[5]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
