// from server: 100% by auto
// roc 2007-03 005464b0  unit: seg_00540000  size: 709 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005464b0
//
// 005464b0  64a100000000         mov eax, dword ptr fs:[0]
// 005464b6  6aff                 push -1
// 005464b8  68926f7500           push 0x756f92
// 005464bd  50                   push eax
// 005464be  64892500000000       mov dword ptr fs:[0], esp
// 005464c5  8b442418             mov eax, dword ptr [esp + 0x18]
// 005464c9  83ec48               sub esp, 0x48
// 005464cc  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005464d0  55                   push ebp
// 005464d1  8be9                 mov ebp, ecx
// 005464d3  7459                 je 0x54652e
// 005464d5  68dc3e7800           push 0x783edc
// 005464da  8d4c240c             lea ecx, [esp + 0xc]
// 005464de  ff1578e77700         call dword ptr [0x77e778]
// 005464e4  8d4c2424             lea ecx, [esp + 0x24]
// 005464e8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 005464f0  ff1560e97700         call dword ptr [0x77e960]
// 005464f6  8d442408             lea eax, [esp + 8]
// 005464fa  50                   push eax
// 005464fb  8d4c2434             lea ecx, [esp + 0x34]
// 005464ff  c644245801           mov byte ptr [esp + 0x58], 1
// 00546504  c7442428383e7800     mov dword ptr [esp + 0x28], 0x783e38
// 0054650c  ff157ce77700         call dword ptr [0x77e77c]
// 00546512  68ccf38300           push 0x83f3cc
// 00546517  8d4c2428             lea ecx, [esp + 0x28]
// 0054651b  51                   push ecx
// 0054651c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00546521  c744242c503e7800     mov dword ptr [esp + 0x2c], 0x783e50
// 00546529  e8008b0d00           call 0x61f02e
// 0054652e  53                   push ebx
// 0054652f  56                   push esi
// 00546530  8bd8                 mov ebx, eax
// 00546532  57                   push edi
// 00546533  8d4c246c             lea ecx, [esp + 0x6c]
// 00546537  895c2410             mov dword ptr [esp + 0x10], ebx
// 0054653b  e83071feff           call 0x52d670
// 00546540  8b03                 mov eax, dword ptr [ebx]
// 00546542  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00546546  7405                 je 0x54654d
// 00546548  8b7b08               mov edi, dword ptr [ebx + 8]
// 0054654b  eb18                 jmp 0x546565
// 0054654d  8b5308               mov edx, dword ptr [ebx + 8]
// 00546550  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 00546554  7404                 je 0x54655a
// 00546556  8bf8                 mov edi, eax
// 00546558  eb0b                 jmp 0x546565
// 0054655a  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 0054655e  3bcb                 cmp ecx, ebx
// 00546560  8b7908               mov edi, dword ptr [ecx + 8]
// 00546563  756b                 jne 0x5465d0
// 00546565  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 00546569  8b7304               mov esi, dword ptr [ebx + 4]
// 0054656c  7503                 jne 0x546571
// 0054656e  897704               mov dword ptr [edi + 4], esi
// 00546571  8b4504               mov eax, dword ptr [ebp + 4]
// 00546574  395804               cmp dword ptr [eax + 4], ebx
// 00546577  7505                 jne 0x54657e
// 00546579  897804               mov dword ptr [eax + 4], edi
// 0054657c  eb0b                 jmp 0x546589
// 0054657e  391e                 cmp dword ptr [esi], ebx
// 00546580  7504                 jne 0x546586
// 00546582  893e                 mov dword ptr [esi], edi
// 00546584  eb03                 jmp 0x546589
// 00546586  897e08               mov dword ptr [esi + 8], edi
// 00546589  8b5d04               mov ebx, dword ptr [ebp + 4]
// 0054658c  8b03                 mov eax, dword ptr [ebx]
// 0054658e  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00546592  7515                 jne 0x5465a9
// 00546594  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 00546598  7404                 je 0x54659e
// 0054659a  8bc6                 mov eax, esi
// 0054659c  eb09                 jmp 0x5465a7
// 0054659e  57                   push edi
// 0054659f  e87c2b0200           call 0x569120
// 005465a4  83c404               add esp, 4
// 005465a7  8903                 mov dword ptr [ebx], eax
// 005465a9  8b5d04               mov ebx, dword ptr [ebp + 4]
// 005465ac  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005465b0  394b08               cmp dword ptr [ebx + 8], ecx
// 005465b3  7572                 jne 0x546627
// 005465b5  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 005465b9  7407                 je 0x5465c2
// 005465bb  8bc6                 mov eax, esi
// 005465bd  894308               mov dword ptr [ebx + 8], eax
// 005465c0  eb65                 jmp 0x546627
// 005465c2  57                   push edi
// 005465c3  e848180c00           call 0x607e10
// 005465c8  83c404               add esp, 4
// 005465cb  894308               mov dword ptr [ebx + 8], eax
// 005465ce  eb57                 jmp 0x546627
// 005465d0  894804               mov dword ptr [eax + 4], ecx
// 005465d3  8b13                 mov edx, dword ptr [ebx]
// 005465d5  8911                 mov dword ptr [ecx], edx
// 005465d7  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 005465da  7504                 jne 0x5465e0
// 005465dc  8bf1                 mov esi, ecx
// 005465de  eb1a                 jmp 0x5465fa
// 005465e0  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 005465e4  8b7104               mov esi, dword ptr [ecx + 4]
// 005465e7  7503                 jne 0x5465ec
// 005465e9  897704               mov dword ptr [edi + 4], esi
// 005465ec  893e                 mov dword ptr [esi], edi
// 005465ee  8b4308               mov eax, dword ptr [ebx + 8]
// 005465f1  894108               mov dword ptr [ecx + 8], eax
// 005465f4  8b5308               mov edx, dword ptr [ebx + 8]
// 005465f7  894a04               mov dword ptr [edx + 4], ecx
// 005465fa  8b4504               mov eax, dword ptr [ebp + 4]
// 005465fd  395804               cmp dword ptr [eax + 4], ebx
// 00546600  7505                 jne 0x546607
// 00546602  894804               mov dword ptr [eax + 4], ecx
// 00546605  eb0e                 jmp 0x546615
// 00546607  8b4304               mov eax, dword ptr [ebx + 4]
// 0054660a  3918                 cmp dword ptr [eax], ebx
// 0054660c  7504                 jne 0x546612
// 0054660e  8908                 mov dword ptr [eax], ecx
// 00546610  eb03                 jmp 0x546615
// 00546612  894808               mov dword ptr [eax + 8], ecx
// 00546615  8b4304               mov eax, dword ptr [ebx + 4]
// 00546618  894104               mov dword ptr [ecx + 4], eax
// 0054661b  8a532c               mov dl, byte ptr [ebx + 0x2c]
// 0054661e  8a412c               mov al, byte ptr [ecx + 0x2c]
// 00546621  88512c               mov byte ptr [ecx + 0x2c], dl
// 00546624  88432c               mov byte ptr [ebx + 0x2c], al
// 00546627  8b442410             mov eax, dword ptr [esp + 0x10]
// 0054662b  b301                 mov bl, 1
// 0054662d  38582c               cmp byte ptr [eax + 0x2c], bl
// 00546630  0f85f2000000         jne 0x546728
// 00546636  8b4d04               mov ecx, dword ptr [ebp + 4]
// 00546639  3b7904               cmp edi, dword ptr [ecx + 4]
// 0054663c  0f84e3000000         je 0x546725
// 00546642  385f2c               cmp byte ptr [edi + 0x2c], bl
// 00546645  0f85da000000         jne 0x546725
// 0054664b  8b06                 mov eax, dword ptr [esi]
// 0054664d  3bf8                 cmp edi, eax
// 0054664f  7563                 jne 0x5466b4
// 00546651  8b4608               mov eax, dword ptr [esi + 8]
// 00546654  80782c00             cmp byte ptr [eax + 0x2c], 0
// 00546658  7512                 jne 0x54666c
// 0054665a  88582c               mov byte ptr [eax + 0x2c], bl
// 0054665d  56                   push esi
// 0054665e  8bcd                 mov ecx, ebp
// 00546660  c6462c00             mov byte ptr [esi + 0x2c], 0
// 00546664  e827c7ffff           call 0x542d90
// 00546669  8b4608               mov eax, dword ptr [esi + 8]
// 0054666c  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00546670  7572                 jne 0x5466e4
// 00546672  8b10                 mov edx, dword ptr [eax]
// 00546674  385a2c               cmp byte ptr [edx + 0x2c], bl
// 00546677  7508                 jne 0x546681
// 00546679  8b4808               mov ecx, dword ptr [eax + 8]
// 0054667c  38592c               cmp byte ptr [ecx + 0x2c], bl
// 0054667f  745f                 je 0x5466e0
// 00546681  8b4808               mov ecx, dword ptr [eax + 8]
// 00546684  38592c               cmp byte ptr [ecx + 0x2c], bl
// 00546687  7512                 jne 0x54669b
// 00546689  885a2c               mov byte ptr [edx + 0x2c], bl
// 0054668c  50                   push eax
// 0054668d  8bcd                 mov ecx, ebp
// 0054668f  c6402c00             mov byte ptr [eax + 0x2c], 0
// 00546693  e8c8bc0200           call 0x572360
// 00546698  8b4608               mov eax, dword ptr [esi + 8]
// 0054669b  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 0054669e  88482c               mov byte ptr [eax + 0x2c], cl
// 005466a1  885e2c               mov byte ptr [esi + 0x2c], bl
// 005466a4  8b5008               mov edx, dword ptr [eax + 8]
// 005466a7  56                   push esi
// 005466a8  8bcd                 mov ecx, ebp
// 005466aa  885a2c               mov byte ptr [edx + 0x2c], bl
// 005466ad  e8dec6ffff           call 0x542d90
// 005466b2  eb71                 jmp 0x546725
// 005466b4  80782c00             cmp byte ptr [eax + 0x2c], 0
// 005466b8  7511                 jne 0x5466cb
// 005466ba  88582c               mov byte ptr [eax + 0x2c], bl
// 005466bd  56                   push esi
// 005466be  8bcd                 mov ecx, ebp
// 005466c0  c6462c00             mov byte ptr [esi + 0x2c], 0
// 005466c4  e897bc0200           call 0x572360
// 005466c9  8b06                 mov eax, dword ptr [esi]
// 005466cb  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005466cf  7513                 jne 0x5466e4
// 005466d1  8b5008               mov edx, dword ptr [eax + 8]
// 005466d4  385a2c               cmp byte ptr [edx + 0x2c], bl
// 005466d7  751e                 jne 0x5466f7
// 005466d9  8b08                 mov ecx, dword ptr [eax]
// 005466db  38592c               cmp byte ptr [ecx + 0x2c], bl
// 005466de  7517                 jne 0x5466f7
// 005466e0  c6402c00             mov byte ptr [eax + 0x2c], 0
// 005466e4  8b5504               mov edx, dword ptr [ebp + 4]
// 005466e7  8bfe                 mov edi, esi
// 005466e9  3b7a04               cmp edi, dword ptr [edx + 4]
// 005466ec  8b7604               mov esi, dword ptr [esi + 4]
// 005466ef  0f854dffffff         jne 0x546642
// 005466f5  eb2e                 jmp 0x546725
// 005466f7  8b08                 mov ecx, dword ptr [eax]
// 005466f9  38592c               cmp byte ptr [ecx + 0x2c], bl
// 005466fc  7511                 jne 0x54670f
// 005466fe  885a2c               mov byte ptr [edx + 0x2c], bl
// 00546701  50                   push eax
// 00546702  8bcd                 mov ecx, ebp
// 00546704  c6402c00             mov byte ptr [eax + 0x2c], 0
// 00546708  e883c6ffff           call 0x542d90
// 0054670d  8b06                 mov eax, dword ptr [esi]
// 0054670f  8a4e2c               mov cl, byte ptr [esi + 0x2c]
// 00546712  88482c               mov byte ptr [eax + 0x2c], cl
// 00546715  885e2c               mov byte ptr [esi + 0x2c], bl
// 00546718  8b10                 mov edx, dword ptr [eax]
// 0054671a  56                   push esi
// 0054671b  8bcd                 mov ecx, ebp
// 0054671d  885a2c               mov byte ptr [edx + 0x2c], bl
// 00546720  e83bbc0200           call 0x572360
// 00546725  885f2c               mov byte ptr [edi + 0x2c], bl
// 00546728  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0054672c  83c110               add ecx, 0x10
// 0054672f  ff158ce77700         call dword ptr [0x77e78c]
// 00546735  8b442410             mov eax, dword ptr [esp + 0x10]
// 00546739  50                   push eax
// 0054673a  e8b1790d00           call 0x61e0f0
// 0054673f  8b4508               mov eax, dword ptr [ebp + 8]
// 00546742  83c404               add esp, 4
// 00546745  85c0                 test eax, eax
// 00546747  5f                   pop edi
// 00546748  5e                   pop esi
// 00546749  5b                   pop ebx
// 0054674a  7606                 jbe 0x546752
// 0054674c  83c0ff               add eax, -1
// 0054674f  894508               mov dword ptr [ebp + 8], eax
// 00546752  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 00546756  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0054675a  8b542464             mov edx, dword ptr [esp + 0x64]
// 0054675e  8908                 mov dword ptr [eax], ecx
// 00546760  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00546764  895004               mov dword ptr [eax + 4], edx
// 00546767  5d                   pop ebp
// 00546768  64890d00000000       mov dword ptr fs:[0], ecx
// 0054676f  83c454               add esp, 0x54
// 00546772  c20c00               ret 0xc
// standard library map_int<string> (function ?erase@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@V312@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
