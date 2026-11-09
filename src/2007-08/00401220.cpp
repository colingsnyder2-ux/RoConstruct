// from server: 100% by auto
// roc 2007-08 00401220  unit: CSettingsDialog  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401220
//
// 00401220  8b442404             mov eax, dword ptr [esp + 4]
// 00401224  85c0                 test eax, eax
// 00401226  56                   push esi
// 00401227  8bf1                 mov esi, ecx
// 00401229  741b                 je 0x401246
// 0040122b  6aff                 push -1
// 0040122d  50                   push eax
// 0040122e  e84dffffff           call 0x401180
// 00401233  83c408               add esp, 8
// 00401236  85c0                 test eax, eax
// 00401238  8906                 mov dword ptr [esi], eax
// 0040123a  7510                 jne 0x40124c
// 0040123c  680e000780           push 0x8007000e
// 00401241  e8bafdffff           call 0x401000
// 00401246  c70600000000         mov dword ptr [esi], 0
// 0040124c  8bc6                 mov eax, esi
// 0040124e  5e                   pop esi
// 0040124f  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??0CComBSTR@ATL@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
