// from server: 100% by auto
// roc 2010-06 007e5b20  unit: CXTTreeBase  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e5b20
//
// 007e5b20  53                   push ebx
// 007e5b21  56                   push esi
// 007e5b22  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007e5b26  57                   push edi
// 007e5b27  8bf9                 mov edi, ecx
// 007e5b29  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 007e5b2c  56                   push esi
// 007e5b2d  e82e751900           call 0x97d060
// 007e5b32  8b1d54ba9e00         mov ebx, dword ptr [0x9eba54]
// 007e5b38  85c0                 test eax, eax
// 007e5b3a  7415                 je 0x7e5b51
// 007e5b3c  8b4734               mov eax, dword ptr [edi + 0x34]
// 007e5b3f  8b4020               mov eax, dword ptr [eax + 0x20]
// 007e5b42  56                   push esi
// 007e5b43  6a04                 push 4
// 007e5b45  680a110000           push 0x110a
// 007e5b4a  50                   push eax
// 007e5b4b  ffd3                 call ebx
// 007e5b4d  85c0                 test eax, eax
// 007e5b4f  7549                 jne 0x7e5b9a
// 007e5b51  8b4734               mov eax, dword ptr [edi + 0x34]
// 007e5b54  8b4820               mov ecx, dword ptr [eax + 0x20]
// 007e5b57  56                   push esi
// 007e5b58  6a01                 push 1
// 007e5b5a  680a110000           push 0x110a
// 007e5b5f  51                   push ecx
// 007e5b60  ffd3                 call ebx
// 007e5b62  85c0                 test eax, eax
// 007e5b64  7534                 jne 0x7e5b9a
// 007e5b66  8b4734               mov eax, dword ptr [edi + 0x34]
// 007e5b69  8b5020               mov edx, dword ptr [eax + 0x20]
// 007e5b6c  56                   push esi
// 007e5b6d  6a03                 push 3
// 007e5b6f  680a110000           push 0x110a
// 007e5b74  52                   push edx
// 007e5b75  ffd3                 call ebx
// 007e5b77  8bf0                 mov esi, eax
// 007e5b79  85f6                 test esi, esi
// 007e5b7b  741b                 je 0x7e5b98
// 007e5b7d  8b4734               mov eax, dword ptr [edi + 0x34]
// 007e5b80  8b4020               mov eax, dword ptr [eax + 0x20]
// 007e5b83  56                   push esi
// 007e5b84  6a01                 push 1
// 007e5b86  680a110000           push 0x110a
// 007e5b8b  50                   push eax
// 007e5b8c  ffd3                 call ebx
// 007e5b8e  85c0                 test eax, eax
// 007e5b90  74d4                 je 0x7e5b66
// 007e5b92  5f                   pop edi
// 007e5b93  5e                   pop esi
// 007e5b94  5b                   pop ebx
// 007e5b95  c20400               ret 4
// 007e5b98  33c0                 xor eax, eax
// 007e5b9a  5f                   pop edi
// 007e5b9b  5e                   pop esi
// 007e5b9c  5b                   pop ebx
// 007e5b9d  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?GetNextItem@CXTTreeBase@@UBEPAU_TREEITEM@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
