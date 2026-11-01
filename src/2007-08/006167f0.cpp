// from server: 100% by auto
// roc 2007-08 006167f0  unit: seg_00610000  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006167f0
//
// 006167f0  56                   push esi
// 006167f1  8b742408             mov esi, dword ptr [esp + 8]
// 006167f5  8b4634               mov eax, dword ptr [esi + 0x34]
// 006167f8  6683403401           add word ptr [eax + 0x34], 1
// 006167fd  8b4634               mov eax, dword ptr [esi + 0x34]
// 00616800  66817834c800         cmp word ptr [eax + 0x34], 0xc8
// 00616806  57                   push edi
// 00616807  7617                 jbe 0x616820
// 00616809  6a00                 push 0
// 0061680b  6830347c00           push 0x7c3430
// 00616810  56                   push esi
// 00616811  e80a0d0000           call 0x617520
// 00616816  83c40c               add esp, 0xc
// 00616819  8da42400000000       lea esp, [esp]
// 00616820  8b4610               mov eax, dword ptr [esi + 0x10]
// 00616823  05fcfeffff           add eax, 0xfffffefc
// 00616828  83f81b               cmp eax, 0x1b
// 0061682b  770e                 ja 0x61683b
// 0061682d  0fb68878686100       movzx ecx, byte ptr [eax + 0x616878]
// 00616834  ff248d70686100       jmp dword ptr [ecx*4 + 0x616870]
// 0061683b  8bc6                 mov eax, esi
// 0061683d  e85efeffff           call 0x6166a0
// 00616842  837e103b             cmp dword ptr [esi + 0x10], 0x3b
// 00616846  8bf8                 mov edi, eax
// 00616848  7509                 jne 0x616853
// 0061684a  56                   push esi
// 0061684b  e8a0210000           call 0x6189f0
// 00616850  83c404               add esp, 4
// 00616853  85ff                 test edi, edi
// 00616855  8b4630               mov eax, dword ptr [esi + 0x30]
// 00616858  0fb65032             movzx edx, byte ptr [eax + 0x32]
// 0061685c  895024               mov dword ptr [eax + 0x24], edx
// 0061685f  74bf                 je 0x616820
// 00616861  8b7634               mov esi, dword ptr [esi + 0x34]
// 00616864  66814634ffff         add word ptr [esi + 0x34], 0xffff
// 0061686a  5f                   pop edi
// 0061686b  5e                   pop esi
// 0061686c  c3                   ret 
// 0061686d  8d4900               lea ecx, [ecx]
// 00616870  61                   popal 
// 00616871  6861003b68           push 0x683b0061
// 00616876  61                   popal 
// 00616877  0000                 add byte ptr [eax], al
// 00616879  0000                 add byte ptr [eax], al
// 0061687b  0101                 add dword ptr [ecx], eax
// 0061687d  0101                 add dword ptr [ecx], eax
// 0061687f  0101                 add dword ptr [ecx], eax
// 00616881  0101                 add dword ptr [ecx], eax
// 00616883  0101                 add dword ptr [ecx], eax
// 00616885  0101                 add dword ptr [ecx], eax
// 00616887  0100                 add dword ptr [eax], eax
// 00616889  0101                 add dword ptr [ecx], eax
// 0061688b  0101                 add dword ptr [ecx], eax
// 0061688d  0101                 add dword ptr [ecx], eax
// 0061688f  0101                 add dword ptr [ecx], eax
// 00616891  0101                 add dword ptr [ecx], eax
// library lua-5.1/lparser.c (function _chunk)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
