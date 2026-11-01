// from server: 100% by auto
// roc 2009-06 00793a10  unit: CXTPHookManager::CHookSink  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00793a10
//
// 00793a10  837c240400           cmp dword ptr [esp + 4], 0
// 00793a15  56                   push esi
// 00793a16  8bf1                 mov esi, ecx
// 00793a18  742c                 je 0x793a46
// 00793a1a  837e0400             cmp dword ptr [esi + 4], 0
// 00793a1e  753b                 jne 0x793a5b
// 00793a20  57                   push edi
// 00793a21  e8d052f8ff           call 0x718cf6
// 00793a26  8b7808               mov edi, dword ptr [eax + 8]
// 00793a29  ff15ece18900         call dword ptr [0x89e1ec]
// 00793a2f  50                   push eax
// 00793a30  57                   push edi
// 00793a31  68c0367900           push 0x7936c0
// 00793a36  6a02                 push 2
// 00793a38  ff15c4ee8900         call dword ptr [0x89eec4]
// 00793a3e  5f                   pop edi
// 00793a3f  894604               mov dword ptr [esi + 4], eax
// 00793a42  5e                   pop esi
// 00793a43  c20400               ret 4
// 00793a46  8b4604               mov eax, dword ptr [esi + 4]
// 00793a49  85c0                 test eax, eax
// 00793a4b  740e                 je 0x793a5b
// 00793a4d  50                   push eax
// 00793a4e  ff15c0ee8900         call dword ptr [0x89eec0]
// 00793a54  c7460400000000       mov dword ptr [esi + 4], 0
// 00793a5b  5e                   pop esi
// 00793a5c  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPKeyboardManager.cpp (function ?SetupKeyboardHook@CXTPKeyboardManager@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPKeyboardManager.cpp
