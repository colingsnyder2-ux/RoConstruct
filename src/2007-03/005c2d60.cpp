// from server: 100% by auto
// roc 2007-03 005c2d60  unit: seg_005c0000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c2d60
//
// 005c2d60  a900010000           test eax, 0x100
// 005c2d65  7419                 je 0x5c2d80
// 005c2d67  8b5108               mov edx, dword ptr [ecx + 8]
// 005c2d6a  25fffeffff           and eax, 0xfffffeff
// 005c2d6f  c1e004               shl eax, 4
// 005c2d72  03c2                 add eax, edx
// 005c2d74  83780804             cmp dword ptr [eax + 8], 4
// 005c2d78  7506                 jne 0x5c2d80
// 005c2d7a  8b00                 mov eax, dword ptr [eax]
// 005c2d7c  83c010               add eax, 0x10
// 005c2d7f  c3                   ret 
// 005c2d80  b89cc57900           mov eax, 0x79c59c
// 005c2d85  c3                   ret 
// library lua-5.1.1/ldebug.c (function _kname)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldebug.c
