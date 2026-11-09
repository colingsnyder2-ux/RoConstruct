// from server: 100% by auto
// roc 2010-06 004e4490  unit: RBX::Network::IdSerializer  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e4490
//
// 004e4490  83ec08               sub esp, 8
// 004e4493  53                   push ebx
// 004e4494  56                   push esi
// 004e4495  8bf1                 mov esi, ecx
// 004e4497  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004e449a  57                   push edi
// 004e449b  85db                 test ebx, ebx
// 004e449d  7504                 jne 0x4e44a3
// 004e449f  33c9                 xor ecx, ecx
// 004e44a1  eb15                 jmp 0x4e44b8
// 004e44a3  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004e44a6  2bcb                 sub ecx, ebx
// 004e44a8  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004e44ad  f7e9                 imul ecx
// 004e44af  d1fa                 sar edx, 1
// 004e44b1  8bca                 mov ecx, edx
// 004e44b3  c1e91f               shr ecx, 0x1f
// 004e44b6  03ca                 add ecx, edx
// 004e44b8  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004e44bb  8bd7                 mov edx, edi
// 004e44bd  2bd3                 sub edx, ebx
// 004e44bf  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004e44c4  f7ea                 imul edx
// 004e44c6  d1fa                 sar edx, 1
// 004e44c8  8bc2                 mov eax, edx
// 004e44ca  c1e81f               shr eax, 0x1f
// 004e44cd  03c2                 add eax, edx
// 004e44cf  3bc1                 cmp eax, ecx
// 004e44d1  7332                 jae 0x4e4505
// 004e44d3  8b542418             mov edx, dword ptr [esp + 0x18]
// 004e44d7  c644240c00           mov byte ptr [esp + 0xc], 0
// 004e44dc  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004e44e0  51                   push ecx
// 004e44e1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004e44e5  52                   push edx
// 004e44e6  8d4608               lea eax, [esi + 8]
// 004e44e9  50                   push eax
// 004e44ea  51                   push ecx
// 004e44eb  6a01                 push 1
// 004e44ed  57                   push edi
// 004e44ee  e88defffff           call 0x4e3480
// 004e44f3  83c418               add esp, 0x18
// 004e44f6  83c70c               add edi, 0xc
// 004e44f9  897e10               mov dword ptr [esi + 0x10], edi
// 004e44fc  5f                   pop edi
// 004e44fd  5e                   pop esi
// 004e44fe  5b                   pop ebx
// 004e44ff  83c408               add esp, 8
// 004e4502  c20400               ret 4
// 004e4505  3bdf                 cmp ebx, edi
// 004e4507  7606                 jbe 0x4e450f
// 004e4509  ff150ca99e00         call dword ptr [0x9ea90c]
// 004e450f  8b542418             mov edx, dword ptr [esp + 0x18]
// 004e4513  8b06                 mov eax, dword ptr [esi]
// 004e4515  52                   push edx
// 004e4516  57                   push edi
// 004e4517  50                   push eax
// 004e4518  8d442418             lea eax, [esp + 0x18]
// 004e451c  50                   push eax
// 004e451d  8bce                 mov ecx, esi
// 004e451f  e89cfeffff           call 0x4e43c0
// 004e4524  5f                   pop edi
// 004e4525  5e                   pop esi
// 004e4526  5b                   pop ebx
// 004e4527  83c408               add esp, 8
// 004e452a  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
