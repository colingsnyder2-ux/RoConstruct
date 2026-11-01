// from server: 100% by auto
// roc 2009-12 00812c80  unit: CXTPToolBar  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00812c80
//
// 00812c80  55                   push ebp
// 00812c81  8be9                 mov ebp, ecx
// 00812c83  e8a811feff           call 0x7f3e30
// 00812c88  85c0                 test eax, eax
// 00812c8a  7504                 jne 0x812c90
// 00812c8c  5d                   pop ebp
// 00812c8d  c20400               ret 4
// 00812c90  57                   push edi
// 00812c91  8bcd                 mov ecx, ebp
// 00812c93  e8da371100           call 0x926472
// 00812c98  a900010000           test eax, 0x100
// 00812c9d  747a                 je 0x812d19
// 00812c9f  8bcd                 mov ecx, ebp
// 00812ca1  e80a391100           call 0x9265b0
// 00812ca6  8bf8                 mov edi, eax
// 00812ca8  85ff                 test edi, edi
// 00812caa  7505                 jne 0x812cb1
// 00812cac  5f                   pop edi
// 00812cad  5d                   pop ebp
// 00812cae  c20400               ret 4
// 00812cb1  53                   push ebx
// 00812cb2  56                   push esi
// 00812cb3  ff15cccb9800         call dword ptr [0x98cbcc]
// 00812cb9  50                   push eax
// 00812cba  e86b0efeff           call 0x7f3b2a
// 00812cbf  8b1dc4cb9800         mov ebx, dword ptr [0x98cbc4]
// 00812cc5  8bf0                 mov esi, eax
// 00812cc7  3bfe                 cmp edi, esi
// 00812cc9  742b                 je 0x812cf6
// 00812ccb  8b4720               mov eax, dword ptr [edi + 0x20]
// 00812cce  50                   push eax
// 00812ccf  ff1518cb9800         call dword ptr [0x98cb18]
// 00812cd5  50                   push eax
// 00812cd6  e84f0efeff           call 0x7f3b2a
// 00812cdb  3bc6                 cmp eax, esi
// 00812cdd  7513                 jne 0x812cf2
// 00812cdf  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00812ce2  6a00                 push 0
// 00812ce4  6a40                 push 0x40
// 00812ce6  686d030000           push 0x36d
// 00812ceb  51                   push ecx
// 00812cec  ffd3                 call ebx
// 00812cee  85c0                 test eax, eax
// 00812cf0  7504                 jne 0x812cf6
// 00812cf2  33c0                 xor eax, eax
// 00812cf4  eb05                 jmp 0x812cfb
// 00812cf6  b801000000           mov eax, 1
// 00812cfb  33d2                 xor edx, edx
// 00812cfd  85c0                 test eax, eax
// 00812cff  8b4520               mov eax, dword ptr [ebp + 0x20]
// 00812d02  0f94c2               sete dl
// 00812d05  6a00                 push 0
// 00812d07  8d149504000000       lea edx, [edx*4 + 4]
// 00812d0e  52                   push edx
// 00812d0f  686d030000           push 0x36d
// 00812d14  50                   push eax
// 00812d15  ffd3                 call ebx
// 00812d17  5e                   pop esi
// 00812d18  5b                   pop ebx
// 00812d19  5f                   pop edi
// 00812d1a  b801000000           mov eax, 1
// 00812d1f  5d                   pop ebp
// 00812d20  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?OnNcCreate@CXTPPopupBar@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
