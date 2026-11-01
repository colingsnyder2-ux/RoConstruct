// from server: 100% by auto
// roc 2009-12 00419090  unit: CRBXHTMLControlSite::XDocHostUIHandler  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00419090
//
// 00419090  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00419094  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00419098  50                   push eax
// 00419099  51                   push ecx
// 0041909a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041909e  81c114ffffff         add ecx, 0xffffff14
// 004190a4  e8a9af3d00           call 0x7f4052
// 004190a9  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?QueryInterface@CBrowserControlSite@@MAGJABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
