// from server: 100% by auto
// roc 2010-06 00419190  unit: CRBXHTMLControlSite::XDocHostUIHandler  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00419190
//
// 00419190  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00419194  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00419198  50                   push eax
// 00419199  51                   push ecx
// 0041919a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041919e  81c114ffffff         add ecx, 0xffffff14
// 004191a4  e8e9ef3800           call 0x7a8192
// 004191a9  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?QueryInterface@CBrowserControlSite@@MAGJABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
