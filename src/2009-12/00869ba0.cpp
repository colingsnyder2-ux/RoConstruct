// from server: 100% by auto
// roc 2009-12 00869ba0  unit: CXTPPropertyGridView  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00869ba0
//
// 00869ba0  8b542404             mov edx, dword ptr [esp + 4]
// 00869ba4  8d41ac               lea eax, [ecx - 0x54]
// 00869ba7  c70200000000         mov dword ptr [edx], 0
// 00869bad  85c0                 test eax, eax
// 00869baf  742e                 je 0x869bdf
// 00869bb1  83782000             cmp dword ptr [eax + 0x20], 0
// 00869bb5  7428                 je 0x869bdf
// 00869bb7  85c0                 test eax, eax
// 00869bb9  7510                 jne 0x869bcb
// 00869bbb  52                   push edx
// 00869bbc  68a04ba200           push 0xa24ba0
// 00869bc1  50                   push eax
// 00869bc2  50                   push eax
// 00869bc3  e89828fdff           call 0x83c460
// 00869bc8  c20400               ret 4
// 00869bcb  8b4020               mov eax, dword ptr [eax + 0x20]
// 00869bce  52                   push edx
// 00869bcf  68a04ba200           push 0xa24ba0
// 00869bd4  6a00                 push 0
// 00869bd6  50                   push eax
// 00869bd7  e88428fdff           call 0x83c460
// 00869bdc  c20400               ret 4
// 00869bdf  b805400080           mov eax, 0x80004005
// 00869be4  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleParent@CXTPPropertyGridView@@MAEJPAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
