// from server: 100% by auto
// roc 2010-06 00821e30  unit: CSelectionCaption  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00821e30
//
// 00821e30  83ec10               sub esp, 0x10
// 00821e33  56                   push esi
// 00821e34  8bf1                 mov esi, ecx
// 00821e36  e83561f8ff           call 0x7a7f70
// 00821e3b  8b86fc000000         mov eax, dword ptr [esi + 0xfc]
// 00821e41  50                   push eax
// 00821e42  ff1528bc9e00         call dword ptr [0x9ebc28]
// 00821e48  85c0                 test eax, eax
// 00821e4a  7433                 je 0x821e7f
// 00821e4c  8b16                 mov edx, dword ptr [esi]
// 00821e4e  8b927c010000         mov edx, dword ptr [edx + 0x17c]
// 00821e54  57                   push edi
// 00821e55  8d442408             lea eax, [esp + 8]
// 00821e59  50                   push eax
// 00821e5a  8bce                 mov ecx, esi
// 00821e5c  ffd2                 call edx
// 00821e5e  8b4804               mov ecx, dword ptr [eax + 4]
// 00821e61  8b780c               mov edi, dword ptr [eax + 0xc]
// 00821e64  8b10                 mov edx, dword ptr [eax]
// 00821e66  8b4008               mov eax, dword ptr [eax + 8]
// 00821e69  6a01                 push 1
// 00821e6b  2bf9                 sub edi, ecx
// 00821e6d  57                   push edi
// 00821e6e  2bc2                 sub eax, edx
// 00821e70  50                   push eax
// 00821e71  51                   push ecx
// 00821e72  52                   push edx
// 00821e73  8d8edc000000         lea ecx, [esi + 0xdc]
// 00821e79  e8f45ef8ff           call 0x7a7d72
// 00821e7e  5f                   pop edi
// 00821e7f  5e                   pop esi
// 00821e80  83c410               add esp, 0x10
// 00821e83  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Controls\XTCaption.cpp (function ?OnWindowPosChanged@CXTCaption@@IAEXPAUtagWINDOWPOS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTCaption.cpp
