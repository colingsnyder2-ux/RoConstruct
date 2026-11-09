// from server: 100% by auto
// roc 2009-12 008587d0  unit: CXTPTabClientWnd  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008587d0
//
// 008587d0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008587d4  8b542408             mov edx, dword ptr [esp + 8]
// 008587d8  50                   push eax
// 008587d9  8b442408             mov eax, dword ptr [esp + 8]
// 008587dd  52                   push edx
// 008587de  50                   push eax
// 008587df  e8fcfaffff           call 0x8582e0
// 008587e4  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d BinaryInput.cpp
