// from server: 100% by auto
// roc 2012-06 004363c0  unit: CMainFrame  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004363c0
//
// 004363c0  8b01                 mov eax, dword ptr [ecx]
// 004363c2  50                   push eax
// 004363c3  e806ee6500           call 0xa951ce
// 004363c8  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??1Graphics@Gdiplus@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
