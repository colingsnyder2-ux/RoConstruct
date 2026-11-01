// from server: 100% by auto
// roc 2007-03 0062f0a0  unit: seg_00620000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062f0a0
//
// 0062f0a0  8b442404             mov eax, dword ptr [esp + 4]
// 0062f0a4  83f802               cmp eax, 2
// 0062f0a7  7408                 je 0x62f0b1
// 0062f0a9  83f803               cmp eax, 3
// 0062f0ac  7403                 je 0x62f0b1
// 0062f0ae  33c0                 xor eax, eax
// 0062f0b0  c3                   ret 
// 0062f0b1  b801000000           mov eax, 1
// 0062f0b6  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ?IsKeyboardSelected@@YAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
