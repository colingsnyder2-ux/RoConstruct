// from server: 100% by auto
// roc 2010-06 0081b990  unit: CXTPPropertyGridView  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081b990
//
// 0081b990  8d442404             lea eax, [esp + 4]
// 0081b994  50                   push eax
// 0081b995  e85641fdff           call 0x7efaf0
// 0081b99a  85c0                 test eax, eax
// 0081b99c  740d                 je 0x81b9ab
// 0081b99e  83f8ff               cmp eax, -1
// 0081b9a1  7408                 je 0x81b9ab
// 0081b9a3  b857000780           mov eax, 0x80070057
// 0081b9a8  c21400               ret 0x14
// 0081b9ab  682c32a600           push 0xa6322c
// 0081b9b0  ff1580aa9e00         call dword ptr [0x9eaa80]
// 0081b9b6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0081b9ba  8901                 mov dword ptr [ecx], eax
// 0081b9bc  33c0                 xor eax, eax
// 0081b9be  c21400               ret 0x14
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleName@CXTPPropertyGridView@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
