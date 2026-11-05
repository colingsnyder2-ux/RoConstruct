// from server: 100% by auto
// roc 2010-06 00898970  unit: CXTCaptionTheme  size: 302 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00898970
//
// 00898970  83ec10               sub esp, 0x10
// 00898973  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00898977  8b5004               mov edx, dword ptr [eax + 4]
// 0089897a  53                   push ebx
// 0089897b  55                   push ebp
// 0089897c  56                   push esi
// 0089897d  8bf1                 mov esi, ecx
// 0089897f  8b08                 mov ecx, dword ptr [eax]
// 00898981  894c240c             mov dword ptr [esp + 0xc], ecx
// 00898985  8b4808               mov ecx, dword ptr [eax + 8]
// 00898988  57                   push edi
// 00898989  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0089898d  89542414             mov dword ptr [esp + 0x14], edx
// 00898991  8b500c               mov edx, dword ptr [eax + 0xc]
// 00898994  894c2418             mov dword ptr [esp + 0x18], ecx
// 00898998  6a01                 push 1
// 0089899a  8bcf                 mov ecx, edi
// 0089899c  89542420             mov dword ptr [esp + 0x20], edx
// 008989a0  e80f440e00           call 0x97cdb4
// 008989a5  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 008989a9  8b4370               mov eax, dword ptr [ebx + 0x70]
// 008989ac  50                   push eax
// 008989ad  8d4c2414             lea ecx, [esp + 0x14]
// 008989b1  51                   push ecx
// 008989b2  8bcf                 mov ecx, edi
// 008989b4  e885fdf0ff           call 0x7a873e
// 008989b9  8b83c8000000         mov eax, dword ptr [ebx + 0xc8]
// 008989bf  8b2ddcbb9e00         mov ebp, dword ptr [0x9ebbdc]
// 008989c5  a801                 test al, 1
// 008989c7  746c                 je 0x898a35
// 008989c9  8b4628               mov eax, dword ptr [esi + 0x28]
// 008989cc  83f8ff               cmp eax, -1
// 008989cf  7505                 jne 0x8989d6
// 008989d1  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 008989d4  eb02                 jmp 0x8989d8
// 008989d6  8bc8                 mov ecx, eax
// 008989d8  8b461c               mov eax, dword ptr [esi + 0x1c]
// 008989db  83f8ff               cmp eax, -1
// 008989de  7503                 jne 0x8989e3
// 008989e0  8b4618               mov eax, dword ptr [esi + 0x18]
// 008989e3  51                   push ecx
// 008989e4  50                   push eax
// 008989e5  8d542418             lea edx, [esp + 0x18]
// 008989e9  52                   push edx
// 008989ea  8bcf                 mov ecx, edi
// 008989ec  e847fdf0ff           call 0x7a8738
// 008989f1  6aff                 push -1
// 008989f3  6aff                 push -1
// 008989f5  8d442418             lea eax, [esp + 0x18]
// 008989f9  50                   push eax
// 008989fa  ffd5                 call ebp
// 008989fc  8b461c               mov eax, dword ptr [esi + 0x1c]
// 008989ff  83f8ff               cmp eax, -1
// 00898a02  7503                 jne 0x898a07
// 00898a04  8b4618               mov eax, dword ptr [esi + 0x18]
// 00898a07  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 00898a0a  83f9ff               cmp ecx, -1
// 00898a0d  7505                 jne 0x898a14
// 00898a0f  8b7624               mov esi, dword ptr [esi + 0x24]
// 00898a12  eb02                 jmp 0x898a16
// 00898a14  8bf1                 mov esi, ecx
// 00898a16  50                   push eax
// 00898a17  56                   push esi
// 00898a18  8d4c2418             lea ecx, [esp + 0x18]
// 00898a1c  51                   push ecx
// 00898a1d  8bcf                 mov ecx, edi
// 00898a1f  e814fdf0ff           call 0x7a8738
// 00898a24  837b6c00             cmp dword ptr [ebx + 0x6c], 0
// 00898a28  754c                 jne 0x898a76
// 00898a2a  6aff                 push -1
// 00898a2c  6aff                 push -1
// 00898a2e  8d542418             lea edx, [esp + 0x18]
// 00898a32  52                   push edx
// 00898a33  eb3f                 jmp 0x898a74
// 00898a35  a802                 test al, 2
// 00898a37  743d                 je 0x898a76
// 00898a39  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00898a3c  83f8ff               cmp eax, -1
// 00898a3f  7505                 jne 0x898a46
// 00898a41  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00898a44  eb02                 jmp 0x898a48
// 00898a46  8bc8                 mov ecx, eax
// 00898a48  8b4628               mov eax, dword ptr [esi + 0x28]
// 00898a4b  83f8ff               cmp eax, -1
// 00898a4e  7505                 jne 0x898a55
// 00898a50  8b7624               mov esi, dword ptr [esi + 0x24]
// 00898a53  eb02                 jmp 0x898a57
// 00898a55  8bf0                 mov esi, eax
// 00898a57  51                   push ecx
// 00898a58  56                   push esi
// 00898a59  8d442418             lea eax, [esp + 0x18]
// 00898a5d  50                   push eax
// 00898a5e  8bcf                 mov ecx, edi
// 00898a60  e8d3fcf0ff           call 0x7a8738
// 00898a65  837b6c00             cmp dword ptr [ebx + 0x6c], 0
// 00898a69  750b                 jne 0x898a76
// 00898a6b  6aff                 push -1
// 00898a6d  6aff                 push -1
// 00898a6f  8d4c2418             lea ecx, [esp + 0x18]
// 00898a73  51                   push ecx
// 00898a74  ffd5                 call ebp
// 00898a76  8b436c               mov eax, dword ptr [ebx + 0x6c]
// 00898a79  f7d8                 neg eax
// 00898a7b  50                   push eax
// 00898a7c  50                   push eax
// 00898a7d  8d542418             lea edx, [esp + 0x18]
// 00898a81  52                   push edx
// 00898a82  ffd5                 call ebp
// 00898a84  8b4374               mov eax, dword ptr [ebx + 0x74]
// 00898a87  50                   push eax
// 00898a88  8d4c2414             lea ecx, [esp + 0x14]
// 00898a8c  51                   push ecx
// 00898a8d  8bcf                 mov ecx, edi
// 00898a8f  e8aafcf0ff           call 0x7a873e
// 00898a94  5f                   pop edi
// 00898a95  5e                   pop esi
// 00898a96  5d                   pop ebp
// 00898a97  5b                   pop ebx
// 00898a98  83c410               add esp, 0x10
// 00898a9b  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawCaptionBack@CXTCaptionTheme@@UAEXPAVCDC@@PAVCXTCaption@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
