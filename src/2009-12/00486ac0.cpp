// from server: 100% by auto
// roc 2009-12 00486ac0  unit: Ogre::GfxClustererPart  size: 725 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00486ac0
//
// 00486ac0  64a100000000         mov eax, dword ptr fs:[0]
// 00486ac6  6aff                 push -1
// 00486ac8  6812699500           push 0x956912
// 00486acd  50                   push eax
// 00486ace  64892500000000       mov dword ptr fs:[0], esp
// 00486ad5  8b442418             mov eax, dword ptr [esp + 0x18]
// 00486ad9  83ec48               sub esp, 0x48
// 00486adc  80782900             cmp byte ptr [eax + 0x29], 0
// 00486ae0  55                   push ebp
// 00486ae1  8be9                 mov ebp, ecx
// 00486ae3  7459                 je 0x486b3e
// 00486ae5  68e4f49900           push 0x99f4e4
// 00486aea  8d4c240c             lea ecx, [esp + 0xc]
// 00486aee  ff15f4b69800         call dword ptr [0x98b6f4]
// 00486af4  8d4c2424             lea ecx, [esp + 0x24]
// 00486af8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00486b00  ff1554b79800         call dword ptr [0x98b754]
// 00486b06  8d442408             lea eax, [esp + 8]
// 00486b0a  50                   push eax
// 00486b0b  8d4c2434             lea ecx, [esp + 0x34]
// 00486b0f  c644245801           mov byte ptr [esp + 0x58], 1
// 00486b14  c744242884f49900     mov dword ptr [esp + 0x28], 0x99f484
// 00486b1c  ff15f0b69800         call dword ptr [0x98b6f0]
// 00486b22  688cefa800           push 0xa8ef8c
// 00486b27  8d4c2428             lea ecx, [esp + 0x28]
// 00486b2b  51                   push ecx
// 00486b2c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00486b31  c744242c9cf49900     mov dword ptr [esp + 0x2c], 0x99f49c
// 00486b39  e83add3600           call 0x7f4878
// 00486b3e  53                   push ebx
// 00486b3f  56                   push esi
// 00486b40  8bd8                 mov ebx, eax
// 00486b42  57                   push edi
// 00486b43  8d4c246c             lea ecx, [esp + 0x6c]
// 00486b47  895c2410             mov dword ptr [esp + 0x10], ebx
// 00486b4b  e810671400           call 0x5cd260
// 00486b50  8b0b                 mov ecx, dword ptr [ebx]
// 00486b52  80792900             cmp byte ptr [ecx + 0x29], 0
// 00486b56  7405                 je 0x486b5d
// 00486b58  8b7b08               mov edi, dword ptr [ebx + 8]
// 00486b5b  eb1b                 jmp 0x486b78
// 00486b5d  8b5308               mov edx, dword ptr [ebx + 8]
// 00486b60  807a2900             cmp byte ptr [edx + 0x29], 0
// 00486b64  7404                 je 0x486b6a
// 00486b66  8bf9                 mov edi, ecx
// 00486b68  eb0e                 jmp 0x486b78
// 00486b6a  8b442470             mov eax, dword ptr [esp + 0x70]
// 00486b6e  8b7808               mov edi, dword ptr [eax + 8]
// 00486b71  8d5008               lea edx, [eax + 8]
// 00486b74  3bc3                 cmp eax, ebx
// 00486b76  756b                 jne 0x486be3
// 00486b78  807f2900             cmp byte ptr [edi + 0x29], 0
// 00486b7c  8b7304               mov esi, dword ptr [ebx + 4]
// 00486b7f  7503                 jne 0x486b84
// 00486b81  897704               mov dword ptr [edi + 4], esi
// 00486b84  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00486b87  395804               cmp dword ptr [eax + 4], ebx
// 00486b8a  7505                 jne 0x486b91
// 00486b8c  897804               mov dword ptr [eax + 4], edi
// 00486b8f  eb0b                 jmp 0x486b9c
// 00486b91  391e                 cmp dword ptr [esi], ebx
// 00486b93  7504                 jne 0x486b99
// 00486b95  893e                 mov dword ptr [esi], edi
// 00486b97  eb03                 jmp 0x486b9c
// 00486b99  897e08               mov dword ptr [esi + 8], edi
// 00486b9c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00486b9f  8b03                 mov eax, dword ptr [ebx]
// 00486ba1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00486ba5  7515                 jne 0x486bbc
// 00486ba7  807f2900             cmp byte ptr [edi + 0x29], 0
// 00486bab  7404                 je 0x486bb1
// 00486bad  8bc6                 mov eax, esi
// 00486baf  eb09                 jmp 0x486bba
// 00486bb1  57                   push edi
// 00486bb2  e8c95a1400           call 0x5cc680
// 00486bb7  83c404               add esp, 4
// 00486bba  8903                 mov dword ptr [ebx], eax
// 00486bbc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00486bbf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00486bc3  394b08               cmp dword ptr [ebx + 8], ecx
// 00486bc6  7577                 jne 0x486c3f
// 00486bc8  807f2900             cmp byte ptr [edi + 0x29], 0
// 00486bcc  7407                 je 0x486bd5
// 00486bce  8bc6                 mov eax, esi
// 00486bd0  894308               mov dword ptr [ebx + 8], eax
// 00486bd3  eb6a                 jmp 0x486c3f
// 00486bd5  57                   push edi
// 00486bd6  e8855a1400           call 0x5cc660
// 00486bdb  83c404               add esp, 4
// 00486bde  894308               mov dword ptr [ebx + 8], eax
// 00486be1  eb5c                 jmp 0x486c3f
// 00486be3  894104               mov dword ptr [ecx + 4], eax
// 00486be6  8b0b                 mov ecx, dword ptr [ebx]
// 00486be8  8908                 mov dword ptr [eax], ecx
// 00486bea  3b4308               cmp eax, dword ptr [ebx + 8]
// 00486bed  7504                 jne 0x486bf3
// 00486bef  8bf0                 mov esi, eax
// 00486bf1  eb19                 jmp 0x486c0c
// 00486bf3  807f2900             cmp byte ptr [edi + 0x29], 0
// 00486bf7  8b7004               mov esi, dword ptr [eax + 4]
// 00486bfa  7503                 jne 0x486bff
// 00486bfc  897704               mov dword ptr [edi + 4], esi
// 00486bff  893e                 mov dword ptr [esi], edi
// 00486c01  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00486c04  890a                 mov dword ptr [edx], ecx
// 00486c06  8b5308               mov edx, dword ptr [ebx + 8]
// 00486c09  894204               mov dword ptr [edx + 4], eax
// 00486c0c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00486c0f  395904               cmp dword ptr [ecx + 4], ebx
// 00486c12  7505                 jne 0x486c19
// 00486c14  894104               mov dword ptr [ecx + 4], eax
// 00486c17  eb0e                 jmp 0x486c27
// 00486c19  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00486c1c  3919                 cmp dword ptr [ecx], ebx
// 00486c1e  7504                 jne 0x486c24
// 00486c20  8901                 mov dword ptr [ecx], eax
// 00486c22  eb03                 jmp 0x486c27
// 00486c24  894108               mov dword ptr [ecx + 8], eax
// 00486c27  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00486c2a  894804               mov dword ptr [eax + 4], ecx
// 00486c2d  8d4b28               lea ecx, [ebx + 0x28]
// 00486c30  83c028               add eax, 0x28
// 00486c33  3bc1                 cmp eax, ecx
// 00486c35  7408                 je 0x486c3f
// 00486c37  8a19                 mov bl, byte ptr [ecx]
// 00486c39  8a10                 mov dl, byte ptr [eax]
// 00486c3b  8818                 mov byte ptr [eax], bl
// 00486c3d  8811                 mov byte ptr [ecx], dl
// 00486c3f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00486c43  b301                 mov bl, 1
// 00486c45  385a28               cmp byte ptr [edx + 0x28], bl
// 00486c48  0f85fd000000         jne 0x486d4b
// 00486c4e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00486c51  3b7804               cmp edi, dword ptr [eax + 4]
// 00486c54  0f84ee000000         je 0x486d48
// 00486c5a  8d9b00000000         lea ebx, [ebx]
// 00486c60  385f28               cmp byte ptr [edi + 0x28], bl
// 00486c63  0f85df000000         jne 0x486d48
// 00486c69  8b06                 mov eax, dword ptr [esi]
// 00486c6b  3bf8                 cmp edi, eax
// 00486c6d  7565                 jne 0x486cd4
// 00486c6f  8b4608               mov eax, dword ptr [esi + 8]
// 00486c72  80782800             cmp byte ptr [eax + 0x28], 0
// 00486c76  7512                 jne 0x486c8a
// 00486c78  885828               mov byte ptr [eax + 0x28], bl
// 00486c7b  56                   push esi
// 00486c7c  8bcd                 mov ecx, ebp
// 00486c7e  c6462800             mov byte ptr [esi + 0x28], 0
// 00486c82  e8f9641400           call 0x5cd180
// 00486c87  8b4608               mov eax, dword ptr [esi + 8]
// 00486c8a  80782900             cmp byte ptr [eax + 0x29], 0
// 00486c8e  7574                 jne 0x486d04
// 00486c90  8b08                 mov ecx, dword ptr [eax]
// 00486c92  385928               cmp byte ptr [ecx + 0x28], bl
// 00486c95  7508                 jne 0x486c9f
// 00486c97  8b5008               mov edx, dword ptr [eax + 8]
// 00486c9a  385a28               cmp byte ptr [edx + 0x28], bl
// 00486c9d  7461                 je 0x486d00
// 00486c9f  8b4808               mov ecx, dword ptr [eax + 8]
// 00486ca2  385928               cmp byte ptr [ecx + 0x28], bl
// 00486ca5  7514                 jne 0x486cbb
// 00486ca7  8b10                 mov edx, dword ptr [eax]
// 00486ca9  885a28               mov byte ptr [edx + 0x28], bl
// 00486cac  50                   push eax
// 00486cad  8bcd                 mov ecx, ebp
// 00486caf  c6402800             mov byte ptr [eax + 0x28], 0
// 00486cb3  e828591400           call 0x5cc5e0
// 00486cb8  8b4608               mov eax, dword ptr [esi + 8]
// 00486cbb  8a4e28               mov cl, byte ptr [esi + 0x28]
// 00486cbe  884828               mov byte ptr [eax + 0x28], cl
// 00486cc1  885e28               mov byte ptr [esi + 0x28], bl
// 00486cc4  8b5008               mov edx, dword ptr [eax + 8]
// 00486cc7  56                   push esi
// 00486cc8  8bcd                 mov ecx, ebp
// 00486cca  885a28               mov byte ptr [edx + 0x28], bl
// 00486ccd  e8ae641400           call 0x5cd180
// 00486cd2  eb74                 jmp 0x486d48
// 00486cd4  80782800             cmp byte ptr [eax + 0x28], 0
// 00486cd8  7511                 jne 0x486ceb
// 00486cda  885828               mov byte ptr [eax + 0x28], bl
// 00486cdd  56                   push esi
// 00486cde  8bcd                 mov ecx, ebp
// 00486ce0  c6462800             mov byte ptr [esi + 0x28], 0
// 00486ce4  e8f7581400           call 0x5cc5e0
// 00486ce9  8b06                 mov eax, dword ptr [esi]
// 00486ceb  80782900             cmp byte ptr [eax + 0x29], 0
// 00486cef  7513                 jne 0x486d04
// 00486cf1  8b4808               mov ecx, dword ptr [eax + 8]
// 00486cf4  385928               cmp byte ptr [ecx + 0x28], bl
// 00486cf7  751e                 jne 0x486d17
// 00486cf9  8b10                 mov edx, dword ptr [eax]
// 00486cfb  385a28               cmp byte ptr [edx + 0x28], bl
// 00486cfe  7517                 jne 0x486d17
// 00486d00  c6402800             mov byte ptr [eax + 0x28], 0
// 00486d04  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00486d07  8bfe                 mov edi, esi
// 00486d09  8b7604               mov esi, dword ptr [esi + 4]
// 00486d0c  3b7804               cmp edi, dword ptr [eax + 4]
// 00486d0f  0f854bffffff         jne 0x486c60
// 00486d15  eb31                 jmp 0x486d48
// 00486d17  8b08                 mov ecx, dword ptr [eax]
// 00486d19  385928               cmp byte ptr [ecx + 0x28], bl
// 00486d1c  7514                 jne 0x486d32
// 00486d1e  8b5008               mov edx, dword ptr [eax + 8]
// 00486d21  885a28               mov byte ptr [edx + 0x28], bl
// 00486d24  50                   push eax
// 00486d25  8bcd                 mov ecx, ebp
// 00486d27  c6402800             mov byte ptr [eax + 0x28], 0
// 00486d2b  e850641400           call 0x5cd180
// 00486d30  8b06                 mov eax, dword ptr [esi]
// 00486d32  8a4e28               mov cl, byte ptr [esi + 0x28]
// 00486d35  884828               mov byte ptr [eax + 0x28], cl
// 00486d38  885e28               mov byte ptr [esi + 0x28], bl
// 00486d3b  8b10                 mov edx, dword ptr [eax]
// 00486d3d  56                   push esi
// 00486d3e  8bcd                 mov ecx, ebp
// 00486d40  885a28               mov byte ptr [edx + 0x28], bl
// 00486d43  e898581400           call 0x5cc5e0
// 00486d48  885f28               mov byte ptr [edi + 0x28], bl
// 00486d4b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00486d4f  83c10c               add ecx, 0xc
// 00486d52  ff15e4b69800         call dword ptr [0x98b6e4]
// 00486d58  8b442410             mov eax, dword ptr [esp + 0x10]
// 00486d5c  50                   push eax
// 00486d5d  e8f8ca3600           call 0x7f385a
// 00486d62  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00486d65  83c404               add esp, 4
// 00486d68  5f                   pop edi
// 00486d69  5e                   pop esi
// 00486d6a  5b                   pop ebx
// 00486d6b  85c0                 test eax, eax
// 00486d6d  7604                 jbe 0x486d73
// 00486d6f  48                   dec eax
// 00486d70  89451c               mov dword ptr [ebp + 0x1c], eax
// 00486d73  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00486d77  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00486d7b  8b5500               mov edx, dword ptr [ebp]
// 00486d7e  894804               mov dword ptr [eax + 4], ecx
// 00486d81  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00486d85  8910                 mov dword ptr [eax], edx
// 00486d87  5d                   pop ebp
// 00486d88  64890d00000000       mov dword ptr fs:[0], ecx
// 00486d8f  83c454               add esp, 0x54
// 00486d92  c20c00               ret 0xc
// standard library set<string> (function ?erase@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
