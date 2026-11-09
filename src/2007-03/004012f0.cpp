// from server: 100% by auto
// roc 2007-03 004012f0  unit: seg_00400000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004012f0
//
// 004012f0  56                   push esi
// 004012f1  8bf1                 mov esi, ecx
// 004012f3  c70674377800         mov dword ptr [esi], 0x783774
// 004012f9  c7467448377800       mov dword ptr [esi + 0x74], 0x783748
// 00401300  e85bfdffff           call 0x401060
// 00401305  f644240801           test byte ptr [esp + 8], 1
// 0040130a  7409                 je 0x401315
// 0040130c  56                   push esi
// 0040130d  e8decd2100           call 0x61e0f0
// 00401312  83c404               add esp, 4
// 00401315  8bc6                 mov eax, esi
// 00401317  5e                   pop esi
// 00401318  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??_GCMultiPageDHtmlDialog@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
