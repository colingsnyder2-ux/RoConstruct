// from server: 100% by auto
// roc 2011-06 005506c0  unit: seg_00550000  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005506c0
//
// 005506c0  83ec08               sub esp, 8
// 005506c3  b00a                 mov al, 0xa
// 005506c5  88442405             mov byte ptr [esp + 5], al
// 005506c9  88442407             mov byte ptr [esp + 7], al
// 005506cd  8b442414             mov eax, dword ptr [esp + 0x14]
// 005506d1  c6042489             mov byte ptr [esp], 0x89
// 005506d5  c644240150           mov byte ptr [esp + 1], 0x50
// 005506da  c64424024e           mov byte ptr [esp + 2], 0x4e
// 005506df  c644240347           mov byte ptr [esp + 3], 0x47
// 005506e4  c64424040d           mov byte ptr [esp + 4], 0xd
// 005506e9  c64424061a           mov byte ptr [esp + 6], 0x1a
// 005506ee  83f808               cmp eax, 8
// 005506f1  0f8698000000         jbe 0x55078f
// 005506f7  b808000000           mov eax, 8
// 005506fc  8b542410             mov edx, dword ptr [esp + 0x10]
// 00550700  83fa07               cmp edx, 7
// 00550703  0f878f000000         ja 0x550798
// 00550709  8d0c02               lea ecx, [edx + eax]
// 0055070c  83f908               cmp ecx, 8
// 0055070f  7607                 jbe 0x550718
// 00550711  b808000000           mov eax, 8
// 00550716  2bc2                 sub eax, edx
// 00550718  56                   push esi
// 00550719  57                   push edi
// 0055071a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0055071e  8d4c1408             lea ecx, [esp + edx + 8]
// 00550722  03d7                 add edx, edi
// 00550724  8bf0                 mov esi, eax
// 00550726  83f804               cmp eax, 4
// 00550729  7219                 jb 0x550744
// 0055072b  eb03                 jmp 0x550730
// 0055072d  8d4900               lea ecx, [ecx]
// 00550730  8b02                 mov eax, dword ptr [edx]
// 00550732  3b01                 cmp eax, dword ptr [ecx]
// 00550734  7512                 jne 0x550748
// 00550736  83ee04               sub esi, 4
// 00550739  83c104               add ecx, 4
// 0055073c  83c204               add edx, 4
// 0055073f  83fe04               cmp esi, 4
// 00550742  73ec                 jae 0x550730
// 00550744  85f6                 test esi, esi
// 00550746  7457                 je 0x55079f
// 00550748  0fb602               movzx eax, byte ptr [edx]
// 0055074b  0fb639               movzx edi, byte ptr [ecx]
// 0055074e  2bc7                 sub eax, edi
// 00550750  7531                 jne 0x550783
// 00550752  83fe01               cmp esi, 1
// 00550755  7648                 jbe 0x55079f
// 00550757  0fb64201             movzx eax, byte ptr [edx + 1]
// 0055075b  0fb67901             movzx edi, byte ptr [ecx + 1]
// 0055075f  2bc7                 sub eax, edi
// 00550761  7520                 jne 0x550783
// 00550763  83fe02               cmp esi, 2
// 00550766  7637                 jbe 0x55079f
// 00550768  0fb64202             movzx eax, byte ptr [edx + 2]
// 0055076c  0fb67902             movzx edi, byte ptr [ecx + 2]
// 00550770  2bc7                 sub eax, edi
// 00550772  750f                 jne 0x550783
// 00550774  83fe03               cmp esi, 3
// 00550777  7626                 jbe 0x55079f
// 00550779  0fb64203             movzx eax, byte ptr [edx + 3]
// 0055077d  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 00550781  2bc1                 sub eax, ecx
// 00550783  c1f81f               sar eax, 0x1f
// 00550786  5f                   pop edi
// 00550787  83c801               or eax, 1
// 0055078a  5e                   pop esi
// 0055078b  83c408               add esp, 8
// 0055078e  c3                   ret 
// 0055078f  83f801               cmp eax, 1
// 00550792  0f8364ffffff         jae 0x5506fc
// 00550798  83c8ff               or eax, 0xffffffff
// 0055079b  83c408               add esp, 8
// 0055079e  c3                   ret 
// 0055079f  5f                   pop edi
// 005507a0  33c0                 xor eax, eax
// 005507a2  5e                   pop esi
// 005507a3  83c408               add esp, 8
// 005507a6  c3                   ret 
// library libpng-1.2.10/png.c (function _png_sig_cmp)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 png.c
