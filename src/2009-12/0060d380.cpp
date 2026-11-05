// from server: 100% by auto
// roc 2009-12 0060d380  unit: seg_00600000  size: 678 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060d380
//
// 0060d380  83ec28               sub esp, 0x28
// 0060d383  837c243c04           cmp dword ptr [esp + 0x3c], 4
// 0060d388  56                   push esi
// 0060d389  8b742430             mov esi, dword ptr [esp + 0x30]
// 0060d38d  c644241870           mov byte ptr [esp + 0x18], 0x70
// 0060d392  c644241943           mov byte ptr [esp + 0x19], 0x43
// 0060d397  c644241a41           mov byte ptr [esp + 0x1a], 0x41
// 0060d39c  c644241b4c           mov byte ptr [esp + 0x1b], 0x4c
// 0060d3a1  c644241c00           mov byte ptr [esp + 0x1c], 0
// 0060d3a6  7c0e                 jl 0x60d3b6
// 0060d3a8  68a85b9c00           push 0x9c5ba8
// 0060d3ad  56                   push esi
// 0060d3ae  e88d2e0000           call 0x610240
// 0060d3b3  83c408               add esp, 8
// 0060d3b6  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0060d3ba  53                   push ebx
// 0060d3bb  55                   push ebp
// 0060d3bc  57                   push edi
// 0060d3bd  8d442410             lea eax, [esp + 0x10]
// 0060d3c1  50                   push eax
// 0060d3c2  51                   push ecx
// 0060d3c3  56                   push esi
// 0060d3c4  e8a7fbffff           call 0x60cf70
// 0060d3c9  8be8                 mov ebp, eax
// 0060d3cb  8b442460             mov eax, dword ptr [esp + 0x60]
// 0060d3cf  83c40c               add esp, 0xc
// 0060d3d2  45                   inc ebp
// 0060d3d3  896c2418             mov dword ptr [esp + 0x18], ebp
// 0060d3d7  8d4801               lea ecx, [eax + 1]
// 0060d3da  8d9b00000000         lea ebx, [ebx]
// 0060d3e0  8a10                 mov dl, byte ptr [eax]
// 0060d3e2  40                   inc eax
// 0060d3e3  84d2                 test dl, dl
// 0060d3e5  75f9                 jne 0x60d3e0
// 0060d3e7  8b5c2450             mov ebx, dword ptr [esp + 0x50]
// 0060d3eb  2bc1                 sub eax, ecx
// 0060d3ed  33d2                 xor edx, edx
// 0060d3ef  85db                 test ebx, ebx
// 0060d3f1  0f95c2               setne dl
// 0060d3f4  8d0c9d00000000       lea ecx, [ebx*4]
// 0060d3fb  51                   push ecx
// 0060d3fc  56                   push esi
// 0060d3fd  03d0                 add edx, eax
// 0060d3ff  8bfa                 mov edi, edx
// 0060d401  8d442f0a             lea eax, [edi + ebp + 0xa]
// 0060d405  897c2424             mov dword ptr [esp + 0x24], edi
// 0060d409  89442444             mov dword ptr [esp + 0x44], eax
// 0060d40d  e86e380000           call 0x610c80
// 0060d412  83c408               add esp, 8
// 0060d415  33c9                 xor ecx, ecx
// 0060d417  89442450             mov dword ptr [esp + 0x50], eax
// 0060d41b  85db                 test ebx, ebx
// 0060d41d  7e50                 jle 0x60d46f
// 0060d41f  8b542458             mov edx, dword ptr [esp + 0x58]
// 0060d423  2bd0                 sub edx, eax
// 0060d425  8bf8                 mov edi, eax
// 0060d427  89542414             mov dword ptr [esp + 0x14], edx
// 0060d42b  eb07                 jmp 0x60d434
// 0060d42d  8d4900               lea ecx, [ecx]
// 0060d430  8b542414             mov edx, dword ptr [esp + 0x14]
// 0060d434  8b043a               mov eax, dword ptr [edx + edi]
// 0060d437  8d6801               lea ebp, [eax + 1]
// 0060d43a  8d9b00000000         lea ebx, [ebx]
// 0060d440  8a10                 mov dl, byte ptr [eax]
// 0060d442  40                   inc eax
// 0060d443  84d2                 test dl, dl
// 0060d445  75f9                 jne 0x60d440
// 0060d447  2bc5                 sub eax, ebp
// 0060d449  8be8                 mov ebp, eax
// 0060d44b  33d2                 xor edx, edx
// 0060d44d  8d43ff               lea eax, [ebx - 1]
// 0060d450  3bc8                 cmp ecx, eax
// 0060d452  0f95c2               setne dl
// 0060d455  41                   inc ecx
// 0060d456  83c704               add edi, 4
// 0060d459  8d042a               lea eax, [edx + ebp]
// 0060d45c  0144243c             add dword ptr [esp + 0x3c], eax
// 0060d460  3bcb                 cmp ecx, ebx
// 0060d462  8947fc               mov dword ptr [edi - 4], eax
// 0060d465  7cc9                 jl 0x60d430
// 0060d467  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0060d46b  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0060d46f  85f6                 test esi, esi
// 0060d471  747b                 je 0x60d4ee
// 0060d473  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0060d477  8bc8                 mov ecx, eax
// 0060d479  c1e918               shr ecx, 0x18
// 0060d47c  884c241c             mov byte ptr [esp + 0x1c], cl
// 0060d480  8bd0                 mov edx, eax
// 0060d482  8bc8                 mov ecx, eax
// 0060d484  c1ea10               shr edx, 0x10
// 0060d487  8844241f             mov byte ptr [esp + 0x1f], al
// 0060d48b  6a08                 push 8
// 0060d48d  8d442420             lea eax, [esp + 0x20]
// 0060d491  88542421             mov byte ptr [esp + 0x21], dl
// 0060d495  8b542428             mov edx, dword ptr [esp + 0x28]
// 0060d499  50                   push eax
// 0060d49a  c1e908               shr ecx, 8
// 0060d49d  56                   push esi
// 0060d49e  884c242a             mov byte ptr [esp + 0x2a], cl
// 0060d4a2  8954242c             mov dword ptr [esp + 0x2c], edx
// 0060d4a6  e8e55effff           call 0x603390
// 0060d4ab  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0060d4af  56                   push esi
// 0060d4b0  898e1c010000         mov dword ptr [esi + 0x11c], ecx
// 0060d4b6  e89561ffff           call 0x603650
// 0060d4bb  6a04                 push 4
// 0060d4bd  8d542438             lea edx, [esp + 0x38]
// 0060d4c1  52                   push edx
// 0060d4c2  56                   push esi
// 0060d4c3  e8a861ffff           call 0x603670
// 0060d4c8  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0060d4cc  83c41c               add esp, 0x1c
// 0060d4cf  85c0                 test eax, eax
// 0060d4d1  741b                 je 0x60d4ee
// 0060d4d3  85ed                 test ebp, ebp
// 0060d4d5  7617                 jbe 0x60d4ee
// 0060d4d7  55                   push ebp
// 0060d4d8  50                   push eax
// 0060d4d9  56                   push esi
// 0060d4da  e8b15effff           call 0x603390
// 0060d4df  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0060d4e3  55                   push ebp
// 0060d4e4  50                   push eax
// 0060d4e5  56                   push esi
// 0060d4e6  e88561ffff           call 0x603670
// 0060d4eb  83c418               add esp, 0x18
// 0060d4ee  8b442444             mov eax, dword ptr [esp + 0x44]
// 0060d4f2  8bc8                 mov ecx, eax
// 0060d4f4  c1f918               sar ecx, 0x18
// 0060d4f7  884c242c             mov byte ptr [esp + 0x2c], cl
// 0060d4fb  8bd0                 mov edx, eax
// 0060d4fd  c1fa10               sar edx, 0x10
// 0060d500  8bc8                 mov ecx, eax
// 0060d502  8854242d             mov byte ptr [esp + 0x2d], dl
// 0060d506  8844242f             mov byte ptr [esp + 0x2f], al
// 0060d50a  8b442448             mov eax, dword ptr [esp + 0x48]
// 0060d50e  c1f908               sar ecx, 8
// 0060d511  8bd0                 mov edx, eax
// 0060d513  c1fa18               sar edx, 0x18
// 0060d516  884c242e             mov byte ptr [esp + 0x2e], cl
// 0060d51a  88542430             mov byte ptr [esp + 0x30], dl
// 0060d51e  8bc8                 mov ecx, eax
// 0060d520  8bd0                 mov edx, eax
// 0060d522  c1f910               sar ecx, 0x10
// 0060d525  c1fa08               sar edx, 8
// 0060d528  88442433             mov byte ptr [esp + 0x33], al
// 0060d52c  8a44244c             mov al, byte ptr [esp + 0x4c]
// 0060d530  884c2431             mov byte ptr [esp + 0x31], cl
// 0060d534  88542432             mov byte ptr [esp + 0x32], dl
// 0060d538  88442434             mov byte ptr [esp + 0x34], al
// 0060d53c  885c2435             mov byte ptr [esp + 0x35], bl
// 0060d540  85f6                 test esi, esi
// 0060d542  743c                 je 0x60d580
// 0060d544  6a0a                 push 0xa
// 0060d546  8d4c2430             lea ecx, [esp + 0x30]
// 0060d54a  51                   push ecx
// 0060d54b  56                   push esi
// 0060d54c  e83f5effff           call 0x603390
// 0060d551  6a0a                 push 0xa
// 0060d553  8d54243c             lea edx, [esp + 0x3c]
// 0060d557  52                   push edx
// 0060d558  56                   push esi
// 0060d559  e81261ffff           call 0x603670
// 0060d55e  8b6c246c             mov ebp, dword ptr [esp + 0x6c]
// 0060d562  83c418               add esp, 0x18
// 0060d565  85ed                 test ebp, ebp
// 0060d567  7417                 je 0x60d580
// 0060d569  85ff                 test edi, edi
// 0060d56b  7613                 jbe 0x60d580
// 0060d56d  57                   push edi
// 0060d56e  55                   push ebp
// 0060d56f  56                   push esi
// 0060d570  e81b5effff           call 0x603390
// 0060d575  57                   push edi
// 0060d576  55                   push ebp
// 0060d577  56                   push esi
// 0060d578  e8f360ffff           call 0x603670
// 0060d57d  83c418               add esp, 0x18
// 0060d580  8b442410             mov eax, dword ptr [esp + 0x10]
// 0060d584  50                   push eax
// 0060d585  56                   push esi
// 0060d586  e855370000           call 0x610ce0
// 0060d58b  83c408               add esp, 8
// 0060d58e  85db                 test ebx, ebx
// 0060d590  7e45                 jle 0x60d5d7
// 0060d592  8b6c2458             mov ebp, dword ptr [esp + 0x58]
// 0060d596  8b442450             mov eax, dword ptr [esp + 0x50]
// 0060d59a  2bc5                 sub eax, ebp
// 0060d59c  8944243c             mov dword ptr [esp + 0x3c], eax
// 0060d5a0  895c244c             mov dword ptr [esp + 0x4c], ebx
// 0060d5a4  8b1c28               mov ebx, dword ptr [eax + ebp]
// 0060d5a7  8b7d00               mov edi, dword ptr [ebp]
// 0060d5aa  85f6                 test esi, esi
// 0060d5ac  741f                 je 0x60d5cd
// 0060d5ae  85ff                 test edi, edi
// 0060d5b0  741b                 je 0x60d5cd
// 0060d5b2  85db                 test ebx, ebx
// 0060d5b4  7617                 jbe 0x60d5cd
// 0060d5b6  53                   push ebx
// 0060d5b7  57                   push edi
// 0060d5b8  56                   push esi
// 0060d5b9  e8d25dffff           call 0x603390
// 0060d5be  53                   push ebx
// 0060d5bf  57                   push edi
// 0060d5c0  56                   push esi
// 0060d5c1  e8aa60ffff           call 0x603670
// 0060d5c6  8b442454             mov eax, dword ptr [esp + 0x54]
// 0060d5ca  83c418               add esp, 0x18
// 0060d5cd  83c504               add ebp, 4
// 0060d5d0  836c244c01           sub dword ptr [esp + 0x4c], 1
// 0060d5d5  75cd                 jne 0x60d5a4
// 0060d5d7  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 0060d5db  51                   push ecx
// 0060d5dc  56                   push esi
// 0060d5dd  e8fe360000           call 0x610ce0
// 0060d5e2  83c408               add esp, 8
// 0060d5e5  5f                   pop edi
// 0060d5e6  5d                   pop ebp
// 0060d5e7  5b                   pop ebx
// 0060d5e8  85f6                 test esi, esi
// 0060d5ea  7435                 je 0x60d621
// 0060d5ec  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0060d5f2  8bd0                 mov edx, eax
// 0060d5f4  c1ea18               shr edx, 0x18
// 0060d5f7  88542440             mov byte ptr [esp + 0x40], dl
// 0060d5fb  8bc8                 mov ecx, eax
// 0060d5fd  8bd0                 mov edx, eax
// 0060d5ff  88442443             mov byte ptr [esp + 0x43], al
// 0060d603  6a04                 push 4
// 0060d605  8d442444             lea eax, [esp + 0x44]
// 0060d609  50                   push eax
// 0060d60a  c1e910               shr ecx, 0x10
// 0060d60d  c1ea08               shr edx, 8
// 0060d610  56                   push esi
// 0060d611  884c244d             mov byte ptr [esp + 0x4d], cl
// 0060d615  8854244e             mov byte ptr [esp + 0x4e], dl
// 0060d619  e8725dffff           call 0x603390
// 0060d61e  83c40c               add esp, 0xc
// 0060d621  5e                   pop esi
// 0060d622  83c428               add esp, 0x28
// 0060d625  c3                   ret 
// library libpng-1.2.32/pngwutil.c (function _png_write_pCAL)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngwutil.c
