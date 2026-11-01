// from server: 100% by auto
// roc 2009-06 00768fc0  unit: CXTPPopupBar  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00768fc0
//
// 00768fc0  51                   push ecx
// 00768fc1  57                   push edi
// 00768fc2  8bf9                 mov edi, ecx
// 00768fc4  897c2404             mov dword ptr [esp + 4], edi
// 00768fc8  85ff                 test edi, edi
// 00768fca  7407                 je 0x768fd3
// 00768fcc  8b4720               mov eax, dword ptr [edi + 0x20]
// 00768fcf  85c0                 test eax, eax
// 00768fd1  7509                 jne 0x768fdc
// 00768fd3  5f                   pop edi
// 00768fd4  83c404               add esp, 4
// 00768fd7  e9dafafaff           jmp 0x718ab6
// 00768fdc  55                   push ebp
// 00768fdd  8b2d68ee8900         mov ebp, dword ptr [0x89ee68]
// 00768fe3  56                   push esi
// 00768fe4  6a05                 push 5
// 00768fe6  50                   push eax
// 00768fe7  ffd5                 call ebp
// 00768fe9  50                   push eax
// 00768fea  e813fdfaff           call 0x718d02
// 00768fef  8bf0                 mov esi, eax
// 00768ff1  8bcf                 mov ecx, edi
// 00768ff3  85f6                 test esi, esi
// 00768ff5  750b                 jne 0x769002
// 00768ff7  5e                   pop esi
// 00768ff8  5d                   pop ebp
// 00768ff9  5f                   pop edi
// 00768ffa  83c404               add esp, 4
// 00768ffd  e9b4fafaff           jmp 0x718ab6
// 00769002  53                   push ebx
// 00769003  e8286ffcff           call 0x72ff30
// 00769008  8bd8                 mov ebx, eax
// 0076900a  8d9b00000000         lea ebx, [ebx]
// 00769010  8b4620               mov eax, dword ptr [esi + 0x20]
// 00769013  6a02                 push 2
// 00769015  50                   push eax
// 00769016  ffd5                 call ebp
// 00769018  50                   push eax
// 00769019  e8e4fcfaff           call 0x718d02
// 0076901e  6a00                 push 0
// 00769020  8bce                 mov ecx, esi
// 00769022  8bf8                 mov edi, eax
// 00769024  e8f7fcfaff           call 0x718d20
// 00769029  85db                 test ebx, ebx
// 0076902b  7504                 jne 0x769031
// 0076902d  33c0                 xor eax, eax
// 0076902f  eb03                 jmp 0x769034
// 00769031  8b4320               mov eax, dword ptr [ebx + 0x20]
// 00769034  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00769037  50                   push eax
// 00769038  51                   push ecx
// 00769039  ff15a0ec8900         call dword ptr [0x89eca0]
// 0076903f  50                   push eax
// 00769040  e8bdfcfaff           call 0x718d02
// 00769045  8bf7                 mov esi, edi
// 00769047  85ff                 test edi, edi
// 00769049  75c5                 jne 0x769010
// 0076904b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0076904f  5b                   pop ebx
// 00769050  5e                   pop esi
// 00769051  5d                   pop ebp
// 00769052  5f                   pop edi
// 00769053  83c404               add esp, 4
// 00769056  e95bfafaff           jmp 0x718ab6
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?DestroyWindow@CXTPPopupBar@@UAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
