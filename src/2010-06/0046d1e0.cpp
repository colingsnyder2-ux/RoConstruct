// from server: 100% by auto
// roc 2010-06 0046d1e0  unit: CSaveToRobloxDialog  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0046d1e0
//
// 0046d1e0  56                   push esi
// 0046d1e1  8bf1                 mov esi, ecx
// 0046d1e3  c7064401a100         mov dword ptr [esi], 0xa10144
// 0046d1e9  c746741801a100       mov dword ptr [esi + 0x74], 0xa10118
// 0046d1f0  e86b3ef9ff           call 0x401060
// 0046d1f5  f644240801           test byte ptr [esp + 8], 1
// 0046d1fa  7409                 je 0x46d205
// 0046d1fc  56                   push esi
// 0046d1fd  e898a73300           call 0x7a799a
// 0046d202  83c404               add esp, 4
// 0046d205  8bc6                 mov eax, esi
// 0046d207  5e                   pop esi
// 0046d208  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??_GCMultiPageDHtmlDialog@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
