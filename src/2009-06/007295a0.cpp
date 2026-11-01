// from server: 100% by auto
// roc 2009-06 007295a0  unit: CXTPCommandBar  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007295a0
//
// 007295a0  e8eb3d0000           call 0x72d390
// 007295a5  85c0                 test eax, eax
// 007295a7  7506                 jne 0x7295af
// 007295a9  b801000000           mov eax, 1
// 007295ae  c3                   ret 
// 007295af  8b80b0000000         mov eax, dword ptr [eax + 0xb0]
// 007295b5  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?IsKeyboardCuesVisible@CXTPCommandBar@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
