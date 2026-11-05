// from server: 100% by auto
// roc 2007-08 005e0c70  unit: RBX::VMotorFeature::?$FactoryProduct  size: 202 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e0c70
//
// 005e0c70  55                   push ebp
// 005e0c71  8bec                 mov ebp, esp
// 005e0c73  6aff                 push -1
// 005e0c75  68d0a97500           push 0x75a9d0
// 005e0c7a  64a100000000         mov eax, dword ptr fs:[0]
// 005e0c80  50                   push eax
// 005e0c81  64892500000000       mov dword ptr fs:[0], esp
// 005e0c88  83ec0c               sub esp, 0xc
// 005e0c8b  53                   push ebx
// 005e0c8c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005e0c8f  8b4304               mov eax, dword ptr [ebx + 4]
// 005e0c92  56                   push esi
// 005e0c93  8bf1                 mov esi, ecx
// 005e0c95  33c9                 xor ecx, ecx
// 005e0c97  3bc1                 cmp eax, ecx
// 005e0c99  57                   push edi
// 005e0c9a  8965f0               mov dword ptr [ebp - 0x10], esp
// 005e0c9d  8975e8               mov dword ptr [ebp - 0x18], esi
// 005e0ca0  7504                 jne 0x5e0ca6
// 005e0ca2  33ff                 xor edi, edi
// 005e0ca4  eb08                 jmp 0x5e0cae
// 005e0ca6  8b7b08               mov edi, dword ptr [ebx + 8]
// 005e0ca9  2bf8                 sub edi, eax
// 005e0cab  c1ff03               sar edi, 3
// 005e0cae  3bf9                 cmp edi, ecx
// 005e0cb0  894e04               mov dword ptr [esi + 4], ecx
// 005e0cb3  894e08               mov dword ptr [esi + 8], ecx
// 005e0cb6  894e0c               mov dword ptr [esi + 0xc], ecx
// 005e0cb9  746a                 je 0x5e0d25
// 005e0cbb  81ffffffff1f         cmp edi, 0x1fffffff
// 005e0cc1  7605                 jbe 0x5e0cc8
// 005e0cc3  e868c0feff           call 0x5ccd30
// 005e0cc8  51                   push ecx
// 005e0cc9  57                   push edi
// 005e0cca  e8f16df8ff           call 0x567ac0
// 005e0ccf  894604               mov dword ptr [esi + 4], eax
// 005e0cd2  894608               mov dword ptr [esi + 8], eax
// 005e0cd5  8d04f8               lea eax, [eax + edi*8]
// 005e0cd8  89460c               mov dword ptr [esi + 0xc], eax
// 005e0cdb  8b4308               mov eax, dword ptr [ebx + 8]
// 005e0cde  83c408               add esp, 8
// 005e0ce1  394304               cmp dword ptr [ebx + 4], eax
// 005e0ce4  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005e0ceb  8945ec               mov dword ptr [ebp - 0x14], eax
// 005e0cee  7606                 jbe 0x5e0cf6
// 005e0cf0  ff15d8e67700         call dword ptr [0x77e6d8]
// 005e0cf6  8b7b04               mov edi, dword ptr [ebx + 4]
// 005e0cf9  3b7b08               cmp edi, dword ptr [ebx + 8]
// 005e0cfc  7606                 jbe 0x5e0d04
// 005e0cfe  ff15d8e67700         call dword ptr [0x77e6d8]
// 005e0d04  8b4604               mov eax, dword ptr [esi + 4]
// 005e0d07  c6450800             mov byte ptr [ebp + 8], 0
// 005e0d0b  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005e0d0e  8b5508               mov edx, dword ptr [ebp + 8]
// 005e0d11  51                   push ecx
// 005e0d12  52                   push edx
// 005e0d13  56                   push esi
// 005e0d14  50                   push eax
// 005e0d15  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 005e0d18  50                   push eax
// 005e0d19  57                   push edi
// 005e0d1a  e80147f9ff           call 0x575420
// 005e0d1f  83c418               add esp, 0x18
// 005e0d22  894608               mov dword ptr [esi + 8], eax
// 005e0d25  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005e0d28  5f                   pop edi
// 005e0d29  8bc6                 mov eax, esi
// 005e0d2b  5e                   pop esi
// 005e0d2c  64890d00000000       mov dword ptr fs:[0], ecx
// 005e0d33  5b                   pop ebx
// 005e0d34  8be5                 mov esp, ebp
// 005e0d36  5d                   pop ebp
// 005e0d37  c20400               ret 4
// standard library vector<pod8> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
