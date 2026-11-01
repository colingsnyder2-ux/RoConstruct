// from server: 100% by auto
// roc 2007-03 0062b5e0  unit: seg_00620000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062b5e0
//
// 0062b5e0  e82bd70000           call 0x638d10
// 0062b5e5  85c0                 test eax, eax
// 0062b5e7  7506                 jne 0x62b5ef
// 0062b5e9  b801000000           mov eax, 1
// 0062b5ee  c3                   ret 
// 0062b5ef  8b80b0000000         mov eax, dword ptr [eax + 0xb0]
// 0062b5f5  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?IsKeyboardCuesVisible@CXTPCommandBar@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
