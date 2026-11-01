// from server: 100% by auto
// roc 2007-03 005fd480  unit: seg_005f0000  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fd480
//
// 005fd480  8b06                 mov eax, dword ptr [esi]
// 005fd482  8b403c               mov eax, dword ptr [eax + 0x3c]
// 005fd485  85c0                 test eax, eax
// 005fd487  51                   push ecx
// 005fd488  52                   push edx
// 005fd489  7521                 jne 0x5fd4ac
// 005fd48b  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005fd48e  6860047c00           push 0x7c0460
// 005fd493  51                   push ecx
// 005fd494  e8a7b3ffff           call 0x5f8840
// 005fd499  83c410               add esp, 0x10
// 005fd49c  6a00                 push 0
// 005fd49e  50                   push eax
// 005fd49f  8b460c               mov eax, dword ptr [esi + 0xc]
// 005fd4a2  50                   push eax
// 005fd4a3  e8283a0000           call 0x600ed0
// 005fd4a8  83c40c               add esp, 0xc
// 005fd4ab  c3                   ret 
// 005fd4ac  8b5610               mov edx, dword ptr [esi + 0x10]
// 005fd4af  50                   push eax
// 005fd4b0  6838047c00           push 0x7c0438
// 005fd4b5  52                   push edx
// 005fd4b6  e885b3ffff           call 0x5f8840
// 005fd4bb  83c414               add esp, 0x14
// 005fd4be  6a00                 push 0
// 005fd4c0  50                   push eax
// 005fd4c1  8b460c               mov eax, dword ptr [esi + 0xc]
// 005fd4c4  50                   push eax
// 005fd4c5  e8063a0000           call 0x600ed0
// 005fd4ca  83c40c               add esp, 0xc
// 005fd4cd  c3                   ret 
// library lua-5.1.1/lparser.c (function _errorlimit)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
