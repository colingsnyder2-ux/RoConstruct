// from server: 100% by auto
// roc 2010-06 00804630  unit: CXTPPropExchangeArchive  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804630
//
// 00804630  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00804634  8b542408             mov edx, dword ptr [esp + 8]
// 00804638  8b4944               mov ecx, dword ptr [ecx + 0x44]
// 0080463b  50                   push eax
// 0080463c  52                   push edx
// 0080463d  e8da3efaff           call 0x7a851c
// 00804642  c20c00               ret 0xc
// library xtp-13.2.1/Source\Common\XTPPropExchange.cpp (function ?Write@CXTPPropExchangeArchive@@UAEXPBDPBXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPPropExchange.cpp
