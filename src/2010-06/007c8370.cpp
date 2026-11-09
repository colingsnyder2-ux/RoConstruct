// from server: 100% by auto
// roc 2010-06 007c8370  unit: CXTPCommandBar  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c8370
//
// 007c8370  e85b02ffff           call 0x7b85d0
// 007c8375  85c0                 test eax, eax
// 007c8377  7506                 jne 0x7c837f
// 007c8379  b801000000           mov eax, 1
// 007c837e  c3                   ret 
// 007c837f  8b80b0000000         mov eax, dword ptr [eax + 0xb0]
// 007c8385  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?IsKeyboardCuesVisible@CXTPCommandBar@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
