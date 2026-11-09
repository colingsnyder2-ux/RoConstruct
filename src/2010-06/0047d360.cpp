// from server: 100% by auto
// roc 2010-06 0047d360  unit: VCContent::?$CComObject  size: 725 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0047d360
//
// 0047d360  64a100000000         mov eax, dword ptr fs:[0]
// 0047d366  6aff                 push -1
// 0047d368  68e22f9a00           push 0x9a2fe2
// 0047d36d  50                   push eax
// 0047d36e  64892500000000       mov dword ptr fs:[0], esp
// 0047d375  8b442418             mov eax, dword ptr [esp + 0x18]
// 0047d379  83ec48               sub esp, 0x48
// 0047d37c  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0047d380  55                   push ebp
// 0047d381  8be9                 mov ebp, ecx
// 0047d383  7459                 je 0x47d3de
// 0047d385  688c00a000           push 0xa0008c
// 0047d38a  8d4c240c             lea ecx, [esp + 0xc]
// 0047d38e  ff1510a49e00         call dword ptr [0x9ea410]
// 0047d394  8d4c2424             lea ecx, [esp + 0x24]
// 0047d398  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0047d3a0  ff1518a99e00         call dword ptr [0x9ea918]
// 0047d3a6  8d442408             lea eax, [esp + 8]
// 0047d3aa  50                   push eax
// 0047d3ab  8d4c2434             lea ecx, [esp + 0x34]
// 0047d3af  c644245801           mov byte ptr [esp + 0x58], 1
// 0047d3b4  c74424282c00a000     mov dword ptr [esp + 0x28], 0xa0002c
// 0047d3bc  ff150ca49e00         call dword ptr [0x9ea40c]
// 0047d3c2  68081bb000           push 0xb01b08
// 0047d3c7  8d4c2428             lea ecx, [esp + 0x28]
// 0047d3cb  51                   push ecx
// 0047d3cc  c644245c00           mov byte ptr [esp + 0x5c], 0
// 0047d3d1  c744242c4400a000     mov dword ptr [esp + 0x2c], 0xa00044
// 0047d3d9  e8d4b53200           call 0x7a89b2
// 0047d3de  53                   push ebx
// 0047d3df  56                   push esi
// 0047d3e0  8bd8                 mov ebx, eax
// 0047d3e2  57                   push edi
// 0047d3e3  8d4c246c             lea ecx, [esp + 0x6c]
// 0047d3e7  895c2410             mov dword ptr [esp + 0x10], ebx
// 0047d3eb  e8508e4400           call 0x8c6240
// 0047d3f0  8b0b                 mov ecx, dword ptr [ebx]
// 0047d3f2  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 0047d3f6  7405                 je 0x47d3fd
// 0047d3f8  8b7b08               mov edi, dword ptr [ebx + 8]
// 0047d3fb  eb1b                 jmp 0x47d418
// 0047d3fd  8b5308               mov edx, dword ptr [ebx + 8]
// 0047d400  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 0047d404  7404                 je 0x47d40a
// 0047d406  8bf9                 mov edi, ecx
// 0047d408  eb0e                 jmp 0x47d418
// 0047d40a  8b442470             mov eax, dword ptr [esp + 0x70]
// 0047d40e  8b7808               mov edi, dword ptr [eax + 8]
// 0047d411  8d5008               lea edx, [eax + 8]
// 0047d414  3bc3                 cmp eax, ebx
// 0047d416  756b                 jne 0x47d483
// 0047d418  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0047d41c  8b7304               mov esi, dword ptr [ebx + 4]
// 0047d41f  7503                 jne 0x47d424
// 0047d421  897704               mov dword ptr [edi + 4], esi
// 0047d424  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0047d427  395804               cmp dword ptr [eax + 4], ebx
// 0047d42a  7505                 jne 0x47d431
// 0047d42c  897804               mov dword ptr [eax + 4], edi
// 0047d42f  eb0b                 jmp 0x47d43c
// 0047d431  391e                 cmp dword ptr [esi], ebx
// 0047d433  7504                 jne 0x47d439
// 0047d435  893e                 mov dword ptr [esi], edi
// 0047d437  eb03                 jmp 0x47d43c
// 0047d439  897e08               mov dword ptr [esi + 8], edi
// 0047d43c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0047d43f  8b03                 mov eax, dword ptr [ebx]
// 0047d441  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0047d445  7515                 jne 0x47d45c
// 0047d447  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0047d44b  7404                 je 0x47d451
// 0047d44d  8bc6                 mov eax, esi
// 0047d44f  eb09                 jmp 0x47d45a
// 0047d451  57                   push edi
// 0047d452  e899380000           call 0x480cf0
// 0047d457  83c404               add esp, 4
// 0047d45a  8903                 mov dword ptr [ebx], eax
// 0047d45c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0047d45f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0047d463  394b08               cmp dword ptr [ebx + 8], ecx
// 0047d466  7577                 jne 0x47d4df
// 0047d468  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0047d46c  7407                 je 0x47d475
// 0047d46e  8bc6                 mov eax, esi
// 0047d470  894308               mov dword ptr [ebx + 8], eax
// 0047d473  eb6a                 jmp 0x47d4df
// 0047d475  57                   push edi
// 0047d476  e835c32b00           call 0x7397b0
// 0047d47b  83c404               add esp, 4
// 0047d47e  894308               mov dword ptr [ebx + 8], eax
// 0047d481  eb5c                 jmp 0x47d4df
// 0047d483  894104               mov dword ptr [ecx + 4], eax
// 0047d486  8b0b                 mov ecx, dword ptr [ebx]
// 0047d488  8908                 mov dword ptr [eax], ecx
// 0047d48a  3b4308               cmp eax, dword ptr [ebx + 8]
// 0047d48d  7504                 jne 0x47d493
// 0047d48f  8bf0                 mov esi, eax
// 0047d491  eb19                 jmp 0x47d4ac
// 0047d493  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0047d497  8b7004               mov esi, dword ptr [eax + 4]
// 0047d49a  7503                 jne 0x47d49f
// 0047d49c  897704               mov dword ptr [edi + 4], esi
// 0047d49f  893e                 mov dword ptr [esi], edi
// 0047d4a1  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0047d4a4  890a                 mov dword ptr [edx], ecx
// 0047d4a6  8b5308               mov edx, dword ptr [ebx + 8]
// 0047d4a9  894204               mov dword ptr [edx + 4], eax
// 0047d4ac  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0047d4af  395904               cmp dword ptr [ecx + 4], ebx
// 0047d4b2  7505                 jne 0x47d4b9
// 0047d4b4  894104               mov dword ptr [ecx + 4], eax
// 0047d4b7  eb0e                 jmp 0x47d4c7
// 0047d4b9  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0047d4bc  3919                 cmp dword ptr [ecx], ebx
// 0047d4be  7504                 jne 0x47d4c4
// 0047d4c0  8901                 mov dword ptr [ecx], eax
// 0047d4c2  eb03                 jmp 0x47d4c7
// 0047d4c4  894108               mov dword ptr [ecx + 8], eax
// 0047d4c7  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0047d4ca  894804               mov dword ptr [eax + 4], ecx
// 0047d4cd  8d4b2c               lea ecx, [ebx + 0x2c]
// 0047d4d0  83c02c               add eax, 0x2c
// 0047d4d3  3bc1                 cmp eax, ecx
// 0047d4d5  7408                 je 0x47d4df
// 0047d4d7  8a19                 mov bl, byte ptr [ecx]
// 0047d4d9  8a10                 mov dl, byte ptr [eax]
// 0047d4db  8818                 mov byte ptr [eax], bl
// 0047d4dd  8811                 mov byte ptr [ecx], dl
// 0047d4df  8b542410             mov edx, dword ptr [esp + 0x10]
// 0047d4e3  b301                 mov bl, 1
// 0047d4e5  385a2c               cmp byte ptr [edx + 0x2c], bl
// 0047d4e8  0f85fd000000         jne 0x47d5eb
// 0047d4ee  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0047d4f1  3b7804               cmp edi, dword ptr [eax + 4]
// 0047d4f4  0f84ee000000         je 0x47d5e8
// 0047d4fa  8d9b00000000         lea ebx, [ebx]
// 0047d500  385f2c               cmp byte ptr [edi + 0x2c], bl
// 0047d503  0f85df000000         jne 0x47d5e8
// 0047d509  8b06                 mov eax, dword ptr [esi]
// 0047d50b  3bf8                 cmp edi, eax
// 0047d50d  7565                 jne 0x47d574
// 0047d50f  8b4608               mov eax, dword ptr [esi + 8]
// 0047d512  80782c00             cmp byte ptr [eax + 0x2c], 0
// 0047d516  7512                 jne 0x47d52a
// 0047d518  88582c               mov byte ptr [eax + 0x2c], bl
// 0047d51b  56                   push esi
// 0047d51c  8bcd                 mov ecx, ebp
// 0047d51e  c6462c00             mov byte ptr [esi + 0x2c], 0
// 0047d522  e8a9c22b00           call 0x7397d0
// 0047d527  8b4608               mov eax, dword ptr [esi + 8]
// 0047d52a  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0047d52e  7574                 jne 0x47d5a4
// 0047d530  8b08                 mov ecx, dword ptr [eax]
// 0047d532  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0047d535  7508                 jne 0x47d53f
// 0047d537  8b5008               mov edx, dword ptr [eax + 8]
// 0047d53a  385a2c               cmp byte ptr [edx + 0x2c], bl
// 0047d53d  7461                 je 0x47d5a0
// 0047d53f  8b4808               mov ecx, dword ptr [eax + 8]
// 0047d542  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0047d545  7514                 jne 0x47d55b
// 0047d547  8b10                 mov edx, dword ptr [eax]
// 0047d549  885a2c               mov byte ptr [edx + 0x2c], bl
// 0047d54c  50                   push eax
// 0047d54d  8bcd                 mov ecx, ebp
// 0047d54f  c6402c00             mov byte ptr [eax + 0x2c], 0
// 0047d553  e868354e00           call 0x960ac0
// 0047d558  8b4608               mov eax, dword ptr [esi + 8]
// 0047d55b  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 0047d55e  88482c               mov byte ptr [eax + 0x2c], cl
// 0047d561  885e2c               mov byte ptr [esi + 0x2c], bl
// 0047d564  8b5008               mov edx, dword ptr [eax + 8]
// 0047d567  56                   push esi
// 0047d568  8bcd                 mov ecx, ebp
// 0047d56a  885a2c               mov byte ptr [edx + 0x2c], bl
// 0047d56d  e85ec22b00           call 0x7397d0
// 0047d572  eb74                 jmp 0x47d5e8
// 0047d574  80782c00             cmp byte ptr [eax + 0x2c], 0
// 0047d578  7511                 jne 0x47d58b
// 0047d57a  88582c               mov byte ptr [eax + 0x2c], bl
// 0047d57d  56                   push esi
// 0047d57e  8bcd                 mov ecx, ebp
// 0047d580  c6462c00             mov byte ptr [esi + 0x2c], 0
// 0047d584  e837354e00           call 0x960ac0
// 0047d589  8b06                 mov eax, dword ptr [esi]
// 0047d58b  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0047d58f  7513                 jne 0x47d5a4
// 0047d591  8b4808               mov ecx, dword ptr [eax + 8]
// 0047d594  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0047d597  751e                 jne 0x47d5b7
// 0047d599  8b10                 mov edx, dword ptr [eax]
// 0047d59b  385a2c               cmp byte ptr [edx + 0x2c], bl
// 0047d59e  7517                 jne 0x47d5b7
// 0047d5a0  c6402c00             mov byte ptr [eax + 0x2c], 0
// 0047d5a4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0047d5a7  8bfe                 mov edi, esi
// 0047d5a9  8b7604               mov esi, dword ptr [esi + 4]
// 0047d5ac  3b7804               cmp edi, dword ptr [eax + 4]
// 0047d5af  0f854bffffff         jne 0x47d500
// 0047d5b5  eb31                 jmp 0x47d5e8
// 0047d5b7  8b08                 mov ecx, dword ptr [eax]
// 0047d5b9  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0047d5bc  7514                 jne 0x47d5d2
// 0047d5be  8b5008               mov edx, dword ptr [eax + 8]
// 0047d5c1  885a2c               mov byte ptr [edx + 0x2c], bl
// 0047d5c4  50                   push eax
// 0047d5c5  8bcd                 mov ecx, ebp
// 0047d5c7  c6402c00             mov byte ptr [eax + 0x2c], 0
// 0047d5cb  e800c22b00           call 0x7397d0
// 0047d5d0  8b06                 mov eax, dword ptr [esi]
// 0047d5d2  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 0047d5d5  88482c               mov byte ptr [eax + 0x2c], cl
// 0047d5d8  885e2c               mov byte ptr [esi + 0x2c], bl
// 0047d5db  8b10                 mov edx, dword ptr [eax]
// 0047d5dd  56                   push esi
// 0047d5de  8bcd                 mov ecx, ebp
// 0047d5e0  885a2c               mov byte ptr [edx + 0x2c], bl
// 0047d5e3  e8d8344e00           call 0x960ac0
// 0047d5e8  885f2c               mov byte ptr [edi + 0x2c], bl
// 0047d5eb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0047d5ef  83c10c               add ecx, 0xc
// 0047d5f2  ff1500a49e00         call dword ptr [0x9ea400]
// 0047d5f8  8b442410             mov eax, dword ptr [esp + 0x10]
// 0047d5fc  50                   push eax
// 0047d5fd  e898a33200           call 0x7a799a
// 0047d602  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 0047d605  83c404               add esp, 4
// 0047d608  5f                   pop edi
// 0047d609  5e                   pop esi
// 0047d60a  5b                   pop ebx
// 0047d60b  85c0                 test eax, eax
// 0047d60d  7604                 jbe 0x47d613
// 0047d60f  48                   dec eax
// 0047d610  89451c               mov dword ptr [ebp + 0x1c], eax
// 0047d613  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 0047d617  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0047d61b  8b5500               mov edx, dword ptr [ebp]
// 0047d61e  894804               mov dword ptr [eax + 4], ecx
// 0047d621  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0047d625  8910                 mov dword ptr [eax], edx
// 0047d627  5d                   pop ebp
// 0047d628  64890d00000000       mov dword ptr fs:[0], ecx
// 0047d62f  83c454               add esp, 0x54
// 0047d632  c20c00               ret 0xc
// standard library map_str<ptr> (function ?erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
