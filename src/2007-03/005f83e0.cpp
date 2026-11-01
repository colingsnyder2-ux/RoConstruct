// from server: 100% by auto
// roc 2007-03 005f83e0  unit: seg_005f0000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f83e0
//
// 005f83e0  8b442404             mov eax, dword ptr [esp + 4]
// 005f83e4  8bc8                 mov ecx, eax
// 005f83e6  c1f903               sar ecx, 3
// 005f83e9  83e11f               and ecx, 0x1f
// 005f83ec  740b                 je 0x5f83f9
// 005f83ee  83e007               and eax, 7
// 005f83f1  83c008               add eax, 8
// 005f83f4  83c1ff               add ecx, -1
// 005f83f7  d3e0                 shl eax, cl
// 005f83f9  c3                   ret 
// library lua-5.1.1/lobject.c (function _luaO_fb2int)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lobject.c
