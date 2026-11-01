// from server: 100% by auto
// roc 2009-06 0078eb80  unit: CXTPPropertyGridView  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078eb80
//
// 0078eb80  8b542404             mov edx, dword ptr [esp + 4]
// 0078eb84  8d41ac               lea eax, [ecx - 0x54]
// 0078eb87  c70200000000         mov dword ptr [edx], 0
// 0078eb8d  85c0                 test eax, eax
// 0078eb8f  742e                 je 0x78ebbf
// 0078eb91  83782000             cmp dword ptr [eax + 0x20], 0
// 0078eb95  7428                 je 0x78ebbf
// 0078eb97  85c0                 test eax, eax
// 0078eb99  7510                 jne 0x78ebab
// 0078eb9b  52                   push edx
// 0078eb9c  68e04e9200           push 0x924ee0
// 0078eba1  50                   push eax
// 0078eba2  50                   push eax
// 0078eba3  e8e82afdff           call 0x761690
// 0078eba8  c20400               ret 4
// 0078ebab  8b4020               mov eax, dword ptr [eax + 0x20]
// 0078ebae  52                   push edx
// 0078ebaf  68e04e9200           push 0x924ee0
// 0078ebb4  6a00                 push 0
// 0078ebb6  50                   push eax
// 0078ebb7  e8d42afdff           call 0x761690
// 0078ebbc  c20400               ret 4
// 0078ebbf  b805400080           mov eax, 0x80004005
// 0078ebc4  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleParent@CXTPPropertyGridView@@MAEJPAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
