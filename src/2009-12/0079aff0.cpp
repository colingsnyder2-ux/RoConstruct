// from server: 100% by auto
// roc 2009-12 0079aff0  unit: lua_exception  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079aff0
//
// 0079aff0  a900010000           test eax, 0x100
// 0079aff5  7419                 je 0x79b010
// 0079aff7  8b5108               mov edx, dword ptr [ecx + 8]
// 0079affa  25fffeffff           and eax, 0xfffffeff
// 0079afff  c1e004               shl eax, 4
// 0079b002  03c2                 add eax, edx
// 0079b004  83780804             cmp dword ptr [eax + 8], 4
// 0079b008  7506                 jne 0x79b010
// 0079b00a  8b00                 mov eax, dword ptr [eax]
// 0079b00c  83c010               add eax, 0x10
// 0079b00f  c3                   ret 
// 0079b010  b8d0d99b00           mov eax, 0x9bd9d0
// 0079b015  c3                   ret 
// library lua-5.1/ldebug.c (function _kname)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
