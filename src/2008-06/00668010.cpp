// from server: 100% by auto
// roc 2008-06 00668010  unit: RBX::HUMAN::GettingUp  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00668010
//
// 00668010  64a100000000         mov eax, dword ptr fs:[0]
// 00668016  6aff                 push -1
// 00668018  6842e87d00           push 0x7de842
// 0066801d  50                   push eax
// 0066801e  64892500000000       mov dword ptr fs:[0], esp
// 00668025  83ec44               sub esp, 0x44
// 00668028  57                   push edi
// 00668029  8bf9                 mov edi, ecx
// 0066802b  817f1cfeffff1f       cmp dword ptr [edi + 0x1c], 0x1ffffffe
// 00668032  7259                 jb 0x66808d
// 00668034  688cb28000           push 0x80b28c
// 00668039  8d4c2408             lea ecx, [esp + 8]
// 0066803d  ff1558248000         call dword ptr [0x802458]
// 00668043  8d4c2420             lea ecx, [esp + 0x20]
// 00668047  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0066804f  ff1598288000         call dword ptr [0x802898]
// 00668055  8d442404             lea eax, [esp + 4]
// 00668059  50                   push eax
// 0066805a  8d4c2430             lea ecx, [esp + 0x30]
// 0066805e  c644245401           mov byte ptr [esp + 0x54], 1
// 00668063  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 0066806b  ff155c248000         call dword ptr [0x80245c]
// 00668071  68c00c8d00           push 0x8d0cc0
// 00668076  8d4c2424             lea ecx, [esp + 0x24]
// 0066807a  51                   push ecx
// 0066807b  c644245800           mov byte ptr [esp + 0x58], 0
// 00668080  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 00668088  e8ff940300           call 0x6a158c
// 0066808d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00668091  8b4718               mov eax, dword ptr [edi + 0x18]
// 00668094  53                   push ebx
// 00668095  55                   push ebp
// 00668096  56                   push esi
// 00668097  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0066809b  6a00                 push 0
// 0066809d  52                   push edx
// 0066809e  50                   push eax
// 0066809f  56                   push esi
// 006680a0  50                   push eax
// 006680a1  e84acffaff           call 0x614ff0
// 006680a6  8be8                 mov ebp, eax
// 006680a8  8b4718               mov eax, dword ptr [edi + 0x18]
// 006680ab  bb01000000           mov ebx, 1
// 006680b0  015f1c               add dword ptr [edi + 0x1c], ebx
// 006680b3  3bf0                 cmp esi, eax
// 006680b5  7510                 jne 0x6680c7
// 006680b7  896804               mov dword ptr [eax + 4], ebp
// 006680ba  8b4718               mov eax, dword ptr [edi + 0x18]
// 006680bd  8928                 mov dword ptr [eax], ebp
// 006680bf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006680c2  896908               mov dword ptr [ecx + 8], ebp
// 006680c5  eb22                 jmp 0x6680e9
// 006680c7  807c246800           cmp byte ptr [esp + 0x68], 0
// 006680cc  740d                 je 0x6680db
// 006680ce  892e                 mov dword ptr [esi], ebp
// 006680d0  8b4718               mov eax, dword ptr [edi + 0x18]
// 006680d3  3b30                 cmp esi, dword ptr [eax]
// 006680d5  7512                 jne 0x6680e9
// 006680d7  8928                 mov dword ptr [eax], ebp
// 006680d9  eb0e                 jmp 0x6680e9
// 006680db  896e08               mov dword ptr [esi + 8], ebp
// 006680de  8b4718               mov eax, dword ptr [edi + 0x18]
// 006680e1  3b7008               cmp esi, dword ptr [eax + 8]
// 006680e4  7503                 jne 0x6680e9
// 006680e6  896808               mov dword ptr [eax + 8], ebp
// 006680e9  8b5504               mov edx, dword ptr [ebp + 4]
// 006680ec  807a1400             cmp byte ptr [edx + 0x14], 0
// 006680f0  8d4504               lea eax, [ebp + 4]
// 006680f3  8bf5                 mov esi, ebp
// 006680f5  0f85ea000000         jne 0x6681e5
// 006680fb  eb03                 jmp 0x668100
// 006680fd  8d4900               lea ecx, [ecx]
// 00668100  8b08                 mov ecx, dword ptr [eax]
// 00668102  8b5104               mov edx, dword ptr [ecx + 4]
// 00668105  3b0a                 cmp ecx, dword ptr [edx]
// 00668107  7551                 jne 0x66815a
// 00668109  8b5208               mov edx, dword ptr [edx + 8]
// 0066810c  807a1400             cmp byte ptr [edx + 0x14], 0
// 00668110  7519                 jne 0x66812b
// 00668112  885914               mov byte ptr [ecx + 0x14], bl
// 00668115  885a14               mov byte ptr [edx + 0x14], bl
// 00668118  8b10                 mov edx, dword ptr [eax]
// 0066811a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0066811d  c6411400             mov byte ptr [ecx + 0x14], 0
// 00668121  8b10                 mov edx, dword ptr [eax]
// 00668123  8b7204               mov esi, dword ptr [edx + 4]
// 00668126  e9aa000000           jmp 0x6681d5
// 0066812b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0066812e  750a                 jne 0x66813a
// 00668130  8bf1                 mov esi, ecx
// 00668132  56                   push esi
// 00668133  8bcf                 mov ecx, edi
// 00668135  e866d1ddff           call 0x4452a0
// 0066813a  8b4604               mov eax, dword ptr [esi + 4]
// 0066813d  885814               mov byte ptr [eax + 0x14], bl
// 00668140  8b4e04               mov ecx, dword ptr [esi + 4]
// 00668143  8b5104               mov edx, dword ptr [ecx + 4]
// 00668146  c6421400             mov byte ptr [edx + 0x14], 0
// 0066814a  8b4604               mov eax, dword ptr [esi + 4]
// 0066814d  8b4804               mov ecx, dword ptr [eax + 4]
// 00668150  51                   push ecx
// 00668151  8bcf                 mov ecx, edi
// 00668153  e8e8eaf4ff           call 0x5b6c40
// 00668158  eb7b                 jmp 0x6681d5
// 0066815a  8b12                 mov edx, dword ptr [edx]
// 0066815c  807a1400             cmp byte ptr [edx + 0x14], 0
// 00668160  7516                 jne 0x668178
// 00668162  885914               mov byte ptr [ecx + 0x14], bl
// 00668165  885a14               mov byte ptr [edx + 0x14], bl
// 00668168  8b10                 mov edx, dword ptr [eax]
// 0066816a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0066816d  c6411400             mov byte ptr [ecx + 0x14], 0
// 00668171  8b10                 mov edx, dword ptr [eax]
// 00668173  8b7204               mov esi, dword ptr [edx + 4]
// 00668176  eb5d                 jmp 0x6681d5
// 00668178  3b31                 cmp esi, dword ptr [ecx]
// 0066817a  750a                 jne 0x668186
// 0066817c  8bf1                 mov esi, ecx
// 0066817e  56                   push esi
// 0066817f  8bcf                 mov ecx, edi
// 00668181  e8baeaf4ff           call 0x5b6c40
// 00668186  8b4604               mov eax, dword ptr [esi + 4]
// 00668189  885814               mov byte ptr [eax + 0x14], bl
// 0066818c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0066818f  8b5104               mov edx, dword ptr [ecx + 4]
// 00668192  c6421400             mov byte ptr [edx + 0x14], 0
// 00668196  8b4604               mov eax, dword ptr [esi + 4]
// 00668199  8b4004               mov eax, dword ptr [eax + 4]
// 0066819c  8b4808               mov ecx, dword ptr [eax + 8]
// 0066819f  8b11                 mov edx, dword ptr [ecx]
// 006681a1  895008               mov dword ptr [eax + 8], edx
// 006681a4  8b11                 mov edx, dword ptr [ecx]
// 006681a6  807a1500             cmp byte ptr [edx + 0x15], 0
// 006681aa  7503                 jne 0x6681af
// 006681ac  894204               mov dword ptr [edx + 4], eax
// 006681af  8b5004               mov edx, dword ptr [eax + 4]
// 006681b2  895104               mov dword ptr [ecx + 4], edx
// 006681b5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006681b8  3b4204               cmp eax, dword ptr [edx + 4]
// 006681bb  7505                 jne 0x6681c2
// 006681bd  894a04               mov dword ptr [edx + 4], ecx
// 006681c0  eb0e                 jmp 0x6681d0
// 006681c2  8b5004               mov edx, dword ptr [eax + 4]
// 006681c5  3b02                 cmp eax, dword ptr [edx]
// 006681c7  7504                 jne 0x6681cd
// 006681c9  890a                 mov dword ptr [edx], ecx
// 006681cb  eb03                 jmp 0x6681d0
// 006681cd  894a08               mov dword ptr [edx + 8], ecx
// 006681d0  8901                 mov dword ptr [ecx], eax
// 006681d2  894804               mov dword ptr [eax + 4], ecx
// 006681d5  8b4e04               mov ecx, dword ptr [esi + 4]
// 006681d8  80791400             cmp byte ptr [ecx + 0x14], 0
// 006681dc  8d4604               lea eax, [esi + 4]
// 006681df  0f841bffffff         je 0x668100
// 006681e5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006681e8  8b4204               mov eax, dword ptr [edx + 4]
// 006681eb  885814               mov byte ptr [eax + 0x14], bl
// 006681ee  8b442464             mov eax, dword ptr [esp + 0x64]
// 006681f2  8b0f                 mov ecx, dword ptr [edi]
// 006681f4  5e                   pop esi
// 006681f5  896804               mov dword ptr [eax + 4], ebp
// 006681f8  5d                   pop ebp
// 006681f9  8908                 mov dword ptr [eax], ecx
// 006681fb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006681ff  5b                   pop ebx
// 00668200  5f                   pop edi
// 00668201  64890d00000000       mov dword ptr fs:[0], ecx
// 00668208  83c450               add esp, 0x50
// 0066820b  c21000               ret 0x10
// standard library map_int<ptr> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
