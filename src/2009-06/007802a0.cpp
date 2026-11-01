// from server: 100% by auto
// roc 2009-06 007802a0  unit: CXTPStatusBar  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007802a0
//
// 007802a0  8b442404             mov eax, dword ptr [esp + 4]
// 007802a4  85c0                 test eax, eax
// 007802a6  7c14                 jl 0x7802bc
// 007802a8  3b81a0000000         cmp eax, dword ptr [ecx + 0xa0]
// 007802ae  7d0c                 jge 0x7802bc
// 007802b0  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 007802b6  8b0481               mov eax, dword ptr [ecx + eax*4]
// 007802b9  c20400               ret 4
// 007802bc  33c0                 xor eax, eax
// 007802be  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPStatusBar.cpp (function ?GetPane@CXTPStatusBar@@QBEPAVCXTPStatusBarPane@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPStatusBar.cpp
