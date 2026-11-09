// from server: 100% by auto
// roc 2011-06 00422dc0  unit: CRBXHTMLControlSite::XDocHostUIHandler  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00422dc0
//
// 00422dc0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00422dc4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00422dc8  50                   push eax
// 00422dc9  51                   push ecx
// 00422dca  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00422dce  81c114ffffff         add ecx, 0xffffff14
// 00422dd4  e8777a3e00           call 0x80a850
// 00422dd9  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?QueryInterface@CBrowserControlSite@@MAGJABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
