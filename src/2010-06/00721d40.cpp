// from server: 100% by auto
// roc 2010-06 00721d40  unit: RBX::UniversalTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721d40
//
// 00721d40  83ec14               sub esp, 0x14
// 00721d43  56                   push esi
// 00721d44  57                   push edi
// 00721d45  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00721d49  85ff                 test edi, edi
// 00721d4b  7505                 jne 0x721d52
// 00721d4d  bf08b9a100           mov edi, 0xa1b908
// 00721d52  8b442428             mov eax, dword ptr [esp + 0x28]
// 00721d56  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00721d5a  8b742420             mov esi, dword ptr [esp + 0x20]
// 00721d5e  50                   push eax
// 00721d5f  51                   push ecx
// 00721d60  8d542410             lea edx, [esp + 0x10]
// 00721d64  52                   push edx
// 00721d65  56                   push esi
// 00721d66  e855c60500           call 0x77e3c0
// 00721d6b  57                   push edi
// 00721d6c  8d44241c             lea eax, [esp + 0x1c]
// 00721d70  50                   push eax
// 00721d71  56                   push esi
// 00721d72  e899e80000           call 0x730610
// 00721d77  83c41c               add esp, 0x1c
// 00721d7a  5f                   pop edi
// 00721d7b  5e                   pop esi
// 00721d7c  83c414               add esp, 0x14
// 00721d7f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_load)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
