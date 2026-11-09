// from server: 100% by auto
// roc 2010-06 005e9930  unit: RBX::VModelInstance::?$BoundFuncDesc  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005e9930
//
// 005e9930  56                   push esi
// 005e9931  8bf1                 mov esi, ecx
// 005e9933  833e00               cmp dword ptr [esi], 0
// 005e9936  57                   push edi
// 005e9937  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 005e993d  7502                 jne 0x5e9941
// 005e993f  ffd7                 call edi
// 005e9941  8b4604               mov eax, dword ptr [esi + 4]
// 005e9944  80784900             cmp byte ptr [eax + 0x49], 0
// 005e9948  7411                 je 0x5e995b
// 005e994a  8b4008               mov eax, dword ptr [eax + 8]
// 005e994d  894604               mov dword ptr [esi + 4], eax
// 005e9950  80784900             cmp byte ptr [eax + 0x49], 0
// 005e9954  745b                 je 0x5e99b1
// 005e9956  ffd7                 call edi
// 005e9958  5f                   pop edi
// 005e9959  5e                   pop esi
// 005e995a  c3                   ret 
// 005e995b  8b08                 mov ecx, dword ptr [eax]
// 005e995d  80794900             cmp byte ptr [ecx + 0x49], 0
// 005e9961  751e                 jne 0x5e9981
// 005e9963  8b4108               mov eax, dword ptr [ecx + 8]
// 005e9966  80784900             cmp byte ptr [eax + 0x49], 0
// 005e996a  750f                 jne 0x5e997b
// 005e996c  8d642400             lea esp, [esp]
// 005e9970  8bc8                 mov ecx, eax
// 005e9972  8b4108               mov eax, dword ptr [ecx + 8]
// 005e9975  80784900             cmp byte ptr [eax + 0x49], 0
// 005e9979  74f5                 je 0x5e9970
// 005e997b  5f                   pop edi
// 005e997c  894e04               mov dword ptr [esi + 4], ecx
// 005e997f  5e                   pop esi
// 005e9980  c3                   ret 
// 005e9981  8b4004               mov eax, dword ptr [eax + 4]
// 005e9984  80784900             cmp byte ptr [eax + 0x49], 0
// 005e9988  751b                 jne 0x5e99a5
// 005e998a  8d9b00000000         lea ebx, [ebx]
// 005e9990  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e9993  3b08                 cmp ecx, dword ptr [eax]
// 005e9995  750e                 jne 0x5e99a5
// 005e9997  894604               mov dword ptr [esi + 4], eax
// 005e999a  8bd0                 mov edx, eax
// 005e999c  8b4204               mov eax, dword ptr [edx + 4]
// 005e999f  80784900             cmp byte ptr [eax + 0x49], 0
// 005e99a3  74eb                 je 0x5e9990
// 005e99a5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e99a8  80794900             cmp byte ptr [ecx + 0x49], 0
// 005e99ac  75a8                 jne 0x5e9956
// 005e99ae  894604               mov dword ptr [esi + 4], eax
// 005e99b1  5f                   pop edi
// 005e99b2  5e                   pop esi
// 005e99b3  c3                   ret 
// standard library map_str<pod32> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAEXXZ)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
