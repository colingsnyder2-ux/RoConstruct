// from server: 100% by auto
// roc 2010-06 008d6fb0  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 343 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d6fb0
//
// 008d6fb0  56                   push esi
// 008d6fb1  57                   push edi
// 008d6fb2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008d6fb6  8bf1                 mov esi, ecx
// 008d6fb8  3bf7                 cmp esi, edi
// 008d6fba  0f8440010000         je 0x8d7100
// 008d6fc0  8b470c               mov eax, dword ptr [edi + 0xc]
// 008d6fc3  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 008d6fc6  2bc8                 sub ecx, eax
// 008d6fc8  b8310cc330           mov eax, 0x30c30c31
// 008d6fcd  f7e9                 imul ecx
// 008d6fcf  55                   push ebp
// 008d6fd0  c1fa04               sar edx, 4
// 008d6fd3  8bea                 mov ebp, edx
// 008d6fd5  c1ed1f               shr ebp, 0x1f
// 008d6fd8  03ea                 add ebp, edx
// 008d6fda  750f                 jne 0x8d6feb
// 008d6fdc  8bce                 mov ecx, esi
// 008d6fde  e83dfcffff           call 0x8d6c20
// 008d6fe3  5d                   pop ebp
// 008d6fe4  5f                   pop edi
// 008d6fe5  8bc6                 mov eax, esi
// 008d6fe7  5e                   pop esi
// 008d6fe8  c20400               ret 4
// 008d6feb  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 008d6fee  53                   push ebx
// 008d6fef  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008d6ff2  2bcb                 sub ecx, ebx
// 008d6ff4  b8310cc330           mov eax, 0x30c30c31
// 008d6ff9  f7e9                 imul ecx
// 008d6ffb  c1fa04               sar edx, 4
// 008d6ffe  8bca                 mov ecx, edx
// 008d7000  c1e91f               shr ecx, 0x1f
// 008d7003  03ca                 add ecx, edx
// 008d7005  3be9                 cmp ebp, ecx
// 008d7007  774d                 ja 0x8d7056
// 008d7009  8b4710               mov eax, dword ptr [edi + 0x10]
// 008d700c  53                   push ebx
// 008d700d  50                   push eax
// 008d700e  8b470c               mov eax, dword ptr [edi + 0xc]
// 008d7011  50                   push eax
// 008d7012  e839f3ffff           call 0x8d6350
// 008d7017  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008d701b  51                   push ecx
// 008d701c  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 008d701f  8d5608               lea edx, [esi + 8]
// 008d7022  52                   push edx
// 008d7023  51                   push ecx
// 008d7024  50                   push eax
// 008d7025  e8c6f2ffff           call 0x8d62f0
// 008d702a  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 008d702d  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 008d7030  b8310cc330           mov eax, 0x30c30c31
// 008d7035  f7e9                 imul ecx
// 008d7037  c1fa04               sar edx, 4
// 008d703a  8bc2                 mov eax, edx
// 008d703c  c1e81f               shr eax, 0x1f
// 008d703f  03c2                 add eax, edx
// 008d7041  6bc054               imul eax, eax, 0x54
// 008d7044  83c41c               add esp, 0x1c
// 008d7047  03460c               add eax, dword ptr [esi + 0xc]
// 008d704a  5b                   pop ebx
// 008d704b  5d                   pop ebp
// 008d704c  894610               mov dword ptr [esi + 0x10], eax
// 008d704f  5f                   pop edi
// 008d7050  8bc6                 mov eax, esi
// 008d7052  5e                   pop esi
// 008d7053  c20400               ret 4
// 008d7056  85db                 test ebx, ebx
// 008d7058  7504                 jne 0x8d705e
// 008d705a  33c0                 xor eax, eax
// 008d705c  eb16                 jmp 0x8d7074
// 008d705e  8b5614               mov edx, dword ptr [esi + 0x14]
// 008d7061  2bd3                 sub edx, ebx
// 008d7063  b8310cc330           mov eax, 0x30c30c31
// 008d7068  f7ea                 imul edx
// 008d706a  c1fa04               sar edx, 4
// 008d706d  8bc2                 mov eax, edx
// 008d706f  c1e81f               shr eax, 0x1f
// 008d7072  03c2                 add eax, edx
// 008d7074  3be8                 cmp ebp, eax
// 008d7076  7731                 ja 0x8d70a9
// 008d7078  8b470c               mov eax, dword ptr [edi + 0xc]
// 008d707b  6bc954               imul ecx, ecx, 0x54
// 008d707e  03c8                 add ecx, eax
// 008d7080  8be9                 mov ebp, ecx
// 008d7082  53                   push ebx
// 008d7083  55                   push ebp
// 008d7084  50                   push eax
// 008d7085  e8c6f2ffff           call 0x8d6350
// 008d708a  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 008d708d  8b5710               mov edx, dword ptr [edi + 0x10]
// 008d7090  83c40c               add esp, 0xc
// 008d7093  51                   push ecx
// 008d7094  52                   push edx
// 008d7095  55                   push ebp
// 008d7096  8bce                 mov ecx, esi
// 008d7098  e843630000           call 0x8dd3e0
// 008d709d  5b                   pop ebx
// 008d709e  5d                   pop ebp
// 008d709f  894610               mov dword ptr [esi + 0x10], eax
// 008d70a2  5f                   pop edi
// 008d70a3  8bc6                 mov eax, esi
// 008d70a5  5e                   pop esi
// 008d70a6  c20400               ret 4
// 008d70a9  85db                 test ebx, ebx
// 008d70ab  7418                 je 0x8d70c5
// 008d70ad  8b4610               mov eax, dword ptr [esi + 0x10]
// 008d70b0  50                   push eax
// 008d70b1  53                   push ebx
// 008d70b2  8bce                 mov ecx, esi
// 008d70b4  e817f6ffff           call 0x8d66d0
// 008d70b9  8b460c               mov eax, dword ptr [esi + 0xc]
// 008d70bc  50                   push eax
// 008d70bd  e8d808edff           call 0x7a799a
// 008d70c2  83c404               add esp, 4
// 008d70c5  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 008d70c8  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 008d70cb  b8310cc330           mov eax, 0x30c30c31
// 008d70d0  f7e9                 imul ecx
// 008d70d2  c1fa04               sar edx, 4
// 008d70d5  8bc2                 mov eax, edx
// 008d70d7  c1e81f               shr eax, 0x1f
// 008d70da  03c2                 add eax, edx
// 008d70dc  50                   push eax
// 008d70dd  8bce                 mov ecx, esi
// 008d70df  e80cebffff           call 0x8d5bf0
// 008d70e4  84c0                 test al, al
// 008d70e6  7416                 je 0x8d70fe
// 008d70e8  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 008d70eb  8b5710               mov edx, dword ptr [edi + 0x10]
// 008d70ee  8b470c               mov eax, dword ptr [edi + 0xc]
// 008d70f1  51                   push ecx
// 008d70f2  52                   push edx
// 008d70f3  50                   push eax
// 008d70f4  8bce                 mov ecx, esi
// 008d70f6  e8e5620000           call 0x8dd3e0
// 008d70fb  894610               mov dword ptr [esi + 0x10], eax
// 008d70fe  5b                   pop ebx
// 008d70ff  5d                   pop ebp
// 008d7100  5f                   pop edi
// 008d7101  8bc6                 mov eax, esi
// 008d7103  5e                   pop esi
// 008d7104  c20400               ret 4
// library boost-1.40.0/libs\program_options\src\cmdline.cpp (function ??4?$vector@V?$basic_option@D@program_options@boost@@V?$allocator@V?$basic_option@D@program_options@boost@@@std@@@std@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/program_options/src/cmdline.cpp
