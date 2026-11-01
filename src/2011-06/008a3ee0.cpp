// from server: 100% by auto
// roc 2011-06 008a3ee0  unit: CXTPDockBar  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008a3ee0
//
// 008a3ee0  8b442404             mov eax, dword ptr [esp + 4]
// 008a3ee4  56                   push esi
// 008a3ee5  50                   push eax
// 008a3ee6  8bf1                 mov esi, ecx
// 008a3ee8  e8a3ffffff           call 0x8a3e90
// 008a3eed  83f8ff               cmp eax, -1
// 008a3ef0  7414                 je 0x8a3f06
// 008a3ef2  8b16                 mov edx, dword ptr [esi]
// 008a3ef4  6a00                 push 0
// 008a3ef6  50                   push eax
// 008a3ef7  8b8220010000         mov eax, dword ptr [edx + 0x120]
// 008a3efd  6802040000           push 0x402
// 008a3f02  8bce                 mov ecx, esi
// 008a3f04  ffd0                 call eax
// 008a3f06  5e                   pop esi
// 008a3f07  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPReBar.cpp (function ?DeleteToolBar@CXTPReBar@@QAEXPAVCXTPToolBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPReBar.cpp
