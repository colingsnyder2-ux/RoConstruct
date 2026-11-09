// from server: 100% by auto
// roc 2012-06 0063dd00  unit: seg_00630000  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0063dd00
//
// 0063dd00  83ec08               sub esp, 8
// 0063dd03  b00a                 mov al, 0xa
// 0063dd05  88442405             mov byte ptr [esp + 5], al
// 0063dd09  88442407             mov byte ptr [esp + 7], al
// 0063dd0d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0063dd11  c6042489             mov byte ptr [esp], 0x89
// 0063dd15  c644240150           mov byte ptr [esp + 1], 0x50
// 0063dd1a  c64424024e           mov byte ptr [esp + 2], 0x4e
// 0063dd1f  c644240347           mov byte ptr [esp + 3], 0x47
// 0063dd24  c64424040d           mov byte ptr [esp + 4], 0xd
// 0063dd29  c64424061a           mov byte ptr [esp + 6], 0x1a
// 0063dd2e  83f808               cmp eax, 8
// 0063dd31  0f8698000000         jbe 0x63ddcf
// 0063dd37  b808000000           mov eax, 8
// 0063dd3c  8b542410             mov edx, dword ptr [esp + 0x10]
// 0063dd40  83fa07               cmp edx, 7
// 0063dd43  0f878f000000         ja 0x63ddd8
// 0063dd49  8d0c02               lea ecx, [edx + eax]
// 0063dd4c  83f908               cmp ecx, 8
// 0063dd4f  7607                 jbe 0x63dd58
// 0063dd51  b808000000           mov eax, 8
// 0063dd56  2bc2                 sub eax, edx
// 0063dd58  56                   push esi
// 0063dd59  57                   push edi
// 0063dd5a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0063dd5e  8d4c1408             lea ecx, [esp + edx + 8]
// 0063dd62  03d7                 add edx, edi
// 0063dd64  8bf0                 mov esi, eax
// 0063dd66  83f804               cmp eax, 4
// 0063dd69  7219                 jb 0x63dd84
// 0063dd6b  eb03                 jmp 0x63dd70
// 0063dd6d  8d4900               lea ecx, [ecx]
// 0063dd70  8b02                 mov eax, dword ptr [edx]
// 0063dd72  3b01                 cmp eax, dword ptr [ecx]
// 0063dd74  7512                 jne 0x63dd88
// 0063dd76  83ee04               sub esi, 4
// 0063dd79  83c104               add ecx, 4
// 0063dd7c  83c204               add edx, 4
// 0063dd7f  83fe04               cmp esi, 4
// 0063dd82  73ec                 jae 0x63dd70
// 0063dd84  85f6                 test esi, esi
// 0063dd86  7457                 je 0x63dddf
// 0063dd88  0fb602               movzx eax, byte ptr [edx]
// 0063dd8b  0fb639               movzx edi, byte ptr [ecx]
// 0063dd8e  2bc7                 sub eax, edi
// 0063dd90  7531                 jne 0x63ddc3
// 0063dd92  83fe01               cmp esi, 1
// 0063dd95  7648                 jbe 0x63dddf
// 0063dd97  0fb64201             movzx eax, byte ptr [edx + 1]
// 0063dd9b  0fb67901             movzx edi, byte ptr [ecx + 1]
// 0063dd9f  2bc7                 sub eax, edi
// 0063dda1  7520                 jne 0x63ddc3
// 0063dda3  83fe02               cmp esi, 2
// 0063dda6  7637                 jbe 0x63dddf
// 0063dda8  0fb64202             movzx eax, byte ptr [edx + 2]
// 0063ddac  0fb67902             movzx edi, byte ptr [ecx + 2]
// 0063ddb0  2bc7                 sub eax, edi
// 0063ddb2  750f                 jne 0x63ddc3
// 0063ddb4  83fe03               cmp esi, 3
// 0063ddb7  7626                 jbe 0x63dddf
// 0063ddb9  0fb64203             movzx eax, byte ptr [edx + 3]
// 0063ddbd  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 0063ddc1  2bc1                 sub eax, ecx
// 0063ddc3  c1f81f               sar eax, 0x1f
// 0063ddc6  5f                   pop edi
// 0063ddc7  83c801               or eax, 1
// 0063ddca  5e                   pop esi
// 0063ddcb  83c408               add esp, 8
// 0063ddce  c3                   ret 
// 0063ddcf  83f801               cmp eax, 1
// 0063ddd2  0f8364ffffff         jae 0x63dd3c
// 0063ddd8  83c8ff               or eax, 0xffffffff
// 0063dddb  83c408               add esp, 8
// 0063ddde  c3                   ret 
// 0063dddf  5f                   pop edi
// 0063dde0  33c0                 xor eax, eax
// 0063dde2  5e                   pop esi
// 0063dde3  83c408               add esp, 8
// 0063dde6  c3                   ret 
// library libpng-1.2.10/png.c (function _png_sig_cmp)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 png.c
