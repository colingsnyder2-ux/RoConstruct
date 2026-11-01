// from server: 100% by auto
// roc 2007-03 0066e180  unit: seg_00660000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066e180
//
// 0066e180  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0066e184  8b542408             mov edx, dword ptr [esp + 8]
// 0066e188  50                   push eax
// 0066e189  8b442408             mov eax, dword ptr [esp + 8]
// 0066e18d  52                   push edx
// 0066e18e  50                   push eax
// 0066e18f  e8acffffff           call 0x66e140
// 0066e194  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d BinaryInput.cpp
