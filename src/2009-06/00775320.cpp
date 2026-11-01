// from server: 100% by auto
// roc 2009-06 00775320  unit: CXTPPropExchange  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00775320
//
// 00775320  8b442404             mov eax, dword ptr [esp + 4]
// 00775324  c7413001000000       mov dword ptr [ecx + 0x30], 1
// 0077532b  8b502c               mov edx, dword ptr [eax + 0x2c]
// 0077532e  89512c               mov dword ptr [ecx + 0x2c], edx
// 00775331  8b5020               mov edx, dword ptr [eax + 0x20]
// 00775334  895120               mov dword ptr [ecx + 0x20], edx
// 00775337  8b5034               mov edx, dword ptr [eax + 0x34]
// 0077533a  895134               mov dword ptr [ecx + 0x34], edx
// 0077533d  8b503c               mov edx, dword ptr [eax + 0x3c]
// 00775340  89513c               mov dword ptr [ecx + 0x3c], edx
// 00775343  8b4040               mov eax, dword ptr [eax + 0x40]
// 00775346  894140               mov dword ptr [ecx + 0x40], eax
// 00775349  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?InitSection@CXTPPropExchange@@IAEXPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
