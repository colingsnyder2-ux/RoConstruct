// from server: 100% by auto
// roc 2011-06 00851310  unit: CXTPToolBar::CControlButtonExpand  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00851310
//
// 00851310  8b01                 mov eax, dword ptr [ecx]
// 00851312  50                   push eax
// 00851313  ff158403a400         call dword ptr [0xa40384]
// 00851319  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
