// from server: 100% by auto
// roc 2009-06 004d8e40  unit: RBX::Network::VGuidRegistryService::?$FactoryProduct  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004d8e40
//
// 004d8e40  64a100000000         mov eax, dword ptr fs:[0]
// 004d8e46  6aff                 push -1
// 004d8e48  68b2db8500           push 0x85dbb2
// 004d8e4d  50                   push eax
// 004d8e4e  64892500000000       mov dword ptr fs:[0], esp
// 004d8e55  8b442418             mov eax, dword ptr [esp + 0x18]
// 004d8e59  83ec48               sub esp, 0x48
// 004d8e5c  80781900             cmp byte ptr [eax + 0x19], 0
// 004d8e60  55                   push ebp
// 004d8e61  8be9                 mov ebp, ecx
// 004d8e63  7459                 je 0x4d8ebe
// 004d8e65  68a4c98a00           push 0x8ac9a4
// 004d8e6a  8d4c240c             lea ecx, [esp + 0xc]
// 004d8e6e  ff15b4e48900         call dword ptr [0x89e4b4]
// 004d8e74  8d4c2424             lea ecx, [esp + 0x24]
// 004d8e78  c744245400000000     mov dword ptr [esp + 0x54], 0
// 004d8e80  ff15b8e98900         call dword ptr [0x89e9b8]
// 004d8e86  8d442408             lea eax, [esp + 8]
// 004d8e8a  50                   push eax
// 004d8e8b  8d4c2434             lea ecx, [esp + 0x34]
// 004d8e8f  c644245801           mov byte ptr [esp + 0x58], 1
// 004d8e94  c744242844c98a00     mov dword ptr [esp + 0x28], 0x8ac944
// 004d8e9c  ff15b8e48900         call dword ptr [0x89e4b8]
// 004d8ea2  68dc919700           push 0x9791dc
// 004d8ea7  8d4c2428             lea ecx, [esp + 0x28]
// 004d8eab  51                   push ecx
// 004d8eac  c644245c00           mov byte ptr [esp + 0x5c], 0
// 004d8eb1  c744242c5cc98a00     mov dword ptr [esp + 0x2c], 0x8ac95c
// 004d8eb9  e88c0b2400           call 0x719a4a
// 004d8ebe  53                   push ebx
// 004d8ebf  56                   push esi
// 004d8ec0  8bd8                 mov ebx, eax
// 004d8ec2  57                   push edi
// 004d8ec3  8d4c246c             lea ecx, [esp + 0x6c]
// 004d8ec7  895c2410             mov dword ptr [esp + 0x10], ebx
// 004d8ecb  e8f0931400           call 0x6222c0
// 004d8ed0  8b0b                 mov ecx, dword ptr [ebx]
// 004d8ed2  80791900             cmp byte ptr [ecx + 0x19], 0
// 004d8ed6  7405                 je 0x4d8edd
// 004d8ed8  8b7b08               mov edi, dword ptr [ebx + 8]
// 004d8edb  eb1b                 jmp 0x4d8ef8
// 004d8edd  8b5308               mov edx, dword ptr [ebx + 8]
// 004d8ee0  807a1900             cmp byte ptr [edx + 0x19], 0
// 004d8ee4  7404                 je 0x4d8eea
// 004d8ee6  8bf9                 mov edi, ecx
// 004d8ee8  eb0e                 jmp 0x4d8ef8
// 004d8eea  8b442470             mov eax, dword ptr [esp + 0x70]
// 004d8eee  8b7808               mov edi, dword ptr [eax + 8]
// 004d8ef1  8d5008               lea edx, [eax + 8]
// 004d8ef4  3bc3                 cmp eax, ebx
// 004d8ef6  756b                 jne 0x4d8f63
// 004d8ef8  807f1900             cmp byte ptr [edi + 0x19], 0
// 004d8efc  8b7304               mov esi, dword ptr [ebx + 4]
// 004d8eff  7503                 jne 0x4d8f04
// 004d8f01  897704               mov dword ptr [edi + 4], esi
// 004d8f04  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004d8f07  395804               cmp dword ptr [eax + 4], ebx
// 004d8f0a  7505                 jne 0x4d8f11
// 004d8f0c  897804               mov dword ptr [eax + 4], edi
// 004d8f0f  eb0b                 jmp 0x4d8f1c
// 004d8f11  391e                 cmp dword ptr [esi], ebx
// 004d8f13  7504                 jne 0x4d8f19
// 004d8f15  893e                 mov dword ptr [esi], edi
// 004d8f17  eb03                 jmp 0x4d8f1c
// 004d8f19  897e08               mov dword ptr [esi + 8], edi
// 004d8f1c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 004d8f1f  8b03                 mov eax, dword ptr [ebx]
// 004d8f21  3b442410             cmp eax, dword ptr [esp + 0x10]
// 004d8f25  7515                 jne 0x4d8f3c
// 004d8f27  807f1900             cmp byte ptr [edi + 0x19], 0
// 004d8f2b  7404                 je 0x4d8f31
// 004d8f2d  8bc6                 mov eax, esi
// 004d8f2f  eb09                 jmp 0x4d8f3a
// 004d8f31  57                   push edi
// 004d8f32  e899a51600           call 0x6434d0
// 004d8f37  83c404               add esp, 4
// 004d8f3a  8903                 mov dword ptr [ebx], eax
// 004d8f3c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 004d8f3f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004d8f43  394b08               cmp dword ptr [ebx + 8], ecx
// 004d8f46  7577                 jne 0x4d8fbf
// 004d8f48  807f1900             cmp byte ptr [edi + 0x19], 0
// 004d8f4c  7407                 je 0x4d8f55
// 004d8f4e  8bc6                 mov eax, esi
// 004d8f50  894308               mov dword ptr [ebx + 8], eax
// 004d8f53  eb6a                 jmp 0x4d8fbf
// 004d8f55  57                   push edi
// 004d8f56  e875a30000           call 0x4e32d0
// 004d8f5b  83c404               add esp, 4
// 004d8f5e  894308               mov dword ptr [ebx + 8], eax
// 004d8f61  eb5c                 jmp 0x4d8fbf
// 004d8f63  894104               mov dword ptr [ecx + 4], eax
// 004d8f66  8b0b                 mov ecx, dword ptr [ebx]
// 004d8f68  8908                 mov dword ptr [eax], ecx
// 004d8f6a  3b4308               cmp eax, dword ptr [ebx + 8]
// 004d8f6d  7504                 jne 0x4d8f73
// 004d8f6f  8bf0                 mov esi, eax
// 004d8f71  eb19                 jmp 0x4d8f8c
// 004d8f73  807f1900             cmp byte ptr [edi + 0x19], 0
// 004d8f77  8b7004               mov esi, dword ptr [eax + 4]
// 004d8f7a  7503                 jne 0x4d8f7f
// 004d8f7c  897704               mov dword ptr [edi + 4], esi
// 004d8f7f  893e                 mov dword ptr [esi], edi
// 004d8f81  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004d8f84  890a                 mov dword ptr [edx], ecx
// 004d8f86  8b5308               mov edx, dword ptr [ebx + 8]
// 004d8f89  894204               mov dword ptr [edx + 4], eax
// 004d8f8c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 004d8f8f  395904               cmp dword ptr [ecx + 4], ebx
// 004d8f92  7505                 jne 0x4d8f99
// 004d8f94  894104               mov dword ptr [ecx + 4], eax
// 004d8f97  eb0e                 jmp 0x4d8fa7
// 004d8f99  8b4b04               mov ecx, dword ptr [ebx + 4]
// 004d8f9c  3919                 cmp dword ptr [ecx], ebx
// 004d8f9e  7504                 jne 0x4d8fa4
// 004d8fa0  8901                 mov dword ptr [ecx], eax
// 004d8fa2  eb03                 jmp 0x4d8fa7
// 004d8fa4  894108               mov dword ptr [ecx + 8], eax
// 004d8fa7  8b4b04               mov ecx, dword ptr [ebx + 4]
// 004d8faa  894804               mov dword ptr [eax + 4], ecx
// 004d8fad  8d4b18               lea ecx, [ebx + 0x18]
// 004d8fb0  83c018               add eax, 0x18
// 004d8fb3  3bc1                 cmp eax, ecx
// 004d8fb5  7408                 je 0x4d8fbf
// 004d8fb7  8a19                 mov bl, byte ptr [ecx]
// 004d8fb9  8a10                 mov dl, byte ptr [eax]
// 004d8fbb  8818                 mov byte ptr [eax], bl
// 004d8fbd  8811                 mov byte ptr [ecx], dl
// 004d8fbf  8b542410             mov edx, dword ptr [esp + 0x10]
// 004d8fc3  b301                 mov bl, 1
// 004d8fc5  385a18               cmp byte ptr [edx + 0x18], bl
// 004d8fc8  0f85fd000000         jne 0x4d90cb
// 004d8fce  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004d8fd1  3b7804               cmp edi, dword ptr [eax + 4]
// 004d8fd4  0f84ee000000         je 0x4d90c8
// 004d8fda  8d9b00000000         lea ebx, [ebx]
// 004d8fe0  385f18               cmp byte ptr [edi + 0x18], bl
// 004d8fe3  0f85df000000         jne 0x4d90c8
// 004d8fe9  8b06                 mov eax, dword ptr [esi]
// 004d8feb  3bf8                 cmp edi, eax
// 004d8fed  7565                 jne 0x4d9054
// 004d8fef  8b4608               mov eax, dword ptr [esi + 8]
// 004d8ff2  80781800             cmp byte ptr [eax + 0x18], 0
// 004d8ff6  7512                 jne 0x4d900a
// 004d8ff8  885818               mov byte ptr [eax + 0x18], bl
// 004d8ffb  56                   push esi
// 004d8ffc  8bcd                 mov ecx, ebp
// 004d8ffe  c6461800             mov byte ptr [esi + 0x18], 0
// 004d9002  e839f61300           call 0x618640
// 004d9007  8b4608               mov eax, dword ptr [esi + 8]
// 004d900a  80781900             cmp byte ptr [eax + 0x19], 0
// 004d900e  7574                 jne 0x4d9084
// 004d9010  8b08                 mov ecx, dword ptr [eax]
// 004d9012  385918               cmp byte ptr [ecx + 0x18], bl
// 004d9015  7508                 jne 0x4d901f
// 004d9017  8b5008               mov edx, dword ptr [eax + 8]
// 004d901a  385a18               cmp byte ptr [edx + 0x18], bl
// 004d901d  7461                 je 0x4d9080
// 004d901f  8b4808               mov ecx, dword ptr [eax + 8]
// 004d9022  385918               cmp byte ptr [ecx + 0x18], bl
// 004d9025  7514                 jne 0x4d903b
// 004d9027  8b10                 mov edx, dword ptr [eax]
// 004d9029  885a18               mov byte ptr [edx + 0x18], bl
// 004d902c  50                   push eax
// 004d902d  8bcd                 mov ecx, ebp
// 004d902f  c6401800             mov byte ptr [eax + 0x18], 0
// 004d9033  e888aa1600           call 0x643ac0
// 004d9038  8b4608               mov eax, dword ptr [esi + 8]
// 004d903b  8a4e18               mov cl, byte ptr [esi + 0x18]
// 004d903e  884818               mov byte ptr [eax + 0x18], cl
// 004d9041  885e18               mov byte ptr [esi + 0x18], bl
// 004d9044  8b5008               mov edx, dword ptr [eax + 8]
// 004d9047  56                   push esi
// 004d9048  8bcd                 mov ecx, ebp
// 004d904a  885a18               mov byte ptr [edx + 0x18], bl
// 004d904d  e8eef51300           call 0x618640
// 004d9052  eb74                 jmp 0x4d90c8
// 004d9054  80781800             cmp byte ptr [eax + 0x18], 0
// 004d9058  7511                 jne 0x4d906b
// 004d905a  885818               mov byte ptr [eax + 0x18], bl
// 004d905d  56                   push esi
// 004d905e  8bcd                 mov ecx, ebp
// 004d9060  c6461800             mov byte ptr [esi + 0x18], 0
// 004d9064  e857aa1600           call 0x643ac0
// 004d9069  8b06                 mov eax, dword ptr [esi]
// 004d906b  80781900             cmp byte ptr [eax + 0x19], 0
// 004d906f  7513                 jne 0x4d9084
// 004d9071  8b4808               mov ecx, dword ptr [eax + 8]
// 004d9074  385918               cmp byte ptr [ecx + 0x18], bl
// 004d9077  751e                 jne 0x4d9097
// 004d9079  8b10                 mov edx, dword ptr [eax]
// 004d907b  385a18               cmp byte ptr [edx + 0x18], bl
// 004d907e  7517                 jne 0x4d9097
// 004d9080  c6401800             mov byte ptr [eax + 0x18], 0
// 004d9084  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004d9087  8bfe                 mov edi, esi
// 004d9089  8b7604               mov esi, dword ptr [esi + 4]
// 004d908c  3b7804               cmp edi, dword ptr [eax + 4]
// 004d908f  0f854bffffff         jne 0x4d8fe0
// 004d9095  eb31                 jmp 0x4d90c8
// 004d9097  8b08                 mov ecx, dword ptr [eax]
// 004d9099  385918               cmp byte ptr [ecx + 0x18], bl
// 004d909c  7514                 jne 0x4d90b2
// 004d909e  8b5008               mov edx, dword ptr [eax + 8]
// 004d90a1  885a18               mov byte ptr [edx + 0x18], bl
// 004d90a4  50                   push eax
// 004d90a5  8bcd                 mov ecx, ebp
// 004d90a7  c6401800             mov byte ptr [eax + 0x18], 0
// 004d90ab  e890f51300           call 0x618640
// 004d90b0  8b06                 mov eax, dword ptr [esi]
// 004d90b2  8a4e18               mov cl, byte ptr [esi + 0x18]
// 004d90b5  884818               mov byte ptr [eax + 0x18], cl
// 004d90b8  885e18               mov byte ptr [esi + 0x18], bl
// 004d90bb  8b10                 mov edx, dword ptr [eax]
// 004d90bd  56                   push esi
// 004d90be  8bcd                 mov ecx, ebp
// 004d90c0  885a18               mov byte ptr [edx + 0x18], bl
// 004d90c3  e8f8a91600           call 0x643ac0
// 004d90c8  885f18               mov byte ptr [edi + 0x18], bl
// 004d90cb  8b442410             mov eax, dword ptr [esp + 0x10]
// 004d90cf  50                   push eax
// 004d90d0  e85df92300           call 0x718a32
// 004d90d5  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 004d90d8  83c404               add esp, 4
// 004d90db  5f                   pop edi
// 004d90dc  5e                   pop esi
// 004d90dd  5b                   pop ebx
// 004d90de  85c0                 test eax, eax
// 004d90e0  7604                 jbe 0x4d90e6
// 004d90e2  48                   dec eax
// 004d90e3  89451c               mov dword ptr [ebp + 0x1c], eax
// 004d90e6  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 004d90ea  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 004d90ee  8b5500               mov edx, dword ptr [ebp]
// 004d90f1  894804               mov dword ptr [eax + 4], ecx
// 004d90f4  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004d90f8  8910                 mov dword ptr [eax], edx
// 004d90fa  5d                   pop ebp
// 004d90fb  64890d00000000       mov dword ptr fs:[0], ecx
// 004d9102  83c454               add esp, 0x54
// 004d9105  c20c00               ret 0xc
// standard library set<double> (function ?erase@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
