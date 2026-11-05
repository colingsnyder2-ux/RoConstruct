// from server: 100% by auto
// roc 2007-08 00413010  unit: std::runtime_error  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00413010
//
// 00413010  8b01                 mov eax, dword ptr [ecx]
// 00413012  83e810               sub eax, 0x10
// 00413015  8d480c               lea ecx, [eax + 0xc]
// 00413018  83caff               or edx, 0xffffffff
// 0041301b  f00fc111             lock xadd dword ptr [ecx], edx
// 0041301f  4a                   dec edx
// 00413020  85d2                 test edx, edx
// 00413022  7f0a                 jg 0x41302e
// 00413024  8b08                 mov ecx, dword ptr [eax]
// 00413026  8b11                 mov edx, dword ptr [ecx]
// 00413028  50                   push eax
// 00413029  8b4204               mov eax, dword ptr [edx + 4]
// 0041302c  ffd0                 call eax
// 0041302e  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??1?$CSimpleStringT@D$0A@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
