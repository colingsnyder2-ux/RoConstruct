// from server: 100% by auto
// roc 2010-06 00436800  unit: IIHAAH::?$CMap  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00436800
//
// 00436800  55                   push ebp
// 00436801  8bec                 mov ebp, esp
// 00436803  6aff                 push -1
// 00436805  68680a9800           push 0x980a68
// 0043680a  64a100000000         mov eax, dword ptr fs:[0]
// 00436810  50                   push eax
// 00436811  64892500000000       mov dword ptr fs:[0], esp
// 00436818  83ec0c               sub esp, 0xc
// 0043681b  53                   push ebx
// 0043681c  56                   push esi
// 0043681d  57                   push edi
// 0043681e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00436821  8bf1                 mov esi, ecx
// 00436823  6a04                 push 4
// 00436825  8975e8               mov dword ptr [ebp - 0x18], esi
// 00436828  e873113700           call 0x7a79a0
// 0043682d  33c9                 xor ecx, ecx
// 0043682f  83c404               add esp, 4
// 00436832  3bc1                 cmp eax, ecx
// 00436834  7404                 je 0x43683a
// 00436836  8930                 mov dword ptr [eax], esi
// 00436838  eb02                 jmp 0x43683c
// 0043683a  33c0                 xor eax, eax
// 0043683c  8906                 mov dword ptr [esi], eax
// 0043683e  8b5d08               mov ebx, dword ptr [ebp + 8]
// 00436841  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 00436844  2b7b0c               sub edi, dword ptr [ebx + 0xc]
// 00436847  894dfc               mov dword ptr [ebp - 4], ecx
// 0043684a  c1ff03               sar edi, 3
// 0043684d  894e0c               mov dword ptr [esi + 0xc], ecx
// 00436850  894e10               mov dword ptr [esi + 0x10], ecx
// 00436853  894e14               mov dword ptr [esi + 0x14], ecx
// 00436856  3bf9                 cmp edi, ecx
// 00436858  746a                 je 0x4368c4
// 0043685a  81ffffffff1f         cmp edi, 0x1fffffff
// 00436860  7605                 jbe 0x436867
// 00436862  e889d5feff           call 0x423df0
// 00436867  51                   push ecx
// 00436868  57                   push edi
// 00436869  e8427d4c00           call 0x8fe5b0
// 0043686e  89460c               mov dword ptr [esi + 0xc], eax
// 00436871  894610               mov dword ptr [esi + 0x10], eax
// 00436874  8d04f8               lea eax, [eax + edi*8]
// 00436877  894614               mov dword ptr [esi + 0x14], eax
// 0043687a  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0043687d  83c408               add esp, 8
// 00436880  c645fc01             mov byte ptr [ebp - 4], 1
// 00436884  8945ec               mov dword ptr [ebp - 0x14], eax
// 00436887  39430c               cmp dword ptr [ebx + 0xc], eax
// 0043688a  7606                 jbe 0x436892
// 0043688c  ff150ca99e00         call dword ptr [0x9ea90c]
// 00436892  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 00436895  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 00436898  7606                 jbe 0x4368a0
// 0043689a  ff150ca99e00         call dword ptr [0x9ea90c]
// 004368a0  8b460c               mov eax, dword ptr [esi + 0xc]
// 004368a3  c6450800             mov byte ptr [ebp + 8], 0
// 004368a7  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004368aa  8b5508               mov edx, dword ptr [ebp + 8]
// 004368ad  51                   push ecx
// 004368ae  52                   push edx
// 004368af  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004368b2  8d4e08               lea ecx, [esi + 8]
// 004368b5  51                   push ecx
// 004368b6  50                   push eax
// 004368b7  52                   push edx
// 004368b8  57                   push edi
// 004368b9  e832941d00           call 0x60fcf0
// 004368be  83c418               add esp, 0x18
// 004368c1  894610               mov dword ptr [esi + 0x10], eax
// 004368c4  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004368c7  5f                   pop edi
// 004368c8  8bc6                 mov eax, esi
// 004368ca  5e                   pop esi
// 004368cb  64890d00000000       mov dword ptr fs:[0], ecx
// 004368d2  5b                   pop ebx
// 004368d3  8be5                 mov esp, ebp
// 004368d5  5d                   pop ebp
// 004368d6  c20400               ret 4
// standard library vector<pod8> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
