// from server: 100% by auto
// roc 2009-06 00401670  unit: CAboutRobloxDialog  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00401670
//
// 00401670  56                   push esi
// 00401671  8bf1                 mov esi, ecx
// 00401673  c70644c78a00         mov dword ptr [esi], 0x8ac744
// 00401679  c7467418c78a00       mov dword ptr [esi + 0x74], 0x8ac718
// 00401680  e8ebf9ffff           call 0x401070
// 00401685  f644240801           test byte ptr [esp + 8], 1
// 0040168a  7409                 je 0x401695
// 0040168c  56                   push esi
// 0040168d  e8a0733100           call 0x718a32
// 00401692  83c404               add esp, 4
// 00401695  8bc6                 mov eax, esi
// 00401697  5e                   pop esi
// 00401698  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??_GCMultiPageDHtmlDialog@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
