// from server: 100% by auto
// roc 2007-03 005c2880  unit: seg_005c0000  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c2880
//
// 005c2880  83e800               sub eax, 0
// 005c2883  743f                 je 0x5c28c4
// 005c2885  83e802               sub eax, 2
// 005c2888  742f                 je 0x5c28b9
// 005c288a  83e801               sub eax, 1
// 005c288d  7539                 jne 0x5c28c8
// 005c288f  f7c100010000         test ecx, 0x100
// 005c2895  7410                 je 0x5c28a7
// 005c2897  81e1fffeffff         and ecx, 0xfffffeff
// 005c289d  33c0                 xor eax, eax
// 005c289f  3b4a28               cmp ecx, dword ptr [edx + 0x28]
// 005c28a2  0f9cc0               setl al
// 005c28a5  eb0d                 jmp 0x5c28b4
// 005c28a7  0fb6424b             movzx eax, byte ptr [edx + 0x4b]
// 005c28ab  33d2                 xor edx, edx
// 005c28ad  3bc8                 cmp ecx, eax
// 005c28af  0f9cc2               setl dl
// 005c28b2  8bc2                 mov eax, edx
// 005c28b4  85c0                 test eax, eax
// 005c28b6  7510                 jne 0x5c28c8
// 005c28b8  c3                   ret 
// 005c28b9  0fb6424b             movzx eax, byte ptr [edx + 0x4b]
// 005c28bd  3bc8                 cmp ecx, eax
// 005c28bf  7c07                 jl 0x5c28c8
// 005c28c1  33c0                 xor eax, eax
// 005c28c3  c3                   ret 
// 005c28c4  85c9                 test ecx, ecx
// 005c28c6  75f9                 jne 0x5c28c1
// 005c28c8  b801000000           mov eax, 1
// 005c28cd  c3                   ret 
// library lua-5.1.1/ldebug.c (function _checkArgMode)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldebug.c
