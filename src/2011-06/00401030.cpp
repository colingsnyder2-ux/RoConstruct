// from server: 100% by auto
// roc 2011-06 00401030  unit: seg_00400000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00401030
//
// 00401030  8b01                 mov eax, dword ptr [ecx]
// 00401032  50                   push eax
// 00401033  ff15a403a400         call dword ptr [0xa403a4]
// 00401039  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
