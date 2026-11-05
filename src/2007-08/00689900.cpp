// from server: 100% by auto
// roc 2007-08 00689900  unit: CXTPTabClientWnd::CSingleWorkspace  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00689900
//
// 00689900  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00689904  8b542408             mov edx, dword ptr [esp + 8]
// 00689908  50                   push eax
// 00689909  8b442408             mov eax, dword ptr [esp + 8]
// 0068990d  52                   push edx
// 0068990e  50                   push eax
// 0068990f  e8acffffff           call 0x6898c0
// 00689914  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
