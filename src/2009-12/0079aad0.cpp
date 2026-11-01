// from server: 100% by auto
// roc 2009-12 0079aad0  unit: lua_exception  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079aad0
//
// 0079aad0  83e800               sub eax, 0
// 0079aad3  743d                 je 0x79ab12
// 0079aad5  83e802               sub eax, 2
// 0079aad8  742d                 je 0x79ab07
// 0079aada  83e801               sub eax, 1
// 0079aadd  7537                 jne 0x79ab16
// 0079aadf  f7c100010000         test ecx, 0x100
// 0079aae5  740e                 je 0x79aaf5
// 0079aae7  81e1fffeffff         and ecx, 0xfffffeff
// 0079aaed  3b4a28               cmp ecx, dword ptr [edx + 0x28]
// 0079aaf0  0f9cc0               setl al
// 0079aaf3  eb0d                 jmp 0x79ab02
// 0079aaf5  0fb6424b             movzx eax, byte ptr [edx + 0x4b]
// 0079aaf9  33d2                 xor edx, edx
// 0079aafb  3bc8                 cmp ecx, eax
// 0079aafd  0f9cc2               setl dl
// 0079ab00  8bc2                 mov eax, edx
// 0079ab02  85c0                 test eax, eax
// 0079ab04  7510                 jne 0x79ab16
// 0079ab06  c3                   ret 
// 0079ab07  0fb6424b             movzx eax, byte ptr [edx + 0x4b]
// 0079ab0b  3bc8                 cmp ecx, eax
// 0079ab0d  7c07                 jl 0x79ab16
// 0079ab0f  33c0                 xor eax, eax
// 0079ab11  c3                   ret 
// 0079ab12  85c9                 test ecx, ecx
// 0079ab14  75f9                 jne 0x79ab0f
// 0079ab16  b801000000           mov eax, 1
// 0079ab1b  c3                   ret 
// library lua-5.1/ldebug.c (function _checkArgMode)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
