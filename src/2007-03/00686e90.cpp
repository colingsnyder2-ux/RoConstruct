// from server: 100% by auto
// roc 2007-03 00686e90  unit: seg_00680000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00686e90
//
// 00686e90  8d442404             lea eax, [esp + 4]
// 00686e94  50                   push eax
// 00686e95  e816f1ffff           call 0x685fb0
// 00686e9a  85c0                 test eax, eax
// 00686e9c  740d                 je 0x686eab
// 00686e9e  83f8ff               cmp eax, -1
// 00686ea1  7408                 je 0x686eab
// 00686ea3  b857000780           mov eax, 0x80070057
// 00686ea8  c21400               ret 0x14
// 00686eab  68ccea7c00           push 0x7ceacc
// 00686eb0  ff15ccea7700         call dword ptr [0x77eacc]
// 00686eb6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00686eba  8901                 mov dword ptr [ecx], eax
// 00686ebc  33c0                 xor eax, eax
// 00686ebe  c21400               ret 0x14
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleName@CXTPPropertyGridView@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
