// from server: 100% by auto
// roc 2012-06 009dfee0  unit: CXTPTabClientWnd  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009dfee0
//
// 009dfee0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 009dfee4  8b542408             mov edx, dword ptr [esp + 8]
// 009dfee8  50                   push eax
// 009dfee9  8b442408             mov eax, dword ptr [esp + 8]
// 009dfeed  52                   push edx
// 009dfeee  50                   push eax
// 009dfeef  e8fcfaffff           call 0x9df9f0
// 009dfef4  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
