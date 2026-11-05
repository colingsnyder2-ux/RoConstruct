// from server: 100% by auto
// roc 2009-06 0041d0f0  unit: CSelectionTreeCtrl  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041d0f0
//
// 0041d0f0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041d0f4  8b542408             mov edx, dword ptr [esp + 8]
// 0041d0f8  50                   push eax
// 0041d0f9  8b442408             mov eax, dword ptr [esp + 8]
// 0041d0fd  52                   push edx
// 0041d0fe  50                   push eax
// 0041d0ff  e8ecb73300           call 0x7588f0
// 0041d104  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
