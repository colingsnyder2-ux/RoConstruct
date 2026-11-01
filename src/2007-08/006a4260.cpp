// from server: 100% by auto
// roc 2007-08 006a4260  unit: CXTPMouseManager  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a4260
//
// 006a4260  8b442404             mov eax, dword ptr [esp + 4]
// 006a4264  56                   push esi
// 006a4265  50                   push eax
// 006a4266  8bf1                 mov esi, ecx
// 006a4268  e8a3ffffff           call 0x6a4210
// 006a426d  83f8ff               cmp eax, -1
// 006a4270  7414                 je 0x6a4286
// 006a4272  8b16                 mov edx, dword ptr [esi]
// 006a4274  6a00                 push 0
// 006a4276  50                   push eax
// 006a4277  8b8218010000         mov eax, dword ptr [edx + 0x118]
// 006a427d  6802040000           push 0x402
// 006a4282  8bce                 mov ecx, esi
// 006a4284  ffd0                 call eax
// 006a4286  5e                   pop esi
// 006a4287  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPReBar.cpp (function ?DeleteToolBar@CXTPReBar@@QAEXPAVCXTPToolBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPReBar.cpp
