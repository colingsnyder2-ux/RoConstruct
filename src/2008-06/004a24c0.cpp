// from server: 100% by auto
// roc 2008-06 004a24c0  unit: RBX::Network::VServer::?$FactoryProduct  size: 725 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a24c0
//
// 004a24c0  64a100000000         mov eax, dword ptr fs:[0]
// 004a24c6  6aff                 push -1
// 004a24c8  6842e87d00           push 0x7de842
// 004a24cd  50                   push eax
// 004a24ce  64892500000000       mov dword ptr fs:[0], esp
// 004a24d5  8b442418             mov eax, dword ptr [esp + 0x18]
// 004a24d9  83ec48               sub esp, 0x48
// 004a24dc  80782900             cmp byte ptr [eax + 0x29], 0
// 004a24e0  55                   push ebp
// 004a24e1  8be9                 mov ebp, ecx
// 004a24e3  7459                 je 0x4a253e
// 004a24e5  6870b28000           push 0x80b270
// 004a24ea  8d4c240c             lea ecx, [esp + 0xc]
// 004a24ee  ff1558248000         call dword ptr [0x802458]
// 004a24f4  8d4c2424             lea ecx, [esp + 0x24]
// 004a24f8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 004a2500  ff1598288000         call dword ptr [0x802898]
// 004a2506  8d442408             lea eax, [esp + 8]
// 004a250a  50                   push eax
// 004a250b  8d4c2434             lea ecx, [esp + 0x34]
// 004a250f  c644245801           mov byte ptr [esp + 0x58], 1
// 004a2514  c744242810b18000     mov dword ptr [esp + 0x28], 0x80b110
// 004a251c  ff155c248000         call dword ptr [0x80245c]
// 004a2522  683c0c8d00           push 0x8d0c3c
// 004a2527  8d4c2428             lea ecx, [esp + 0x28]
// 004a252b  51                   push ecx
// 004a252c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 004a2531  c744242c28b18000     mov dword ptr [esp + 0x2c], 0x80b128
// 004a2539  e84ef01f00           call 0x6a158c
// 004a253e  53                   push ebx
// 004a253f  56                   push esi
// 004a2540  8bd8                 mov ebx, eax
// 004a2542  57                   push edi
// 004a2543  8d4c246c             lea ecx, [esp + 0x6c]
// 004a2547  895c2410             mov dword ptr [esp + 0x10], ebx
// 004a254b  e82062f9ff           call 0x438770
// 004a2550  8b0b                 mov ecx, dword ptr [ebx]
// 004a2552  80792900             cmp byte ptr [ecx + 0x29], 0
// 004a2556  7405                 je 0x4a255d
// 004a2558  8b7b08               mov edi, dword ptr [ebx + 8]
// 004a255b  eb1b                 jmp 0x4a2578
// 004a255d  8b5308               mov edx, dword ptr [ebx + 8]
// 004a2560  807a2900             cmp byte ptr [edx + 0x29], 0
// 004a2564  7404                 je 0x4a256a
// 004a2566  8bf9                 mov edi, ecx
// 004a2568  eb0e                 jmp 0x4a2578
// 004a256a  8b442470             mov eax, dword ptr [esp + 0x70]
// 004a256e  8b7808               mov edi, dword ptr [eax + 8]
// 004a2571  8d5008               lea edx, [eax + 8]
// 004a2574  3bc3                 cmp eax, ebx
// 004a2576  756b                 jne 0x4a25e3
// 004a2578  807f2900             cmp byte ptr [edi + 0x29], 0
// 004a257c  8b7304               mov esi, dword ptr [ebx + 4]
// 004a257f  7503                 jne 0x4a2584
// 004a2581  897704               mov dword ptr [edi + 4], esi
// 004a2584  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004a2587  395804               cmp dword ptr [eax + 4], ebx
// 004a258a  7505                 jne 0x4a2591
// 004a258c  897804               mov dword ptr [eax + 4], edi
// 004a258f  eb0b                 jmp 0x4a259c
// 004a2591  391e                 cmp dword ptr [esi], ebx
// 004a2593  7504                 jne 0x4a2599
// 004a2595  893e                 mov dword ptr [esi], edi
// 004a2597  eb03                 jmp 0x4a259c
// 004a2599  897e08               mov dword ptr [esi + 8], edi
// 004a259c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 004a259f  8b03                 mov eax, dword ptr [ebx]
// 004a25a1  3b442410             cmp eax, dword ptr [esp + 0x10]
// 004a25a5  7515                 jne 0x4a25bc
// 004a25a7  807f2900             cmp byte ptr [edi + 0x29], 0
// 004a25ab  7404                 je 0x4a25b1
// 004a25ad  8bc6                 mov eax, esi
// 004a25af  eb09                 jmp 0x4a25ba
// 004a25b1  57                   push edi
// 004a25b2  e84959f9ff           call 0x437f00
// 004a25b7  83c404               add esp, 4
// 004a25ba  8903                 mov dword ptr [ebx], eax
// 004a25bc  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 004a25bf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a25c3  394b08               cmp dword ptr [ebx + 8], ecx
// 004a25c6  7577                 jne 0x4a263f
// 004a25c8  807f2900             cmp byte ptr [edi + 0x29], 0
// 004a25cc  7407                 je 0x4a25d5
// 004a25ce  8bc6                 mov eax, esi
// 004a25d0  894308               mov dword ptr [ebx + 8], eax
// 004a25d3  eb6a                 jmp 0x4a263f
// 004a25d5  57                   push edi
// 004a25d6  e885f0ffff           call 0x4a1660
// 004a25db  83c404               add esp, 4
// 004a25de  894308               mov dword ptr [ebx + 8], eax
// 004a25e1  eb5c                 jmp 0x4a263f
// 004a25e3  894104               mov dword ptr [ecx + 4], eax
// 004a25e6  8b0b                 mov ecx, dword ptr [ebx]
// 004a25e8  8908                 mov dword ptr [eax], ecx
// 004a25ea  3b4308               cmp eax, dword ptr [ebx + 8]
// 004a25ed  7504                 jne 0x4a25f3
// 004a25ef  8bf0                 mov esi, eax
// 004a25f1  eb19                 jmp 0x4a260c
// 004a25f3  807f2900             cmp byte ptr [edi + 0x29], 0
// 004a25f7  8b7004               mov esi, dword ptr [eax + 4]
// 004a25fa  7503                 jne 0x4a25ff
// 004a25fc  897704               mov dword ptr [edi + 4], esi
// 004a25ff  893e                 mov dword ptr [esi], edi
// 004a2601  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004a2604  890a                 mov dword ptr [edx], ecx
// 004a2606  8b5308               mov edx, dword ptr [ebx + 8]
// 004a2609  894204               mov dword ptr [edx + 4], eax
// 004a260c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 004a260f  395904               cmp dword ptr [ecx + 4], ebx
// 004a2612  7505                 jne 0x4a2619
// 004a2614  894104               mov dword ptr [ecx + 4], eax
// 004a2617  eb0e                 jmp 0x4a2627
// 004a2619  8b4b04               mov ecx, dword ptr [ebx + 4]
// 004a261c  3919                 cmp dword ptr [ecx], ebx
// 004a261e  7504                 jne 0x4a2624
// 004a2620  8901                 mov dword ptr [ecx], eax
// 004a2622  eb03                 jmp 0x4a2627
// 004a2624  894108               mov dword ptr [ecx + 8], eax
// 004a2627  8b4b04               mov ecx, dword ptr [ebx + 4]
// 004a262a  894804               mov dword ptr [eax + 4], ecx
// 004a262d  8d4b28               lea ecx, [ebx + 0x28]
// 004a2630  83c028               add eax, 0x28
// 004a2633  3bc1                 cmp eax, ecx
// 004a2635  7408                 je 0x4a263f
// 004a2637  8a19                 mov bl, byte ptr [ecx]
// 004a2639  8a10                 mov dl, byte ptr [eax]
// 004a263b  8818                 mov byte ptr [eax], bl
// 004a263d  8811                 mov byte ptr [ecx], dl
// 004a263f  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a2643  b301                 mov bl, 1
// 004a2645  385a28               cmp byte ptr [edx + 0x28], bl
// 004a2648  0f85fd000000         jne 0x4a274b
// 004a264e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004a2651  3b7804               cmp edi, dword ptr [eax + 4]
// 004a2654  0f84ee000000         je 0x4a2748
// 004a265a  8d9b00000000         lea ebx, [ebx]
// 004a2660  385f28               cmp byte ptr [edi + 0x28], bl
// 004a2663  0f85df000000         jne 0x4a2748
// 004a2669  8b06                 mov eax, dword ptr [esi]
// 004a266b  3bf8                 cmp edi, eax
// 004a266d  7565                 jne 0x4a26d4
// 004a266f  8b4608               mov eax, dword ptr [esi + 8]
// 004a2672  80782800             cmp byte ptr [eax + 0x28], 0
// 004a2676  7512                 jne 0x4a268a
// 004a2678  885828               mov byte ptr [eax + 0x28], bl
// 004a267b  56                   push esi
// 004a267c  8bcd                 mov ecx, ebp
// 004a267e  c6462800             mov byte ptr [esi + 0x28], 0
// 004a2682  e8194f0300           call 0x4d75a0
// 004a2687  8b4608               mov eax, dword ptr [esi + 8]
// 004a268a  80782900             cmp byte ptr [eax + 0x29], 0
// 004a268e  7574                 jne 0x4a2704
// 004a2690  8b08                 mov ecx, dword ptr [eax]
// 004a2692  385928               cmp byte ptr [ecx + 0x28], bl
// 004a2695  7508                 jne 0x4a269f
// 004a2697  8b5008               mov edx, dword ptr [eax + 8]
// 004a269a  385a28               cmp byte ptr [edx + 0x28], bl
// 004a269d  7461                 je 0x4a2700
// 004a269f  8b4808               mov ecx, dword ptr [eax + 8]
// 004a26a2  385928               cmp byte ptr [ecx + 0x28], bl
// 004a26a5  7514                 jne 0x4a26bb
// 004a26a7  8b10                 mov edx, dword ptr [eax]
// 004a26a9  885a28               mov byte ptr [edx + 0x28], bl
// 004a26ac  50                   push eax
// 004a26ad  8bcd                 mov ecx, ebp
// 004a26af  c6402800             mov byte ptr [eax + 0x28], 0
// 004a26b3  e8d8f3ffff           call 0x4a1a90
// 004a26b8  8b4608               mov eax, dword ptr [esi + 8]
// 004a26bb  8a4e28               mov cl, byte ptr [esi + 0x28]
// 004a26be  884828               mov byte ptr [eax + 0x28], cl
// 004a26c1  885e28               mov byte ptr [esi + 0x28], bl
// 004a26c4  8b5008               mov edx, dword ptr [eax + 8]
// 004a26c7  56                   push esi
// 004a26c8  8bcd                 mov ecx, ebp
// 004a26ca  885a28               mov byte ptr [edx + 0x28], bl
// 004a26cd  e8ce4e0300           call 0x4d75a0
// 004a26d2  eb74                 jmp 0x4a2748
// 004a26d4  80782800             cmp byte ptr [eax + 0x28], 0
// 004a26d8  7511                 jne 0x4a26eb
// 004a26da  885828               mov byte ptr [eax + 0x28], bl
// 004a26dd  56                   push esi
// 004a26de  8bcd                 mov ecx, ebp
// 004a26e0  c6462800             mov byte ptr [esi + 0x28], 0
// 004a26e4  e8a7f3ffff           call 0x4a1a90
// 004a26e9  8b06                 mov eax, dword ptr [esi]
// 004a26eb  80782900             cmp byte ptr [eax + 0x29], 0
// 004a26ef  7513                 jne 0x4a2704
// 004a26f1  8b4808               mov ecx, dword ptr [eax + 8]
// 004a26f4  385928               cmp byte ptr [ecx + 0x28], bl
// 004a26f7  751e                 jne 0x4a2717
// 004a26f9  8b10                 mov edx, dword ptr [eax]
// 004a26fb  385a28               cmp byte ptr [edx + 0x28], bl
// 004a26fe  7517                 jne 0x4a2717
// 004a2700  c6402800             mov byte ptr [eax + 0x28], 0
// 004a2704  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004a2707  8bfe                 mov edi, esi
// 004a2709  8b7604               mov esi, dword ptr [esi + 4]
// 004a270c  3b7804               cmp edi, dword ptr [eax + 4]
// 004a270f  0f854bffffff         jne 0x4a2660
// 004a2715  eb31                 jmp 0x4a2748
// 004a2717  8b08                 mov ecx, dword ptr [eax]
// 004a2719  385928               cmp byte ptr [ecx + 0x28], bl
// 004a271c  7514                 jne 0x4a2732
// 004a271e  8b5008               mov edx, dword ptr [eax + 8]
// 004a2721  885a28               mov byte ptr [edx + 0x28], bl
// 004a2724  50                   push eax
// 004a2725  8bcd                 mov ecx, ebp
// 004a2727  c6402800             mov byte ptr [eax + 0x28], 0
// 004a272b  e8704e0300           call 0x4d75a0
// 004a2730  8b06                 mov eax, dword ptr [esi]
// 004a2732  8a4e28               mov cl, byte ptr [esi + 0x28]
// 004a2735  884828               mov byte ptr [eax + 0x28], cl
// 004a2738  885e28               mov byte ptr [esi + 0x28], bl
// 004a273b  8b10                 mov edx, dword ptr [eax]
// 004a273d  56                   push esi
// 004a273e  8bcd                 mov ecx, ebp
// 004a2740  885a28               mov byte ptr [edx + 0x28], bl
// 004a2743  e848f3ffff           call 0x4a1a90
// 004a2748  885f28               mov byte ptr [edi + 0x28], bl
// 004a274b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a274f  83c10c               add ecx, 0xc
// 004a2752  ff1568248000         call dword ptr [0x802468]
// 004a2758  8b442410             mov eax, dword ptr [esp + 0x10]
// 004a275c  50                   push eax
// 004a275d  e818df1f00           call 0x6a067a
// 004a2762  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 004a2765  83c404               add esp, 4
// 004a2768  5f                   pop edi
// 004a2769  5e                   pop esi
// 004a276a  5b                   pop ebx
// 004a276b  85c0                 test eax, eax
// 004a276d  7604                 jbe 0x4a2773
// 004a276f  48                   dec eax
// 004a2770  89451c               mov dword ptr [ebp + 0x1c], eax
// 004a2773  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 004a2777  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 004a277b  8b5500               mov edx, dword ptr [ebp]
// 004a277e  894804               mov dword ptr [eax + 4], ecx
// 004a2781  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004a2785  8910                 mov dword ptr [eax], edx
// 004a2787  5d                   pop ebp
// 004a2788  64890d00000000       mov dword ptr fs:[0], ecx
// 004a278f  83c454               add esp, 0x54
// 004a2792  c20c00               ret 0xc
// standard library set<string> (function ?erase@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
