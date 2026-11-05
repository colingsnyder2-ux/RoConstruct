// from server: 100% by auto
// roc 2009-12 0041d760  unit: CSelectionTreeCtrl  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041d760
//
// 0041d760  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041d764  8b542408             mov edx, dword ptr [esp + 8]
// 0041d768  50                   push eax
// 0041d769  8b442408             mov eax, dword ptr [esp + 8]
// 0041d76d  52                   push edx
// 0041d76e  50                   push eax
// 0041d76f  e8fc5f4100           call 0x833770
// 0041d774  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d BinaryInput.cpp
