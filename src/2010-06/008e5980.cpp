// from server: 100% by auto
// roc 2010-06 008e5980  unit: Ogre::RbxEntity  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e5980
//
// 008e5980  83ec08               sub esp, 8
// 008e5983  53                   push ebx
// 008e5984  56                   push esi
// 008e5985  8bf1                 mov esi, ecx
// 008e5987  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008e598a  57                   push edi
// 008e598b  85db                 test ebx, ebx
// 008e598d  7504                 jne 0x8e5993
// 008e598f  33c9                 xor ecx, ecx
// 008e5991  eb15                 jmp 0x8e59a8
// 008e5993  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 008e5996  2bcb                 sub ecx, ebx
// 008e5998  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008e599d  f7e9                 imul ecx
// 008e599f  d1fa                 sar edx, 1
// 008e59a1  8bca                 mov ecx, edx
// 008e59a3  c1e91f               shr ecx, 0x1f
// 008e59a6  03ca                 add ecx, edx
// 008e59a8  8b7e10               mov edi, dword ptr [esi + 0x10]
// 008e59ab  8bd7                 mov edx, edi
// 008e59ad  2bd3                 sub edx, ebx
// 008e59af  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008e59b4  f7ea                 imul edx
// 008e59b6  d1fa                 sar edx, 1
// 008e59b8  8bc2                 mov eax, edx
// 008e59ba  c1e81f               shr eax, 0x1f
// 008e59bd  03c2                 add eax, edx
// 008e59bf  3bc1                 cmp eax, ecx
// 008e59c1  7332                 jae 0x8e59f5
// 008e59c3  8b542418             mov edx, dword ptr [esp + 0x18]
// 008e59c7  c644240c00           mov byte ptr [esp + 0xc], 0
// 008e59cc  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008e59d0  51                   push ecx
// 008e59d1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 008e59d5  52                   push edx
// 008e59d6  8d4608               lea eax, [esi + 8]
// 008e59d9  50                   push eax
// 008e59da  51                   push ecx
// 008e59db  6a01                 push 1
// 008e59dd  57                   push edi
// 008e59de  e84da3ffff           call 0x8dfd30
// 008e59e3  83c418               add esp, 0x18
// 008e59e6  83c70c               add edi, 0xc
// 008e59e9  897e10               mov dword ptr [esi + 0x10], edi
// 008e59ec  5f                   pop edi
// 008e59ed  5e                   pop esi
// 008e59ee  5b                   pop ebx
// 008e59ef  83c408               add esp, 8
// 008e59f2  c20400               ret 4
// 008e59f5  3bdf                 cmp ebx, edi
// 008e59f7  7606                 jbe 0x8e59ff
// 008e59f9  ff150ca99e00         call dword ptr [0x9ea90c]
// 008e59ff  8b542418             mov edx, dword ptr [esp + 0x18]
// 008e5a03  8b06                 mov eax, dword ptr [esi]
// 008e5a05  52                   push edx
// 008e5a06  57                   push edi
// 008e5a07  50                   push eax
// 008e5a08  8d442418             lea eax, [esp + 0x18]
// 008e5a0c  50                   push eax
// 008e5a0d  8bce                 mov ecx, esi
// 008e5a0f  e89cfeffff           call 0x8e58b0
// 008e5a14  5f                   pop edi
// 008e5a15  5e                   pop esi
// 008e5a16  5b                   pop ebx
// 008e5a17  83c408               add esp, 8
// 008e5a1a  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
