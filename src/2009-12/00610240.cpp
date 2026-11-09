// from server: 100% by auto
// roc 2009-12 00610240  unit: seg_00610000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00610240
//
// 00610240  56                   push esi
// 00610241  8b742408             mov esi, dword ptr [esp + 8]
// 00610245  33c0                 xor eax, eax
// 00610247  85f6                 test esi, esi
// 00610249  7441                 je 0x61028c
// 0061024b  f7466c00000c00       test dword ptr [esi + 0x6c], 0xc0000
// 00610252  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00610256  7422                 je 0x61027a
// 00610258  803a23               cmp byte ptr [edx], 0x23
// 0061025b  751d                 jne 0x61027a
// 0061025d  b801000000           mov eax, 1
// 00610262  b120                 mov cl, 0x20
// 00610264  380c10               cmp byte ptr [eax + edx], cl
// 00610267  7411                 je 0x61027a
// 00610269  384c1001             cmp byte ptr [eax + edx + 1], cl
// 0061026d  740a                 je 0x610279
// 0061026f  83c002               add eax, 2
// 00610272  83f80f               cmp eax, 0xf
// 00610275  7ced                 jl 0x610264
// 00610277  eb01                 jmp 0x61027a
// 00610279  40                   inc eax
// 0061027a  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 0061027d  85c9                 test ecx, ecx
// 0061027f  7409                 je 0x61028a
// 00610281  03c2                 add eax, edx
// 00610283  50                   push eax
// 00610284  56                   push esi
// 00610285  ffd1                 call ecx
// 00610287  83c408               add esp, 8
// 0061028a  5e                   pop esi
// 0061028b  c3                   ret 
// 0061028c  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00610290  5e                   pop esi
// 00610291  e9bafdffff           jmp 0x610050
// library libpng-1.2.10/pngerror.c (function _png_warning)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngerror.c
