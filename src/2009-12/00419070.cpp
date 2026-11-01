// from server: 100% by auto
// roc 2009-12 00419070  unit: CRBXHTMLControlSite::XDocHostUIHandler  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00419070
//
// 00419070  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00419074  81c114ffffff         add ecx, 0xffffff14
// 0041907a  e8cdaf3d00           call 0x7f404c
// 0041907f  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?AddRef@CBrowserControlSite@@MAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
