// from server: 100% by auto
// roc 2009-12 00610190  unit: seg_00610000  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00610190
//
// 00610190  83ec10               sub esp, 0x10
// 00610193  55                   push ebp
// 00610194  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00610198  56                   push esi
// 00610199  8b742420             mov esi, dword ptr [esp + 0x20]
// 0061019d  85ed                 test ebp, ebp
// 0061019f  0f8487000000         je 0x61022c
// 006101a5  8b556c               mov edx, dword ptr [ebp + 0x6c]
// 006101a8  f7c200000c00         test edx, 0xc0000
// 006101ae  746e                 je 0x61021e
// 006101b0  803e23               cmp byte ptr [esi], 0x23
// 006101b3  7553                 jne 0x610208
// 006101b5  b801000000           mov eax, 1
// 006101ba  b120                 mov cl, 0x20
// 006101bc  8d642400             lea esp, [esp]
// 006101c0  380c30               cmp byte ptr [eax + esi], cl
// 006101c3  7411                 je 0x6101d6
// 006101c5  384c3001             cmp byte ptr [eax + esi + 1], cl
// 006101c9  740a                 je 0x6101d5
// 006101cb  83c002               add eax, 2
// 006101ce  83f80f               cmp eax, 0xf
// 006101d1  7ced                 jl 0x6101c0
// 006101d3  eb01                 jmp 0x6101d6
// 006101d5  40                   inc eax
// 006101d6  f7c200000800         test edx, 0x80000
// 006101dc  7426                 je 0x610204
// 006101de  57                   push edi
// 006101df  8d78ff               lea edi, [eax - 1]
// 006101e2  33c9                 xor ecx, ecx
// 006101e4  85ff                 test edi, edi
// 006101e6  7e14                 jle 0x6101fc
// 006101e8  8d4601               lea eax, [esi + 1]
// 006101eb  57                   push edi
// 006101ec  50                   push eax
// 006101ed  8d442414             lea eax, [esp + 0x14]
// 006101f1  50                   push eax
// 006101f2  e8ef4a1e00           call 0x7f4ce6
// 006101f7  83c40c               add esp, 0xc
// 006101fa  8bcf                 mov ecx, edi
// 006101fc  c6440c0b00           mov byte ptr [esp + ecx + 0xb], 0
// 00610201  5f                   pop edi
// 00610202  eb16                 jmp 0x61021a
// 00610204  03f0                 add esi, eax
// 00610206  eb16                 jmp 0x61021e
// 00610208  f7c200000800         test edx, 0x80000
// 0061020e  740e                 je 0x61021e
// 00610210  c644240830           mov byte ptr [esp + 8], 0x30
// 00610215  c644240900           mov byte ptr [esp + 9], 0
// 0061021a  8d742408             lea esi, [esp + 8]
// 0061021e  8b4540               mov eax, dword ptr [ebp + 0x40]
// 00610221  85c0                 test eax, eax
// 00610223  7407                 je 0x61022c
// 00610225  56                   push esi
// 00610226  55                   push ebp
// 00610227  ffd0                 call eax
// 00610229  83c408               add esp, 8
// 0061022c  55                   push ebp
// 0061022d  8bc6                 mov eax, esi
// 0061022f  e8fcfcffff           call 0x60ff30
// 00610234  83c404               add esp, 4
// 00610237  5e                   pop esi
// 00610238  5d                   pop ebp
// 00610239  83c410               add esp, 0x10
// 0061023c  c3                   ret 
// library libpng-1.2.32/pngerror.c (function _png_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngerror.c
