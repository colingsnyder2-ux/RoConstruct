// from server: 100% by auto
// roc 2008-06 007015c0  unit: CXTPTabClientWnd::CSingleWorkspace  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007015c0
//
// 007015c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007015c4  8b542408             mov edx, dword ptr [esp + 8]
// 007015c8  50                   push eax
// 007015c9  8b442408             mov eax, dword ptr [esp + 8]
// 007015cd  52                   push edx
// 007015ce  50                   push eax
// 007015cf  e8acffffff           call 0x701580
// 007015d4  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
