// from server: 100% by auto
// roc 2012-06 0042aaf0  unit: CSelectionTreeCtrl  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0042aaf0
//
// 0042aaf0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0042aaf4  8b542408             mov edx, dword ptr [esp + 8]
// 0042aaf8  50                   push eax
// 0042aaf9  8b442408             mov eax, dword ptr [esp + 8]
// 0042aafd  52                   push edx
// 0042aafe  50                   push eax
// 0042aaff  e8fc6a5900           call 0x9c1600
// 0042ab04  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
