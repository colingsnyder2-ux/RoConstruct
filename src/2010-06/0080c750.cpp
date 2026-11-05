// from server: 100% by auto
// roc 2010-06 0080c750  unit: CXTPTabClientWnd  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080c750
//
// 0080c750  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0080c754  8b542408             mov edx, dword ptr [esp + 8]
// 0080c758  50                   push eax
// 0080c759  8b442408             mov eax, dword ptr [esp + 8]
// 0080c75d  52                   push edx
// 0080c75e  50                   push eax
// 0080c75f  e8fcfaffff           call 0x80c260
// 0080c764  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
