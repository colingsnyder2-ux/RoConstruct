// from server: 100% by auto
// roc 2010-06 005efba0  unit: RBX::ChangeHistoryService  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005efba0
//
// 005efba0  56                   push esi
// 005efba1  8bf1                 mov esi, ecx
// 005efba3  833e00               cmp dword ptr [esi], 0
// 005efba6  57                   push edi
// 005efba7  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 005efbad  7502                 jne 0x5efbb1
// 005efbaf  ffd7                 call edi
// 005efbb1  8b4604               mov eax, dword ptr [esi + 4]
// 005efbb4  80784500             cmp byte ptr [eax + 0x45], 0
// 005efbb8  7411                 je 0x5efbcb
// 005efbba  8b4008               mov eax, dword ptr [eax + 8]
// 005efbbd  894604               mov dword ptr [esi + 4], eax
// 005efbc0  80784500             cmp byte ptr [eax + 0x45], 0
// 005efbc4  745b                 je 0x5efc21
// 005efbc6  ffd7                 call edi
// 005efbc8  5f                   pop edi
// 005efbc9  5e                   pop esi
// 005efbca  c3                   ret 
// 005efbcb  8b08                 mov ecx, dword ptr [eax]
// 005efbcd  80794500             cmp byte ptr [ecx + 0x45], 0
// 005efbd1  751e                 jne 0x5efbf1
// 005efbd3  8b4108               mov eax, dword ptr [ecx + 8]
// 005efbd6  80784500             cmp byte ptr [eax + 0x45], 0
// 005efbda  750f                 jne 0x5efbeb
// 005efbdc  8d642400             lea esp, [esp]
// 005efbe0  8bc8                 mov ecx, eax
// 005efbe2  8b4108               mov eax, dword ptr [ecx + 8]
// 005efbe5  80784500             cmp byte ptr [eax + 0x45], 0
// 005efbe9  74f5                 je 0x5efbe0
// 005efbeb  5f                   pop edi
// 005efbec  894e04               mov dword ptr [esi + 4], ecx
// 005efbef  5e                   pop esi
// 005efbf0  c3                   ret 
// 005efbf1  8b4004               mov eax, dword ptr [eax + 4]
// 005efbf4  80784500             cmp byte ptr [eax + 0x45], 0
// 005efbf8  751b                 jne 0x5efc15
// 005efbfa  8d9b00000000         lea ebx, [ebx]
// 005efc00  8b4e04               mov ecx, dword ptr [esi + 4]
// 005efc03  3b08                 cmp ecx, dword ptr [eax]
// 005efc05  750e                 jne 0x5efc15
// 005efc07  894604               mov dword ptr [esi + 4], eax
// 005efc0a  8bd0                 mov edx, eax
// 005efc0c  8b4204               mov eax, dword ptr [edx + 4]
// 005efc0f  80784500             cmp byte ptr [eax + 0x45], 0
// 005efc13  74eb                 je 0x5efc00
// 005efc15  8b4e04               mov ecx, dword ptr [esi + 4]
// 005efc18  80794500             cmp byte ptr [ecx + 0x45], 0
// 005efc1c  75a8                 jne 0x5efbc6
// 005efc1e  894604               mov dword ptr [esi + 4], eax
// 005efc21  5f                   pop edi
// 005efc22  5e                   pop esi
// 005efc23  c3                   ret 
// standard library map_str<string> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
