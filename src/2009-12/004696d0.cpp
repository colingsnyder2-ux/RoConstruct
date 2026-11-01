// from server: 100% by auto
// roc 2009-12 004696d0  unit: CSaveToRobloxDialog  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004696d0
//
// 004696d0  56                   push esi
// 004696d1  8bf1                 mov esi, ecx
// 004696d3  c706ccf49a00         mov dword ptr [esi], 0x9af4cc
// 004696d9  c74674a0f49a00       mov dword ptr [esi + 0x74], 0x9af4a0
// 004696e0  e87b79f9ff           call 0x401060
// 004696e5  f644240801           test byte ptr [esp + 8], 1
// 004696ea  7409                 je 0x4696f5
// 004696ec  56                   push esi
// 004696ed  e868a13800           call 0x7f385a
// 004696f2  83c404               add esp, 4
// 004696f5  8bc6                 mov eax, esi
// 004696f7  5e                   pop esi
// 004696f8  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??_GCMultiPageDHtmlDialog@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
