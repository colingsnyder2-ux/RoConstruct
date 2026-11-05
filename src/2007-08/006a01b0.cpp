// from server: 100% by auto
// roc 2007-08 006a01b0  unit: CSelectionCaption  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a01b0
//
// 006a01b0  83ec10               sub esp, 0x10
// 006a01b3  56                   push esi
// 006a01b4  8bf1                 mov esi, ecx
// 006a01b6  e88300f9ff           call 0x63023e
// 006a01bb  8b86fc000000         mov eax, dword ptr [esi + 0xfc]
// 006a01c1  50                   push eax
// 006a01c2  ff15bced7700         call dword ptr [0x77edbc]
// 006a01c8  85c0                 test eax, eax
// 006a01ca  7433                 je 0x6a01ff
// 006a01cc  8b16                 mov edx, dword ptr [esi]
// 006a01ce  8b9274010000         mov edx, dword ptr [edx + 0x174]
// 006a01d4  57                   push edi
// 006a01d5  8d442408             lea eax, [esp + 8]
// 006a01d9  50                   push eax
// 006a01da  8bce                 mov ecx, esi
// 006a01dc  ffd2                 call edx
// 006a01de  8b4804               mov ecx, dword ptr [eax + 4]
// 006a01e1  8b780c               mov edi, dword ptr [eax + 0xc]
// 006a01e4  8b10                 mov edx, dword ptr [eax]
// 006a01e6  8b4008               mov eax, dword ptr [eax + 8]
// 006a01e9  6a01                 push 1
// 006a01eb  2bf9                 sub edi, ecx
// 006a01ed  57                   push edi
// 006a01ee  2bc2                 sub eax, edx
// 006a01f0  50                   push eax
// 006a01f1  51                   push ecx
// 006a01f2  52                   push edx
// 006a01f3  8d8edc000000         lea ecx, [esi + 0xdc]
// 006a01f9  e836fef8ff           call 0x630034
// 006a01fe  5f                   pop edi
// 006a01ff  5e                   pop esi
// 006a0200  83c410               add esp, 0x10
// 006a0203  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTCaption.cpp (function ?OnWindowPosChanged@CXTCaption@@IAEXPAUtagWINDOWPOS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaption.cpp
