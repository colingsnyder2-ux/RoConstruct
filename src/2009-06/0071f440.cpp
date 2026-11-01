// from server: 100% by auto
// roc 2009-06 0071f440  unit: CXTPControlComboBoxAutoCompleteWnd  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071f440
//
// 0071f440  8b442404             mov eax, dword ptr [esp + 4]
// 0071f444  83f802               cmp eax, 2
// 0071f447  7408                 je 0x71f451
// 0071f449  83f803               cmp eax, 3
// 0071f44c  7403                 je 0x71f451
// 0071f44e  33c0                 xor eax, eax
// 0071f450  c3                   ret 
// 0071f451  b801000000           mov eax, 1
// 0071f456  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ?IsKeyboardSelected@@YAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
