// from server: 100% by auto
// roc 2008-06 00401290  unit: CAboutRobloxDialog  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401290
//
// 00401290  56                   push esi
// 00401291  8bf1                 mov esi, ecx
// 00401293  c706c4aa8000         mov dword ptr [esi], 0x80aac4
// 00401299  c7467498aa8000       mov dword ptr [esi + 0x74], 0x80aa98
// 004012a0  e8abfdffff           call 0x401050
// 004012a5  f644240801           test byte ptr [esp + 8], 1
// 004012aa  7409                 je 0x4012b5
// 004012ac  56                   push esi
// 004012ad  e8c8f32900           call 0x6a067a
// 004012b2  83c404               add esp, 4
// 004012b5  8bc6                 mov eax, esi
// 004012b7  5e                   pop esi
// 004012b8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??_GCMultiPageDHtmlDialog@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
