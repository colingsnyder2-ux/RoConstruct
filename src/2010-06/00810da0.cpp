// from server: 100% by auto
// roc 2010-06 00810da0  unit: CXTPDockingPane  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00810da0
//
// 00810da0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00810da4  b903000000           mov ecx, 3
// 00810da9  668908               mov word ptr [eax], cx
// 00810dac  c7400800000000       mov dword ptr [eax + 8], 0
// 00810db3  33c0                 xor eax, eax
// 00810db5  c20c00               ret 0xc
// library xtp-13.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?AccessibleHitTest@CXTPDockingPane@@MAEJJJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPane.cpp
