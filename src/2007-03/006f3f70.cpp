// from server: 100% by auto
// roc 2007-03 006f3f70  unit: seg_006f0000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f3f70
//
// 006f3f70  85c9                 test ecx, ecx
// 006f3f72  7409                 je 0x6f3f7d
// 006f3f74  8b01                 mov eax, dword ptr [ecx]
// 006f3f76  8b5004               mov edx, dword ptr [eax + 4]
// 006f3f79  6a01                 push 1
// 006f3f7b  ffd2                 call edx
// 006f3f7d  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dlgfr.cpp (function ?PostNcDestroy@CFindReplaceDialog@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgfr.cpp
