// from server: 100% by auto
// roc 2010-06 00892ba0  unit: CXTColorPageCustom  size: 501 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00892ba0
//
// 00892ba0  53                   push ebx
// 00892ba1  56                   push esi
// 00892ba2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00892ba6  57                   push edi
// 00892ba7  8bf9                 mov edi, ecx
// 00892ba9  8d8788000000         lea eax, [edi + 0x88]
// 00892baf  50                   push eax
// 00892bb0  6a65                 push 0x65
// 00892bb2  56                   push esi
// 00892bb3  e83657f1ff           call 0x7a82ee
// 00892bb8  8d8f08010000         lea ecx, [edi + 0x108]
// 00892bbe  51                   push ecx
// 00892bbf  6a66                 push 0x66
// 00892bc1  56                   push esi
// 00892bc2  e82757f1ff           call 0x7a82ee
// 00892bc7  8d9780010000         lea edx, [edi + 0x180]
// 00892bcd  52                   push edx
// 00892bce  6a69                 push 0x69
// 00892bd0  56                   push esi
// 00892bd1  e81857f1ff           call 0x7a82ee
// 00892bd6  8d87d4010000         lea eax, [edi + 0x1d4]
// 00892bdc  50                   push eax
// 00892bdd  6a6b                 push 0x6b
// 00892bdf  56                   push esi
// 00892be0  e80957f1ff           call 0x7a82ee
// 00892be5  8d8f28020000         lea ecx, [edi + 0x228]
// 00892beb  51                   push ecx
// 00892bec  6a6a                 push 0x6a
// 00892bee  56                   push esi
// 00892bef  e8fa56f1ff           call 0x7a82ee
// 00892bf4  8d977c020000         lea edx, [edi + 0x27c]
// 00892bfa  52                   push edx
// 00892bfb  6a68                 push 0x68
// 00892bfd  56                   push esi
// 00892bfe  e8eb56f1ff           call 0x7a82ee
// 00892c03  8d87d0020000         lea eax, [edi + 0x2d0]
// 00892c09  50                   push eax
// 00892c0a  6a6c                 push 0x6c
// 00892c0c  56                   push esi
// 00892c0d  e8dc56f1ff           call 0x7a82ee
// 00892c12  8d8f24030000         lea ecx, [edi + 0x324]
// 00892c18  51                   push ecx
// 00892c19  6a6d                 push 0x6d
// 00892c1b  56                   push esi
// 00892c1c  e8cd56f1ff           call 0x7a82ee
// 00892c21  8d9778030000         lea edx, [edi + 0x378]
// 00892c27  52                   push edx
// 00892c28  6a74                 push 0x74
// 00892c2a  56                   push esi
// 00892c2b  e8be56f1ff           call 0x7a82ee
// 00892c30  8d87cc030000         lea eax, [edi + 0x3cc]
// 00892c36  50                   push eax
// 00892c37  6a77                 push 0x77
// 00892c39  56                   push esi
// 00892c3a  e8af56f1ff           call 0x7a82ee
// 00892c3f  8d8f20040000         lea ecx, [edi + 0x420]
// 00892c45  51                   push ecx
// 00892c46  6a75                 push 0x75
// 00892c48  56                   push esi
// 00892c49  e8a056f1ff           call 0x7a82ee
// 00892c4e  8d9774040000         lea edx, [edi + 0x474]
// 00892c54  52                   push edx
// 00892c55  6a70                 push 0x70
// 00892c57  56                   push esi
// 00892c58  e89156f1ff           call 0x7a82ee
// 00892c5d  8d87c8040000         lea eax, [edi + 0x4c8]
// 00892c63  50                   push eax
// 00892c64  6a78                 push 0x78
// 00892c66  56                   push esi
// 00892c67  e88256f1ff           call 0x7a82ee
// 00892c6c  8d8f1c050000         lea ecx, [edi + 0x51c]
// 00892c72  51                   push ecx
// 00892c73  6a79                 push 0x79
// 00892c75  56                   push esi
// 00892c76  e87356f1ff           call 0x7a82ee
// 00892c7b  8d9770050000         lea edx, [edi + 0x570]
// 00892c81  52                   push edx
// 00892c82  6a73                 push 0x73
// 00892c84  56                   push esi
// 00892c85  e86456f1ff           call 0x7a82ee
// 00892c8a  8d87c4050000         lea eax, [edi + 0x5c4]
// 00892c90  50                   push eax
// 00892c91  6a6f                 push 0x6f
// 00892c93  56                   push esi
// 00892c94  e85556f1ff           call 0x7a82ee
// 00892c99  8d8f18060000         lea ecx, [edi + 0x618]
// 00892c9f  51                   push ecx
// 00892ca0  6a76                 push 0x76
// 00892ca2  56                   push esi
// 00892ca3  e84656f1ff           call 0x7a82ee
// 00892ca8  8d976c060000         lea edx, [edi + 0x66c]
// 00892cae  52                   push edx
// 00892caf  6a71                 push 0x71
// 00892cb1  56                   push esi
// 00892cb2  e83756f1ff           call 0x7a82ee
// 00892cb7  8d87c0060000         lea eax, [edi + 0x6c0]
// 00892cbd  50                   push eax
// 00892cbe  6a6e                 push 0x6e
// 00892cc0  56                   push esi
// 00892cc1  e82856f1ff           call 0x7a82ee
// 00892cc6  8d8f14070000         lea ecx, [edi + 0x714]
// 00892ccc  51                   push ecx
// 00892ccd  6a72                 push 0x72
// 00892ccf  56                   push esi
// 00892cd0  e81956f1ff           call 0x7a82ee
// 00892cd5  8d9f68070000         lea ebx, [edi + 0x768]
// 00892cdb  53                   push ebx
// 00892cdc  6a6e                 push 0x6e
// 00892cde  56                   push esi
// 00892cdf  e81eaa0e00           call 0x97d702
// 00892ce4  8b13                 mov edx, dword ptr [ebx]
// 00892ce6  68ff000000           push 0xff
// 00892ceb  6a00                 push 0
// 00892ced  52                   push edx
// 00892cee  56                   push esi
// 00892cef  e808aa0e00           call 0x97d6fc
// 00892cf4  8d9f6c070000         lea ebx, [edi + 0x76c]
// 00892cfa  53                   push ebx
// 00892cfb  6a76                 push 0x76
// 00892cfd  56                   push esi
// 00892cfe  e8ffa90e00           call 0x97d702
// 00892d03  8b03                 mov eax, dword ptr [ebx]
// 00892d05  68ff000000           push 0xff
// 00892d0a  6a00                 push 0
// 00892d0c  50                   push eax
// 00892d0d  56                   push esi
// 00892d0e  e8e9a90e00           call 0x97d6fc
// 00892d13  8d9f70070000         lea ebx, [edi + 0x770]
// 00892d19  53                   push ebx
// 00892d1a  6a6f                 push 0x6f
// 00892d1c  56                   push esi
// 00892d1d  e8e0a90e00           call 0x97d702
// 00892d22  8b0b                 mov ecx, dword ptr [ebx]
// 00892d24  68ff000000           push 0xff
// 00892d29  6a00                 push 0
// 00892d2b  51                   push ecx
// 00892d2c  56                   push esi
// 00892d2d  e8caa90e00           call 0x97d6fc
// 00892d32  8d9f74070000         lea ebx, [edi + 0x774]
// 00892d38  53                   push ebx
// 00892d39  6a73                 push 0x73
// 00892d3b  56                   push esi
// 00892d3c  e8c1a90e00           call 0x97d702
// 00892d41  8b13                 mov edx, dword ptr [ebx]
// 00892d43  68ff000000           push 0xff
// 00892d48  6a00                 push 0
// 00892d4a  52                   push edx
// 00892d4b  56                   push esi
// 00892d4c  e8aba90e00           call 0x97d6fc
// 00892d51  8d9f78070000         lea ebx, [edi + 0x778]
// 00892d57  53                   push ebx
// 00892d58  6a71                 push 0x71
// 00892d5a  56                   push esi
// 00892d5b  e8a2a90e00           call 0x97d702
// 00892d60  8b03                 mov eax, dword ptr [ebx]
// 00892d62  68ff000000           push 0xff
// 00892d67  6a00                 push 0
// 00892d69  50                   push eax
// 00892d6a  56                   push esi
// 00892d6b  e88ca90e00           call 0x97d6fc
// 00892d70  81c77c070000         add edi, 0x77c
// 00892d76  57                   push edi
// 00892d77  6a72                 push 0x72
// 00892d79  56                   push esi
// 00892d7a  e883a90e00           call 0x97d702
// 00892d7f  8b0f                 mov ecx, dword ptr [edi]
// 00892d81  68ff000000           push 0xff
// 00892d86  6a00                 push 0
// 00892d88  51                   push ecx
// 00892d89  56                   push esi
// 00892d8a  e86da90e00           call 0x97d6fc
// 00892d8f  5f                   pop edi
// 00892d90  5e                   pop esi
// 00892d91  5b                   pop ebx
// 00892d92  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?DoDataExchange@CXTColorPageCustom@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
