// from server: 100% by auto
// roc 2010-06 007efac0  unit: CXTPToolBar::CControlButtonExpand  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efac0
//
// 007efac0  8b01                 mov eax, dword ptr [ecx]
// 007efac2  50                   push eax
// 007efac3  ff1574a39e00         call dword ptr [0x9ea374]
// 007efac9  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
