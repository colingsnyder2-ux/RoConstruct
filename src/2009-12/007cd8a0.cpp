// from server: 100% by auto
// roc 2009-12 007cd8a0  unit: RBX::PartDropTool  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cd8a0
//
// 007cd8a0  55                   push ebp
// 007cd8a1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 007cd8a5  56                   push esi
// 007cd8a6  57                   push edi
// 007cd8a7  8db598000000         lea esi, [ebp + 0x98]
// 007cd8ad  bf09000000           mov edi, 9
// 007cd8b2  8b06                 mov eax, dword ptr [esi]
// 007cd8b4  85c0                 test eax, eax
// 007cd8b6  7410                 je 0x7cd8c8
// 007cd8b8  f6400503             test byte ptr [eax + 5], 3
// 007cd8bc  740a                 je 0x7cd8c8
// 007cd8be  50                   push eax
// 007cd8bf  55                   push ebp
// 007cd8c0  e88bf5ffff           call 0x7cce50
// 007cd8c5  83c408               add esp, 8
// 007cd8c8  83c604               add esi, 4
// 007cd8cb  83ef01               sub edi, 1
// 007cd8ce  75e2                 jne 0x7cd8b2
// 007cd8d0  5f                   pop edi
// 007cd8d1  5e                   pop esi
// 007cd8d2  5d                   pop ebp
// 007cd8d3  c3                   ret 
// library lua-5.1/lgc.c (function _markmt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
