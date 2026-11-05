// from server: 100% by auto
// roc 2007-08 0045bd10  unit: CSaveToRobloxDialog  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045bd10
//
// 0045bd10  56                   push esi
// 0045bd11  8bf1                 mov esi, ecx
// 0045bd13  c706443e7900         mov dword ptr [esi], 0x793e44
// 0045bd19  c74674183e7900       mov dword ptr [esi + 0x74], 0x793e18
// 0045bd20  e81b53faff           call 0x401040
// 0045bd25  f644240801           test byte ptr [esp + 8], 1
// 0045bd2a  7409                 je 0x45bd35
// 0045bd2c  56                   push esi
// 0045bd2d  e8303f1d00           call 0x62fc62
// 0045bd32  83c404               add esp, 4
// 0045bd35  8bc6                 mov eax, esi
// 0045bd37  5e                   pop esi
// 0045bd38  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??_GCMultiPageDHtmlDialog@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
