// from server: 100% by auto
// roc 2007-08 00410800  unit: CopyVerb  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00410800
//
// 00410800  83ec08               sub esp, 8
// 00410803  56                   push esi
// 00410804  8bf1                 mov esi, ecx
// 00410806  57                   push edi
// 00410807  8b7e04               mov edi, dword ptr [esi + 4]
// 0041080a  85ff                 test edi, edi
// 0041080c  7504                 jne 0x410812
// 0041080e  33c9                 xor ecx, ecx
// 00410810  eb16                 jmp 0x410828
// 00410812  8b4e08               mov ecx, dword ptr [esi + 8]
// 00410815  2bcf                 sub ecx, edi
// 00410817  b8398ee338           mov eax, 0x38e38e39
// 0041081c  f7e9                 imul ecx
// 0041081e  c1fa03               sar edx, 3
// 00410821  8bca                 mov ecx, edx
// 00410823  c1e91f               shr ecx, 0x1f
// 00410826  03ca                 add ecx, edx
// 00410828  85ff                 test edi, edi
// 0041082a  744b                 je 0x410877
// 0041082c  8b560c               mov edx, dword ptr [esi + 0xc]
// 0041082f  2bd7                 sub edx, edi
// 00410831  b8398ee338           mov eax, 0x38e38e39
// 00410836  f7ea                 imul edx
// 00410838  c1fa03               sar edx, 3
// 0041083b  8bc2                 mov eax, edx
// 0041083d  c1e81f               shr eax, 0x1f
// 00410840  03c2                 add eax, edx
// 00410842  3bc8                 cmp ecx, eax
// 00410844  7331                 jae 0x410877
// 00410846  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0041084a  8b542414             mov edx, dword ptr [esp + 0x14]
// 0041084e  8b7e08               mov edi, dword ptr [esi + 8]
// 00410851  c644240800           mov byte ptr [esp + 8], 0
// 00410856  8b442408             mov eax, dword ptr [esp + 8]
// 0041085a  50                   push eax
// 0041085b  51                   push ecx
// 0041085c  56                   push esi
// 0041085d  52                   push edx
// 0041085e  6a01                 push 1
// 00410860  57                   push edi
// 00410861  e87af3ffff           call 0x40fbe0
// 00410866  83c418               add esp, 0x18
// 00410869  83c724               add edi, 0x24
// 0041086c  897e08               mov dword ptr [esi + 8], edi
// 0041086f  5f                   pop edi
// 00410870  5e                   pop esi
// 00410871  83c408               add esp, 8
// 00410874  c20400               ret 4
// 00410877  53                   push ebx
// 00410878  8b5e08               mov ebx, dword ptr [esi + 8]
// 0041087b  3bfb                 cmp edi, ebx
// 0041087d  7606                 jbe 0x410885
// 0041087f  ff15d8e67700         call dword ptr [0x77e6d8]
// 00410885  8b442418             mov eax, dword ptr [esp + 0x18]
// 00410889  50                   push eax
// 0041088a  53                   push ebx
// 0041088b  56                   push esi
// 0041088c  8d4c2418             lea ecx, [esp + 0x18]
// 00410890  51                   push ecx
// 00410891  8bce                 mov ecx, esi
// 00410893  e898fdffff           call 0x410630
// 00410898  5b                   pop ebx
// 00410899  5f                   pop edi
// 0041089a  5e                   pop esi
// 0041089b  83c408               add esp, 8
// 0041089e  c20400               ret 4
// standard library vector<pod36> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
