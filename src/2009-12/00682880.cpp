// from server: 100% by auto
// roc 2009-12 00682880  unit: RBX::Script  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00682880
//
// 00682880  56                   push esi
// 00682881  8bf1                 mov esi, ecx
// 00682883  833e00               cmp dword ptr [esi], 0
// 00682886  57                   push edi
// 00682887  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 0068288d  7502                 jne 0x682891
// 0068288f  ffd7                 call edi
// 00682891  8b4604               mov eax, dword ptr [esi + 4]
// 00682894  80784900             cmp byte ptr [eax + 0x49], 0
// 00682898  7411                 je 0x6828ab
// 0068289a  8b4008               mov eax, dword ptr [eax + 8]
// 0068289d  894604               mov dword ptr [esi + 4], eax
// 006828a0  80784900             cmp byte ptr [eax + 0x49], 0
// 006828a4  745b                 je 0x682901
// 006828a6  ffd7                 call edi
// 006828a8  5f                   pop edi
// 006828a9  5e                   pop esi
// 006828aa  c3                   ret 
// 006828ab  8b08                 mov ecx, dword ptr [eax]
// 006828ad  80794900             cmp byte ptr [ecx + 0x49], 0
// 006828b1  751e                 jne 0x6828d1
// 006828b3  8b4108               mov eax, dword ptr [ecx + 8]
// 006828b6  80784900             cmp byte ptr [eax + 0x49], 0
// 006828ba  750f                 jne 0x6828cb
// 006828bc  8d642400             lea esp, [esp]
// 006828c0  8bc8                 mov ecx, eax
// 006828c2  8b4108               mov eax, dword ptr [ecx + 8]
// 006828c5  80784900             cmp byte ptr [eax + 0x49], 0
// 006828c9  74f5                 je 0x6828c0
// 006828cb  5f                   pop edi
// 006828cc  894e04               mov dword ptr [esi + 4], ecx
// 006828cf  5e                   pop esi
// 006828d0  c3                   ret 
// 006828d1  8b4004               mov eax, dword ptr [eax + 4]
// 006828d4  80784900             cmp byte ptr [eax + 0x49], 0
// 006828d8  751b                 jne 0x6828f5
// 006828da  8d9b00000000         lea ebx, [ebx]
// 006828e0  8b4e04               mov ecx, dword ptr [esi + 4]
// 006828e3  3b08                 cmp ecx, dword ptr [eax]
// 006828e5  750e                 jne 0x6828f5
// 006828e7  894604               mov dword ptr [esi + 4], eax
// 006828ea  8bd0                 mov edx, eax
// 006828ec  8b4204               mov eax, dword ptr [edx + 4]
// 006828ef  80784900             cmp byte ptr [eax + 0x49], 0
// 006828f3  74eb                 je 0x6828e0
// 006828f5  8b4e04               mov ecx, dword ptr [esi + 4]
// 006828f8  80794900             cmp byte ptr [ecx + 0x49], 0
// 006828fc  75a8                 jne 0x6828a6
// 006828fe  894604               mov dword ptr [esi + 4], eax
// 00682901  5f                   pop edi
// 00682902  5e                   pop esi
// 00682903  c3                   ret 
// standard library map_str<pod32> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
