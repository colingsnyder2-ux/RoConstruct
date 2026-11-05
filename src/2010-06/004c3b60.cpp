// from server: 100% by auto
// roc 2010-06 004c3b60  unit: RBX::VInstance::?$NonFactoryProduct  size: 725 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004c3b60
//
// 004c3b60  64a100000000         mov eax, dword ptr fs:[0]
// 004c3b66  6aff                 push -1
// 004c3b68  68e22f9a00           push 0x9a2fe2
// 004c3b6d  50                   push eax
// 004c3b6e  64892500000000       mov dword ptr fs:[0], esp
// 004c3b75  8b442418             mov eax, dword ptr [esp + 0x18]
// 004c3b79  83ec48               sub esp, 0x48
// 004c3b7c  80782900             cmp byte ptr [eax + 0x29], 0
// 004c3b80  55                   push ebp
// 004c3b81  8be9                 mov ebp, ecx
// 004c3b83  7459                 je 0x4c3bde
// 004c3b85  688c00a000           push 0xa0008c
// 004c3b8a  8d4c240c             lea ecx, [esp + 0xc]
// 004c3b8e  ff1510a49e00         call dword ptr [0x9ea410]
// 004c3b94  8d4c2424             lea ecx, [esp + 0x24]
// 004c3b98  c744245400000000     mov dword ptr [esp + 0x54], 0
// 004c3ba0  ff1518a99e00         call dword ptr [0x9ea918]
// 004c3ba6  8d442408             lea eax, [esp + 8]
// 004c3baa  50                   push eax
// 004c3bab  8d4c2434             lea ecx, [esp + 0x34]
// 004c3baf  c644245801           mov byte ptr [esp + 0x58], 1
// 004c3bb4  c74424282c00a000     mov dword ptr [esp + 0x28], 0xa0002c
// 004c3bbc  ff150ca49e00         call dword ptr [0x9ea40c]
// 004c3bc2  68081bb000           push 0xb01b08
// 004c3bc7  8d4c2428             lea ecx, [esp + 0x28]
// 004c3bcb  51                   push ecx
// 004c3bcc  c644245c00           mov byte ptr [esp + 0x5c], 0
// 004c3bd1  c744242c4400a000     mov dword ptr [esp + 0x2c], 0xa00044
// 004c3bd9  e8d44d2e00           call 0x7a89b2
// 004c3bde  53                   push ebx
// 004c3bdf  56                   push esi
// 004c3be0  8bd8                 mov ebx, eax
// 004c3be2  57                   push edi
// 004c3be3  8d4c246c             lea ecx, [esp + 0x6c]
// 004c3be7  895c2410             mov dword ptr [esp + 0x10], ebx
// 004c3beb  e8c0b92a00           call 0x76f5b0
// 004c3bf0  8b0b                 mov ecx, dword ptr [ebx]
// 004c3bf2  80792900             cmp byte ptr [ecx + 0x29], 0
// 004c3bf6  7405                 je 0x4c3bfd
// 004c3bf8  8b7b08               mov edi, dword ptr [ebx + 8]
// 004c3bfb  eb1b                 jmp 0x4c3c18
// 004c3bfd  8b5308               mov edx, dword ptr [ebx + 8]
// 004c3c00  807a2900             cmp byte ptr [edx + 0x29], 0
// 004c3c04  7404                 je 0x4c3c0a
// 004c3c06  8bf9                 mov edi, ecx
// 004c3c08  eb0e                 jmp 0x4c3c18
// 004c3c0a  8b442470             mov eax, dword ptr [esp + 0x70]
// 004c3c0e  8b7808               mov edi, dword ptr [eax + 8]
// 004c3c11  8d5008               lea edx, [eax + 8]
// 004c3c14  3bc3                 cmp eax, ebx
// 004c3c16  756b                 jne 0x4c3c83
// 004c3c18  807f2900             cmp byte ptr [edi + 0x29], 0
// 004c3c1c  8b7304               mov esi, dword ptr [ebx + 4]
// 004c3c1f  7503                 jne 0x4c3c24
// 004c3c21  897704               mov dword ptr [edi + 4], esi
// 004c3c24  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004c3c27  395804               cmp dword ptr [eax + 4], ebx
// 004c3c2a  7505                 jne 0x4c3c31
// 004c3c2c  897804               mov dword ptr [eax + 4], edi
// 004c3c2f  eb0b                 jmp 0x4c3c3c
// 004c3c31  391e                 cmp dword ptr [esi], ebx
// 004c3c33  7504                 jne 0x4c3c39
// 004c3c35  893e                 mov dword ptr [esi], edi
// 004c3c37  eb03                 jmp 0x4c3c3c
// 004c3c39  897e08               mov dword ptr [esi + 8], edi
// 004c3c3c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 004c3c3f  8b03                 mov eax, dword ptr [ebx]
// 004c3c41  3b442410             cmp eax, dword ptr [esp + 0x10]
// 004c3c45  7515                 jne 0x4c3c5c
// 004c3c47  807f2900             cmp byte ptr [edi + 0x29], 0
// 004c3c4b  7404                 je 0x4c3c51
// 004c3c4d  8bc6                 mov eax, esi
// 004c3c4f  eb09                 jmp 0x4c3c5a
// 004c3c51  57                   push edi
// 004c3c52  e8d92e0600           call 0x526b30
// 004c3c57  83c404               add esp, 4
// 004c3c5a  8903                 mov dword ptr [ebx], eax
// 004c3c5c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 004c3c5f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c3c63  394b08               cmp dword ptr [ebx + 8], ecx
// 004c3c66  7577                 jne 0x4c3cdf
// 004c3c68  807f2900             cmp byte ptr [edi + 0x29], 0
// 004c3c6c  7407                 je 0x4c3c75
// 004c3c6e  8bc6                 mov eax, esi
// 004c3c70  894308               mov dword ptr [ebx + 8], eax
// 004c3c73  eb6a                 jmp 0x4c3cdf
// 004c3c75  57                   push edi
// 004c3c76  e815890600           call 0x52c590
// 004c3c7b  83c404               add esp, 4
// 004c3c7e  894308               mov dword ptr [ebx + 8], eax
// 004c3c81  eb5c                 jmp 0x4c3cdf
// 004c3c83  894104               mov dword ptr [ecx + 4], eax
// 004c3c86  8b0b                 mov ecx, dword ptr [ebx]
// 004c3c88  8908                 mov dword ptr [eax], ecx
// 004c3c8a  3b4308               cmp eax, dword ptr [ebx + 8]
// 004c3c8d  7504                 jne 0x4c3c93
// 004c3c8f  8bf0                 mov esi, eax
// 004c3c91  eb19                 jmp 0x4c3cac
// 004c3c93  807f2900             cmp byte ptr [edi + 0x29], 0
// 004c3c97  8b7004               mov esi, dword ptr [eax + 4]
// 004c3c9a  7503                 jne 0x4c3c9f
// 004c3c9c  897704               mov dword ptr [edi + 4], esi
// 004c3c9f  893e                 mov dword ptr [esi], edi
// 004c3ca1  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004c3ca4  890a                 mov dword ptr [edx], ecx
// 004c3ca6  8b5308               mov edx, dword ptr [ebx + 8]
// 004c3ca9  894204               mov dword ptr [edx + 4], eax
// 004c3cac  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 004c3caf  395904               cmp dword ptr [ecx + 4], ebx
// 004c3cb2  7505                 jne 0x4c3cb9
// 004c3cb4  894104               mov dword ptr [ecx + 4], eax
// 004c3cb7  eb0e                 jmp 0x4c3cc7
// 004c3cb9  8b4b04               mov ecx, dword ptr [ebx + 4]
// 004c3cbc  3919                 cmp dword ptr [ecx], ebx
// 004c3cbe  7504                 jne 0x4c3cc4
// 004c3cc0  8901                 mov dword ptr [ecx], eax
// 004c3cc2  eb03                 jmp 0x4c3cc7
// 004c3cc4  894108               mov dword ptr [ecx + 8], eax
// 004c3cc7  8b4b04               mov ecx, dword ptr [ebx + 4]
// 004c3cca  894804               mov dword ptr [eax + 4], ecx
// 004c3ccd  8d4b28               lea ecx, [ebx + 0x28]
// 004c3cd0  83c028               add eax, 0x28
// 004c3cd3  3bc1                 cmp eax, ecx
// 004c3cd5  7408                 je 0x4c3cdf
// 004c3cd7  8a19                 mov bl, byte ptr [ecx]
// 004c3cd9  8a10                 mov dl, byte ptr [eax]
// 004c3cdb  8818                 mov byte ptr [eax], bl
// 004c3cdd  8811                 mov byte ptr [ecx], dl
// 004c3cdf  8b542410             mov edx, dword ptr [esp + 0x10]
// 004c3ce3  b301                 mov bl, 1
// 004c3ce5  385a28               cmp byte ptr [edx + 0x28], bl
// 004c3ce8  0f85fd000000         jne 0x4c3deb
// 004c3cee  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004c3cf1  3b7804               cmp edi, dword ptr [eax + 4]
// 004c3cf4  0f84ee000000         je 0x4c3de8
// 004c3cfa  8d9b00000000         lea ebx, [ebx]
// 004c3d00  385f28               cmp byte ptr [edi + 0x28], bl
// 004c3d03  0f85df000000         jne 0x4c3de8
// 004c3d09  8b06                 mov eax, dword ptr [esi]
// 004c3d0b  3bf8                 cmp edi, eax
// 004c3d0d  7565                 jne 0x4c3d74
// 004c3d0f  8b4608               mov eax, dword ptr [esi + 8]
// 004c3d12  80782800             cmp byte ptr [eax + 0x28], 0
// 004c3d16  7512                 jne 0x4c3d2a
// 004c3d18  885828               mov byte ptr [eax + 0x28], bl
// 004c3d1b  56                   push esi
// 004c3d1c  8bcd                 mov ecx, ebp
// 004c3d1e  c6462800             mov byte ptr [esi + 0x28], 0
// 004c3d22  e8a9320600           call 0x526fd0
// 004c3d27  8b4608               mov eax, dword ptr [esi + 8]
// 004c3d2a  80782900             cmp byte ptr [eax + 0x29], 0
// 004c3d2e  7574                 jne 0x4c3da4
// 004c3d30  8b08                 mov ecx, dword ptr [eax]
// 004c3d32  385928               cmp byte ptr [ecx + 0x28], bl
// 004c3d35  7508                 jne 0x4c3d3f
// 004c3d37  8b5008               mov edx, dword ptr [eax + 8]
// 004c3d3a  385a28               cmp byte ptr [edx + 0x28], bl
// 004c3d3d  7461                 je 0x4c3da0
// 004c3d3f  8b4808               mov ecx, dword ptr [eax + 8]
// 004c3d42  385928               cmp byte ptr [ecx + 0x28], bl
// 004c3d45  7514                 jne 0x4c3d5b
// 004c3d47  8b10                 mov edx, dword ptr [eax]
// 004c3d49  885a28               mov byte ptr [edx + 0x28], bl
// 004c3d4c  50                   push eax
// 004c3d4d  8bcd                 mov ecx, ebp
// 004c3d4f  c6402800             mov byte ptr [eax + 0x28], 0
// 004c3d53  e818320600           call 0x526f70
// 004c3d58  8b4608               mov eax, dword ptr [esi + 8]
// 004c3d5b  8a4e28               mov cl, byte ptr [esi + 0x28]
// 004c3d5e  884828               mov byte ptr [eax + 0x28], cl
// 004c3d61  885e28               mov byte ptr [esi + 0x28], bl
// 004c3d64  8b5008               mov edx, dword ptr [eax + 8]
// 004c3d67  56                   push esi
// 004c3d68  8bcd                 mov ecx, ebp
// 004c3d6a  885a28               mov byte ptr [edx + 0x28], bl
// 004c3d6d  e85e320600           call 0x526fd0
// 004c3d72  eb74                 jmp 0x4c3de8
// 004c3d74  80782800             cmp byte ptr [eax + 0x28], 0
// 004c3d78  7511                 jne 0x4c3d8b
// 004c3d7a  885828               mov byte ptr [eax + 0x28], bl
// 004c3d7d  56                   push esi
// 004c3d7e  8bcd                 mov ecx, ebp
// 004c3d80  c6462800             mov byte ptr [esi + 0x28], 0
// 004c3d84  e8e7310600           call 0x526f70
// 004c3d89  8b06                 mov eax, dword ptr [esi]
// 004c3d8b  80782900             cmp byte ptr [eax + 0x29], 0
// 004c3d8f  7513                 jne 0x4c3da4
// 004c3d91  8b4808               mov ecx, dword ptr [eax + 8]
// 004c3d94  385928               cmp byte ptr [ecx + 0x28], bl
// 004c3d97  751e                 jne 0x4c3db7
// 004c3d99  8b10                 mov edx, dword ptr [eax]
// 004c3d9b  385a28               cmp byte ptr [edx + 0x28], bl
// 004c3d9e  7517                 jne 0x4c3db7
// 004c3da0  c6402800             mov byte ptr [eax + 0x28], 0
// 004c3da4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004c3da7  8bfe                 mov edi, esi
// 004c3da9  8b7604               mov esi, dword ptr [esi + 4]
// 004c3dac  3b7804               cmp edi, dword ptr [eax + 4]
// 004c3daf  0f854bffffff         jne 0x4c3d00
// 004c3db5  eb31                 jmp 0x4c3de8
// 004c3db7  8b08                 mov ecx, dword ptr [eax]
// 004c3db9  385928               cmp byte ptr [ecx + 0x28], bl
// 004c3dbc  7514                 jne 0x4c3dd2
// 004c3dbe  8b5008               mov edx, dword ptr [eax + 8]
// 004c3dc1  885a28               mov byte ptr [edx + 0x28], bl
// 004c3dc4  50                   push eax
// 004c3dc5  8bcd                 mov ecx, ebp
// 004c3dc7  c6402800             mov byte ptr [eax + 0x28], 0
// 004c3dcb  e800320600           call 0x526fd0
// 004c3dd0  8b06                 mov eax, dword ptr [esi]
// 004c3dd2  8a4e28               mov cl, byte ptr [esi + 0x28]
// 004c3dd5  884828               mov byte ptr [eax + 0x28], cl
// 004c3dd8  885e28               mov byte ptr [esi + 0x28], bl
// 004c3ddb  8b10                 mov edx, dword ptr [eax]
// 004c3ddd  56                   push esi
// 004c3dde  8bcd                 mov ecx, ebp
// 004c3de0  885a28               mov byte ptr [edx + 0x28], bl
// 004c3de3  e888310600           call 0x526f70
// 004c3de8  885f28               mov byte ptr [edi + 0x28], bl
// 004c3deb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c3def  83c10c               add ecx, 0xc
// 004c3df2  ff1500a49e00         call dword ptr [0x9ea400]
// 004c3df8  8b442410             mov eax, dword ptr [esp + 0x10]
// 004c3dfc  50                   push eax
// 004c3dfd  e8983b2e00           call 0x7a799a
// 004c3e02  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 004c3e05  83c404               add esp, 4
// 004c3e08  5f                   pop edi
// 004c3e09  5e                   pop esi
// 004c3e0a  5b                   pop ebx
// 004c3e0b  85c0                 test eax, eax
// 004c3e0d  7604                 jbe 0x4c3e13
// 004c3e0f  48                   dec eax
// 004c3e10  89451c               mov dword ptr [ebp + 0x1c], eax
// 004c3e13  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 004c3e17  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 004c3e1b  8b5500               mov edx, dword ptr [ebp]
// 004c3e1e  894804               mov dword ptr [eax + 4], ecx
// 004c3e21  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004c3e25  8910                 mov dword ptr [eax], edx
// 004c3e27  5d                   pop ebp
// 004c3e28  64890d00000000       mov dword ptr fs:[0], ecx
// 004c3e2f  83c454               add esp, 0x54
// 004c3e32  c20c00               ret 0xc
// standard library set<string> (function ?erase@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
