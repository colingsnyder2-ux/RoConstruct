// from server: 100% by auto
// roc 2010-06 007f5950  unit: CXTPCustomizeCommandsPage  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f5950
//
// 007f5950  8b442404             mov eax, dword ptr [esp + 4]
// 007f5954  83f804               cmp eax, 4
// 007f5957  740d                 je 0x7f5966
// 007f5959  83f803               cmp eax, 3
// 007f595c  7408                 je 0x7f5966
// 007f595e  83f802               cmp eax, 2
// 007f5961  7403                 je 0x7f5966
// 007f5963  33c0                 xor eax, eax
// 007f5965  c3                   ret 
// 007f5966  b801000000           mov eax, 1
// 007f596b  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?IsAnimateType@@YAHW4XTPAnimationType@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPopupBar.cpp
