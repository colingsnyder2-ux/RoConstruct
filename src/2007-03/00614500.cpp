// from server: 100% by auto
// roc 2007-03 00614500  unit: seg_00610000  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614500
//
// 00614500  55                   push ebp
// 00614501  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00614505  56                   push esi
// 00614506  8bf0                 mov esi, eax
// 00614508  83feff               cmp esi, -1
// 0061450b  7472                 je 0x61457f
// 0061450d  53                   push ebx
// 0061450e  b280                 mov dl, 0x80
// 00614510  57                   push edi
// 00614511  8b4500               mov eax, dword ptr [ebp]
// 00614514  8b400c               mov eax, dword ptr [eax + 0xc]
// 00614517  8d3cb500000000       lea edi, [esi*4]
// 0061451e  03c7                 add eax, edi
// 00614520  83fe01               cmp esi, 1
// 00614523  7c11                 jl 0x614536
// 00614525  8b58fc               mov ebx, dword ptr [eax - 4]
// 00614528  8d48fc               lea ecx, [eax - 4]
// 0061452b  83e33f               and ebx, 0x3f
// 0061452e  8493ac087c00         test byte ptr [ebx + 0x7c08ac], dl
// 00614534  7502                 jne 0x614538
// 00614536  8bc8                 mov ecx, eax
// 00614538  8b01                 mov eax, dword ptr [ecx]
// 0061453a  8bd8                 mov ebx, eax
// 0061453c  83e33f               and ebx, 0x3f
// 0061453f  80fb1b               cmp bl, 0x1b
// 00614542  751a                 jne 0x61455e
// 00614544  8bd8                 mov ebx, eax
// 00614546  81e3ffffb5ff         and ebx, 0xffb5ffff
// 0061454c  81cb00003400         or ebx, 0x340000
// 00614552  c1eb11               shr ebx, 0x11
// 00614555  2500c07f00           and eax, 0x7fc000
// 0061455a  0bd8                 or ebx, eax
// 0061455c  8919                 mov dword ptr [ecx], ebx
// 0061455e  8b4d00               mov ecx, dword ptr [ebp]
// 00614561  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00614564  8b0407               mov eax, dword ptr [edi + eax]
// 00614567  c1e80e               shr eax, 0xe
// 0061456a  2dffff0100           sub eax, 0x1ffff
// 0061456f  83f8ff               cmp eax, -1
// 00614572  7409                 je 0x61457d
// 00614574  8d740601             lea esi, [esi + eax + 1]
// 00614578  83feff               cmp esi, -1
// 0061457b  7594                 jne 0x614511
// 0061457d  5f                   pop edi
// 0061457e  5b                   pop ebx
// 0061457f  5e                   pop esi
// 00614580  5d                   pop ebp
// 00614581  c3                   ret 
// library lua-5.1.1/lcode.c (function _removevalues)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
