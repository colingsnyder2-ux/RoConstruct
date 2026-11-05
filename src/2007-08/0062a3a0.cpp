// from server: 100% by auto
// roc 2007-08 0062a3a0  unit: RBX::AssemblyStage  size: 709 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0062a3a0
//
// 0062a3a0  64a100000000         mov eax, dword ptr fs:[0]
// 0062a3a6  6aff                 push -1
// 0062a3a8  68b2417500           push 0x7541b2
// 0062a3ad  50                   push eax
// 0062a3ae  64892500000000       mov dword ptr fs:[0], esp
// 0062a3b5  8b442418             mov eax, dword ptr [esp + 0x18]
// 0062a3b9  83ec48               sub esp, 0x48
// 0062a3bc  80782900             cmp byte ptr [eax + 0x29], 0
// 0062a3c0  55                   push ebp
// 0062a3c1  8be9                 mov ebp, ecx
// 0062a3c3  7459                 je 0x62a41e
// 0062a3c5  68dc4e7800           push 0x784edc
// 0062a3ca  8d4c240c             lea ecx, [esp + 0xc]
// 0062a3ce  ff1598e67700         call dword ptr [0x77e698]
// 0062a3d4  8d4c2424             lea ecx, [esp + 0x24]
// 0062a3d8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0062a3e0  ff15f8e67700         call dword ptr [0x77e6f8]
// 0062a3e6  8d442408             lea eax, [esp + 8]
// 0062a3ea  50                   push eax
// 0062a3eb  8d4c2434             lea ecx, [esp + 0x34]
// 0062a3ef  c644245801           mov byte ptr [esp + 0x58], 1
// 0062a3f4  c7442428604e7800     mov dword ptr [esp + 0x28], 0x784e60
// 0062a3fc  ff159ce67700         call dword ptr [0x77e69c]
// 0062a402  6864f38300           push 0x83f364
// 0062a407  8d4c2428             lea ecx, [esp + 0x28]
// 0062a40b  51                   push ecx
// 0062a40c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 0062a411  c744242c784e7800     mov dword ptr [esp + 0x2c], 0x784e78
// 0062a419  e880670000           call 0x630b9e
// 0062a41e  53                   push ebx
// 0062a41f  56                   push esi
// 0062a420  8bd8                 mov ebx, eax
// 0062a422  57                   push edi
// 0062a423  8d4c246c             lea ecx, [esp + 0x6c]
// 0062a427  895c2410             mov dword ptr [esp + 0x10], ebx
// 0062a42b  e8b064eaff           call 0x4d08e0
// 0062a430  8b03                 mov eax, dword ptr [ebx]
// 0062a432  80782900             cmp byte ptr [eax + 0x29], 0
// 0062a436  7405                 je 0x62a43d
// 0062a438  8b7b08               mov edi, dword ptr [ebx + 8]
// 0062a43b  eb18                 jmp 0x62a455
// 0062a43d  8b5308               mov edx, dword ptr [ebx + 8]
// 0062a440  807a2900             cmp byte ptr [edx + 0x29], 0
// 0062a444  7404                 je 0x62a44a
// 0062a446  8bf8                 mov edi, eax
// 0062a448  eb0b                 jmp 0x62a455
// 0062a44a  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 0062a44e  3bcb                 cmp ecx, ebx
// 0062a450  8b7908               mov edi, dword ptr [ecx + 8]
// 0062a453  756b                 jne 0x62a4c0
// 0062a455  807f2900             cmp byte ptr [edi + 0x29], 0
// 0062a459  8b7304               mov esi, dword ptr [ebx + 4]
// 0062a45c  7503                 jne 0x62a461
// 0062a45e  897704               mov dword ptr [edi + 4], esi
// 0062a461  8b4504               mov eax, dword ptr [ebp + 4]
// 0062a464  395804               cmp dword ptr [eax + 4], ebx
// 0062a467  7505                 jne 0x62a46e
// 0062a469  897804               mov dword ptr [eax + 4], edi
// 0062a46c  eb0b                 jmp 0x62a479
// 0062a46e  391e                 cmp dword ptr [esi], ebx
// 0062a470  7504                 jne 0x62a476
// 0062a472  893e                 mov dword ptr [esi], edi
// 0062a474  eb03                 jmp 0x62a479
// 0062a476  897e08               mov dword ptr [esi + 8], edi
// 0062a479  8b5d04               mov ebx, dword ptr [ebp + 4]
// 0062a47c  8b03                 mov eax, dword ptr [ebx]
// 0062a47e  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0062a482  7515                 jne 0x62a499
// 0062a484  807f2900             cmp byte ptr [edi + 0x29], 0
// 0062a488  7404                 je 0x62a48e
// 0062a48a  8bc6                 mov eax, esi
// 0062a48c  eb09                 jmp 0x62a497
// 0062a48e  57                   push edi
// 0062a48f  e8bc5eeaff           call 0x4d0350
// 0062a494  83c404               add esp, 4
// 0062a497  8903                 mov dword ptr [ebx], eax
// 0062a499  8b5d04               mov ebx, dword ptr [ebp + 4]
// 0062a49c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0062a4a0  394b08               cmp dword ptr [ebx + 8], ecx
// 0062a4a3  7572                 jne 0x62a517
// 0062a4a5  807f2900             cmp byte ptr [edi + 0x29], 0
// 0062a4a9  7407                 je 0x62a4b2
// 0062a4ab  8bc6                 mov eax, esi
// 0062a4ad  894308               mov dword ptr [ebx + 8], eax
// 0062a4b0  eb65                 jmp 0x62a517
// 0062a4b2  57                   push edi
// 0062a4b3  e8b85eeaff           call 0x4d0370
// 0062a4b8  83c404               add esp, 4
// 0062a4bb  894308               mov dword ptr [ebx + 8], eax
// 0062a4be  eb57                 jmp 0x62a517
// 0062a4c0  894804               mov dword ptr [eax + 4], ecx
// 0062a4c3  8b13                 mov edx, dword ptr [ebx]
// 0062a4c5  8911                 mov dword ptr [ecx], edx
// 0062a4c7  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 0062a4ca  7504                 jne 0x62a4d0
// 0062a4cc  8bf1                 mov esi, ecx
// 0062a4ce  eb1a                 jmp 0x62a4ea
// 0062a4d0  807f2900             cmp byte ptr [edi + 0x29], 0
// 0062a4d4  8b7104               mov esi, dword ptr [ecx + 4]
// 0062a4d7  7503                 jne 0x62a4dc
// 0062a4d9  897704               mov dword ptr [edi + 4], esi
// 0062a4dc  893e                 mov dword ptr [esi], edi
// 0062a4de  8b4308               mov eax, dword ptr [ebx + 8]
// 0062a4e1  894108               mov dword ptr [ecx + 8], eax
// 0062a4e4  8b5308               mov edx, dword ptr [ebx + 8]
// 0062a4e7  894a04               mov dword ptr [edx + 4], ecx
// 0062a4ea  8b4504               mov eax, dword ptr [ebp + 4]
// 0062a4ed  395804               cmp dword ptr [eax + 4], ebx
// 0062a4f0  7505                 jne 0x62a4f7
// 0062a4f2  894804               mov dword ptr [eax + 4], ecx
// 0062a4f5  eb0e                 jmp 0x62a505
// 0062a4f7  8b4304               mov eax, dword ptr [ebx + 4]
// 0062a4fa  3918                 cmp dword ptr [eax], ebx
// 0062a4fc  7504                 jne 0x62a502
// 0062a4fe  8908                 mov dword ptr [eax], ecx
// 0062a500  eb03                 jmp 0x62a505
// 0062a502  894808               mov dword ptr [eax + 8], ecx
// 0062a505  8b4304               mov eax, dword ptr [ebx + 4]
// 0062a508  894104               mov dword ptr [ecx + 4], eax
// 0062a50b  8a5328               mov dl, byte ptr [ebx + 0x28]
// 0062a50e  8a4128               mov al, byte ptr [ecx + 0x28]
// 0062a511  885128               mov byte ptr [ecx + 0x28], dl
// 0062a514  884328               mov byte ptr [ebx + 0x28], al
// 0062a517  8b442410             mov eax, dword ptr [esp + 0x10]
// 0062a51b  b301                 mov bl, 1
// 0062a51d  385828               cmp byte ptr [eax + 0x28], bl
// 0062a520  0f85f2000000         jne 0x62a618
// 0062a526  8b4d04               mov ecx, dword ptr [ebp + 4]
// 0062a529  3b7904               cmp edi, dword ptr [ecx + 4]
// 0062a52c  0f84e3000000         je 0x62a615
// 0062a532  385f28               cmp byte ptr [edi + 0x28], bl
// 0062a535  0f85da000000         jne 0x62a615
// 0062a53b  8b06                 mov eax, dword ptr [esi]
// 0062a53d  3bf8                 cmp edi, eax
// 0062a53f  7563                 jne 0x62a5a4
// 0062a541  8b4608               mov eax, dword ptr [esi + 8]
// 0062a544  80782800             cmp byte ptr [eax + 0x28], 0
// 0062a548  7512                 jne 0x62a55c
// 0062a54a  885828               mov byte ptr [eax + 0x28], bl
// 0062a54d  56                   push esi
// 0062a54e  8bcd                 mov ecx, ebp
// 0062a550  c6462800             mov byte ptr [esi + 0x28], 0
// 0062a554  e83762eaff           call 0x4d0790
// 0062a559  8b4608               mov eax, dword ptr [esi + 8]
// 0062a55c  80782900             cmp byte ptr [eax + 0x29], 0
// 0062a560  7572                 jne 0x62a5d4
// 0062a562  8b10                 mov edx, dword ptr [eax]
// 0062a564  385a28               cmp byte ptr [edx + 0x28], bl
// 0062a567  7508                 jne 0x62a571
// 0062a569  8b4808               mov ecx, dword ptr [eax + 8]
// 0062a56c  385928               cmp byte ptr [ecx + 0x28], bl
// 0062a56f  745f                 je 0x62a5d0
// 0062a571  8b4808               mov ecx, dword ptr [eax + 8]
// 0062a574  385928               cmp byte ptr [ecx + 0x28], bl
// 0062a577  7512                 jne 0x62a58b
// 0062a579  885a28               mov byte ptr [edx + 0x28], bl
// 0062a57c  50                   push eax
// 0062a57d  8bcd                 mov ecx, ebp
// 0062a57f  c6402800             mov byte ptr [eax + 0x28], 0
// 0062a583  e8085deaff           call 0x4d0290
// 0062a588  8b4608               mov eax, dword ptr [esi + 8]
// 0062a58b  8a4e28               mov cl, byte ptr [esi + 0x28]
// 0062a58e  884828               mov byte ptr [eax + 0x28], cl
// 0062a591  885e28               mov byte ptr [esi + 0x28], bl
// 0062a594  8b5008               mov edx, dword ptr [eax + 8]
// 0062a597  56                   push esi
// 0062a598  8bcd                 mov ecx, ebp
// 0062a59a  885a28               mov byte ptr [edx + 0x28], bl
// 0062a59d  e8ee61eaff           call 0x4d0790
// 0062a5a2  eb71                 jmp 0x62a615
// 0062a5a4  80782800             cmp byte ptr [eax + 0x28], 0
// 0062a5a8  7511                 jne 0x62a5bb
// 0062a5aa  885828               mov byte ptr [eax + 0x28], bl
// 0062a5ad  56                   push esi
// 0062a5ae  8bcd                 mov ecx, ebp
// 0062a5b0  c6462800             mov byte ptr [esi + 0x28], 0
// 0062a5b4  e8d75ceaff           call 0x4d0290
// 0062a5b9  8b06                 mov eax, dword ptr [esi]
// 0062a5bb  80782900             cmp byte ptr [eax + 0x29], 0
// 0062a5bf  7513                 jne 0x62a5d4
// 0062a5c1  8b5008               mov edx, dword ptr [eax + 8]
// 0062a5c4  385a28               cmp byte ptr [edx + 0x28], bl
// 0062a5c7  751e                 jne 0x62a5e7
// 0062a5c9  8b08                 mov ecx, dword ptr [eax]
// 0062a5cb  385928               cmp byte ptr [ecx + 0x28], bl
// 0062a5ce  7517                 jne 0x62a5e7
// 0062a5d0  c6402800             mov byte ptr [eax + 0x28], 0
// 0062a5d4  8b5504               mov edx, dword ptr [ebp + 4]
// 0062a5d7  8bfe                 mov edi, esi
// 0062a5d9  3b7a04               cmp edi, dword ptr [edx + 4]
// 0062a5dc  8b7604               mov esi, dword ptr [esi + 4]
// 0062a5df  0f854dffffff         jne 0x62a532
// 0062a5e5  eb2e                 jmp 0x62a615
// 0062a5e7  8b08                 mov ecx, dword ptr [eax]
// 0062a5e9  385928               cmp byte ptr [ecx + 0x28], bl
// 0062a5ec  7511                 jne 0x62a5ff
// 0062a5ee  885a28               mov byte ptr [edx + 0x28], bl
// 0062a5f1  50                   push eax
// 0062a5f2  8bcd                 mov ecx, ebp
// 0062a5f4  c6402800             mov byte ptr [eax + 0x28], 0
// 0062a5f8  e89361eaff           call 0x4d0790
// 0062a5fd  8b06                 mov eax, dword ptr [esi]
// 0062a5ff  8a4e28               mov cl, byte ptr [esi + 0x28]
// 0062a602  884828               mov byte ptr [eax + 0x28], cl
// 0062a605  885e28               mov byte ptr [esi + 0x28], bl
// 0062a608  8b10                 mov edx, dword ptr [eax]
// 0062a60a  56                   push esi
// 0062a60b  8bcd                 mov ecx, ebp
// 0062a60d  885a28               mov byte ptr [edx + 0x28], bl
// 0062a610  e87b5ceaff           call 0x4d0290
// 0062a615  885f28               mov byte ptr [edi + 0x28], bl
// 0062a618  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0062a61c  83c10c               add ecx, 0xc
// 0062a61f  ff15ace67700         call dword ptr [0x77e6ac]
// 0062a625  8b442410             mov eax, dword ptr [esp + 0x10]
// 0062a629  50                   push eax
// 0062a62a  e833560000           call 0x62fc62
// 0062a62f  8b4508               mov eax, dword ptr [ebp + 8]
// 0062a632  83c404               add esp, 4
// 0062a635  85c0                 test eax, eax
// 0062a637  5f                   pop edi
// 0062a638  5e                   pop esi
// 0062a639  5b                   pop ebx
// 0062a63a  7606                 jbe 0x62a642
// 0062a63c  83c0ff               add eax, -1
// 0062a63f  894508               mov dword ptr [ebp + 8], eax
// 0062a642  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0062a646  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0062a64a  8b542464             mov edx, dword ptr [esp + 0x64]
// 0062a64e  8908                 mov dword ptr [eax], ecx
// 0062a650  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0062a654  895004               mov dword ptr [eax + 4], edx
// 0062a657  5d                   pop ebp
// 0062a658  64890d00000000       mov dword ptr fs:[0], ecx
// 0062a65f  83c454               add esp, 0x54
// 0062a662  c20c00               ret 0xc
// standard library set<string> (function ?erase@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@V312@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
