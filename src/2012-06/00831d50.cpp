// from server: 100% by auto
// roc 2012-06 00831d50  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831d50
//
// 00831d50  8b442408             mov eax, dword ptr [esp + 8]
// 00831d54  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00831d58  83ec10               sub esp, 0x10
// 00831d5b  e8e0fbffff           call 0x831940
// 00831d60  83780803             cmp dword ptr [eax + 8], 3
// 00831d64  7415                 je 0x831d7b
// 00831d66  8d0c24               lea ecx, [esp]
// 00831d69  51                   push ecx
// 00831d6a  50                   push eax
// 00831d6b  e810181000           call 0x933580
// 00831d70  83c408               add esp, 8
// 00831d73  85c0                 test eax, eax
// 00831d75  7504                 jne 0x831d7b
// 00831d77  83c410               add esp, 0x10
// 00831d7a  c3                   ret 
// 00831d7b  b801000000           mov eax, 1
// 00831d80  83c410               add esp, 0x10
// 00831d83  c3                   ret 
// library lua-5.1/lapi.c (function _lua_isnumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
