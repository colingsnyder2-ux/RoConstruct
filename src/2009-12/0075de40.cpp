// from server: 100% by auto
// roc 2009-12 0075de40  unit: RBX::VLuaDragger::?$FactoryProduct  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0075de40
//
// 0075de40  55                   push ebp
// 0075de41  8bec                 mov ebp, esp
// 0075de43  6aff                 push -1
// 0075de45  6898189500           push 0x951898
// 0075de4a  64a100000000         mov eax, dword ptr fs:[0]
// 0075de50  50                   push eax
// 0075de51  64892500000000       mov dword ptr fs:[0], esp
// 0075de58  83ec0c               sub esp, 0xc
// 0075de5b  53                   push ebx
// 0075de5c  56                   push esi
// 0075de5d  57                   push edi
// 0075de5e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0075de61  8bf1                 mov esi, ecx
// 0075de63  6a04                 push 4
// 0075de65  8975e8               mov dword ptr [ebp - 0x18], esi
// 0075de68  e8f3590900           call 0x7f3860
// 0075de6d  33c9                 xor ecx, ecx
// 0075de6f  83c404               add esp, 4
// 0075de72  3bc1                 cmp eax, ecx
// 0075de74  7404                 je 0x75de7a
// 0075de76  8930                 mov dword ptr [eax], esi
// 0075de78  eb02                 jmp 0x75de7c
// 0075de7a  33c0                 xor eax, eax
// 0075de7c  8906                 mov dword ptr [esi], eax
// 0075de7e  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0075de81  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 0075de84  2b7b0c               sub edi, dword ptr [ebx + 0xc]
// 0075de87  894dfc               mov dword ptr [ebp - 4], ecx
// 0075de8a  c1ff03               sar edi, 3
// 0075de8d  894e0c               mov dword ptr [esi + 0xc], ecx
// 0075de90  894e10               mov dword ptr [esi + 0x10], ecx
// 0075de93  894e14               mov dword ptr [esi + 0x14], ecx
// 0075de96  3bf9                 cmp edi, ecx
// 0075de98  746a                 je 0x75df04
// 0075de9a  81ffffffff1f         cmp edi, 0x1fffffff
// 0075dea0  7605                 jbe 0x75dea7
// 0075dea2  e8b942ceff           call 0x442160
// 0075dea7  51                   push ecx
// 0075dea8  57                   push edi
// 0075dea9  e822dce1ff           call 0x57bad0
// 0075deae  89460c               mov dword ptr [esi + 0xc], eax
// 0075deb1  894610               mov dword ptr [esi + 0x10], eax
// 0075deb4  8d04f8               lea eax, [eax + edi*8]
// 0075deb7  894614               mov dword ptr [esi + 0x14], eax
// 0075deba  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0075debd  83c408               add esp, 8
// 0075dec0  c645fc01             mov byte ptr [ebp - 4], 1
// 0075dec4  8945ec               mov dword ptr [ebp - 0x14], eax
// 0075dec7  39430c               cmp dword ptr [ebx + 0xc], eax
// 0075deca  7606                 jbe 0x75ded2
// 0075decc  ff1560b79800         call dword ptr [0x98b760]
// 0075ded2  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 0075ded5  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 0075ded8  7606                 jbe 0x75dee0
// 0075deda  ff1560b79800         call dword ptr [0x98b760]
// 0075dee0  8b460c               mov eax, dword ptr [esi + 0xc]
// 0075dee3  c6450800             mov byte ptr [ebp + 8], 0
// 0075dee7  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0075deea  8b5508               mov edx, dword ptr [ebp + 8]
// 0075deed  51                   push ecx
// 0075deee  52                   push edx
// 0075deef  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 0075def2  8d4e08               lea ecx, [esi + 8]
// 0075def5  51                   push ecx
// 0075def6  50                   push eax
// 0075def7  52                   push edx
// 0075def8  57                   push edi
// 0075def9  e822f6ffff           call 0x75d520
// 0075defe  83c418               add esp, 0x18
// 0075df01  894610               mov dword ptr [esi + 0x10], eax
// 0075df04  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0075df07  5f                   pop edi
// 0075df08  8bc6                 mov eax, esi
// 0075df0a  5e                   pop esi
// 0075df0b  64890d00000000       mov dword ptr fs:[0], ecx
// 0075df12  5b                   pop ebx
// 0075df13  8be5                 mov esp, ebp
// 0075df15  5d                   pop ebp
// 0075df16  c20400               ret 4
// standard library vector<pod8> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
