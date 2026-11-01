// from server: 100% by auto
// roc 2007-03 006e2cc0  unit: seg_006e0000  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e2cc0
//
// 006e2cc0  56                   push esi
// 006e2cc1  8bf1                 mov esi, ecx
// 006e2cc3  8b467c               mov eax, dword ptr [esi + 0x7c]
// 006e2cc6  6a0c                 push 0xc
// 006e2cc8  894678               mov dword ptr [esi + 0x78], eax
// 006e2ccb  e838b4f3ff           call 0x61e108
// 006e2cd0  33c9                 xor ecx, ecx
// 006e2cd2  83c404               add esp, 4
// 006e2cd5  3bc1                 cmp eax, ecx
// 006e2cd7  740e                 je 0x6e2ce7
// 006e2cd9  894804               mov dword ptr [eax + 4], ecx
// 006e2cdc  c70044887d00         mov dword ptr [eax], 0x7d8844
// 006e2ce2  894808               mov dword ptr [eax + 8], ecx
// 006e2ce5  eb02                 jmp 0x6e2ce9
// 006e2ce7  33c0                 xor eax, eax
// 006e2ce9  8b542408             mov edx, dword ptr [esp + 8]
// 006e2ced  51                   push ecx
// 006e2cee  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006e2cf2  68fffeff00           push 0xfffeff
// 006e2cf7  68fffeff00           push 0xfffeff
// 006e2cfc  51                   push ecx
// 006e2cfd  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 006e2d00  52                   push edx
// 006e2d01  8b5654               mov edx, dword ptr [esi + 0x54]
// 006e2d04  51                   push ecx
// 006e2d05  8b4e78               mov ecx, dword ptr [esi + 0x78]
// 006e2d08  52                   push edx
// 006e2d09  51                   push ecx
// 006e2d0a  50                   push eax
// 006e2d0b  89467c               mov dword ptr [esi + 0x7c], eax
// 006e2d0e  e8add9ffff           call 0x6e06c0
// 006e2d13  83c424               add esp, 0x24
// 006e2d16  8bce                 mov ecx, esi
// 006e2d18  e8a3fbffff           call 0x6e28c0
// 006e2d1d  5e                   pop esi
// 006e2d1e  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?MovePicture@CXTPImageEditorPicture@@QAEXVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
