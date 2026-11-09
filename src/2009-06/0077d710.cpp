// from server: 100% by auto
// roc 2009-06 0077d710  unit: CXTPTabClientWnd  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077d710
//
// 0077d710  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0077d714  8b542408             mov edx, dword ptr [esp + 8]
// 0077d718  50                   push eax
// 0077d719  8b442408             mov eax, dword ptr [esp + 8]
// 0077d71d  52                   push edx
// 0077d71e  50                   push eax
// 0077d71f  e8fcfaffff           call 0x77d220
// 0077d724  c20c00               ret 0xc
// library rbx2016-g3d/BinaryInput.cpp (function ?readBool8@BinaryInput@G3D@@QAEXPA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryInput.cpp
