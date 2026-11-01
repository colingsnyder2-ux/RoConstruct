// from server: 100% by auto
// roc 2009-06 00793a60  unit: CXTPHookManager::CHookSink  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00793a60
//
// 00793a60  837c240400           cmp dword ptr [esp + 4], 0
// 00793a65  56                   push esi
// 00793a66  8bf1                 mov esi, ecx
// 00793a68  742c                 je 0x793a96
// 00793a6a  837e0800             cmp dword ptr [esi + 8], 0
// 00793a6e  753b                 jne 0x793aab
// 00793a70  57                   push edi
// 00793a71  e88052f8ff           call 0x718cf6
// 00793a76  8b7808               mov edi, dword ptr [eax + 8]
// 00793a79  ff15ece18900         call dword ptr [0x89e1ec]
// 00793a7f  50                   push eax
// 00793a80  57                   push edi
// 00793a81  68d0357900           push 0x7935d0
// 00793a86  6a04                 push 4
// 00793a88  ff15c4ee8900         call dword ptr [0x89eec4]
// 00793a8e  5f                   pop edi
// 00793a8f  894608               mov dword ptr [esi + 8], eax
// 00793a92  5e                   pop esi
// 00793a93  c20400               ret 4
// 00793a96  8b4608               mov eax, dword ptr [esi + 8]
// 00793a99  85c0                 test eax, eax
// 00793a9b  740e                 je 0x793aab
// 00793a9d  50                   push eax
// 00793a9e  ff15c0ee8900         call dword ptr [0x89eec0]
// 00793aa4  c7460800000000       mov dword ptr [esi + 8], 0
// 00793aab  5e                   pop esi
// 00793aac  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPKeyboardManager.cpp (function ?SetupCallWndProcHook@CXTPKeyboardManager@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPKeyboardManager.cpp
