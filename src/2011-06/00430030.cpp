// from server: 100% by auto
// roc 2011-06 00430030  unit: MainLogManager  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00430030
//
// 00430030  8b01                 mov eax, dword ptr [ecx]
// 00430032  50                   push eax
// 00430033  e896d14e00           call 0x91d1ce
// 00430038  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??1Graphics@Gdiplus@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
