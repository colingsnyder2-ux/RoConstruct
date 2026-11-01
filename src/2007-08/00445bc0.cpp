// from server: 100% by auto
// roc 2007-08 00445bc0  unit: VCRenderSettings::?$FactoryProduct  size: 372 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00445bc0
//
// 00445bc0  55                   push ebp
// 00445bc1  8bec                 mov ebp, esp
// 00445bc3  6aff                 push -1
// 00445bc5  6830f67300           push 0x73f630
// 00445bca  64a100000000         mov eax, dword ptr fs:[0]
// 00445bd0  50                   push eax
// 00445bd1  83ec0c               sub esp, 0xc
// 00445bd4  53                   push ebx
// 00445bd5  56                   push esi
// 00445bd6  57                   push edi
// 00445bd7  a188518b00           mov eax, dword ptr [0x8b5188]
// 00445bdc  33c5                 xor eax, ebp
// 00445bde  50                   push eax
// 00445bdf  8d45f4               lea eax, [ebp - 0xc]
// 00445be2  64a300000000         mov dword ptr fs:[0], eax
// 00445be8  8965f0               mov dword ptr [ebp - 0x10], esp
// 00445beb  8bf1                 mov esi, ecx
// 00445bed  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00445bf0  8b08                 mov ecx, dword ptr [eax]
// 00445bf2  894d14               mov dword ptr [ebp + 0x14], ecx
// 00445bf5  8b4e04               mov ecx, dword ptr [esi + 4]
// 00445bf8  85c9                 test ecx, ecx
// 00445bfa  7504                 jne 0x445c00
// 00445bfc  33ff                 xor edi, edi
// 00445bfe  eb08                 jmp 0x445c08
// 00445c00  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00445c03  2bf9                 sub edi, ecx
// 00445c05  c1ff02               sar edi, 2
// 00445c08  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00445c0b  85d2                 test edx, edx
// 00445c0d  0f84e9010000         je 0x445dfc
// 00445c13  85c9                 test ecx, ecx
// 00445c15  7504                 jne 0x445c1b
// 00445c17  33c0                 xor eax, eax
// 00445c19  eb08                 jmp 0x445c23
// 00445c1b  8b4608               mov eax, dword ptr [esi + 8]
// 00445c1e  2bc1                 sub eax, ecx
// 00445c20  c1f802               sar eax, 2
// 00445c23  bbffffff3f           mov ebx, 0x3fffffff
// 00445c28  2bd8                 sub ebx, eax
// 00445c2a  3bda                 cmp ebx, edx
// 00445c2c  7305                 jae 0x445c33
// 00445c2e  e8cd1bfdff           call 0x417800
// 00445c33  85c9                 test ecx, ecx
// 00445c35  7504                 jne 0x445c3b
// 00445c37  33c0                 xor eax, eax
// 00445c39  eb08                 jmp 0x445c43
// 00445c3b  8b4608               mov eax, dword ptr [esi + 8]
// 00445c3e  2bc1                 sub eax, ecx
// 00445c40  c1f802               sar eax, 2
// 00445c43  03c2                 add eax, edx
// 00445c45  3bf8                 cmp edi, eax
// 00445c47  0f83fc000000         jae 0x445d49
// 00445c4d  8bc7                 mov eax, edi
// 00445c4f  d1e8                 shr eax, 1
// 00445c51  bbffffff3f           mov ebx, 0x3fffffff
// 00445c56  2bd8                 sub ebx, eax
// 00445c58  3bdf                 cmp ebx, edi
// 00445c5a  7304                 jae 0x445c60
// 00445c5c  33ff                 xor edi, edi
// 00445c5e  eb02                 jmp 0x445c62
// 00445c60  03f8                 add edi, eax
// 00445c62  85c9                 test ecx, ecx
// 00445c64  7504                 jne 0x445c6a
// 00445c66  33c0                 xor eax, eax
// 00445c68  eb08                 jmp 0x445c72
// 00445c6a  8b4608               mov eax, dword ptr [esi + 8]
// 00445c6d  2bc1                 sub eax, ecx
// 00445c6f  c1f802               sar eax, 2
// 00445c72  03c2                 add eax, edx
// 00445c74  3bf8                 cmp edi, eax
// 00445c76  7313                 jae 0x445c8b
// 00445c78  85c9                 test ecx, ecx
// 00445c7a  7504                 jne 0x445c80
// 00445c7c  33c0                 xor eax, eax
// 00445c7e  eb08                 jmp 0x445c88
// 00445c80  8b4608               mov eax, dword ptr [esi + 8]
// 00445c83  2bc1                 sub eax, ecx
// 00445c85  c1f802               sar eax, 2
// 00445c88  8d3c10               lea edi, [eax + edx]
// 00445c8b  6a00                 push 0
// 00445c8d  57                   push edi
// 00445c8e  e8cda01600           call 0x5afd60
// 00445c93  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00445c96  c645ec00             mov byte ptr [ebp - 0x14], 0
// 00445c9a  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00445c9d  52                   push edx
// 00445c9e  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00445ca1  51                   push ecx
// 00445ca2  8bd8                 mov ebx, eax
// 00445ca4  8b4604               mov eax, dword ptr [esi + 4]
// 00445ca7  56                   push esi
// 00445ca8  53                   push ebx
// 00445ca9  52                   push edx
// 00445caa  50                   push eax
// 00445cab  895de8               mov dword ptr [ebp - 0x18], ebx
// 00445cae  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00445cb5  e8c6ea1200           call 0x574780
// 00445cba  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00445cbd  83c420               add esp, 0x20
// 00445cc0  8d4d14               lea ecx, [ebp + 0x14]
// 00445cc3  51                   push ecx
// 00445cc4  52                   push edx
// 00445cc5  50                   push eax
// 00445cc6  8bce                 mov ecx, esi
// 00445cc8  e893791500           call 0x59d660
// 00445ccd  8b4e08               mov ecx, dword ptr [esi + 8]
// 00445cd0  c6451400             mov byte ptr [ebp + 0x14], 0
// 00445cd4  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00445cd7  52                   push edx
// 00445cd8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00445cdb  52                   push edx
// 00445cdc  56                   push esi
// 00445cdd  50                   push eax
// 00445cde  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00445ce1  51                   push ecx
// 00445ce2  50                   push eax
// 00445ce3  e898ea1200           call 0x574780
// 00445ce8  8b4e04               mov ecx, dword ptr [esi + 4]
// 00445ceb  83c418               add esp, 0x18
// 00445cee  85c9                 test ecx, ecx
// 00445cf0  7504                 jne 0x445cf6
// 00445cf2  33c0                 xor eax, eax
// 00445cf4  eb08                 jmp 0x445cfe
// 00445cf6  8b4608               mov eax, dword ptr [esi + 8]
// 00445cf9  2bc1                 sub eax, ecx
// 00445cfb  c1f802               sar eax, 2
// 00445cfe  014510               add dword ptr [ebp + 0x10], eax
// 00445d01  85c9                 test ecx, ecx
// 00445d03  7409                 je 0x445d0e
// 00445d05  51                   push ecx
// 00445d06  e8579f1e00           call 0x62fc62
// 00445d0b  83c404               add esp, 4
// 00445d0e  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00445d11  8d0cbb               lea ecx, [ebx + edi*4]
// 00445d14  8d0493               lea eax, [ebx + edx*4]
// 00445d17  894e0c               mov dword ptr [esi + 0xc], ecx
// 00445d1a  894608               mov dword ptr [esi + 8], eax
// 00445d1d  895e04               mov dword ptr [esi + 4], ebx
// 00445d20  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00445d23  64890d00000000       mov dword ptr fs:[0], ecx
// 00445d2a  59                   pop ecx
// 00445d2b  5f                   pop edi
// 00445d2c  5e                   pop esi
// 00445d2d  5b                   pop ebx
// 00445d2e  8be5                 mov esp, ebp
// 00445d30  5d                   pop ebp
// 00445d31  c21000               ret 0x10
// library ogre-1.7.0/OgreScriptTranslator.cpp (function ?_Insert_n@?$vector@W4PixelFormat@Ogre@@V?$allocator@W4PixelFormat@Ogre@@@std@@@std@@IAEXV?$_Vector_iterator@W4PixelFormat@Ogre@@V?$allocator@W4PixelFormat@Ogre@@@std@@@2@IABW4PixelFormat@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptTranslator.cpp
