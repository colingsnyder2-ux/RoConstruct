// from server: 100% by auto
// roc 2009-06 00476bb0  unit: Ogre::RbxMeshLoader  size: 725 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00476bb0
//
// 00476bb0  64a100000000         mov eax, dword ptr fs:[0]
// 00476bb6  6aff                 push -1
// 00476bb8  68b2db8500           push 0x85dbb2
// 00476bbd  50                   push eax
// 00476bbe  64892500000000       mov dword ptr fs:[0], esp
// 00476bc5  8b442418             mov eax, dword ptr [esp + 0x18]
// 00476bc9  83ec48               sub esp, 0x48
// 00476bcc  80782900             cmp byte ptr [eax + 0x29], 0
// 00476bd0  55                   push ebp
// 00476bd1  8be9                 mov ebp, ecx
// 00476bd3  7459                 je 0x476c2e
// 00476bd5  68a4c98a00           push 0x8ac9a4
// 00476bda  8d4c240c             lea ecx, [esp + 0xc]
// 00476bde  ff15b4e48900         call dword ptr [0x89e4b4]
// 00476be4  8d4c2424             lea ecx, [esp + 0x24]
// 00476be8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00476bf0  ff15b8e98900         call dword ptr [0x89e9b8]
// 00476bf6  8d442408             lea eax, [esp + 8]
// 00476bfa  50                   push eax
// 00476bfb  8d4c2434             lea ecx, [esp + 0x34]
// 00476bff  c644245801           mov byte ptr [esp + 0x58], 1
// 00476c04  c744242844c98a00     mov dword ptr [esp + 0x28], 0x8ac944
// 00476c0c  ff15b8e48900         call dword ptr [0x89e4b8]
// 00476c12  68dc919700           push 0x9791dc
// 00476c17  8d4c2428             lea ecx, [esp + 0x28]
// 00476c1b  51                   push ecx
// 00476c1c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00476c21  c744242c5cc98a00     mov dword ptr [esp + 0x2c], 0x8ac95c
// 00476c29  e81c2e2a00           call 0x719a4a
// 00476c2e  53                   push ebx
// 00476c2f  56                   push esi
// 00476c30  8bd8                 mov ebx, eax
// 00476c32  57                   push edi
// 00476c33  8d4c246c             lea ecx, [esp + 0x6c]
// 00476c37  895c2410             mov dword ptr [esp + 0x10], ebx
// 00476c3b  e8300c0a00           call 0x517870
// 00476c40  8b0b                 mov ecx, dword ptr [ebx]
// 00476c42  80792900             cmp byte ptr [ecx + 0x29], 0
// 00476c46  7405                 je 0x476c4d
// 00476c48  8b7b08               mov edi, dword ptr [ebx + 8]
// 00476c4b  eb1b                 jmp 0x476c68
// 00476c4d  8b5308               mov edx, dword ptr [ebx + 8]
// 00476c50  807a2900             cmp byte ptr [edx + 0x29], 0
// 00476c54  7404                 je 0x476c5a
// 00476c56  8bf9                 mov edi, ecx
// 00476c58  eb0e                 jmp 0x476c68
// 00476c5a  8b442470             mov eax, dword ptr [esp + 0x70]
// 00476c5e  8b7808               mov edi, dword ptr [eax + 8]
// 00476c61  8d5008               lea edx, [eax + 8]
// 00476c64  3bc3                 cmp eax, ebx
// 00476c66  756b                 jne 0x476cd3
// 00476c68  807f2900             cmp byte ptr [edi + 0x29], 0
// 00476c6c  8b7304               mov esi, dword ptr [ebx + 4]
// 00476c6f  7503                 jne 0x476c74
// 00476c71  897704               mov dword ptr [edi + 4], esi
// 00476c74  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00476c77  395804               cmp dword ptr [eax + 4], ebx
// 00476c7a  7505                 jne 0x476c81
// 00476c7c  897804               mov dword ptr [eax + 4], edi
// 00476c7f  eb0b                 jmp 0x476c8c
// 00476c81  391e                 cmp dword ptr [esi], ebx
// 00476c83  7504                 jne 0x476c89
// 00476c85  893e                 mov dword ptr [esi], edi
// 00476c87  eb03                 jmp 0x476c8c
// 00476c89  897e08               mov dword ptr [esi + 8], edi
// 00476c8c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00476c8f  8b03                 mov eax, dword ptr [ebx]
// 00476c91  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00476c95  7515                 jne 0x476cac
// 00476c97  807f2900             cmp byte ptr [edi + 0x29], 0
// 00476c9b  7404                 je 0x476ca1
// 00476c9d  8bc6                 mov eax, esi
// 00476c9f  eb09                 jmp 0x476caa
// 00476ca1  57                   push edi
// 00476ca2  e829fe0900           call 0x516ad0
// 00476ca7  83c404               add esp, 4
// 00476caa  8903                 mov dword ptr [ebx], eax
// 00476cac  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00476caf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00476cb3  394b08               cmp dword ptr [ebx + 8], ecx
// 00476cb6  7577                 jne 0x476d2f
// 00476cb8  807f2900             cmp byte ptr [edi + 0x29], 0
// 00476cbc  7407                 je 0x476cc5
// 00476cbe  8bc6                 mov eax, esi
// 00476cc0  894308               mov dword ptr [ebx + 8], eax
// 00476cc3  eb6a                 jmp 0x476d2f
// 00476cc5  57                   push edi
// 00476cc6  e835b32600           call 0x6e2000
// 00476ccb  83c404               add esp, 4
// 00476cce  894308               mov dword ptr [ebx + 8], eax
// 00476cd1  eb5c                 jmp 0x476d2f
// 00476cd3  894104               mov dword ptr [ecx + 4], eax
// 00476cd6  8b0b                 mov ecx, dword ptr [ebx]
// 00476cd8  8908                 mov dword ptr [eax], ecx
// 00476cda  3b4308               cmp eax, dword ptr [ebx + 8]
// 00476cdd  7504                 jne 0x476ce3
// 00476cdf  8bf0                 mov esi, eax
// 00476ce1  eb19                 jmp 0x476cfc
// 00476ce3  807f2900             cmp byte ptr [edi + 0x29], 0
// 00476ce7  8b7004               mov esi, dword ptr [eax + 4]
// 00476cea  7503                 jne 0x476cef
// 00476cec  897704               mov dword ptr [edi + 4], esi
// 00476cef  893e                 mov dword ptr [esi], edi
// 00476cf1  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00476cf4  890a                 mov dword ptr [edx], ecx
// 00476cf6  8b5308               mov edx, dword ptr [ebx + 8]
// 00476cf9  894204               mov dword ptr [edx + 4], eax
// 00476cfc  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00476cff  395904               cmp dword ptr [ecx + 4], ebx
// 00476d02  7505                 jne 0x476d09
// 00476d04  894104               mov dword ptr [ecx + 4], eax
// 00476d07  eb0e                 jmp 0x476d17
// 00476d09  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00476d0c  3919                 cmp dword ptr [ecx], ebx
// 00476d0e  7504                 jne 0x476d14
// 00476d10  8901                 mov dword ptr [ecx], eax
// 00476d12  eb03                 jmp 0x476d17
// 00476d14  894108               mov dword ptr [ecx + 8], eax
// 00476d17  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00476d1a  894804               mov dword ptr [eax + 4], ecx
// 00476d1d  8d4b28               lea ecx, [ebx + 0x28]
// 00476d20  83c028               add eax, 0x28
// 00476d23  3bc1                 cmp eax, ecx
// 00476d25  7408                 je 0x476d2f
// 00476d27  8a19                 mov bl, byte ptr [ecx]
// 00476d29  8a10                 mov dl, byte ptr [eax]
// 00476d2b  8818                 mov byte ptr [eax], bl
// 00476d2d  8811                 mov byte ptr [ecx], dl
// 00476d2f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00476d33  b301                 mov bl, 1
// 00476d35  385a28               cmp byte ptr [edx + 0x28], bl
// 00476d38  0f85fd000000         jne 0x476e3b
// 00476d3e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00476d41  3b7804               cmp edi, dword ptr [eax + 4]
// 00476d44  0f84ee000000         je 0x476e38
// 00476d4a  8d9b00000000         lea ebx, [ebx]
// 00476d50  385f28               cmp byte ptr [edi + 0x28], bl
// 00476d53  0f85df000000         jne 0x476e38
// 00476d59  8b06                 mov eax, dword ptr [esi]
// 00476d5b  3bf8                 cmp edi, eax
// 00476d5d  7565                 jne 0x476dc4
// 00476d5f  8b4608               mov eax, dword ptr [esi + 8]
// 00476d62  80782800             cmp byte ptr [eax + 0x28], 0
// 00476d66  7512                 jne 0x476d7a
// 00476d68  885828               mov byte ptr [eax + 0x28], bl
// 00476d6b  56                   push esi
// 00476d6c  8bcd                 mov ecx, ebp
// 00476d6e  c6462800             mov byte ptr [esi + 0x28], 0
// 00476d72  e859b42600           call 0x6e21d0
// 00476d77  8b4608               mov eax, dword ptr [esi + 8]
// 00476d7a  80782900             cmp byte ptr [eax + 0x29], 0
// 00476d7e  7574                 jne 0x476df4
// 00476d80  8b08                 mov ecx, dword ptr [eax]
// 00476d82  385928               cmp byte ptr [ecx + 0x28], bl
// 00476d85  7508                 jne 0x476d8f
// 00476d87  8b5008               mov edx, dword ptr [eax + 8]
// 00476d8a  385a28               cmp byte ptr [edx + 0x28], bl
// 00476d8d  7461                 je 0x476df0
// 00476d8f  8b4808               mov ecx, dword ptr [eax + 8]
// 00476d92  385928               cmp byte ptr [ecx + 0x28], bl
// 00476d95  7514                 jne 0x476dab
// 00476d97  8b10                 mov edx, dword ptr [eax]
// 00476d99  885a28               mov byte ptr [edx + 0x28], bl
// 00476d9c  50                   push eax
// 00476d9d  8bcd                 mov ecx, ebp
// 00476d9f  c6402800             mov byte ptr [eax + 0x28], 0
// 00476da3  e848fc0900           call 0x5169f0
// 00476da8  8b4608               mov eax, dword ptr [esi + 8]
// 00476dab  8a4e28               mov cl, byte ptr [esi + 0x28]
// 00476dae  884828               mov byte ptr [eax + 0x28], cl
// 00476db1  885e28               mov byte ptr [esi + 0x28], bl
// 00476db4  8b5008               mov edx, dword ptr [eax + 8]
// 00476db7  56                   push esi
// 00476db8  8bcd                 mov ecx, ebp
// 00476dba  885a28               mov byte ptr [edx + 0x28], bl
// 00476dbd  e80eb42600           call 0x6e21d0
// 00476dc2  eb74                 jmp 0x476e38
// 00476dc4  80782800             cmp byte ptr [eax + 0x28], 0
// 00476dc8  7511                 jne 0x476ddb
// 00476dca  885828               mov byte ptr [eax + 0x28], bl
// 00476dcd  56                   push esi
// 00476dce  8bcd                 mov ecx, ebp
// 00476dd0  c6462800             mov byte ptr [esi + 0x28], 0
// 00476dd4  e817fc0900           call 0x5169f0
// 00476dd9  8b06                 mov eax, dword ptr [esi]
// 00476ddb  80782900             cmp byte ptr [eax + 0x29], 0
// 00476ddf  7513                 jne 0x476df4
// 00476de1  8b4808               mov ecx, dword ptr [eax + 8]
// 00476de4  385928               cmp byte ptr [ecx + 0x28], bl
// 00476de7  751e                 jne 0x476e07
// 00476de9  8b10                 mov edx, dword ptr [eax]
// 00476deb  385a28               cmp byte ptr [edx + 0x28], bl
// 00476dee  7517                 jne 0x476e07
// 00476df0  c6402800             mov byte ptr [eax + 0x28], 0
// 00476df4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00476df7  8bfe                 mov edi, esi
// 00476df9  8b7604               mov esi, dword ptr [esi + 4]
// 00476dfc  3b7804               cmp edi, dword ptr [eax + 4]
// 00476dff  0f854bffffff         jne 0x476d50
// 00476e05  eb31                 jmp 0x476e38
// 00476e07  8b08                 mov ecx, dword ptr [eax]
// 00476e09  385928               cmp byte ptr [ecx + 0x28], bl
// 00476e0c  7514                 jne 0x476e22
// 00476e0e  8b5008               mov edx, dword ptr [eax + 8]
// 00476e11  885a28               mov byte ptr [edx + 0x28], bl
// 00476e14  50                   push eax
// 00476e15  8bcd                 mov ecx, ebp
// 00476e17  c6402800             mov byte ptr [eax + 0x28], 0
// 00476e1b  e8b0b32600           call 0x6e21d0
// 00476e20  8b06                 mov eax, dword ptr [esi]
// 00476e22  8a4e28               mov cl, byte ptr [esi + 0x28]
// 00476e25  884828               mov byte ptr [eax + 0x28], cl
// 00476e28  885e28               mov byte ptr [esi + 0x28], bl
// 00476e2b  8b10                 mov edx, dword ptr [eax]
// 00476e2d  56                   push esi
// 00476e2e  8bcd                 mov ecx, ebp
// 00476e30  885a28               mov byte ptr [edx + 0x28], bl
// 00476e33  e8b8fb0900           call 0x5169f0
// 00476e38  885f28               mov byte ptr [edi + 0x28], bl
// 00476e3b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00476e3f  83c10c               add ecx, 0xc
// 00476e42  ff15c4e48900         call dword ptr [0x89e4c4]
// 00476e48  8b442410             mov eax, dword ptr [esp + 0x10]
// 00476e4c  50                   push eax
// 00476e4d  e8e01b2a00           call 0x718a32
// 00476e52  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00476e55  83c404               add esp, 4
// 00476e58  5f                   pop edi
// 00476e59  5e                   pop esi
// 00476e5a  5b                   pop ebx
// 00476e5b  85c0                 test eax, eax
// 00476e5d  7604                 jbe 0x476e63
// 00476e5f  48                   dec eax
// 00476e60  89451c               mov dword ptr [ebp + 0x1c], eax
// 00476e63  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00476e67  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00476e6b  8b5500               mov edx, dword ptr [ebp]
// 00476e6e  894804               mov dword ptr [eax + 4], ecx
// 00476e71  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00476e75  8910                 mov dword ptr [eax], edx
// 00476e77  5d                   pop ebp
// 00476e78  64890d00000000       mov dword ptr fs:[0], ecx
// 00476e7f  83c454               add esp, 0x54
// 00476e82  c20c00               ret 0xc
// standard library set<string> (function ?erase@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
