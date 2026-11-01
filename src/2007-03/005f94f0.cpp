// from server: 100% by auto
// roc 2007-03 005f94f0  unit: seg_005f0000  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f94f0
//
// 005f94f0  55                   push ebp
// 005f94f1  56                   push esi
// 005f94f2  8bb78c000000         mov esi, dword ptr [edi + 0x8c]
// 005f94f8  8d6f78               lea ebp, [edi + 0x78]
// 005f94fb  3bf5                 cmp esi, ebp
// 005f94fd  7429                 je 0x5f9528
// 005f94ff  90                   nop 
// 005f9500  f6460507             test byte ptr [esi + 5], 7
// 005f9504  751b                 jne 0x5f9521
// 005f9506  8b4608               mov eax, dword ptr [esi + 8]
// 005f9509  83780804             cmp dword ptr [eax + 8], 4
// 005f950d  7c12                 jl 0x5f9521
// 005f950f  8b00                 mov eax, dword ptr [eax]
// 005f9511  f6400503             test byte ptr [eax + 5], 3
// 005f9515  740a                 je 0x5f9521
// 005f9517  50                   push eax
// 005f9518  57                   push edi
// 005f9519  e8a2f4ffff           call 0x5f89c0
// 005f951e  83c408               add esp, 8
// 005f9521  8b7614               mov esi, dword ptr [esi + 0x14]
// 005f9524  3bf5                 cmp esi, ebp
// 005f9526  75d8                 jne 0x5f9500
// 005f9528  5e                   pop esi
// 005f9529  5d                   pop ebp
// 005f952a  c3                   ret 
// library lua-5.1.1/lgc.c (function _remarkupvals)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
