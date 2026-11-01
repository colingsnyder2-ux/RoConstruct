// from server: 100% by auto
// roc 2007-03 0062f9b0  unit: seg_00620000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062f9b0
//
// 0062f9b0  8d442404             lea eax, [esp + 4]
// 0062f9b4  50                   push eax
// 0062f9b5  e8f6650500           call 0x685fb0
// 0062f9ba  85c0                 test eax, eax
// 0062f9bc  7408                 je 0x62f9c6
// 0062f9be  b857000780           mov eax, 0x80070057
// 0062f9c3  c21400               ret 0x14
// 0062f9c6  68903b7c00           push 0x7c3b90
// 0062f9cb  ff15ccea7700         call dword ptr [0x77eacc]
// 0062f9d1  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0062f9d5  8901                 mov dword ptr [ecx], eax
// 0062f9d7  33c0                 xor eax, eax
// 0062f9d9  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ?GetAccessibleDefaultAction@CXTPControl@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
