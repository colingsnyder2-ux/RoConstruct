// from server: 100% by auto
// roc 2008-06 00628e30  unit: seg_00620000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00628e30
//
// 00628e30  8b442404             mov eax, dword ptr [esp + 4]
// 00628e34  50                   push eax
// 00628e35  e8f695feff           call 0x612430
// 00628e3a  83c404               add esp, 4
// 00628e3d  f7d8                 neg eax
// 00628e3f  1bc0                 sbb eax, eax
// 00628e41  40                   inc eax
// 00628e42  c3                   ret 
// library lua-5.1.2/lbaselib.c (function _luaB_corunning)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lbaselib.c
