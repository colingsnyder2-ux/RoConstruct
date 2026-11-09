// from server: 100% by auto
// roc 2010-06 00867c20  unit: CXTPDockingPaneSplitterContainer  size: 385 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00867c20
//
// 00867c20  83ec2c               sub esp, 0x2c
// 00867c23  53                   push ebx
// 00867c24  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 00867c28  55                   push ebp
// 00867c29  57                   push edi
// 00867c2a  53                   push ebx
// 00867c2b  8be9                 mov ebp, ecx
// 00867c2d  e82eceffff           call 0x864a60
// 00867c32  8bcd                 mov ecx, ebp
// 00867c34  33ff                 xor edi, edi
// 00867c36  e88575f9ff           call 0x7ff1c0
// 00867c3b  8944243c             mov dword ptr [esp + 0x3c], eax
// 00867c3f  85c0                 test eax, eax
// 00867c41  0f8451010000         je 0x867d98
// 00867c47  56                   push esi
// 00867c48  8d442440             lea eax, [esp + 0x40]
// 00867c4c  50                   push eax
// 00867c4d  8bcd                 mov ecx, ebp
// 00867c4f  e80cf40300           call 0x8a7060
// 00867c54  8bf0                 mov esi, eax
// 00867c56  8b16                 mov edx, dword ptr [esi]
// 00867c58  8b4214               mov eax, dword ptr [edx + 0x14]
// 00867c5b  8bce                 mov ecx, esi
// 00867c5d  ffd0                 call eax
// 00867c5f  85c0                 test eax, eax
// 00867c61  0f85ea000000         jne 0x867d51
// 00867c67  8b16                 mov edx, dword ptr [esi]
// 00867c69  8b5210               mov edx, dword ptr [edx + 0x10]
// 00867c6c  8d442414             lea eax, [esp + 0x14]
// 00867c70  47                   inc edi
// 00867c71  50                   push eax
// 00867c72  8bce                 mov ecx, esi
// 00867c74  897c2414             mov dword ptr [esp + 0x14], edi
// 00867c78  ffd2                 call edx
// 00867c7a  83ff01               cmp edi, 1
// 00867c7d  7516                 jne 0x867c95
// 00867c7f  b90a000000           mov ecx, 0xa
// 00867c84  8d742414             lea esi, [esp + 0x14]
// 00867c88  8bfb                 mov edi, ebx
// 00867c8a  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00867c8c  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00867c90  e9bc000000           jmp 0x867d51
// 00867c95  8b4d70               mov ecx, dword ptr [ebp + 0x70]
// 00867c98  8d4318               lea eax, [ebx + 0x18]
// 00867c9b  85c9                 test ecx, ecx
// 00867c9d  7543                 jne 0x867ce2
// 00867c9f  8d431c               lea eax, [ebx + 0x1c]
// 00867ca2  8d4c2430             lea ecx, [esp + 0x30]
// 00867ca6  8b09                 mov ecx, dword ptr [ecx]
// 00867ca8  0108                 add dword ptr [eax], ecx
// 00867caa  8b4d70               mov ecx, dword ptr [ebp + 0x70]
// 00867cad  8d4320               lea eax, [ebx + 0x20]
// 00867cb0  85c9                 test ecx, ecx
// 00867cb2  7534                 jne 0x867ce8
// 00867cb4  8d4324               lea eax, [ebx + 0x24]
// 00867cb7  8d4c2438             lea ecx, [esp + 0x38]
// 00867cbb  8b11                 mov edx, dword ptr [ecx]
// 00867cbd  0110                 add dword ptr [eax], edx
// 00867cbf  8b4570               mov eax, dword ptr [ebp + 0x70]
// 00867cc2  8d5318               lea edx, [ebx + 0x18]
// 00867cc5  85c0                 test eax, eax
// 00867cc7  7425                 je 0x867cee
// 00867cc9  8d531c               lea edx, [ebx + 0x1c]
// 00867ccc  8d4c2430             lea ecx, [esp + 0x30]
// 00867cd0  8b12                 mov edx, dword ptr [edx]
// 00867cd2  3b11                 cmp edx, dword ptr [ecx]
// 00867cd4  7e1e                 jle 0x867cf4
// 00867cd6  8d4b18               lea ecx, [ebx + 0x18]
// 00867cd9  85c0                 test eax, eax
// 00867cdb  7423                 je 0x867d00
// 00867cdd  8d4b1c               lea ecx, [ebx + 0x1c]
// 00867ce0  eb1e                 jmp 0x867d00
// 00867ce2  8d4c242c             lea ecx, [esp + 0x2c]
// 00867ce6  ebbe                 jmp 0x867ca6
// 00867ce8  8d4c2434             lea ecx, [esp + 0x34]
// 00867cec  ebcd                 jmp 0x867cbb
// 00867cee  8d4c242c             lea ecx, [esp + 0x2c]
// 00867cf2  ebdc                 jmp 0x867cd0
// 00867cf4  8d4c242c             lea ecx, [esp + 0x2c]
// 00867cf8  85c0                 test eax, eax
// 00867cfa  7404                 je 0x867d00
// 00867cfc  8d4c2430             lea ecx, [esp + 0x30]
// 00867d00  8b09                 mov ecx, dword ptr [ecx]
// 00867d02  85c0                 test eax, eax
// 00867d04  8d4318               lea eax, [ebx + 0x18]
// 00867d07  7403                 je 0x867d0c
// 00867d09  8d431c               lea eax, [ebx + 0x1c]
// 00867d0c  8908                 mov dword ptr [eax], ecx
// 00867d0e  8b4570               mov eax, dword ptr [ebp + 0x70]
// 00867d11  8d5320               lea edx, [ebx + 0x20]
// 00867d14  85c0                 test eax, eax
// 00867d16  7419                 je 0x867d31
// 00867d18  8d5324               lea edx, [ebx + 0x24]
// 00867d1b  8d4c2438             lea ecx, [esp + 0x38]
// 00867d1f  8b12                 mov edx, dword ptr [edx]
// 00867d21  3b11                 cmp edx, dword ptr [ecx]
// 00867d23  7d12                 jge 0x867d37
// 00867d25  8d4b20               lea ecx, [ebx + 0x20]
// 00867d28  85c0                 test eax, eax
// 00867d2a  7417                 je 0x867d43
// 00867d2c  8d4b24               lea ecx, [ebx + 0x24]
// 00867d2f  eb12                 jmp 0x867d43
// 00867d31  8d4c2434             lea ecx, [esp + 0x34]
// 00867d35  ebe8                 jmp 0x867d1f
// 00867d37  8d4c2434             lea ecx, [esp + 0x34]
// 00867d3b  85c0                 test eax, eax
// 00867d3d  7404                 je 0x867d43
// 00867d3f  8d4c2438             lea ecx, [esp + 0x38]
// 00867d43  8b09                 mov ecx, dword ptr [ecx]
// 00867d45  85c0                 test eax, eax
// 00867d47  8d4320               lea eax, [ebx + 0x20]
// 00867d4a  7403                 je 0x867d4f
// 00867d4c  8d4324               lea eax, [ebx + 0x24]
// 00867d4f  8908                 mov dword ptr [eax], ecx
// 00867d51  837c244000           cmp dword ptr [esp + 0x40], 0
// 00867d56  0f85ecfeffff         jne 0x867c48
// 00867d5c  85ff                 test edi, edi
// 00867d5e  7e37                 jle 0x867d97
// 00867d60  837d7000             cmp dword ptr [ebp + 0x70], 0
// 00867d64  8d7318               lea esi, [ebx + 0x18]
// 00867d67  7503                 jne 0x867d6c
// 00867d69  8d731c               lea esi, [ebx + 0x1c]
// 00867d6c  8bcd                 mov ecx, ebp
// 00867d6e  4f                   dec edi
// 00867d6f  e8accbffff           call 0x864920
// 00867d74  8b4028               mov eax, dword ptr [eax + 0x28]
// 00867d77  0fafc7               imul eax, edi
// 00867d7a  0106                 add dword ptr [esi], eax
// 00867d7c  837d7000             cmp dword ptr [ebp + 0x70], 0
// 00867d80  8d7320               lea esi, [ebx + 0x20]
// 00867d83  7503                 jne 0x867d88
// 00867d85  8d7324               lea esi, [ebx + 0x24]
// 00867d88  8bcd                 mov ecx, ebp
// 00867d8a  e891cbffff           call 0x864920
// 00867d8f  8b4828               mov ecx, dword ptr [eax + 0x28]
// 00867d92  0fafcf               imul ecx, edi
// 00867d95  010e                 add dword ptr [esi], ecx
// 00867d97  5e                   pop esi
// 00867d98  5f                   pop edi
// 00867d99  5d                   pop ebp
// 00867d9a  5b                   pop ebx
// 00867d9b  83c42c               add esp, 0x2c
// 00867d9e  c20400               ret 4
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?GetMinMaxInfo@CXTPDockingPaneSplitterContainer@@UBEXPAUtagMINMAXINFO@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
