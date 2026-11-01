// from server: 100% by auto
// roc 2009-12 00851aa0  unit: CXTPPropExchange  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00851aa0
//
// 00851aa0  56                   push esi
// 00851aa1  8bf1                 mov esi, ecx
// 00851aa3  e878e5ffff           call 0x850020
// 00851aa8  8b442408             mov eax, dword ptr [esp + 8]
// 00851aac  894644               mov dword ptr [esi + 0x44], eax
// 00851aaf  c7068cc49f00         mov dword ptr [esi], 0x9fc48c
// 00851ab5  8b4018               mov eax, dword ptr [eax + 0x18]
// 00851ab8  83e001               and eax, 1
// 00851abb  894628               mov dword ptr [esi + 0x28], eax
// 00851abe  8bc6                 mov eax, esi
// 00851ac0  5e                   pop esi
// 00851ac1  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ??0CXTPPropExchangeArchive@@QAE@AAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
