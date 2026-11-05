// from server: 100% by auto
// roc 2010-06 00721cb0  unit: RBX::UniversalTool  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721cb0
//
// 00721cb0  8b442408             mov eax, dword ptr [esp + 8]
// 00721cb4  8b4804               mov ecx, dword ptr [eax + 4]
// 00721cb7  8b10                 mov edx, dword ptr [eax]
// 00721cb9  8b442404             mov eax, dword ptr [esp + 4]
// 00721cbd  51                   push ecx
// 00721cbe  52                   push edx
// 00721cbf  50                   push eax
// 00721cc0  e89be60000           call 0x730360
// 00721cc5  83c40c               add esp, 0xc
// 00721cc8  c3                   ret 
// library lua-5.1/lapi.c (function _f_call)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
