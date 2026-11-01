// from server: 100% by auto
// roc 2007-03 00614850  unit: seg_00610000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614850
//
// 00614850  83ec10               sub esp, 0x10
// 00614853  dd442418             fld qword ptr [esp + 0x18]
// 00614857  8d0424               lea eax, [esp]
// 0061485a  53                   push ebx
// 0061485b  dd5c2404             fstp qword ptr [esp + 4]
// 0061485f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00614863  50                   push eax
// 00614864  8bc8                 mov ecx, eax
// 00614866  c744241003000000     mov dword ptr [esp + 0x10], 3
// 0061486e  e8cdfeffff           call 0x614740
// 00614873  83c404               add esp, 4
// 00614876  5b                   pop ebx
// 00614877  83c410               add esp, 0x10
// 0061487a  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_numberK)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
