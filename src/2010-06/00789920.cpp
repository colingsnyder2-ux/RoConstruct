// from server: 100% by auto
// roc 2010-06 00789920  unit: RBX::HUMAN::GettingUp  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00789920
//
// 00789920  83ec08               sub esp, 8
// 00789923  53                   push ebx
// 00789924  56                   push esi
// 00789925  8bf1                 mov esi, ecx
// 00789927  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0078992a  57                   push edi
// 0078992b  85db                 test ebx, ebx
// 0078992d  7504                 jne 0x789933
// 0078992f  33c9                 xor ecx, ecx
// 00789931  eb16                 jmp 0x789949
// 00789933  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00789936  2bcb                 sub ecx, ebx
// 00789938  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0078993d  f7e9                 imul ecx
// 0078993f  c1fa03               sar edx, 3
// 00789942  8bca                 mov ecx, edx
// 00789944  c1e91f               shr ecx, 0x1f
// 00789947  03ca                 add ecx, edx
// 00789949  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0078994c  8bd7                 mov edx, edi
// 0078994e  2bd3                 sub edx, ebx
// 00789950  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00789955  f7ea                 imul edx
// 00789957  c1fa03               sar edx, 3
// 0078995a  8bc2                 mov eax, edx
// 0078995c  c1e81f               shr eax, 0x1f
// 0078995f  03c2                 add eax, edx
// 00789961  3bc1                 cmp eax, ecx
// 00789963  7332                 jae 0x789997
// 00789965  8b542418             mov edx, dword ptr [esp + 0x18]
// 00789969  c644240c00           mov byte ptr [esp + 0xc], 0
// 0078996e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00789972  51                   push ecx
// 00789973  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00789977  52                   push edx
// 00789978  8d4608               lea eax, [esi + 8]
// 0078997b  50                   push eax
// 0078997c  51                   push ecx
// 0078997d  6a01                 push 1
// 0078997f  57                   push edi
// 00789980  e8abedffff           call 0x788730
// 00789985  83c418               add esp, 0x18
// 00789988  83c730               add edi, 0x30
// 0078998b  897e10               mov dword ptr [esi + 0x10], edi
// 0078998e  5f                   pop edi
// 0078998f  5e                   pop esi
// 00789990  5b                   pop ebx
// 00789991  83c408               add esp, 8
// 00789994  c20400               ret 4
// 00789997  3bdf                 cmp ebx, edi
// 00789999  7606                 jbe 0x7899a1
// 0078999b  ff150ca99e00         call dword ptr [0x9ea90c]
// 007899a1  8b542418             mov edx, dword ptr [esp + 0x18]
// 007899a5  8b06                 mov eax, dword ptr [esi]
// 007899a7  52                   push edx
// 007899a8  57                   push edi
// 007899a9  50                   push eax
// 007899aa  8d442418             lea eax, [esp + 0x18]
// 007899ae  50                   push eax
// 007899af  8bce                 mov ecx, esi
// 007899b1  e8eafdffff           call 0x7897a0
// 007899b6  5f                   pop edi
// 007899b7  5e                   pop esi
// 007899b8  5b                   pop ebx
// 007899b9  83c408               add esp, 8
// 007899bc  c20400               ret 4
// standard library vector<pod48> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod48>
struct E { int v[12]; };
#include <vector>
template class std::vector<E>;
