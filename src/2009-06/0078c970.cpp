// from server: 100% by auto
// roc 2009-06 0078c970  unit: CXTPPropertyGridView  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078c970
//
// 0078c970  8d442404             lea eax, [esp + 4]
// 0078c974  50                   push eax
// 0078c975  e85642fdff           call 0x760bd0
// 0078c97a  85c0                 test eax, eax
// 0078c97c  740d                 je 0x78c98b
// 0078c97e  83f8ff               cmp eax, -1
// 0078c981  7408                 je 0x78c98b
// 0078c983  b857000780           mov eax, 0x80070057
// 0078c988  c21400               ret 0x14
// 0078c98b  68acea8f00           push 0x8feaac
// 0078c990  ff15d8e98900         call dword ptr [0x89e9d8]
// 0078c996  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0078c99a  8901                 mov dword ptr [ecx], eax
// 0078c99c  33c0                 xor eax, eax
// 0078c99e  c21400               ret 0x14
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleName@CXTPPropertyGridView@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
