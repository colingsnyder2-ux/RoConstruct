// from server: 100% by auto
// roc 2009-06 005c8ac0  unit: seg_005c0000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c8ac0
//
// 005c8ac0  8b442404             mov eax, dword ptr [esp + 4]
// 005c8ac4  a3d049a200           mov dword ptr [0xa249d0], eax
// 005c8ac9  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?EnableWindowsTheming@CMFCButton@@SGXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
