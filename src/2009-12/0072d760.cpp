// from server: 100% by auto
// roc 2009-12 0072d760  unit: RBX::PriorityThreadPool::PriorityThreadPoolData  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0072d760
//
// 0072d760  83ec08               sub esp, 8
// 0072d763  53                   push ebx
// 0072d764  56                   push esi
// 0072d765  8bf1                 mov esi, ecx
// 0072d767  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0072d76a  57                   push edi
// 0072d76b  85db                 test ebx, ebx
// 0072d76d  7504                 jne 0x72d773
// 0072d76f  33c9                 xor ecx, ecx
// 0072d771  eb16                 jmp 0x72d789
// 0072d773  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0072d776  2bcb                 sub ecx, ebx
// 0072d778  b867666666           mov eax, 0x66666667
// 0072d77d  f7e9                 imul ecx
// 0072d77f  c1fa04               sar edx, 4
// 0072d782  8bca                 mov ecx, edx
// 0072d784  c1e91f               shr ecx, 0x1f
// 0072d787  03ca                 add ecx, edx
// 0072d789  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0072d78c  8bd7                 mov edx, edi
// 0072d78e  2bd3                 sub edx, ebx
// 0072d790  b867666666           mov eax, 0x66666667
// 0072d795  f7ea                 imul edx
// 0072d797  c1fa04               sar edx, 4
// 0072d79a  8bc2                 mov eax, edx
// 0072d79c  c1e81f               shr eax, 0x1f
// 0072d79f  03c2                 add eax, edx
// 0072d7a1  3bc1                 cmp eax, ecx
// 0072d7a3  7332                 jae 0x72d7d7
// 0072d7a5  8b542418             mov edx, dword ptr [esp + 0x18]
// 0072d7a9  c644240c00           mov byte ptr [esp + 0xc], 0
// 0072d7ae  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0072d7b2  51                   push ecx
// 0072d7b3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0072d7b7  52                   push edx
// 0072d7b8  8d4608               lea eax, [esi + 8]
// 0072d7bb  50                   push eax
// 0072d7bc  51                   push ecx
// 0072d7bd  6a01                 push 1
// 0072d7bf  57                   push edi
// 0072d7c0  e89bebffff           call 0x72c360
// 0072d7c5  83c418               add esp, 0x18
// 0072d7c8  83c728               add edi, 0x28
// 0072d7cb  897e10               mov dword ptr [esi + 0x10], edi
// 0072d7ce  5f                   pop edi
// 0072d7cf  5e                   pop esi
// 0072d7d0  5b                   pop ebx
// 0072d7d1  83c408               add esp, 8
// 0072d7d4  c20400               ret 4
// 0072d7d7  3bdf                 cmp ebx, edi
// 0072d7d9  7606                 jbe 0x72d7e1
// 0072d7db  ff1560b79800         call dword ptr [0x98b760]
// 0072d7e1  8b542418             mov edx, dword ptr [esp + 0x18]
// 0072d7e5  8b06                 mov eax, dword ptr [esi]
// 0072d7e7  52                   push edx
// 0072d7e8  57                   push edi
// 0072d7e9  50                   push eax
// 0072d7ea  8d442418             lea eax, [esp + 0x18]
// 0072d7ee  50                   push eax
// 0072d7ef  8bce                 mov ecx, esi
// 0072d7f1  e84af9ffff           call 0x72d140
// 0072d7f6  5f                   pop edi
// 0072d7f7  5e                   pop esi
// 0072d7f8  5b                   pop ebx
// 0072d7f9  83c408               add esp, 8
// 0072d7fc  c20400               ret 4
// standard library vector<pod40> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod40>
struct E { int v[10]; };
#include <vector>
template class std::vector<E>;
