// from server: 100% by auto
// roc 2010-06 007e68e0  unit: CRobloxTreeCtrl  size: 328 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e68e0
//
// 007e68e0  53                   push ebx
// 007e68e1  8b1d54ba9e00         mov ebx, dword ptr [0x9eba54]
// 007e68e7  56                   push esi
// 007e68e8  57                   push edi
// 007e68e9  6a00                 push 0
// 007e68eb  8bf9                 mov edi, ecx
// 007e68ed  8b4734               mov eax, dword ptr [edi + 0x34]
// 007e68f0  8b4020               mov eax, dword ptr [eax + 0x20]
// 007e68f3  6a00                 push 0
// 007e68f5  680a110000           push 0x110a
// 007e68fa  50                   push eax
// 007e68fb  ffd3                 call ebx
// 007e68fd  8bf0                 mov esi, eax
// 007e68ff  85f6                 test esi, esi
// 007e6901  0f84db000000         je 0x7e69e2
// 007e6907  55                   push ebp
// 007e6908  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 007e690c  8d642400             lea esp, [esp]
// 007e6910  8b442414             mov eax, dword ptr [esp + 0x14]
// 007e6914  3bf0                 cmp esi, eax
// 007e6916  7442                 je 0x7e695a
// 007e6918  3bf5                 cmp esi, ebp
// 007e691a  743e                 je 0x7e695a
// 007e691c  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 007e6921  741b                 je 0x7e693e
// 007e6923  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 007e6926  6a02                 push 2
// 007e6928  56                   push esi
// 007e6929  e814671900           call 0x97d042
// 007e692e  a802                 test al, 2
// 007e6930  740c                 je 0x7e693e
// 007e6932  6a02                 push 2
// 007e6934  6a00                 push 0
// 007e6936  56                   push esi
// 007e6937  8bcf                 mov ecx, edi
// 007e6939  e8d2f9ffff           call 0x7e6310
// 007e693e  8b4734               mov eax, dword ptr [edi + 0x34]
// 007e6941  8b4820               mov ecx, dword ptr [eax + 0x20]
// 007e6944  56                   push esi
// 007e6945  6a06                 push 6
// 007e6947  680a110000           push 0x110a
// 007e694c  51                   push ecx
// 007e694d  ffd3                 call ebx
// 007e694f  8bf0                 mov esi, eax
// 007e6951  85f6                 test esi, esi
// 007e6953  75bb                 jne 0x7e6910
// 007e6955  e987000000           jmp 0x7e69e1
// 007e695a  3bc5                 cmp eax, ebp
// 007e695c  742e                 je 0x7e698c
// 007e695e  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 007e6961  6a02                 push 2
// 007e6963  56                   push esi
// 007e6964  e8d9661900           call 0x97d042
// 007e6969  a802                 test al, 2
// 007e696b  750c                 jne 0x7e6979
// 007e696d  6a02                 push 2
// 007e696f  6a02                 push 2
// 007e6971  56                   push esi
// 007e6972  8bcf                 mov ecx, edi
// 007e6974  e897f9ffff           call 0x7e6310
// 007e6979  8b4734               mov eax, dword ptr [edi + 0x34]
// 007e697c  8b5020               mov edx, dword ptr [eax + 0x20]
// 007e697f  56                   push esi
// 007e6980  6a06                 push 6
// 007e6982  680a110000           push 0x110a
// 007e6987  52                   push edx
// 007e6988  ffd3                 call ebx
// 007e698a  8bf0                 mov esi, eax
// 007e698c  85f6                 test esi, esi
// 007e698e  7451                 je 0x7e69e1
// 007e6990  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 007e6993  6a02                 push 2
// 007e6995  56                   push esi
// 007e6996  e8a7661900           call 0x97d042
// 007e699b  a802                 test al, 2
// 007e699d  750c                 jne 0x7e69ab
// 007e699f  6a02                 push 2
// 007e69a1  6a02                 push 2
// 007e69a3  56                   push esi
// 007e69a4  8bcf                 mov ecx, edi
// 007e69a6  e865f9ffff           call 0x7e6310
// 007e69ab  3b742414             cmp esi, dword ptr [esp + 0x14]
// 007e69af  741d                 je 0x7e69ce
// 007e69b1  3bf5                 cmp esi, ebp
// 007e69b3  7419                 je 0x7e69ce
// 007e69b5  8b4734               mov eax, dword ptr [edi + 0x34]
// 007e69b8  8b4020               mov eax, dword ptr [eax + 0x20]
// 007e69bb  56                   push esi
// 007e69bc  6a06                 push 6
// 007e69be  680a110000           push 0x110a
// 007e69c3  50                   push eax
// 007e69c4  ffd3                 call ebx
// 007e69c6  8bf0                 mov esi, eax
// 007e69c8  85f6                 test esi, esi
// 007e69ca  75c4                 jne 0x7e6990
// 007e69cc  eb13                 jmp 0x7e69e1
// 007e69ce  8b4734               mov eax, dword ptr [edi + 0x34]
// 007e69d1  8b4820               mov ecx, dword ptr [eax + 0x20]
// 007e69d4  56                   push esi
// 007e69d5  6a06                 push 6
// 007e69d7  680a110000           push 0x110a
// 007e69dc  51                   push ecx
// 007e69dd  ffd3                 call ebx
// 007e69df  8bf0                 mov esi, eax
// 007e69e1  5d                   pop ebp
// 007e69e2  837c241800           cmp dword ptr [esp + 0x18], 0
// 007e69e7  7439                 je 0x7e6a22
// 007e69e9  85f6                 test esi, esi
// 007e69eb  7435                 je 0x7e6a22
// 007e69ed  8d4900               lea ecx, [ecx]
// 007e69f0  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 007e69f3  6a02                 push 2
// 007e69f5  56                   push esi
// 007e69f6  e847661900           call 0x97d042
// 007e69fb  a802                 test al, 2
// 007e69fd  740c                 je 0x7e6a0b
// 007e69ff  6a02                 push 2
// 007e6a01  6a00                 push 0
// 007e6a03  56                   push esi
// 007e6a04  8bcf                 mov ecx, edi
// 007e6a06  e805f9ffff           call 0x7e6310
// 007e6a0b  8b4734               mov eax, dword ptr [edi + 0x34]
// 007e6a0e  8b5020               mov edx, dword ptr [eax + 0x20]
// 007e6a11  56                   push esi
// 007e6a12  6a06                 push 6
// 007e6a14  680a110000           push 0x110a
// 007e6a19  52                   push edx
// 007e6a1a  ffd3                 call ebx
// 007e6a1c  8bf0                 mov esi, eax
// 007e6a1e  85f6                 test esi, esi
// 007e6a20  75ce                 jne 0x7e69f0
// 007e6a22  5f                   pop edi
// 007e6a23  5e                   pop esi
// 007e6a24  5b                   pop ebx
// 007e6a25  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?SelectItems@CXTTreeBase@@QAEXPAU_TREEITEM@@0H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
