// from server: 100% by auto
// roc 2009-12 00870dd0  unit: CXTPHookManager::CHookSink  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00870dd0
//
// 00870dd0  837c240400           cmp dword ptr [esp + 4], 0
// 00870dd5  56                   push esi
// 00870dd6  8bf1                 mov esi, ecx
// 00870dd8  742c                 je 0x870e06
// 00870dda  837e0800             cmp dword ptr [esi + 8], 0
// 00870dde  753b                 jne 0x870e1b
// 00870de0  57                   push edi
// 00870de1  e8382df8ff           call 0x7f3b1e
// 00870de6  8b7808               mov edi, dword ptr [eax + 8]
// 00870de9  ff1524b29800         call dword ptr [0x98b224]
// 00870def  50                   push eax
// 00870df0  57                   push edi
// 00870df1  6840098700           push 0x870940
// 00870df6  6a04                 push 4
// 00870df8  ff15d0ca9800         call dword ptr [0x98cad0]
// 00870dfe  5f                   pop edi
// 00870dff  894608               mov dword ptr [esi + 8], eax
// 00870e02  5e                   pop esi
// 00870e03  c20400               ret 4
// 00870e06  8b4608               mov eax, dword ptr [esi + 8]
// 00870e09  85c0                 test eax, eax
// 00870e0b  740e                 je 0x870e1b
// 00870e0d  50                   push eax
// 00870e0e  ff15ccca9800         call dword ptr [0x98cacc]
// 00870e14  c7460800000000       mov dword ptr [esi + 8], 0
// 00870e1b  5e                   pop esi
// 00870e1c  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPKeyboardManager.cpp (function ?SetupCallWndProcHook@CXTPKeyboardManager@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPKeyboardManager.cpp
