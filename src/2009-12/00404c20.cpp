// from server: 100% by auto
// roc 2009-12 00404c20  unit: ATL::CComClassFactory  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00404c20
//
// 00404c20  8b01                 mov eax, dword ptr [ecx]
// 00404c22  83e810               sub eax, 0x10
// 00404c25  8d480c               lea ecx, [eax + 0xc]
// 00404c28  83caff               or edx, 0xffffffff
// 00404c2b  f00fc111             lock xadd dword ptr [ecx], edx
// 00404c2f  4a                   dec edx
// 00404c30  85d2                 test edx, edx
// 00404c32  7f0a                 jg 0x404c3e
// 00404c34  8b08                 mov ecx, dword ptr [eax]
// 00404c36  8b11                 mov edx, dword ptr [ecx]
// 00404c38  50                   push eax
// 00404c39  8b4204               mov eax, dword ptr [edx + 4]
// 00404c3c  ffd0                 call eax
// 00404c3e  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??1?$CSimpleStringT@D$0A@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
