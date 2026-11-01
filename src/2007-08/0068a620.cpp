// from server: 100% by auto
// roc 2007-08 0068a620  unit: CXTPTabClientWnd::CWorkspace  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0068a620
//
// 0068a620  8b442404             mov eax, dword ptr [esp + 4]
// 0068a624  83780402             cmp dword ptr [eax + 4], 2
// 0068a628  753d                 jne 0x68a667
// 0068a62a  56                   push esi
// 0068a62b  8b702c               mov esi, dword ptr [eax + 0x2c]
// 0068a62e  85f6                 test esi, esi
// 0068a630  7507                 jne 0x68a639
// 0068a632  8b7104               mov esi, dword ptr [ecx + 4]
// 0068a635  85f6                 test esi, esi
// 0068a637  742d                 je 0x68a666
// 0068a639  8b818c000000         mov eax, dword ptr [ecx + 0x8c]
// 0068a63f  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0068a642  6a00                 push 0
// 0068a644  6a00                 push 0
// 0068a646  6863030000           push 0x363
// 0068a64b  51                   push ecx
// 0068a64c  ff15d0ec7700         call dword ptr [0x77ecd0]
// 0068a652  8bce                 mov ecx, esi
// 0068a654  e8172b0700           call 0x6fd170
// 0068a659  6a00                 push 0
// 0068a65b  6a00                 push 0
// 0068a65d  6a10                 push 0x10
// 0068a65f  50                   push eax
// 0068a660  ff15d8ec7700         call dword ptr [0x77ecd8]
// 0068a666  5e                   pop esi
// 0068a667  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnNavigateButtonClick@CWorkspace@CXTPTabClientWnd@@MAEXPAVCXTPTabManagerNavigateButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
