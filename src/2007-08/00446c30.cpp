// from server: 100% by auto
// roc 2007-08 00446c30  unit: CRenderSettings::W4AASamples::?$EnumDesc  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00446c30
//
// 00446c30  56                   push esi
// 00446c31  8bf1                 mov esi, ecx
// 00446c33  8b4604               mov eax, dword ptr [esi + 4]
// 00446c36  85c0                 test eax, eax
// 00446c38  57                   push edi
// 00446c39  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00446c3d  741c                 je 0x446c5b
// 00446c3f  8b4e08               mov ecx, dword ptr [esi + 8]
// 00446c42  2bc8                 sub ecx, eax
// 00446c44  b893244992           mov eax, 0x92492493
// 00446c49  f7e9                 imul ecx
// 00446c4b  03d1                 add edx, ecx
// 00446c4d  c1fa04               sar edx, 4
// 00446c50  8bc2                 mov eax, edx
// 00446c52  c1e81f               shr eax, 0x1f
// 00446c55  03c2                 add eax, edx
// 00446c57  3bf8                 cmp edi, eax
// 00446c59  7206                 jb 0x446c61
// 00446c5b  ff15d8e67700         call dword ptr [0x77e6d8]
// 00446c61  8b4e04               mov ecx, dword ptr [esi + 4]
// 00446c64  8d04fd00000000       lea eax, [edi*8]
// 00446c6b  2bc7                 sub eax, edi
// 00446c6d  5f                   pop edi
// 00446c6e  8d0481               lea eax, [ecx + eax*4]
// 00446c71  5e                   pop esi
// 00446c72  c20400               ret 4
// standard library vector<string> (function ??A?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QBEABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@I@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
