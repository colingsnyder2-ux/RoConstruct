// from server: 100% by auto
// roc 2009-12 0079a0e0  unit: lua_exception  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079a0e0
//
// 0079a0e0  8b442404             mov eax, dword ptr [esp + 4]
// 0079a0e4  8bc8                 mov ecx, eax
// 0079a0e6  c1f903               sar ecx, 3
// 0079a0e9  83e11f               and ecx, 0x1f
// 0079a0ec  7409                 je 0x79a0f7
// 0079a0ee  83e007               and eax, 7
// 0079a0f1  83c008               add eax, 8
// 0079a0f4  49                   dec ecx
// 0079a0f5  d3e0                 shl eax, cl
// 0079a0f7  c3                   ret 
// library lua-5.1/lobject.c (function _luaO_fb2int)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lobject.c
