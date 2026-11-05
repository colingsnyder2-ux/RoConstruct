// from server: 100% by auto
// roc 2012-06 00832850  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832850
//
// 00832850  8b442408             mov eax, dword ptr [esp + 8]
// 00832854  8b4804               mov ecx, dword ptr [eax + 4]
// 00832857  8b10                 mov edx, dword ptr [eax]
// 00832859  8b442404             mov eax, dword ptr [esp + 4]
// 0083285d  51                   push ecx
// 0083285e  52                   push edx
// 0083285f  50                   push eax
// 00832860  e8cb260200           call 0x854f30
// 00832865  83c40c               add esp, 0xc
// 00832868  c3                   ret 
// library lua-5.1/lapi.c (function _f_call)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
