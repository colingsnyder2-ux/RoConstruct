// from server: 100% by auto
// roc 2007-03 00545890  unit: seg_00540000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00545890
//
// 00545890  8b01                 mov eax, dword ptr [ecx]
// 00545892  83e810               sub eax, 0x10
// 00545895  8d480c               lea ecx, [eax + 0xc]
// 00545898  83caff               or edx, 0xffffffff
// 0054589b  f00fc111             lock xadd dword ptr [ecx], edx
// 0054589f  4a                   dec edx
// 005458a0  85d2                 test edx, edx
// 005458a2  7f0a                 jg 0x5458ae
// 005458a4  8b08                 mov ecx, dword ptr [eax]
// 005458a6  8b11                 mov edx, dword ptr [ecx]
// 005458a8  50                   push eax
// 005458a9  8b4204               mov eax, dword ptr [edx + 4]
// 005458ac  ffd0                 call eax
// 005458ae  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??1?$CSimpleStringT@D$0A@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
