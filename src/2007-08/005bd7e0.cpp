// from server: 100% by auto
// roc 2007-08 005bd7e0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd7e0
//
// 005bd7e0  8b442408             mov eax, dword ptr [esp + 8]
// 005bd7e4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005bd7e8  83ec10               sub esp, 0x10
// 005bd7eb  e840fcffff           call 0x5bd430
// 005bd7f0  83780803             cmp dword ptr [eax + 8], 3
// 005bd7f4  7415                 je 0x5bd80b
// 005bd7f6  8d0c24               lea ecx, [esp]
// 005bd7f9  51                   push ecx
// 005bd7fa  50                   push eax
// 005bd7fb  e8d0280500           call 0x6100d0
// 005bd800  83c408               add esp, 8
// 005bd803  85c0                 test eax, eax
// 005bd805  7504                 jne 0x5bd80b
// 005bd807  83c410               add esp, 0x10
// 005bd80a  c3                   ret 
// 005bd80b  b801000000           mov eax, 1
// 005bd810  83c410               add esp, 0x10
// 005bd813  c3                   ret 
// library lua-5.1/lapi.c (function _lua_isnumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
