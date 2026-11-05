// from server: 100% by auto
// roc 2009-12 007d4280  unit: seg_007d0000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d4280
//
// 007d4280  83ec30               sub esp, 0x30
// 007d4283  56                   push esi
// 007d4284  e8a7240000           call 0x7d6730
// 007d4289  8d44241c             lea eax, [esp + 0x1c]
// 007d428d  8bce                 mov ecx, esi
// 007d428f  e80cffffff           call 0x7d41a0
// 007d4294  57                   push edi
// 007d4295  50                   push eax
// 007d4296  8d44240c             lea eax, [esp + 0xc]
// 007d429a  50                   push eax
// 007d429b  8bc6                 mov eax, esi
// 007d429d  e84ee4ffff           call 0x7d26f0
// 007d42a2  8b4630               mov eax, dword ptr [esi + 0x30]
// 007d42a5  8d4c2410             lea ecx, [esp + 0x10]
// 007d42a9  51                   push ecx
// 007d42aa  8d54242c             lea edx, [esp + 0x2c]
// 007d42ae  52                   push edx
// 007d42af  50                   push eax
// 007d42b0  e84b8b0000           call 0x7dce00
// 007d42b5  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 007d42b8  57                   push edi
// 007d42b9  51                   push ecx
// 007d42ba  e881820000           call 0x7dc540
// 007d42bf  83c454               add esp, 0x54
// 007d42c2  c3                   ret 
// library lua-5.1/lparser.c (function _funcstat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
