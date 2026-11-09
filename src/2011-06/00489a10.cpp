// from server: 100% by auto
// roc 2011-06 00489a10  unit: CSaveToRobloxDialog  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00489a10
//
// 00489a10  56                   push esi
// 00489a11  8bf1                 mov esi, ecx
// 00489a13  c706cc34a700         mov dword ptr [esi], 0xa734cc
// 00489a19  c74674a034a700       mov dword ptr [esi + 0x74], 0xa734a0
// 00489a20  e83b76f7ff           call 0x401060
// 00489a25  f644240801           test byte ptr [esp + 8], 1
// 00489a2a  7409                 je 0x489a35
// 00489a2c  56                   push esi
// 00489a2d  e826063800           call 0x80a058
// 00489a32  83c404               add esp, 4
// 00489a35  8bc6                 mov eax, esi
// 00489a37  5e                   pop esi
// 00489a38  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??_GCMultiPageDHtmlDialog@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
