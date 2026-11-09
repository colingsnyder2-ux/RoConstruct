// from server: 100% by auto
// roc 2009-12 0062bcd0  unit: seg_00620000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0062bcd0
//
// 0062bcd0  8b442404             mov eax, dword ptr [esp + 4]
// 0062bcd4  a3e84ab600           mov dword ptr [0xb64ae8], eax
// 0062bcd9  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?EnableWindowsTheming@CMFCButton@@SGXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
