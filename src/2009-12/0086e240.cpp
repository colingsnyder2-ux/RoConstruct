// from server: 100% by auto
// roc 2009-12 0086e240  unit: CXTPResourceManager  size: 162 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086e240
//
// 0086e240  8b442408             mov eax, dword ptr [esp + 8]
// 0086e244  56                   push esi
// 0086e245  8b35ecb19800         mov esi, dword ptr [0x98b1ec]
// 0086e24b  57                   push edi
// 0086e24c  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0086e250  6a0e                 push 0xe
// 0086e252  50                   push eax
// 0086e253  57                   push edi
// 0086e254  ffd6                 call esi
// 0086e256  85c0                 test eax, eax
// 0086e258  7505                 jne 0x86e25f
// 0086e25a  5f                   pop edi
// 0086e25b  5e                   pop esi
// 0086e25c  c21000               ret 0x10
// 0086e25f  55                   push ebp
// 0086e260  8b2df0b19800         mov ebp, dword ptr [0x98b1f0]
// 0086e266  50                   push eax
// 0086e267  57                   push edi
// 0086e268  ffd5                 call ebp
// 0086e26a  85c0                 test eax, eax
// 0086e26c  7506                 jne 0x86e274
// 0086e26e  5d                   pop ebp
// 0086e26f  5f                   pop edi
// 0086e270  5e                   pop esi
// 0086e271  c21000               ret 0x10
// 0086e274  53                   push ebx
// 0086e275  8b1d7cb29800         mov ebx, dword ptr [0x98b27c]
// 0086e27b  50                   push eax
// 0086e27c  ffd3                 call ebx
// 0086e27e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0086e282  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0086e286  6a00                 push 0
// 0086e288  51                   push ecx
// 0086e289  52                   push edx
// 0086e28a  6a01                 push 1
// 0086e28c  50                   push eax
// 0086e28d  ff1578cb9800         call dword ptr [0x98cb78]
// 0086e293  0fb7c0               movzx eax, ax
// 0086e296  6a03                 push 3
// 0086e298  50                   push eax
// 0086e299  57                   push edi
// 0086e29a  ffd6                 call esi
// 0086e29c  8bf0                 mov esi, eax
// 0086e29e  85f6                 test esi, esi
// 0086e2a0  7408                 je 0x86e2aa
// 0086e2a2  56                   push esi
// 0086e2a3  57                   push edi
// 0086e2a4  ffd5                 call ebp
// 0086e2a6  85c0                 test eax, eax
// 0086e2a8  7509                 jne 0x86e2b3
// 0086e2aa  5b                   pop ebx
// 0086e2ab  5d                   pop ebp
// 0086e2ac  5f                   pop edi
// 0086e2ad  33c0                 xor eax, eax
// 0086e2af  5e                   pop esi
// 0086e2b0  c21000               ret 0x10
// 0086e2b3  50                   push eax
// 0086e2b4  ffd3                 call ebx
// 0086e2b6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0086e2ba  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0086e2be  6a00                 push 0
// 0086e2c0  51                   push ecx
// 0086e2c1  52                   push edx
// 0086e2c2  6800000300           push 0x30000
// 0086e2c7  6a01                 push 1
// 0086e2c9  56                   push esi
// 0086e2ca  57                   push edi
// 0086e2cb  8bd8                 mov ebx, eax
// 0086e2cd  ff15f4b19800         call dword ptr [0x98b1f4]
// 0086e2d3  50                   push eax
// 0086e2d4  53                   push ebx
// 0086e2d5  ff1510cb9800         call dword ptr [0x98cb10]
// 0086e2db  5b                   pop ebx
// 0086e2dc  5d                   pop ebp
// 0086e2dd  5f                   pop edi
// 0086e2de  5e                   pop esi
// 0086e2df  c21000               ret 0x10
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?CreateIconFromResource@CXTPResourceManager@@UAEPAUHICON__@@PAUHINSTANCE__@@PBDVCSize@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
