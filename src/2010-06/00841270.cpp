// from server: 100% by auto
// roc 2010-06 00841270  unit: CXTPHookManager::CHookSink  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00841270
//
// 00841270  837c240400           cmp dword ptr [esp + 4], 0
// 00841275  56                   push esi
// 00841276  8bf1                 mov esi, ecx
// 00841278  742c                 je 0x8412a6
// 0084127a  837e0400             cmp dword ptr [esi + 4], 0
// 0084127e  753b                 jne 0x8412bb
// 00841280  57                   push edi
// 00841281  e8d869f6ff           call 0x7a7c5e
// 00841286  8b7808               mov edi, dword ptr [eax + 8]
// 00841289  ff1594a39e00         call dword ptr [0x9ea394]
// 0084128f  50                   push eax
// 00841290  57                   push edi
// 00841291  68200f8400           push 0x840f20
// 00841296  6a02                 push 2
// 00841298  ff15a0ba9e00         call dword ptr [0x9ebaa0]
// 0084129e  5f                   pop edi
// 0084129f  894604               mov dword ptr [esi + 4], eax
// 008412a2  5e                   pop esi
// 008412a3  c20400               ret 4
// 008412a6  8b4604               mov eax, dword ptr [esi + 4]
// 008412a9  85c0                 test eax, eax
// 008412ab  740e                 je 0x8412bb
// 008412ad  50                   push eax
// 008412ae  ff159cba9e00         call dword ptr [0x9eba9c]
// 008412b4  c7460400000000       mov dword ptr [esi + 4], 0
// 008412bb  5e                   pop esi
// 008412bc  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPKeyboardManager.cpp (function ?SetupKeyboardHook@CXTPKeyboardManager@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPKeyboardManager.cpp
