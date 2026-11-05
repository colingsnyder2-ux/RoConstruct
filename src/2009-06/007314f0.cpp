// from server: 100% by auto
// roc 2009-06 007314f0  unit: CXTPCommandBar  size: 657 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007314f0
//
// 007314f0  83ec18               sub esp, 0x18
// 007314f3  53                   push ebx
// 007314f4  57                   push edi
// 007314f5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 007314f9  33db                 xor ebx, ebx
// 007314fb  895c2414             mov dword ptr [esp + 0x14], ebx
// 007314ff  3bfb                 cmp edi, ebx
// 00731501  0f8470020000         je 0x731777
// 00731507  395c2438             cmp dword ptr [esp + 0x38], ebx
// 0073150b  0f8466020000         je 0x731777
// 00731511  55                   push ebp
// 00731512  56                   push esi
// 00731513  68ffffff00           push 0xffffff
// 00731518  57                   push edi
// 00731519  895c241c             mov dword ptr [esp + 0x1c], ebx
// 0073151d  895c2418             mov dword ptr [esp + 0x18], ebx
// 00731521  895c2420             mov dword ptr [esp + 0x20], ebx
// 00731525  ff15b8e08900         call dword ptr [0x89e0b8]
// 0073152b  53                   push ebx
// 0073152c  57                   push edi
// 0073152d  89442428             mov dword ptr [esp + 0x28], eax
// 00731531  ff15bce08900         call dword ptr [0x89e0bc]
// 00731537  8b3520e18900         mov esi, dword ptr [0x89e120]
// 0073153d  57                   push edi
// 0073153e  89442428             mov dword ptr [esp + 0x28], eax
// 00731542  ffd6                 call esi
// 00731544  8be8                 mov ebp, eax
// 00731546  3beb                 cmp ebp, ebx
// 00731548  0f8403020000         je 0x731751
// 0073154e  8b442440             mov eax, dword ptr [esp + 0x40]
// 00731552  50                   push eax
// 00731553  ffd6                 call esi
// 00731555  8bf0                 mov esi, eax
// 00731557  3bf3                 cmp esi, ebx
// 00731559  0f84b4010000         je 0x731713
// 0073155f  8b5c2450             mov ebx, dword ptr [esp + 0x50]
// 00731563  8b7c244c             mov edi, dword ptr [esp + 0x4c]
// 00731567  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0073156b  53                   push ebx
// 0073156c  57                   push edi
// 0073156d  51                   push ecx
// 0073156e  ff15c0e08900         call dword ptr [0x89e0c0]
// 00731574  89442410             mov dword ptr [esp + 0x10], eax
// 00731578  85c0                 test eax, eax
// 0073157a  0f848f010000         je 0x73170f
// 00731580  8bd0                 mov edx, eax
// 00731582  52                   push edx
// 00731583  56                   push esi
// 00731584  ff1524e18900         call dword ptr [0x89e124]
// 0073158a  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0073158e  8b542440             mov edx, dword ptr [esp + 0x40]
// 00731592  682000cc00           push 0xcc0020
// 00731597  8944241c             mov dword ptr [esp + 0x1c], eax
// 0073159b  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0073159f  50                   push eax
// 007315a0  51                   push ecx
// 007315a1  52                   push edx
// 007315a2  53                   push ebx
// 007315a3  57                   push edi
// 007315a4  6a00                 push 0
// 007315a6  6a00                 push 0
// 007315a8  56                   push esi
// 007315a9  ff15e0e08900         call dword ptr [0x89e0e0]
// 007315af  85c0                 test eax, eax
// 007315b1  0f8458010000         je 0x73170f
// 007315b7  6a00                 push 0
// 007315b9  6a01                 push 1
// 007315bb  6a01                 push 1
// 007315bd  53                   push ebx
// 007315be  57                   push edi
// 007315bf  ff1544e18900         call dword ptr [0x89e144]
// 007315c5  89442414             mov dword ptr [esp + 0x14], eax
// 007315c9  85c0                 test eax, eax
// 007315cb  0f843e010000         je 0x73170f
// 007315d1  50                   push eax
// 007315d2  55                   push ebp
// 007315d3  ff1524e18900         call dword ptr [0x89e124]
// 007315d9  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 007315dd  51                   push ecx
// 007315de  56                   push esi
// 007315df  89442448             mov dword ptr [esp + 0x48], eax
// 007315e3  ff15b8e08900         call dword ptr [0x89e0b8]
// 007315e9  682000cc00           push 0xcc0020
// 007315ee  6a00                 push 0
// 007315f0  6a00                 push 0
// 007315f2  56                   push esi
// 007315f3  53                   push ebx
// 007315f4  57                   push edi
// 007315f5  6a00                 push 0
// 007315f7  6a00                 push 0
// 007315f9  55                   push ebp
// 007315fa  ff15e0e08900         call dword ptr [0x89e0e0]
// 00731600  85c0                 test eax, eax
// 00731602  0f84f7000000         je 0x7316ff
// 00731608  837c245400           cmp dword ptr [esp + 0x54], 0
// 0073160d  7434                 je 0x731643
// 0073160f  6a00                 push 0
// 00731611  56                   push esi
// 00731612  ff15b8e08900         call dword ptr [0x89e0b8]
// 00731618  68ffffff00           push 0xffffff
// 0073161d  56                   push esi
// 0073161e  ff15bce08900         call dword ptr [0x89e0bc]
// 00731624  68c6008800           push 0x8800c6
// 00731629  6a00                 push 0
// 0073162b  6a00                 push 0
// 0073162d  55                   push ebp
// 0073162e  53                   push ebx
// 0073162f  57                   push edi
// 00731630  6a00                 push 0
// 00731632  6a00                 push 0
// 00731634  56                   push esi
// 00731635  ff15e0e08900         call dword ptr [0x89e0e0]
// 0073163b  85c0                 test eax, eax
// 0073163d  0f84bc000000         je 0x7316ff
// 00731643  8b442438             mov eax, dword ptr [esp + 0x38]
// 00731647  3bc7                 cmp eax, edi
// 00731649  7552                 jne 0x73169d
// 0073164b  395c243c             cmp dword ptr [esp + 0x3c], ebx
// 0073164f  754c                 jne 0x73169d
// 00731651  8b542434             mov edx, dword ptr [esp + 0x34]
// 00731655  8b442430             mov eax, dword ptr [esp + 0x30]
// 00731659  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0073165d  68c6008800           push 0x8800c6
// 00731662  6a00                 push 0
// 00731664  6a00                 push 0
// 00731666  55                   push ebp
// 00731667  53                   push ebx
// 00731668  57                   push edi
// 00731669  52                   push edx
// 0073166a  50                   push eax
// 0073166b  51                   push ecx
// 0073166c  ff15e0e08900         call dword ptr [0x89e0e0]
// 00731672  85c0                 test eax, eax
// 00731674  0f8485000000         je 0x7316ff
// 0073167a  8b542434             mov edx, dword ptr [esp + 0x34]
// 0073167e  8b442430             mov eax, dword ptr [esp + 0x30]
// 00731682  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00731686  688600ee00           push 0xee0086
// 0073168b  6a00                 push 0
// 0073168d  6a00                 push 0
// 0073168f  56                   push esi
// 00731690  53                   push ebx
// 00731691  57                   push edi
// 00731692  52                   push edx
// 00731693  50                   push eax
// 00731694  51                   push ecx
// 00731695  ff15e0e08900         call dword ptr [0x89e0e0]
// 0073169b  eb56                 jmp 0x7316f3
// 0073169d  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 007316a1  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007316a5  68c6008800           push 0x8800c6
// 007316aa  53                   push ebx
// 007316ab  57                   push edi
// 007316ac  6a00                 push 0
// 007316ae  6a00                 push 0
// 007316b0  55                   push ebp
// 007316b1  52                   push edx
// 007316b2  8b542448             mov edx, dword ptr [esp + 0x48]
// 007316b6  50                   push eax
// 007316b7  8b442454             mov eax, dword ptr [esp + 0x54]
// 007316bb  50                   push eax
// 007316bc  51                   push ecx
// 007316bd  52                   push edx
// 007316be  ff15dce08900         call dword ptr [0x89e0dc]
// 007316c4  85c0                 test eax, eax
// 007316c6  7437                 je 0x7316ff
// 007316c8  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 007316cc  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 007316d0  8b542434             mov edx, dword ptr [esp + 0x34]
// 007316d4  688600ee00           push 0xee0086
// 007316d9  53                   push ebx
// 007316da  57                   push edi
// 007316db  6a00                 push 0
// 007316dd  6a00                 push 0
// 007316df  56                   push esi
// 007316e0  50                   push eax
// 007316e1  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 007316e5  51                   push ecx
// 007316e6  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 007316ea  52                   push edx
// 007316eb  50                   push eax
// 007316ec  51                   push ecx
// 007316ed  ff15dce08900         call dword ptr [0x89e0dc]
// 007316f3  85c0                 test eax, eax
// 007316f5  7408                 je 0x7316ff
// 007316f7  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 007316ff  8b442440             mov eax, dword ptr [esp + 0x40]
// 00731703  85c0                 test eax, eax
// 00731705  7408                 je 0x73170f
// 00731707  50                   push eax
// 00731708  55                   push ebp
// 00731709  ff1524e18900         call dword ptr [0x89e124]
// 0073170f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00731713  8b1d2ce18900         mov ebx, dword ptr [0x89e12c]
// 00731719  55                   push ebp
// 0073171a  ffd3                 call ebx
// 0073171c  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00731720  85ed                 test ebp, ebp
// 00731722  7417                 je 0x73173b
// 00731724  8b442418             mov eax, dword ptr [esp + 0x18]
// 00731728  85c0                 test eax, eax
// 0073172a  7408                 je 0x731734
// 0073172c  50                   push eax
// 0073172d  56                   push esi
// 0073172e  ff1524e18900         call dword ptr [0x89e124]
// 00731734  55                   push ebp
// 00731735  ff1560e18900         call dword ptr [0x89e160]
// 0073173b  85f6                 test esi, esi
// 0073173d  7403                 je 0x731742
// 0073173f  56                   push esi
// 00731740  ffd3                 call ebx
// 00731742  8b442414             mov eax, dword ptr [esp + 0x14]
// 00731746  85c0                 test eax, eax
// 00731748  7407                 je 0x731751
// 0073174a  50                   push eax
// 0073174b  ff1560e18900         call dword ptr [0x89e160]
// 00731751  8b542420             mov edx, dword ptr [esp + 0x20]
// 00731755  52                   push edx
// 00731756  57                   push edi
// 00731757  ff15b8e08900         call dword ptr [0x89e0b8]
// 0073175d  8b442424             mov eax, dword ptr [esp + 0x24]
// 00731761  50                   push eax
// 00731762  57                   push edi
// 00731763  ff15bce08900         call dword ptr [0x89e0bc]
// 00731769  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0073176d  5e                   pop esi
// 0073176e  5d                   pop ebp
// 0073176f  5f                   pop edi
// 00731770  5b                   pop ebx
// 00731771  83c418               add esp, 0x18
// 00731774  c22c00               ret 0x2c
// 00731777  5f                   pop edi
// 00731778  33c0                 xor eax, eax
// 0073177a  5b                   pop ebx
// 0073177b  83c418               add esp, 0x18
// 0073177e  c22c00               ret 0x2c
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?McTransparentBlt@CXTPImageManager@@ABEHPAUHDC__@@HHHH0HHHHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
