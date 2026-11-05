// from server: 100% by auto
// roc 2010-06 00742840  unit: RBX::VHttp::?$sp_counted_impl_p  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00742840
//
// 00742840  55                   push ebp
// 00742841  8bec                 mov ebp, esp
// 00742843  6aff                 push -1
// 00742845  6818a89a00           push 0x9aa818
// 0074284a  64a100000000         mov eax, dword ptr fs:[0]
// 00742850  50                   push eax
// 00742851  64892500000000       mov dword ptr fs:[0], esp
// 00742858  83ec0c               sub esp, 0xc
// 0074285b  53                   push ebx
// 0074285c  56                   push esi
// 0074285d  57                   push edi
// 0074285e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00742861  8bf1                 mov esi, ecx
// 00742863  6a04                 push 4
// 00742865  8975e8               mov dword ptr [ebp - 0x18], esi
// 00742868  e833510600           call 0x7a79a0
// 0074286d  83c404               add esp, 4
// 00742870  85c0                 test eax, eax
// 00742872  7404                 je 0x742878
// 00742874  8930                 mov dword ptr [eax], esi
// 00742876  eb02                 jmp 0x74287a
// 00742878  33c0                 xor eax, eax
// 0074287a  8906                 mov dword ptr [esi], eax
// 0074287c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0074287f  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00742882  2b4b0c               sub ecx, dword ptr [ebx + 0xc]
// 00742885  b867666666           mov eax, 0x66666667
// 0074288a  f7e9                 imul ecx
// 0074288c  c1fa04               sar edx, 4
// 0074288f  8bfa                 mov edi, edx
// 00742891  b800000000           mov eax, 0
// 00742896  c1ef1f               shr edi, 0x1f
// 00742899  03fa                 add edi, edx
// 0074289b  c745fc00000000       mov dword ptr [ebp - 4], 0
// 007428a2  89460c               mov dword ptr [esi + 0xc], eax
// 007428a5  894610               mov dword ptr [esi + 0x10], eax
// 007428a8  894614               mov dword ptr [esi + 0x14], eax
// 007428ab  746d                 je 0x74291a
// 007428ad  81ff66666606         cmp edi, 0x6666666
// 007428b3  7605                 jbe 0x7428ba
// 007428b5  e83615ceff           call 0x423df0
// 007428ba  50                   push eax
// 007428bb  57                   push edi
// 007428bc  e8ff79f6ff           call 0x6aa2c0
// 007428c1  8d0cbf               lea ecx, [edi + edi*4]
// 007428c4  8d14c8               lea edx, [eax + ecx*8]
// 007428c7  89460c               mov dword ptr [esi + 0xc], eax
// 007428ca  894610               mov dword ptr [esi + 0x10], eax
// 007428cd  895614               mov dword ptr [esi + 0x14], edx
// 007428d0  8b4310               mov eax, dword ptr [ebx + 0x10]
// 007428d3  83c408               add esp, 8
// 007428d6  c645fc01             mov byte ptr [ebp - 4], 1
// 007428da  8945ec               mov dword ptr [ebp - 0x14], eax
// 007428dd  39430c               cmp dword ptr [ebx + 0xc], eax
// 007428e0  7606                 jbe 0x7428e8
// 007428e2  ff150ca99e00         call dword ptr [0x9ea90c]
// 007428e8  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 007428eb  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 007428ee  7606                 jbe 0x7428f6
// 007428f0  ff150ca99e00         call dword ptr [0x9ea90c]
// 007428f6  8b460c               mov eax, dword ptr [esi + 0xc]
// 007428f9  c6450800             mov byte ptr [ebp + 8], 0
// 007428fd  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00742900  8b5508               mov edx, dword ptr [ebp + 8]
// 00742903  51                   push ecx
// 00742904  52                   push edx
// 00742905  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00742908  8d4e08               lea ecx, [esi + 8]
// 0074290b  51                   push ecx
// 0074290c  50                   push eax
// 0074290d  52                   push edx
// 0074290e  57                   push edi
// 0074290f  e8acefffff           call 0x7418c0
// 00742914  83c418               add esp, 0x18
// 00742917  894610               mov dword ptr [esi + 0x10], eax
// 0074291a  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0074291d  5f                   pop edi
// 0074291e  8bc6                 mov eax, esi
// 00742920  5e                   pop esi
// 00742921  64890d00000000       mov dword ptr fs:[0], ecx
// 00742928  5b                   pop ebx
// 00742929  8be5                 mov esp, ebp
// 0074292b  5d                   pop ebp
// 0074292c  c20400               ret 4
// standard library vector<pod40> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod40>
struct E { int v[10]; };
#include <vector>
template class std::vector<E>;
