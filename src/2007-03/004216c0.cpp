// from server: 100% by auto
// roc 2007-03 004216c0  unit: seg_00420000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004216c0
//
// 004216c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004216c4  8b542408             mov edx, dword ptr [esp + 8]
// 004216c8  50                   push eax
// 004216c9  8b442408             mov eax, dword ptr [esp + 8]
// 004216cd  52                   push edx
// 004216ce  50                   push eax
// 004216cf  e8dc1b2300           call 0x6532b0
// 004216d4  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d BinaryInput.cpp
