// from server: 100% by auto
// roc 2009-12 004a2c80  unit: Ogre::RbxMeshPartAdapter  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a2c80
//
// 004a2c80  55                   push ebp
// 004a2c81  8bec                 mov ebp, esp
// 004a2c83  6aff                 push -1
// 004a2c85  68d0089300           push 0x9308d0
// 004a2c8a  64a100000000         mov eax, dword ptr fs:[0]
// 004a2c90  50                   push eax
// 004a2c91  64892500000000       mov dword ptr fs:[0], esp
// 004a2c98  83ec10               sub esp, 0x10
// 004a2c9b  8b5508               mov edx, dword ptr [ebp + 8]
// 004a2c9e  53                   push ebx
// 004a2c9f  56                   push esi
// 004a2ca0  57                   push edi
// 004a2ca1  8965f0               mov dword ptr [ebp - 0x10], esp
// 004a2ca4  8bf1                 mov esi, ecx
// 004a2ca6  81faffffff07         cmp edx, 0x7ffffff
// 004a2cac  7605                 jbe 0x4a2cb3
// 004a2cae  e8adf4f9ff           call 0x442160
// 004a2cb3  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004a2cb6  85c9                 test ecx, ecx
// 004a2cb8  7504                 jne 0x4a2cbe
// 004a2cba  33c0                 xor eax, eax
// 004a2cbc  eb08                 jmp 0x4a2cc6
// 004a2cbe  8b4614               mov eax, dword ptr [esi + 0x14]
// 004a2cc1  2bc1                 sub eax, ecx
// 004a2cc3  c1f805               sar eax, 5
// 004a2cc6  3bc2                 cmp eax, edx
// 004a2cc8  0f8382000000         jae 0x4a2d50
// 004a2cce  6a00                 push 0
// 004a2cd0  52                   push edx
// 004a2cd1  e8aa23feff           call 0x485080
// 004a2cd6  8bd8                 mov ebx, eax
// 004a2cd8  8b4610               mov eax, dword ptr [esi + 0x10]
// 004a2cdb  83c408               add esp, 8
// 004a2cde  895de4               mov dword ptr [ebp - 0x1c], ebx
// 004a2ce1  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004a2ce8  8945e8               mov dword ptr [ebp - 0x18], eax
// 004a2ceb  39460c               cmp dword ptr [esi + 0xc], eax
// 004a2cee  7606                 jbe 0x4a2cf6
// 004a2cf0  ff1560b79800         call dword ptr [0x98b760]
// 004a2cf6  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004a2cf9  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004a2cfc  7606                 jbe 0x4a2d04
// 004a2cfe  ff1560b79800         call dword ptr [0x98b760]
// 004a2d04  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004a2d07  c645ec00             mov byte ptr [ebp - 0x14], 0
// 004a2d0b  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 004a2d0e  50                   push eax
// 004a2d0f  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 004a2d12  51                   push ecx
// 004a2d13  8d5608               lea edx, [esi + 8]
// 004a2d16  52                   push edx
// 004a2d17  53                   push ebx
// 004a2d18  50                   push eax
// 004a2d19  57                   push edi
// 004a2d1a  e8a1f0ffff           call 0x4a1dc0
// 004a2d1f  8b460c               mov eax, dword ptr [esi + 0xc]
// 004a2d22  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004a2d25  2bf8                 sub edi, eax
// 004a2d27  83c418               add esp, 0x18
// 004a2d2a  c1ff05               sar edi, 5
// 004a2d2d  85c0                 test eax, eax
// 004a2d2f  7409                 je 0x4a2d3a
// 004a2d31  50                   push eax
// 004a2d32  e8230b3500           call 0x7f385a
// 004a2d37  83c404               add esp, 4
// 004a2d3a  8b4508               mov eax, dword ptr [ebp + 8]
// 004a2d3d  c1e005               shl eax, 5
// 004a2d40  03c3                 add eax, ebx
// 004a2d42  c1e705               shl edi, 5
// 004a2d45  03fb                 add edi, ebx
// 004a2d47  894614               mov dword ptr [esi + 0x14], eax
// 004a2d4a  897e10               mov dword ptr [esi + 0x10], edi
// 004a2d4d  895e0c               mov dword ptr [esi + 0xc], ebx
// 004a2d50  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004a2d53  5f                   pop edi
// 004a2d54  5e                   pop esi
// 004a2d55  64890d00000000       mov dword ptr fs:[0], ecx
// 004a2d5c  5b                   pop ebx
// 004a2d5d  8be5                 mov esp, ebp
// 004a2d5f  5d                   pop ebp
// 004a2d60  c20400               ret 4
// standard library vector<pod32> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
