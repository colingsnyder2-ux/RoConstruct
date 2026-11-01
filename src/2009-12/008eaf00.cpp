// from server: 100% by auto
// roc 2009-12 008eaf00  unit: CXTPScrollBase  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008eaf00
//
// 008eaf00  55                   push ebp
// 008eaf01  8be9                 mov ebp, ecx
// 008eaf03  56                   push esi
// 008eaf04  8b7560               mov esi, dword ptr [ebp + 0x60]
// 008eaf07  85f6                 test esi, esi
// 008eaf09  7476                 je 0x8eaf81
// 008eaf0b  53                   push ebx
// 008eaf0c  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 008eaf10  3b5e20               cmp ebx, dword ptr [esi + 0x20]
// 008eaf13  746b                 je 0x8eaf80
// 008eaf15  57                   push edi
// 008eaf16  8b7e34               mov edi, dword ptr [esi + 0x34]
// 008eaf19  53                   push ebx
// 008eaf1a  57                   push edi
// 008eaf1b  e870ffffff           call 0x8eae90
// 008eaf20  83c408               add esp, 8
// 008eaf23  894628               mov dword ptr [esi + 0x28], eax
// 008eaf26  3b4624               cmp eax, dword ptr [esi + 0x24]
// 008eaf29  743c                 je 0x8eaf67
// 008eaf2b  eb03                 jmp 0x8eaf30
// 008eaf2d  8d4900               lea ecx, [ecx]
// 008eaf30  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 008eaf33  8b4500               mov eax, dword ptr [ebp]
// 008eaf36  8b5018               mov edx, dword ptr [eax + 0x18]
// 008eaf39  51                   push ecx
// 008eaf3a  6a05                 push 5
// 008eaf3c  8bcd                 mov ecx, ebp
// 008eaf3e  ffd2                 call edx
// 008eaf40  8b4628               mov eax, dword ptr [esi + 0x28]
// 008eaf43  894624               mov dword ptr [esi + 0x24], eax
// 008eaf46  8b4f40               mov ecx, dword ptr [edi + 0x40]
// 008eaf49  8b573c               mov edx, dword ptr [edi + 0x3c]
// 008eaf4c  8d0411               lea eax, [ecx + edx]
// 008eaf4f  3bd8                 cmp ebx, eax
// 008eaf51  7c14                 jl 0x8eaf67
// 008eaf53  8bd8                 mov ebx, eax
// 008eaf55  53                   push ebx
// 008eaf56  57                   push edi
// 008eaf57  e834ffffff           call 0x8eae90
// 008eaf5c  83c408               add esp, 8
// 008eaf5f  894628               mov dword ptr [esi + 0x28], eax
// 008eaf62  3b4624               cmp eax, dword ptr [esi + 0x24]
// 008eaf65  75c9                 jne 0x8eaf30
// 008eaf67  8b4720               mov eax, dword ptr [edi + 0x20]
// 008eaf6a  03c3                 add eax, ebx
// 008eaf6c  894730               mov dword ptr [edi + 0x30], eax
// 008eaf6f  895f34               mov dword ptr [edi + 0x34], ebx
// 008eaf72  895e20               mov dword ptr [esi + 0x20], ebx
// 008eaf75  8b5500               mov edx, dword ptr [ebp]
// 008eaf78  8b421c               mov eax, dword ptr [edx + 0x1c]
// 008eaf7b  8bcd                 mov ecx, ebp
// 008eaf7d  ffd0                 call eax
// 008eaf7f  5f                   pop edi
// 008eaf80  5b                   pop ebx
// 008eaf81  5e                   pop esi
// 008eaf82  5d                   pop ebp
// 008eaf83  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?MoveThumb@CXTPScrollBase@@IAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPScrollBase.cpp
