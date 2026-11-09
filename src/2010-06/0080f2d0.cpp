// from server: 100% by auto
// roc 2010-06 0080f2d0  unit: CXTPStatusBar  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080f2d0
//
// 0080f2d0  8b442404             mov eax, dword ptr [esp + 4]
// 0080f2d4  85c0                 test eax, eax
// 0080f2d6  7c14                 jl 0x80f2ec
// 0080f2d8  3b81a0000000         cmp eax, dword ptr [ecx + 0xa0]
// 0080f2de  7d0c                 jge 0x80f2ec
// 0080f2e0  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 0080f2e6  8b0481               mov eax, dword ptr [ecx + eax*4]
// 0080f2e9  c20400               ret 4
// 0080f2ec  33c0                 xor eax, eax
// 0080f2ee  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPStatusBar.cpp (function ?GetPane@CXTPStatusBar@@QBEPAVCXTPStatusBarPane@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPStatusBar.cpp
