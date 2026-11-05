// from server: 100% by auto
// roc 2012-06 00426750  unit: CRBXHTMLControlSite::XDocHostUIHandler  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00426750
//
// 00426750  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00426754  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00426758  50                   push eax
// 00426759  51                   push ecx
// 0042675a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0042675e  81c114ffffff         add ecx, 0xffffff14
// 00426764  e867c15500           call 0x9828d0
// 00426769  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?QueryInterface@CBrowserControlSite@@MAGJABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
