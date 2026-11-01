// from server: 100% by auto
// roc 2007-03 00656e20  unit: seg_00650000  size: 272 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00656e20
//
// 00656e20  837c240800           cmp dword ptr [esp + 8], 0
// 00656e25  53                   push ebx
// 00656e26  55                   push ebp
// 00656e27  56                   push esi
// 00656e28  57                   push edi
// 00656e29  8bf1                 mov esi, ecx
// 00656e2b  0f84f8000000         je 0x656f29
// 00656e31  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00656e35  6a00                 push 0
// 00656e37  56                   push esi
// 00656e38  68047e7c00           push 0x7c7e04
// 00656e3d  57                   push edi
// 00656e3e  e8fdfe0000           call 0x666d40
// 00656e43  6a01                 push 1
// 00656e45  8d4604               lea eax, [esi + 4]
// 00656e48  50                   push eax
// 00656e49  68ac707900           push 0x7970ac
// 00656e4e  57                   push edi
// 00656e4f  e82cff0000           call 0x666d80
// 00656e54  6a00                 push 0
// 00656e56  8d4e08               lea ecx, [esi + 8]
// 00656e59  51                   push ecx
// 00656e5a  68f87d7c00           push 0x7c7df8
// 00656e5f  57                   push edi
// 00656e60  e81bff0000           call 0x666d80
// 00656e65  8d5614               lea edx, [esi + 0x14]
// 00656e68  52                   push edx
// 00656e69  68ec7d7c00           push 0x7c7dec
// 00656e6e  57                   push edi
// 00656e6f  e8acfe0000           call 0x666d20
// 00656e74  6a00                 push 0
// 00656e76  8d4618               lea eax, [esi + 0x18]
// 00656e79  50                   push eax
// 00656e7a  68dc7d7c00           push 0x7c7ddc
// 00656e7f  57                   push edi
// 00656e80  e8bbfe0000           call 0x666d40
// 00656e85  83c44c               add esp, 0x4c
// 00656e88  33c9                 xor ecx, ecx
// 00656e8a  51                   push ecx
// 00656e8b  33c0                 xor eax, eax
// 00656e8d  50                   push eax
// 00656e8e  8d4e0c               lea ecx, [esi + 0xc]
// 00656e91  51                   push ecx
// 00656e92  68d07d7c00           push 0x7c7dd0
// 00656e97  57                   push edi
// 00656e98  e883ff0000           call 0x666e20
// 00656e9d  83c404               add esp, 4
// 00656ea0  8bc4                 mov eax, esp
// 00656ea2  33c9                 xor ecx, ecx
// 00656ea4  33d2                 xor edx, edx
// 00656ea6  8908                 mov dword ptr [eax], ecx
// 00656ea8  895004               mov dword ptr [eax + 4], edx
// 00656eab  8d561c               lea edx, [esi + 0x1c]
// 00656eae  52                   push edx
// 00656eaf  33db                 xor ebx, ebx
// 00656eb1  68c47d7c00           push 0x7c7dc4
// 00656eb6  33ed                 xor ebp, ebp
// 00656eb8  895808               mov dword ptr [eax + 8], ebx
// 00656ebb  57                   push edi
// 00656ebc  89680c               mov dword ptr [eax + 0xc], ebp
// 00656ebf  e87cff0000           call 0x666e40
// 00656ec4  33c9                 xor ecx, ecx
// 00656ec6  51                   push ecx
// 00656ec7  33c0                 xor eax, eax
// 00656ec9  50                   push eax
// 00656eca  8d4630               lea eax, [esi + 0x30]
// 00656ecd  50                   push eax
// 00656ece  68b87d7c00           push 0x7c7db8
// 00656ed3  57                   push edi
// 00656ed4  e847ff0000           call 0x666e20
// 00656ed9  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 00656edd  83c430               add esp, 0x30
// 00656ee0  833906               cmp dword ptr [ecx], 6
// 00656ee3  7644                 jbe 0x656f29
// 00656ee5  55                   push ebp
// 00656ee6  8d5e3c               lea ebx, [esi + 0x3c]
// 00656ee9  53                   push ebx
// 00656eea  68ac7d7c00           push 0x7c7dac
// 00656eef  57                   push edi
// 00656ef0  e88bfe0000           call 0x666d80
// 00656ef5  83c410               add esp, 0x10
// 00656ef8  392b                 cmp dword ptr [ebx], ebp
// 00656efa  742d                 je 0x656f29
// 00656efc  33c9                 xor ecx, ecx
// 00656efe  51                   push ecx
// 00656eff  33c0                 xor eax, eax
// 00656f01  50                   push eax
// 00656f02  8d5640               lea edx, [esi + 0x40]
// 00656f05  52                   push edx
// 00656f06  68907d7c00           push 0x7c7d90
// 00656f0b  57                   push edi
// 00656f0c  e80fff0000           call 0x666e20
// 00656f11  33c9                 xor ecx, ecx
// 00656f13  51                   push ecx
// 00656f14  33c0                 xor eax, eax
// 00656f16  50                   push eax
// 00656f17  83c648               add esi, 0x48
// 00656f1a  56                   push esi
// 00656f1b  68747d7c00           push 0x7c7d74
// 00656f20  57                   push edi
// 00656f21  e8fafe0000           call 0x666e20
// 00656f26  83c428               add esp, 0x28
// 00656f29  5f                   pop edi
// 00656f2a  5e                   pop esi
// 00656f2b  5d                   pop ebp
// 00656f2c  5b                   pop ebx
// 00656f2d  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPDockState.cpp (function ?DoPropExchange@CToolBarInfo@CXTPToolBar@@QAEXPAVCXTPPropExchange@@PAVCXTPDockState@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockState.cpp
