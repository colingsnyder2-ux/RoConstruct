// from server: 100% by auto
// roc 2010-06 007aa4b0  unit: CPatchedControlComboBox  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007aa4b0
//
// 007aa4b0  8d442404             lea eax, [esp + 4]
// 007aa4b4  50                   push eax
// 007aa4b5  e836560400           call 0x7efaf0
// 007aa4ba  85c0                 test eax, eax
// 007aa4bc  7408                 je 0x7aa4c6
// 007aa4be  b857000780           mov eax, 0x80070057
// 007aa4c3  c21400               ret 0x14
// 007aa4c6  68a85aa500           push 0xa55aa8
// 007aa4cb  ff1580aa9e00         call dword ptr [0x9eaa80]
// 007aa4d1  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007aa4d5  8901                 mov dword ptr [ecx], eax
// 007aa4d7  33c0                 xor eax, eax
// 007aa4d9  c21400               ret 0x14
// library xtp-13.2.1/Source\CommandBars\XTPControl.cpp (function ?GetAccessibleDefaultAction@CXTPControl@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControl.cpp
