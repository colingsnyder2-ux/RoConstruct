// from server: 100% by auto
// roc 2008-06 00704da0  unit: CXTPTabClientWnd  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00704da0
//
// 00704da0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00704da4  8b542408             mov edx, dword ptr [esp + 8]
// 00704da8  50                   push eax
// 00704da9  8b442408             mov eax, dword ptr [esp + 8]
// 00704dad  52                   push edx
// 00704dae  50                   push eax
// 00704daf  e8fcfaffff           call 0x7048b0
// 00704db4  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
