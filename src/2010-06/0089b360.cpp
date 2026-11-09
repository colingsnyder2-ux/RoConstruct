// from server: 100% by auto
// roc 2010-06 0089b360  unit: CXTPScrollBase  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089b360
//
// 0089b360  55                   push ebp
// 0089b361  8be9                 mov ebp, ecx
// 0089b363  56                   push esi
// 0089b364  8b7560               mov esi, dword ptr [ebp + 0x60]
// 0089b367  85f6                 test esi, esi
// 0089b369  7476                 je 0x89b3e1
// 0089b36b  53                   push ebx
// 0089b36c  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0089b370  3b5e20               cmp ebx, dword ptr [esi + 0x20]
// 0089b373  746b                 je 0x89b3e0
// 0089b375  57                   push edi
// 0089b376  8b7e34               mov edi, dword ptr [esi + 0x34]
// 0089b379  53                   push ebx
// 0089b37a  57                   push edi
// 0089b37b  e870ffffff           call 0x89b2f0
// 0089b380  83c408               add esp, 8
// 0089b383  894628               mov dword ptr [esi + 0x28], eax
// 0089b386  3b4624               cmp eax, dword ptr [esi + 0x24]
// 0089b389  743c                 je 0x89b3c7
// 0089b38b  eb03                 jmp 0x89b390
// 0089b38d  8d4900               lea ecx, [ecx]
// 0089b390  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 0089b393  8b4500               mov eax, dword ptr [ebp]
// 0089b396  8b5018               mov edx, dword ptr [eax + 0x18]
// 0089b399  51                   push ecx
// 0089b39a  6a05                 push 5
// 0089b39c  8bcd                 mov ecx, ebp
// 0089b39e  ffd2                 call edx
// 0089b3a0  8b4628               mov eax, dword ptr [esi + 0x28]
// 0089b3a3  894624               mov dword ptr [esi + 0x24], eax
// 0089b3a6  8b4f40               mov ecx, dword ptr [edi + 0x40]
// 0089b3a9  8b573c               mov edx, dword ptr [edi + 0x3c]
// 0089b3ac  8d0411               lea eax, [ecx + edx]
// 0089b3af  3bd8                 cmp ebx, eax
// 0089b3b1  7c14                 jl 0x89b3c7
// 0089b3b3  8bd8                 mov ebx, eax
// 0089b3b5  53                   push ebx
// 0089b3b6  57                   push edi
// 0089b3b7  e834ffffff           call 0x89b2f0
// 0089b3bc  83c408               add esp, 8
// 0089b3bf  894628               mov dword ptr [esi + 0x28], eax
// 0089b3c2  3b4624               cmp eax, dword ptr [esi + 0x24]
// 0089b3c5  75c9                 jne 0x89b390
// 0089b3c7  8b4720               mov eax, dword ptr [edi + 0x20]
// 0089b3ca  03c3                 add eax, ebx
// 0089b3cc  894730               mov dword ptr [edi + 0x30], eax
// 0089b3cf  895f34               mov dword ptr [edi + 0x34], ebx
// 0089b3d2  895e20               mov dword ptr [esi + 0x20], ebx
// 0089b3d5  8b5500               mov edx, dword ptr [ebp]
// 0089b3d8  8b421c               mov eax, dword ptr [edx + 0x1c]
// 0089b3db  8bcd                 mov ecx, ebp
// 0089b3dd  ffd0                 call eax
// 0089b3df  5f                   pop edi
// 0089b3e0  5b                   pop ebx
// 0089b3e1  5e                   pop esi
// 0089b3e2  5d                   pop ebp
// 0089b3e3  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?MoveThumb@CXTPScrollBase@@IAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPScrollBase.cpp
