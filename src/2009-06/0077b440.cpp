// from server: 100% by auto
// roc 2009-06 0077b440  unit: CXTPTabClientWnd  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077b440
//
// 0077b440  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0077b444  56                   push esi
// 0077b445  57                   push edi
// 0077b446  e88561f3ff           call 0x6b15d0
// 0077b44b  8b3d90ee8900         mov edi, dword ptr [0x89ee90]
// 0077b451  6a00                 push 0
// 0077b453  6a00                 push 0
// 0077b455  8bf0                 mov esi, eax
// 0077b457  6860280000           push 0x2860
// 0077b45c  56                   push esi
// 0077b45d  ffd7                 call edi
// 0077b45f  85c0                 test eax, eax
// 0077b461  7541                 jne 0x77b4a4
// 0077b463  50                   push eax
// 0077b464  50                   push eax
// 0077b465  6a7f                 push 0x7f
// 0077b467  56                   push esi
// 0077b468  ffd7                 call edi
// 0077b46a  85c0                 test eax, eax
// 0077b46c  7536                 jne 0x77b4a4
// 0077b46e  50                   push eax
// 0077b46f  6a01                 push 1
// 0077b471  6a7f                 push 0x7f
// 0077b473  56                   push esi
// 0077b474  ffd7                 call edi
// 0077b476  85c0                 test eax, eax
// 0077b478  752a                 jne 0x77b4a4
// 0077b47a  8b3d70ec8900         mov edi, dword ptr [0x89ec70]
// 0077b480  6ade                 push -0x22
// 0077b482  56                   push esi
// 0077b483  ffd7                 call edi
// 0077b485  85c0                 test eax, eax
// 0077b487  751b                 jne 0x77b4a4
// 0077b489  6af2                 push -0xe
// 0077b48b  56                   push esi
// 0077b48c  ffd7                 call edi
// 0077b48e  85c0                 test eax, eax
// 0077b490  7512                 jne 0x77b4a4
// 0077b492  e85fd8f9ff           call 0x718cf6
// 0077b497  68057f0000           push 0x7f05
// 0077b49c  6a00                 push 0
// 0077b49e  ff15f0ed8900         call dword ptr [0x89edf0]
// 0077b4a4  5f                   pop edi
// 0077b4a5  5e                   pop esi
// 0077b4a6  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?GetItemIcon@CXTPTabClientWnd@@MBEPAUHICON__@@PBVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
