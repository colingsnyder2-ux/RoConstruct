// from server: 100% by auto
// roc 2010-06 00808cd0  unit: CXTPTabClientWnd::CSingleWorkspace  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00808cd0
//
// 00808cd0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00808cd4  8b542408             mov edx, dword ptr [esp + 8]
// 00808cd8  50                   push eax
// 00808cd9  8b442408             mov eax, dword ptr [esp + 8]
// 00808cdd  52                   push edx
// 00808cde  50                   push eax
// 00808cdf  e8acffffff           call 0x808c90
// 00808ce4  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
