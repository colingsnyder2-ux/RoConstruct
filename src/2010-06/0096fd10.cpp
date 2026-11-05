// from server: 100% by auto
// roc 2010-06 0096fd10  unit: seg_00960000  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096fd10
//
// 0096fd10  83ec08               sub esp, 8
// 0096fd13  53                   push ebx
// 0096fd14  56                   push esi
// 0096fd15  8bf1                 mov esi, ecx
// 0096fd17  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0096fd1a  57                   push edi
// 0096fd1b  85db                 test ebx, ebx
// 0096fd1d  7504                 jne 0x96fd23
// 0096fd1f  33c9                 xor ecx, ecx
// 0096fd21  eb15                 jmp 0x96fd38
// 0096fd23  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0096fd26  2bcb                 sub ecx, ebx
// 0096fd28  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096fd2d  f7e9                 imul ecx
// 0096fd2f  d1fa                 sar edx, 1
// 0096fd31  8bca                 mov ecx, edx
// 0096fd33  c1e91f               shr ecx, 0x1f
// 0096fd36  03ca                 add ecx, edx
// 0096fd38  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0096fd3b  8bd7                 mov edx, edi
// 0096fd3d  2bd3                 sub edx, ebx
// 0096fd3f  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096fd44  f7ea                 imul edx
// 0096fd46  d1fa                 sar edx, 1
// 0096fd48  8bc2                 mov eax, edx
// 0096fd4a  c1e81f               shr eax, 0x1f
// 0096fd4d  03c2                 add eax, edx
// 0096fd4f  3bc1                 cmp eax, ecx
// 0096fd51  7332                 jae 0x96fd85
// 0096fd53  8b542418             mov edx, dword ptr [esp + 0x18]
// 0096fd57  c644240c00           mov byte ptr [esp + 0xc], 0
// 0096fd5c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0096fd60  51                   push ecx
// 0096fd61  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0096fd65  52                   push edx
// 0096fd66  8d4608               lea eax, [esi + 8]
// 0096fd69  50                   push eax
// 0096fd6a  51                   push ecx
// 0096fd6b  6a01                 push 1
// 0096fd6d  57                   push edi
// 0096fd6e  e8bdfff6ff           call 0x8dfd30
// 0096fd73  83c418               add esp, 0x18
// 0096fd76  83c70c               add edi, 0xc
// 0096fd79  897e10               mov dword ptr [esi + 0x10], edi
// 0096fd7c  5f                   pop edi
// 0096fd7d  5e                   pop esi
// 0096fd7e  5b                   pop ebx
// 0096fd7f  83c408               add esp, 8
// 0096fd82  c20400               ret 4
// 0096fd85  3bdf                 cmp ebx, edi
// 0096fd87  7606                 jbe 0x96fd8f
// 0096fd89  ff150ca99e00         call dword ptr [0x9ea90c]
// 0096fd8f  8b542418             mov edx, dword ptr [esp + 0x18]
// 0096fd93  8b06                 mov eax, dword ptr [esi]
// 0096fd95  52                   push edx
// 0096fd96  57                   push edi
// 0096fd97  50                   push eax
// 0096fd98  8d442418             lea eax, [esp + 0x18]
// 0096fd9c  50                   push eax
// 0096fd9d  8bce                 mov ecx, esi
// 0096fd9f  e89cfeffff           call 0x96fc40
// 0096fda4  5f                   pop edi
// 0096fda5  5e                   pop esi
// 0096fda6  5b                   pop ebx
// 0096fda7  83c408               add esp, 8
// 0096fdaa  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
