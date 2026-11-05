// from server: 100% by auto
// roc 2010-06 004734e0  unit: CRobloxScriptReviewPaneView  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004734e0
//
// 004734e0  56                   push esi
// 004734e1  8bf1                 mov esi, ecx
// 004734e3  833e00               cmp dword ptr [esi], 0
// 004734e6  57                   push edi
// 004734e7  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 004734ed  7502                 jne 0x4734f1
// 004734ef  ffd7                 call edi
// 004734f1  8b4604               mov eax, dword ptr [esi + 4]
// 004734f4  80783100             cmp byte ptr [eax + 0x31], 0
// 004734f8  7411                 je 0x47350b
// 004734fa  8b4008               mov eax, dword ptr [eax + 8]
// 004734fd  894604               mov dword ptr [esi + 4], eax
// 00473500  80783100             cmp byte ptr [eax + 0x31], 0
// 00473504  745b                 je 0x473561
// 00473506  ffd7                 call edi
// 00473508  5f                   pop edi
// 00473509  5e                   pop esi
// 0047350a  c3                   ret 
// 0047350b  8b08                 mov ecx, dword ptr [eax]
// 0047350d  80793100             cmp byte ptr [ecx + 0x31], 0
// 00473511  751e                 jne 0x473531
// 00473513  8b4108               mov eax, dword ptr [ecx + 8]
// 00473516  80783100             cmp byte ptr [eax + 0x31], 0
// 0047351a  750f                 jne 0x47352b
// 0047351c  8d642400             lea esp, [esp]
// 00473520  8bc8                 mov ecx, eax
// 00473522  8b4108               mov eax, dword ptr [ecx + 8]
// 00473525  80783100             cmp byte ptr [eax + 0x31], 0
// 00473529  74f5                 je 0x473520
// 0047352b  5f                   pop edi
// 0047352c  894e04               mov dword ptr [esi + 4], ecx
// 0047352f  5e                   pop esi
// 00473530  c3                   ret 
// 00473531  8b4004               mov eax, dword ptr [eax + 4]
// 00473534  80783100             cmp byte ptr [eax + 0x31], 0
// 00473538  751b                 jne 0x473555
// 0047353a  8d9b00000000         lea ebx, [ebx]
// 00473540  8b4e04               mov ecx, dword ptr [esi + 4]
// 00473543  3b08                 cmp ecx, dword ptr [eax]
// 00473545  750e                 jne 0x473555
// 00473547  894604               mov dword ptr [esi + 4], eax
// 0047354a  8bd0                 mov edx, eax
// 0047354c  8b4204               mov eax, dword ptr [edx + 4]
// 0047354f  80783100             cmp byte ptr [eax + 0x31], 0
// 00473553  74eb                 je 0x473540
// 00473555  8b4e04               mov ecx, dword ptr [esi + 4]
// 00473558  80793100             cmp byte ptr [ecx + 0x31], 0
// 0047355c  75a8                 jne 0x473506
// 0047355e  894604               mov dword ptr [esi + 4], eax
// 00473561  5f                   pop edi
// 00473562  5e                   pop esi
// 00473563  c3                   ret 
// standard library map_int<pod32> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
