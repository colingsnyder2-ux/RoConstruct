// from server: 100% by auto
// roc 2009-06 00779ed0  unit: CXTPTabClientWnd::CSingleWorkspace  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00779ed0
//
// 00779ed0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00779ed4  8b542408             mov edx, dword ptr [esp + 8]
// 00779ed8  50                   push eax
// 00779ed9  8b442408             mov eax, dword ptr [esp + 8]
// 00779edd  52                   push edx
// 00779ede  50                   push eax
// 00779edf  e8acffffff           call 0x779e90
// 00779ee4  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
