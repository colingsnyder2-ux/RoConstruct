// from server: 100% by auto
// roc 2008-06 00422930  unit: CSelectionTreeCtrl  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00422930
//
// 00422930  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00422934  8b542408             mov edx, dword ptr [esp + 8]
// 00422938  50                   push eax
// 00422939  8b442408             mov eax, dword ptr [esp + 8]
// 0042293d  52                   push edx
// 0042293e  50                   push eax
// 0042293f  e8dcb62b00           call 0x6de020
// 00422944  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
