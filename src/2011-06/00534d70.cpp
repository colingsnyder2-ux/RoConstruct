// from server: 100% by auto
// roc 2011-06 00534d70  unit: seg_00530000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00534d70
//
// 00534d70  8b01                 mov eax, dword ptr [ecx]
// 00534d72  50                   push eax
// 00534d73  ff157403a400         call dword ptr [0xa40374]
// 00534d79  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
