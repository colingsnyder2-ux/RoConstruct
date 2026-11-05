// from server: 100% by auto
// roc 2009-12 005fa6e0  unit: G3D::LineSegment  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005fa6e0
//
// 005fa6e0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005fa6e4  8b542404             mov edx, dword ptr [esp + 4]
// 005fa6e8  8d44240c             lea eax, [esp + 0xc]
// 005fa6ec  50                   push eax
// 005fa6ed  51                   push ecx
// 005fa6ee  52                   push edx
// 005fa6ef  e84cffffff           call 0x5fa640
// 005fa6f4  83c40c               add esp, 0xc
// 005fa6f7  c3                   ret 
// library lua-5.1/lobject.c (function _luaO_pushfstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lobject.c
