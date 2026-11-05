// from server: 100% by auto
// roc 2009-06 00581730  unit: seg_00580000  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00581730
//
// 00581730  83ec08               sub esp, 8
// 00581733  b00a                 mov al, 0xa
// 00581735  88442405             mov byte ptr [esp + 5], al
// 00581739  88442407             mov byte ptr [esp + 7], al
// 0058173d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00581741  c6042489             mov byte ptr [esp], 0x89
// 00581745  c644240150           mov byte ptr [esp + 1], 0x50
// 0058174a  c64424024e           mov byte ptr [esp + 2], 0x4e
// 0058174f  c644240347           mov byte ptr [esp + 3], 0x47
// 00581754  c64424040d           mov byte ptr [esp + 4], 0xd
// 00581759  c64424061a           mov byte ptr [esp + 6], 0x1a
// 0058175e  83f808               cmp eax, 8
// 00581761  0f8698000000         jbe 0x5817ff
// 00581767  b808000000           mov eax, 8
// 0058176c  8b542410             mov edx, dword ptr [esp + 0x10]
// 00581770  83fa07               cmp edx, 7
// 00581773  0f878f000000         ja 0x581808
// 00581779  8d0c02               lea ecx, [edx + eax]
// 0058177c  83f908               cmp ecx, 8
// 0058177f  7607                 jbe 0x581788
// 00581781  b808000000           mov eax, 8
// 00581786  2bc2                 sub eax, edx
// 00581788  56                   push esi
// 00581789  57                   push edi
// 0058178a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0058178e  8d4c1408             lea ecx, [esp + edx + 8]
// 00581792  03d7                 add edx, edi
// 00581794  8bf0                 mov esi, eax
// 00581796  83f804               cmp eax, 4
// 00581799  7219                 jb 0x5817b4
// 0058179b  eb03                 jmp 0x5817a0
// 0058179d  8d4900               lea ecx, [ecx]
// 005817a0  8b02                 mov eax, dword ptr [edx]
// 005817a2  3b01                 cmp eax, dword ptr [ecx]
// 005817a4  7512                 jne 0x5817b8
// 005817a6  83ee04               sub esi, 4
// 005817a9  83c104               add ecx, 4
// 005817ac  83c204               add edx, 4
// 005817af  83fe04               cmp esi, 4
// 005817b2  73ec                 jae 0x5817a0
// 005817b4  85f6                 test esi, esi
// 005817b6  7457                 je 0x58180f
// 005817b8  0fb602               movzx eax, byte ptr [edx]
// 005817bb  0fb639               movzx edi, byte ptr [ecx]
// 005817be  2bc7                 sub eax, edi
// 005817c0  7531                 jne 0x5817f3
// 005817c2  83fe01               cmp esi, 1
// 005817c5  7648                 jbe 0x58180f
// 005817c7  0fb64201             movzx eax, byte ptr [edx + 1]
// 005817cb  0fb67901             movzx edi, byte ptr [ecx + 1]
// 005817cf  2bc7                 sub eax, edi
// 005817d1  7520                 jne 0x5817f3
// 005817d3  83fe02               cmp esi, 2
// 005817d6  7637                 jbe 0x58180f
// 005817d8  0fb64202             movzx eax, byte ptr [edx + 2]
// 005817dc  0fb67902             movzx edi, byte ptr [ecx + 2]
// 005817e0  2bc7                 sub eax, edi
// 005817e2  750f                 jne 0x5817f3
// 005817e4  83fe03               cmp esi, 3
// 005817e7  7626                 jbe 0x58180f
// 005817e9  0fb64203             movzx eax, byte ptr [edx + 3]
// 005817ed  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 005817f1  2bc1                 sub eax, ecx
// 005817f3  c1f81f               sar eax, 0x1f
// 005817f6  5f                   pop edi
// 005817f7  83c801               or eax, 1
// 005817fa  5e                   pop esi
// 005817fb  83c408               add esp, 8
// 005817fe  c3                   ret 
// 005817ff  83f801               cmp eax, 1
// 00581802  0f8364ffffff         jae 0x58176c
// 00581808  83c8ff               or eax, 0xffffffff
// 0058180b  83c408               add esp, 8
// 0058180e  c3                   ret 
// 0058180f  5f                   pop edi
// 00581810  33c0                 xor eax, eax
// 00581812  5e                   pop esi
// 00581813  83c408               add esp, 8
// 00581816  c3                   ret 
// library libpng-1.2.10/png.c (function _png_sig_cmp)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 png.c
