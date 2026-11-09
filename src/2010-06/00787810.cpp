// from server: 100% by auto
// roc 2010-06 00787810  unit: RBX::HUMAN::GettingUp  size: 210 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00787810
//
// 00787810  6aff                 push -1
// 00787812  68d8ce9a00           push 0x9aced8
// 00787817  64a100000000         mov eax, dword ptr fs:[0]
// 0078781d  50                   push eax
// 0078781e  64892500000000       mov dword ptr fs:[0], esp
// 00787825  51                   push ecx
// 00787826  53                   push ebx
// 00787827  56                   push esi
// 00787828  57                   push edi
// 00787829  8bf1                 mov esi, ecx
// 0078782b  6a04                 push 4
// 0078782d  89742410             mov dword ptr [esp + 0x10], esi
// 00787831  e86a010200           call 0x7a79a0
// 00787836  33c9                 xor ecx, ecx
// 00787838  83c404               add esp, 4
// 0078783b  3bc1                 cmp eax, ecx
// 0078783d  7404                 je 0x787843
// 0078783f  8930                 mov dword ptr [eax], esi
// 00787841  eb02                 jmp 0x787845
// 00787843  33c0                 xor eax, eax
// 00787845  8906                 mov dword ptr [esi], eax
// 00787847  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0078784b  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 0078784e  2b7b0c               sub edi, dword ptr [ebx + 0xc]
// 00787851  894c2418             mov dword ptr [esp + 0x18], ecx
// 00787855  c1ff02               sar edi, 2
// 00787858  894e0c               mov dword ptr [esi + 0xc], ecx
// 0078785b  894e10               mov dword ptr [esi + 0x10], ecx
// 0078785e  894e14               mov dword ptr [esi + 0x14], ecx
// 00787861  3bf9                 cmp edi, ecx
// 00787863  7467                 je 0x7878cc
// 00787865  81ffffffff3f         cmp edi, 0x3fffffff
// 0078786b  7605                 jbe 0x787872
// 0078786d  e87ec5c9ff           call 0x423df0
// 00787872  51                   push ecx
// 00787873  57                   push edi
// 00787874  e897da1400           call 0x8d5310
// 00787879  89460c               mov dword ptr [esi + 0xc], eax
// 0078787c  894610               mov dword ptr [esi + 0x10], eax
// 0078787f  8d04b8               lea eax, [eax + edi*4]
// 00787882  894614               mov dword ptr [esi + 0x14], eax
// 00787885  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 00787888  83c408               add esp, 8
// 0078788b  397b0c               cmp dword ptr [ebx + 0xc], edi
// 0078788e  7606                 jbe 0x787896
// 00787890  ff150ca99e00         call dword ptr [0x9ea90c]
// 00787896  55                   push ebp
// 00787897  8b6b0c               mov ebp, dword ptr [ebx + 0xc]
// 0078789a  3b6b10               cmp ebp, dword ptr [ebx + 0x10]
// 0078789d  7606                 jbe 0x7878a5
// 0078789f  ff150ca99e00         call dword ptr [0x9ea90c]
// 007878a5  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007878a8  2bfd                 sub edi, ebp
// 007878aa  c1ff02               sar edi, 2
// 007878ad  8d04bd00000000       lea eax, [edi*4]
// 007878b4  8d1c08               lea ebx, [eax + ecx]
// 007878b7  85ff                 test edi, edi
// 007878b9  760d                 jbe 0x7878c8
// 007878bb  50                   push eax
// 007878bc  55                   push ebp
// 007878bd  50                   push eax
// 007878be  51                   push ecx
// 007878bf  ff1580a89e00         call dword ptr [0x9ea880]
// 007878c5  83c410               add esp, 0x10
// 007878c8  895e10               mov dword ptr [esi + 0x10], ebx
// 007878cb  5d                   pop ebp
// 007878cc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007878d0  5f                   pop edi
// 007878d1  8bc6                 mov eax, esi
// 007878d3  5e                   pop esi
// 007878d4  5b                   pop ebx
// 007878d5  64890d00000000       mov dword ptr fs:[0], ecx
// 007878dc  83c410               add esp, 0x10
// 007878df  c20400               ret 4
// standard library vector<ptr> (function ??0?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
