// from server: 100% by auto
// roc 2011-06 0058bee0  unit: std::Vlength_error::U?$error_info_injector::?$clone_impl  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0058bee0
//
// 0058bee0  8b442404             mov eax, dword ptr [esp + 4]
// 0058bee4  a3846cd100           mov dword ptr [0xd16c84], eax
// 0058bee9  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?EnableWindowsTheming@CMFCButton@@SGXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
