// from server: 100% by auto
// roc 2009-12 005ddc20  unit: RBX::AdornG3D  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005ddc20
//
// 005ddc20  83ec08               sub esp, 8
// 005ddc23  53                   push ebx
// 005ddc24  56                   push esi
// 005ddc25  8bf1                 mov esi, ecx
// 005ddc27  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005ddc2a  57                   push edi
// 005ddc2b  85db                 test ebx, ebx
// 005ddc2d  7504                 jne 0x5ddc33
// 005ddc2f  33c9                 xor ecx, ecx
// 005ddc31  eb16                 jmp 0x5ddc49
// 005ddc33  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005ddc36  2bcb                 sub ecx, ebx
// 005ddc38  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005ddc3d  f7e9                 imul ecx
// 005ddc3f  c1fa02               sar edx, 2
// 005ddc42  8bca                 mov ecx, edx
// 005ddc44  c1e91f               shr ecx, 0x1f
// 005ddc47  03ca                 add ecx, edx
// 005ddc49  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005ddc4c  8bd7                 mov edx, edi
// 005ddc4e  2bd3                 sub edx, ebx
// 005ddc50  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005ddc55  f7ea                 imul edx
// 005ddc57  c1fa02               sar edx, 2
// 005ddc5a  8bc2                 mov eax, edx
// 005ddc5c  c1e81f               shr eax, 0x1f
// 005ddc5f  03c2                 add eax, edx
// 005ddc61  3bc1                 cmp eax, ecx
// 005ddc63  7332                 jae 0x5ddc97
// 005ddc65  8b542418             mov edx, dword ptr [esp + 0x18]
// 005ddc69  c644240c00           mov byte ptr [esp + 0xc], 0
// 005ddc6e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005ddc72  51                   push ecx
// 005ddc73  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005ddc77  52                   push edx
// 005ddc78  8d4608               lea eax, [esi + 8]
// 005ddc7b  50                   push eax
// 005ddc7c  51                   push ecx
// 005ddc7d  6a01                 push 1
// 005ddc7f  57                   push edi
// 005ddc80  e86bf8ffff           call 0x5dd4f0
// 005ddc85  83c418               add esp, 0x18
// 005ddc88  83c718               add edi, 0x18
// 005ddc8b  897e10               mov dword ptr [esi + 0x10], edi
// 005ddc8e  5f                   pop edi
// 005ddc8f  5e                   pop esi
// 005ddc90  5b                   pop ebx
// 005ddc91  83c408               add esp, 8
// 005ddc94  c20400               ret 4
// 005ddc97  3bdf                 cmp ebx, edi
// 005ddc99  7606                 jbe 0x5ddca1
// 005ddc9b  ff1560b79800         call dword ptr [0x98b760]
// 005ddca1  8b542418             mov edx, dword ptr [esp + 0x18]
// 005ddca5  8b06                 mov eax, dword ptr [esi]
// 005ddca7  52                   push edx
// 005ddca8  57                   push edi
// 005ddca9  50                   push eax
// 005ddcaa  8d442418             lea eax, [esp + 0x18]
// 005ddcae  50                   push eax
// 005ddcaf  8bce                 mov ecx, esi
// 005ddcb1  e8bafeffff           call 0x5ddb70
// 005ddcb6  5f                   pop edi
// 005ddcb7  5e                   pop esi
// 005ddcb8  5b                   pop ebx
// 005ddcb9  83c408               add esp, 8
// 005ddcbc  c20400               ret 4
// standard library vector<pod24> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
