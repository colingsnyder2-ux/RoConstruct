// from server: 100% by auto
// roc 2009-06 00418c60  unit: CRBXHTMLControlSite::XDocHostUIHandler  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00418c60
//
// 00418c60  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00418c64  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00418c68  50                   push eax
// 00418c69  51                   push ecx
// 00418c6a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00418c6e  81c114ffffff         add ecx, 0xffffff14
// 00418c74  e8b1053000           call 0x71922a
// 00418c79  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?QueryInterface@CBrowserControlSite@@MAGJABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
