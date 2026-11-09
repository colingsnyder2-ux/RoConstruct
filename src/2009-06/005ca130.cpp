// from server: 100% by auto
// roc 2009-06 005ca130  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ca130
//
// 005ca130  55                   push ebp
// 005ca131  8bec                 mov ebp, esp
// 005ca133  6aff                 push -1
// 005ca135  6818228600           push 0x862218
// 005ca13a  64a100000000         mov eax, dword ptr fs:[0]
// 005ca140  50                   push eax
// 005ca141  64892500000000       mov dword ptr fs:[0], esp
// 005ca148  83ec0c               sub esp, 0xc
// 005ca14b  53                   push ebx
// 005ca14c  56                   push esi
// 005ca14d  57                   push edi
// 005ca14e  8965f0               mov dword ptr [ebp - 0x10], esp
// 005ca151  8bf1                 mov esi, ecx
// 005ca153  6a04                 push 4
// 005ca155  8975e8               mov dword ptr [ebp - 0x18], esi
// 005ca158  e8dbe81400           call 0x718a38
// 005ca15d  33c9                 xor ecx, ecx
// 005ca15f  83c404               add esp, 4
// 005ca162  3bc1                 cmp eax, ecx
// 005ca164  7404                 je 0x5ca16a
// 005ca166  8930                 mov dword ptr [eax], esi
// 005ca168  eb02                 jmp 0x5ca16c
// 005ca16a  33c0                 xor eax, eax
// 005ca16c  8906                 mov dword ptr [esi], eax
// 005ca16e  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005ca171  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 005ca174  2b7b0c               sub edi, dword ptr [ebx + 0xc]
// 005ca177  894dfc               mov dword ptr [ebp - 4], ecx
// 005ca17a  c1ff03               sar edi, 3
// 005ca17d  894e0c               mov dword ptr [esi + 0xc], ecx
// 005ca180  894e10               mov dword ptr [esi + 0x10], ecx
// 005ca183  894e14               mov dword ptr [esi + 0x14], ecx
// 005ca186  3bf9                 cmp edi, ecx
// 005ca188  746a                 je 0x5ca1f4
// 005ca18a  81ffffffff1f         cmp edi, 0x1fffffff
// 005ca190  7605                 jbe 0x5ca197
// 005ca192  e8c961ecff           call 0x490360
// 005ca197  51                   push ecx
// 005ca198  57                   push edi
// 005ca199  e852adebff           call 0x484ef0
// 005ca19e  89460c               mov dword ptr [esi + 0xc], eax
// 005ca1a1  894610               mov dword ptr [esi + 0x10], eax
// 005ca1a4  8d04f8               lea eax, [eax + edi*8]
// 005ca1a7  894614               mov dword ptr [esi + 0x14], eax
// 005ca1aa  8b4310               mov eax, dword ptr [ebx + 0x10]
// 005ca1ad  83c408               add esp, 8
// 005ca1b0  c645fc01             mov byte ptr [ebp - 4], 1
// 005ca1b4  8945ec               mov dword ptr [ebp - 0x14], eax
// 005ca1b7  39430c               cmp dword ptr [ebx + 0xc], eax
// 005ca1ba  7606                 jbe 0x5ca1c2
// 005ca1bc  ff15ace98900         call dword ptr [0x89e9ac]
// 005ca1c2  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 005ca1c5  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 005ca1c8  7606                 jbe 0x5ca1d0
// 005ca1ca  ff15ace98900         call dword ptr [0x89e9ac]
// 005ca1d0  8b460c               mov eax, dword ptr [esi + 0xc]
// 005ca1d3  c6450800             mov byte ptr [ebp + 8], 0
// 005ca1d7  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005ca1da  8b5508               mov edx, dword ptr [ebp + 8]
// 005ca1dd  51                   push ecx
// 005ca1de  52                   push edx
// 005ca1df  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 005ca1e2  8d4e08               lea ecx, [esi + 8]
// 005ca1e5  51                   push ecx
// 005ca1e6  50                   push eax
// 005ca1e7  52                   push edx
// 005ca1e8  57                   push edi
// 005ca1e9  e872f8ffff           call 0x5c9a60
// 005ca1ee  83c418               add esp, 0x18
// 005ca1f1  894610               mov dword ptr [esi + 0x10], eax
// 005ca1f4  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005ca1f7  5f                   pop edi
// 005ca1f8  8bc6                 mov eax, esi
// 005ca1fa  5e                   pop esi
// 005ca1fb  64890d00000000       mov dword ptr fs:[0], ecx
// 005ca202  5b                   pop ebx
// 005ca203  8be5                 mov esp, ebp
// 005ca205  5d                   pop ebp
// 005ca206  c20400               ret 4
// standard library vector<pod8> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
