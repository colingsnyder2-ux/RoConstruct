// from server: 100% by auto
// roc 2009-06 005329f1  unit: RBX::BeveledBlockBuilder  size: 313 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005329f1
//
// 005329f1  6a00                 push 0
// 005329f3  6a00                 push 0
// 005329f5  e850701e00           call 0x719a4a
// 005329fa  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005329fd  8bd3                 mov edx, ebx
// 005329ff  2bd1                 sub edx, ecx
// 00532a01  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00532a06  f7ea                 imul edx
// 00532a08  c1fa02               sar edx, 2
// 00532a0b  8bc2                 mov eax, edx
// 00532a0d  c1e81f               shr eax, 0x1f
// 00532a10  03c2                 add eax, edx
// 00532a12  3bc7                 cmp eax, edi
// 00532a14  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00532a17  0f8399000000         jae 0x532ab6
// 00532a1d  8b10                 mov edx, dword ptr [eax]
// 00532a1f  8955d4               mov dword ptr [ebp - 0x2c], edx
// 00532a22  8b5004               mov edx, dword ptr [eax + 4]
// 00532a25  8955d8               mov dword ptr [ebp - 0x28], edx
// 00532a28  8b5008               mov edx, dword ptr [eax + 8]
// 00532a2b  8955dc               mov dword ptr [ebp - 0x24], edx
// 00532a2e  8b500c               mov edx, dword ptr [eax + 0xc]
// 00532a31  8955e0               mov dword ptr [ebp - 0x20], edx
// 00532a34  8b5010               mov edx, dword ptr [eax + 0x10]
// 00532a37  8b4014               mov eax, dword ptr [eax + 0x14]
// 00532a3a  8945e8               mov dword ptr [ebp - 0x18], eax
// 00532a3d  8d047f               lea eax, [edi + edi*2]
// 00532a40  03c0                 add eax, eax
// 00532a42  03c0                 add eax, eax
// 00532a44  03c0                 add eax, eax
// 00532a46  894514               mov dword ptr [ebp + 0x14], eax
// 00532a49  03c1                 add eax, ecx
// 00532a4b  50                   push eax
// 00532a4c  53                   push ebx
// 00532a4d  51                   push ecx
// 00532a4e  8bce                 mov ecx, esi
// 00532a50  8955e4               mov dword ptr [ebp - 0x1c], edx
// 00532a53  e8c8fdffff           call 0x532820
// 00532a58  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00532a5b  8d4dd4               lea ecx, [ebp - 0x2c]
// 00532a5e  51                   push ecx
// 00532a5f  8bcb                 mov ecx, ebx
// 00532a61  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 00532a64  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00532a69  f7e9                 imul ecx
// 00532a6b  c1fa02               sar edx, 2
// 00532a6e  8bc2                 mov eax, edx
// 00532a70  c1e81f               shr eax, 0x1f
// 00532a73  03c2                 add eax, edx
// 00532a75  2bf8                 sub edi, eax
// 00532a77  57                   push edi
// 00532a78  53                   push ebx
// 00532a79  8bce                 mov ecx, esi
// 00532a7b  c745fc02000000       mov dword ptr [ebp - 4], 2
// 00532a82  e8d9fcffff           call 0x532760
// 00532a87  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00532a8a  014610               add dword ptr [esi + 0x10], eax
// 00532a8d  8b7610               mov esi, dword ptr [esi + 0x10]
// 00532a90  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00532a93  8d4dd4               lea ecx, [ebp - 0x2c]
// 00532a96  51                   push ecx
// 00532a97  2bf0                 sub esi, eax
// 00532a99  56                   push esi
// 00532a9a  52                   push edx
// 00532a9b  e8b0e0ffff           call 0x530b50
// 00532aa0  83c40c               add esp, 0xc
// 00532aa3  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00532aa6  64890d00000000       mov dword ptr fs:[0], ecx
// 00532aad  5f                   pop edi
// 00532aae  5e                   pop esi
// 00532aaf  5b                   pop ebx
// 00532ab0  8be5                 mov esp, ebp
// 00532ab2  5d                   pop ebp
// 00532ab3  c21000               ret 0x10
// 00532ab6  8b08                 mov ecx, dword ptr [eax]
// 00532ab8  8b5004               mov edx, dword ptr [eax + 4]
// 00532abb  894dd4               mov dword ptr [ebp - 0x2c], ecx
// 00532abe  8b4808               mov ecx, dword ptr [eax + 8]
// 00532ac1  8d3c7f               lea edi, [edi + edi*2]
// 00532ac4  8955d8               mov dword ptr [ebp - 0x28], edx
// 00532ac7  8b500c               mov edx, dword ptr [eax + 0xc]
// 00532aca  03ff                 add edi, edi
// 00532acc  894ddc               mov dword ptr [ebp - 0x24], ecx
// 00532acf  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00532ad2  8955e0               mov dword ptr [ebp - 0x20], edx
// 00532ad5  8b5014               mov edx, dword ptr [eax + 0x14]
// 00532ad8  03ff                 add edi, edi
// 00532ada  53                   push ebx
// 00532adb  03ff                 add edi, edi
// 00532add  8bc3                 mov eax, ebx
// 00532adf  2bc7                 sub eax, edi
// 00532ae1  53                   push ebx
// 00532ae2  894de4               mov dword ptr [ebp - 0x1c], ecx
// 00532ae5  50                   push eax
// 00532ae6  8bce                 mov ecx, esi
// 00532ae8  8955e8               mov dword ptr [ebp - 0x18], edx
// 00532aeb  894514               mov dword ptr [ebp + 0x14], eax
// 00532aee  e82dfdffff           call 0x532820
// 00532af3  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00532af6  894610               mov dword ptr [esi + 0x10], eax
// 00532af9  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00532afc  53                   push ebx
// 00532afd  50                   push eax
// 00532afe  51                   push ecx
// 00532aff  e82cfcffff           call 0x532730
// 00532b04  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00532b07  8d55d4               lea edx, [ebp - 0x2c]
// 00532b0a  52                   push edx
// 00532b0b  03f8                 add edi, eax
// 00532b0d  57                   push edi
// 00532b0e  50                   push eax
// 00532b0f  e83ce0ffff           call 0x530b50
// 00532b14  83c418               add esp, 0x18
// 00532b17  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00532b1a  5f                   pop edi
// 00532b1b  5e                   pop esi
// 00532b1c  64890d00000000       mov dword ptr fs:[0], ecx
// 00532b23  5b                   pop ebx
// 00532b24  8be5                 mov esp, ebp
// 00532b26  5d                   pop ebp
// 00532b27  c21000               ret 0x10
// standard library vector<pod24> (function __catch$?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z$2)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
