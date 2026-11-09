// from server: 100% by auto
// roc 2010-06 007c4640  unit: CXTPImageManager  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c4640
//
// 007c4640  8b442408             mov eax, dword ptr [esp + 8]
// 007c4644  50                   push eax
// 007c4645  8b442408             mov eax, dword ptr [esp + 8]
// 007c4649  50                   push eax
// 007c464a  50                   push eax
// 007c464b  e870ffffff           call 0x7c45c0
// 007c4650  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?SetIcons@CXTPImageManager@@QAEHIW4XTPImageState@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
