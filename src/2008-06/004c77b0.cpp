// from server: 100% by auto
// roc 2008-06 004c77b0  unit: RBX::VInstance::?$Association::Item  size: 210 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c77b0
//
// 004c77b0  6aff                 push -1
// 004c77b2  68a8957c00           push 0x7c95a8
// 004c77b7  64a100000000         mov eax, dword ptr fs:[0]
// 004c77bd  50                   push eax
// 004c77be  64892500000000       mov dword ptr fs:[0], esp
// 004c77c5  51                   push ecx
// 004c77c6  53                   push ebx
// 004c77c7  56                   push esi
// 004c77c8  57                   push edi
// 004c77c9  8bf1                 mov esi, ecx
// 004c77cb  6a04                 push 4
// 004c77cd  89742410             mov dword ptr [esp + 0x10], esi
// 004c77d1  e84a911d00           call 0x6a0920
// 004c77d6  33c9                 xor ecx, ecx
// 004c77d8  83c404               add esp, 4
// 004c77db  3bc1                 cmp eax, ecx
// 004c77dd  7404                 je 0x4c77e3
// 004c77df  8930                 mov dword ptr [eax], esi
// 004c77e1  eb02                 jmp 0x4c77e5
// 004c77e3  33c0                 xor eax, eax
// 004c77e5  8906                 mov dword ptr [esi], eax
// 004c77e7  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 004c77eb  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 004c77ee  2b7b0c               sub edi, dword ptr [ebx + 0xc]
// 004c77f1  894c2418             mov dword ptr [esp + 0x18], ecx
// 004c77f5  c1ff02               sar edi, 2
// 004c77f8  894e0c               mov dword ptr [esi + 0xc], ecx
// 004c77fb  894e10               mov dword ptr [esi + 0x10], ecx
// 004c77fe  894e14               mov dword ptr [esi + 0x14], ecx
// 004c7801  3bf9                 cmp edi, ecx
// 004c7803  7467                 je 0x4c786c
// 004c7805  81ffffffff3f         cmp edi, 0x3fffffff
// 004c780b  7605                 jbe 0x4c7812
// 004c780d  e82ef5ffff           call 0x4c6d40
// 004c7812  51                   push ecx
// 004c7813  57                   push edi
// 004c7814  e83793f5ff           call 0x420b50
// 004c7819  89460c               mov dword ptr [esi + 0xc], eax
// 004c781c  894610               mov dword ptr [esi + 0x10], eax
// 004c781f  8d04b8               lea eax, [eax + edi*4]
// 004c7822  894614               mov dword ptr [esi + 0x14], eax
// 004c7825  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 004c7828  83c408               add esp, 8
// 004c782b  397b0c               cmp dword ptr [ebx + 0xc], edi
// 004c782e  7606                 jbe 0x4c7836
// 004c7830  ff1590288000         call dword ptr [0x802890]
// 004c7836  55                   push ebp
// 004c7837  8b6b0c               mov ebp, dword ptr [ebx + 0xc]
// 004c783a  3b6b10               cmp ebp, dword ptr [ebx + 0x10]
// 004c783d  7606                 jbe 0x4c7845
// 004c783f  ff1590288000         call dword ptr [0x802890]
// 004c7845  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004c7848  2bfd                 sub edi, ebp
// 004c784a  c1ff02               sar edi, 2
// 004c784d  8d04bd00000000       lea eax, [edi*4]
// 004c7854  8d1c08               lea ebx, [eax + ecx]
// 004c7857  85ff                 test edi, edi
// 004c7859  760d                 jbe 0x4c7868
// 004c785b  50                   push eax
// 004c785c  55                   push ebp
// 004c785d  50                   push eax
// 004c785e  51                   push ecx
// 004c785f  ff1550288000         call dword ptr [0x802850]
// 004c7865  83c410               add esp, 0x10
// 004c7868  895e10               mov dword ptr [esi + 0x10], ebx
// 004c786b  5d                   pop ebp
// 004c786c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c7870  5f                   pop edi
// 004c7871  8bc6                 mov eax, esi
// 004c7873  5e                   pop esi
// 004c7874  5b                   pop ebx
// 004c7875  64890d00000000       mov dword ptr fs:[0], ecx
// 004c787c  83c410               add esp, 0x10
// 004c787f  c20400               ret 4
// standard library vector<ptr> (function ??0?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
