// from server: 100% by auto
// roc 2007-08 005df2c0  unit: RBX::VMotorFeature::?$FactoryProduct  size: 696 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005df2c0
//
// 005df2c0  64a100000000         mov eax, dword ptr fs:[0]
// 005df2c6  6aff                 push -1
// 005df2c8  68b2417500           push 0x7541b2
// 005df2cd  50                   push eax
// 005df2ce  64892500000000       mov dword ptr fs:[0], esp
// 005df2d5  8b442418             mov eax, dword ptr [esp + 0x18]
// 005df2d9  83ec48               sub esp, 0x48
// 005df2dc  80781900             cmp byte ptr [eax + 0x19], 0
// 005df2e0  55                   push ebp
// 005df2e1  8be9                 mov ebp, ecx
// 005df2e3  7459                 je 0x5df33e
// 005df2e5  68dc4e7800           push 0x784edc
// 005df2ea  8d4c240c             lea ecx, [esp + 0xc]
// 005df2ee  ff1598e67700         call dword ptr [0x77e698]
// 005df2f4  8d4c2424             lea ecx, [esp + 0x24]
// 005df2f8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 005df300  ff15f8e67700         call dword ptr [0x77e6f8]
// 005df306  8d442408             lea eax, [esp + 8]
// 005df30a  50                   push eax
// 005df30b  8d4c2434             lea ecx, [esp + 0x34]
// 005df30f  c644245801           mov byte ptr [esp + 0x58], 1
// 005df314  c7442428604e7800     mov dword ptr [esp + 0x28], 0x784e60
// 005df31c  ff159ce67700         call dword ptr [0x77e69c]
// 005df322  6864f38300           push 0x83f364
// 005df327  8d4c2428             lea ecx, [esp + 0x28]
// 005df32b  51                   push ecx
// 005df32c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 005df331  c744242c784e7800     mov dword ptr [esp + 0x2c], 0x784e78
// 005df339  e860180500           call 0x630b9e
// 005df33e  53                   push ebx
// 005df33f  56                   push esi
// 005df340  8bd8                 mov ebx, eax
// 005df342  57                   push edi
// 005df343  8d4c246c             lea ecx, [esp + 0x6c]
// 005df347  895c2410             mov dword ptr [esp + 0x10], ebx
// 005df34b  e87089faff           call 0x587cc0
// 005df350  8b03                 mov eax, dword ptr [ebx]
// 005df352  80781900             cmp byte ptr [eax + 0x19], 0
// 005df356  7405                 je 0x5df35d
// 005df358  8b7b08               mov edi, dword ptr [ebx + 8]
// 005df35b  eb18                 jmp 0x5df375
// 005df35d  8b5308               mov edx, dword ptr [ebx + 8]
// 005df360  807a1900             cmp byte ptr [edx + 0x19], 0
// 005df364  7404                 je 0x5df36a
// 005df366  8bf8                 mov edi, eax
// 005df368  eb0b                 jmp 0x5df375
// 005df36a  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 005df36e  3bcb                 cmp ecx, ebx
// 005df370  8b7908               mov edi, dword ptr [ecx + 8]
// 005df373  756b                 jne 0x5df3e0
// 005df375  807f1900             cmp byte ptr [edi + 0x19], 0
// 005df379  8b7304               mov esi, dword ptr [ebx + 4]
// 005df37c  7503                 jne 0x5df381
// 005df37e  897704               mov dword ptr [edi + 4], esi
// 005df381  8b4504               mov eax, dword ptr [ebp + 4]
// 005df384  395804               cmp dword ptr [eax + 4], ebx
// 005df387  7505                 jne 0x5df38e
// 005df389  897804               mov dword ptr [eax + 4], edi
// 005df38c  eb0b                 jmp 0x5df399
// 005df38e  391e                 cmp dword ptr [esi], ebx
// 005df390  7504                 jne 0x5df396
// 005df392  893e                 mov dword ptr [esi], edi
// 005df394  eb03                 jmp 0x5df399
// 005df396  897e08               mov dword ptr [esi + 8], edi
// 005df399  8b5d04               mov ebx, dword ptr [ebp + 4]
// 005df39c  8b03                 mov eax, dword ptr [ebx]
// 005df39e  3b442410             cmp eax, dword ptr [esp + 0x10]
// 005df3a2  7515                 jne 0x5df3b9
// 005df3a4  807f1900             cmp byte ptr [edi + 0x19], 0
// 005df3a8  7404                 je 0x5df3ae
// 005df3aa  8bc6                 mov eax, esi
// 005df3ac  eb09                 jmp 0x5df3b7
// 005df3ae  57                   push edi
// 005df3af  e85c88faff           call 0x587c10
// 005df3b4  83c404               add esp, 4
// 005df3b7  8903                 mov dword ptr [ebx], eax
// 005df3b9  8b5d04               mov ebx, dword ptr [ebp + 4]
// 005df3bc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005df3c0  394b08               cmp dword ptr [ebx + 8], ecx
// 005df3c3  7572                 jne 0x5df437
// 005df3c5  807f1900             cmp byte ptr [edi + 0x19], 0
// 005df3c9  7407                 je 0x5df3d2
// 005df3cb  8bc6                 mov eax, esi
// 005df3cd  894308               mov dword ptr [ebx + 8], eax
// 005df3d0  eb65                 jmp 0x5df437
// 005df3d2  57                   push edi
// 005df3d3  e81888faff           call 0x587bf0
// 005df3d8  83c404               add esp, 4
// 005df3db  894308               mov dword ptr [ebx + 8], eax
// 005df3de  eb57                 jmp 0x5df437
// 005df3e0  894804               mov dword ptr [eax + 4], ecx
// 005df3e3  8b13                 mov edx, dword ptr [ebx]
// 005df3e5  8911                 mov dword ptr [ecx], edx
// 005df3e7  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 005df3ea  7504                 jne 0x5df3f0
// 005df3ec  8bf1                 mov esi, ecx
// 005df3ee  eb1a                 jmp 0x5df40a
// 005df3f0  807f1900             cmp byte ptr [edi + 0x19], 0
// 005df3f4  8b7104               mov esi, dword ptr [ecx + 4]
// 005df3f7  7503                 jne 0x5df3fc
// 005df3f9  897704               mov dword ptr [edi + 4], esi
// 005df3fc  893e                 mov dword ptr [esi], edi
// 005df3fe  8b4308               mov eax, dword ptr [ebx + 8]
// 005df401  894108               mov dword ptr [ecx + 8], eax
// 005df404  8b5308               mov edx, dword ptr [ebx + 8]
// 005df407  894a04               mov dword ptr [edx + 4], ecx
// 005df40a  8b4504               mov eax, dword ptr [ebp + 4]
// 005df40d  395804               cmp dword ptr [eax + 4], ebx
// 005df410  7505                 jne 0x5df417
// 005df412  894804               mov dword ptr [eax + 4], ecx
// 005df415  eb0e                 jmp 0x5df425
// 005df417  8b4304               mov eax, dword ptr [ebx + 4]
// 005df41a  3918                 cmp dword ptr [eax], ebx
// 005df41c  7504                 jne 0x5df422
// 005df41e  8908                 mov dword ptr [eax], ecx
// 005df420  eb03                 jmp 0x5df425
// 005df422  894808               mov dword ptr [eax + 8], ecx
// 005df425  8b4304               mov eax, dword ptr [ebx + 4]
// 005df428  894104               mov dword ptr [ecx + 4], eax
// 005df42b  8a5318               mov dl, byte ptr [ebx + 0x18]
// 005df42e  8a4118               mov al, byte ptr [ecx + 0x18]
// 005df431  885118               mov byte ptr [ecx + 0x18], dl
// 005df434  884318               mov byte ptr [ebx + 0x18], al
// 005df437  8b442410             mov eax, dword ptr [esp + 0x10]
// 005df43b  b301                 mov bl, 1
// 005df43d  385818               cmp byte ptr [eax + 0x18], bl
// 005df440  0f85f2000000         jne 0x5df538
// 005df446  8b4d04               mov ecx, dword ptr [ebp + 4]
// 005df449  3b7904               cmp edi, dword ptr [ecx + 4]
// 005df44c  0f84e3000000         je 0x5df535
// 005df452  385f18               cmp byte ptr [edi + 0x18], bl
// 005df455  0f85da000000         jne 0x5df535
// 005df45b  8b06                 mov eax, dword ptr [esi]
// 005df45d  3bf8                 cmp edi, eax
// 005df45f  7563                 jne 0x5df4c4
// 005df461  8b4608               mov eax, dword ptr [esi + 8]
// 005df464  80781800             cmp byte ptr [eax + 0x18], 0
// 005df468  7512                 jne 0x5df47c
// 005df46a  885818               mov byte ptr [eax + 0x18], bl
// 005df46d  56                   push esi
// 005df46e  8bcd                 mov ecx, ebp
// 005df470  c6461800             mov byte ptr [esi + 0x18], 0
// 005df474  e847f0ffff           call 0x5de4c0
// 005df479  8b4608               mov eax, dword ptr [esi + 8]
// 005df47c  80781900             cmp byte ptr [eax + 0x19], 0
// 005df480  7572                 jne 0x5df4f4
// 005df482  8b10                 mov edx, dword ptr [eax]
// 005df484  385a18               cmp byte ptr [edx + 0x18], bl
// 005df487  7508                 jne 0x5df491
// 005df489  8b4808               mov ecx, dword ptr [eax + 8]
// 005df48c  385918               cmp byte ptr [ecx + 0x18], bl
// 005df48f  745f                 je 0x5df4f0
// 005df491  8b4808               mov ecx, dword ptr [eax + 8]
// 005df494  385918               cmp byte ptr [ecx + 0x18], bl
// 005df497  7512                 jne 0x5df4ab
// 005df499  885a18               mov byte ptr [edx + 0x18], bl
// 005df49c  50                   push eax
// 005df49d  8bcd                 mov ecx, ebp
// 005df49f  c6401800             mov byte ptr [eax + 0x18], 0
// 005df4a3  e8e8ffe2ff           call 0x40f490
// 005df4a8  8b4608               mov eax, dword ptr [esi + 8]
// 005df4ab  8a4e18               mov cl, byte ptr [esi + 0x18]
// 005df4ae  884818               mov byte ptr [eax + 0x18], cl
// 005df4b1  885e18               mov byte ptr [esi + 0x18], bl
// 005df4b4  8b5008               mov edx, dword ptr [eax + 8]
// 005df4b7  56                   push esi
// 005df4b8  8bcd                 mov ecx, ebp
// 005df4ba  885a18               mov byte ptr [edx + 0x18], bl
// 005df4bd  e8feefffff           call 0x5de4c0
// 005df4c2  eb71                 jmp 0x5df535
// 005df4c4  80781800             cmp byte ptr [eax + 0x18], 0
// 005df4c8  7511                 jne 0x5df4db
// 005df4ca  885818               mov byte ptr [eax + 0x18], bl
// 005df4cd  56                   push esi
// 005df4ce  8bcd                 mov ecx, ebp
// 005df4d0  c6461800             mov byte ptr [esi + 0x18], 0
// 005df4d4  e8b7ffe2ff           call 0x40f490
// 005df4d9  8b06                 mov eax, dword ptr [esi]
// 005df4db  80781900             cmp byte ptr [eax + 0x19], 0
// 005df4df  7513                 jne 0x5df4f4
// 005df4e1  8b5008               mov edx, dword ptr [eax + 8]
// 005df4e4  385a18               cmp byte ptr [edx + 0x18], bl
// 005df4e7  751e                 jne 0x5df507
// 005df4e9  8b08                 mov ecx, dword ptr [eax]
// 005df4eb  385918               cmp byte ptr [ecx + 0x18], bl
// 005df4ee  7517                 jne 0x5df507
// 005df4f0  c6401800             mov byte ptr [eax + 0x18], 0
// 005df4f4  8b5504               mov edx, dword ptr [ebp + 4]
// 005df4f7  8bfe                 mov edi, esi
// 005df4f9  3b7a04               cmp edi, dword ptr [edx + 4]
// 005df4fc  8b7604               mov esi, dword ptr [esi + 4]
// 005df4ff  0f854dffffff         jne 0x5df452
// 005df505  eb2e                 jmp 0x5df535
// 005df507  8b08                 mov ecx, dword ptr [eax]
// 005df509  385918               cmp byte ptr [ecx + 0x18], bl
// 005df50c  7511                 jne 0x5df51f
// 005df50e  885a18               mov byte ptr [edx + 0x18], bl
// 005df511  50                   push eax
// 005df512  8bcd                 mov ecx, ebp
// 005df514  c6401800             mov byte ptr [eax + 0x18], 0
// 005df518  e8a3efffff           call 0x5de4c0
// 005df51d  8b06                 mov eax, dword ptr [esi]
// 005df51f  8a4e18               mov cl, byte ptr [esi + 0x18]
// 005df522  884818               mov byte ptr [eax + 0x18], cl
// 005df525  885e18               mov byte ptr [esi + 0x18], bl
// 005df528  8b10                 mov edx, dword ptr [eax]
// 005df52a  56                   push esi
// 005df52b  8bcd                 mov ecx, ebp
// 005df52d  885a18               mov byte ptr [edx + 0x18], bl
// 005df530  e85bffe2ff           call 0x40f490
// 005df535  885f18               mov byte ptr [edi + 0x18], bl
// 005df538  8b442410             mov eax, dword ptr [esp + 0x10]
// 005df53c  50                   push eax
// 005df53d  e820070500           call 0x62fc62
// 005df542  8b4508               mov eax, dword ptr [ebp + 8]
// 005df545  83c404               add esp, 4
// 005df548  85c0                 test eax, eax
// 005df54a  5f                   pop edi
// 005df54b  5e                   pop esi
// 005df54c  5b                   pop ebx
// 005df54d  7606                 jbe 0x5df555
// 005df54f  83c0ff               add eax, -1
// 005df552  894508               mov dword ptr [ebp + 8], eax
// 005df555  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 005df559  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 005df55d  8b542464             mov edx, dword ptr [esp + 0x64]
// 005df561  8908                 mov dword ptr [eax], ecx
// 005df563  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005df567  895004               mov dword ptr [eax + 4], edx
// 005df56a  5d                   pop ebp
// 005df56b  64890d00000000       mov dword ptr fs:[0], ecx
// 005df572  83c454               add esp, 0x54
// 005df575  c20c00               ret 0xc
// standard library set<double> (function ?erase@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@QAE?AViterator@12@V312@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
