// from server: 100% by auto
// roc 2007-03 00671100  unit: seg_00670000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00671100
//
// 00671100  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00671104  8b542408             mov edx, dword ptr [esp + 8]
// 00671108  50                   push eax
// 00671109  8b442408             mov eax, dword ptr [esp + 8]
// 0067110d  52                   push edx
// 0067110e  50                   push eax
// 0067110f  e8dcfaffff           call 0x670bf0
// 00671114  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d BinaryInput.cpp
