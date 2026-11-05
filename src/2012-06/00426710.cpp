// from server: 100% by auto
// roc 2012-06 00426710  unit: CRBXHTMLControlSite::XDocHostUIHandler  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00426710
//
// 00426710  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00426714  81c114ffffff         add ecx, 0xffffff14
// 0042671a  e8a5c15500           call 0x9828c4
// 0042671f  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?AddRef@CBrowserControlSite@@MAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
