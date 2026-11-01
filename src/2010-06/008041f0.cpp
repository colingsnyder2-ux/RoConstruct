// from server: 100% by auto
// roc 2010-06 008041f0  unit: CXTPPropExchange  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008041f0
//
// 008041f0  8b01                 mov eax, dword ptr [ecx]
// 008041f2  8b405c               mov eax, dword ptr [eax + 0x5c]
// 008041f5  8d54240c             lea edx, [esp + 0xc]
// 008041f9  52                   push edx
// 008041fa  8d54240c             lea edx, [esp + 0xc]
// 008041fe  52                   push edx
// 008041ff  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00804203  52                   push edx
// 00804204  ffd0                 call eax
// 00804206  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?Write@CXTPPropExchange@@UAEXPBDPBXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
