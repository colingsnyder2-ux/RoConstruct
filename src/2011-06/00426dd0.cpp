// from server: 100% by auto
// roc 2011-06 00426dd0  unit: CSelectionTreeCtrl  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00426dd0
//
// 00426dd0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00426dd4  8b542408             mov edx, dword ptr [esp + 8]
// 00426dd8  50                   push eax
// 00426dd9  8b442408             mov eax, dword ptr [esp + 8]
// 00426ddd  52                   push edx
// 00426dde  50                   push eax
// 00426ddf  e89c234200           call 0x849180
// 00426de4  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
