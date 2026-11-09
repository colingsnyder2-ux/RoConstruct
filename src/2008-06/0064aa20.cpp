// from server: 100% by auto
// roc 2008-06 0064aa20  unit: RBX::SleepStage  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064aa20
//
// 0064aa20  64a100000000         mov eax, dword ptr fs:[0]
// 0064aa26  6aff                 push -1
// 0064aa28  6842e87d00           push 0x7de842
// 0064aa2d  50                   push eax
// 0064aa2e  64892500000000       mov dword ptr fs:[0], esp
// 0064aa35  8b442418             mov eax, dword ptr [esp + 0x18]
// 0064aa39  83ec48               sub esp, 0x48
// 0064aa3c  80781100             cmp byte ptr [eax + 0x11], 0
// 0064aa40  55                   push ebp
// 0064aa41  8be9                 mov ebp, ecx
// 0064aa43  7459                 je 0x64aa9e
// 0064aa45  6870b28000           push 0x80b270
// 0064aa4a  8d4c240c             lea ecx, [esp + 0xc]
// 0064aa4e  ff1558248000         call dword ptr [0x802458]
// 0064aa54  8d4c2424             lea ecx, [esp + 0x24]
// 0064aa58  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0064aa60  ff1598288000         call dword ptr [0x802898]
// 0064aa66  8d442408             lea eax, [esp + 8]
// 0064aa6a  50                   push eax
// 0064aa6b  8d4c2434             lea ecx, [esp + 0x34]
// 0064aa6f  c644245801           mov byte ptr [esp + 0x58], 1
// 0064aa74  c744242810b18000     mov dword ptr [esp + 0x28], 0x80b110
// 0064aa7c  ff155c248000         call dword ptr [0x80245c]
// 0064aa82  683c0c8d00           push 0x8d0c3c
// 0064aa87  8d4c2428             lea ecx, [esp + 0x28]
// 0064aa8b  51                   push ecx
// 0064aa8c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 0064aa91  c744242c28b18000     mov dword ptr [esp + 0x2c], 0x80b128
// 0064aa99  e8ee6a0500           call 0x6a158c
// 0064aa9e  53                   push ebx
// 0064aa9f  56                   push esi
// 0064aaa0  8bd8                 mov ebx, eax
// 0064aaa2  57                   push edi
// 0064aaa3  8d4c246c             lea ecx, [esp + 0x6c]
// 0064aaa7  895c2410             mov dword ptr [esp + 0x10], ebx
// 0064aaab  e890e8f9ff           call 0x5e9340
// 0064aab0  8b0b                 mov ecx, dword ptr [ebx]
// 0064aab2  80791100             cmp byte ptr [ecx + 0x11], 0
// 0064aab6  7405                 je 0x64aabd
// 0064aab8  8b7b08               mov edi, dword ptr [ebx + 8]
// 0064aabb  eb1b                 jmp 0x64aad8
// 0064aabd  8b5308               mov edx, dword ptr [ebx + 8]
// 0064aac0  807a1100             cmp byte ptr [edx + 0x11], 0
// 0064aac4  7404                 je 0x64aaca
// 0064aac6  8bf9                 mov edi, ecx
// 0064aac8  eb0e                 jmp 0x64aad8
// 0064aaca  8b442470             mov eax, dword ptr [esp + 0x70]
// 0064aace  8b7808               mov edi, dword ptr [eax + 8]
// 0064aad1  8d5008               lea edx, [eax + 8]
// 0064aad4  3bc3                 cmp eax, ebx
// 0064aad6  756b                 jne 0x64ab43
// 0064aad8  807f1100             cmp byte ptr [edi + 0x11], 0
// 0064aadc  8b7304               mov esi, dword ptr [ebx + 4]
// 0064aadf  7503                 jne 0x64aae4
// 0064aae1  897704               mov dword ptr [edi + 4], esi
// 0064aae4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0064aae7  395804               cmp dword ptr [eax + 4], ebx
// 0064aaea  7505                 jne 0x64aaf1
// 0064aaec  897804               mov dword ptr [eax + 4], edi
// 0064aaef  eb0b                 jmp 0x64aafc
// 0064aaf1  391e                 cmp dword ptr [esi], ebx
// 0064aaf3  7504                 jne 0x64aaf9
// 0064aaf5  893e                 mov dword ptr [esi], edi
// 0064aaf7  eb03                 jmp 0x64aafc
// 0064aaf9  897e08               mov dword ptr [esi + 8], edi
// 0064aafc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0064aaff  8b03                 mov eax, dword ptr [ebx]
// 0064ab01  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0064ab05  7515                 jne 0x64ab1c
// 0064ab07  807f1100             cmp byte ptr [edi + 0x11], 0
// 0064ab0b  7404                 je 0x64ab11
// 0064ab0d  8bc6                 mov eax, esi
// 0064ab0f  eb09                 jmp 0x64ab1a
// 0064ab11  57                   push edi
// 0064ab12  e839f0e7ff           call 0x4c9b50
// 0064ab17  83c404               add esp, 4
// 0064ab1a  8903                 mov dword ptr [ebx], eax
// 0064ab1c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0064ab1f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0064ab23  394b08               cmp dword ptr [ebx + 8], ecx
// 0064ab26  7577                 jne 0x64ab9f
// 0064ab28  807f1100             cmp byte ptr [edi + 0x11], 0
// 0064ab2c  7407                 je 0x64ab35
// 0064ab2e  8bc6                 mov eax, esi
// 0064ab30  894308               mov dword ptr [ebx + 8], eax
// 0064ab33  eb6a                 jmp 0x64ab9f
// 0064ab35  57                   push edi
// 0064ab36  e815e20100           call 0x668d50
// 0064ab3b  83c404               add esp, 4
// 0064ab3e  894308               mov dword ptr [ebx + 8], eax
// 0064ab41  eb5c                 jmp 0x64ab9f
// 0064ab43  894104               mov dword ptr [ecx + 4], eax
// 0064ab46  8b0b                 mov ecx, dword ptr [ebx]
// 0064ab48  8908                 mov dword ptr [eax], ecx
// 0064ab4a  3b4308               cmp eax, dword ptr [ebx + 8]
// 0064ab4d  7504                 jne 0x64ab53
// 0064ab4f  8bf0                 mov esi, eax
// 0064ab51  eb19                 jmp 0x64ab6c
// 0064ab53  807f1100             cmp byte ptr [edi + 0x11], 0
// 0064ab57  8b7004               mov esi, dword ptr [eax + 4]
// 0064ab5a  7503                 jne 0x64ab5f
// 0064ab5c  897704               mov dword ptr [edi + 4], esi
// 0064ab5f  893e                 mov dword ptr [esi], edi
// 0064ab61  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0064ab64  890a                 mov dword ptr [edx], ecx
// 0064ab66  8b5308               mov edx, dword ptr [ebx + 8]
// 0064ab69  894204               mov dword ptr [edx + 4], eax
// 0064ab6c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0064ab6f  395904               cmp dword ptr [ecx + 4], ebx
// 0064ab72  7505                 jne 0x64ab79
// 0064ab74  894104               mov dword ptr [ecx + 4], eax
// 0064ab77  eb0e                 jmp 0x64ab87
// 0064ab79  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0064ab7c  3919                 cmp dword ptr [ecx], ebx
// 0064ab7e  7504                 jne 0x64ab84
// 0064ab80  8901                 mov dword ptr [ecx], eax
// 0064ab82  eb03                 jmp 0x64ab87
// 0064ab84  894108               mov dword ptr [ecx + 8], eax
// 0064ab87  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0064ab8a  894804               mov dword ptr [eax + 4], ecx
// 0064ab8d  8d4b10               lea ecx, [ebx + 0x10]
// 0064ab90  83c010               add eax, 0x10
// 0064ab93  3bc1                 cmp eax, ecx
// 0064ab95  7408                 je 0x64ab9f
// 0064ab97  8a19                 mov bl, byte ptr [ecx]
// 0064ab99  8a10                 mov dl, byte ptr [eax]
// 0064ab9b  8818                 mov byte ptr [eax], bl
// 0064ab9d  8811                 mov byte ptr [ecx], dl
// 0064ab9f  8b542410             mov edx, dword ptr [esp + 0x10]
// 0064aba3  b301                 mov bl, 1
// 0064aba5  385a10               cmp byte ptr [edx + 0x10], bl
// 0064aba8  0f85fd000000         jne 0x64acab
// 0064abae  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0064abb1  3b7804               cmp edi, dword ptr [eax + 4]
// 0064abb4  0f84ee000000         je 0x64aca8
// 0064abba  8d9b00000000         lea ebx, [ebx]
// 0064abc0  385f10               cmp byte ptr [edi + 0x10], bl
// 0064abc3  0f85df000000         jne 0x64aca8
// 0064abc9  8b06                 mov eax, dword ptr [esi]
// 0064abcb  3bf8                 cmp edi, eax
// 0064abcd  7565                 jne 0x64ac34
// 0064abcf  8b4608               mov eax, dword ptr [esi + 8]
// 0064abd2  80781000             cmp byte ptr [eax + 0x10], 0
// 0064abd6  7512                 jne 0x64abea
// 0064abd8  885810               mov byte ptr [eax + 0x10], bl
// 0064abdb  56                   push esi
// 0064abdc  8bcd                 mov ecx, ebp
// 0064abde  c6461000             mov byte ptr [esi + 0x10], 0
// 0064abe2  e8a9dadeff           call 0x438690
// 0064abe7  8b4608               mov eax, dword ptr [esi + 8]
// 0064abea  80781100             cmp byte ptr [eax + 0x11], 0
// 0064abee  7574                 jne 0x64ac64
// 0064abf0  8b08                 mov ecx, dword ptr [eax]
// 0064abf2  385910               cmp byte ptr [ecx + 0x10], bl
// 0064abf5  7508                 jne 0x64abff
// 0064abf7  8b5008               mov edx, dword ptr [eax + 8]
// 0064abfa  385a10               cmp byte ptr [edx + 0x10], bl
// 0064abfd  7461                 je 0x64ac60
// 0064abff  8b4808               mov ecx, dword ptr [eax + 8]
// 0064ac02  385910               cmp byte ptr [ecx + 0x10], bl
// 0064ac05  7514                 jne 0x64ac1b
// 0064ac07  8b10                 mov edx, dword ptr [eax]
// 0064ac09  885a10               mov byte ptr [edx + 0x10], bl
// 0064ac0c  50                   push eax
// 0064ac0d  8bcd                 mov ecx, ebp
// 0064ac0f  c6401000             mov byte ptr [eax + 0x10], 0
// 0064ac13  e888240400           call 0x68d0a0
// 0064ac18  8b4608               mov eax, dword ptr [esi + 8]
// 0064ac1b  8a4e10               mov cl, byte ptr [esi + 0x10]
// 0064ac1e  884810               mov byte ptr [eax + 0x10], cl
// 0064ac21  885e10               mov byte ptr [esi + 0x10], bl
// 0064ac24  8b5008               mov edx, dword ptr [eax + 8]
// 0064ac27  56                   push esi
// 0064ac28  8bcd                 mov ecx, ebp
// 0064ac2a  885a10               mov byte ptr [edx + 0x10], bl
// 0064ac2d  e85edadeff           call 0x438690
// 0064ac32  eb74                 jmp 0x64aca8
// 0064ac34  80781000             cmp byte ptr [eax + 0x10], 0
// 0064ac38  7511                 jne 0x64ac4b
// 0064ac3a  885810               mov byte ptr [eax + 0x10], bl
// 0064ac3d  56                   push esi
// 0064ac3e  8bcd                 mov ecx, ebp
// 0064ac40  c6461000             mov byte ptr [esi + 0x10], 0
// 0064ac44  e857240400           call 0x68d0a0
// 0064ac49  8b06                 mov eax, dword ptr [esi]
// 0064ac4b  80781100             cmp byte ptr [eax + 0x11], 0
// 0064ac4f  7513                 jne 0x64ac64
// 0064ac51  8b4808               mov ecx, dword ptr [eax + 8]
// 0064ac54  385910               cmp byte ptr [ecx + 0x10], bl
// 0064ac57  751e                 jne 0x64ac77
// 0064ac59  8b10                 mov edx, dword ptr [eax]
// 0064ac5b  385a10               cmp byte ptr [edx + 0x10], bl
// 0064ac5e  7517                 jne 0x64ac77
// 0064ac60  c6401000             mov byte ptr [eax + 0x10], 0
// 0064ac64  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0064ac67  8bfe                 mov edi, esi
// 0064ac69  8b7604               mov esi, dword ptr [esi + 4]
// 0064ac6c  3b7804               cmp edi, dword ptr [eax + 4]
// 0064ac6f  0f854bffffff         jne 0x64abc0
// 0064ac75  eb31                 jmp 0x64aca8
// 0064ac77  8b08                 mov ecx, dword ptr [eax]
// 0064ac79  385910               cmp byte ptr [ecx + 0x10], bl
// 0064ac7c  7514                 jne 0x64ac92
// 0064ac7e  8b5008               mov edx, dword ptr [eax + 8]
// 0064ac81  885a10               mov byte ptr [edx + 0x10], bl
// 0064ac84  50                   push eax
// 0064ac85  8bcd                 mov ecx, ebp
// 0064ac87  c6401000             mov byte ptr [eax + 0x10], 0
// 0064ac8b  e800dadeff           call 0x438690
// 0064ac90  8b06                 mov eax, dword ptr [esi]
// 0064ac92  8a4e10               mov cl, byte ptr [esi + 0x10]
// 0064ac95  884810               mov byte ptr [eax + 0x10], cl
// 0064ac98  885e10               mov byte ptr [esi + 0x10], bl
// 0064ac9b  8b10                 mov edx, dword ptr [eax]
// 0064ac9d  56                   push esi
// 0064ac9e  8bcd                 mov ecx, ebp
// 0064aca0  885a10               mov byte ptr [edx + 0x10], bl
// 0064aca3  e8f8230400           call 0x68d0a0
// 0064aca8  885f10               mov byte ptr [edi + 0x10], bl
// 0064acab  8b442410             mov eax, dword ptr [esp + 0x10]
// 0064acaf  50                   push eax
// 0064acb0  e8c5590500           call 0x6a067a
// 0064acb5  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 0064acb8  83c404               add esp, 4
// 0064acbb  5f                   pop edi
// 0064acbc  5e                   pop esi
// 0064acbd  5b                   pop ebx
// 0064acbe  85c0                 test eax, eax
// 0064acc0  7604                 jbe 0x64acc6
// 0064acc2  48                   dec eax
// 0064acc3  89451c               mov dword ptr [ebp + 0x1c], eax
// 0064acc6  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 0064acca  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0064acce  8b5500               mov edx, dword ptr [ebp]
// 0064acd1  894804               mov dword ptr [eax + 4], ecx
// 0064acd4  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0064acd8  8910                 mov dword ptr [eax], edx
// 0064acda  5d                   pop ebp
// 0064acdb  64890d00000000       mov dword ptr fs:[0], ecx
// 0064ace2  83c454               add esp, 0x54
// 0064ace5  c20c00               ret 0xc
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
