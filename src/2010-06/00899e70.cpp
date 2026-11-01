// from server: 100% by auto
// roc 2010-06 00899e70  unit: CXTCaptionButton  size: 229 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00899e70
//
// 00899e70  83ec40               sub esp, 0x40
// 00899e73  56                   push esi
// 00899e74  57                   push edi
// 00899e75  6a30                 push 0x30
// 00899e77  8d44241c             lea eax, [esp + 0x1c]
// 00899e7b  6a00                 push 0
// 00899e7d  50                   push eax
// 00899e7e  8bf1                 mov esi, ecx
// 00899e80  e85fedf0ff           call 0x7a8be4
// 00899e85  83c40c               add esp, 0xc
// 00899e88  8bce                 mov ecx, esi
// 00899e8a  c744241804000000     mov dword ptr [esp + 0x18], 4
// 00899e92  e86f310e00           call 0x97d006
// 00899e97  8b7e20               mov edi, dword ptr [esi + 0x20]
// 00899e9a  8944241c             mov dword ptr [esp + 0x1c], eax
// 00899e9e  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00899ea6  ff1580ba9e00         call dword ptr [0x9eba80]
// 00899eac  3bc7                 cmp eax, edi
// 00899eae  7505                 jne 0x899eb5
// 00899eb0  834c242810           or dword ptr [esp + 0x28], 0x10
// 00899eb5  83bea400000000       cmp dword ptr [esi + 0xa4], 0
// 00899ebc  7405                 je 0x899ec3
// 00899ebe  834c242801           or dword ptr [esp + 0x28], 1
// 00899ec3  6a00                 push 0
// 00899ec5  6a00                 push 0
// 00899ec7  6829010000           push 0x129
// 00899ecc  57                   push edi
// 00899ecd  ff1554ba9e00         call dword ptr [0x9eba54]
// 00899ed3  a802                 test al, 2
// 00899ed5  7408                 je 0x899edf
// 00899ed7  814c242800010000     or dword ptr [esp + 0x28], 0x100
// 00899edf  a801                 test al, 1
// 00899ee1  7408                 je 0x899eeb
// 00899ee3  814c242800020000     or dword ptr [esp + 0x28], 0x200
// 00899eeb  8bce                 mov ecx, esi
// 00899eed  e8f0300e00           call 0x97cfe2
// 00899ef2  85c0                 test eax, eax
// 00899ef4  7505                 jne 0x899efb
// 00899ef6  834c242804           or dword ptr [esp + 0x28], 4
// 00899efb  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 00899eff  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00899f02  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00899f06  85c0                 test eax, eax
// 00899f08  7506                 jne 0x899f10
// 00899f0a  89442430             mov dword ptr [esp + 0x30], eax
// 00899f0e  eb07                 jmp 0x899f17
// 00899f10  8b5004               mov edx, dword ptr [eax + 4]
// 00899f13  89542430             mov dword ptr [esp + 0x30], edx
// 00899f17  56                   push esi
// 00899f18  8d4c240c             lea ecx, [esp + 0xc]
// 00899f1c  e8ef53f6ff           call 0x7ff310
// 00899f21  8b08                 mov ecx, dword ptr [eax]
// 00899f23  894c2434             mov dword ptr [esp + 0x34], ecx
// 00899f27  8b5004               mov edx, dword ptr [eax + 4]
// 00899f2a  89542438             mov dword ptr [esp + 0x38], edx
// 00899f2e  8b4808               mov ecx, dword ptr [eax + 8]
// 00899f31  894c243c             mov dword ptr [esp + 0x3c], ecx
// 00899f35  8b500c               mov edx, dword ptr [eax + 0xc]
// 00899f38  8b06                 mov eax, dword ptr [esi]
// 00899f3a  8d4c2418             lea ecx, [esp + 0x18]
// 00899f3e  89542440             mov dword ptr [esp + 0x40], edx
// 00899f42  8b9048010000         mov edx, dword ptr [eax + 0x148]
// 00899f48  51                   push ecx
// 00899f49  8bce                 mov ecx, esi
// 00899f4b  ffd2                 call edx
// 00899f4d  5f                   pop edi
// 00899f4e  5e                   pop esi
// 00899f4f  83c440               add esp, 0x40
// 00899f52  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Controls\XTButton.cpp (function ?OnDraw@CXTButton@@MAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTButton.cpp
