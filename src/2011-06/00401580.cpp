// from server: 100% by auto
// roc 2011-06 00401580  unit: CAboutRobloxDialog  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00401580
//
// 00401580  56                   push esi
// 00401581  8bf1                 mov esi, ecx
// 00401583  c706ecb3a500         mov dword ptr [esi], 0xa5b3ec
// 00401589  c74674c0b3a500       mov dword ptr [esi + 0x74], 0xa5b3c0
// 00401590  e8cbfaffff           call 0x401060
// 00401595  f644240801           test byte ptr [esp + 8], 1
// 0040159a  7409                 je 0x4015a5
// 0040159c  56                   push esi
// 0040159d  e8b68a4000           call 0x80a058
// 004015a2  83c404               add esp, 4
// 004015a5  8bc6                 mov eax, esi
// 004015a7  5e                   pop esi
// 004015a8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??_GCMultiPageDHtmlDialog@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
