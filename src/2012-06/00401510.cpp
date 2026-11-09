// from server: 100% by auto
// roc 2012-06 00401510  unit: CAboutRobloxDialog  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00401510
//
// 00401510  56                   push esi
// 00401511  8bf1                 mov esi, ecx
// 00401513  c706cc2cb400         mov dword ptr [esi], 0xb42ccc
// 00401519  c74674a02cb400       mov dword ptr [esi + 0x74], 0xb42ca0
// 00401520  e82bfbffff           call 0x401050
// 00401525  f644240801           test byte ptr [esp + 8], 1
// 0040152a  7409                 je 0x401535
// 0040152c  56                   push esi
// 0040152d  e8e20b5800           call 0x982114
// 00401532  83c404               add esp, 4
// 00401535  8bc6                 mov eax, esi
// 00401537  5e                   pop esi
// 00401538  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??_GCMultiPageDHtmlDialog@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
