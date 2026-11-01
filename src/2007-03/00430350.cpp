// from server: 100% by auto
// roc 2007-03 00430350  unit: seg_00430000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00430350
//
// 00430350  8b442404             mov eax, dword ptr [esp + 4]
// 00430354  83f802               cmp eax, 2
// 00430357  740d                 je 0x430366
// 00430359  83f803               cmp eax, 3
// 0043035c  7408                 je 0x430366
// 0043035e  83f805               cmp eax, 5
// 00430361  7403                 je 0x430366
// 00430363  33c0                 xor eax, eax
// 00430365  c3                   ret 
// 00430366  b801000000           mov eax, 1
// 0043036b  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?IsVerticalPosition@@YAHW4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDefaultTheme.cpp
