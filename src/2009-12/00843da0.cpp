// from server: 100% by auto
// roc 2009-12 00843da0  unit: CXTPPopupBar  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00843da0
//
// 00843da0  51                   push ecx
// 00843da1  57                   push edi
// 00843da2  8bf9                 mov edi, ecx
// 00843da4  897c2404             mov dword ptr [esp + 4], edi
// 00843da8  85ff                 test edi, edi
// 00843daa  7407                 je 0x843db3
// 00843dac  8b4720               mov eax, dword ptr [edi + 0x20]
// 00843daf  85c0                 test eax, eax
// 00843db1  7509                 jne 0x843dbc
// 00843db3  5f                   pop edi
// 00843db4  83c404               add esp, 4
// 00843db7  e922fbfaff           jmp 0x7f38de
// 00843dbc  55                   push ebp
// 00843dbd  8b2dfccb9800         mov ebp, dword ptr [0x98cbfc]
// 00843dc3  56                   push esi
// 00843dc4  6a05                 push 5
// 00843dc6  50                   push eax
// 00843dc7  ffd5                 call ebp
// 00843dc9  50                   push eax
// 00843dca  e85bfdfaff           call 0x7f3b2a
// 00843dcf  8bf0                 mov esi, eax
// 00843dd1  8bcf                 mov ecx, edi
// 00843dd3  85f6                 test esi, esi
// 00843dd5  750b                 jne 0x843de2
// 00843dd7  5e                   pop esi
// 00843dd8  5d                   pop ebp
// 00843dd9  5f                   pop edi
// 00843dda  83c404               add esp, 4
// 00843ddd  e9fcfafaff           jmp 0x7f38de
// 00843de2  53                   push ebx
// 00843de3  e8a832fcff           call 0x807090
// 00843de8  8bd8                 mov ebx, eax
// 00843dea  8d9b00000000         lea ebx, [ebx]
// 00843df0  8b4620               mov eax, dword ptr [esi + 0x20]
// 00843df3  6a02                 push 2
// 00843df5  50                   push eax
// 00843df6  ffd5                 call ebp
// 00843df8  50                   push eax
// 00843df9  e82cfdfaff           call 0x7f3b2a
// 00843dfe  6a00                 push 0
// 00843e00  8bce                 mov ecx, esi
// 00843e02  8bf8                 mov edi, eax
// 00843e04  e83ffdfaff           call 0x7f3b48
// 00843e09  85db                 test ebx, ebx
// 00843e0b  7504                 jne 0x843e11
// 00843e0d  33c0                 xor eax, eax
// 00843e0f  eb03                 jmp 0x843e14
// 00843e11  8b4320               mov eax, dword ptr [ebx + 0x20]
// 00843e14  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00843e17  50                   push eax
// 00843e18  51                   push ecx
// 00843e19  ff1538cb9800         call dword ptr [0x98cb38]
// 00843e1f  50                   push eax
// 00843e20  e805fdfaff           call 0x7f3b2a
// 00843e25  8bf7                 mov esi, edi
// 00843e27  85ff                 test edi, edi
// 00843e29  75c5                 jne 0x843df0
// 00843e2b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00843e2f  5b                   pop ebx
// 00843e30  5e                   pop esi
// 00843e31  5d                   pop ebp
// 00843e32  5f                   pop edi
// 00843e33  83c404               add esp, 4
// 00843e36  e9a3fafaff           jmp 0x7f38de
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?DestroyWindow@CXTPPopupBar@@UAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
