// from server: 100% by auto
// roc 2009-06 00810360  unit: CXTPScrollBase  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00810360
//
// 00810360  55                   push ebp
// 00810361  8be9                 mov ebp, ecx
// 00810363  56                   push esi
// 00810364  8b7560               mov esi, dword ptr [ebp + 0x60]
// 00810367  85f6                 test esi, esi
// 00810369  7476                 je 0x8103e1
// 0081036b  53                   push ebx
// 0081036c  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00810370  3b5e20               cmp ebx, dword ptr [esi + 0x20]
// 00810373  746b                 je 0x8103e0
// 00810375  57                   push edi
// 00810376  8b7e34               mov edi, dword ptr [esi + 0x34]
// 00810379  53                   push ebx
// 0081037a  57                   push edi
// 0081037b  e870ffffff           call 0x8102f0
// 00810380  83c408               add esp, 8
// 00810383  894628               mov dword ptr [esi + 0x28], eax
// 00810386  3b4624               cmp eax, dword ptr [esi + 0x24]
// 00810389  743c                 je 0x8103c7
// 0081038b  eb03                 jmp 0x810390
// 0081038d  8d4900               lea ecx, [ecx]
// 00810390  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 00810393  8b4500               mov eax, dword ptr [ebp]
// 00810396  8b5018               mov edx, dword ptr [eax + 0x18]
// 00810399  51                   push ecx
// 0081039a  6a05                 push 5
// 0081039c  8bcd                 mov ecx, ebp
// 0081039e  ffd2                 call edx
// 008103a0  8b4628               mov eax, dword ptr [esi + 0x28]
// 008103a3  894624               mov dword ptr [esi + 0x24], eax
// 008103a6  8b4f40               mov ecx, dword ptr [edi + 0x40]
// 008103a9  8b573c               mov edx, dword ptr [edi + 0x3c]
// 008103ac  8d0411               lea eax, [ecx + edx]
// 008103af  3bd8                 cmp ebx, eax
// 008103b1  7c14                 jl 0x8103c7
// 008103b3  8bd8                 mov ebx, eax
// 008103b5  53                   push ebx
// 008103b6  57                   push edi
// 008103b7  e834ffffff           call 0x8102f0
// 008103bc  83c408               add esp, 8
// 008103bf  894628               mov dword ptr [esi + 0x28], eax
// 008103c2  3b4624               cmp eax, dword ptr [esi + 0x24]
// 008103c5  75c9                 jne 0x810390
// 008103c7  8b4720               mov eax, dword ptr [edi + 0x20]
// 008103ca  03c3                 add eax, ebx
// 008103cc  894730               mov dword ptr [edi + 0x30], eax
// 008103cf  895f34               mov dword ptr [edi + 0x34], ebx
// 008103d2  895e20               mov dword ptr [esi + 0x20], ebx
// 008103d5  8b5500               mov edx, dword ptr [ebp]
// 008103d8  8b421c               mov eax, dword ptr [edx + 0x1c]
// 008103db  8bcd                 mov ecx, ebp
// 008103dd  ffd0                 call eax
// 008103df  5f                   pop edi
// 008103e0  5b                   pop ebx
// 008103e1  5e                   pop esi
// 008103e2  5d                   pop ebp
// 008103e3  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?MoveThumb@CXTPScrollBase@@IAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPScrollBase.cpp
