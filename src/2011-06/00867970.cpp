// from server: 100% by auto
// roc 2011-06 00867970  unit: CXTPTabClientWnd  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00867970
//
// 00867970  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00867974  8b542408             mov edx, dword ptr [esp + 8]
// 00867978  50                   push eax
// 00867979  8b442408             mov eax, dword ptr [esp + 8]
// 0086797d  52                   push edx
// 0086797e  50                   push eax
// 0086797f  e8fcfaffff           call 0x867480
// 00867984  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
