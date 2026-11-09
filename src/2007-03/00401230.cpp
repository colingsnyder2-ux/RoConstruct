// from server: 100% by auto
// roc 2007-03 00401230  unit: seg_00400000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401230
//
// 00401230  8b442404             mov eax, dword ptr [esp + 4]
// 00401234  85c0                 test eax, eax
// 00401236  56                   push esi
// 00401237  8bf1                 mov esi, ecx
// 00401239  741b                 je 0x401256
// 0040123b  6aff                 push -1
// 0040123d  50                   push eax
// 0040123e  e84dffffff           call 0x401190
// 00401243  83c408               add esp, 8
// 00401246  85c0                 test eax, eax
// 00401248  8906                 mov dword ptr [esi], eax
// 0040124a  7510                 jne 0x40125c
// 0040124c  680e000780           push 0x8007000e
// 00401251  e8aafdffff           call 0x401000
// 00401256  c70600000000         mov dword ptr [esi], 0
// 0040125c  8bc6                 mov eax, esi
// 0040125e  5e                   pop esi
// 0040125f  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??0CComBSTR@ATL@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
