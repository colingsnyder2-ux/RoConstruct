// from server: 100% by auto
// roc 2009-12 00419050  unit: CRBXHTMLControlSite::XDocHostUIHandler  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00419050
//
// 00419050  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00419054  81c114ffffff         add ecx, 0xffffff14
// 0041905a  e8e7af3d00           call 0x7f4046
// 0041905f  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?AddRef@CBrowserControlSite@@MAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
