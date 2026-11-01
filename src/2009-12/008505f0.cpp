// from server: 100% by auto
// roc 2009-12 008505f0  unit: CXTPPropExchangeArchive  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008505f0
//
// 008505f0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008505f4  8b542408             mov edx, dword ptr [esp + 8]
// 008505f8  8b4944               mov ecx, dword ptr [ecx + 0x44]
// 008505fb  50                   push eax
// 008505fc  52                   push edx
// 008505fd  e8d43dfaff           call 0x7f43d6
// 00850602  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?Write@CXTPPropExchangeArchive@@UAEXPBDPBXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
