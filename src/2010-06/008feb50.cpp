// from server: 100% by auto
// roc 2010-06 008feb50  unit: Ogre::RbxSceneUpdater  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008feb50
//
// 008feb50  55                   push ebp
// 008feb51  8bec                 mov ebp, esp
// 008feb53  6aff                 push -1
// 008feb55  6838039c00           push 0x9c0338
// 008feb5a  64a100000000         mov eax, dword ptr fs:[0]
// 008feb60  50                   push eax
// 008feb61  64892500000000       mov dword ptr fs:[0], esp
// 008feb68  83ec0c               sub esp, 0xc
// 008feb6b  53                   push ebx
// 008feb6c  56                   push esi
// 008feb6d  57                   push edi
// 008feb6e  8965f0               mov dword ptr [ebp - 0x10], esp
// 008feb71  8bf1                 mov esi, ecx
// 008feb73  6a04                 push 4
// 008feb75  8975e8               mov dword ptr [ebp - 0x18], esi
// 008feb78  e8238eeaff           call 0x7a79a0
// 008feb7d  33c9                 xor ecx, ecx
// 008feb7f  83c404               add esp, 4
// 008feb82  3bc1                 cmp eax, ecx
// 008feb84  7404                 je 0x8feb8a
// 008feb86  8930                 mov dword ptr [eax], esi
// 008feb88  eb02                 jmp 0x8feb8c
// 008feb8a  33c0                 xor eax, eax
// 008feb8c  8906                 mov dword ptr [esi], eax
// 008feb8e  8b5d08               mov ebx, dword ptr [ebp + 8]
// 008feb91  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 008feb94  2b7b0c               sub edi, dword ptr [ebx + 0xc]
// 008feb97  894dfc               mov dword ptr [ebp - 4], ecx
// 008feb9a  c1ff03               sar edi, 3
// 008feb9d  894e0c               mov dword ptr [esi + 0xc], ecx
// 008feba0  894e10               mov dword ptr [esi + 0x10], ecx
// 008feba3  894e14               mov dword ptr [esi + 0x14], ecx
// 008feba6  3bf9                 cmp edi, ecx
// 008feba8  746a                 je 0x8fec14
// 008febaa  81ffffffff1f         cmp edi, 0x1fffffff
// 008febb0  7605                 jbe 0x8febb7
// 008febb2  e83952b2ff           call 0x423df0
// 008febb7  51                   push ecx
// 008febb8  57                   push edi
// 008febb9  e8f2f9ffff           call 0x8fe5b0
// 008febbe  89460c               mov dword ptr [esi + 0xc], eax
// 008febc1  894610               mov dword ptr [esi + 0x10], eax
// 008febc4  8d04f8               lea eax, [eax + edi*8]
// 008febc7  894614               mov dword ptr [esi + 0x14], eax
// 008febca  8b4310               mov eax, dword ptr [ebx + 0x10]
// 008febcd  83c408               add esp, 8
// 008febd0  c645fc01             mov byte ptr [ebp - 4], 1
// 008febd4  8945ec               mov dword ptr [ebp - 0x14], eax
// 008febd7  39430c               cmp dword ptr [ebx + 0xc], eax
// 008febda  7606                 jbe 0x8febe2
// 008febdc  ff150ca99e00         call dword ptr [0x9ea90c]
// 008febe2  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 008febe5  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 008febe8  7606                 jbe 0x8febf0
// 008febea  ff150ca99e00         call dword ptr [0x9ea90c]
// 008febf0  8b460c               mov eax, dword ptr [esi + 0xc]
// 008febf3  c6450800             mov byte ptr [ebp + 8], 0
// 008febf7  8b4d08               mov ecx, dword ptr [ebp + 8]
// 008febfa  8b5508               mov edx, dword ptr [ebp + 8]
// 008febfd  51                   push ecx
// 008febfe  52                   push edx
// 008febff  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 008fec02  8d4e08               lea ecx, [esi + 8]
// 008fec05  51                   push ecx
// 008fec06  50                   push eax
// 008fec07  52                   push edx
// 008fec08  57                   push edi
// 008fec09  e8e2faffff           call 0x8fe6f0
// 008fec0e  83c418               add esp, 0x18
// 008fec11  894610               mov dword ptr [esi + 0x10], eax
// 008fec14  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 008fec17  5f                   pop edi
// 008fec18  8bc6                 mov eax, esi
// 008fec1a  5e                   pop esi
// 008fec1b  64890d00000000       mov dword ptr fs:[0], ecx
// 008fec22  5b                   pop ebx
// 008fec23  8be5                 mov esp, ebp
// 008fec25  5d                   pop ebp
// 008fec26  c20400               ret 4
// standard library vector<pod8> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
