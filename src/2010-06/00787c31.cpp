// from server: 100% by auto
// roc 2010-06 00787c31  unit: RBX::HUMAN::GettingUp  size: 297 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00787c31
//
// 00787c31  6a00                 push 0
// 00787c33  6a00                 push 0
// 00787c35  e8780d0200           call 0x7a89b2
// 00787c3a  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00787c3d  8bd3                 mov edx, ebx
// 00787c3f  2bd1                 sub edx, ecx
// 00787c41  b867666666           mov eax, 0x66666667
// 00787c46  f7ea                 imul edx
// 00787c48  c1fa03               sar edx, 3
// 00787c4b  8bc2                 mov eax, edx
// 00787c4d  c1e81f               shr eax, 0x1f
// 00787c50  03c2                 add eax, edx
// 00787c52  3bc7                 cmp eax, edi
// 00787c54  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00787c57  0f8391000000         jae 0x787cee
// 00787c5d  8b10                 mov edx, dword ptr [eax]
// 00787c5f  8955d8               mov dword ptr [ebp - 0x28], edx
// 00787c62  8b5004               mov edx, dword ptr [eax + 4]
// 00787c65  8955dc               mov dword ptr [ebp - 0x24], edx
// 00787c68  8b5008               mov edx, dword ptr [eax + 8]
// 00787c6b  8955e0               mov dword ptr [ebp - 0x20], edx
// 00787c6e  8b500c               mov edx, dword ptr [eax + 0xc]
// 00787c71  8b4010               mov eax, dword ptr [eax + 0x10]
// 00787c74  8945e8               mov dword ptr [ebp - 0x18], eax
// 00787c77  8d04bf               lea eax, [edi + edi*4]
// 00787c7a  03c0                 add eax, eax
// 00787c7c  03c0                 add eax, eax
// 00787c7e  894514               mov dword ptr [ebp + 0x14], eax
// 00787c81  03c1                 add eax, ecx
// 00787c83  50                   push eax
// 00787c84  53                   push ebx
// 00787c85  51                   push ecx
// 00787c86  8bce                 mov ecx, esi
// 00787c88  8955e4               mov dword ptr [ebp - 0x1c], edx
// 00787c8b  e860fcffff           call 0x7878f0
// 00787c90  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00787c93  8d4dd8               lea ecx, [ebp - 0x28]
// 00787c96  51                   push ecx
// 00787c97  8bcb                 mov ecx, ebx
// 00787c99  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 00787c9c  b867666666           mov eax, 0x66666667
// 00787ca1  f7e9                 imul ecx
// 00787ca3  c1fa03               sar edx, 3
// 00787ca6  8bc2                 mov eax, edx
// 00787ca8  c1e81f               shr eax, 0x1f
// 00787cab  03c2                 add eax, edx
// 00787cad  2bf8                 sub edi, eax
// 00787caf  57                   push edi
// 00787cb0  53                   push ebx
// 00787cb1  8bce                 mov ecx, esi
// 00787cb3  c745fc02000000       mov dword ptr [ebp - 4], 2
// 00787cba  e821faffff           call 0x7876e0
// 00787cbf  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00787cc2  014610               add dword ptr [esi + 0x10], eax
// 00787cc5  8b7610               mov esi, dword ptr [esi + 0x10]
// 00787cc8  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00787ccb  8d4dd8               lea ecx, [ebp - 0x28]
// 00787cce  51                   push ecx
// 00787ccf  2bf0                 sub esi, eax
// 00787cd1  56                   push esi
// 00787cd2  52                   push edx
// 00787cd3  e828e6ffff           call 0x786300
// 00787cd8  83c40c               add esp, 0xc
// 00787cdb  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00787cde  64890d00000000       mov dword ptr fs:[0], ecx
// 00787ce5  5f                   pop edi
// 00787ce6  5e                   pop esi
// 00787ce7  5b                   pop ebx
// 00787ce8  8be5                 mov esp, ebp
// 00787cea  5d                   pop ebp
// 00787ceb  c21000               ret 0x10
// 00787cee  8b08                 mov ecx, dword ptr [eax]
// 00787cf0  8b5004               mov edx, dword ptr [eax + 4]
// 00787cf3  894dd8               mov dword ptr [ebp - 0x28], ecx
// 00787cf6  8b4808               mov ecx, dword ptr [eax + 8]
// 00787cf9  8955dc               mov dword ptr [ebp - 0x24], edx
// 00787cfc  8b500c               mov edx, dword ptr [eax + 0xc]
// 00787cff  8b4010               mov eax, dword ptr [eax + 0x10]
// 00787d02  8d3cbf               lea edi, [edi + edi*4]
// 00787d05  8945e8               mov dword ptr [ebp - 0x18], eax
// 00787d08  03ff                 add edi, edi
// 00787d0a  53                   push ebx
// 00787d0b  03ff                 add edi, edi
// 00787d0d  8bc3                 mov eax, ebx
// 00787d0f  2bc7                 sub eax, edi
// 00787d11  53                   push ebx
// 00787d12  894de0               mov dword ptr [ebp - 0x20], ecx
// 00787d15  50                   push eax
// 00787d16  8bce                 mov ecx, esi
// 00787d18  8955e4               mov dword ptr [ebp - 0x1c], edx
// 00787d1b  894514               mov dword ptr [ebp + 0x14], eax
// 00787d1e  e8cdfbffff           call 0x7878f0
// 00787d23  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00787d26  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00787d29  53                   push ebx
// 00787d2a  51                   push ecx
// 00787d2b  52                   push edx
// 00787d2c  894610               mov dword ptr [esi + 0x10], eax
// 00787d2f  e87cf9ffff           call 0x7876b0
// 00787d34  8d45d8               lea eax, [ebp - 0x28]
// 00787d37  50                   push eax
// 00787d38  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00787d3b  03f8                 add edi, eax
// 00787d3d  57                   push edi
// 00787d3e  50                   push eax
// 00787d3f  e8bce5ffff           call 0x786300
// 00787d44  83c418               add esp, 0x18
// 00787d47  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00787d4a  5f                   pop edi
// 00787d4b  5e                   pop esi
// 00787d4c  64890d00000000       mov dword ptr fs:[0], ecx
// 00787d53  5b                   pop ebx
// 00787d54  8be5                 mov esp, ebp
// 00787d56  5d                   pop ebp
// 00787d57  c21000               ret 0x10
// standard library vector<pod20> (function __catch$?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z$2)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
