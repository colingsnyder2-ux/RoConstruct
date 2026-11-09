// from server: 100% by auto
// roc 2008-06 0044eaf0  unit: CRobloxControlColorSelector  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044eaf0
//
// 0044eaf0  83ec08               sub esp, 8
// 0044eaf3  53                   push ebx
// 0044eaf4  56                   push esi
// 0044eaf5  8bf1                 mov esi, ecx
// 0044eaf7  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0044eafa  57                   push edi
// 0044eafb  85db                 test ebx, ebx
// 0044eafd  7504                 jne 0x44eb03
// 0044eaff  33c9                 xor ecx, ecx
// 0044eb01  eb15                 jmp 0x44eb18
// 0044eb03  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0044eb06  2bcb                 sub ecx, ebx
// 0044eb08  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044eb0d  f7e9                 imul ecx
// 0044eb0f  d1fa                 sar edx, 1
// 0044eb11  8bca                 mov ecx, edx
// 0044eb13  c1e91f               shr ecx, 0x1f
// 0044eb16  03ca                 add ecx, edx
// 0044eb18  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0044eb1b  8bd7                 mov edx, edi
// 0044eb1d  2bd3                 sub edx, ebx
// 0044eb1f  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044eb24  f7ea                 imul edx
// 0044eb26  d1fa                 sar edx, 1
// 0044eb28  8bc2                 mov eax, edx
// 0044eb2a  c1e81f               shr eax, 0x1f
// 0044eb2d  03c2                 add eax, edx
// 0044eb2f  3bc1                 cmp eax, ecx
// 0044eb31  7332                 jae 0x44eb65
// 0044eb33  8b542418             mov edx, dword ptr [esp + 0x18]
// 0044eb37  c644240c00           mov byte ptr [esp + 0xc], 0
// 0044eb3c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044eb40  51                   push ecx
// 0044eb41  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0044eb45  52                   push edx
// 0044eb46  8d4608               lea eax, [esi + 8]
// 0044eb49  50                   push eax
// 0044eb4a  51                   push ecx
// 0044eb4b  6a01                 push 1
// 0044eb4d  57                   push edi
// 0044eb4e  e87dfaffff           call 0x44e5d0
// 0044eb53  83c418               add esp, 0x18
// 0044eb56  83c70c               add edi, 0xc
// 0044eb59  897e10               mov dword ptr [esi + 0x10], edi
// 0044eb5c  5f                   pop edi
// 0044eb5d  5e                   pop esi
// 0044eb5e  5b                   pop ebx
// 0044eb5f  83c408               add esp, 8
// 0044eb62  c20400               ret 4
// 0044eb65  3bdf                 cmp ebx, edi
// 0044eb67  7606                 jbe 0x44eb6f
// 0044eb69  ff1590288000         call dword ptr [0x802890]
// 0044eb6f  8b542418             mov edx, dword ptr [esp + 0x18]
// 0044eb73  8b06                 mov eax, dword ptr [esi]
// 0044eb75  52                   push edx
// 0044eb76  57                   push edi
// 0044eb77  50                   push eax
// 0044eb78  8d442418             lea eax, [esp + 0x18]
// 0044eb7c  50                   push eax
// 0044eb7d  8bce                 mov ecx, esi
// 0044eb7f  e89cfeffff           call 0x44ea20
// 0044eb84  5f                   pop edi
// 0044eb85  5e                   pop esi
// 0044eb86  5b                   pop ebx
// 0044eb87  83c408               add esp, 8
// 0044eb8a  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
