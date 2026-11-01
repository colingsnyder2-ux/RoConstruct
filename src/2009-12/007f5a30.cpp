// from server: 100% by auto
// roc 2009-12 007f5a30  unit: ActiveDocView  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f5a30
//
// 007f5a30  8b442404             mov eax, dword ptr [esp + 4]
// 007f5a34  83f802               cmp eax, 2
// 007f5a37  7408                 je 0x7f5a41
// 007f5a39  83f803               cmp eax, 3
// 007f5a3c  7403                 je 0x7f5a41
// 007f5a3e  33c0                 xor eax, eax
// 007f5a40  c3                   ret 
// 007f5a41  b801000000           mov eax, 1
// 007f5a46  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ?IsKeyboardSelected@@YAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
