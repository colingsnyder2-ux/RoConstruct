// from server: 100% by auto
// roc 2009-12 008505d0  unit: CXTPPropExchangeArchive  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008505d0
//
// 008505d0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008505d4  8b542408             mov edx, dword ptr [esp + 8]
// 008505d8  8b4944               mov ecx, dword ptr [ecx + 0x44]
// 008505db  50                   push eax
// 008505dc  52                   push edx
// 008505dd  e8fa3dfaff           call 0x7f43dc
// 008505e2  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?Write@CXTPPropExchangeArchive@@UAEXPBDPBXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
