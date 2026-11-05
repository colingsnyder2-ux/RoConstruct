// from server: 100% by auto
// roc 2009-12 004015a0  unit: CAboutRobloxDialog  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004015a0
//
// 004015a0  56                   push esi
// 004015a1  8bf1                 mov esi, ecx
// 004015a3  c706a4f29900         mov dword ptr [esi], 0x99f2a4
// 004015a9  c7467478f29900       mov dword ptr [esi + 0x74], 0x99f278
// 004015b0  e8abfaffff           call 0x401060
// 004015b5  f644240801           test byte ptr [esp + 8], 1
// 004015ba  7409                 je 0x4015c5
// 004015bc  56                   push esi
// 004015bd  e898223f00           call 0x7f385a
// 004015c2  83c404               add esp, 4
// 004015c5  8bc6                 mov eax, esi
// 004015c7  5e                   pop esi
// 004015c8  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??_GCMultiPageDHtmlDialog@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
