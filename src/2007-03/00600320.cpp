// from server: 100% by auto
// roc 2007-03 00600320  unit: seg_00600000  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00600320
//
// 00600320  51                   push ecx
// 00600321  8b4e04               mov ecx, dword ptr [esi + 4]
// 00600324  6a04                 push 4
// 00600326  8d442404             lea eax, [esp + 4]
// 0060032a  50                   push eax
// 0060032b  51                   push ecx
// 0060032c  e83fcaffff           call 0x5fcd70
// 00600331  83c40c               add esp, 0xc
// 00600334  85c0                 test eax, eax
// 00600336  7423                 je 0x60035b
// 00600338  8b560c               mov edx, dword ptr [esi + 0xc]
// 0060033b  8b06                 mov eax, dword ptr [esi]
// 0060033d  6898067c00           push 0x7c0698
// 00600342  52                   push edx
// 00600343  687c067c00           push 0x7c067c
// 00600348  50                   push eax
// 00600349  e8f284ffff           call 0x5f8840
// 0060034e  8b0e                 mov ecx, dword ptr [esi]
// 00600350  6a03                 push 3
// 00600352  51                   push ecx
// 00600353  e8a8fefbff           call 0x5c0200
// 00600358  83c418               add esp, 0x18
// 0060035b  8b0424               mov eax, dword ptr [esp]
// 0060035e  85c0                 test eax, eax
// 00600360  7d27                 jge 0x600389
// 00600362  8b560c               mov edx, dword ptr [esi + 0xc]
// 00600365  8b06                 mov eax, dword ptr [esi]
// 00600367  68a8067c00           push 0x7c06a8
// 0060036c  52                   push edx
// 0060036d  687c067c00           push 0x7c067c
// 00600372  50                   push eax
// 00600373  e8c884ffff           call 0x5f8840
// 00600378  8b0e                 mov ecx, dword ptr [esi]
// 0060037a  6a03                 push 3
// 0060037c  51                   push ecx
// 0060037d  e87efefbff           call 0x5c0200
// 00600382  8b442418             mov eax, dword ptr [esp + 0x18]
// 00600386  83c418               add esp, 0x18
// 00600389  59                   pop ecx
// 0060038a  c3                   ret 
// library lua-5.1.1/lundump.c (function _LoadInt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lundump.c
