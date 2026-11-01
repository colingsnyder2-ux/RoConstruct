// from server: 100% by auto
// roc 2009-12 00808670  unit: CXTPCommandBar  size: 657 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00808670
//
// 00808670  83ec18               sub esp, 0x18
// 00808673  53                   push ebx
// 00808674  57                   push edi
// 00808675  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00808679  33db                 xor ebx, ebx
// 0080867b  895c2414             mov dword ptr [esp + 0x14], ebx
// 0080867f  3bfb                 cmp edi, ebx
// 00808681  0f8470020000         je 0x8088f7
// 00808687  395c2438             cmp dword ptr [esp + 0x38], ebx
// 0080868b  0f8466020000         je 0x8088f7
// 00808691  55                   push ebp
// 00808692  56                   push esi
// 00808693  68ffffff00           push 0xffffff
// 00808698  57                   push edi
// 00808699  895c241c             mov dword ptr [esp + 0x1c], ebx
// 0080869d  895c2418             mov dword ptr [esp + 0x18], ebx
// 008086a1  895c2420             mov dword ptr [esp + 0x20], ebx
// 008086a5  ff15fcb09800         call dword ptr [0x98b0fc]
// 008086ab  53                   push ebx
// 008086ac  57                   push edi
// 008086ad  89442428             mov dword ptr [esp + 0x28], eax
// 008086b1  ff1500b19800         call dword ptr [0x98b100]
// 008086b7  8b3554b19800         mov esi, dword ptr [0x98b154]
// 008086bd  57                   push edi
// 008086be  89442428             mov dword ptr [esp + 0x28], eax
// 008086c2  ffd6                 call esi
// 008086c4  8be8                 mov ebp, eax
// 008086c6  3beb                 cmp ebp, ebx
// 008086c8  0f8403020000         je 0x8088d1
// 008086ce  8b442440             mov eax, dword ptr [esp + 0x40]
// 008086d2  50                   push eax
// 008086d3  ffd6                 call esi
// 008086d5  8bf0                 mov esi, eax
// 008086d7  3bf3                 cmp esi, ebx
// 008086d9  0f84b4010000         je 0x808893
// 008086df  8b5c2450             mov ebx, dword ptr [esp + 0x50]
// 008086e3  8b7c244c             mov edi, dword ptr [esp + 0x4c]
// 008086e7  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 008086eb  53                   push ebx
// 008086ec  57                   push edi
// 008086ed  51                   push ecx
// 008086ee  ff1550b19800         call dword ptr [0x98b150]
// 008086f4  89442410             mov dword ptr [esp + 0x10], eax
// 008086f8  85c0                 test eax, eax
// 008086fa  0f848f010000         je 0x80888f
// 00808700  8bd0                 mov edx, eax
// 00808702  52                   push edx
// 00808703  56                   push esi
// 00808704  ff154cb19800         call dword ptr [0x98b14c]
// 0080870a  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0080870e  8b542440             mov edx, dword ptr [esp + 0x40]
// 00808712  682000cc00           push 0xcc0020
// 00808717  8944241c             mov dword ptr [esp + 0x1c], eax
// 0080871b  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0080871f  50                   push eax
// 00808720  51                   push ecx
// 00808721  52                   push edx
// 00808722  53                   push ebx
// 00808723  57                   push edi
// 00808724  6a00                 push 0
// 00808726  6a00                 push 0
// 00808728  56                   push esi
// 00808729  ff1548b19800         call dword ptr [0x98b148]
// 0080872f  85c0                 test eax, eax
// 00808731  0f8458010000         je 0x80888f
// 00808737  6a00                 push 0
// 00808739  6a01                 push 1
// 0080873b  6a01                 push 1
// 0080873d  53                   push ebx
// 0080873e  57                   push edi
// 0080873f  ff1578b19800         call dword ptr [0x98b178]
// 00808745  89442414             mov dword ptr [esp + 0x14], eax
// 00808749  85c0                 test eax, eax
// 0080874b  0f843e010000         je 0x80888f
// 00808751  50                   push eax
// 00808752  55                   push ebp
// 00808753  ff154cb19800         call dword ptr [0x98b14c]
// 00808759  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0080875d  51                   push ecx
// 0080875e  56                   push esi
// 0080875f  89442448             mov dword ptr [esp + 0x48], eax
// 00808763  ff15fcb09800         call dword ptr [0x98b0fc]
// 00808769  682000cc00           push 0xcc0020
// 0080876e  6a00                 push 0
// 00808770  6a00                 push 0
// 00808772  56                   push esi
// 00808773  53                   push ebx
// 00808774  57                   push edi
// 00808775  6a00                 push 0
// 00808777  6a00                 push 0
// 00808779  55                   push ebp
// 0080877a  ff1548b19800         call dword ptr [0x98b148]
// 00808780  85c0                 test eax, eax
// 00808782  0f84f7000000         je 0x80887f
// 00808788  837c245400           cmp dword ptr [esp + 0x54], 0
// 0080878d  7434                 je 0x8087c3
// 0080878f  6a00                 push 0
// 00808791  56                   push esi
// 00808792  ff15fcb09800         call dword ptr [0x98b0fc]
// 00808798  68ffffff00           push 0xffffff
// 0080879d  56                   push esi
// 0080879e  ff1500b19800         call dword ptr [0x98b100]
// 008087a4  68c6008800           push 0x8800c6
// 008087a9  6a00                 push 0
// 008087ab  6a00                 push 0
// 008087ad  55                   push ebp
// 008087ae  53                   push ebx
// 008087af  57                   push edi
// 008087b0  6a00                 push 0
// 008087b2  6a00                 push 0
// 008087b4  56                   push esi
// 008087b5  ff1548b19800         call dword ptr [0x98b148]
// 008087bb  85c0                 test eax, eax
// 008087bd  0f84bc000000         je 0x80887f
// 008087c3  8b442438             mov eax, dword ptr [esp + 0x38]
// 008087c7  3bc7                 cmp eax, edi
// 008087c9  7552                 jne 0x80881d
// 008087cb  395c243c             cmp dword ptr [esp + 0x3c], ebx
// 008087cf  754c                 jne 0x80881d
// 008087d1  8b542434             mov edx, dword ptr [esp + 0x34]
// 008087d5  8b442430             mov eax, dword ptr [esp + 0x30]
// 008087d9  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 008087dd  68c6008800           push 0x8800c6
// 008087e2  6a00                 push 0
// 008087e4  6a00                 push 0
// 008087e6  55                   push ebp
// 008087e7  53                   push ebx
// 008087e8  57                   push edi
// 008087e9  52                   push edx
// 008087ea  50                   push eax
// 008087eb  51                   push ecx
// 008087ec  ff1548b19800         call dword ptr [0x98b148]
// 008087f2  85c0                 test eax, eax
// 008087f4  0f8485000000         je 0x80887f
// 008087fa  8b542434             mov edx, dword ptr [esp + 0x34]
// 008087fe  8b442430             mov eax, dword ptr [esp + 0x30]
// 00808802  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00808806  688600ee00           push 0xee0086
// 0080880b  6a00                 push 0
// 0080880d  6a00                 push 0
// 0080880f  56                   push esi
// 00808810  53                   push ebx
// 00808811  57                   push edi
// 00808812  52                   push edx
// 00808813  50                   push eax
// 00808814  51                   push ecx
// 00808815  ff1548b19800         call dword ptr [0x98b148]
// 0080881b  eb56                 jmp 0x808873
// 0080881d  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 00808821  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00808825  68c6008800           push 0x8800c6
// 0080882a  53                   push ebx
// 0080882b  57                   push edi
// 0080882c  6a00                 push 0
// 0080882e  6a00                 push 0
// 00808830  55                   push ebp
// 00808831  52                   push edx
// 00808832  8b542448             mov edx, dword ptr [esp + 0x48]
// 00808836  50                   push eax
// 00808837  8b442454             mov eax, dword ptr [esp + 0x54]
// 0080883b  50                   push eax
// 0080883c  51                   push ecx
// 0080883d  52                   push edx
// 0080883e  ff151cb19800         call dword ptr [0x98b11c]
// 00808844  85c0                 test eax, eax
// 00808846  7437                 je 0x80887f
// 00808848  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0080884c  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00808850  8b542434             mov edx, dword ptr [esp + 0x34]
// 00808854  688600ee00           push 0xee0086
// 00808859  53                   push ebx
// 0080885a  57                   push edi
// 0080885b  6a00                 push 0
// 0080885d  6a00                 push 0
// 0080885f  56                   push esi
// 00808860  50                   push eax
// 00808861  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 00808865  51                   push ecx
// 00808866  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0080886a  52                   push edx
// 0080886b  50                   push eax
// 0080886c  51                   push ecx
// 0080886d  ff151cb19800         call dword ptr [0x98b11c]
// 00808873  85c0                 test eax, eax
// 00808875  7408                 je 0x80887f
// 00808877  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 0080887f  8b442440             mov eax, dword ptr [esp + 0x40]
// 00808883  85c0                 test eax, eax
// 00808885  7408                 je 0x80888f
// 00808887  50                   push eax
// 00808888  55                   push ebp
// 00808889  ff154cb19800         call dword ptr [0x98b14c]
// 0080888f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00808893  8b1d40b19800         mov ebx, dword ptr [0x98b140]
// 00808899  55                   push ebp
// 0080889a  ffd3                 call ebx
// 0080889c  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 008088a0  85ed                 test ebp, ebp
// 008088a2  7417                 je 0x8088bb
// 008088a4  8b442418             mov eax, dword ptr [esp + 0x18]
// 008088a8  85c0                 test eax, eax
// 008088aa  7408                 je 0x8088b4
// 008088ac  50                   push eax
// 008088ad  56                   push esi
// 008088ae  ff154cb19800         call dword ptr [0x98b14c]
// 008088b4  55                   push ebp
// 008088b5  ff153cb19800         call dword ptr [0x98b13c]
// 008088bb  85f6                 test esi, esi
// 008088bd  7403                 je 0x8088c2
// 008088bf  56                   push esi
// 008088c0  ffd3                 call ebx
// 008088c2  8b442414             mov eax, dword ptr [esp + 0x14]
// 008088c6  85c0                 test eax, eax
// 008088c8  7407                 je 0x8088d1
// 008088ca  50                   push eax
// 008088cb  ff153cb19800         call dword ptr [0x98b13c]
// 008088d1  8b542420             mov edx, dword ptr [esp + 0x20]
// 008088d5  52                   push edx
// 008088d6  57                   push edi
// 008088d7  ff15fcb09800         call dword ptr [0x98b0fc]
// 008088dd  8b442424             mov eax, dword ptr [esp + 0x24]
// 008088e1  50                   push eax
// 008088e2  57                   push edi
// 008088e3  ff1500b19800         call dword ptr [0x98b100]
// 008088e9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008088ed  5e                   pop esi
// 008088ee  5d                   pop ebp
// 008088ef  5f                   pop edi
// 008088f0  5b                   pop ebx
// 008088f1  83c418               add esp, 0x18
// 008088f4  c22c00               ret 0x2c
// 008088f7  5f                   pop edi
// 008088f8  33c0                 xor eax, eax
// 008088fa  5b                   pop ebx
// 008088fb  83c418               add esp, 0x18
// 008088fe  c22c00               ret 0x2c
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?McTransparentBlt@CXTPImageManager@@ABEHPAUHDC__@@HHHH0HHHHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
