// from server: 100% by auto
// roc 2009-06 00685070  unit: RBX::Sky  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00685070
//
// 00685070  8b01                 mov eax, dword ptr [ecx]
// 00685072  50                   push eax
// 00685073  ff1554ef8900         call dword ptr [0x89ef54]
// 00685079  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
