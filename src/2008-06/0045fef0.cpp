// from server: 100% by auto
// roc 2008-06 0045fef0  unit: CSaveToRobloxDialog  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045fef0
//
// 0045fef0  56                   push esi
// 0045fef1  8bf1                 mov esi, ecx
// 0045fef3  c70664a58100         mov dword ptr [esi], 0x81a564
// 0045fef9  c7467438a58100       mov dword ptr [esi + 0x74], 0x81a538
// 0045ff00  e84b11faff           call 0x401050
// 0045ff05  f644240801           test byte ptr [esp + 8], 1
// 0045ff0a  7409                 je 0x45ff15
// 0045ff0c  56                   push esi
// 0045ff0d  e868072400           call 0x6a067a
// 0045ff12  83c404               add esp, 4
// 0045ff15  8bc6                 mov eax, esi
// 0045ff17  5e                   pop esi
// 0045ff18  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??_GCMultiPageDHtmlDialog@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
