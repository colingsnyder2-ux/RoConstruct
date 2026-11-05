// from server: 100% by auto
// roc 2009-06 00460b40  unit: CSaveToRobloxDialog  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00460b40
//
// 00460b40  56                   push esi
// 00460b41  8bf1                 mov esi, ecx
// 00460b43  c70624af8b00         mov dword ptr [esi], 0x8baf24
// 00460b49  c74674f8ae8b00       mov dword ptr [esi + 0x74], 0x8baef8
// 00460b50  e81b05faff           call 0x401070
// 00460b55  f644240801           test byte ptr [esp + 8], 1
// 00460b5a  7409                 je 0x460b65
// 00460b5c  56                   push esi
// 00460b5d  e8d07e2b00           call 0x718a32
// 00460b62  83c404               add esp, 4
// 00460b65  8bc6                 mov eax, esi
// 00460b67  5e                   pop esi
// 00460b68  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??_GCMultiPageDHtmlDialog@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
