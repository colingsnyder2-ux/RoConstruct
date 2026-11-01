// from server: 100% by auto
// roc 2009-12 00850080  unit: CXTPPropExchange  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00850080
//
// 00850080  8b442404             mov eax, dword ptr [esp + 4]
// 00850084  c7413001000000       mov dword ptr [ecx + 0x30], 1
// 0085008b  8b502c               mov edx, dword ptr [eax + 0x2c]
// 0085008e  89512c               mov dword ptr [ecx + 0x2c], edx
// 00850091  8b5020               mov edx, dword ptr [eax + 0x20]
// 00850094  895120               mov dword ptr [ecx + 0x20], edx
// 00850097  8b5034               mov edx, dword ptr [eax + 0x34]
// 0085009a  895134               mov dword ptr [ecx + 0x34], edx
// 0085009d  8b503c               mov edx, dword ptr [eax + 0x3c]
// 008500a0  89513c               mov dword ptr [ecx + 0x3c], edx
// 008500a3  8b4040               mov eax, dword ptr [eax + 0x40]
// 008500a6  894140               mov dword ptr [ecx + 0x40], eax
// 008500a9  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?InitSection@CXTPPropExchange@@IAEXPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
