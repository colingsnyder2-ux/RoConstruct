// from server: 100% by auto
// roc 2007-03 00614720  unit: seg_00610000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614720
//
// 00614720  83380c               cmp dword ptr [eax], 0xc
// 00614723  7516                 jne 0x61473b
// 00614725  8b4008               mov eax, dword ptr [eax + 8]
// 00614728  a900010000           test eax, 0x100
// 0061472d  750c                 jne 0x61473b
// 0061472f  0fb65132             movzx edx, byte ptr [ecx + 0x32]
// 00614733  3bc2                 cmp eax, edx
// 00614735  7c04                 jl 0x61473b
// 00614737  834124ff             add dword ptr [ecx + 0x24], -1
// 0061473b  c3                   ret 
// library lua-5.1.1/lcode.c (function _freeexp)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
