// from server: 100% by auto
// roc 2009-06 007e9460  unit: CXTPImageEditorPicture  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e9460
//
// 007e9460  56                   push esi
// 007e9461  8bf1                 mov esi, ecx
// 007e9463  8b467c               mov eax, dword ptr [esi + 0x7c]
// 007e9466  6a0c                 push 0xc
// 007e9468  894678               mov dword ptr [esi + 0x78], eax
// 007e946b  e8c8f5f2ff           call 0x718a38
// 007e9470  33c9                 xor ecx, ecx
// 007e9472  83c404               add esp, 4
// 007e9475  3bc1                 cmp eax, ecx
// 007e9477  740e                 je 0x7e9487
// 007e9479  894804               mov dword ptr [eax + 4], ecx
// 007e947c  c700a4859000         mov dword ptr [eax], 0x9085a4
// 007e9482  894808               mov dword ptr [eax + 8], ecx
// 007e9485  eb02                 jmp 0x7e9489
// 007e9487  33c0                 xor eax, eax
// 007e9489  8b542408             mov edx, dword ptr [esp + 8]
// 007e948d  51                   push ecx
// 007e948e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007e9492  68fffeff00           push 0xfffeff
// 007e9497  68fffeff00           push 0xfffeff
// 007e949c  51                   push ecx
// 007e949d  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 007e94a0  52                   push edx
// 007e94a1  8b5654               mov edx, dword ptr [esi + 0x54]
// 007e94a4  51                   push ecx
// 007e94a5  8b4e78               mov ecx, dword ptr [esi + 0x78]
// 007e94a8  52                   push edx
// 007e94a9  51                   push ecx
// 007e94aa  50                   push eax
// 007e94ab  89467c               mov dword ptr [esi + 0x7c], eax
// 007e94ae  e82ddbffff           call 0x7e6fe0
// 007e94b3  83c424               add esp, 0x24
// 007e94b6  8bce                 mov ecx, esi
// 007e94b8  e893fbffff           call 0x7e9050
// 007e94bd  5e                   pop esi
// 007e94be  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?MovePicture@CXTPImageEditorPicture@@QAEXVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
