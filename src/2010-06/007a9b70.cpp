// from server: 100% by auto
// roc 2010-06 007a9b70  unit: ActiveDocView  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007a9b70
//
// 007a9b70  8b442404             mov eax, dword ptr [esp + 4]
// 007a9b74  83f802               cmp eax, 2
// 007a9b77  7408                 je 0x7a9b81
// 007a9b79  83f803               cmp eax, 3
// 007a9b7c  7403                 je 0x7a9b81
// 007a9b7e  33c0                 xor eax, eax
// 007a9b80  c3                   ret 
// 007a9b81  b801000000           mov eax, 1
// 007a9b86  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControl.cpp (function ?IsKeyboardSelected@@YAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControl.cpp
