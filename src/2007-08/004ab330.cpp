// from server: 100% by auto
// roc 2007-08 004ab330  unit: RBX::Network::Peer  size: 692 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ab330
//
// 004ab330  6aff                 push -1
// 004ab332  68e9a07400           push 0x74a0e9
// 004ab337  64a100000000         mov eax, dword ptr fs:[0]
// 004ab33d  50                   push eax
// 004ab33e  83ec48               sub esp, 0x48
// 004ab341  53                   push ebx
// 004ab342  55                   push ebp
// 004ab343  56                   push esi
// 004ab344  57                   push edi
// 004ab345  a188518b00           mov eax, dword ptr [0x8b5188]
// 004ab34a  33c4                 xor eax, esp
// 004ab34c  50                   push eax
// 004ab34d  8d44245c             lea eax, [esp + 0x5c]
// 004ab351  64a300000000         mov dword ptr fs:[0], eax
// 004ab357  8be9                 mov ebp, ecx
// 004ab359  8b442474             mov eax, dword ptr [esp + 0x74]
// 004ab35d  80782d00             cmp byte ptr [eax + 0x2d], 0
// 004ab361  743c                 je 0x4ab39f
// 004ab363  68dc4e7800           push 0x784edc
// 004ab368  8d4c241c             lea ecx, [esp + 0x1c]
// 004ab36c  ff1598e67700         call dword ptr [0x77e698]
// 004ab372  8d442418             lea eax, [esp + 0x18]
// 004ab376  50                   push eax
// 004ab377  8d4c2438             lea ecx, [esp + 0x38]
// 004ab37b  c744246800000000     mov dword ptr [esp + 0x68], 0
// 004ab383  e83871f5ff           call 0x4024c0
// 004ab388  6864f38300           push 0x83f364
// 004ab38d  8d4c2438             lea ecx, [esp + 0x38]
// 004ab391  51                   push ecx
// 004ab392  c744243c784e7800     mov dword ptr [esp + 0x3c], 0x784e78
// 004ab39a  e8ff571800           call 0x630b9e
// 004ab39f  8bd8                 mov ebx, eax
// 004ab3a1  8d4c2470             lea ecx, [esp + 0x70]
// 004ab3a5  895c2414             mov dword ptr [esp + 0x14], ebx
// 004ab3a9  e872eb1200           call 0x5d9f20
// 004ab3ae  8b03                 mov eax, dword ptr [ebx]
// 004ab3b0  80782d00             cmp byte ptr [eax + 0x2d], 0
// 004ab3b4  7405                 je 0x4ab3bb
// 004ab3b6  8b7b08               mov edi, dword ptr [ebx + 8]
// 004ab3b9  eb18                 jmp 0x4ab3d3
// 004ab3bb  8b5308               mov edx, dword ptr [ebx + 8]
// 004ab3be  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 004ab3c2  7404                 je 0x4ab3c8
// 004ab3c4  8bf8                 mov edi, eax
// 004ab3c6  eb0b                 jmp 0x4ab3d3
// 004ab3c8  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 004ab3cc  3bcb                 cmp ecx, ebx
// 004ab3ce  8b7908               mov edi, dword ptr [ecx + 8]
// 004ab3d1  756b                 jne 0x4ab43e
// 004ab3d3  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 004ab3d7  8b7304               mov esi, dword ptr [ebx + 4]
// 004ab3da  7503                 jne 0x4ab3df
// 004ab3dc  897704               mov dword ptr [edi + 4], esi
// 004ab3df  8b4504               mov eax, dword ptr [ebp + 4]
// 004ab3e2  395804               cmp dword ptr [eax + 4], ebx
// 004ab3e5  7505                 jne 0x4ab3ec
// 004ab3e7  897804               mov dword ptr [eax + 4], edi
// 004ab3ea  eb0b                 jmp 0x4ab3f7
// 004ab3ec  391e                 cmp dword ptr [esi], ebx
// 004ab3ee  7504                 jne 0x4ab3f4
// 004ab3f0  893e                 mov dword ptr [esi], edi
// 004ab3f2  eb03                 jmp 0x4ab3f7
// 004ab3f4  897e08               mov dword ptr [esi + 8], edi
// 004ab3f7  8b5d04               mov ebx, dword ptr [ebp + 4]
// 004ab3fa  8b03                 mov eax, dword ptr [ebx]
// 004ab3fc  3b442414             cmp eax, dword ptr [esp + 0x14]
// 004ab400  7515                 jne 0x4ab417
// 004ab402  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 004ab406  7404                 je 0x4ab40c
// 004ab408  8bc6                 mov eax, esi
// 004ab40a  eb09                 jmp 0x4ab415
// 004ab40c  57                   push edi
// 004ab40d  e87e4fffff           call 0x4a0390
// 004ab412  83c404               add esp, 4
// 004ab415  8903                 mov dword ptr [ebx], eax
// 004ab417  8b5d04               mov ebx, dword ptr [ebp + 4]
// 004ab41a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004ab41e  394b08               cmp dword ptr [ebx + 8], ecx
// 004ab421  7572                 jne 0x4ab495
// 004ab423  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 004ab427  7407                 je 0x4ab430
// 004ab429  8bc6                 mov eax, esi
// 004ab42b  894308               mov dword ptr [ebx + 8], eax
// 004ab42e  eb65                 jmp 0x4ab495
// 004ab430  57                   push edi
// 004ab431  e81ae30e00           call 0x599750
// 004ab436  83c404               add esp, 4
// 004ab439  894308               mov dword ptr [ebx + 8], eax
// 004ab43c  eb57                 jmp 0x4ab495
// 004ab43e  894804               mov dword ptr [eax + 4], ecx
// 004ab441  8b13                 mov edx, dword ptr [ebx]
// 004ab443  8911                 mov dword ptr [ecx], edx
// 004ab445  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 004ab448  7504                 jne 0x4ab44e
// 004ab44a  8bf1                 mov esi, ecx
// 004ab44c  eb1a                 jmp 0x4ab468
// 004ab44e  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 004ab452  8b7104               mov esi, dword ptr [ecx + 4]
// 004ab455  7503                 jne 0x4ab45a
// 004ab457  897704               mov dword ptr [edi + 4], esi
// 004ab45a  893e                 mov dword ptr [esi], edi
// 004ab45c  8b4308               mov eax, dword ptr [ebx + 8]
// 004ab45f  894108               mov dword ptr [ecx + 8], eax
// 004ab462  8b5308               mov edx, dword ptr [ebx + 8]
// 004ab465  894a04               mov dword ptr [edx + 4], ecx
// 004ab468  8b4504               mov eax, dword ptr [ebp + 4]
// 004ab46b  395804               cmp dword ptr [eax + 4], ebx
// 004ab46e  7505                 jne 0x4ab475
// 004ab470  894804               mov dword ptr [eax + 4], ecx
// 004ab473  eb0e                 jmp 0x4ab483
// 004ab475  8b4304               mov eax, dword ptr [ebx + 4]
// 004ab478  3918                 cmp dword ptr [eax], ebx
// 004ab47a  7504                 jne 0x4ab480
// 004ab47c  8908                 mov dword ptr [eax], ecx
// 004ab47e  eb03                 jmp 0x4ab483
// 004ab480  894808               mov dword ptr [eax + 8], ecx
// 004ab483  8b4304               mov eax, dword ptr [ebx + 4]
// 004ab486  894104               mov dword ptr [ecx + 4], eax
// 004ab489  8a532c               mov dl, byte ptr [ebx + 0x2c]
// 004ab48c  8a412c               mov al, byte ptr [ecx + 0x2c]
// 004ab48f  88512c               mov byte ptr [ecx + 0x2c], dl
// 004ab492  88432c               mov byte ptr [ebx + 0x2c], al
// 004ab495  8b442414             mov eax, dword ptr [esp + 0x14]
// 004ab499  b301                 mov bl, 1
// 004ab49b  38582c               cmp byte ptr [eax + 0x2c], bl
// 004ab49e  0f85f2000000         jne 0x4ab596
// 004ab4a4  8b4d04               mov ecx, dword ptr [ebp + 4]
// 004ab4a7  3b7904               cmp edi, dword ptr [ecx + 4]
// 004ab4aa  0f84e3000000         je 0x4ab593
// 004ab4b0  385f2c               cmp byte ptr [edi + 0x2c], bl
// 004ab4b3  0f85da000000         jne 0x4ab593
// 004ab4b9  8b06                 mov eax, dword ptr [esi]
// 004ab4bb  3bf8                 cmp edi, eax
// 004ab4bd  7563                 jne 0x4ab522
// 004ab4bf  8b4608               mov eax, dword ptr [esi + 8]
// 004ab4c2  80782c00             cmp byte ptr [eax + 0x2c], 0
// 004ab4c6  7512                 jne 0x4ab4da
// 004ab4c8  88582c               mov byte ptr [eax + 0x2c], bl
// 004ab4cb  56                   push esi
// 004ab4cc  8bcd                 mov ecx, ebp
// 004ab4ce  c6462c00             mov byte ptr [esi + 0x2c], 0
// 004ab4d2  e8b95affff           call 0x4a0f90
// 004ab4d7  8b4608               mov eax, dword ptr [esi + 8]
// 004ab4da  80782d00             cmp byte ptr [eax + 0x2d], 0
// 004ab4de  7572                 jne 0x4ab552
// 004ab4e0  8b10                 mov edx, dword ptr [eax]
// 004ab4e2  385a2c               cmp byte ptr [edx + 0x2c], bl
// 004ab4e5  7508                 jne 0x4ab4ef
// 004ab4e7  8b4808               mov ecx, dword ptr [eax + 8]
// 004ab4ea  38592c               cmp byte ptr [ecx + 0x2c], bl
// 004ab4ed  745f                 je 0x4ab54e
// 004ab4ef  8b4808               mov ecx, dword ptr [eax + 8]
// 004ab4f2  38592c               cmp byte ptr [ecx + 0x2c], bl
// 004ab4f5  7512                 jne 0x4ab509
// 004ab4f7  885a2c               mov byte ptr [edx + 0x2c], bl
// 004ab4fa  50                   push eax
// 004ab4fb  8bcd                 mov ecx, ebp
// 004ab4fd  c6402c00             mov byte ptr [eax + 0x2c], 0
// 004ab501  e8da59ffff           call 0x4a0ee0
// 004ab506  8b4608               mov eax, dword ptr [esi + 8]
// 004ab509  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 004ab50c  88482c               mov byte ptr [eax + 0x2c], cl
// 004ab50f  885e2c               mov byte ptr [esi + 0x2c], bl
// 004ab512  8b5008               mov edx, dword ptr [eax + 8]
// 004ab515  56                   push esi
// 004ab516  8bcd                 mov ecx, ebp
// 004ab518  885a2c               mov byte ptr [edx + 0x2c], bl
// 004ab51b  e8705affff           call 0x4a0f90
// 004ab520  eb71                 jmp 0x4ab593
// 004ab522  80782c00             cmp byte ptr [eax + 0x2c], 0
// 004ab526  7511                 jne 0x4ab539
// 004ab528  88582c               mov byte ptr [eax + 0x2c], bl
// 004ab52b  56                   push esi
// 004ab52c  8bcd                 mov ecx, ebp
// 004ab52e  c6462c00             mov byte ptr [esi + 0x2c], 0
// 004ab532  e8a959ffff           call 0x4a0ee0
// 004ab537  8b06                 mov eax, dword ptr [esi]
// 004ab539  80782d00             cmp byte ptr [eax + 0x2d], 0
// 004ab53d  7513                 jne 0x4ab552
// 004ab53f  8b5008               mov edx, dword ptr [eax + 8]
// 004ab542  385a2c               cmp byte ptr [edx + 0x2c], bl
// 004ab545  751e                 jne 0x4ab565
// 004ab547  8b08                 mov ecx, dword ptr [eax]
// 004ab549  38592c               cmp byte ptr [ecx + 0x2c], bl
// 004ab54c  7517                 jne 0x4ab565
// 004ab54e  c6402c00             mov byte ptr [eax + 0x2c], 0
// 004ab552  8b5504               mov edx, dword ptr [ebp + 4]
// 004ab555  8bfe                 mov edi, esi
// 004ab557  3b7a04               cmp edi, dword ptr [edx + 4]
// 004ab55a  8b7604               mov esi, dword ptr [esi + 4]
// 004ab55d  0f854dffffff         jne 0x4ab4b0
// 004ab563  eb2e                 jmp 0x4ab593
// 004ab565  8b08                 mov ecx, dword ptr [eax]
// 004ab567  38592c               cmp byte ptr [ecx + 0x2c], bl
// 004ab56a  7511                 jne 0x4ab57d
// 004ab56c  885a2c               mov byte ptr [edx + 0x2c], bl
// 004ab56f  50                   push eax
// 004ab570  8bcd                 mov ecx, ebp
// 004ab572  c6402c00             mov byte ptr [eax + 0x2c], 0
// 004ab576  e8155affff           call 0x4a0f90
// 004ab57b  8b06                 mov eax, dword ptr [esi]
// 004ab57d  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 004ab580  88482c               mov byte ptr [eax + 0x2c], cl
// 004ab583  885e2c               mov byte ptr [esi + 0x2c], bl
// 004ab586  8b10                 mov edx, dword ptr [eax]
// 004ab588  56                   push esi
// 004ab589  8bcd                 mov ecx, ebp
// 004ab58b  885a2c               mov byte ptr [edx + 0x2c], bl
// 004ab58e  e84d59ffff           call 0x4a0ee0
// 004ab593  885f2c               mov byte ptr [edi + 0x2c], bl
// 004ab596  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004ab59a  83c110               add ecx, 0x10
// 004ab59d  ff15ace67700         call dword ptr [0x77e6ac]
// 004ab5a3  8b442414             mov eax, dword ptr [esp + 0x14]
// 004ab5a7  50                   push eax
// 004ab5a8  e8b5461800           call 0x62fc62
// 004ab5ad  8b4508               mov eax, dword ptr [ebp + 8]
// 004ab5b0  83c404               add esp, 4
// 004ab5b3  85c0                 test eax, eax
// 004ab5b5  7606                 jbe 0x4ab5bd
// 004ab5b7  83c0ff               add eax, -1
// 004ab5ba  894508               mov dword ptr [ebp + 8], eax
// 004ab5bd  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 004ab5c1  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 004ab5c5  8b542474             mov edx, dword ptr [esp + 0x74]
// 004ab5c9  8908                 mov dword ptr [eax], ecx
// 004ab5cb  895004               mov dword ptr [eax + 4], edx
// 004ab5ce  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 004ab5d2  64890d00000000       mov dword ptr fs:[0], ecx
// 004ab5d9  59                   pop ecx
// 004ab5da  5f                   pop edi
// 004ab5db  5e                   pop esi
// 004ab5dc  5d                   pop ebp
// 004ab5dd  5b                   pop ebx
// 004ab5de  83c454               add esp, 0x54
// 004ab5e1  c20c00               ret 0xc
// standard library map_int<string> (function ?erase@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@V312@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
