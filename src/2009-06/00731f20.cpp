// from server: 100% by auto
// roc 2009-06 00731f20  unit: CXTPCommandBar  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00731f20
//
// 00731f20  8b4178               mov eax, dword ptr [ecx + 0x78]
// 00731f23  83f801               cmp eax, 1
// 00731f26  7503                 jne 0x731f2b
// 00731f28  c20400               ret 4
// 00731f2b  83f802               cmp eax, 2
// 00731f2e  7510                 jne 0x731f40
// 00731f30  8b442404             mov eax, dword ptr [esp + 4]
// 00731f34  50                   push eax
// 00731f35  e8d6f30300           call 0x771310
// 00731f3a  83c404               add esp, 4
// 00731f3d  c20400               ret 4
// 00731f40  33c0                 xor eax, eax
// 00731f42  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?IsDrawReverted@CXTPImageManager@@QBEHPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
