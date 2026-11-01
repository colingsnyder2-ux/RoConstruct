// from server: 100% by auto
// roc 2011-06 0085f6d0  unit: CXTPPropExchange  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0085f6d0
//
// 0085f6d0  8b01                 mov eax, dword ptr [ecx]
// 0085f6d2  8b405c               mov eax, dword ptr [eax + 0x5c]
// 0085f6d5  8d54240c             lea edx, [esp + 0xc]
// 0085f6d9  52                   push edx
// 0085f6da  8d54240c             lea edx, [esp + 0xc]
// 0085f6de  52                   push edx
// 0085f6df  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0085f6e3  52                   push edx
// 0085f6e4  ffd0                 call eax
// 0085f6e6  c20c00               ret 0xc
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?Write@CXTPPropExchange@@UAEXPBDPBXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
