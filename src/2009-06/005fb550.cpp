// from server: 100% by auto
// roc 2009-06 005fb550  unit: RBX::DataModel  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005fb550
//
// 005fb550  56                   push esi
// 005fb551  8bf1                 mov esi, ecx
// 005fb553  833e00               cmp dword ptr [esi], 0
// 005fb556  57                   push edi
// 005fb557  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 005fb55d  7502                 jne 0x5fb561
// 005fb55f  ffd7                 call edi
// 005fb561  8b4604               mov eax, dword ptr [esi + 4]
// 005fb564  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005fb568  7411                 je 0x5fb57b
// 005fb56a  8b4008               mov eax, dword ptr [eax + 8]
// 005fb56d  894604               mov dword ptr [esi + 4], eax
// 005fb570  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005fb574  745b                 je 0x5fb5d1
// 005fb576  ffd7                 call edi
// 005fb578  5f                   pop edi
// 005fb579  5e                   pop esi
// 005fb57a  c3                   ret 
// 005fb57b  8b08                 mov ecx, dword ptr [eax]
// 005fb57d  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 005fb581  751e                 jne 0x5fb5a1
// 005fb583  8b4108               mov eax, dword ptr [ecx + 8]
// 005fb586  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005fb58a  750f                 jne 0x5fb59b
// 005fb58c  8d642400             lea esp, [esp]
// 005fb590  8bc8                 mov ecx, eax
// 005fb592  8b4108               mov eax, dword ptr [ecx + 8]
// 005fb595  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005fb599  74f5                 je 0x5fb590
// 005fb59b  5f                   pop edi
// 005fb59c  894e04               mov dword ptr [esi + 4], ecx
// 005fb59f  5e                   pop esi
// 005fb5a0  c3                   ret 
// 005fb5a1  8b4004               mov eax, dword ptr [eax + 4]
// 005fb5a4  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005fb5a8  751b                 jne 0x5fb5c5
// 005fb5aa  8d9b00000000         lea ebx, [ebx]
// 005fb5b0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005fb5b3  3b08                 cmp ecx, dword ptr [eax]
// 005fb5b5  750e                 jne 0x5fb5c5
// 005fb5b7  894604               mov dword ptr [esi + 4], eax
// 005fb5ba  8bd0                 mov edx, eax
// 005fb5bc  8b4204               mov eax, dword ptr [edx + 4]
// 005fb5bf  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005fb5c3  74eb                 je 0x5fb5b0
// 005fb5c5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005fb5c8  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 005fb5cc  75a8                 jne 0x5fb576
// 005fb5ce  894604               mov dword ptr [esi + 4], eax
// 005fb5d1  5f                   pop edi
// 005fb5d2  5e                   pop esi
// 005fb5d3  c3                   ret 
// standard library map_int<string> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
