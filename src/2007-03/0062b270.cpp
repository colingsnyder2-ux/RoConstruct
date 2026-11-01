// from server: 100% by auto
// roc 2007-03 0062b270  unit: seg_00620000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062b270
//
// 0062b270  8b442408             mov eax, dword ptr [esp + 8]
// 0062b274  50                   push eax
// 0062b275  8b442408             mov eax, dword ptr [esp + 8]
// 0062b279  50                   push eax
// 0062b27a  50                   push eax
// 0062b27b  e870ffffff           call 0x62b1f0
// 0062b280  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?SetIcons@CXTPImageManager@@QAEHIW4XTPImageState@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
