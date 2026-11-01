// from server: 100% by auto
// roc 2009-12 008564a0  unit: CXTPTabClientWnd  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008564a0
//
// 008564a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008564a4  56                   push esi
// 008564a5  57                   push edi
// 008564a6  e8d59feeff           call 0x740480
// 008564ab  8b3dc4cb9800         mov edi, dword ptr [0x98cbc4]
// 008564b1  6a00                 push 0
// 008564b3  6a00                 push 0
// 008564b5  8bf0                 mov esi, eax
// 008564b7  6860280000           push 0x2860
// 008564bc  56                   push esi
// 008564bd  ffd7                 call edi
// 008564bf  85c0                 test eax, eax
// 008564c1  7541                 jne 0x856504
// 008564c3  50                   push eax
// 008564c4  50                   push eax
// 008564c5  6a7f                 push 0x7f
// 008564c7  56                   push esi
// 008564c8  ffd7                 call edi
// 008564ca  85c0                 test eax, eax
// 008564cc  7536                 jne 0x856504
// 008564ce  50                   push eax
// 008564cf  6a01                 push 1
// 008564d1  6a7f                 push 0x7f
// 008564d3  56                   push esi
// 008564d4  ffd7                 call edi
// 008564d6  85c0                 test eax, eax
// 008564d8  752a                 jne 0x856504
// 008564da  8b3d68cb9800         mov edi, dword ptr [0x98cb68]
// 008564e0  6ade                 push -0x22
// 008564e2  56                   push esi
// 008564e3  ffd7                 call edi
// 008564e5  85c0                 test eax, eax
// 008564e7  751b                 jne 0x856504
// 008564e9  6af2                 push -0xe
// 008564eb  56                   push esi
// 008564ec  ffd7                 call edi
// 008564ee  85c0                 test eax, eax
// 008564f0  7512                 jne 0x856504
// 008564f2  e827d6f9ff           call 0x7f3b1e
// 008564f7  68057f0000           push 0x7f05
// 008564fc  6a00                 push 0
// 008564fe  ff1574cc9800         call dword ptr [0x98cc74]
// 00856504  5f                   pop edi
// 00856505  5e                   pop esi
// 00856506  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?GetItemIcon@CXTPTabClientWnd@@MBEPAUHICON__@@PBVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
