// from server: 100% by auto
// roc 2008-06 00401020  unit: seg_00400000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401020
//
// 00401020  8b01                 mov eax, dword ptr [ecx]
// 00401022  50                   push eax
// 00401023  ff1544298000         call dword ptr [0x802944]
// 00401029  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
