// from server: 100% by auto
// roc 2007-03 00696630  unit: seg_00690000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00696630
//
// 00696630  8b442404             mov eax, dword ptr [esp + 4]
// 00696634  56                   push esi
// 00696635  50                   push eax
// 00696636  8bf1                 mov esi, ecx
// 00696638  e8a3ffffff           call 0x6965e0
// 0069663d  83f8ff               cmp eax, -1
// 00696640  7414                 je 0x696656
// 00696642  8b16                 mov edx, dword ptr [esi]
// 00696644  6a00                 push 0
// 00696646  50                   push eax
// 00696647  8b8218010000         mov eax, dword ptr [edx + 0x118]
// 0069664d  6802040000           push 0x402
// 00696652  8bce                 mov ecx, esi
// 00696654  ffd0                 call eax
// 00696656  5e                   pop esi
// 00696657  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPReBar.cpp (function ?DeleteToolBar@CXTPReBar@@QAEXPAVCXTPToolBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPReBar.cpp
