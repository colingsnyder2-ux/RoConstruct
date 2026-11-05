// from server: 100% by auto
// roc 2007-08 0068d060  unit: CXTPTabClientWnd  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0068d060
//
// 0068d060  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068d064  8b542408             mov edx, dword ptr [esp + 8]
// 0068d068  50                   push eax
// 0068d069  8b442408             mov eax, dword ptr [esp + 8]
// 0068d06d  52                   push edx
// 0068d06e  50                   push eax
// 0068d06f  e82cfbffff           call 0x68cba0
// 0068d074  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
