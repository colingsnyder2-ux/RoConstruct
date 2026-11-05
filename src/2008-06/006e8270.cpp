// from server: 100% by auto
// roc 2008-06 006e8270  unit: CXTPToolBar::CControlButtonExpand  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006e8270
//
// 006e8270  8b01                 mov eax, dword ptr [ecx]
// 006e8272  50                   push eax
// 006e8273  ff15d4228000         call dword ptr [0x8022d4]
// 006e8279  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
