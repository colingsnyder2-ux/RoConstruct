// from server: 100% by auto
// roc 2009-06 00722720  unit: CRobloxControlColorSelector  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00722720
//
// 00722720  56                   push esi
// 00722721  6a3c                 push 0x3c
// 00722723  8bf1                 mov esi, ecx
// 00722725  6a00                 push 0
// 00722727  56                   push esi
// 00722728  e84775ffff           call 0x719c74
// 0072272d  83c40c               add esp, 0xc
// 00722730  8bc6                 mov eax, esi
// 00722732  5e                   pop esi
// 00722733  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ??0CLogFont@CXTPPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
