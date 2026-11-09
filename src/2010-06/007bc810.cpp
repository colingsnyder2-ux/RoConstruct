// from server: 100% by auto
// roc 2010-06 007bc810  unit: CXTPCommandBar  size: 657 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bc810
//
// 007bc810  83ec18               sub esp, 0x18
// 007bc813  53                   push ebx
// 007bc814  57                   push edi
// 007bc815  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 007bc819  33db                 xor ebx, ebx
// 007bc81b  895c2414             mov dword ptr [esp + 0x14], ebx
// 007bc81f  3bfb                 cmp edi, ebx
// 007bc821  0f8470020000         je 0x7bca97
// 007bc827  395c2438             cmp dword ptr [esp + 0x38], ebx
// 007bc82b  0f8466020000         je 0x7bca97
// 007bc831  55                   push ebp
// 007bc832  56                   push esi
// 007bc833  68ffffff00           push 0xffffff
// 007bc838  57                   push edi
// 007bc839  895c241c             mov dword ptr [esp + 0x1c], ebx
// 007bc83d  895c2418             mov dword ptr [esp + 0x18], ebx
// 007bc841  895c2420             mov dword ptr [esp + 0x20], ebx
// 007bc845  ff1544a19e00         call dword ptr [0x9ea144]
// 007bc84b  53                   push ebx
// 007bc84c  57                   push edi
// 007bc84d  89442428             mov dword ptr [esp + 0x28], eax
// 007bc851  ff1548a19e00         call dword ptr [0x9ea148]
// 007bc857  8b35aca09e00         mov esi, dword ptr [0x9ea0ac]
// 007bc85d  57                   push edi
// 007bc85e  89442428             mov dword ptr [esp + 0x28], eax
// 007bc862  ffd6                 call esi
// 007bc864  8be8                 mov ebp, eax
// 007bc866  3beb                 cmp ebp, ebx
// 007bc868  0f8403020000         je 0x7bca71
// 007bc86e  8b442440             mov eax, dword ptr [esp + 0x40]
// 007bc872  50                   push eax
// 007bc873  ffd6                 call esi
// 007bc875  8bf0                 mov esi, eax
// 007bc877  3bf3                 cmp esi, ebx
// 007bc879  0f84b4010000         je 0x7bca33
// 007bc87f  8b5c2450             mov ebx, dword ptr [esp + 0x50]
// 007bc883  8b7c244c             mov edi, dword ptr [esp + 0x4c]
// 007bc887  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007bc88b  53                   push ebx
// 007bc88c  57                   push edi
// 007bc88d  51                   push ecx
// 007bc88e  ff15c4a09e00         call dword ptr [0x9ea0c4]
// 007bc894  89442410             mov dword ptr [esp + 0x10], eax
// 007bc898  85c0                 test eax, eax
// 007bc89a  0f848f010000         je 0x7bca2f
// 007bc8a0  8bd0                 mov edx, eax
// 007bc8a2  52                   push edx
// 007bc8a3  56                   push esi
// 007bc8a4  ff15c8a09e00         call dword ptr [0x9ea0c8]
// 007bc8aa  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 007bc8ae  8b542440             mov edx, dword ptr [esp + 0x40]
// 007bc8b2  682000cc00           push 0xcc0020
// 007bc8b7  8944241c             mov dword ptr [esp + 0x1c], eax
// 007bc8bb  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 007bc8bf  50                   push eax
// 007bc8c0  51                   push ecx
// 007bc8c1  52                   push edx
// 007bc8c2  53                   push ebx
// 007bc8c3  57                   push edi
// 007bc8c4  6a00                 push 0
// 007bc8c6  6a00                 push 0
// 007bc8c8  56                   push esi
// 007bc8c9  ff15c0a09e00         call dword ptr [0x9ea0c0]
// 007bc8cf  85c0                 test eax, eax
// 007bc8d1  0f8458010000         je 0x7bca2f
// 007bc8d7  6a00                 push 0
// 007bc8d9  6a01                 push 1
// 007bc8db  6a01                 push 1
// 007bc8dd  53                   push ebx
// 007bc8de  57                   push edi
// 007bc8df  ff1588a19e00         call dword ptr [0x9ea188]
// 007bc8e5  89442414             mov dword ptr [esp + 0x14], eax
// 007bc8e9  85c0                 test eax, eax
// 007bc8eb  0f843e010000         je 0x7bca2f
// 007bc8f1  50                   push eax
// 007bc8f2  55                   push ebp
// 007bc8f3  ff15c8a09e00         call dword ptr [0x9ea0c8]
// 007bc8f9  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 007bc8fd  51                   push ecx
// 007bc8fe  56                   push esi
// 007bc8ff  89442448             mov dword ptr [esp + 0x48], eax
// 007bc903  ff1544a19e00         call dword ptr [0x9ea144]
// 007bc909  682000cc00           push 0xcc0020
// 007bc90e  6a00                 push 0
// 007bc910  6a00                 push 0
// 007bc912  56                   push esi
// 007bc913  53                   push ebx
// 007bc914  57                   push edi
// 007bc915  6a00                 push 0
// 007bc917  6a00                 push 0
// 007bc919  55                   push ebp
// 007bc91a  ff15c0a09e00         call dword ptr [0x9ea0c0]
// 007bc920  85c0                 test eax, eax
// 007bc922  0f84f7000000         je 0x7bca1f
// 007bc928  837c245400           cmp dword ptr [esp + 0x54], 0
// 007bc92d  7434                 je 0x7bc963
// 007bc92f  6a00                 push 0
// 007bc931  56                   push esi
// 007bc932  ff1544a19e00         call dword ptr [0x9ea144]
// 007bc938  68ffffff00           push 0xffffff
// 007bc93d  56                   push esi
// 007bc93e  ff1548a19e00         call dword ptr [0x9ea148]
// 007bc944  68c6008800           push 0x8800c6
// 007bc949  6a00                 push 0
// 007bc94b  6a00                 push 0
// 007bc94d  55                   push ebp
// 007bc94e  53                   push ebx
// 007bc94f  57                   push edi
// 007bc950  6a00                 push 0
// 007bc952  6a00                 push 0
// 007bc954  56                   push esi
// 007bc955  ff15c0a09e00         call dword ptr [0x9ea0c0]
// 007bc95b  85c0                 test eax, eax
// 007bc95d  0f84bc000000         je 0x7bca1f
// 007bc963  8b442438             mov eax, dword ptr [esp + 0x38]
// 007bc967  3bc7                 cmp eax, edi
// 007bc969  7552                 jne 0x7bc9bd
// 007bc96b  395c243c             cmp dword ptr [esp + 0x3c], ebx
// 007bc96f  754c                 jne 0x7bc9bd
// 007bc971  8b542434             mov edx, dword ptr [esp + 0x34]
// 007bc975  8b442430             mov eax, dword ptr [esp + 0x30]
// 007bc979  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007bc97d  68c6008800           push 0x8800c6
// 007bc982  6a00                 push 0
// 007bc984  6a00                 push 0
// 007bc986  55                   push ebp
// 007bc987  53                   push ebx
// 007bc988  57                   push edi
// 007bc989  52                   push edx
// 007bc98a  50                   push eax
// 007bc98b  51                   push ecx
// 007bc98c  ff15c0a09e00         call dword ptr [0x9ea0c0]
// 007bc992  85c0                 test eax, eax
// 007bc994  0f8485000000         je 0x7bca1f
// 007bc99a  8b542434             mov edx, dword ptr [esp + 0x34]
// 007bc99e  8b442430             mov eax, dword ptr [esp + 0x30]
// 007bc9a2  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007bc9a6  688600ee00           push 0xee0086
// 007bc9ab  6a00                 push 0
// 007bc9ad  6a00                 push 0
// 007bc9af  56                   push esi
// 007bc9b0  53                   push ebx
// 007bc9b1  57                   push edi
// 007bc9b2  52                   push edx
// 007bc9b3  50                   push eax
// 007bc9b4  51                   push ecx
// 007bc9b5  ff15c0a09e00         call dword ptr [0x9ea0c0]
// 007bc9bb  eb56                 jmp 0x7bca13
// 007bc9bd  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 007bc9c1  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007bc9c5  68c6008800           push 0x8800c6
// 007bc9ca  53                   push ebx
// 007bc9cb  57                   push edi
// 007bc9cc  6a00                 push 0
// 007bc9ce  6a00                 push 0
// 007bc9d0  55                   push ebp
// 007bc9d1  52                   push edx
// 007bc9d2  8b542448             mov edx, dword ptr [esp + 0x48]
// 007bc9d6  50                   push eax
// 007bc9d7  8b442454             mov eax, dword ptr [esp + 0x54]
// 007bc9db  50                   push eax
// 007bc9dc  51                   push ecx
// 007bc9dd  52                   push edx
// 007bc9de  ff1564a19e00         call dword ptr [0x9ea164]
// 007bc9e4  85c0                 test eax, eax
// 007bc9e6  7437                 je 0x7bca1f
// 007bc9e8  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 007bc9ec  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 007bc9f0  8b542434             mov edx, dword ptr [esp + 0x34]
// 007bc9f4  688600ee00           push 0xee0086
// 007bc9f9  53                   push ebx
// 007bc9fa  57                   push edi
// 007bc9fb  6a00                 push 0
// 007bc9fd  6a00                 push 0
// 007bc9ff  56                   push esi
// 007bca00  50                   push eax
// 007bca01  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 007bca05  51                   push ecx
// 007bca06  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 007bca0a  52                   push edx
// 007bca0b  50                   push eax
// 007bca0c  51                   push ecx
// 007bca0d  ff1564a19e00         call dword ptr [0x9ea164]
// 007bca13  85c0                 test eax, eax
// 007bca15  7408                 je 0x7bca1f
// 007bca17  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 007bca1f  8b442440             mov eax, dword ptr [esp + 0x40]
// 007bca23  85c0                 test eax, eax
// 007bca25  7408                 je 0x7bca2f
// 007bca27  50                   push eax
// 007bca28  55                   push ebp
// 007bca29  ff15c8a09e00         call dword ptr [0x9ea0c8]
// 007bca2f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 007bca33  8b1dd0a09e00         mov ebx, dword ptr [0x9ea0d0]
// 007bca39  55                   push ebp
// 007bca3a  ffd3                 call ebx
// 007bca3c  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 007bca40  85ed                 test ebp, ebp
// 007bca42  7417                 je 0x7bca5b
// 007bca44  8b442418             mov eax, dword ptr [esp + 0x18]
// 007bca48  85c0                 test eax, eax
// 007bca4a  7408                 je 0x7bca54
// 007bca4c  50                   push eax
// 007bca4d  56                   push esi
// 007bca4e  ff15c8a09e00         call dword ptr [0x9ea0c8]
// 007bca54  55                   push ebp
// 007bca55  ff15d4a09e00         call dword ptr [0x9ea0d4]
// 007bca5b  85f6                 test esi, esi
// 007bca5d  7403                 je 0x7bca62
// 007bca5f  56                   push esi
// 007bca60  ffd3                 call ebx
// 007bca62  8b442414             mov eax, dword ptr [esp + 0x14]
// 007bca66  85c0                 test eax, eax
// 007bca68  7407                 je 0x7bca71
// 007bca6a  50                   push eax
// 007bca6b  ff15d4a09e00         call dword ptr [0x9ea0d4]
// 007bca71  8b542420             mov edx, dword ptr [esp + 0x20]
// 007bca75  52                   push edx
// 007bca76  57                   push edi
// 007bca77  ff1544a19e00         call dword ptr [0x9ea144]
// 007bca7d  8b442424             mov eax, dword ptr [esp + 0x24]
// 007bca81  50                   push eax
// 007bca82  57                   push edi
// 007bca83  ff1548a19e00         call dword ptr [0x9ea148]
// 007bca89  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007bca8d  5e                   pop esi
// 007bca8e  5d                   pop ebp
// 007bca8f  5f                   pop edi
// 007bca90  5b                   pop ebx
// 007bca91  83c418               add esp, 0x18
// 007bca94  c22c00               ret 0x2c
// 007bca97  5f                   pop edi
// 007bca98  33c0                 xor eax, eax
// 007bca9a  5b                   pop ebx
// 007bca9b  83c418               add esp, 0x18
// 007bca9e  c22c00               ret 0x2c
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?McTransparentBlt@CXTPImageManager@@ABEHPAUHDC__@@HHHH0HHHHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
