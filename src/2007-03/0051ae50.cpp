// from server: 100% by auto
// roc 2007-03 0051ae50  unit: seg_00510000  size: 764 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0051ae50
//
// 0051ae50  83ec10               sub esp, 0x10
// 0051ae53  817c241cff000000     cmp dword ptr [esp + 0x1c], 0xff
// 0051ae5b  7546                 jne 0x51aea3
// 0051ae5d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0051ae61  8a810b010000         mov al, byte ptr [ecx + 0x10b]
// 0051ae67  3c08                 cmp al, 8
// 0051ae69  0fb6c0               movzx eax, al
// 0051ae6c  720c                 jb 0x51ae7a
// 0051ae6e  c1e803               shr eax, 3
// 0051ae71  0faf81c8000000       imul eax, dword ptr [ecx + 0xc8]
// 0051ae78  eb0d                 jmp 0x51ae87
// 0051ae7a  0faf81c8000000       imul eax, dword ptr [ecx + 0xc8]
// 0051ae81  83c007               add eax, 7
// 0051ae84  c1e803               shr eax, 3
// 0051ae87  50                   push eax
// 0051ae88  8b81ec000000         mov eax, dword ptr [ecx + 0xec]
// 0051ae8e  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0051ae92  83c001               add eax, 1
// 0051ae95  50                   push eax
// 0051ae96  51                   push ecx
// 0051ae97  e846431000           call 0x61f1e2
// 0051ae9c  83c40c               add esp, 0xc
// 0051ae9f  83c410               add esp, 0x10
// 0051aea2  c3                   ret 
// 0051aea3  8b442414             mov eax, dword ptr [esp + 0x14]
// 0051aea7  0fb6880b010000       movzx ecx, byte ptr [eax + 0x10b]
// 0051aeae  53                   push ebx
// 0051aeaf  55                   push ebp
// 0051aeb0  56                   push esi
// 0051aeb1  8bb0ec000000         mov esi, dword ptr [eax + 0xec]
// 0051aeb7  8bd1                 mov edx, ecx
// 0051aeb9  83c601               add esi, 1
// 0051aebc  83ea01               sub edx, 1
// 0051aebf  57                   push edi
// 0051aec0  0f84d1010000         je 0x51b097
// 0051aec6  83ea01               sub edx, 1
// 0051aec9  0f8409010000         je 0x51afd8
// 0051aecf  83ea02               sub edx, 2
// 0051aed2  744e                 je 0x51af22
// 0051aed4  8b80c8000000         mov eax, dword ptr [eax + 0xc8]
// 0051aeda  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0051aede  c1e903               shr ecx, 3
// 0051aee1  85c0                 test eax, eax
// 0051aee3  8bf9                 mov edi, ecx
// 0051aee5  b380                 mov bl, 0x80
// 0051aee7  0f8657020000         jbe 0x51b144
// 0051aeed  89442410             mov dword ptr [esp + 0x10], eax
// 0051aef1  8a54242c             mov dl, byte ptr [esp + 0x2c]
// 0051aef5  84da                 test dl, bl
// 0051aef7  740b                 je 0x51af04
// 0051aef9  57                   push edi
// 0051aefa  56                   push esi
// 0051aefb  55                   push ebp
// 0051aefc  e8e1421000           call 0x61f1e2
// 0051af01  83c40c               add esp, 0xc
// 0051af04  03f7                 add esi, edi
// 0051af06  03ef                 add ebp, edi
// 0051af08  80fb01               cmp bl, 1
// 0051af0b  7504                 jne 0x51af11
// 0051af0d  b380                 mov bl, 0x80
// 0051af0f  eb02                 jmp 0x51af13
// 0051af11  d0eb                 shr bl, 1
// 0051af13  836c241001           sub dword ptr [esp + 0x10], 1
// 0051af18  75d7                 jne 0x51aef1
// 0051af1a  5f                   pop edi
// 0051af1b  5e                   pop esi
// 0051af1c  5d                   pop ebp
// 0051af1d  5b                   pop ebx
// 0051af1e  83c410               add esp, 0x10
// 0051af21  c3                   ret 
// 0051af22  f7407000000100       test dword ptr [eax + 0x70], 0x10000
// 0051af29  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0051af2d  8b88c8000000         mov ecx, dword ptr [eax + 0xc8]
// 0051af33  c744241080000000     mov dword ptr [esp + 0x10], 0x80
// 0051af3b  7411                 je 0x51af4e
// 0051af3d  b804000000           mov eax, 4
// 0051af42  33ed                 xor ebp, ebp
// 0051af44  89442414             mov dword ptr [esp + 0x14], eax
// 0051af48  89442418             mov dword ptr [esp + 0x18], eax
// 0051af4c  eb15                 jmp 0x51af63
// 0051af4e  bd04000000           mov ebp, 4
// 0051af53  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0051af5b  c7442418fcffffff     mov dword ptr [esp + 0x18], 0xfffffffc
// 0051af63  85c9                 test ecx, ecx
// 0051af65  8bd5                 mov edx, ebp
// 0051af67  0f86d7010000         jbe 0x51b144
// 0051af6d  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0051af71  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0051af75  85442410             test dword ptr [esp + 0x10], eax
// 0051af79  7422                 je 0x51af9d
// 0051af7b  0fb606               movzx eax, byte ptr [esi]
// 0051af7e  8aca                 mov cl, dl
// 0051af80  d3e8                 shr eax, cl
// 0051af82  b904000000           mov ecx, 4
// 0051af87  2bca                 sub ecx, edx
// 0051af89  bb0f0f0000           mov ebx, 0xf0f
// 0051af8e  d3fb                 sar ebx, cl
// 0051af90  83e00f               and eax, 0xf
// 0051af93  8bca                 mov ecx, edx
// 0051af95  d2e0                 shl al, cl
// 0051af97  221f                 and bl, byte ptr [edi]
// 0051af99  0ad8                 or bl, al
// 0051af9b  881f                 mov byte ptr [edi], bl
// 0051af9d  3b542414             cmp edx, dword ptr [esp + 0x14]
// 0051afa1  750a                 jne 0x51afad
// 0051afa3  83c601               add esi, 1
// 0051afa6  8bd5                 mov edx, ebp
// 0051afa8  83c701               add edi, 1
// 0051afab  eb04                 jmp 0x51afb1
// 0051afad  03542418             add edx, dword ptr [esp + 0x18]
// 0051afb1  b801000000           mov eax, 1
// 0051afb6  39442410             cmp dword ptr [esp + 0x10], eax
// 0051afba  750a                 jne 0x51afc6
// 0051afbc  c744241080000000     mov dword ptr [esp + 0x10], 0x80
// 0051afc4  eb04                 jmp 0x51afca
// 0051afc6  d17c2410             sar dword ptr [esp + 0x10], 1
// 0051afca  2944241c             sub dword ptr [esp + 0x1c], eax
// 0051afce  75a1                 jne 0x51af71
// 0051afd0  5f                   pop edi
// 0051afd1  5e                   pop esi
// 0051afd2  5d                   pop ebp
// 0051afd3  5b                   pop ebx
// 0051afd4  83c410               add esp, 0x10
// 0051afd7  c3                   ret 
// 0051afd8  f7407000000100       test dword ptr [eax + 0x70], 0x10000
// 0051afdf  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0051afe3  8b88c8000000         mov ecx, dword ptr [eax + 0xc8]
// 0051afe9  c744241080000000     mov dword ptr [esp + 0x10], 0x80
// 0051aff1  7414                 je 0x51b007
// 0051aff3  33ed                 xor ebp, ebp
// 0051aff5  c744241c06000000     mov dword ptr [esp + 0x1c], 6
// 0051affd  c744241802000000     mov dword ptr [esp + 0x18], 2
// 0051b005  eb15                 jmp 0x51b01c
// 0051b007  bd06000000           mov ebp, 6
// 0051b00c  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0051b014  c7442418feffffff     mov dword ptr [esp + 0x18], 0xfffffffe
// 0051b01c  85c9                 test ecx, ecx
// 0051b01e  8bd5                 mov edx, ebp
// 0051b020  0f861e010000         jbe 0x51b144
// 0051b026  894c2414             mov dword ptr [esp + 0x14], ecx
// 0051b02a  8d9b00000000         lea ebx, [ebx]
// 0051b030  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0051b034  854c2410             test dword ptr [esp + 0x10], ecx
// 0051b038  7422                 je 0x51b05c
// 0051b03a  0fb606               movzx eax, byte ptr [esi]
// 0051b03d  8aca                 mov cl, dl
// 0051b03f  d3e8                 shr eax, cl
// 0051b041  b906000000           mov ecx, 6
// 0051b046  2bca                 sub ecx, edx
// 0051b048  bb3f3f0000           mov ebx, 0x3f3f
// 0051b04d  d3fb                 sar ebx, cl
// 0051b04f  83e003               and eax, 3
// 0051b052  8bca                 mov ecx, edx
// 0051b054  d2e0                 shl al, cl
// 0051b056  221f                 and bl, byte ptr [edi]
// 0051b058  0ad8                 or bl, al
// 0051b05a  881f                 mov byte ptr [edi], bl
// 0051b05c  3b54241c             cmp edx, dword ptr [esp + 0x1c]
// 0051b060  750a                 jne 0x51b06c
// 0051b062  83c601               add esi, 1
// 0051b065  8bd5                 mov edx, ebp
// 0051b067  83c701               add edi, 1
// 0051b06a  eb04                 jmp 0x51b070
// 0051b06c  03542418             add edx, dword ptr [esp + 0x18]
// 0051b070  b801000000           mov eax, 1
// 0051b075  39442410             cmp dword ptr [esp + 0x10], eax
// 0051b079  750a                 jne 0x51b085
// 0051b07b  c744241080000000     mov dword ptr [esp + 0x10], 0x80
// 0051b083  eb04                 jmp 0x51b089
// 0051b085  d17c2410             sar dword ptr [esp + 0x10], 1
// 0051b089  29442414             sub dword ptr [esp + 0x14], eax
// 0051b08d  75a1                 jne 0x51b030
// 0051b08f  5f                   pop edi
// 0051b090  5e                   pop esi
// 0051b091  5d                   pop ebp
// 0051b092  5b                   pop ebx
// 0051b093  83c410               add esp, 0x10
// 0051b096  c3                   ret 
// 0051b097  f7407000000100       test dword ptr [eax + 0x70], 0x10000
// 0051b09e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0051b0a2  8b88c8000000         mov ecx, dword ptr [eax + 0xc8]
// 0051b0a8  c744241080000000     mov dword ptr [esp + 0x10], 0x80
// 0051b0b0  7414                 je 0x51b0c6
// 0051b0b2  33ed                 xor ebp, ebp
// 0051b0b4  c744241c07000000     mov dword ptr [esp + 0x1c], 7
// 0051b0bc  c744241801000000     mov dword ptr [esp + 0x18], 1
// 0051b0c4  eb15                 jmp 0x51b0db
// 0051b0c6  bd07000000           mov ebp, 7
// 0051b0cb  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0051b0d3  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0051b0db  85c9                 test ecx, ecx
// 0051b0dd  8bd5                 mov edx, ebp
// 0051b0df  7663                 jbe 0x51b144
// 0051b0e1  894c2414             mov dword ptr [esp + 0x14], ecx
// 0051b0e5  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0051b0e9  85442410             test dword ptr [esp + 0x10], eax
// 0051b0ed  7422                 je 0x51b111
// 0051b0ef  0fb606               movzx eax, byte ptr [esi]
// 0051b0f2  8aca                 mov cl, dl
// 0051b0f4  d3e8                 shr eax, cl
// 0051b0f6  b907000000           mov ecx, 7
// 0051b0fb  2bca                 sub ecx, edx
// 0051b0fd  bb7f7f0000           mov ebx, 0x7f7f
// 0051b102  d3fb                 sar ebx, cl
// 0051b104  83e001               and eax, 1
// 0051b107  8bca                 mov ecx, edx
// 0051b109  d2e0                 shl al, cl
// 0051b10b  221f                 and bl, byte ptr [edi]
// 0051b10d  0ad8                 or bl, al
// 0051b10f  881f                 mov byte ptr [edi], bl
// 0051b111  3b54241c             cmp edx, dword ptr [esp + 0x1c]
// 0051b115  750a                 jne 0x51b121
// 0051b117  83c601               add esi, 1
// 0051b11a  8bd5                 mov edx, ebp
// 0051b11c  83c701               add edi, 1
// 0051b11f  eb04                 jmp 0x51b125
// 0051b121  03542418             add edx, dword ptr [esp + 0x18]
// 0051b125  b801000000           mov eax, 1
// 0051b12a  39442410             cmp dword ptr [esp + 0x10], eax
// 0051b12e  750a                 jne 0x51b13a
// 0051b130  c744241080000000     mov dword ptr [esp + 0x10], 0x80
// 0051b138  eb04                 jmp 0x51b13e
// 0051b13a  d17c2410             sar dword ptr [esp + 0x10], 1
// 0051b13e  29442414             sub dword ptr [esp + 0x14], eax
// 0051b142  75a1                 jne 0x51b0e5
// 0051b144  5f                   pop edi
// 0051b145  5e                   pop esi
// 0051b146  5d                   pop ebp
// 0051b147  5b                   pop ebx
// 0051b148  83c410               add esp, 0x10
// 0051b14b  c3                   ret 
// library libpng-1.2.7/pngrutil.c (function _png_combine_row)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrutil.c
