// from server: 100% by auto
// roc 2008-06 0058d6f0  unit: RBX::ChangeHistoryService  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0058d6f0
//
// 0058d6f0  56                   push esi
// 0058d6f1  8bf1                 mov esi, ecx
// 0058d6f3  833e00               cmp dword ptr [esi], 0
// 0058d6f6  57                   push edi
// 0058d6f7  8b3d90288000         mov edi, dword ptr [0x802890]
// 0058d6fd  7502                 jne 0x58d701
// 0058d6ff  ffd7                 call edi
// 0058d701  8b4604               mov eax, dword ptr [esi + 4]
// 0058d704  80784500             cmp byte ptr [eax + 0x45], 0
// 0058d708  7411                 je 0x58d71b
// 0058d70a  8b4008               mov eax, dword ptr [eax + 8]
// 0058d70d  894604               mov dword ptr [esi + 4], eax
// 0058d710  80784500             cmp byte ptr [eax + 0x45], 0
// 0058d714  745b                 je 0x58d771
// 0058d716  ffd7                 call edi
// 0058d718  5f                   pop edi
// 0058d719  5e                   pop esi
// 0058d71a  c3                   ret 
// 0058d71b  8b08                 mov ecx, dword ptr [eax]
// 0058d71d  80794500             cmp byte ptr [ecx + 0x45], 0
// 0058d721  751e                 jne 0x58d741
// 0058d723  8b4108               mov eax, dword ptr [ecx + 8]
// 0058d726  80784500             cmp byte ptr [eax + 0x45], 0
// 0058d72a  750f                 jne 0x58d73b
// 0058d72c  8d642400             lea esp, [esp]
// 0058d730  8bc8                 mov ecx, eax
// 0058d732  8b4108               mov eax, dword ptr [ecx + 8]
// 0058d735  80784500             cmp byte ptr [eax + 0x45], 0
// 0058d739  74f5                 je 0x58d730
// 0058d73b  5f                   pop edi
// 0058d73c  894e04               mov dword ptr [esi + 4], ecx
// 0058d73f  5e                   pop esi
// 0058d740  c3                   ret 
// 0058d741  8b4004               mov eax, dword ptr [eax + 4]
// 0058d744  80784500             cmp byte ptr [eax + 0x45], 0
// 0058d748  751b                 jne 0x58d765
// 0058d74a  8d9b00000000         lea ebx, [ebx]
// 0058d750  8b4e04               mov ecx, dword ptr [esi + 4]
// 0058d753  3b08                 cmp ecx, dword ptr [eax]
// 0058d755  750e                 jne 0x58d765
// 0058d757  894604               mov dword ptr [esi + 4], eax
// 0058d75a  8bd0                 mov edx, eax
// 0058d75c  8b4204               mov eax, dword ptr [edx + 4]
// 0058d75f  80784500             cmp byte ptr [eax + 0x45], 0
// 0058d763  74eb                 je 0x58d750
// 0058d765  8b4e04               mov ecx, dword ptr [esi + 4]
// 0058d768  80794500             cmp byte ptr [ecx + 0x45], 0
// 0058d76c  75a8                 jne 0x58d716
// 0058d76e  894604               mov dword ptr [esi + 4], eax
// 0058d771  5f                   pop edi
// 0058d772  5e                   pop esi
// 0058d773  c3                   ret 
// standard library map_str<string> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
