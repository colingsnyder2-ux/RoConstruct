// from server: 100% by auto
// roc 2007-03 005fe460  unit: seg_005f0000  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fe460
//
// 005fe460  53                   push ebx
// 005fe461  6a00                 push 0
// 005fe463  57                   push edi
// 005fe464  56                   push esi
// 005fe465  bb01000000           mov ebx, 1
// 005fe46a  e861080000           call 0x5fecd0
// 005fe46f  83c40c               add esp, 0xc
// 005fe472  837e102c             cmp dword ptr [esi + 0x10], 0x2c
// 005fe476  7521                 jne 0x5fe499
// 005fe478  56                   push esi
// 005fe479  e8223f0000           call 0x6023a0
// 005fe47e  8b4630               mov eax, dword ptr [esi + 0x30]
// 005fe481  57                   push edi
// 005fe482  50                   push eax
// 005fe483  e8386d0100           call 0x6151c0
// 005fe488  6a00                 push 0
// 005fe48a  57                   push edi
// 005fe48b  56                   push esi
// 005fe48c  e83f080000           call 0x5fecd0
// 005fe491  83c418               add esp, 0x18
// 005fe494  83c301               add ebx, 1
// 005fe497  ebd9                 jmp 0x5fe472
// 005fe499  8bc3                 mov eax, ebx
// 005fe49b  5b                   pop ebx
// 005fe49c  c3                   ret 
// library lua-5.1.1/lparser.c (function _explist1)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
