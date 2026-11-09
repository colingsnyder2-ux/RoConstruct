// from server: 100% by auto
// roc 2009-06 00760bb0  unit: CXTPToolBar::CControlButtonExpand  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760bb0
//
// 00760bb0  8b01                 mov eax, dword ptr [ecx]
// 00760bb2  50                   push eax
// 00760bb3  ff15a8e18900         call dword ptr [0x89e1a8]
// 00760bb9  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
