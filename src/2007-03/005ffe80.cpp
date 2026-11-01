// from server: 100% by auto
// roc 2007-03 005ffe80  unit: seg_005f0000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ffe80
//
// 005ffe80  83ec30               sub esp, 0x30
// 005ffe83  56                   push esi
// 005ffe84  e817250000           call 0x6023a0
// 005ffe89  8d44241c             lea eax, [esp + 0x1c]
// 005ffe8d  8bce                 mov ecx, esi
// 005ffe8f  e80cffffff           call 0x5ffda0
// 005ffe94  57                   push edi
// 005ffe95  50                   push eax
// 005ffe96  8d44240c             lea eax, [esp + 0xc]
// 005ffe9a  50                   push eax
// 005ffe9b  8bc6                 mov eax, esi
// 005ffe9d  e86ee4ffff           call 0x5fe310
// 005ffea2  8b4630               mov eax, dword ptr [esi + 0x30]
// 005ffea5  8d4c2410             lea ecx, [esp + 0x10]
// 005ffea9  51                   push ecx
// 005ffeaa  8d54242c             lea edx, [esp + 0x2c]
// 005ffeae  52                   push edx
// 005ffeaf  50                   push eax
// 005ffeb0  e8fb540100           call 0x6153b0
// 005ffeb5  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 005ffeb8  57                   push edi
// 005ffeb9  51                   push ecx
// 005ffeba  e8314c0100           call 0x614af0
// 005ffebf  83c454               add esp, 0x54
// 005ffec2  c3                   ret 
// library lua-5.1.1/lparser.c (function _funcstat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
