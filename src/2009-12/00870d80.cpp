// from server: 100% by auto
// roc 2009-12 00870d80  unit: CXTPHookManager::CHookSink  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00870d80
//
// 00870d80  837c240400           cmp dword ptr [esp + 4], 0
// 00870d85  56                   push esi
// 00870d86  8bf1                 mov esi, ecx
// 00870d88  742c                 je 0x870db6
// 00870d8a  837e0400             cmp dword ptr [esi + 4], 0
// 00870d8e  753b                 jne 0x870dcb
// 00870d90  57                   push edi
// 00870d91  e8882df8ff           call 0x7f3b1e
// 00870d96  8b7808               mov edi, dword ptr [eax + 8]
// 00870d99  ff1524b29800         call dword ptr [0x98b224]
// 00870d9f  50                   push eax
// 00870da0  57                   push edi
// 00870da1  68300a8700           push 0x870a30
// 00870da6  6a02                 push 2
// 00870da8  ff15d0ca9800         call dword ptr [0x98cad0]
// 00870dae  5f                   pop edi
// 00870daf  894604               mov dword ptr [esi + 4], eax
// 00870db2  5e                   pop esi
// 00870db3  c20400               ret 4
// 00870db6  8b4604               mov eax, dword ptr [esi + 4]
// 00870db9  85c0                 test eax, eax
// 00870dbb  740e                 je 0x870dcb
// 00870dbd  50                   push eax
// 00870dbe  ff15ccca9800         call dword ptr [0x98cacc]
// 00870dc4  c7460400000000       mov dword ptr [esi + 4], 0
// 00870dcb  5e                   pop esi
// 00870dcc  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPKeyboardManager.cpp (function ?SetupKeyboardHook@CXTPKeyboardManager@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPKeyboardManager.cpp
