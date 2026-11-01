// from server: 100% by auto
// roc 2007-03 00601490  unit: seg_00600000  size: 340 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00601490
//
// 00601490  83ec5c               sub esp, 0x5c
// 00601493  53                   push ebx
// 00601494  55                   push ebp
// 00601495  57                   push edi
// 00601496  8b3e                 mov edi, dword ptr [esi]
// 00601498  33ed                 xor ebp, ebp
// 0060149a  57                   push edi
// 0060149b  8bde                 mov ebx, esi
// 0060149d  896c2410             mov dword ptr [esp + 0x10], ebp
// 006014a1  897c2418             mov dword ptr [esp + 0x18], edi
// 006014a5  e806f9ffff           call 0x600db0
// 006014aa  8b4638               mov eax, dword ptr [esi + 0x38]
// 006014ad  8b08                 mov ecx, dword ptr [eax]
// 006014af  83c404               add esp, 4
// 006014b2  85c9                 test ecx, ecx
// 006014b4  8d51ff               lea edx, [ecx - 1]
// 006014b7  8910                 mov dword ptr [eax], edx
// 006014b9  7611                 jbe 0x6014cc
// 006014bb  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 006014be  8b5104               mov edx, dword ptr [ecx + 4]
// 006014c1  0fb602               movzx eax, byte ptr [edx]
// 006014c4  83c201               add edx, 1
// 006014c7  895104               mov dword ptr [ecx + 4], edx
// 006014ca  eb0c                 jmp 0x6014d8
// 006014cc  8b4638               mov eax, dword ptr [esi + 0x38]
// 006014cf  50                   push eax
// 006014d0  e8cbb7ffff           call 0x5fcca0
// 006014d5  83c404               add esp, 4
// 006014d8  83f83d               cmp eax, 0x3d
// 006014db  8906                 mov dword ptr [esi], eax
// 006014dd  0f85e8000000         jne 0x6015cb
// 006014e3  bd01000000           mov ebp, 1
// 006014e8  eb06                 jmp 0x6014f0
// 006014ea  8d9b00000000         lea ebx, [ebx]
// 006014f0  8b7e3c               mov edi, dword ptr [esi + 0x3c]
// 006014f3  8b5704               mov edx, dword ptr [edi + 4]
// 006014f6  8b4708               mov eax, dword ptr [edi + 8]
// 006014f9  8b0e                 mov ecx, dword ptr [esi]
// 006014fb  03d5                 add edx, ebp
// 006014fd  3bd0                 cmp edx, eax
// 006014ff  894c2410             mov dword ptr [esp + 0x10], ecx
// 00601503  7676                 jbe 0x60157b
// 00601505  3dfeffff7f           cmp eax, 0x7ffffffe
// 0060150a  723d                 jb 0x601549
// 0060150c  8b4640               mov eax, dword ptr [esi + 0x40]
// 0060150f  6a50                 push 0x50
// 00601511  83c010               add eax, 0x10
// 00601514  50                   push eax
// 00601515  8d4c2420             lea ecx, [esp + 0x20]
// 00601519  51                   push ecx
// 0060151a  e84173ffff           call 0x5f8860
// 0060151f  8b5604               mov edx, dword ptr [esi + 4]
// 00601522  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00601525  68e8097c00           push 0x7c09e8
// 0060152a  52                   push edx
// 0060152b  8d44242c             lea eax, [esp + 0x2c]
// 0060152f  50                   push eax
// 00601530  686c9a7b00           push 0x7b9a6c
// 00601535  51                   push ecx
// 00601536  e80573ffff           call 0x5f8840
// 0060153b  8b5634               mov edx, dword ptr [esi + 0x34]
// 0060153e  6a03                 push 3
// 00601540  52                   push edx
// 00601541  e8baecfbff           call 0x5c0200
// 00601546  83c428               add esp, 0x28
// 00601549  8b4708               mov eax, dword ptr [edi + 8]
// 0060154c  8d1c00               lea ebx, [eax + eax]
// 0060154f  8d4b01               lea ecx, [ebx + 1]
// 00601552  83f9fd               cmp ecx, -3
// 00601555  7713                 ja 0x60156a
// 00601557  8b17                 mov edx, dword ptr [edi]
// 00601559  53                   push ebx
// 0060155a  50                   push eax
// 0060155b  8b4634               mov eax, dword ptr [esi + 0x34]
// 0060155e  52                   push edx
// 0060155f  50                   push eax
// 00601560  e83bbeffff           call 0x5fd3a0
// 00601565  83c410               add esp, 0x10
// 00601568  eb0c                 jmp 0x601576
// 0060156a  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0060156d  51                   push ecx
// 0060156e  e80dbeffff           call 0x5fd380
// 00601573  83c404               add esp, 4
// 00601576  8907                 mov dword ptr [edi], eax
// 00601578  895f08               mov dword ptr [edi + 8], ebx
// 0060157b  8b4704               mov eax, dword ptr [edi + 4]
// 0060157e  8b17                 mov edx, dword ptr [edi]
// 00601580  8a4c2410             mov cl, byte ptr [esp + 0x10]
// 00601584  880c02               mov byte ptr [edx + eax], cl
// 00601587  016f04               add dword ptr [edi + 4], ebp
// 0060158a  8b4638               mov eax, dword ptr [esi + 0x38]
// 0060158d  8b08                 mov ecx, dword ptr [eax]
// 0060158f  85c9                 test ecx, ecx
// 00601591  8d51ff               lea edx, [ecx - 1]
// 00601594  8910                 mov dword ptr [eax], edx
// 00601596  7610                 jbe 0x6015a8
// 00601598  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 0060159b  8b5104               mov edx, dword ptr [ecx + 4]
// 0060159e  0fb602               movzx eax, byte ptr [edx]
// 006015a1  03d5                 add edx, ebp
// 006015a3  895104               mov dword ptr [ecx + 4], edx
// 006015a6  eb0c                 jmp 0x6015b4
// 006015a8  8b4638               mov eax, dword ptr [esi + 0x38]
// 006015ab  50                   push eax
// 006015ac  e8efb6ffff           call 0x5fcca0
// 006015b1  83c404               add esp, 4
// 006015b4  016c240c             add dword ptr [esp + 0xc], ebp
// 006015b8  83f83d               cmp eax, 0x3d
// 006015bb  8906                 mov dword ptr [esi], eax
// 006015bd  0f842dffffff         je 0x6014f0
// 006015c3  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006015c7  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 006015cb  393e                 cmp dword ptr [esi], edi
// 006015cd  7509                 jne 0x6015d8
// 006015cf  5f                   pop edi
// 006015d0  8bc5                 mov eax, ebp
// 006015d2  5d                   pop ebp
// 006015d3  5b                   pop ebx
// 006015d4  83c45c               add esp, 0x5c
// 006015d7  c3                   ret 
// 006015d8  83c8ff               or eax, 0xffffffff
// 006015db  5f                   pop edi
// 006015dc  2bc5                 sub eax, ebp
// 006015de  5d                   pop ebp
// 006015df  5b                   pop ebx
// 006015e0  83c45c               add esp, 0x5c
// 006015e3  c3                   ret 
// library lua-5.1.1/llex.c (function _skip_sep)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 llex.c
