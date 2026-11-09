// from server: 100% by auto
// roc 2009-12 007d3e40  unit: seg_007d0000  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d3e40
//
// 007d3e40  83ec18               sub esp, 0x18
// 007d3e43  56                   push esi
// 007d3e44  e8e7280000           call 0x7d6730
// 007d3e49  6a00                 push 0
// 007d3e4b  8d442408             lea eax, [esp + 8]
// 007d3e4f  50                   push eax
// 007d3e50  56                   push esi
// 007d3e51  e85af2ffff           call 0x7d30b0
// 007d3e56  83c410               add esp, 0x10
// 007d3e59  833c2401             cmp dword ptr [esp], 1
// 007d3e5d  7507                 jne 0x7d3e66
// 007d3e5f  c7042403000000       mov dword ptr [esp], 3
// 007d3e66  8b5630               mov edx, dword ptr [esi + 0x30]
// 007d3e69  8d0c24               lea ecx, [esp]
// 007d3e6c  51                   push ecx
// 007d3e6d  52                   push edx
// 007d3e6e  e8bd910000           call 0x7dd030
// 007d3e73  83c408               add esp, 8
// 007d3e76  817e1012010000       cmp dword ptr [esi + 0x10], 0x112
// 007d3e7d  7424                 je 0x7d3ea3
// 007d3e7f  6812010000           push 0x112
// 007d3e84  56                   push esi
// 007d3e85  e8b6130000           call 0x7d5240
// 007d3e8a  50                   push eax
// 007d3e8b  8b4634               mov eax, dword ptr [esi + 0x34]
// 007d3e8e  68d0ed9e00           push 0x9eedd0
// 007d3e93  50                   push eax
// 007d3e94  e8e766fcff           call 0x79a580
// 007d3e99  50                   push eax
// 007d3e9a  56                   push esi
// 007d3e9b  e8a0140000           call 0x7d5340
// 007d3ea0  83c41c               add esp, 0x1c
// 007d3ea3  56                   push esi
// 007d3ea4  e887280000           call 0x7d6730
// 007d3ea9  8bc6                 mov eax, esi
// 007d3eab  e810f3ffff           call 0x7d31c0
// 007d3eb0  8b442418             mov eax, dword ptr [esp + 0x18]
// 007d3eb4  83c41c               add esp, 0x1c
// 007d3eb7  c3                   ret 
// library lua-5.1/lparser.c (function _test_then_block)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
