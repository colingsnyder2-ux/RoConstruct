// from server: 100% by auto
// roc 2009-12 006034e0  unit: seg_00600000  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006034e0
//
// 006034e0  83ec08               sub esp, 8
// 006034e3  b00a                 mov al, 0xa
// 006034e5  88442405             mov byte ptr [esp + 5], al
// 006034e9  88442407             mov byte ptr [esp + 7], al
// 006034ed  8b442414             mov eax, dword ptr [esp + 0x14]
// 006034f1  c6042489             mov byte ptr [esp], 0x89
// 006034f5  c644240150           mov byte ptr [esp + 1], 0x50
// 006034fa  c64424024e           mov byte ptr [esp + 2], 0x4e
// 006034ff  c644240347           mov byte ptr [esp + 3], 0x47
// 00603504  c64424040d           mov byte ptr [esp + 4], 0xd
// 00603509  c64424061a           mov byte ptr [esp + 6], 0x1a
// 0060350e  83f808               cmp eax, 8
// 00603511  0f8698000000         jbe 0x6035af
// 00603517  b808000000           mov eax, 8
// 0060351c  8b542410             mov edx, dword ptr [esp + 0x10]
// 00603520  83fa07               cmp edx, 7
// 00603523  0f878f000000         ja 0x6035b8
// 00603529  8d0c02               lea ecx, [edx + eax]
// 0060352c  83f908               cmp ecx, 8
// 0060352f  7607                 jbe 0x603538
// 00603531  b808000000           mov eax, 8
// 00603536  2bc2                 sub eax, edx
// 00603538  56                   push esi
// 00603539  57                   push edi
// 0060353a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0060353e  8d4c1408             lea ecx, [esp + edx + 8]
// 00603542  03d7                 add edx, edi
// 00603544  8bf0                 mov esi, eax
// 00603546  83f804               cmp eax, 4
// 00603549  7219                 jb 0x603564
// 0060354b  eb03                 jmp 0x603550
// 0060354d  8d4900               lea ecx, [ecx]
// 00603550  8b02                 mov eax, dword ptr [edx]
// 00603552  3b01                 cmp eax, dword ptr [ecx]
// 00603554  7512                 jne 0x603568
// 00603556  83ee04               sub esi, 4
// 00603559  83c104               add ecx, 4
// 0060355c  83c204               add edx, 4
// 0060355f  83fe04               cmp esi, 4
// 00603562  73ec                 jae 0x603550
// 00603564  85f6                 test esi, esi
// 00603566  7457                 je 0x6035bf
// 00603568  0fb602               movzx eax, byte ptr [edx]
// 0060356b  0fb639               movzx edi, byte ptr [ecx]
// 0060356e  2bc7                 sub eax, edi
// 00603570  7531                 jne 0x6035a3
// 00603572  83fe01               cmp esi, 1
// 00603575  7648                 jbe 0x6035bf
// 00603577  0fb64201             movzx eax, byte ptr [edx + 1]
// 0060357b  0fb67901             movzx edi, byte ptr [ecx + 1]
// 0060357f  2bc7                 sub eax, edi
// 00603581  7520                 jne 0x6035a3
// 00603583  83fe02               cmp esi, 2
// 00603586  7637                 jbe 0x6035bf
// 00603588  0fb64202             movzx eax, byte ptr [edx + 2]
// 0060358c  0fb67902             movzx edi, byte ptr [ecx + 2]
// 00603590  2bc7                 sub eax, edi
// 00603592  750f                 jne 0x6035a3
// 00603594  83fe03               cmp esi, 3
// 00603597  7626                 jbe 0x6035bf
// 00603599  0fb64203             movzx eax, byte ptr [edx + 3]
// 0060359d  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 006035a1  2bc1                 sub eax, ecx
// 006035a3  c1f81f               sar eax, 0x1f
// 006035a6  5f                   pop edi
// 006035a7  83c801               or eax, 1
// 006035aa  5e                   pop esi
// 006035ab  83c408               add esp, 8
// 006035ae  c3                   ret 
// 006035af  83f801               cmp eax, 1
// 006035b2  0f8364ffffff         jae 0x60351c
// 006035b8  83c8ff               or eax, 0xffffffff
// 006035bb  83c408               add esp, 8
// 006035be  c3                   ret 
// 006035bf  5f                   pop edi
// 006035c0  33c0                 xor eax, eax
// 006035c2  5e                   pop esi
// 006035c3  83c408               add esp, 8
// 006035c6  c3                   ret 
// library libpng-1.2.10/png.c (function _png_sig_cmp)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 png.c
