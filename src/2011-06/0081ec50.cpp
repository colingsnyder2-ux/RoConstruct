// from server: 100% by auto
// roc 2011-06 0081ec50  unit: CXTPCommandBar  size: 657 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0081ec50
//
// 0081ec50  83ec18               sub esp, 0x18
// 0081ec53  53                   push ebx
// 0081ec54  57                   push edi
// 0081ec55  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0081ec59  33db                 xor ebx, ebx
// 0081ec5b  895c2414             mov dword ptr [esp + 0x14], ebx
// 0081ec5f  3bfb                 cmp edi, ebx
// 0081ec61  0f8470020000         je 0x81eed7
// 0081ec67  395c2438             cmp dword ptr [esp + 0x38], ebx
// 0081ec6b  0f8466020000         je 0x81eed7
// 0081ec71  55                   push ebp
// 0081ec72  56                   push esi
// 0081ec73  68ffffff00           push 0xffffff
// 0081ec78  57                   push edi
// 0081ec79  895c241c             mov dword ptr [esp + 0x1c], ebx
// 0081ec7d  895c2418             mov dword ptr [esp + 0x18], ebx
// 0081ec81  895c2420             mov dword ptr [esp + 0x20], ebx
// 0081ec85  ff15f400a400         call dword ptr [0xa400f4]
// 0081ec8b  53                   push ebx
// 0081ec8c  57                   push edi
// 0081ec8d  89442428             mov dword ptr [esp + 0x28], eax
// 0081ec91  ff15f800a400         call dword ptr [0xa400f8]
// 0081ec97  8b358401a400         mov esi, dword ptr [0xa40184]
// 0081ec9d  57                   push edi
// 0081ec9e  89442428             mov dword ptr [esp + 0x28], eax
// 0081eca2  ffd6                 call esi
// 0081eca4  8be8                 mov ebp, eax
// 0081eca6  3beb                 cmp ebp, ebx
// 0081eca8  0f8403020000         je 0x81eeb1
// 0081ecae  8b442440             mov eax, dword ptr [esp + 0x40]
// 0081ecb2  50                   push eax
// 0081ecb3  ffd6                 call esi
// 0081ecb5  8bf0                 mov esi, eax
// 0081ecb7  3bf3                 cmp esi, ebx
// 0081ecb9  0f84b4010000         je 0x81ee73
// 0081ecbf  8b5c2450             mov ebx, dword ptr [esp + 0x50]
// 0081ecc3  8b7c244c             mov edi, dword ptr [esp + 0x4c]
// 0081ecc7  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0081eccb  53                   push ebx
// 0081eccc  57                   push edi
// 0081eccd  51                   push ecx
// 0081ecce  ff158801a400         call dword ptr [0xa40188]
// 0081ecd4  89442410             mov dword ptr [esp + 0x10], eax
// 0081ecd8  85c0                 test eax, eax
// 0081ecda  0f848f010000         je 0x81ee6f
// 0081ece0  8bd0                 mov edx, eax
// 0081ece2  52                   push edx
// 0081ece3  56                   push esi
// 0081ece4  ff158c01a400         call dword ptr [0xa4018c]
// 0081ecea  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0081ecee  8b542440             mov edx, dword ptr [esp + 0x40]
// 0081ecf2  682000cc00           push 0xcc0020
// 0081ecf7  8944241c             mov dword ptr [esp + 0x1c], eax
// 0081ecfb  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0081ecff  50                   push eax
// 0081ed00  51                   push ecx
// 0081ed01  52                   push edx
// 0081ed02  53                   push ebx
// 0081ed03  57                   push edi
// 0081ed04  6a00                 push 0
// 0081ed06  6a00                 push 0
// 0081ed08  56                   push esi
// 0081ed09  ff159001a400         call dword ptr [0xa40190]
// 0081ed0f  85c0                 test eax, eax
// 0081ed11  0f8458010000         je 0x81ee6f
// 0081ed17  6a00                 push 0
// 0081ed19  6a01                 push 1
// 0081ed1b  6a01                 push 1
// 0081ed1d  53                   push ebx
// 0081ed1e  57                   push edi
// 0081ed1f  ff15fc00a400         call dword ptr [0xa400fc]
// 0081ed25  89442414             mov dword ptr [esp + 0x14], eax
// 0081ed29  85c0                 test eax, eax
// 0081ed2b  0f843e010000         je 0x81ee6f
// 0081ed31  50                   push eax
// 0081ed32  55                   push ebp
// 0081ed33  ff158c01a400         call dword ptr [0xa4018c]
// 0081ed39  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0081ed3d  51                   push ecx
// 0081ed3e  56                   push esi
// 0081ed3f  89442448             mov dword ptr [esp + 0x48], eax
// 0081ed43  ff15f400a400         call dword ptr [0xa400f4]
// 0081ed49  682000cc00           push 0xcc0020
// 0081ed4e  6a00                 push 0
// 0081ed50  6a00                 push 0
// 0081ed52  56                   push esi
// 0081ed53  53                   push ebx
// 0081ed54  57                   push edi
// 0081ed55  6a00                 push 0
// 0081ed57  6a00                 push 0
// 0081ed59  55                   push ebp
// 0081ed5a  ff159001a400         call dword ptr [0xa40190]
// 0081ed60  85c0                 test eax, eax
// 0081ed62  0f84f7000000         je 0x81ee5f
// 0081ed68  837c245400           cmp dword ptr [esp + 0x54], 0
// 0081ed6d  7434                 je 0x81eda3
// 0081ed6f  6a00                 push 0
// 0081ed71  56                   push esi
// 0081ed72  ff15f400a400         call dword ptr [0xa400f4]
// 0081ed78  68ffffff00           push 0xffffff
// 0081ed7d  56                   push esi
// 0081ed7e  ff15f800a400         call dword ptr [0xa400f8]
// 0081ed84  68c6008800           push 0x8800c6
// 0081ed89  6a00                 push 0
// 0081ed8b  6a00                 push 0
// 0081ed8d  55                   push ebp
// 0081ed8e  53                   push ebx
// 0081ed8f  57                   push edi
// 0081ed90  6a00                 push 0
// 0081ed92  6a00                 push 0
// 0081ed94  56                   push esi
// 0081ed95  ff159001a400         call dword ptr [0xa40190]
// 0081ed9b  85c0                 test eax, eax
// 0081ed9d  0f84bc000000         je 0x81ee5f
// 0081eda3  8b442438             mov eax, dword ptr [esp + 0x38]
// 0081eda7  3bc7                 cmp eax, edi
// 0081eda9  7552                 jne 0x81edfd
// 0081edab  395c243c             cmp dword ptr [esp + 0x3c], ebx
// 0081edaf  754c                 jne 0x81edfd
// 0081edb1  8b542434             mov edx, dword ptr [esp + 0x34]
// 0081edb5  8b442430             mov eax, dword ptr [esp + 0x30]
// 0081edb9  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0081edbd  68c6008800           push 0x8800c6
// 0081edc2  6a00                 push 0
// 0081edc4  6a00                 push 0
// 0081edc6  55                   push ebp
// 0081edc7  53                   push ebx
// 0081edc8  57                   push edi
// 0081edc9  52                   push edx
// 0081edca  50                   push eax
// 0081edcb  51                   push ecx
// 0081edcc  ff159001a400         call dword ptr [0xa40190]
// 0081edd2  85c0                 test eax, eax
// 0081edd4  0f8485000000         je 0x81ee5f
// 0081edda  8b542434             mov edx, dword ptr [esp + 0x34]
// 0081edde  8b442430             mov eax, dword ptr [esp + 0x30]
// 0081ede2  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0081ede6  688600ee00           push 0xee0086
// 0081edeb  6a00                 push 0
// 0081eded  6a00                 push 0
// 0081edef  56                   push esi
// 0081edf0  53                   push ebx
// 0081edf1  57                   push edi
// 0081edf2  52                   push edx
// 0081edf3  50                   push eax
// 0081edf4  51                   push ecx
// 0081edf5  ff159001a400         call dword ptr [0xa40190]
// 0081edfb  eb56                 jmp 0x81ee53
// 0081edfd  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0081ee01  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0081ee05  68c6008800           push 0x8800c6
// 0081ee0a  53                   push ebx
// 0081ee0b  57                   push edi
// 0081ee0c  6a00                 push 0
// 0081ee0e  6a00                 push 0
// 0081ee10  55                   push ebp
// 0081ee11  52                   push edx
// 0081ee12  8b542448             mov edx, dword ptr [esp + 0x48]
// 0081ee16  50                   push eax
// 0081ee17  8b442454             mov eax, dword ptr [esp + 0x54]
// 0081ee1b  50                   push eax
// 0081ee1c  51                   push ecx
// 0081ee1d  52                   push edx
// 0081ee1e  ff151401a400         call dword ptr [0xa40114]
// 0081ee24  85c0                 test eax, eax
// 0081ee26  7437                 je 0x81ee5f
// 0081ee28  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0081ee2c  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0081ee30  8b542434             mov edx, dword ptr [esp + 0x34]
// 0081ee34  688600ee00           push 0xee0086
// 0081ee39  53                   push ebx
// 0081ee3a  57                   push edi
// 0081ee3b  6a00                 push 0
// 0081ee3d  6a00                 push 0
// 0081ee3f  56                   push esi
// 0081ee40  50                   push eax
// 0081ee41  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0081ee45  51                   push ecx
// 0081ee46  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0081ee4a  52                   push edx
// 0081ee4b  50                   push eax
// 0081ee4c  51                   push ecx
// 0081ee4d  ff151401a400         call dword ptr [0xa40114]
// 0081ee53  85c0                 test eax, eax
// 0081ee55  7408                 je 0x81ee5f
// 0081ee57  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 0081ee5f  8b442440             mov eax, dword ptr [esp + 0x40]
// 0081ee63  85c0                 test eax, eax
// 0081ee65  7408                 je 0x81ee6f
// 0081ee67  50                   push eax
// 0081ee68  55                   push ebp
// 0081ee69  ff158c01a400         call dword ptr [0xa4018c]
// 0081ee6f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0081ee73  8b1d9801a400         mov ebx, dword ptr [0xa40198]
// 0081ee79  55                   push ebp
// 0081ee7a  ffd3                 call ebx
// 0081ee7c  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0081ee80  85ed                 test ebp, ebp
// 0081ee82  7417                 je 0x81ee9b
// 0081ee84  8b442418             mov eax, dword ptr [esp + 0x18]
// 0081ee88  85c0                 test eax, eax
// 0081ee8a  7408                 je 0x81ee94
// 0081ee8c  50                   push eax
// 0081ee8d  56                   push esi
// 0081ee8e  ff158c01a400         call dword ptr [0xa4018c]
// 0081ee94  55                   push ebp
// 0081ee95  ff159c01a400         call dword ptr [0xa4019c]
// 0081ee9b  85f6                 test esi, esi
// 0081ee9d  7403                 je 0x81eea2
// 0081ee9f  56                   push esi
// 0081eea0  ffd3                 call ebx
// 0081eea2  8b442414             mov eax, dword ptr [esp + 0x14]
// 0081eea6  85c0                 test eax, eax
// 0081eea8  7407                 je 0x81eeb1
// 0081eeaa  50                   push eax
// 0081eeab  ff159c01a400         call dword ptr [0xa4019c]
// 0081eeb1  8b542420             mov edx, dword ptr [esp + 0x20]
// 0081eeb5  52                   push edx
// 0081eeb6  57                   push edi
// 0081eeb7  ff15f400a400         call dword ptr [0xa400f4]
// 0081eebd  8b442424             mov eax, dword ptr [esp + 0x24]
// 0081eec1  50                   push eax
// 0081eec2  57                   push edi
// 0081eec3  ff15f800a400         call dword ptr [0xa400f8]
// 0081eec9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0081eecd  5e                   pop esi
// 0081eece  5d                   pop ebp
// 0081eecf  5f                   pop edi
// 0081eed0  5b                   pop ebx
// 0081eed1  83c418               add esp, 0x18
// 0081eed4  c22c00               ret 0x2c
// 0081eed7  5f                   pop edi
// 0081eed8  33c0                 xor eax, eax
// 0081eeda  5b                   pop ebx
// 0081eedb  83c418               add esp, 0x18
// 0081eede  c22c00               ret 0x2c
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?McTransparentBlt@CXTPImageManager@@ABEHPAUHDC__@@HHHH0HHHHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
