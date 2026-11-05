// from server: 100% by auto
// roc 2010-06 00564e50  unit: seg_00560000  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00564e50
//
// 00564e50  83ec08               sub esp, 8
// 00564e53  b00a                 mov al, 0xa
// 00564e55  88442405             mov byte ptr [esp + 5], al
// 00564e59  88442407             mov byte ptr [esp + 7], al
// 00564e5d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00564e61  c6042489             mov byte ptr [esp], 0x89
// 00564e65  c644240150           mov byte ptr [esp + 1], 0x50
// 00564e6a  c64424024e           mov byte ptr [esp + 2], 0x4e
// 00564e6f  c644240347           mov byte ptr [esp + 3], 0x47
// 00564e74  c64424040d           mov byte ptr [esp + 4], 0xd
// 00564e79  c64424061a           mov byte ptr [esp + 6], 0x1a
// 00564e7e  83f808               cmp eax, 8
// 00564e81  0f8698000000         jbe 0x564f1f
// 00564e87  b808000000           mov eax, 8
// 00564e8c  8b542410             mov edx, dword ptr [esp + 0x10]
// 00564e90  83fa07               cmp edx, 7
// 00564e93  0f878f000000         ja 0x564f28
// 00564e99  8d0c02               lea ecx, [edx + eax]
// 00564e9c  83f908               cmp ecx, 8
// 00564e9f  7607                 jbe 0x564ea8
// 00564ea1  b808000000           mov eax, 8
// 00564ea6  2bc2                 sub eax, edx
// 00564ea8  56                   push esi
// 00564ea9  57                   push edi
// 00564eaa  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00564eae  8d4c1408             lea ecx, [esp + edx + 8]
// 00564eb2  03d7                 add edx, edi
// 00564eb4  8bf0                 mov esi, eax
// 00564eb6  83f804               cmp eax, 4
// 00564eb9  7219                 jb 0x564ed4
// 00564ebb  eb03                 jmp 0x564ec0
// 00564ebd  8d4900               lea ecx, [ecx]
// 00564ec0  8b02                 mov eax, dword ptr [edx]
// 00564ec2  3b01                 cmp eax, dword ptr [ecx]
// 00564ec4  7512                 jne 0x564ed8
// 00564ec6  83ee04               sub esi, 4
// 00564ec9  83c104               add ecx, 4
// 00564ecc  83c204               add edx, 4
// 00564ecf  83fe04               cmp esi, 4
// 00564ed2  73ec                 jae 0x564ec0
// 00564ed4  85f6                 test esi, esi
// 00564ed6  7457                 je 0x564f2f
// 00564ed8  0fb602               movzx eax, byte ptr [edx]
// 00564edb  0fb639               movzx edi, byte ptr [ecx]
// 00564ede  2bc7                 sub eax, edi
// 00564ee0  7531                 jne 0x564f13
// 00564ee2  83fe01               cmp esi, 1
// 00564ee5  7648                 jbe 0x564f2f
// 00564ee7  0fb64201             movzx eax, byte ptr [edx + 1]
// 00564eeb  0fb67901             movzx edi, byte ptr [ecx + 1]
// 00564eef  2bc7                 sub eax, edi
// 00564ef1  7520                 jne 0x564f13
// 00564ef3  83fe02               cmp esi, 2
// 00564ef6  7637                 jbe 0x564f2f
// 00564ef8  0fb64202             movzx eax, byte ptr [edx + 2]
// 00564efc  0fb67902             movzx edi, byte ptr [ecx + 2]
// 00564f00  2bc7                 sub eax, edi
// 00564f02  750f                 jne 0x564f13
// 00564f04  83fe03               cmp esi, 3
// 00564f07  7626                 jbe 0x564f2f
// 00564f09  0fb64203             movzx eax, byte ptr [edx + 3]
// 00564f0d  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 00564f11  2bc1                 sub eax, ecx
// 00564f13  c1f81f               sar eax, 0x1f
// 00564f16  5f                   pop edi
// 00564f17  83c801               or eax, 1
// 00564f1a  5e                   pop esi
// 00564f1b  83c408               add esp, 8
// 00564f1e  c3                   ret 
// 00564f1f  83f801               cmp eax, 1
// 00564f22  0f8364ffffff         jae 0x564e8c
// 00564f28  83c8ff               or eax, 0xffffffff
// 00564f2b  83c408               add esp, 8
// 00564f2e  c3                   ret 
// 00564f2f  5f                   pop edi
// 00564f30  33c0                 xor eax, eax
// 00564f32  5e                   pop esi
// 00564f33  83c408               add esp, 8
// 00564f36  c3                   ret 
// library libpng-1.2.10/png.c (function _png_sig_cmp)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 png.c
