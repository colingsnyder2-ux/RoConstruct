// from server: 100% by auto
// roc 2009-06 008193a0  unit: CXTButtonTheme  size: 188 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008193a0
//
// 008193a0  53                   push ebx
// 008193a1  56                   push esi
// 008193a2  57                   push edi
// 008193a3  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 008193a7  8bf1                 mov esi, ecx
// 008193a9  8b06                 mov eax, dword ptr [esi]
// 008193ab  8b5014               mov edx, dword ptr [eax + 0x14]
// 008193ae  57                   push edi
// 008193af  ffd2                 call edx
// 008193b1  8a5c2410             mov bl, byte ptr [esp + 0x10]
// 008193b5  85c0                 test eax, eax
// 008193b7  747c                 je 0x819435
// 008193b9  55                   push ebp
// 008193ba  8bcf                 mov ecx, edi
// 008193bc  bd01000000           mov ebp, 1
// 008193c1  e89a16ffff           call 0x80aa60
// 008193c6  3c01                 cmp al, 1
// 008193c8  7505                 jne 0x8193cf
// 008193ca  bd05000000           mov ebp, 5
// 008193cf  83bfa000000000       cmp dword ptr [edi + 0xa0], 0
// 008193d6  750b                 jne 0x8193e3
// 008193d8  ff153cee8900         call dword ptr [0x89ee3c]
// 008193de  3b4720               cmp eax, dword ptr [edi + 0x20]
// 008193e1  7505                 jne 0x8193e8
// 008193e3  bd02000000           mov ebp, 2
// 008193e8  f6c301               test bl, 1
// 008193eb  7506                 jne 0x8193f3
// 008193ed  837f7c00             cmp dword ptr [edi + 0x7c], 0
// 008193f1  7405                 je 0x8193f8
// 008193f3  bd03000000           mov ebp, 3
// 008193f8  f6c304               test bl, 4
// 008193fb  7405                 je 0x819402
// 008193fd  bd04000000           mov ebp, 4
// 00819402  8b4634               mov eax, dword ptr [esi + 0x34]
// 00819405  83f8ff               cmp eax, -1
// 00819408  7503                 jne 0x81940d
// 0081940a  8b4630               mov eax, dword ptr [esi + 0x30]
// 0081940d  8d4c2418             lea ecx, [esp + 0x18]
// 00819411  51                   push ecx
// 00819412  68db0e0000           push 0xedb
// 00819417  55                   push ebp
// 00819418  6a01                 push 1
// 0081941a  8d4e74               lea ecx, [esi + 0x74]
// 0081941d  89442428             mov dword ptr [esp + 0x28], eax
// 00819421  e86a75f7ff           call 0x790990
// 00819426  5d                   pop ebp
// 00819427  85c0                 test eax, eax
// 00819429  7c0a                 jl 0x819435
// 0081942b  8b442414             mov eax, dword ptr [esp + 0x14]
// 0081942f  5f                   pop edi
// 00819430  5e                   pop esi
// 00819431  5b                   pop ebx
// 00819432  c20800               ret 8
// 00819435  f6c304               test bl, 4
// 00819438  7411                 je 0x81944b
// 0081943a  8b4640               mov eax, dword ptr [esi + 0x40]
// 0081943d  83f8ff               cmp eax, -1
// 00819440  7514                 jne 0x819456
// 00819442  8b463c               mov eax, dword ptr [esi + 0x3c]
// 00819445  5f                   pop edi
// 00819446  5e                   pop esi
// 00819447  5b                   pop ebx
// 00819448  c20800               ret 8
// 0081944b  8b4634               mov eax, dword ptr [esi + 0x34]
// 0081944e  83f8ff               cmp eax, -1
// 00819451  7503                 jne 0x819456
// 00819453  8b4630               mov eax, dword ptr [esi + 0x30]
// 00819456  5f                   pop edi
// 00819457  5e                   pop esi
// 00819458  5b                   pop ebx
// 00819459  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTButtonTheme.cpp (function ?GetTextColor@CXTButtonTheme@@MAEKIPAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButtonTheme.cpp
