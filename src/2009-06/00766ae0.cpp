// from server: 100% by auto
// roc 2009-06 00766ae0  unit: CXTPCustomizeCommandsPage  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00766ae0
//
// 00766ae0  8b442404             mov eax, dword ptr [esp + 4]
// 00766ae4  83f804               cmp eax, 4
// 00766ae7  740d                 je 0x766af6
// 00766ae9  83f803               cmp eax, 3
// 00766aec  7408                 je 0x766af6
// 00766aee  83f802               cmp eax, 2
// 00766af1  7403                 je 0x766af6
// 00766af3  33c0                 xor eax, eax
// 00766af5  c3                   ret 
// 00766af6  b801000000           mov eax, 1
// 00766afb  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?IsAnimateType@@YAHW4XTPAnimationType@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
