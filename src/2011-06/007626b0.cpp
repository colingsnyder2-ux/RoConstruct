// from server: 100% by auto
// roc 2011-06 007626b0  unit: seg_00760000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007626b0
//
// 007626b0  8b442408             mov eax, dword ptr [esp + 8]
// 007626b4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007626b8  83ec10               sub esp, 0x10
// 007626bb  e8f0faffff           call 0x7621b0
// 007626c0  83780803             cmp dword ptr [eax + 8], 3
// 007626c4  7417                 je 0x7626dd
// 007626c6  8d0c24               lea ecx, [esp]
// 007626c9  51                   push ecx
// 007626ca  50                   push eax
// 007626cb  e8a04d0700           call 0x7d7470
// 007626d0  83c408               add esp, 8
// 007626d3  85c0                 test eax, eax
// 007626d5  7506                 jne 0x7626dd
// 007626d7  d9ee                 fldz 
// 007626d9  83c410               add esp, 0x10
// 007626dc  c3                   ret 
// 007626dd  dd00                 fld qword ptr [eax]
// 007626df  83c410               add esp, 0x10
// 007626e2  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tonumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
