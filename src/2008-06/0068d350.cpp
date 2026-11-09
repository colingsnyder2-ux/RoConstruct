// from server: 100% by auto
// roc 2008-06 0068d350  unit: Ogre::VShadowCameraSetup::?$SharedPtr  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068d350
//
// 0068d350  56                   push esi
// 0068d351  8bf1                 mov esi, ecx
// 0068d353  833e00               cmp dword ptr [esi], 0
// 0068d356  57                   push edi
// 0068d357  8b3d90288000         mov edi, dword ptr [0x802890]
// 0068d35d  7502                 jne 0x68d361
// 0068d35f  ffd7                 call edi
// 0068d361  8b4604               mov eax, dword ptr [esi + 4]
// 0068d364  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0068d368  7411                 je 0x68d37b
// 0068d36a  8b4008               mov eax, dword ptr [eax + 8]
// 0068d36d  894604               mov dword ptr [esi + 4], eax
// 0068d370  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0068d374  745b                 je 0x68d3d1
// 0068d376  ffd7                 call edi
// 0068d378  5f                   pop edi
// 0068d379  5e                   pop esi
// 0068d37a  c3                   ret 
// 0068d37b  8b08                 mov ecx, dword ptr [eax]
// 0068d37d  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0068d381  751e                 jne 0x68d3a1
// 0068d383  8b4108               mov eax, dword ptr [ecx + 8]
// 0068d386  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0068d38a  750f                 jne 0x68d39b
// 0068d38c  8d642400             lea esp, [esp]
// 0068d390  8bc8                 mov ecx, eax
// 0068d392  8b4108               mov eax, dword ptr [ecx + 8]
// 0068d395  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0068d399  74f5                 je 0x68d390
// 0068d39b  5f                   pop edi
// 0068d39c  894e04               mov dword ptr [esi + 4], ecx
// 0068d39f  5e                   pop esi
// 0068d3a0  c3                   ret 
// 0068d3a1  8b4004               mov eax, dword ptr [eax + 4]
// 0068d3a4  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0068d3a8  751b                 jne 0x68d3c5
// 0068d3aa  8d9b00000000         lea ebx, [ebx]
// 0068d3b0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0068d3b3  3b08                 cmp ecx, dword ptr [eax]
// 0068d3b5  750e                 jne 0x68d3c5
// 0068d3b7  894604               mov dword ptr [esi + 4], eax
// 0068d3ba  8bd0                 mov edx, eax
// 0068d3bc  8b4204               mov eax, dword ptr [edx + 4]
// 0068d3bf  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0068d3c3  74eb                 je 0x68d3b0
// 0068d3c5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0068d3c8  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0068d3cc  75a8                 jne 0x68d376
// 0068d3ce  894604               mov dword ptr [esi + 4], eax
// 0068d3d1  5f                   pop edi
// 0068d3d2  5e                   pop esi
// 0068d3d3  c3                   ret 
// standard library map_int<string> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
