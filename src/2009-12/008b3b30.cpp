// from server: 100% by auto
// roc 2009-12 008b3b30  unit: CXTPDockingPaneSplitterContainer  size: 385 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b3b30
//
// 008b3b30  83ec2c               sub esp, 0x2c
// 008b3b33  53                   push ebx
// 008b3b34  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 008b3b38  55                   push ebp
// 008b3b39  57                   push edi
// 008b3b3a  53                   push ebx
// 008b3b3b  8be9                 mov ebp, ecx
// 008b3b3d  e84eceffff           call 0x8b0990
// 008b3b42  8bcd                 mov ecx, ebp
// 008b3b44  33ff                 xor edi, edi
// 008b3b46  e8456cfaff           call 0x85a790
// 008b3b4b  8944243c             mov dword ptr [esp + 0x3c], eax
// 008b3b4f  85c0                 test eax, eax
// 008b3b51  0f8451010000         je 0x8b3ca8
// 008b3b57  56                   push esi
// 008b3b58  8d442440             lea eax, [esp + 0x40]
// 008b3b5c  50                   push eax
// 008b3b5d  8bcd                 mov ecx, ebp
// 008b3b5f  e8acf30300           call 0x8f2f10
// 008b3b64  8bf0                 mov esi, eax
// 008b3b66  8b16                 mov edx, dword ptr [esi]
// 008b3b68  8b4214               mov eax, dword ptr [edx + 0x14]
// 008b3b6b  8bce                 mov ecx, esi
// 008b3b6d  ffd0                 call eax
// 008b3b6f  85c0                 test eax, eax
// 008b3b71  0f85ea000000         jne 0x8b3c61
// 008b3b77  8b16                 mov edx, dword ptr [esi]
// 008b3b79  8b5210               mov edx, dword ptr [edx + 0x10]
// 008b3b7c  8d442414             lea eax, [esp + 0x14]
// 008b3b80  47                   inc edi
// 008b3b81  50                   push eax
// 008b3b82  8bce                 mov ecx, esi
// 008b3b84  897c2414             mov dword ptr [esp + 0x14], edi
// 008b3b88  ffd2                 call edx
// 008b3b8a  83ff01               cmp edi, 1
// 008b3b8d  7516                 jne 0x8b3ba5
// 008b3b8f  b90a000000           mov ecx, 0xa
// 008b3b94  8d742414             lea esi, [esp + 0x14]
// 008b3b98  8bfb                 mov edi, ebx
// 008b3b9a  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 008b3b9c  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008b3ba0  e9bc000000           jmp 0x8b3c61
// 008b3ba5  8b4d70               mov ecx, dword ptr [ebp + 0x70]
// 008b3ba8  8d4318               lea eax, [ebx + 0x18]
// 008b3bab  85c9                 test ecx, ecx
// 008b3bad  7543                 jne 0x8b3bf2
// 008b3baf  8d431c               lea eax, [ebx + 0x1c]
// 008b3bb2  8d4c2430             lea ecx, [esp + 0x30]
// 008b3bb6  8b09                 mov ecx, dword ptr [ecx]
// 008b3bb8  0108                 add dword ptr [eax], ecx
// 008b3bba  8b4d70               mov ecx, dword ptr [ebp + 0x70]
// 008b3bbd  8d4320               lea eax, [ebx + 0x20]
// 008b3bc0  85c9                 test ecx, ecx
// 008b3bc2  7534                 jne 0x8b3bf8
// 008b3bc4  8d4324               lea eax, [ebx + 0x24]
// 008b3bc7  8d4c2438             lea ecx, [esp + 0x38]
// 008b3bcb  8b11                 mov edx, dword ptr [ecx]
// 008b3bcd  0110                 add dword ptr [eax], edx
// 008b3bcf  8b4570               mov eax, dword ptr [ebp + 0x70]
// 008b3bd2  8d5318               lea edx, [ebx + 0x18]
// 008b3bd5  85c0                 test eax, eax
// 008b3bd7  7425                 je 0x8b3bfe
// 008b3bd9  8d531c               lea edx, [ebx + 0x1c]
// 008b3bdc  8d4c2430             lea ecx, [esp + 0x30]
// 008b3be0  8b12                 mov edx, dword ptr [edx]
// 008b3be2  3b11                 cmp edx, dword ptr [ecx]
// 008b3be4  7e1e                 jle 0x8b3c04
// 008b3be6  8d4b18               lea ecx, [ebx + 0x18]
// 008b3be9  85c0                 test eax, eax
// 008b3beb  7423                 je 0x8b3c10
// 008b3bed  8d4b1c               lea ecx, [ebx + 0x1c]
// 008b3bf0  eb1e                 jmp 0x8b3c10
// 008b3bf2  8d4c242c             lea ecx, [esp + 0x2c]
// 008b3bf6  ebbe                 jmp 0x8b3bb6
// 008b3bf8  8d4c2434             lea ecx, [esp + 0x34]
// 008b3bfc  ebcd                 jmp 0x8b3bcb
// 008b3bfe  8d4c242c             lea ecx, [esp + 0x2c]
// 008b3c02  ebdc                 jmp 0x8b3be0
// 008b3c04  8d4c242c             lea ecx, [esp + 0x2c]
// 008b3c08  85c0                 test eax, eax
// 008b3c0a  7404                 je 0x8b3c10
// 008b3c0c  8d4c2430             lea ecx, [esp + 0x30]
// 008b3c10  8b09                 mov ecx, dword ptr [ecx]
// 008b3c12  85c0                 test eax, eax
// 008b3c14  8d4318               lea eax, [ebx + 0x18]
// 008b3c17  7403                 je 0x8b3c1c
// 008b3c19  8d431c               lea eax, [ebx + 0x1c]
// 008b3c1c  8908                 mov dword ptr [eax], ecx
// 008b3c1e  8b4570               mov eax, dword ptr [ebp + 0x70]
// 008b3c21  8d5320               lea edx, [ebx + 0x20]
// 008b3c24  85c0                 test eax, eax
// 008b3c26  7419                 je 0x8b3c41
// 008b3c28  8d5324               lea edx, [ebx + 0x24]
// 008b3c2b  8d4c2438             lea ecx, [esp + 0x38]
// 008b3c2f  8b12                 mov edx, dword ptr [edx]
// 008b3c31  3b11                 cmp edx, dword ptr [ecx]
// 008b3c33  7d12                 jge 0x8b3c47
// 008b3c35  8d4b20               lea ecx, [ebx + 0x20]
// 008b3c38  85c0                 test eax, eax
// 008b3c3a  7417                 je 0x8b3c53
// 008b3c3c  8d4b24               lea ecx, [ebx + 0x24]
// 008b3c3f  eb12                 jmp 0x8b3c53
// 008b3c41  8d4c2434             lea ecx, [esp + 0x34]
// 008b3c45  ebe8                 jmp 0x8b3c2f
// 008b3c47  8d4c2434             lea ecx, [esp + 0x34]
// 008b3c4b  85c0                 test eax, eax
// 008b3c4d  7404                 je 0x8b3c53
// 008b3c4f  8d4c2438             lea ecx, [esp + 0x38]
// 008b3c53  8b09                 mov ecx, dword ptr [ecx]
// 008b3c55  85c0                 test eax, eax
// 008b3c57  8d4320               lea eax, [ebx + 0x20]
// 008b3c5a  7403                 je 0x8b3c5f
// 008b3c5c  8d4324               lea eax, [ebx + 0x24]
// 008b3c5f  8908                 mov dword ptr [eax], ecx
// 008b3c61  837c244000           cmp dword ptr [esp + 0x40], 0
// 008b3c66  0f85ecfeffff         jne 0x8b3b58
// 008b3c6c  85ff                 test edi, edi
// 008b3c6e  7e37                 jle 0x8b3ca7
// 008b3c70  837d7000             cmp dword ptr [ebp + 0x70], 0
// 008b3c74  8d7318               lea esi, [ebx + 0x18]
// 008b3c77  7503                 jne 0x8b3c7c
// 008b3c79  8d731c               lea esi, [ebx + 0x1c]
// 008b3c7c  8bcd                 mov ecx, ebp
// 008b3c7e  4f                   dec edi
// 008b3c7f  e8cccbffff           call 0x8b0850
// 008b3c84  8b4028               mov eax, dword ptr [eax + 0x28]
// 008b3c87  0fafc7               imul eax, edi
// 008b3c8a  0106                 add dword ptr [esi], eax
// 008b3c8c  837d7000             cmp dword ptr [ebp + 0x70], 0
// 008b3c90  8d7320               lea esi, [ebx + 0x20]
// 008b3c93  7503                 jne 0x8b3c98
// 008b3c95  8d7324               lea esi, [ebx + 0x24]
// 008b3c98  8bcd                 mov ecx, ebp
// 008b3c9a  e8b1cbffff           call 0x8b0850
// 008b3c9f  8b4828               mov ecx, dword ptr [eax + 0x28]
// 008b3ca2  0fafcf               imul ecx, edi
// 008b3ca5  010e                 add dword ptr [esi], ecx
// 008b3ca7  5e                   pop esi
// 008b3ca8  5f                   pop edi
// 008b3ca9  5d                   pop ebp
// 008b3caa  5b                   pop ebx
// 008b3cab  83c42c               add esp, 0x2c
// 008b3cae  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?GetMinMaxInfo@CXTPDockingPaneSplitterContainer@@UBEXPAUtagMINMAXINFO@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
