// from server: 100% by auto
// roc 2010-06 00657e20  unit: RBX::VKeyframeSequence::?$FactoryProduct  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00657e20
//
// 00657e20  55                   push ebp
// 00657e21  8bec                 mov ebp, esp
// 00657e23  6aff                 push -1
// 00657e25  6870e09900           push 0x99e070
// 00657e2a  64a100000000         mov eax, dword ptr fs:[0]
// 00657e30  50                   push eax
// 00657e31  64892500000000       mov dword ptr fs:[0], esp
// 00657e38  83ec10               sub esp, 0x10
// 00657e3b  8b5508               mov edx, dword ptr [ebp + 8]
// 00657e3e  53                   push ebx
// 00657e3f  56                   push esi
// 00657e40  57                   push edi
// 00657e41  8965f0               mov dword ptr [ebp - 0x10], esp
// 00657e44  8bf1                 mov esi, ecx
// 00657e46  81faffffff07         cmp edx, 0x7ffffff
// 00657e4c  7605                 jbe 0x657e53
// 00657e4e  e89dbfdcff           call 0x423df0
// 00657e53  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00657e56  85c9                 test ecx, ecx
// 00657e58  7504                 jne 0x657e5e
// 00657e5a  33c0                 xor eax, eax
// 00657e5c  eb08                 jmp 0x657e66
// 00657e5e  8b4614               mov eax, dword ptr [esi + 0x14]
// 00657e61  2bc1                 sub eax, ecx
// 00657e63  c1f805               sar eax, 5
// 00657e66  3bc2                 cmp eax, edx
// 00657e68  0f8382000000         jae 0x657ef0
// 00657e6e  6a00                 push 0
// 00657e70  52                   push edx
// 00657e71  e8ba6b2900           call 0x8eea30
// 00657e76  8bd8                 mov ebx, eax
// 00657e78  8b4610               mov eax, dword ptr [esi + 0x10]
// 00657e7b  83c408               add esp, 8
// 00657e7e  895de4               mov dword ptr [ebp - 0x1c], ebx
// 00657e81  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00657e88  8945e8               mov dword ptr [ebp - 0x18], eax
// 00657e8b  39460c               cmp dword ptr [esi + 0xc], eax
// 00657e8e  7606                 jbe 0x657e96
// 00657e90  ff150ca99e00         call dword ptr [0x9ea90c]
// 00657e96  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00657e99  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00657e9c  7606                 jbe 0x657ea4
// 00657e9e  ff150ca99e00         call dword ptr [0x9ea90c]
// 00657ea4  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00657ea7  c645ec00             mov byte ptr [ebp - 0x14], 0
// 00657eab  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00657eae  50                   push eax
// 00657eaf  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 00657eb2  51                   push ecx
// 00657eb3  8d5608               lea edx, [esi + 8]
// 00657eb6  52                   push edx
// 00657eb7  53                   push ebx
// 00657eb8  50                   push eax
// 00657eb9  57                   push edi
// 00657eba  e871f6ffff           call 0x657530
// 00657ebf  8b460c               mov eax, dword ptr [esi + 0xc]
// 00657ec2  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00657ec5  2bf8                 sub edi, eax
// 00657ec7  83c418               add esp, 0x18
// 00657eca  c1ff05               sar edi, 5
// 00657ecd  85c0                 test eax, eax
// 00657ecf  7409                 je 0x657eda
// 00657ed1  50                   push eax
// 00657ed2  e8c3fa1400           call 0x7a799a
// 00657ed7  83c404               add esp, 4
// 00657eda  8b4508               mov eax, dword ptr [ebp + 8]
// 00657edd  c1e005               shl eax, 5
// 00657ee0  03c3                 add eax, ebx
// 00657ee2  c1e705               shl edi, 5
// 00657ee5  03fb                 add edi, ebx
// 00657ee7  894614               mov dword ptr [esi + 0x14], eax
// 00657eea  897e10               mov dword ptr [esi + 0x10], edi
// 00657eed  895e0c               mov dword ptr [esi + 0xc], ebx
// 00657ef0  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00657ef3  5f                   pop edi
// 00657ef4  5e                   pop esi
// 00657ef5  64890d00000000       mov dword ptr fs:[0], ecx
// 00657efc  5b                   pop ebx
// 00657efd  8be5                 mov esp, ebp
// 00657eff  5d                   pop ebp
// 00657f00  c20400               ret 4
// standard library vector<pod32> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
