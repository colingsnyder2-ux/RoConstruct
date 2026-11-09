// from server: 100% by auto
// roc 2011-06 0058bec0  unit: std::Vlength_error::U?$error_info_injector::?$clone_impl  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0058bec0
//
// 0058bec0  8b442404             mov eax, dword ptr [esp + 4]
// 0058bec4  a3d4e5cc00           mov dword ptr [0xcce5d4], eax
// 0058bec9  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?EnableWindowsTheming@CMFCButton@@SGXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
