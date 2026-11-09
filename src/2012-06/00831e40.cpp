// from server: 100% by auto
// roc 2012-06 00831e40  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831e40
//
// 00831e40  8b442408             mov eax, dword ptr [esp + 8]
// 00831e44  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00831e48  83ec10               sub esp, 0x10
// 00831e4b  e8f0faffff           call 0x831940
// 00831e50  83780803             cmp dword ptr [eax + 8], 3
// 00831e54  7417                 je 0x831e6d
// 00831e56  8d0c24               lea ecx, [esp]
// 00831e59  51                   push ecx
// 00831e5a  50                   push eax
// 00831e5b  e820171000           call 0x933580
// 00831e60  83c408               add esp, 8
// 00831e63  85c0                 test eax, eax
// 00831e65  7506                 jne 0x831e6d
// 00831e67  d9ee                 fldz 
// 00831e69  83c410               add esp, 0x10
// 00831e6c  c3                   ret 
// 00831e6d  dd00                 fld qword ptr [eax]
// 00831e6f  83c410               add esp, 0x10
// 00831e72  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tonumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
