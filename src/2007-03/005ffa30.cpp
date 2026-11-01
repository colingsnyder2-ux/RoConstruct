// from server: 100% by auto
// roc 2007-03 005ffa30  unit: seg_005f0000  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ffa30
//
// 005ffa30  83ec18               sub esp, 0x18
// 005ffa33  56                   push esi
// 005ffa34  e867290000           call 0x6023a0
// 005ffa39  6a00                 push 0
// 005ffa3b  8d442408             lea eax, [esp + 8]
// 005ffa3f  50                   push eax
// 005ffa40  56                   push esi
// 005ffa41  e88af2ffff           call 0x5fecd0
// 005ffa46  83c410               add esp, 0x10
// 005ffa49  833c2401             cmp dword ptr [esp], 1
// 005ffa4d  7507                 jne 0x5ffa56
// 005ffa4f  c7042403000000       mov dword ptr [esp], 3
// 005ffa56  8b5630               mov edx, dword ptr [esi + 0x30]
// 005ffa59  8d0c24               lea ecx, [esp]
// 005ffa5c  51                   push ecx
// 005ffa5d  52                   push edx
// 005ffa5e  e87d5b0100           call 0x6155e0
// 005ffa63  83c408               add esp, 8
// 005ffa66  817e1012010000       cmp dword ptr [esi + 0x10], 0x112
// 005ffa6d  7424                 je 0x5ffa93
// 005ffa6f  6812010000           push 0x112
// 005ffa74  56                   push esi
// 005ffa75  e8f6130000           call 0x600e70
// 005ffa7a  50                   push eax
// 005ffa7b  8b4634               mov eax, dword ptr [esi + 0x34]
// 005ffa7e  6828047c00           push 0x7c0428
// 005ffa83  50                   push eax
// 005ffa84  e8b78dffff           call 0x5f8840
// 005ffa89  50                   push eax
// 005ffa8a  56                   push esi
// 005ffa8b  e8e0140000           call 0x600f70
// 005ffa90  83c41c               add esp, 0x1c
// 005ffa93  56                   push esi
// 005ffa94  e807290000           call 0x6023a0
// 005ffa99  8bc6                 mov eax, esi
// 005ffa9b  e840f3ffff           call 0x5fede0
// 005ffaa0  8b442418             mov eax, dword ptr [esp + 0x18]
// 005ffaa4  83c41c               add esp, 0x1c
// 005ffaa7  c3                   ret 
// library lua-5.1.1/lparser.c (function _test_then_block)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
