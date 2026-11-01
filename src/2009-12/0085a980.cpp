// from server: 100% by auto
// roc 2009-12 0085a980  unit: CXTPStatusBar  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085a980
//
// 0085a980  56                   push esi
// 0085a981  8bf1                 mov esi, ecx
// 0085a983  e8a894f9ff           call 0x7f3e30
// 0085a988  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0085a98c  898eac000000         mov dword ptr [esi + 0xac], ecx
// 0085a992  5e                   pop esi
// 0085a993  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPStatusBar.cpp (function ?OnSetMinHeight@CXTPStatusBar@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPStatusBar.cpp
