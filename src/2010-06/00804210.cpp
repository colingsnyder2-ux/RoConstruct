// from server: 100% by auto
// roc 2010-06 00804210  unit: CXTPPropExchange  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804210
//
// 00804210  8b01                 mov eax, dword ptr [ecx]
// 00804212  8b405c               mov eax, dword ptr [eax + 0x5c]
// 00804215  8d54240c             lea edx, [esp + 0xc]
// 00804219  52                   push edx
// 0080421a  8d54240c             lea edx, [esp + 0xc]
// 0080421e  52                   push edx
// 0080421f  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00804223  52                   push edx
// 00804224  ffd0                 call eax
// 00804226  f7d8                 neg eax
// 00804228  1bc0                 sbb eax, eax
// 0080422a  2344240c             and eax, dword ptr [esp + 0xc]
// 0080422e  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?Read@CXTPPropExchange@@UAEIPBDPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
