// from server: 100% by auto
// roc 2009-12 008090a0  unit: CXTPCommandBar  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008090a0
//
// 008090a0  8b4178               mov eax, dword ptr [ecx + 0x78]
// 008090a3  83f801               cmp eax, 1
// 008090a6  7503                 jne 0x8090ab
// 008090a8  c20400               ret 4
// 008090ab  83f802               cmp eax, 2
// 008090ae  7510                 jne 0x8090c0
// 008090b0  8b442404             mov eax, dword ptr [esp + 4]
// 008090b4  50                   push eax
// 008090b5  e856300400           call 0x84c110
// 008090ba  83c404               add esp, 4
// 008090bd  c20400               ret 4
// 008090c0  33c0                 xor eax, eax
// 008090c2  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?IsDrawReverted@CXTPImageManager@@QBEHPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
