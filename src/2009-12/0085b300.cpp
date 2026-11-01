// from server: 100% by auto
// roc 2009-12 0085b300  unit: CXTPStatusBar  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085b300
//
// 0085b300  8b442404             mov eax, dword ptr [esp + 4]
// 0085b304  85c0                 test eax, eax
// 0085b306  7c14                 jl 0x85b31c
// 0085b308  3b81a0000000         cmp eax, dword ptr [ecx + 0xa0]
// 0085b30e  7d0c                 jge 0x85b31c
// 0085b310  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 0085b316  8b0481               mov eax, dword ptr [ecx + eax*4]
// 0085b319  c20400               ret 4
// 0085b31c  33c0                 xor eax, eax
// 0085b31e  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPStatusBar.cpp (function ?GetPane@CXTPStatusBar@@QBEPAVCXTPStatusBarPane@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPStatusBar.cpp
