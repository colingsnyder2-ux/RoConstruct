// from server: 100% by auto
// roc 2009-06 0073bb90  unit: CXTPToolBar  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073bb90
//
// 0073bb90  55                   push ebp
// 0073bb91  8be9                 mov ebp, ecx
// 0073bb93  e870d4fdff           call 0x719008
// 0073bb98  85c0                 test eax, eax
// 0073bb9a  7504                 jne 0x73bba0
// 0073bb9c  5d                   pop ebp
// 0073bb9d  c20400               ret 4
// 0073bba0  57                   push edi
// 0073bba1  8bcd                 mov ecx, ebp
// 0073bba3  e834031100           call 0x84bedc
// 0073bba8  a900010000           test eax, 0x100
// 0073bbad  747a                 je 0x73bc29
// 0073bbaf  8bcd                 mov ecx, ebp
// 0073bbb1  e8c4041100           call 0x84c07a
// 0073bbb6  8bf8                 mov edi, eax
// 0073bbb8  85ff                 test edi, edi
// 0073bbba  7505                 jne 0x73bbc1
// 0073bbbc  5f                   pop edi
// 0073bbbd  5d                   pop ebp
// 0073bbbe  c20400               ret 4
// 0073bbc1  53                   push ebx
// 0073bbc2  56                   push esi
// 0073bbc3  ff1588ee8900         call dword ptr [0x89ee88]
// 0073bbc9  50                   push eax
// 0073bbca  e833d1fdff           call 0x718d02
// 0073bbcf  8b1d90ee8900         mov ebx, dword ptr [0x89ee90]
// 0073bbd5  8bf0                 mov esi, eax
// 0073bbd7  3bfe                 cmp edi, esi
// 0073bbd9  742b                 je 0x73bc06
// 0073bbdb  8b4720               mov eax, dword ptr [edi + 0x20]
// 0073bbde  50                   push eax
// 0073bbdf  ff152cef8900         call dword ptr [0x89ef2c]
// 0073bbe5  50                   push eax
// 0073bbe6  e817d1fdff           call 0x718d02
// 0073bbeb  3bc6                 cmp eax, esi
// 0073bbed  7513                 jne 0x73bc02
// 0073bbef  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0073bbf2  6a00                 push 0
// 0073bbf4  6a40                 push 0x40
// 0073bbf6  686d030000           push 0x36d
// 0073bbfb  51                   push ecx
// 0073bbfc  ffd3                 call ebx
// 0073bbfe  85c0                 test eax, eax
// 0073bc00  7504                 jne 0x73bc06
// 0073bc02  33c0                 xor eax, eax
// 0073bc04  eb05                 jmp 0x73bc0b
// 0073bc06  b801000000           mov eax, 1
// 0073bc0b  33d2                 xor edx, edx
// 0073bc0d  85c0                 test eax, eax
// 0073bc0f  8b4520               mov eax, dword ptr [ebp + 0x20]
// 0073bc12  0f94c2               sete dl
// 0073bc15  6a00                 push 0
// 0073bc17  8d149504000000       lea edx, [edx*4 + 4]
// 0073bc1e  52                   push edx
// 0073bc1f  686d030000           push 0x36d
// 0073bc24  50                   push eax
// 0073bc25  ffd3                 call ebx
// 0073bc27  5e                   pop esi
// 0073bc28  5b                   pop ebx
// 0073bc29  5f                   pop edi
// 0073bc2a  b801000000           mov eax, 1
// 0073bc2f  5d                   pop ebp
// 0073bc30  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?OnNcCreate@CXTPPopupBar@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
