// from server: 100% by auto
// roc 2007-03 00499900  unit: seg_00490000  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00499900
//
// 00499900  83ec08               sub esp, 8
// 00499903  56                   push esi
// 00499904  8bf1                 mov esi, ecx
// 00499906  57                   push edi
// 00499907  8b7e04               mov edi, dword ptr [esi + 4]
// 0049990a  85ff                 test edi, edi
// 0049990c  7504                 jne 0x499912
// 0049990e  33c9                 xor ecx, ecx
// 00499910  eb15                 jmp 0x499927
// 00499912  8b4e08               mov ecx, dword ptr [esi + 8]
// 00499915  2bcf                 sub ecx, edi
// 00499917  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0049991c  f7e9                 imul ecx
// 0049991e  d1fa                 sar edx, 1
// 00499920  8bca                 mov ecx, edx
// 00499922  c1e91f               shr ecx, 0x1f
// 00499925  03ca                 add ecx, edx
// 00499927  85ff                 test edi, edi
// 00499929  744a                 je 0x499975
// 0049992b  8b560c               mov edx, dword ptr [esi + 0xc]
// 0049992e  2bd7                 sub edx, edi
// 00499930  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00499935  f7ea                 imul edx
// 00499937  d1fa                 sar edx, 1
// 00499939  8bc2                 mov eax, edx
// 0049993b  c1e81f               shr eax, 0x1f
// 0049993e  03c2                 add eax, edx
// 00499940  3bc8                 cmp ecx, eax
// 00499942  7331                 jae 0x499975
// 00499944  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00499948  8b542414             mov edx, dword ptr [esp + 0x14]
// 0049994c  8b7e08               mov edi, dword ptr [esi + 8]
// 0049994f  c644240800           mov byte ptr [esp + 8], 0
// 00499954  8b442408             mov eax, dword ptr [esp + 8]
// 00499958  50                   push eax
// 00499959  51                   push ecx
// 0049995a  56                   push esi
// 0049995b  52                   push edx
// 0049995c  6a01                 push 1
// 0049995e  57                   push edi
// 0049995f  e8dcf8ffff           call 0x499240
// 00499964  83c418               add esp, 0x18
// 00499967  83c70c               add edi, 0xc
// 0049996a  897e08               mov dword ptr [esi + 8], edi
// 0049996d  5f                   pop edi
// 0049996e  5e                   pop esi
// 0049996f  83c408               add esp, 8
// 00499972  c20400               ret 4
// 00499975  53                   push ebx
// 00499976  8b5e08               mov ebx, dword ptr [esi + 8]
// 00499979  3bfb                 cmp edi, ebx
// 0049997b  7606                 jbe 0x499983
// 0049997d  ff1544e97700         call dword ptr [0x77e944]
// 00499983  8b442418             mov eax, dword ptr [esp + 0x18]
// 00499987  50                   push eax
// 00499988  53                   push ebx
// 00499989  56                   push esi
// 0049998a  8d4c2418             lea ecx, [esp + 0x18]
// 0049998e  51                   push ecx
// 0049998f  8bce                 mov ecx, esi
// 00499991  e8bafeffff           call 0x499850
// 00499996  5b                   pop ebx
// 00499997  5f                   pop edi
// 00499998  5e                   pop esi
// 00499999  83c408               add esp, 8
// 0049999c  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
