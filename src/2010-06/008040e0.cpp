// from server: 100% by auto
// roc 2010-06 008040e0  unit: CXTPPropExchange  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008040e0
//
// 008040e0  8b442404             mov eax, dword ptr [esp + 4]
// 008040e4  c7413001000000       mov dword ptr [ecx + 0x30], 1
// 008040eb  8b502c               mov edx, dword ptr [eax + 0x2c]
// 008040ee  89512c               mov dword ptr [ecx + 0x2c], edx
// 008040f1  8b5020               mov edx, dword ptr [eax + 0x20]
// 008040f4  895120               mov dword ptr [ecx + 0x20], edx
// 008040f7  8b5034               mov edx, dword ptr [eax + 0x34]
// 008040fa  895134               mov dword ptr [ecx + 0x34], edx
// 008040fd  8b503c               mov edx, dword ptr [eax + 0x3c]
// 00804100  89513c               mov dword ptr [ecx + 0x3c], edx
// 00804103  8b4040               mov eax, dword ptr [eax + 0x40]
// 00804106  894140               mov dword ptr [ecx + 0x40], eax
// 00804109  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPPropExchange.cpp (function ?InitSection@CXTPPropExchange@@IAEXPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPPropExchange.cpp
