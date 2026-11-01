// from server: 100% by auto
// roc 2009-06 00775880  unit: CXTPPropExchangeArchive  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00775880
//
// 00775880  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00775884  8b542408             mov edx, dword ptr [esp + 8]
// 00775888  8b4944               mov ecx, dword ptr [ecx + 0x44]
// 0077588b  50                   push eax
// 0077588c  52                   push edx
// 0077588d  e8163dfaff           call 0x7195a8
// 00775892  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?Write@CXTPPropExchangeArchive@@UAEXPBDPBXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
