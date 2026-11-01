// from server: 100% by auto
// roc 2007-03 0045b170  unit: seg_00450000  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0045b170
//
// 0045b170  56                   push esi
// 0045b171  8bf1                 mov esi, ecx
// 0045b173  8b4604               mov eax, dword ptr [esi + 4]
// 0045b176  85c0                 test eax, eax
// 0045b178  c706482f7900         mov dword ptr [esi], 0x792f48
// 0045b17e  7409                 je 0x45b189
// 0045b180  50                   push eax
// 0045b181  e82e321c00           call 0x61e3b4
// 0045b186  83c404               add esp, 4
// 0045b189  f644240801           test byte ptr [esp + 8], 1
// 0045b18e  7409                 je 0x45b199
// 0045b190  56                   push esi
// 0045b191  e85a2f1c00           call 0x61e0f0
// 0045b196  83c404               add esp, 4
// 0045b199  8bc6                 mov eax, esi
// 0045b19b  5e                   pop esi
// 0045b19c  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??_G?$CArray@HABH@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
