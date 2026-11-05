// from server: 100% by auto
// roc 2011-06 00422da0  unit: CRBXHTMLControlSite::XDocHostUIHandler  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00422da0
//
// 00422da0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00422da4  81c114ffffff         add ecx, 0xffffff14
// 00422daa  e89b7a3e00           call 0x80a84a
// 00422daf  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?AddRef@CBrowserControlSite@@MAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
