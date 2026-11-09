// from server: 100% by auto
// roc 2009-12 007d4650  unit: seg_007d0000  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d4650
//
// 007d4650  81ec84020000         sub esp, 0x284
// 007d4656  8b842490020000       mov eax, dword ptr [esp + 0x290]
// 007d465d  8b942494020000       mov edx, dword ptr [esp + 0x294]
// 007d4664  53                   push ebx
// 007d4665  89442440             mov dword ptr [esp + 0x40], eax
// 007d4669  8bc2                 mov eax, edx
// 007d466b  56                   push esi
// 007d466c  8d7001               lea esi, [eax + 1]
// 007d466f  90                   nop 
// 007d4670  8a08                 mov cl, byte ptr [eax]
// 007d4672  40                   inc eax
// 007d4673  84c9                 test cl, cl
// 007d4675  75f9                 jne 0x7d4670
// 007d4677  2bc6                 sub eax, esi
// 007d4679  8bb42490020000       mov esi, dword ptr [esp + 0x290]
// 007d4680  50                   push eax
// 007d4681  52                   push edx
// 007d4682  56                   push esi
// 007d4683  e808c5ffff           call 0x7d0b90
// 007d4688  8b8c24a0020000       mov ecx, dword ptr [esp + 0x2a0]
// 007d468f  50                   push eax
// 007d4690  51                   push ecx
// 007d4691  8d54241c             lea edx, [esp + 0x1c]
// 007d4695  52                   push edx
// 007d4696  56                   push esi
// 007d4697  e8a40d0000           call 0x7d5440
// 007d469c  8d44246c             lea eax, [esp + 0x6c]
// 007d46a0  8d5c2424             lea ebx, [esp + 0x24]
// 007d46a4  e887d8ffff           call 0x7d1f30
// 007d46a9  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 007d46ad  8bcb                 mov ecx, ebx
// 007d46af  51                   push ecx
// 007d46b0  c6404a02             mov byte ptr [eax + 0x4a], 2
// 007d46b4  e877200000           call 0x7d6730
// 007d46b9  8bd3                 mov edx, ebx
// 007d46bb  52                   push edx
// 007d46bc  e8dffeffff           call 0x7d45a0
// 007d46c1  83c424               add esp, 0x24
// 007d46c4  817c24181f010000     cmp dword ptr [esp + 0x18], 0x11f
// 007d46cc  5e                   pop esi
// 007d46cd  5b                   pop ebx
// 007d46ce  742c                 je 0x7d46fc
// 007d46d0  8d0424               lea eax, [esp]
// 007d46d3  681f010000           push 0x11f
// 007d46d8  50                   push eax
// 007d46d9  e8620b0000           call 0x7d5240
// 007d46de  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 007d46e2  50                   push eax
// 007d46e3  68d0ed9e00           push 0x9eedd0
// 007d46e8  51                   push ecx
// 007d46e9  e8925efcff           call 0x79a580
// 007d46ee  50                   push eax
// 007d46ef  8d542418             lea edx, [esp + 0x18]
// 007d46f3  52                   push edx
// 007d46f4  e8470c0000           call 0x7d5340
// 007d46f9  83c41c               add esp, 0x1c
// 007d46fc  8d0424               lea eax, [esp]
// 007d46ff  50                   push eax
// 007d4700  e8dbd8ffff           call 0x7d1fe0
// 007d4705  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 007d4709  81c488020000         add esp, 0x288
// 007d470f  c3                   ret 
// library lua-5.1/lparser.c (function _luaY_parser)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
