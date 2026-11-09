// from server: 100% by auto
// roc 2007-03 004594a0  unit: seg_00450000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004594a0
//
// 004594a0  56                   push esi
// 004594a1  8bf1                 mov esi, ecx
// 004594a3  c706cc2b7900         mov dword ptr [esi], 0x792bcc
// 004594a9  c74674a02b7900       mov dword ptr [esi + 0x74], 0x792ba0
// 004594b0  e8ab7bfaff           call 0x401060
// 004594b5  f644240801           test byte ptr [esp + 8], 1
// 004594ba  7409                 je 0x4594c5
// 004594bc  56                   push esi
// 004594bd  e82e4c1c00           call 0x61e0f0
// 004594c2  83c404               add esp, 4
// 004594c5  8bc6                 mov eax, esi
// 004594c7  5e                   pop esi
// 004594c8  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??_GCMultiPageDHtmlDialog@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
