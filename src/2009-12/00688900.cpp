// from server: 100% by auto
// roc 2009-12 00688900  unit: RBX::ChangeHistoryService  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00688900
//
// 00688900  56                   push esi
// 00688901  8bf1                 mov esi, ecx
// 00688903  833e00               cmp dword ptr [esi], 0
// 00688906  57                   push edi
// 00688907  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 0068890d  7502                 jne 0x688911
// 0068890f  ffd7                 call edi
// 00688911  8b4604               mov eax, dword ptr [esi + 4]
// 00688914  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00688918  7411                 je 0x68892b
// 0068891a  8b4008               mov eax, dword ptr [eax + 8]
// 0068891d  894604               mov dword ptr [esi + 4], eax
// 00688920  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00688924  745b                 je 0x688981
// 00688926  ffd7                 call edi
// 00688928  5f                   pop edi
// 00688929  5e                   pop esi
// 0068892a  c3                   ret 
// 0068892b  8b08                 mov ecx, dword ptr [eax]
// 0068892d  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00688931  751e                 jne 0x688951
// 00688933  8b4108               mov eax, dword ptr [ecx + 8]
// 00688936  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0068893a  750f                 jne 0x68894b
// 0068893c  8d642400             lea esp, [esp]
// 00688940  8bc8                 mov ecx, eax
// 00688942  8b4108               mov eax, dword ptr [ecx + 8]
// 00688945  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00688949  74f5                 je 0x688940
// 0068894b  5f                   pop edi
// 0068894c  894e04               mov dword ptr [esi + 4], ecx
// 0068894f  5e                   pop esi
// 00688950  c3                   ret 
// 00688951  8b4004               mov eax, dword ptr [eax + 4]
// 00688954  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00688958  751b                 jne 0x688975
// 0068895a  8d9b00000000         lea ebx, [ebx]
// 00688960  8b4e04               mov ecx, dword ptr [esi + 4]
// 00688963  3b08                 cmp ecx, dword ptr [eax]
// 00688965  750e                 jne 0x688975
// 00688967  894604               mov dword ptr [esi + 4], eax
// 0068896a  8bd0                 mov edx, eax
// 0068896c  8b4204               mov eax, dword ptr [edx + 4]
// 0068896f  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00688973  74eb                 je 0x688960
// 00688975  8b4e04               mov ecx, dword ptr [esi + 4]
// 00688978  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0068897c  75a8                 jne 0x688926
// 0068897e  894604               mov dword ptr [esi + 4], eax
// 00688981  5f                   pop edi
// 00688982  5e                   pop esi
// 00688983  c3                   ret 
// standard library map_int<string> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
