// from server: 100% by auto
// roc 2009-06 007d9000  unit: CXTPDockingPaneSplitterContainer  size: 385 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d9000
//
// 007d9000  83ec2c               sub esp, 0x2c
// 007d9003  53                   push ebx
// 007d9004  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 007d9008  55                   push ebp
// 007d9009  57                   push edi
// 007d900a  53                   push ebx
// 007d900b  8be9                 mov ebp, ecx
// 007d900d  e83eceffff           call 0x7d5e50
// 007d9012  8bcd                 mov ecx, ebp
// 007d9014  33ff                 xor edi, edi
// 007d9016  e885c1faff           call 0x7851a0
// 007d901b  8944243c             mov dword ptr [esp + 0x3c], eax
// 007d901f  85c0                 test eax, eax
// 007d9021  0f8451010000         je 0x7d9178
// 007d9027  56                   push esi
// 007d9028  8d442440             lea eax, [esp + 0x40]
// 007d902c  50                   push eax
// 007d902d  8bcd                 mov ecx, ebp
// 007d902f  e83cf20300           call 0x818270
// 007d9034  8bf0                 mov esi, eax
// 007d9036  8b16                 mov edx, dword ptr [esi]
// 007d9038  8b4214               mov eax, dword ptr [edx + 0x14]
// 007d903b  8bce                 mov ecx, esi
// 007d903d  ffd0                 call eax
// 007d903f  85c0                 test eax, eax
// 007d9041  0f85ea000000         jne 0x7d9131
// 007d9047  8b16                 mov edx, dword ptr [esi]
// 007d9049  8b5210               mov edx, dword ptr [edx + 0x10]
// 007d904c  8d442414             lea eax, [esp + 0x14]
// 007d9050  47                   inc edi
// 007d9051  50                   push eax
// 007d9052  8bce                 mov ecx, esi
// 007d9054  897c2414             mov dword ptr [esp + 0x14], edi
// 007d9058  ffd2                 call edx
// 007d905a  83ff01               cmp edi, 1
// 007d905d  7516                 jne 0x7d9075
// 007d905f  b90a000000           mov ecx, 0xa
// 007d9064  8d742414             lea esi, [esp + 0x14]
// 007d9068  8bfb                 mov edi, ebx
// 007d906a  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 007d906c  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007d9070  e9bc000000           jmp 0x7d9131
// 007d9075  8b4d70               mov ecx, dword ptr [ebp + 0x70]
// 007d9078  8d4318               lea eax, [ebx + 0x18]
// 007d907b  85c9                 test ecx, ecx
// 007d907d  7543                 jne 0x7d90c2
// 007d907f  8d431c               lea eax, [ebx + 0x1c]
// 007d9082  8d4c2430             lea ecx, [esp + 0x30]
// 007d9086  8b09                 mov ecx, dword ptr [ecx]
// 007d9088  0108                 add dword ptr [eax], ecx
// 007d908a  8b4d70               mov ecx, dword ptr [ebp + 0x70]
// 007d908d  8d4320               lea eax, [ebx + 0x20]
// 007d9090  85c9                 test ecx, ecx
// 007d9092  7534                 jne 0x7d90c8
// 007d9094  8d4324               lea eax, [ebx + 0x24]
// 007d9097  8d4c2438             lea ecx, [esp + 0x38]
// 007d909b  8b11                 mov edx, dword ptr [ecx]
// 007d909d  0110                 add dword ptr [eax], edx
// 007d909f  8b4570               mov eax, dword ptr [ebp + 0x70]
// 007d90a2  8d5318               lea edx, [ebx + 0x18]
// 007d90a5  85c0                 test eax, eax
// 007d90a7  7425                 je 0x7d90ce
// 007d90a9  8d531c               lea edx, [ebx + 0x1c]
// 007d90ac  8d4c2430             lea ecx, [esp + 0x30]
// 007d90b0  8b12                 mov edx, dword ptr [edx]
// 007d90b2  3b11                 cmp edx, dword ptr [ecx]
// 007d90b4  7e1e                 jle 0x7d90d4
// 007d90b6  8d4b18               lea ecx, [ebx + 0x18]
// 007d90b9  85c0                 test eax, eax
// 007d90bb  7423                 je 0x7d90e0
// 007d90bd  8d4b1c               lea ecx, [ebx + 0x1c]
// 007d90c0  eb1e                 jmp 0x7d90e0
// 007d90c2  8d4c242c             lea ecx, [esp + 0x2c]
// 007d90c6  ebbe                 jmp 0x7d9086
// 007d90c8  8d4c2434             lea ecx, [esp + 0x34]
// 007d90cc  ebcd                 jmp 0x7d909b
// 007d90ce  8d4c242c             lea ecx, [esp + 0x2c]
// 007d90d2  ebdc                 jmp 0x7d90b0
// 007d90d4  8d4c242c             lea ecx, [esp + 0x2c]
// 007d90d8  85c0                 test eax, eax
// 007d90da  7404                 je 0x7d90e0
// 007d90dc  8d4c2430             lea ecx, [esp + 0x30]
// 007d90e0  8b09                 mov ecx, dword ptr [ecx]
// 007d90e2  85c0                 test eax, eax
// 007d90e4  8d4318               lea eax, [ebx + 0x18]
// 007d90e7  7403                 je 0x7d90ec
// 007d90e9  8d431c               lea eax, [ebx + 0x1c]
// 007d90ec  8908                 mov dword ptr [eax], ecx
// 007d90ee  8b4570               mov eax, dword ptr [ebp + 0x70]
// 007d90f1  8d5320               lea edx, [ebx + 0x20]
// 007d90f4  85c0                 test eax, eax
// 007d90f6  7419                 je 0x7d9111
// 007d90f8  8d5324               lea edx, [ebx + 0x24]
// 007d90fb  8d4c2438             lea ecx, [esp + 0x38]
// 007d90ff  8b12                 mov edx, dword ptr [edx]
// 007d9101  3b11                 cmp edx, dword ptr [ecx]
// 007d9103  7d12                 jge 0x7d9117
// 007d9105  8d4b20               lea ecx, [ebx + 0x20]
// 007d9108  85c0                 test eax, eax
// 007d910a  7417                 je 0x7d9123
// 007d910c  8d4b24               lea ecx, [ebx + 0x24]
// 007d910f  eb12                 jmp 0x7d9123
// 007d9111  8d4c2434             lea ecx, [esp + 0x34]
// 007d9115  ebe8                 jmp 0x7d90ff
// 007d9117  8d4c2434             lea ecx, [esp + 0x34]
// 007d911b  85c0                 test eax, eax
// 007d911d  7404                 je 0x7d9123
// 007d911f  8d4c2438             lea ecx, [esp + 0x38]
// 007d9123  8b09                 mov ecx, dword ptr [ecx]
// 007d9125  85c0                 test eax, eax
// 007d9127  8d4320               lea eax, [ebx + 0x20]
// 007d912a  7403                 je 0x7d912f
// 007d912c  8d4324               lea eax, [ebx + 0x24]
// 007d912f  8908                 mov dword ptr [eax], ecx
// 007d9131  837c244000           cmp dword ptr [esp + 0x40], 0
// 007d9136  0f85ecfeffff         jne 0x7d9028
// 007d913c  85ff                 test edi, edi
// 007d913e  7e37                 jle 0x7d9177
// 007d9140  837d7000             cmp dword ptr [ebp + 0x70], 0
// 007d9144  8d7318               lea esi, [ebx + 0x18]
// 007d9147  7503                 jne 0x7d914c
// 007d9149  8d731c               lea esi, [ebx + 0x1c]
// 007d914c  8bcd                 mov ecx, ebp
// 007d914e  4f                   dec edi
// 007d914f  e8bccbffff           call 0x7d5d10
// 007d9154  8b4028               mov eax, dword ptr [eax + 0x28]
// 007d9157  0fafc7               imul eax, edi
// 007d915a  0106                 add dword ptr [esi], eax
// 007d915c  837d7000             cmp dword ptr [ebp + 0x70], 0
// 007d9160  8d7320               lea esi, [ebx + 0x20]
// 007d9163  7503                 jne 0x7d9168
// 007d9165  8d7324               lea esi, [ebx + 0x24]
// 007d9168  8bcd                 mov ecx, ebp
// 007d916a  e8a1cbffff           call 0x7d5d10
// 007d916f  8b4828               mov ecx, dword ptr [eax + 0x28]
// 007d9172  0fafcf               imul ecx, edi
// 007d9175  010e                 add dword ptr [esi], ecx
// 007d9177  5e                   pop esi
// 007d9178  5f                   pop edi
// 007d9179  5d                   pop ebp
// 007d917a  5b                   pop ebx
// 007d917b  83c42c               add esp, 0x2c
// 007d917e  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?GetMinMaxInfo@CXTPDockingPaneSplitterContainer@@UBEXPAUtagMINMAXINFO@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
