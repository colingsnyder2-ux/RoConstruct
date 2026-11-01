// from server: 100% by auto
// roc 2011-06 008f29d0  unit: CXTCaptionButton  size: 229 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f29d0
//
// 008f29d0  83ec40               sub esp, 0x40
// 008f29d3  56                   push esi
// 008f29d4  57                   push edi
// 008f29d5  6a30                 push 0x30
// 008f29d7  8d44241c             lea eax, [esp + 0x1c]
// 008f29db  6a00                 push 0
// 008f29dd  50                   push eax
// 008f29de  8bf1                 mov esi, ecx
// 008f29e0  e8ff88f1ff           call 0x80b2e4
// 008f29e5  83c40c               add esp, 0xc
// 008f29e8  8bce                 mov ecx, esi
// 008f29ea  c744241804000000     mov dword ptr [esp + 0x18], 4
// 008f29f2  e81f9e0d00           call 0x9cc816
// 008f29f7  8b7e20               mov edi, dword ptr [esi + 0x20]
// 008f29fa  8944241c             mov dword ptr [esp + 0x1c], eax
// 008f29fe  c744242800000000     mov dword ptr [esp + 0x28], 0
// 008f2a06  ff15f819a400         call dword ptr [0xa419f8]
// 008f2a0c  3bc7                 cmp eax, edi
// 008f2a0e  7505                 jne 0x8f2a15
// 008f2a10  834c242810           or dword ptr [esp + 0x28], 0x10
// 008f2a15  83bea400000000       cmp dword ptr [esi + 0xa4], 0
// 008f2a1c  7405                 je 0x8f2a23
// 008f2a1e  834c242801           or dword ptr [esp + 0x28], 1
// 008f2a23  6a00                 push 0
// 008f2a25  6a00                 push 0
// 008f2a27  6829010000           push 0x129
// 008f2a2c  57                   push edi
// 008f2a2d  ff15c019a400         call dword ptr [0xa419c0]
// 008f2a33  a802                 test al, 2
// 008f2a35  7408                 je 0x8f2a3f
// 008f2a37  814c242800010000     or dword ptr [esp + 0x28], 0x100
// 008f2a3f  a801                 test al, 1
// 008f2a41  7408                 je 0x8f2a4b
// 008f2a43  814c242800020000     or dword ptr [esp + 0x28], 0x200
// 008f2a4b  8bce                 mov ecx, esi
// 008f2a4d  e8a09d0d00           call 0x9cc7f2
// 008f2a52  85c0                 test eax, eax
// 008f2a54  7505                 jne 0x8f2a5b
// 008f2a56  834c242804           or dword ptr [esp + 0x28], 4
// 008f2a5b  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 008f2a5f  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008f2a62  894c242c             mov dword ptr [esp + 0x2c], ecx
// 008f2a66  85c0                 test eax, eax
// 008f2a68  7506                 jne 0x8f2a70
// 008f2a6a  89442430             mov dword ptr [esp + 0x30], eax
// 008f2a6e  eb07                 jmp 0x8f2a77
// 008f2a70  8b5004               mov edx, dword ptr [eax + 4]
// 008f2a73  89542430             mov dword ptr [esp + 0x30], edx
// 008f2a77  56                   push esi
// 008f2a78  8d4c240c             lea ecx, [esp + 0xc]
// 008f2a7c  e80fa3f6ff           call 0x85cd90
// 008f2a81  8b08                 mov ecx, dword ptr [eax]
// 008f2a83  894c2434             mov dword ptr [esp + 0x34], ecx
// 008f2a87  8b5004               mov edx, dword ptr [eax + 4]
// 008f2a8a  89542438             mov dword ptr [esp + 0x38], edx
// 008f2a8e  8b4808               mov ecx, dword ptr [eax + 8]
// 008f2a91  894c243c             mov dword ptr [esp + 0x3c], ecx
// 008f2a95  8b500c               mov edx, dword ptr [eax + 0xc]
// 008f2a98  8b06                 mov eax, dword ptr [esi]
// 008f2a9a  8d4c2418             lea ecx, [esp + 0x18]
// 008f2a9e  89542440             mov dword ptr [esp + 0x40], edx
// 008f2aa2  8b9048010000         mov edx, dword ptr [eax + 0x148]
// 008f2aa8  51                   push ecx
// 008f2aa9  8bce                 mov ecx, esi
// 008f2aab  ffd2                 call edx
// 008f2aad  5f                   pop edi
// 008f2aae  5e                   pop esi
// 008f2aaf  83c440               add esp, 0x40
// 008f2ab2  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Controls\Deprecated\XTButton.cpp (function ?OnDraw@CXTButton@@MAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Deprecated/XTButton.cpp
