// from server: 100% by auto
// roc 2009-12 00877c90  unit: CXTPControlGalleryPaintManager  size: 361 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00877c90
//
// 00877c90  53                   push ebx
// 00877c91  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00877c95  56                   push esi
// 00877c96  57                   push edi
// 00877c97  33ff                 xor edi, edi
// 00877c99  3bdf                 cmp ebx, edi
// 00877c9b  8bf1                 mov esi, ecx
// 00877c9d  7d05                 jge 0x877ca4
// 00877c9f  e868bef7ff           call 0x7f3b0c
// 00877ca4  8b442414             mov eax, dword ptr [esp + 0x14]
// 00877ca8  3bc7                 cmp eax, edi
// 00877caa  7c03                 jl 0x877caf
// 00877cac  894610               mov dword ptr [esi + 0x10], eax
// 00877caf  3bdf                 cmp ebx, edi
// 00877cb1  751f                 jne 0x877cd2
// 00877cb3  8b4604               mov eax, dword ptr [esi + 4]
// 00877cb6  3bc7                 cmp eax, edi
// 00877cb8  740c                 je 0x877cc6
// 00877cba  50                   push eax
// 00877cbb  e846bef7ff           call 0x7f3b06
// 00877cc0  83c404               add esp, 4
// 00877cc3  897e04               mov dword ptr [esi + 4], edi
// 00877cc6  897e0c               mov dword ptr [esi + 0xc], edi
// 00877cc9  897e08               mov dword ptr [esi + 8], edi
// 00877ccc  5f                   pop edi
// 00877ccd  5e                   pop esi
// 00877cce  5b                   pop ebx
// 00877ccf  c20800               ret 8
// 00877cd2  8b5604               mov edx, dword ptr [esi + 4]
// 00877cd5  55                   push ebp
// 00877cd6  3bd7                 cmp edx, edi
// 00877cd8  7535                 jne 0x877d0f
// 00877cda  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 00877cdd  3bdd                 cmp ebx, ebp
// 00877cdf  7e02                 jle 0x877ce3
// 00877ce1  8beb                 mov ebp, ebx
// 00877ce3  8d7c6d00             lea edi, [ebp + ebp*2]
// 00877ce7  03ff                 add edi, edi
// 00877ce9  03ff                 add edi, edi
// 00877ceb  03ff                 add edi, edi
// 00877ced  57                   push edi
// 00877cee  e84fbef7ff           call 0x7f3b42
// 00877cf3  57                   push edi
// 00877cf4  6a00                 push 0
// 00877cf6  50                   push eax
// 00877cf7  894604               mov dword ptr [esi + 4], eax
// 00877cfa  e8a5cdf7ff           call 0x7f4aa4
// 00877cff  83c410               add esp, 0x10
// 00877d02  896e0c               mov dword ptr [esi + 0xc], ebp
// 00877d05  5d                   pop ebp
// 00877d06  5f                   pop edi
// 00877d07  895e08               mov dword ptr [esi + 8], ebx
// 00877d0a  5e                   pop esi
// 00877d0b  5b                   pop ebx
// 00877d0c  c20800               ret 8
// 00877d0f  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00877d12  3bd9                 cmp ebx, ecx
// 00877d14  7f33                 jg 0x877d49
// 00877d16  8b4e08               mov ecx, dword ptr [esi + 8]
// 00877d19  3bd9                 cmp ebx, ecx
// 00877d1b  0f8ece000000         jle 0x877def
// 00877d21  8bc3                 mov eax, ebx
// 00877d23  2bc1                 sub eax, ecx
// 00877d25  8d0440               lea eax, [eax + eax*2]
// 00877d28  03c0                 add eax, eax
// 00877d2a  03c0                 add eax, eax
// 00877d2c  03c0                 add eax, eax
// 00877d2e  50                   push eax
// 00877d2f  8d0c49               lea ecx, [ecx + ecx*2]
// 00877d32  8d14ca               lea edx, [edx + ecx*8]
// 00877d35  57                   push edi
// 00877d36  52                   push edx
// 00877d37  e868cdf7ff           call 0x7f4aa4
// 00877d3c  83c40c               add esp, 0xc
// 00877d3f  5d                   pop ebp
// 00877d40  5f                   pop edi
// 00877d41  895e08               mov dword ptr [esi + 8], ebx
// 00877d44  5e                   pop esi
// 00877d45  5b                   pop ebx
// 00877d46  c20800               ret 8
// 00877d49  8b4610               mov eax, dword ptr [esi + 0x10]
// 00877d4c  3bc7                 cmp eax, edi
// 00877d4e  7524                 jne 0x877d74
// 00877d50  8b4608               mov eax, dword ptr [esi + 8]
// 00877d53  99                   cdq 
// 00877d54  83e207               and edx, 7
// 00877d57  03c2                 add eax, edx
// 00877d59  c1f803               sar eax, 3
// 00877d5c  83f804               cmp eax, 4
// 00877d5f  7d07                 jge 0x877d68
// 00877d61  b804000000           mov eax, 4
// 00877d66  eb0c                 jmp 0x877d74
// 00877d68  3d00040000           cmp eax, 0x400
// 00877d6d  7e05                 jle 0x877d74
// 00877d6f  b800040000           mov eax, 0x400
// 00877d74  8d3c01               lea edi, [ecx + eax]
// 00877d77  3bdf                 cmp ebx, edi
// 00877d79  7d06                 jge 0x877d81
// 00877d7b  897c2414             mov dword ptr [esp + 0x14], edi
// 00877d7f  eb06                 jmp 0x877d87
// 00877d81  895c2414             mov dword ptr [esp + 0x14], ebx
// 00877d85  8bfb                 mov edi, ebx
// 00877d87  3bf9                 cmp edi, ecx
// 00877d89  7d05                 jge 0x877d90
// 00877d8b  e87cbdf7ff           call 0x7f3b0c
// 00877d90  8d3c7f               lea edi, [edi + edi*2]
// 00877d93  03ff                 add edi, edi
// 00877d95  03ff                 add edi, edi
// 00877d97  03ff                 add edi, edi
// 00877d99  57                   push edi
// 00877d9a  e8a3bdf7ff           call 0x7f3b42
// 00877d9f  8b4e04               mov ecx, dword ptr [esi + 4]
// 00877da2  8be8                 mov ebp, eax
// 00877da4  8b4608               mov eax, dword ptr [esi + 8]
// 00877da7  8d0440               lea eax, [eax + eax*2]
// 00877daa  03c0                 add eax, eax
// 00877dac  03c0                 add eax, eax
// 00877dae  03c0                 add eax, eax
// 00877db0  50                   push eax
// 00877db1  51                   push ecx
// 00877db2  57                   push edi
// 00877db3  55                   push ebp
// 00877db4  e8e7adb8ff           call 0x402ba0
// 00877db9  8b4e08               mov ecx, dword ptr [esi + 8]
// 00877dbc  8bc3                 mov eax, ebx
// 00877dbe  2bc1                 sub eax, ecx
// 00877dc0  8d1440               lea edx, [eax + eax*2]
// 00877dc3  03d2                 add edx, edx
// 00877dc5  03d2                 add edx, edx
// 00877dc7  03d2                 add edx, edx
// 00877dc9  52                   push edx
// 00877dca  8d0449               lea eax, [ecx + ecx*2]
// 00877dcd  8d4cc500             lea ecx, [ebp + eax*8]
// 00877dd1  6a00                 push 0
// 00877dd3  51                   push ecx
// 00877dd4  e8cbccf7ff           call 0x7f4aa4
// 00877dd9  8b5604               mov edx, dword ptr [esi + 4]
// 00877ddc  52                   push edx
// 00877ddd  e824bdf7ff           call 0x7f3b06
// 00877de2  8b442438             mov eax, dword ptr [esp + 0x38]
// 00877de6  83c424               add esp, 0x24
// 00877de9  896e04               mov dword ptr [esi + 4], ebp
// 00877dec  89460c               mov dword ptr [esi + 0xc], eax
// 00877def  5d                   pop ebp
// 00877df0  5f                   pop edi
// 00877df1  895e08               mov dword ptr [esi + 8], ebx
// 00877df4  5e                   pop esi
// 00877df5  5b                   pop ebx
// 00877df6  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?SetSize@?$CArray@UGALLERYITEM_POSITION@CXTPControlGallery@@AAU12@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlGallery.cpp
