// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 0055fed0  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055fed0
//
// 0055fed0  55                   push ebp
// 0055fed1  8bec                 mov ebp, esp
// 0055fed3  6aff                 push -1
// 0055fed5  6828ec7c00           push 0x7cec28
// 0055feda  64a100000000         mov eax, dword ptr fs:[0]
// 0055fee0  50                   push eax
// 0055fee1  64892500000000       mov dword ptr fs:[0], esp
// 0055fee8  83ec0c               sub esp, 0xc
// 0055feeb  53                   push ebx
// 0055feec  56                   push esi
// 0055feed  57                   push edi
// 0055feee  8965f0               mov dword ptr [ebp - 0x10], esp
// 0055fef1  8bf1                 mov esi, ecx
// 0055fef3  6a04                 push 4
// 0055fef5  8975e8               mov dword ptr [ebp - 0x18], esi
// 0055fef8  e8230a1400           call 0x6a0920
// 0055fefd  33c9                 xor ecx, ecx
// 0055feff  83c404               add esp, 4
// 0055ff02  3bc1                 cmp eax, ecx
// 0055ff04  7404                 je 0x55ff0a
// 0055ff06  8930                 mov dword ptr [eax], esi
// 0055ff08  eb02                 jmp 0x55ff0c
// 0055ff0a  33c0                 xor eax, eax
// 0055ff0c  8906                 mov dword ptr [esi], eax
// 0055ff0e  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0055ff11  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 0055ff14  2b7b0c               sub edi, dword ptr [ebx + 0xc]
// 0055ff17  894dfc               mov dword ptr [ebp - 4], ecx
// 0055ff1a  c1ff03               sar edi, 3
// 0055ff1d  894e0c               mov dword ptr [esi + 0xc], ecx
// 0055ff20  894e10               mov dword ptr [esi + 0x10], ecx
// 0055ff23  894e14               mov dword ptr [esi + 0x14], ecx
// 0055ff26  3bf9                 cmp edi, ecx
// 0055ff28  746a                 je 0x55ff94
// 0055ff2a  81ffffffff1f         cmp edi, 0x1fffffff
// 0055ff30  7605                 jbe 0x55ff37
// 0055ff32  e8096ef6ff           call 0x4c6d40
// 0055ff37  51                   push ecx
// 0055ff38  57                   push edi
// 0055ff39  e802fe1000           call 0x66fd40
// 0055ff3e  89460c               mov dword ptr [esi + 0xc], eax
// 0055ff41  894610               mov dword ptr [esi + 0x10], eax
// 0055ff44  8d04f8               lea eax, [eax + edi*8]
// 0055ff47  894614               mov dword ptr [esi + 0x14], eax
// 0055ff4a  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0055ff4d  83c408               add esp, 8
// 0055ff50  c645fc01             mov byte ptr [ebp - 4], 1
// 0055ff54  8945ec               mov dword ptr [ebp - 0x14], eax
// 0055ff57  39430c               cmp dword ptr [ebx + 0xc], eax
// 0055ff5a  7606                 jbe 0x55ff62
// 0055ff5c  ff1590288000         call dword ptr [0x802890]
// 0055ff62  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 0055ff65  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 0055ff68  7606                 jbe 0x55ff70
// 0055ff6a  ff1590288000         call dword ptr [0x802890]
// 0055ff70  8b460c               mov eax, dword ptr [esi + 0xc]
// 0055ff73  c6450800             mov byte ptr [ebp + 8], 0
// 0055ff77  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0055ff7a  8b5508               mov edx, dword ptr [ebp + 8]
// 0055ff7d  51                   push ecx
// 0055ff7e  52                   push edx
// 0055ff7f  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 0055ff82  8d4e08               lea ecx, [esi + 8]
// 0055ff85  51                   push ecx
// 0055ff86  50                   push eax
// 0055ff87  52                   push edx
// 0055ff88  57                   push edi
// 0055ff89  e842d7ffff           call 0x55d6d0
// 0055ff8e  83c418               add esp, 0x18
// 0055ff91  894610               mov dword ptr [esi + 0x10], eax
// 0055ff94  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0055ff97  5f                   pop edi
// 0055ff98  8bc6                 mov eax, esi
// 0055ff9a  5e                   pop esi
// 0055ff9b  64890d00000000       mov dword ptr fs:[0], ecx
// 0055ffa2  5b                   pop ebx
// 0055ffa3  8be5                 mov esp, ebp
// 0055ffa5  5d                   pop ebp
// 0055ffa6  c20400               ret 4
// standard library vector<pod8> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
