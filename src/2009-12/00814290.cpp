// from server: 100% by auto
// roc 2009-12 00814290  unit: CXTPCommandBar  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00814290
//
// 00814290  e83b02ffff           call 0x8044d0
// 00814295  85c0                 test eax, eax
// 00814297  7506                 jne 0x81429f
// 00814299  b801000000           mov eax, 1
// 0081429e  c3                   ret 
// 0081429f  8b80b0000000         mov eax, dword ptr [eax + 0xb0]
// 008142a5  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?IsKeyboardCuesVisible@CXTPCommandBar@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
