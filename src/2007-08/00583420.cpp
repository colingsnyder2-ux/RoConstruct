// from server: 100% by auto
// roc 2007-08 00583420  unit: RBX::VHat::?$FactoryProduct  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00583420
//
// 00583420  56                   push esi
// 00583421  8bf1                 mov esi, ecx
// 00583423  833e00               cmp dword ptr [esi], 0
// 00583426  57                   push edi
// 00583427  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 0058342d  7502                 jne 0x583431
// 0058342f  ffd7                 call edi
// 00583431  8b4604               mov eax, dword ptr [esi + 4]
// 00583434  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00583438  7411                 je 0x58344b
// 0058343a  8b4008               mov eax, dword ptr [eax + 8]
// 0058343d  894604               mov dword ptr [esi + 4], eax
// 00583440  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00583444  745b                 je 0x5834a1
// 00583446  ffd7                 call edi
// 00583448  5f                   pop edi
// 00583449  5e                   pop esi
// 0058344a  c3                   ret 
// 0058344b  8b08                 mov ecx, dword ptr [eax]
// 0058344d  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00583451  751e                 jne 0x583471
// 00583453  8b4108               mov eax, dword ptr [ecx + 8]
// 00583456  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0058345a  750f                 jne 0x58346b
// 0058345c  8d642400             lea esp, [esp]
// 00583460  8bc8                 mov ecx, eax
// 00583462  8b4108               mov eax, dword ptr [ecx + 8]
// 00583465  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00583469  74f5                 je 0x583460
// 0058346b  5f                   pop edi
// 0058346c  894e04               mov dword ptr [esi + 4], ecx
// 0058346f  5e                   pop esi
// 00583470  c3                   ret 
// 00583471  8b4004               mov eax, dword ptr [eax + 4]
// 00583474  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00583478  751b                 jne 0x583495
// 0058347a  8d9b00000000         lea ebx, [ebx]
// 00583480  8b4e04               mov ecx, dword ptr [esi + 4]
// 00583483  3b08                 cmp ecx, dword ptr [eax]
// 00583485  750e                 jne 0x583495
// 00583487  894604               mov dword ptr [esi + 4], eax
// 0058348a  8bd0                 mov edx, eax
// 0058348c  8b4204               mov eax, dword ptr [edx + 4]
// 0058348f  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00583493  74eb                 je 0x583480
// 00583495  8b4e04               mov ecx, dword ptr [esi + 4]
// 00583498  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0058349c  75a8                 jne 0x583446
// 0058349e  894604               mov dword ptr [esi + 4], eax
// 005834a1  5f                   pop edi
// 005834a2  5e                   pop esi
// 005834a3  c3                   ret 
// standard library map_int<string> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
