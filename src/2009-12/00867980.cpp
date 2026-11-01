// from server: 100% by auto
// roc 2009-12 00867980  unit: CXTPPropertyGridView  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00867980
//
// 00867980  8d442404             lea eax, [esp + 4]
// 00867984  50                   push eax
// 00867985  e81640fdff           call 0x83b9a0
// 0086798a  85c0                 test eax, eax
// 0086798c  740d                 je 0x86799b
// 0086798e  83f8ff               cmp eax, -1
// 00867991  7408                 je 0x86799b
// 00867993  b857000780           mov eax, 0x80070057
// 00867998  c21400               ret 0x14
// 0086799b  683cef9f00           push 0x9fef3c
// 008679a0  ff1550ba9800         call dword ptr [0x98ba50]
// 008679a6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008679aa  8901                 mov dword ptr [ecx], eax
// 008679ac  33c0                 xor eax, eax
// 008679ae  c21400               ret 0x14
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleName@CXTPPropertyGridView@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
