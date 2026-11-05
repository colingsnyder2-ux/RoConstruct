// from server: 100% by auto
// roc 2008-06 00587140  unit: RBX::LocalScript  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00587140
//
// 00587140  56                   push esi
// 00587141  8bf1                 mov esi, ecx
// 00587143  833e00               cmp dword ptr [esi], 0
// 00587146  57                   push edi
// 00587147  8b3d90288000         mov edi, dword ptr [0x802890]
// 0058714d  7502                 jne 0x587151
// 0058714f  ffd7                 call edi
// 00587151  8b4604               mov eax, dword ptr [esi + 4]
// 00587154  80784900             cmp byte ptr [eax + 0x49], 0
// 00587158  7411                 je 0x58716b
// 0058715a  8b4008               mov eax, dword ptr [eax + 8]
// 0058715d  894604               mov dword ptr [esi + 4], eax
// 00587160  80784900             cmp byte ptr [eax + 0x49], 0
// 00587164  745b                 je 0x5871c1
// 00587166  ffd7                 call edi
// 00587168  5f                   pop edi
// 00587169  5e                   pop esi
// 0058716a  c3                   ret 
// 0058716b  8b08                 mov ecx, dword ptr [eax]
// 0058716d  80794900             cmp byte ptr [ecx + 0x49], 0
// 00587171  751e                 jne 0x587191
// 00587173  8b4108               mov eax, dword ptr [ecx + 8]
// 00587176  80784900             cmp byte ptr [eax + 0x49], 0
// 0058717a  750f                 jne 0x58718b
// 0058717c  8d642400             lea esp, [esp]
// 00587180  8bc8                 mov ecx, eax
// 00587182  8b4108               mov eax, dword ptr [ecx + 8]
// 00587185  80784900             cmp byte ptr [eax + 0x49], 0
// 00587189  74f5                 je 0x587180
// 0058718b  5f                   pop edi
// 0058718c  894e04               mov dword ptr [esi + 4], ecx
// 0058718f  5e                   pop esi
// 00587190  c3                   ret 
// 00587191  8b4004               mov eax, dword ptr [eax + 4]
// 00587194  80784900             cmp byte ptr [eax + 0x49], 0
// 00587198  751b                 jne 0x5871b5
// 0058719a  8d9b00000000         lea ebx, [ebx]
// 005871a0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005871a3  3b08                 cmp ecx, dword ptr [eax]
// 005871a5  750e                 jne 0x5871b5
// 005871a7  894604               mov dword ptr [esi + 4], eax
// 005871aa  8bd0                 mov edx, eax
// 005871ac  8b4204               mov eax, dword ptr [edx + 4]
// 005871af  80784900             cmp byte ptr [eax + 0x49], 0
// 005871b3  74eb                 je 0x5871a0
// 005871b5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005871b8  80794900             cmp byte ptr [ecx + 0x49], 0
// 005871bc  75a8                 jne 0x587166
// 005871be  894604               mov dword ptr [esi + 4], eax
// 005871c1  5f                   pop edi
// 005871c2  5e                   pop esi
// 005871c3  c3                   ret 
// standard library map_str<pod32> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
