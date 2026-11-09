// from server: 100% by auto
// roc 2010-06 0058d830  unit: seg_00580000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0058d830
//
// 0058d830  8b442404             mov eax, dword ptr [esp + 4]
// 0058d834  a37057be00           mov dword ptr [0xbe5770], eax
// 0058d839  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?EnableWindowsTheming@CMFCButton@@SGXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
