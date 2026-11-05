// from server: 100% by auto
// roc 2010-06 007f7e50  unit: CXTPPopupBar  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f7e50
//
// 007f7e50  51                   push ecx
// 007f7e51  57                   push edi
// 007f7e52  8bf9                 mov edi, ecx
// 007f7e54  897c2404             mov dword ptr [esp + 4], edi
// 007f7e58  85ff                 test edi, edi
// 007f7e5a  7407                 je 0x7f7e63
// 007f7e5c  8b4720               mov eax, dword ptr [edi + 0x20]
// 007f7e5f  85c0                 test eax, eax
// 007f7e61  7509                 jne 0x7f7e6c
// 007f7e63  5f                   pop edi
// 007f7e64  83c404               add esp, 4
// 007f7e67  e9b2fbfaff           jmp 0x7a7a1e
// 007f7e6c  55                   push ebp
// 007f7e6d  8b2d90ba9e00         mov ebp, dword ptr [0x9eba90]
// 007f7e73  56                   push esi
// 007f7e74  6a05                 push 5
// 007f7e76  50                   push eax
// 007f7e77  ffd5                 call ebp
// 007f7e79  50                   push eax
// 007f7e7a  e8ebfdfaff           call 0x7a7c6a
// 007f7e7f  8bf0                 mov esi, eax
// 007f7e81  8bcf                 mov ecx, edi
// 007f7e83  85f6                 test esi, esi
// 007f7e85  750b                 jne 0x7f7e92
// 007f7e87  5e                   pop esi
// 007f7e88  5d                   pop ebp
// 007f7e89  5f                   pop edi
// 007f7e8a  83c404               add esp, 4
// 007f7e8d  e98cfbfaff           jmp 0x7a7a1e
// 007f7e92  53                   push ebx
// 007f7e93  e86833fcff           call 0x7bb200
// 007f7e98  8bd8                 mov ebx, eax
// 007f7e9a  8d9b00000000         lea ebx, [ebx]
// 007f7ea0  8b4620               mov eax, dword ptr [esi + 0x20]
// 007f7ea3  6a02                 push 2
// 007f7ea5  50                   push eax
// 007f7ea6  ffd5                 call ebp
// 007f7ea8  50                   push eax
// 007f7ea9  e8bcfdfaff           call 0x7a7c6a
// 007f7eae  6a00                 push 0
// 007f7eb0  8bce                 mov ecx, esi
// 007f7eb2  8bf8                 mov edi, eax
// 007f7eb4  e8cffdfaff           call 0x7a7c88
// 007f7eb9  85db                 test ebx, ebx
// 007f7ebb  7504                 jne 0x7f7ec1
// 007f7ebd  33c0                 xor eax, eax
// 007f7ebf  eb03                 jmp 0x7f7ec4
// 007f7ec1  8b4320               mov eax, dword ptr [ebx + 0x20]
// 007f7ec4  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 007f7ec7  50                   push eax
// 007f7ec8  51                   push ecx
// 007f7ec9  ff15f0b99e00         call dword ptr [0x9eb9f0]
// 007f7ecf  50                   push eax
// 007f7ed0  e895fdfaff           call 0x7a7c6a
// 007f7ed5  8bf7                 mov esi, edi
// 007f7ed7  85ff                 test edi, edi
// 007f7ed9  75c5                 jne 0x7f7ea0
// 007f7edb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007f7edf  5b                   pop ebx
// 007f7ee0  5e                   pop esi
// 007f7ee1  5d                   pop ebp
// 007f7ee2  5f                   pop edi
// 007f7ee3  83c404               add esp, 4
// 007f7ee6  e933fbfaff           jmp 0x7a7a1e
// library xtp-13.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?DestroyWindow@CXTPPopupBar@@UAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPopupBar.cpp
