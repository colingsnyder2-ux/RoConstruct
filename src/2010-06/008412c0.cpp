// from server: 100% by auto
// roc 2010-06 008412c0  unit: CXTPHookManager::CHookSink  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008412c0
//
// 008412c0  837c240400           cmp dword ptr [esp + 4], 0
// 008412c5  56                   push esi
// 008412c6  8bf1                 mov esi, ecx
// 008412c8  742c                 je 0x8412f6
// 008412ca  837e0800             cmp dword ptr [esi + 8], 0
// 008412ce  753b                 jne 0x84130b
// 008412d0  57                   push edi
// 008412d1  e88869f6ff           call 0x7a7c5e
// 008412d6  8b7808               mov edi, dword ptr [eax + 8]
// 008412d9  ff1594a39e00         call dword ptr [0x9ea394]
// 008412df  50                   push eax
// 008412e0  57                   push edi
// 008412e1  68300e8400           push 0x840e30
// 008412e6  6a04                 push 4
// 008412e8  ff15a0ba9e00         call dword ptr [0x9ebaa0]
// 008412ee  5f                   pop edi
// 008412ef  894608               mov dword ptr [esi + 8], eax
// 008412f2  5e                   pop esi
// 008412f3  c20400               ret 4
// 008412f6  8b4608               mov eax, dword ptr [esi + 8]
// 008412f9  85c0                 test eax, eax
// 008412fb  740e                 je 0x84130b
// 008412fd  50                   push eax
// 008412fe  ff159cba9e00         call dword ptr [0x9eba9c]
// 00841304  c7460800000000       mov dword ptr [esi + 8], 0
// 0084130b  5e                   pop esi
// 0084130c  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPKeyboardManager.cpp (function ?SetupCallWndProcHook@CXTPKeyboardManager@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPKeyboardManager.cpp
