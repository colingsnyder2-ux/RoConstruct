// from server: 100% by auto
// roc 2009-06 007939a0  unit: CXTPHookManager::CHookSink  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007939a0
//
// 007939a0  83ec08               sub esp, 8
// 007939a3  56                   push esi
// 007939a4  8bf1                 mov esi, ecx
// 007939a6  8b460c               mov eax, dword ptr [esi + 0xc]
// 007939a9  f7d8                 neg eax
// 007939ab  1bc0                 sbb eax, eax
// 007939ad  c744240400000000     mov dword ptr [esp + 4], 0
// 007939b5  89442408             mov dword ptr [esp + 8], eax
// 007939b9  742d                 je 0x7939e8
// 007939bb  57                   push edi
// 007939bc  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007939c0  8d442408             lea eax, [esp + 8]
// 007939c4  50                   push eax
// 007939c5  8d4c2418             lea ecx, [esp + 0x18]
// 007939c9  51                   push ecx
// 007939ca  8d542414             lea edx, [esp + 0x14]
// 007939ce  52                   push edx
// 007939cf  8bce                 mov ecx, esi
// 007939d1  e89af6ffff           call 0x793070
// 007939d6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007939da  57                   push edi
// 007939db  e810feffff           call 0x7937f0
// 007939e0  837c240c00           cmp dword ptr [esp + 0xc], 0
// 007939e5  75d9                 jne 0x7939c0
// 007939e7  5f                   pop edi
// 007939e8  5e                   pop esi
// 007939e9  83c408               add esp, 8
// 007939ec  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPHookManager.cpp (function ?RemoveAll@CXTPHookManager@@QAEXPAVCXTPHookManagerHookAble@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPHookManager.cpp
