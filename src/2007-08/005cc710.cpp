// from server: 100% by auto
// roc 2007-08 005cc710  unit: seg_005c0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005cc710
//
// 005cc710  8b442404             mov eax, dword ptr [esp + 4]
// 005cc714  50                   push eax
// 005cc715  e88616ffff           call 0x5bdda0
// 005cc71a  83c404               add esp, 4
// 005cc71d  f7d8                 neg eax
// 005cc71f  1bc0                 sbb eax, eax
// 005cc721  83c001               add eax, 1
// 005cc724  c3                   ret 
// library lua-5.1.2/lbaselib.c (function _luaB_corunning)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lbaselib.c
