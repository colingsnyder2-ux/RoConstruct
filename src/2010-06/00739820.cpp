// from server: 100% by auto
// roc 2010-06 00739820  unit: seg_00730000  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00739820
//
// 00739820  56                   push esi
// 00739821  8bf1                 mov esi, ecx
// 00739823  833e00               cmp dword ptr [esi], 0
// 00739826  57                   push edi
// 00739827  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 0073982d  7502                 jne 0x739831
// 0073982f  ffd7                 call edi
// 00739831  8b4604               mov eax, dword ptr [esi + 4]
// 00739834  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00739838  7411                 je 0x73984b
// 0073983a  8b4008               mov eax, dword ptr [eax + 8]
// 0073983d  894604               mov dword ptr [esi + 4], eax
// 00739840  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00739844  745b                 je 0x7398a1
// 00739846  ffd7                 call edi
// 00739848  5f                   pop edi
// 00739849  5e                   pop esi
// 0073984a  c3                   ret 
// 0073984b  8b08                 mov ecx, dword ptr [eax]
// 0073984d  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00739851  751e                 jne 0x739871
// 00739853  8b4108               mov eax, dword ptr [ecx + 8]
// 00739856  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0073985a  750f                 jne 0x73986b
// 0073985c  8d642400             lea esp, [esp]
// 00739860  8bc8                 mov ecx, eax
// 00739862  8b4108               mov eax, dword ptr [ecx + 8]
// 00739865  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00739869  74f5                 je 0x739860
// 0073986b  5f                   pop edi
// 0073986c  894e04               mov dword ptr [esi + 4], ecx
// 0073986f  5e                   pop esi
// 00739870  c3                   ret 
// 00739871  8b4004               mov eax, dword ptr [eax + 4]
// 00739874  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00739878  751b                 jne 0x739895
// 0073987a  8d9b00000000         lea ebx, [ebx]
// 00739880  8b4e04               mov ecx, dword ptr [esi + 4]
// 00739883  3b08                 cmp ecx, dword ptr [eax]
// 00739885  750e                 jne 0x739895
// 00739887  894604               mov dword ptr [esi + 4], eax
// 0073988a  8bd0                 mov edx, eax
// 0073988c  8b4204               mov eax, dword ptr [edx + 4]
// 0073988f  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00739893  74eb                 je 0x739880
// 00739895  8b4e04               mov ecx, dword ptr [esi + 4]
// 00739898  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0073989c  75a8                 jne 0x739846
// 0073989e  894604               mov dword ptr [esi + 4], eax
// 007398a1  5f                   pop edi
// 007398a2  5e                   pop esi
// 007398a3  c3                   ret 
// standard library map_int<string> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
