// from server: 100% by auto
// roc 2009-06 007394b0  unit: CXTPImageManager  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007394b0
//
// 007394b0  8b442408             mov eax, dword ptr [esp + 8]
// 007394b4  50                   push eax
// 007394b5  8b442408             mov eax, dword ptr [esp + 8]
// 007394b9  50                   push eax
// 007394ba  50                   push eax
// 007394bb  e870ffffff           call 0x739430
// 007394c0  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?SetIcons@CXTPImageManager@@QAEHIW4XTPImageState@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
