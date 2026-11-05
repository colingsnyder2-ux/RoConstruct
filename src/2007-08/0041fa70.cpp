// from server: 100% by auto
// roc 2007-08 0041fa70  unit: CSelectionTreeCtrl  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041fa70
//
// 0041fa70  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041fa74  8b542408             mov edx, dword ptr [esp + 8]
// 0041fa78  50                   push eax
// 0041fa79  8b442408             mov eax, dword ptr [esp + 8]
// 0041fa7d  52                   push edx
// 0041fa7e  50                   push eax
// 0041fa7f  e8ec772400           call 0x667270
// 0041fa84  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
