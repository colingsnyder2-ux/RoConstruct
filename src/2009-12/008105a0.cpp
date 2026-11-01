// from server: 100% by auto
// roc 2009-12 008105a0  unit: CXTPImageManager  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008105a0
//
// 008105a0  8b442408             mov eax, dword ptr [esp + 8]
// 008105a4  50                   push eax
// 008105a5  8b442408             mov eax, dword ptr [esp + 8]
// 008105a9  50                   push eax
// 008105aa  50                   push eax
// 008105ab  e870ffffff           call 0x810520
// 008105b0  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?SetIcons@CXTPImageManager@@QAEHIW4XTPImageState@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
