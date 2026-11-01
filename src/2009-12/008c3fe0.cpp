// from server: 100% by auto
// roc 2009-12 008c3fe0  unit: CXTPImageEditorPicture  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c3fe0
//
// 008c3fe0  56                   push esi
// 008c3fe1  8bf1                 mov esi, ecx
// 008c3fe3  8b467c               mov eax, dword ptr [esi + 0x7c]
// 008c3fe6  6a0c                 push 0xc
// 008c3fe8  894678               mov dword ptr [esi + 0x78], eax
// 008c3feb  e870f8f2ff           call 0x7f3860
// 008c3ff0  33c9                 xor ecx, ecx
// 008c3ff2  83c404               add esp, 4
// 008c3ff5  3bc1                 cmp eax, ecx
// 008c3ff7  740e                 je 0x8c4007
// 008c3ff9  894804               mov dword ptr [eax + 4], ecx
// 008c3ffc  c700148aa000         mov dword ptr [eax], 0xa08a14
// 008c4002  894808               mov dword ptr [eax + 8], ecx
// 008c4005  eb02                 jmp 0x8c4009
// 008c4007  33c0                 xor eax, eax
// 008c4009  8b542408             mov edx, dword ptr [esp + 8]
// 008c400d  51                   push ecx
// 008c400e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008c4012  68fffeff00           push 0xfffeff
// 008c4017  68fffeff00           push 0xfffeff
// 008c401c  51                   push ecx
// 008c401d  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 008c4020  52                   push edx
// 008c4021  8b5654               mov edx, dword ptr [esi + 0x54]
// 008c4024  51                   push ecx
// 008c4025  8b4e78               mov ecx, dword ptr [esi + 0x78]
// 008c4028  52                   push edx
// 008c4029  51                   push ecx
// 008c402a  50                   push eax
// 008c402b  89467c               mov dword ptr [esi + 0x7c], eax
// 008c402e  e86ddaffff           call 0x8c1aa0
// 008c4033  83c424               add esp, 0x24
// 008c4036  8bce                 mov ecx, esi
// 008c4038  e893fbffff           call 0x8c3bd0
// 008c403d  5e                   pop esi
// 008c403e  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?MovePicture@CXTPImageEditorPicture@@QAEXVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
