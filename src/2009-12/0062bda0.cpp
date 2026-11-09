// from server: 100% by auto
// roc 2009-12 0062bda0  unit: seg_00620000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0062bda0
//
// 0062bda0  8b442404             mov eax, dword ptr [esp + 4]
// 0062bda4  a3802db900           mov dword ptr [0xb92d80], eax
// 0062bda9  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?EnableWindowsTheming@CMFCButton@@SGXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
