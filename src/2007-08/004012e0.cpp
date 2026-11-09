// from server: 100% by auto
// roc 2007-08 004012e0  unit: CAboutRobloxDialog  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004012e0
//
// 004012e0  56                   push esi
// 004012e1  8bf1                 mov esi, ecx
// 004012e3  c70674477800         mov dword ptr [esi], 0x784774
// 004012e9  c7467448477800       mov dword ptr [esi + 0x74], 0x784748
// 004012f0  e84bfdffff           call 0x401040
// 004012f5  f644240801           test byte ptr [esp + 8], 1
// 004012fa  7409                 je 0x401305
// 004012fc  56                   push esi
// 004012fd  e860e92200           call 0x62fc62
// 00401302  83c404               add esp, 4
// 00401305  8bc6                 mov eax, esi
// 00401307  5e                   pop esi
// 00401308  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??_GCMultiPageDHtmlDialog@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
