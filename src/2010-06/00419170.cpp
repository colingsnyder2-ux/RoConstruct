// from server: 100% by auto
// roc 2010-06 00419170  unit: CRBXHTMLControlSite::XDocHostUIHandler  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00419170
//
// 00419170  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00419174  81c114ffffff         add ecx, 0xffffff14
// 0041917a  e80df03800           call 0x7a818c
// 0041917f  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?AddRef@CBrowserControlSite@@MAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
