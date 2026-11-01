// from server: 100% by auto
// roc 2009-06 00781d60  unit: CXTPDockingPane  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00781d60
//
// 00781d60  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00781d64  b903000000           mov ecx, 3
// 00781d69  668908               mov word ptr [eax], cx
// 00781d6c  c7400800000000       mov dword ptr [eax + 8], 0
// 00781d73  33c0                 xor eax, eax
// 00781d75  c20c00               ret 0xc
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?AccessibleHitTest@CXTPDockingPane@@MAEJJJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
