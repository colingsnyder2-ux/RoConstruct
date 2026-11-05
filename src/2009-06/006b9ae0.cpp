// from server: 100% by auto
// roc 2009-06 006b9ae0  unit: RBX::UniversalTool  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9ae0
//
// 006b9ae0  8b442408             mov eax, dword ptr [esp + 8]
// 006b9ae4  8b4804               mov ecx, dword ptr [eax + 4]
// 006b9ae7  8b10                 mov edx, dword ptr [eax]
// 006b9ae9  8b442404             mov eax, dword ptr [esp + 4]
// 006b9aed  51                   push ecx
// 006b9aee  52                   push edx
// 006b9aef  50                   push eax
// 006b9af0  e89b9a0000           call 0x6c3590
// 006b9af5  83c40c               add esp, 0xc
// 006b9af8  c3                   ret 
// library lua-5.1/lapi.c (function _f_call)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
