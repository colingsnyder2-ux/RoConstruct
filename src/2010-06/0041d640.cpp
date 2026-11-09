// from server: 100% by auto
// roc 2010-06 0041d640  unit: CSelectionTreeCtrl  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041d640
//
// 0041d640  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041d644  8b542408             mov edx, dword ptr [esp + 8]
// 0041d648  50                   push eax
// 0041d649  8b442408             mov eax, dword ptr [esp + 8]
// 0041d64d  52                   push edx
// 0041d64e  50                   push eax
// 0041d64f  e8dca23c00           call 0x7e7930
// 0041d654  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
