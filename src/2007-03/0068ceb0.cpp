// from server: 100% by auto
// roc 2007-03 0068ceb0  unit: seg_00680000  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068ceb0
//
// 0068ceb0  837c240400           cmp dword ptr [esp + 4], 0
// 0068ceb5  56                   push esi
// 0068ceb6  8bf1                 mov esi, ecx
// 0068ceb8  742c                 je 0x68cee6
// 0068ceba  837e0400             cmp dword ptr [esi + 4], 0
// 0068cebe  753b                 jne 0x68cefb
// 0068cec0  57                   push edi
// 0068cec1  e8ca14f9ff           call 0x61e390
// 0068cec6  8b7808               mov edi, dword ptr [eax + 8]
// 0068cec9  ff1584d27700         call dword ptr [0x77d284]
// 0068cecf  50                   push eax
// 0068ced0  57                   push edi
// 0068ced1  6850cc6800           push 0x68cc50
// 0068ced6  6a02                 push 2
// 0068ced8  ff15f0ee7700         call dword ptr [0x77eef0]
// 0068cede  5f                   pop edi
// 0068cedf  894604               mov dword ptr [esi + 4], eax
// 0068cee2  5e                   pop esi
// 0068cee3  c20400               ret 4
// 0068cee6  8b4604               mov eax, dword ptr [esi + 4]
// 0068cee9  85c0                 test eax, eax
// 0068ceeb  740e                 je 0x68cefb
// 0068ceed  50                   push eax
// 0068ceee  ff15ecee7700         call dword ptr [0x77eeec]
// 0068cef4  c7460400000000       mov dword ptr [esi + 4], 0
// 0068cefb  5e                   pop esi
// 0068cefc  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPKeyboardManager.cpp (function ?SetupKeyboardHook@CXTPKeyboardManager@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPKeyboardManager.cpp
