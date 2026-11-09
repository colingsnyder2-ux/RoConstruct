// from server: 100% by auto
// roc 2010-06 0080e950  unit: CXTPStatusBar  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080e950
//
// 0080e950  56                   push esi
// 0080e951  8bf1                 mov esi, ecx
// 0080e953  e81896f9ff           call 0x7a7f70
// 0080e958  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0080e95c  898eac000000         mov dword ptr [esi + 0xac], ecx
// 0080e962  5e                   pop esi
// 0080e963  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPStatusBar.cpp (function ?OnSetMinHeight@CXTPStatusBar@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPStatusBar.cpp
