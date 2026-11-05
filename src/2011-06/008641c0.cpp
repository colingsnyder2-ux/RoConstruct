// from server: 100% by auto
// roc 2011-06 008641c0  unit: CXTPTabClientWnd::CSingleWorkspace  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008641c0
//
// 008641c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008641c4  8b542408             mov edx, dword ptr [esp + 8]
// 008641c8  50                   push eax
// 008641c9  8b442408             mov eax, dword ptr [esp + 8]
// 008641cd  52                   push edx
// 008641ce  50                   push eax
// 008641cf  e8acffffff           call 0x864180
// 008641d4  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
