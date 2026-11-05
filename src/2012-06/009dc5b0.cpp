// from server: 100% by auto
// roc 2012-06 009dc5b0  unit: CXTPTabClientWnd::CSingleWorkspace  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009dc5b0
//
// 009dc5b0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 009dc5b4  8b542408             mov edx, dword ptr [esp + 8]
// 009dc5b8  50                   push eax
// 009dc5b9  8b442408             mov eax, dword ptr [esp + 8]
// 009dc5bd  52                   push edx
// 009dc5be  50                   push eax
// 009dc5bf  e8acffffff           call 0x9dc570
// 009dc5c4  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
