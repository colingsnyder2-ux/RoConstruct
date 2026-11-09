// from server: 100% by auto
// roc 2009-06 00418c40  unit: CRBXHTMLControlSite::XDocHostUIHandler  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00418c40
//
// 00418c40  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00418c44  81c114ffffff         add ecx, 0xffffff14
// 00418c4a  e8d5053000           call 0x719224
// 00418c4f  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?AddRef@CBrowserControlSite@@MAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
