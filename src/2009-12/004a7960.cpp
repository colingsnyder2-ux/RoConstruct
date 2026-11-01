// from server: 100% by auto
// roc 2009-12 004a7960  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a7960
//
// 004a7960  83ec08               sub esp, 8
// 004a7963  53                   push ebx
// 004a7964  56                   push esi
// 004a7965  8bf1                 mov esi, ecx
// 004a7967  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004a796a  57                   push edi
// 004a796b  85db                 test ebx, ebx
// 004a796d  7504                 jne 0x4a7973
// 004a796f  33c9                 xor ecx, ecx
// 004a7971  eb16                 jmp 0x4a7989
// 004a7973  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004a7976  2bcb                 sub ecx, ebx
// 004a7978  b8398ee338           mov eax, 0x38e38e39
// 004a797d  f7e9                 imul ecx
// 004a797f  c1fa03               sar edx, 3
// 004a7982  8bca                 mov ecx, edx
// 004a7984  c1e91f               shr ecx, 0x1f
// 004a7987  03ca                 add ecx, edx
// 004a7989  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004a798c  8bd7                 mov edx, edi
// 004a798e  2bd3                 sub edx, ebx
// 004a7990  b8398ee338           mov eax, 0x38e38e39
// 004a7995  f7ea                 imul edx
// 004a7997  c1fa03               sar edx, 3
// 004a799a  8bc2                 mov eax, edx
// 004a799c  c1e81f               shr eax, 0x1f
// 004a799f  03c2                 add eax, edx
// 004a79a1  3bc1                 cmp eax, ecx
// 004a79a3  7332                 jae 0x4a79d7
// 004a79a5  8b542418             mov edx, dword ptr [esp + 0x18]
// 004a79a9  c644240c00           mov byte ptr [esp + 0xc], 0
// 004a79ae  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004a79b2  51                   push ecx
// 004a79b3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004a79b7  52                   push edx
// 004a79b8  8d4608               lea eax, [esi + 8]
// 004a79bb  50                   push eax
// 004a79bc  51                   push ecx
// 004a79bd  6a01                 push 1
// 004a79bf  57                   push edi
// 004a79c0  e87b71ffff           call 0x49eb40
// 004a79c5  83c418               add esp, 0x18
// 004a79c8  83c724               add edi, 0x24
// 004a79cb  897e10               mov dword ptr [esi + 0x10], edi
// 004a79ce  5f                   pop edi
// 004a79cf  5e                   pop esi
// 004a79d0  5b                   pop ebx
// 004a79d1  83c408               add esp, 8
// 004a79d4  c20400               ret 4
// 004a79d7  3bdf                 cmp ebx, edi
// 004a79d9  7606                 jbe 0x4a79e1
// 004a79db  ff1560b79800         call dword ptr [0x98b760]
// 004a79e1  8b542418             mov edx, dword ptr [esp + 0x18]
// 004a79e5  8b06                 mov eax, dword ptr [esi]
// 004a79e7  52                   push edx
// 004a79e8  57                   push edi
// 004a79e9  50                   push eax
// 004a79ea  8d442418             lea eax, [esp + 0x18]
// 004a79ee  50                   push eax
// 004a79ef  8bce                 mov ecx, esi
// 004a79f1  e84af7ffff           call 0x4a7140
// 004a79f6  5f                   pop edi
// 004a79f7  5e                   pop esi
// 004a79f8  5b                   pop ebx
// 004a79f9  83c408               add esp, 8
// 004a79fc  c20400               ret 4
// standard library vector<pod36> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
