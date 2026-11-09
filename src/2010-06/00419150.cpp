// from server: 100% by auto
// roc 2010-06 00419150  unit: CRBXHTMLControlSite::XDocHostUIHandler  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00419150
//
// 00419150  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00419154  81c114ffffff         add ecx, 0xffffff14
// 0041915a  e827f03800           call 0x7a8186
// 0041915f  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?AddRef@CBrowserControlSite@@MAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
