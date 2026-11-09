// from server: 100% by auto
// roc 2010-06 00805b20  unit: CXTPPropExchange  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00805b20
//
// 00805b20  56                   push esi
// 00805b21  8bf1                 mov esi, ecx
// 00805b23  e858e5ffff           call 0x804080
// 00805b28  8b442408             mov eax, dword ptr [esp + 8]
// 00805b2c  894644               mov dword ptr [esi + 0x44], eax
// 00805b2f  c7064c07a600         mov dword ptr [esi], 0xa6074c
// 00805b35  8b4018               mov eax, dword ptr [eax + 0x18]
// 00805b38  83e001               and eax, 1
// 00805b3b  894628               mov dword ptr [esi + 0x28], eax
// 00805b3e  8bc6                 mov eax, esi
// 00805b40  5e                   pop esi
// 00805b41  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPPropExchange.cpp (function ??0CXTPPropExchangeArchive@@QAE@AAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPPropExchange.cpp
