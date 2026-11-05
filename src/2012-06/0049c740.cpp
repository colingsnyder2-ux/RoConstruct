// from server: 100% by auto
// roc 2012-06 0049c740  unit: CSaveToRobloxDialog  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0049c740
//
// 0049c740  56                   push esi
// 0049c741  8bf1                 mov esi, ecx
// 0049c743  c70674fab500         mov dword ptr [esi], 0xb5fa74
// 0049c749  c7467448fab500       mov dword ptr [esi + 0x74], 0xb5fa48
// 0049c750  e8fb48f6ff           call 0x401050
// 0049c755  f644240801           test byte ptr [esp + 8], 1
// 0049c75a  7409                 je 0x49c765
// 0049c75c  56                   push esi
// 0049c75d  e8b2594e00           call 0x982114
// 0049c762  83c404               add esp, 4
// 0049c765  8bc6                 mov eax, esi
// 0049c767  5e                   pop esi
// 0049c768  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??_GCMultiPageDHtmlDialog@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
