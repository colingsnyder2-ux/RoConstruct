// from server: 100% by auto
// roc 2007-03 005c37b0  unit: seg_005c0000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c37b0
//
// 005c37b0  8b442404             mov eax, dword ptr [esp + 4]
// 005c37b4  50                   push eax
// 005c37b5  e8165c0300           call 0x5f93d0
// 005c37ba  59                   pop ecx
// 005c37bb  c3                   ret 
// library lua-5.1.1/lstate.c (function _callallgcTM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstate.c
