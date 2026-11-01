// from server: 100% by auto
// roc 2009-06 0071fd50  unit: CPatchedControlComboBox  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071fd50
//
// 0071fd50  8d442404             lea eax, [esp + 4]
// 0071fd54  50                   push eax
// 0071fd55  e8760e0400           call 0x760bd0
// 0071fd5a  85c0                 test eax, eax
// 0071fd5c  7408                 je 0x71fd66
// 0071fd5e  b857000780           mov eax, 0x80070057
// 0071fd63  c21400               ret 0x14
// 0071fd66  686c218f00           push 0x8f216c
// 0071fd6b  ff15d8e98900         call dword ptr [0x89e9d8]
// 0071fd71  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0071fd75  8901                 mov dword ptr [ecx], eax
// 0071fd77  33c0                 xor eax, eax
// 0071fd79  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ?GetAccessibleDefaultAction@CXTPControl@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
