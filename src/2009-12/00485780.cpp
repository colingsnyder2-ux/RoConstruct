// from server: 100% by auto
// roc 2009-12 00485780  unit: Ogre::GfxClustererPart  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00485780
//
// 00485780  56                   push esi
// 00485781  8bf1                 mov esi, ecx
// 00485783  833e00               cmp dword ptr [esi], 0
// 00485786  57                   push edi
// 00485787  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 0048578d  7502                 jne 0x485791
// 0048578f  ffd7                 call edi
// 00485791  8b4604               mov eax, dword ptr [esi + 4]
// 00485794  80784500             cmp byte ptr [eax + 0x45], 0
// 00485798  7411                 je 0x4857ab
// 0048579a  8b4008               mov eax, dword ptr [eax + 8]
// 0048579d  894604               mov dword ptr [esi + 4], eax
// 004857a0  80784500             cmp byte ptr [eax + 0x45], 0
// 004857a4  745b                 je 0x485801
// 004857a6  ffd7                 call edi
// 004857a8  5f                   pop edi
// 004857a9  5e                   pop esi
// 004857aa  c3                   ret 
// 004857ab  8b08                 mov ecx, dword ptr [eax]
// 004857ad  80794500             cmp byte ptr [ecx + 0x45], 0
// 004857b1  751e                 jne 0x4857d1
// 004857b3  8b4108               mov eax, dword ptr [ecx + 8]
// 004857b6  80784500             cmp byte ptr [eax + 0x45], 0
// 004857ba  750f                 jne 0x4857cb
// 004857bc  8d642400             lea esp, [esp]
// 004857c0  8bc8                 mov ecx, eax
// 004857c2  8b4108               mov eax, dword ptr [ecx + 8]
// 004857c5  80784500             cmp byte ptr [eax + 0x45], 0
// 004857c9  74f5                 je 0x4857c0
// 004857cb  5f                   pop edi
// 004857cc  894e04               mov dword ptr [esi + 4], ecx
// 004857cf  5e                   pop esi
// 004857d0  c3                   ret 
// 004857d1  8b4004               mov eax, dword ptr [eax + 4]
// 004857d4  80784500             cmp byte ptr [eax + 0x45], 0
// 004857d8  751b                 jne 0x4857f5
// 004857da  8d9b00000000         lea ebx, [ebx]
// 004857e0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004857e3  3b08                 cmp ecx, dword ptr [eax]
// 004857e5  750e                 jne 0x4857f5
// 004857e7  894604               mov dword ptr [esi + 4], eax
// 004857ea  8bd0                 mov edx, eax
// 004857ec  8b4204               mov eax, dword ptr [edx + 4]
// 004857ef  80784500             cmp byte ptr [eax + 0x45], 0
// 004857f3  74eb                 je 0x4857e0
// 004857f5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004857f8  80794500             cmp byte ptr [ecx + 0x45], 0
// 004857fc  75a8                 jne 0x4857a6
// 004857fe  894604               mov dword ptr [esi + 4], eax
// 00485801  5f                   pop edi
// 00485802  5e                   pop esi
// 00485803  c3                   ret 
// standard library map_str<string> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
