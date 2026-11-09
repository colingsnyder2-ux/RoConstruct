// from server: 100% by auto
// roc 2010-06 00732010  unit: lua_exception  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00732010
//
// 00732010  83ec08               sub esp, 8
// 00732013  53                   push ebx
// 00732014  56                   push esi
// 00732015  8bf1                 mov esi, ecx
// 00732017  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0073201a  57                   push edi
// 0073201b  85db                 test ebx, ebx
// 0073201d  7504                 jne 0x732023
// 0073201f  33c9                 xor ecx, ecx
// 00732021  eb16                 jmp 0x732039
// 00732023  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00732026  2bcb                 sub ecx, ebx
// 00732028  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0073202d  f7e9                 imul ecx
// 0073202f  c1fa02               sar edx, 2
// 00732032  8bca                 mov ecx, edx
// 00732034  c1e91f               shr ecx, 0x1f
// 00732037  03ca                 add ecx, edx
// 00732039  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0073203c  8bd7                 mov edx, edi
// 0073203e  2bd3                 sub edx, ebx
// 00732040  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00732045  f7ea                 imul edx
// 00732047  c1fa02               sar edx, 2
// 0073204a  8bc2                 mov eax, edx
// 0073204c  c1e81f               shr eax, 0x1f
// 0073204f  03c2                 add eax, edx
// 00732051  3bc1                 cmp eax, ecx
// 00732053  7332                 jae 0x732087
// 00732055  8b542418             mov edx, dword ptr [esp + 0x18]
// 00732059  c644240c00           mov byte ptr [esp + 0xc], 0
// 0073205e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00732062  51                   push ecx
// 00732063  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00732067  52                   push edx
// 00732068  8d4608               lea eax, [esi + 8]
// 0073206b  50                   push eax
// 0073206c  51                   push ecx
// 0073206d  6a01                 push 1
// 0073206f  57                   push edi
// 00732070  e83bf1ffff           call 0x7311b0
// 00732075  83c418               add esp, 0x18
// 00732078  83c718               add edi, 0x18
// 0073207b  897e10               mov dword ptr [esi + 0x10], edi
// 0073207e  5f                   pop edi
// 0073207f  5e                   pop esi
// 00732080  5b                   pop ebx
// 00732081  83c408               add esp, 8
// 00732084  c20400               ret 4
// 00732087  3bdf                 cmp ebx, edi
// 00732089  7606                 jbe 0x732091
// 0073208b  ff150ca99e00         call dword ptr [0x9ea90c]
// 00732091  8b542418             mov edx, dword ptr [esp + 0x18]
// 00732095  8b06                 mov eax, dword ptr [esi]
// 00732097  52                   push edx
// 00732098  57                   push edi
// 00732099  50                   push eax
// 0073209a  8d442418             lea eax, [esp + 0x18]
// 0073209e  50                   push eax
// 0073209f  8bce                 mov ecx, esi
// 007320a1  e81afeffff           call 0x731ec0
// 007320a6  5f                   pop edi
// 007320a7  5e                   pop esi
// 007320a8  5b                   pop ebx
// 007320a9  83c408               add esp, 8
// 007320ac  c20400               ret 4
// standard library vector<pod24> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
