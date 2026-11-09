// from server: 100% by auto
// roc 2009-06 00418c20  unit: CRBXHTMLControlSite::XDocHostUIHandler  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00418c20
//
// 00418c20  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00418c24  81c114ffffff         add ecx, 0xffffff14
// 00418c2a  e8ef053000           call 0x71921e
// 00418c2f  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?AddRef@CBrowserControlSite@@MAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
