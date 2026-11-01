// from server: 100% by auto
// roc 2009-12 00856c30  unit: CXTPTabClientWnd  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00856c30
//
// 00856c30  56                   push esi
// 00856c31  8bf1                 mov esi, ecx
// 00856c33  83beb400000000       cmp dword ptr [esi + 0xb4], 0
// 00856c3a  57                   push edi
// 00856c3b  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00856c3f  7455                 je 0x856c96
// 00856c41  8b4704               mov eax, dword ptr [edi + 4]
// 00856c44  3d01020000           cmp eax, 0x201
// 00856c49  741c                 je 0x856c67
// 00856c4b  3d04020000           cmp eax, 0x204
// 00856c50  7415                 je 0x856c67
// 00856c52  3d07020000           cmp eax, 0x207
// 00856c57  740e                 je 0x856c67
// 00856c59  3d03020000           cmp eax, 0x203
// 00856c5e  7407                 je 0x856c67
// 00856c60  3d06020000           cmp eax, 0x206
// 00856c65  752f                 jne 0x856c96
// 00856c67  8b0f                 mov ecx, dword ptr [edi]
// 00856c69  3b4e20               cmp ecx, dword ptr [esi + 0x20]
// 00856c6c  7528                 jne 0x856c96
// 00856c6e  8b570c               mov edx, dword ptr [edi + 0xc]
// 00856c71  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 00856c77  52                   push edx
// 00856c78  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00856c7b  50                   push eax
// 00856c7c  6868280000           push 0x2868
// 00856c81  52                   push edx
// 00856c82  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00856c88  85c0                 test eax, eax
// 00856c8a  740a                 je 0x856c96
// 00856c8c  5f                   pop edi
// 00856c8d  b801000000           mov eax, 1
// 00856c92  5e                   pop esi
// 00856c93  c20400               ret 4
// 00856c96  57                   push edi
// 00856c97  8bce                 mov ecx, esi
// 00856c99  e8c2d1f9ff           call 0x7f3e60
// 00856c9e  5f                   pop edi
// 00856c9f  5e                   pop esi
// 00856ca0  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?PreTranslateMessage@CXTPTabClientWnd@@MAEHPAUtagMSG@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
