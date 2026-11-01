// from server: 100% by auto
// roc 2009-06 00776d50  unit: CXTPPropExchange  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00776d50
//
// 00776d50  56                   push esi
// 00776d51  8bf1                 mov esi, ecx
// 00776d53  e868e5ffff           call 0x7752c0
// 00776d58  8b442408             mov eax, dword ptr [esp + 8]
// 00776d5c  894644               mov dword ptr [esi + 0x44], eax
// 00776d5f  c706e4bf8f00         mov dword ptr [esi], 0x8fbfe4
// 00776d65  8b4018               mov eax, dword ptr [eax + 0x18]
// 00776d68  83e001               and eax, 1
// 00776d6b  894628               mov dword ptr [esi + 0x28], eax
// 00776d6e  8bc6                 mov eax, esi
// 00776d70  5e                   pop esi
// 00776d71  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ??0CXTPPropExchangeArchive@@QAE@AAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
