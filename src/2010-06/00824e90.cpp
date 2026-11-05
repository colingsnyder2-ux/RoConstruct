// from server: 100% by auto
// roc 2010-06 00824e90  unit: CXTPControlGalleryPaintManager  size: 361 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00824e90
//
// 00824e90  53                   push ebx
// 00824e91  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00824e95  56                   push esi
// 00824e96  57                   push edi
// 00824e97  33ff                 xor edi, edi
// 00824e99  3bdf                 cmp ebx, edi
// 00824e9b  8bf1                 mov esi, ecx
// 00824e9d  7d05                 jge 0x824ea4
// 00824e9f  e8a82df8ff           call 0x7a7c4c
// 00824ea4  8b442414             mov eax, dword ptr [esp + 0x14]
// 00824ea8  3bc7                 cmp eax, edi
// 00824eaa  7c03                 jl 0x824eaf
// 00824eac  894610               mov dword ptr [esi + 0x10], eax
// 00824eaf  3bdf                 cmp ebx, edi
// 00824eb1  751f                 jne 0x824ed2
// 00824eb3  8b4604               mov eax, dword ptr [esi + 4]
// 00824eb6  3bc7                 cmp eax, edi
// 00824eb8  740c                 je 0x824ec6
// 00824eba  50                   push eax
// 00824ebb  e8862df8ff           call 0x7a7c46
// 00824ec0  83c404               add esp, 4
// 00824ec3  897e04               mov dword ptr [esi + 4], edi
// 00824ec6  897e0c               mov dword ptr [esi + 0xc], edi
// 00824ec9  897e08               mov dword ptr [esi + 8], edi
// 00824ecc  5f                   pop edi
// 00824ecd  5e                   pop esi
// 00824ece  5b                   pop ebx
// 00824ecf  c20800               ret 8
// 00824ed2  8b5604               mov edx, dword ptr [esi + 4]
// 00824ed5  55                   push ebp
// 00824ed6  3bd7                 cmp edx, edi
// 00824ed8  7535                 jne 0x824f0f
// 00824eda  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 00824edd  3bdd                 cmp ebx, ebp
// 00824edf  7e02                 jle 0x824ee3
// 00824ee1  8beb                 mov ebp, ebx
// 00824ee3  8d7c6d00             lea edi, [ebp + ebp*2]
// 00824ee7  03ff                 add edi, edi
// 00824ee9  03ff                 add edi, edi
// 00824eeb  03ff                 add edi, edi
// 00824eed  57                   push edi
// 00824eee  e88f2df8ff           call 0x7a7c82
// 00824ef3  57                   push edi
// 00824ef4  6a00                 push 0
// 00824ef6  50                   push eax
// 00824ef7  894604               mov dword ptr [esi + 4], eax
// 00824efa  e8e53cf8ff           call 0x7a8be4
// 00824eff  83c410               add esp, 0x10
// 00824f02  896e0c               mov dword ptr [esi + 0xc], ebp
// 00824f05  5d                   pop ebp
// 00824f06  5f                   pop edi
// 00824f07  895e08               mov dword ptr [esi + 8], ebx
// 00824f0a  5e                   pop esi
// 00824f0b  5b                   pop ebx
// 00824f0c  c20800               ret 8
// 00824f0f  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00824f12  3bd9                 cmp ebx, ecx
// 00824f14  7f33                 jg 0x824f49
// 00824f16  8b4e08               mov ecx, dword ptr [esi + 8]
// 00824f19  3bd9                 cmp ebx, ecx
// 00824f1b  0f8ece000000         jle 0x824fef
// 00824f21  8bc3                 mov eax, ebx
// 00824f23  2bc1                 sub eax, ecx
// 00824f25  8d0440               lea eax, [eax + eax*2]
// 00824f28  03c0                 add eax, eax
// 00824f2a  03c0                 add eax, eax
// 00824f2c  03c0                 add eax, eax
// 00824f2e  50                   push eax
// 00824f2f  8d0c49               lea ecx, [ecx + ecx*2]
// 00824f32  8d14ca               lea edx, [edx + ecx*8]
// 00824f35  57                   push edi
// 00824f36  52                   push edx
// 00824f37  e8a83cf8ff           call 0x7a8be4
// 00824f3c  83c40c               add esp, 0xc
// 00824f3f  5d                   pop ebp
// 00824f40  5f                   pop edi
// 00824f41  895e08               mov dword ptr [esi + 8], ebx
// 00824f44  5e                   pop esi
// 00824f45  5b                   pop ebx
// 00824f46  c20800               ret 8
// 00824f49  8b4610               mov eax, dword ptr [esi + 0x10]
// 00824f4c  3bc7                 cmp eax, edi
// 00824f4e  7524                 jne 0x824f74
// 00824f50  8b4608               mov eax, dword ptr [esi + 8]
// 00824f53  99                   cdq 
// 00824f54  83e207               and edx, 7
// 00824f57  03c2                 add eax, edx
// 00824f59  c1f803               sar eax, 3
// 00824f5c  83f804               cmp eax, 4
// 00824f5f  7d07                 jge 0x824f68
// 00824f61  b804000000           mov eax, 4
// 00824f66  eb0c                 jmp 0x824f74
// 00824f68  3d00040000           cmp eax, 0x400
// 00824f6d  7e05                 jle 0x824f74
// 00824f6f  b800040000           mov eax, 0x400
// 00824f74  8d3c01               lea edi, [ecx + eax]
// 00824f77  3bdf                 cmp ebx, edi
// 00824f79  7d06                 jge 0x824f81
// 00824f7b  897c2414             mov dword ptr [esp + 0x14], edi
// 00824f7f  eb06                 jmp 0x824f87
// 00824f81  895c2414             mov dword ptr [esp + 0x14], ebx
// 00824f85  8bfb                 mov edi, ebx
// 00824f87  3bf9                 cmp edi, ecx
// 00824f89  7d05                 jge 0x824f90
// 00824f8b  e8bc2cf8ff           call 0x7a7c4c
// 00824f90  8d3c7f               lea edi, [edi + edi*2]
// 00824f93  03ff                 add edi, edi
// 00824f95  03ff                 add edi, edi
// 00824f97  03ff                 add edi, edi
// 00824f99  57                   push edi
// 00824f9a  e8e32cf8ff           call 0x7a7c82
// 00824f9f  8b4e04               mov ecx, dword ptr [esi + 4]
// 00824fa2  8be8                 mov ebp, eax
// 00824fa4  8b4608               mov eax, dword ptr [esi + 8]
// 00824fa7  8d0440               lea eax, [eax + eax*2]
// 00824faa  03c0                 add eax, eax
// 00824fac  03c0                 add eax, eax
// 00824fae  03c0                 add eax, eax
// 00824fb0  50                   push eax
// 00824fb1  51                   push ecx
// 00824fb2  57                   push edi
// 00824fb3  55                   push ebp
// 00824fb4  e837dcbdff           call 0x402bf0
// 00824fb9  8b4e08               mov ecx, dword ptr [esi + 8]
// 00824fbc  8bc3                 mov eax, ebx
// 00824fbe  2bc1                 sub eax, ecx
// 00824fc0  8d1440               lea edx, [eax + eax*2]
// 00824fc3  03d2                 add edx, edx
// 00824fc5  03d2                 add edx, edx
// 00824fc7  03d2                 add edx, edx
// 00824fc9  52                   push edx
// 00824fca  8d0449               lea eax, [ecx + ecx*2]
// 00824fcd  8d4cc500             lea ecx, [ebp + eax*8]
// 00824fd1  6a00                 push 0
// 00824fd3  51                   push ecx
// 00824fd4  e80b3cf8ff           call 0x7a8be4
// 00824fd9  8b5604               mov edx, dword ptr [esi + 4]
// 00824fdc  52                   push edx
// 00824fdd  e8642cf8ff           call 0x7a7c46
// 00824fe2  8b442438             mov eax, dword ptr [esp + 0x38]
// 00824fe6  83c424               add esp, 0x24
// 00824fe9  896e04               mov dword ptr [esi + 4], ebp
// 00824fec  89460c               mov dword ptr [esi + 0xc], eax
// 00824fef  5d                   pop ebp
// 00824ff0  5f                   pop edi
// 00824ff1  895e08               mov dword ptr [esi + 8], ebx
// 00824ff4  5e                   pop esi
// 00824ff5  5b                   pop ebx
// 00824ff6  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?SetSize@?$CArray@UGALLERYITEM_POSITION@CXTPControlGallery@@AAU12@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlGallery.cpp
