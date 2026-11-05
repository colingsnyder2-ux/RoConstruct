// from server: 100% by auto
// roc 2010-06 00846d30  unit: CXTPDockBar  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00846d30
//
// 00846d30  8b442404             mov eax, dword ptr [esp + 4]
// 00846d34  56                   push esi
// 00846d35  50                   push eax
// 00846d36  8bf1                 mov esi, ecx
// 00846d38  e8a3ffffff           call 0x846ce0
// 00846d3d  83f8ff               cmp eax, -1
// 00846d40  7414                 je 0x846d56
// 00846d42  8b16                 mov edx, dword ptr [esi]
// 00846d44  6a00                 push 0
// 00846d46  50                   push eax
// 00846d47  8b8220010000         mov eax, dword ptr [edx + 0x120]
// 00846d4d  6802040000           push 0x402
// 00846d52  8bce                 mov ecx, esi
// 00846d54  ffd0                 call eax
// 00846d56  5e                   pop esi
// 00846d57  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPReBar.cpp (function ?DeleteToolBar@CXTPReBar@@QAEXPAVCXTPToolBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPReBar.cpp
