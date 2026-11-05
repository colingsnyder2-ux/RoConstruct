// from server: 100% by auto
// roc 2009-12 008f4090  unit: CXTButtonTheme  size: 188 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f4090
//
// 008f4090  53                   push ebx
// 008f4091  56                   push esi
// 008f4092  57                   push edi
// 008f4093  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 008f4097  8bf1                 mov esi, ecx
// 008f4099  8b06                 mov eax, dword ptr [esi]
// 008f409b  8b5014               mov edx, dword ptr [eax + 0x14]
// 008f409e  57                   push edi
// 008f409f  ffd2                 call edx
// 008f40a1  8a5c2410             mov bl, byte ptr [esp + 0x10]
// 008f40a5  85c0                 test eax, eax
// 008f40a7  747c                 je 0x8f4125
// 008f40a9  55                   push ebp
// 008f40aa  8bcf                 mov ecx, edi
// 008f40ac  bd01000000           mov ebp, 1
// 008f40b1  e84a14ffff           call 0x8e5500
// 008f40b6  3c01                 cmp al, 1
// 008f40b8  7505                 jne 0x8f40bf
// 008f40ba  bd05000000           mov ebp, 5
// 008f40bf  83bfa000000000       cmp dword ptr [edi + 0xa0], 0
// 008f40c6  750b                 jne 0x8f40d3
// 008f40c8  ff1528cc9800         call dword ptr [0x98cc28]
// 008f40ce  3b4720               cmp eax, dword ptr [edi + 0x20]
// 008f40d1  7505                 jne 0x8f40d8
// 008f40d3  bd02000000           mov ebp, 2
// 008f40d8  f6c301               test bl, 1
// 008f40db  7506                 jne 0x8f40e3
// 008f40dd  837f7c00             cmp dword ptr [edi + 0x7c], 0
// 008f40e1  7405                 je 0x8f40e8
// 008f40e3  bd03000000           mov ebp, 3
// 008f40e8  f6c304               test bl, 4
// 008f40eb  7405                 je 0x8f40f2
// 008f40ed  bd04000000           mov ebp, 4
// 008f40f2  8b4634               mov eax, dword ptr [esi + 0x34]
// 008f40f5  83f8ff               cmp eax, -1
// 008f40f8  7503                 jne 0x8f40fd
// 008f40fa  8b4630               mov eax, dword ptr [esi + 0x30]
// 008f40fd  8d4c2418             lea ecx, [esp + 0x18]
// 008f4101  51                   push ecx
// 008f4102  68db0e0000           push 0xedb
// 008f4107  55                   push ebp
// 008f4108  6a01                 push 1
// 008f410a  8d4e74               lea ecx, [esi + 0x74]
// 008f410d  89442428             mov dword ptr [esp + 0x28], eax
// 008f4111  e89a78f7ff           call 0x86b9b0
// 008f4116  5d                   pop ebp
// 008f4117  85c0                 test eax, eax
// 008f4119  7c0a                 jl 0x8f4125
// 008f411b  8b442414             mov eax, dword ptr [esp + 0x14]
// 008f411f  5f                   pop edi
// 008f4120  5e                   pop esi
// 008f4121  5b                   pop ebx
// 008f4122  c20800               ret 8
// 008f4125  f6c304               test bl, 4
// 008f4128  7411                 je 0x8f413b
// 008f412a  8b4640               mov eax, dword ptr [esi + 0x40]
// 008f412d  83f8ff               cmp eax, -1
// 008f4130  7514                 jne 0x8f4146
// 008f4132  8b463c               mov eax, dword ptr [esi + 0x3c]
// 008f4135  5f                   pop edi
// 008f4136  5e                   pop esi
// 008f4137  5b                   pop ebx
// 008f4138  c20800               ret 8
// 008f413b  8b4634               mov eax, dword ptr [esi + 0x34]
// 008f413e  83f8ff               cmp eax, -1
// 008f4141  7503                 jne 0x8f4146
// 008f4143  8b4630               mov eax, dword ptr [esi + 0x30]
// 008f4146  5f                   pop edi
// 008f4147  5e                   pop esi
// 008f4148  5b                   pop ebx
// 008f4149  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTButtonTheme.cpp (function ?GetTextColor@CXTButtonTheme@@MAEKIPAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButtonTheme.cpp
