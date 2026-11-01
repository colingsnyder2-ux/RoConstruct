// from server: 100% by auto
// roc 2009-12 00870d10  unit: CXTPHookManager::CHookSink  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00870d10
//
// 00870d10  83ec08               sub esp, 8
// 00870d13  56                   push esi
// 00870d14  8bf1                 mov esi, ecx
// 00870d16  8b460c               mov eax, dword ptr [esi + 0xc]
// 00870d19  f7d8                 neg eax
// 00870d1b  1bc0                 sbb eax, eax
// 00870d1d  c744240400000000     mov dword ptr [esp + 4], 0
// 00870d25  89442408             mov dword ptr [esp + 8], eax
// 00870d29  742d                 je 0x870d58
// 00870d2b  57                   push edi
// 00870d2c  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00870d30  8d442408             lea eax, [esp + 8]
// 00870d34  50                   push eax
// 00870d35  8d4c2418             lea ecx, [esp + 0x18]
// 00870d39  51                   push ecx
// 00870d3a  8d542414             lea edx, [esp + 0x14]
// 00870d3e  52                   push edx
// 00870d3f  8bce                 mov ecx, esi
// 00870d41  e8da8af9ff           call 0x809820
// 00870d46  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00870d4a  57                   push edi
// 00870d4b  e810feffff           call 0x870b60
// 00870d50  837c240c00           cmp dword ptr [esp + 0xc], 0
// 00870d55  75d9                 jne 0x870d30
// 00870d57  5f                   pop edi
// 00870d58  5e                   pop esi
// 00870d59  83c408               add esp, 8
// 00870d5c  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPHookManager.cpp (function ?RemoveAll@CXTPHookManager@@QAEXPAVCXTPHookManagerHookAble@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPHookManager.cpp
