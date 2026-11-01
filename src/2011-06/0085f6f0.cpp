// from server: 100% by auto
// roc 2011-06 0085f6f0  unit: CXTPPropExchange  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0085f6f0
//
// 0085f6f0  8b01                 mov eax, dword ptr [ecx]
// 0085f6f2  8b405c               mov eax, dword ptr [eax + 0x5c]
// 0085f6f5  8d54240c             lea edx, [esp + 0xc]
// 0085f6f9  52                   push edx
// 0085f6fa  8d54240c             lea edx, [esp + 0xc]
// 0085f6fe  52                   push edx
// 0085f6ff  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0085f703  52                   push edx
// 0085f704  ffd0                 call eax
// 0085f706  f7d8                 neg eax
// 0085f708  1bc0                 sbb eax, eax
// 0085f70a  2344240c             and eax, dword ptr [esp + 0xc]
// 0085f70e  c20c00               ret 0xc
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?Read@CXTPPropExchange@@UAEIPBDPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
