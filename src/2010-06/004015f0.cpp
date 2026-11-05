// from server: 100% by auto
// roc 2010-06 004015f0  unit: CAboutRobloxDialog  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004015f0
//
// 004015f0  56                   push esi
// 004015f1  8bf1                 mov esi, ecx
// 004015f3  c70644fe9f00         mov dword ptr [esi], 0x9ffe44
// 004015f9  c7467418fe9f00       mov dword ptr [esi + 0x74], 0x9ffe18
// 00401600  e85bfaffff           call 0x401060
// 00401605  f644240801           test byte ptr [esp + 8], 1
// 0040160a  7409                 je 0x401615
// 0040160c  56                   push esi
// 0040160d  e888633a00           call 0x7a799a
// 00401612  83c404               add esp, 4
// 00401615  8bc6                 mov eax, esi
// 00401617  5e                   pop esi
// 00401618  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??_GCMultiPageDHtmlDialog@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
