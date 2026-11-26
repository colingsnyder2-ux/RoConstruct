// from server: 100% by Xemicl
// roc 2012-06 0049ec30  unit: Scintilla::CScintillaView  size: 399 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0049ec30
//
// 0049ec30  6aff                 push -1
// 0049ec32  68923aaa00           push 0xaa3a92
// 0049ec37  64a100000000         mov eax, dword ptr fs:[0]
// 0049ec3d  50                   push eax
// 0049ec3e  64892500000000       mov dword ptr fs:[0], esp
// 0049ec45  83ec20               sub esp, 0x20
// 0049ec48  53                   push ebx
// 0049ec49  55                   push ebp
// 0049ec4a  56                   push esi
// 0049ec4b  57                   push edi
// 0049ec4c  8d4c2414             lea ecx, [esp + 0x14]
// 0049ec50  ff158447b200         call dword ptr [0xb24784]
// 0049ec56  8b442444             mov eax, dword ptr [esp + 0x44]
// 0049ec5a  8b4814               mov ecx, dword ptr [eax + 0x14]
// 0049ec5d  51                   push ecx
// 0049ec5e  8d542418             lea edx, [esp + 0x18]
// 0049ec62  689c0db500           push 0xb50d9c
// 0049ec67  52                   push edx
// 0049ec68  c744244400000000     mov dword ptr [esp + 0x44], 0
// 0049ec70  ff158847b200         call dword ptr [0xb24788]
// 0049ec76  83c40c               add esp, 0xc
// 0049ec79  8d4c2410             lea ecx, [esp + 0x10]
// 0049ec7d  ff158447b200         call dword ptr [0xb24784]
// 0049ec83  8d4c2414             lea ecx, [esp + 0x14]
// 0049ec87  c644243801           mov byte ptr [esp + 0x38], 1
// 0049ec8c  ff159847b200         call dword ptr [0xb24798]
// 0049ec92  50                   push eax
// 0049ec93  68c6000000           push 0xc6
// 0049ec98  8d442418             lea eax, [esp + 0x18]
// 0049ec9c  50                   push eax
// 0049ec9d  e86c434e00           call 0x98300e
// 0049eca2  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 0049eca6  8b17                 mov edx, dword ptr [edi]
// 0049eca8  8b4238               mov eax, dword ptr [edx + 0x38]
// 0049ecab  6a00                 push 0
// 0049ecad  8bcf                 mov ecx, edi
// 0049ecaf  ffd0                 call eax
// 0049ecb1  6a00                 push 0
// 0049ecb3  8bcf                 mov ecx, edi
// 0049ecb5  e84e434e00           call 0x983008
// 0049ecba  8d4c2418             lea ecx, [esp + 0x18]
// 0049ecbe  51                   push ecx
// 0049ecbf  8d4c2414             lea ecx, [esp + 0x14]
// 0049ecc3  89442444             mov dword ptr [esp + 0x44], eax
// 0049ecc7  ff155846b200         call dword ptr [0xb24658]
// 0049eccd  50                   push eax
// 0049ecce  8d4c2418             lea ecx, [esp + 0x18]
// 0049ecd2  ff159847b200         call dword ptr [0xb24798]
// 0049ecd8  8b5708               mov edx, dword ptr [edi + 8]
// 0049ecdb  50                   push eax
// 0049ecdc  52                   push edx
// 0049ecdd  ff154021b200         call dword ptr [0xb22140]
// 0049ece3  8b742448             mov esi, dword ptr [esp + 0x48]
// 0049ece7  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0049ecea  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0049ecee  8b5620               mov edx, dword ptr [esi + 0x20]
// 0049ecf1  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 0049ecf4  8bc1                 mov eax, ecx
// 0049ecf6  03db                 add ebx, ebx
// 0049ecf8  2bc3                 sub eax, ebx
// 0049ecfa  89442424             mov dword ptr [esp + 0x24], eax
// 0049ecfe  89542428             mov dword ptr [esp + 0x28], edx
// 0049ed02  8d141b               lea edx, [ebx + ebx]
// 0049ed05  b856555555           mov eax, 0x55555556
// 0049ed0a  f7ea                 imul edx
// 0049ed0c  8bc2                 mov eax, edx
// 0049ed0e  c1e81f               shr eax, 0x1f
// 0049ed11  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0049ed15  03c2                 add eax, edx
// 0049ed17  2bc8                 sub ecx, eax
// 0049ed19  894c2444             mov dword ptr [esp + 0x44], ecx
// 0049ed1d  6a00                 push 0
// 0049ed1f  8d4c2414             lea ecx, [esp + 0x14]
// 0049ed23  896c2424             mov dword ptr [esp + 0x24], ebp
// 0049ed27  ff155846b200         call dword ptr [0xb24658]
// 0049ed2d  50                   push eax
// 0049ed2e  8d4c2418             lea ecx, [esp + 0x18]
// 0049ed32  ff159847b200         call dword ptr [0xb24798]
// 0049ed38  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 0049ed3c  50                   push eax
// 0049ed3d  8d4c242c             lea ecx, [esp + 0x2c]
// 0049ed41  51                   push ecx
// 0049ed42  6a00                 push 0
// 0049ed44  52                   push edx
// 0049ed45  55                   push ebp
// 0049ed46  8b4704               mov eax, dword ptr [edi + 4]
// 0049ed49  50                   push eax
// 0049ed4a  ff154421b200         call dword ptr [0xb22144]
// 0049ed50  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0049ed53  8b5618               mov edx, dword ptr [esi + 0x18]
// 0049ed56  2bcb                 sub ecx, ebx
// 0049ed58  83c105               add ecx, 5
// 0049ed5b  51                   push ecx
// 0049ed5c  52                   push edx
// 0049ed5d  8d442420             lea eax, [esp + 0x20]
// 0049ed61  50                   push eax
// 0049ed62  8bcf                 mov ecx, edi
// 0049ed64  e899424e00           call 0x983002
// 0049ed69  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0049ed6c  8b5620               mov edx, dword ptr [esi + 0x20]
// 0049ed6f  2bcb                 sub ecx, ebx
// 0049ed71  83c105               add ecx, 5
// 0049ed74  51                   push ecx
// 0049ed75  52                   push edx
// 0049ed76  8bcf                 mov ecx, edi
// 0049ed78  e87f424e00           call 0x982ffc
// 0049ed7d  8b442440             mov eax, dword ptr [esp + 0x40]
// 0049ed81  50                   push eax
// 0049ed82  8bcf                 mov ecx, edi
// 0049ed84  e87f424e00           call 0x983008
// 0049ed89  8b4624               mov eax, dword ptr [esi + 0x24]
// 0049ed8c  2bc3                 sub eax, ebx
// 0049ed8e  394614               cmp dword ptr [esi + 0x14], eax
// 0049ed91  7e03                 jle 0x49ed96
// 0049ed93  894614               mov dword ptr [esi + 0x14], eax
// 0049ed96  8d4c2410             lea ecx, [esp + 0x10]
// 0049ed9a  ff15d047b200         call dword ptr [0xb247d0]
// 0049eda0  8d4c2414             lea ecx, [esp + 0x14]
// 0049eda4  ff15d047b200         call dword ptr [0xb247d0]
// 0049edaa  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0049edae  5f                   pop edi
// 0049edaf  5e                   pop esi
// 0049edb0  5d                   pop ebp
// 0049edb1  5b                   pop ebx
// 0049edb2  64890d00000000       mov dword ptr fs:[0], ecx
// 0049edb9  83c42c               add esp, 0x2c
// 0049edbc  c20c00               ret 0xc
// copied from an identical function in another client (function ?drawPage@ns_ROCX00006d@@YGXPAUDC@1@PAUPage@1@PAUPrintInfo@1@@Z)

namespace ns_ROCX00006d {
// from server: 97% by colin
// roc 2008-06 004622e0  unit: Scintilla::CScintillaView  size: 399 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004622e0
//
// 004622e0  6aff                 push -1
// 004622e2  6852317c00           push 0x7c3152
// 004622e7  64a100000000         mov eax, dword ptr fs:[0]
// 004622ed  50                   push eax
// 004622ee  64892500000000       mov dword ptr fs:[0], esp
// 004622f5  83ec20               sub esp, 0x20
// 004622f8  53                   push ebx
// 004622f9  55                   push ebp
// 004622fa  56                   push esi
// 004622fb  57                   push edi
// 004622fc  8d4c2414             lea ecx, [esp + 0x14]
// 00462300  ff15043f8000         call dword ptr [0x803f04]
// 00462306  8b442444             mov eax, dword ptr [esp + 0x44]
// 0046230a  8b4814               mov ecx, dword ptr [eax + 0x14]
// 0046230d  51                   push ecx
// 0046230e  8d542418             lea edx, [esp + 0x18]
// 00462312  68d0358100           push 0x8135d0
// 00462317  52                   push edx
// 00462318  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00462320  ff15dc3e8000         call dword ptr [0x803edc]
// 00462326  83c40c               add esp, 0xc
// 00462329  8d4c2410             lea ecx, [esp + 0x10]
// 0046232d  ff15043f8000         call dword ptr [0x803f04]
// 00462333  8d4c2414             lea ecx, [esp + 0x14]
// 00462337  c644243801           mov byte ptr [esp + 0x38], 1
// 0046233c  ff15e03e8000         call dword ptr [0x803ee0]
// 00462342  50                   push eax
// 00462343  68c6000000           push 0xc6
// 00462348  8d442418             lea eax, [esp + 0x18]
// 0046234c  50                   push eax
// 0046234d  e8e4f02300           call 0x6a1436
// 00462352  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 00462356  8b17                 mov edx, dword ptr [edi]
// 00462358  8b4238               mov eax, dword ptr [edx + 0x38]
// 0046235b  6a00                 push 0
// 0046235d  8bcf                 mov ecx, edi
// 0046235f  ffd0                 call eax
// 00462361  6a00                 push 0
// 00462363  8bcf                 mov ecx, edi
// 00462365  e8c6f02300           call 0x6a1430
// 0046236a  8d4c2418             lea ecx, [esp + 0x18]
// 0046236e  51                   push ecx
// 0046236f  8d4c2414             lea ecx, [esp + 0x14]
// 00462373  89442444             mov dword ptr [esp + 0x44], eax
// 00462377  ff15e02f8000         call dword ptr [0x802fe0]
// 0046237d  50                   push eax
// 0046237e  8d4c2418             lea ecx, [esp + 0x18]
// 00462382  ff15e03e8000         call dword ptr [0x803ee0]
// 00462388  8b5708               mov edx, dword ptr [edi + 8]
// 0046238b  50                   push eax
// 0046238c  52                   push edx
// 0046238d  ff1540218000         call dword ptr [0x802140]
// 00462393  8b742448             mov esi, dword ptr [esp + 0x48]
// 00462397  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0046239a  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0046239e  8b5620               mov edx, dword ptr [esi + 0x20]
// 004623a1  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 004623a4  8bc1                 mov eax, ecx
// 004623a6  03db                 add ebx, ebx
// 004623a8  2bc3                 sub eax, ebx
// 004623aa  89442424             mov dword ptr [esp + 0x24], eax
// 004623ae  89542428             mov dword ptr [esp + 0x28], edx
// 004623b2  8d141b               lea edx, [ebx + ebx]
// 004623b5  b856555555           mov eax, 0x55555556
// 004623ba  f7ea                 imul edx
// 004623bc  8bc2                 mov eax, edx
// 004623be  c1e81f               shr eax, 0x1f
// 004623c1  894c242c             mov dword ptr [esp + 0x2c], ecx
// 004623c5  03c2                 add eax, edx
// 004623c7  2bc8                 sub ecx, eax
// 004623c9  894c2444             mov dword ptr [esp + 0x44], ecx
// 004623cd  6a00                 push 0
// 004623cf  8d4c2414             lea ecx, [esp + 0x14]
// 004623d3  896c2424             mov dword ptr [esp + 0x24], ebp
// 004623d7  ff15e02f8000         call dword ptr [0x802fe0]
// 004623dd  50                   push eax
// 004623de  8d4c2418             lea ecx, [esp + 0x18]
// 004623e2  ff15e03e8000         call dword ptr [0x803ee0]
// 004623e8  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 004623ec  50                   push eax
// 004623ed  8d4c242c             lea ecx, [esp + 0x2c]
// 004623f1  51                   push ecx
// 004623f2  6a00                 push 0
// 004623f4  52                   push edx
// 004623f5  55                   push ebp
// 004623f6  8b4704               mov eax, dword ptr [edi + 4]
// 004623f9  50                   push eax
// 004623fa  ff1544218000         call dword ptr [0x802144]
// 00462400  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 00462403  8b5618               mov edx, dword ptr [esi + 0x18]
// 00462406  2bcb                 sub ecx, ebx
// 00462408  83c105               add ecx, 5
// 0046240b  51                   push ecx
// 0046240c  52                   push edx
// 0046240d  8d442420             lea eax, [esp + 0x20]
// 00462411  50                   push eax
// 00462412  8bcf                 mov ecx, edi
// 00462414  e811f02300           call 0x6a142a
// 00462419  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0046241c  8b5620               mov edx, dword ptr [esi + 0x20]
// 0046241f  2bcb                 sub ecx, ebx
// 00462421  83c105               add ecx, 5
// 00462424  51                   push ecx
// 00462425  52                   push edx
// 00462426  8bcf                 mov ecx, edi
// 00462428  e8f7ef2300           call 0x6a1424
// 0046242d  8b442440             mov eax, dword ptr [esp + 0x40]
// 00462431  50                   push eax
// 00462432  8bcf                 mov ecx, edi
// 00462434  e8f7ef2300           call 0x6a1430
// 00462439  8b4624               mov eax, dword ptr [esi + 0x24]
// 0046243c  2bc3                 sub eax, ebx
// 0046243e  394614               cmp dword ptr [esi + 0x14], eax
// 00462441  7e03                 jle 0x462446
// 00462443  894614               mov dword ptr [esi + 0x14], eax
// 00462446  8d4c2410             lea ecx, [esp + 0x10]
// 0046244a  ff15143f8000         call dword ptr [0x803f14]
// 00462450  8d4c2414             lea ecx, [esp + 0x14]
// 00462454  ff15143f8000         call dword ptr [0x803f14]
// 0046245a  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0046245e  5f                   pop edi
// 0046245f  5e                   pop esi
// 00462460  5d                   pop ebp
// 00462461  5b                   pop ebx
// 00462462  64890d00000000       mov dword ptr fs:[0], ecx
// 00462469  83c42c               add esp, 0x2c
// 0046246c  c20c00               ret 0xc

// from server: 96% by colin
// roc 2008-06 004622e0  unit: Scintilla::CScintillaView  size: 399 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004622e0
//
// 004622e0  6aff                 push -1
// 004622e2  6852317c00           push 0x7c3152
// 004622e7  64a100000000         mov eax, dword ptr fs:[0]
// 004622ed  50                   push eax
// 004622ee  64892500000000       mov dword ptr fs:[0], esp
// 004622f5  83ec20               sub esp, 0x20
// 004622f8  53                   push ebx
// 004622f9  55                   push ebp
// 004622fa  56                   push esi
// 004622fb  57                   push edi
// 004622fc  8d4c2414             lea ecx, [esp + 0x14]
// 00462300  ff15043f8000         call dword ptr [0x803f04]
// 00462306  8b442444             mov eax, dword ptr [esp + 0x44]
// 0046230a  8b4814               mov ecx, dword ptr [eax + 0x14]
// 0046230d  51                   push ecx
// 0046230e  8d542418             lea edx, [esp + 0x18]
// 00462312  68d0358100           push 0x8135d0
// 00462317  52                   push edx
// 00462318  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00462320  ff15dc3e8000         call dword ptr [0x803edc]
// 00462326  83c40c               add esp, 0xc
// 00462329  8d4c2410             lea ecx, [esp + 0x10]
// 0046232d  ff15043f8000         call dword ptr [0x803f04]
// 00462333  8d4c2414             lea ecx, [esp + 0x14]
// 00462337  c644243801           mov byte ptr [esp + 0x38], 1
// 0046233c  ff15e03e8000         call dword ptr [0x803ee0]
// 00462342  50                   push eax
// 00462343  68c6000000           push 0xc6
// 00462348  8d442418             lea eax, [esp + 0x18]
// 0046234c  50                   push eax
// 0046234d  e8e4f02300           call 0x6a1436
// 00462352  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 00462356  8b17                 mov edx, dword ptr [edi]
// 00462358  8b4238               mov eax, dword ptr [edx + 0x38]
// 0046235b  6a00                 push 0
// 0046235d  8bcf                 mov ecx, edi
// 0046235f  ffd0                 call eax
// 00462361  6a00                 push 0
// 00462363  8bcf                 mov ecx, edi
// 00462365  e8c6f02300           call 0x6a1430
// 0046236a  8d4c2418             lea ecx, [esp + 0x18]
// 0046236e  51                   push ecx
// 0046236f  8d4c2414             lea ecx, [esp + 0x14]
// 00462373  89442444             mov dword ptr [esp + 0x44], eax
// 00462377  ff15e02f8000         call dword ptr [0x802fe0]
// 0046237d  50                   push eax
// 0046237e  8d4c2418             lea ecx, [esp + 0x18]
// 00462382  ff15e03e8000         call dword ptr [0x803ee0]
// 00462388  8b5708               mov edx, dword ptr [edi + 8]
// 0046238b  50                   push eax
// 0046238c  52                   push edx
// 0046238d  ff1540218000         call dword ptr [0x802140]
// 00462393  8b742448             mov esi, dword ptr [esp + 0x48]
// 00462397  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0046239a  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0046239e  8b5620               mov edx, dword ptr [esi + 0x20]
// 004623a1  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 004623a4  8bc1                 mov eax, ecx
// 004623a6  03db                 add ebx, ebx
// 004623a8  2bc3                 sub eax, ebx
// 004623aa  89442424             mov dword ptr [esp + 0x24], eax
// 004623ae  89542428             mov dword ptr [esp + 0x28], edx
// 004623b2  8d141b               lea edx, [ebx + ebx]
// 004623b5  b856555555           mov eax, 0x55555556
// 004623ba  f7ea                 imul edx
// 004623bc  8bc2                 mov eax, edx
// 004623be  c1e81f               shr eax, 0x1f
// 004623c1  894c242c             mov dword ptr [esp + 0x2c], ecx
// 004623c5  03c2                 add eax, edx
// 004623c7  2bc8                 sub ecx, eax
// 004623c9  894c2444             mov dword ptr [esp + 0x44], ecx
// 004623cd  6a00                 push 0
// 004623cf  8d4c2414             lea ecx, [esp + 0x14]
// 004623d3  896c2424             mov dword ptr [esp + 0x24], ebp
// 004623d7  ff15e02f8000         call dword ptr [0x802fe0]
// 004623dd  50                   push eax
// 004623de  8d4c2418             lea ecx, [esp + 0x18]
// 004623e2  ff15e03e8000         call dword ptr [0x803ee0]
// 004623e8  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 004623ec  50                   push eax
// 004623ed  8d4c242c             lea ecx, [esp + 0x2c]
// 004623f1  51                   push ecx
// 004623f2  6a00                 push 0
// 004623f4  52                   push edx
// 004623f5  55                   push ebp
// 004623f6  8b4704               mov eax, dword ptr [edi + 4]
// 004623f9  50                   push eax
// 004623fa  ff1544218000         call dword ptr [0x802144]
// 00462400  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 00462403  8b5618               mov edx, dword ptr [esi + 0x18]
// 00462406  2bcb                 sub ecx, ebx
// 00462408  83c105               add ecx, 5
// 0046240b  51                   push ecx
// 0046240c  52                   push edx
// 0046240d  8d442420             lea eax, [esp + 0x20]
// 00462411  50                   push eax
// 00462412  8bcf                 mov ecx, edi
// 00462414  e811f02300           call 0x6a142a
// 00462419  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0046241c  8b5620               mov edx, dword ptr [esi + 0x20]
// 0046241f  2bcb                 sub ecx, ebx
// 00462421  83c105               add ecx, 5
// 00462424  51                   push ecx
// 00462425  52                   push edx
// 00462426  8bcf                 mov ecx, edi
// 00462428  e8f7ef2300           call 0x6a1424
// 0046242d  8b442440             mov eax, dword ptr [esp + 0x40]
// 00462431  50                   push eax
// 00462432  8bcf                 mov ecx, edi
// 00462434  e8f7ef2300           call 0x6a1430
// 00462439  8b4624               mov eax, dword ptr [esi + 0x24]
// 0046243c  2bc3                 sub eax, ebx
// 0046243e  394614               cmp dword ptr [esi + 0x14], eax
// 00462441  7e03                 jle 0x462446
// 00462443  894614               mov dword ptr [esi + 0x14], eax
// 00462446  8d4c2410             lea ecx, [esp + 0x10]
// 0046244a  ff15143f8000         call dword ptr [0x803f14]
// 00462450  8d4c2414             lea ecx, [esp + 0x14]
// 00462454  ff15143f8000         call dword ptr [0x803f14]
// 0046245a  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0046245e  5f                   pop edi
// 0046245f  5e                   pop esi
// 00462460  5d                   pop ebp
// 00462461  5b                   pop ebx
// 00462462  64890d00000000       mov dword ptr fs:[0], ecx
// 00462469  83c42c               add esp, 0x2c
// 0046246c  c20c00               ret 0xc

// from server: 91% by king_originala
// roc 2008-06 004622e0  unit: Scintilla::CScintillaView  size: 399 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004622e0
//
// 004622e0  6aff                 push -1
// 004622e2  6852317c00           push 0x7c3152
// 004622e7  64a100000000         mov eax, dword ptr fs:[0]
// 004622ed  50                   push eax
// 004622ee  64892500000000       mov dword ptr fs:[0], esp
// 004622f5  83ec20               sub esp, 0x20
// 004622f8  53                   push ebx
// 004622f9  55                   push ebp
// 004622fa  56                   push esi
// 004622fb  57                   push edi
// 004622fc  8d4c2414             lea ecx, [esp + 0x14]
// 00462300  ff15043f8000         call dword ptr [0x803f04]
// 00462306  8b442444             mov eax, dword ptr [esp + 0x44]
// 0046230a  8b4814               mov ecx, dword ptr [eax + 0x14]
// 0046230d  51                   push ecx
// 0046230e  8d542418             lea edx, [esp + 0x18]
// 00462312  68d0358100           push 0x8135d0
// 00462317  52                   push edx
// 00462318  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00462320  ff15dc3e8000         call dword ptr [0x803edc]
// 00462326  83c40c               add esp, 0xc
// 00462329  8d4c2410             lea ecx, [esp + 0x10]
// 0046232d  ff15043f8000         call dword ptr [0x803f04]
// 00462333  8d4c2414             lea ecx, [esp + 0x14]
// 00462337  c644243801           mov byte ptr [esp + 0x38], 1
// 0046233c  ff15e03e8000         call dword ptr [0x803ee0]
// 00462342  50                   push eax
// 00462343  68c6000000           push 0xc6
// 00462348  8d442418             lea eax, [esp + 0x18]
// 0046234c  50                   push eax
// 0046234d  e8e4f02300           call 0x6a1436
// 00462352  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 00462356  8b17                 mov edx, dword ptr [edi]
// 00462358  8b4238               mov eax, dword ptr [edx + 0x38]
// 0046235b  6a00                 push 0
// 0046235d  8bcf                 mov ecx, edi
// 0046235f  ffd0                 call eax
// 00462361  6a00                 push 0
// 00462363  8bcf                 mov ecx, edi
// 00462365  e8c6f02300           call 0x6a1430
// 0046236a  8d4c2418             lea ecx, [esp + 0x18]
// 0046236e  51                   push ecx
// 0046236f  8d4c2414             lea ecx, [esp + 0x14]
// 00462373  89442444             mov dword ptr [esp + 0x44], eax
// 00462377  ff15e02f8000         call dword ptr [0x802fe0]
// 0046237d  50                   push eax
// 0046237e  8d4c2418             lea ecx, [esp + 0x18]
// 00462382  ff15e03e8000         call dword ptr [0x803ee0]
// 00462388  8b5708               mov edx, dword ptr [edi + 8]
// 0046238b  50                   push eax
// 0046238c  52                   push edx
// 0046238d  ff1540218000         call dword ptr [0x802140]
// 00462393  8b742448             mov esi, dword ptr [esp + 0x48]
// 00462397  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0046239a  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0046239e  8b5620               mov edx, dword ptr [esi + 0x20]
// 004623a1  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 004623a4  8bc1                 mov eax, ecx
// 004623a6  03db                 add ebx, ebx
// 004623a8  2bc3                 sub eax, ebx
// 004623aa  89442424             mov dword ptr [esp + 0x24], eax
// 004623ae  89542428             mov dword ptr [esp + 0x28], edx
// 004623b2  8d141b               lea edx, [ebx + ebx]
// 004623b5  b856555555           mov eax, 0x55555556
// 004623ba  f7ea                 imul edx
// 004623bc  8bc2                 mov eax, edx
// 004623be  c1e81f               shr eax, 0x1f
// 004623c1  894c242c             mov dword ptr [esp + 0x2c], ecx
// 004623c5  03c2                 add eax, edx
// 004623c7  2bc8                 sub ecx, eax
// 004623c9  894c2444             mov dword ptr [esp + 0x44], ecx
// 004623cd  6a00                 push 0
// 004623cf  8d4c2414             lea ecx, [esp + 0x14]
// 004623d3  896c2424             mov dword ptr [esp + 0x24], ebp
// 004623d7  ff15e02f8000         call dword ptr [0x802fe0]
// 004623dd  50                   push eax
// 004623de  8d4c2418             lea ecx, [esp + 0x18]
// 004623e2  ff15e03e8000         call dword ptr [0x803ee0]
// 004623e8  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 004623ec  50                   push eax
// 004623ed  8d4c242c             lea ecx, [esp + 0x2c]
// 004623f1  51                   push ecx
// 004623f2  6a00                 push 0
// 004623f4  52                   push edx
// 004623f5  55                   push ebp
// 004623f6  8b4704               mov eax, dword ptr [edi + 4]
// 004623f9  50                   push eax
// 004623fa  ff1544218000         call dword ptr [0x802144]
// 00462400  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 00462403  8b5618               mov edx, dword ptr [esi + 0x18]
// 00462406  2bcb                 sub ecx, ebx
// 00462408  83c105               add ecx, 5
// 0046240b  51                   push ecx
// 0046240c  52                   push edx
// 0046240d  8d442420             lea eax, [esp + 0x20]
// 00462411  50                   push eax
// 00462412  8bcf                 mov ecx, edi
// 00462414  e811f02300           call 0x6a142a
// 00462419  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0046241c  8b5620               mov edx, dword ptr [esi + 0x20]
// 0046241f  2bcb                 sub ecx, ebx
// 00462421  83c105               add ecx, 5
// 00462424  51                   push ecx
// 00462425  52                   push edx
// 00462426  8bcf                 mov ecx, edi
// 00462428  e8f7ef2300           call 0x6a1424
// 0046242d  8b442440             mov eax, dword ptr [esp + 0x40]
// 00462431  50                   push eax
// 00462432  8bcf                 mov ecx, edi
// 00462434  e8f7ef2300           call 0x6a1430
// 00462439  8b4624               mov eax, dword ptr [esi + 0x24]
// 0046243c  2bc3                 sub eax, ebx
// 0046243e  394614               cmp dword ptr [esi + 0x14], eax
// 00462441  7e03                 jle 0x462446
// 00462443  894614               mov dword ptr [esi + 0x14], eax
// 00462446  8d4c2410             lea ecx, [esp + 0x10]
// 0046244a  ff15143f8000         call dword ptr [0x803f14]
// 00462450  8d4c2414             lea ecx, [esp + 0x14]
// 00462454  ff15143f8000         call dword ptr [0x803f14]
// 0046245a  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0046245e  5f                   pop edi
// 0046245f  5e                   pop esi
// 00462460  5d                   pop ebp
// 00462461  5b                   pop ebx
// 00462462  64890d00000000       mov dword ptr fs:[0], ecx
// 00462469  83c42c               add esp, 0x2c
// 0046246c  c20c00               ret 0xc

struct Text;
struct Size { int cx, cy; };
struct Point { int x, y; };
struct Rect { int left, top, right, bottom; };

extern void (__thiscall *const textConstruct)(Text *);
extern void (__thiscall *const textDestroy)(Text *);
extern const char *(__thiscall *const textData)(const Text *);
extern int (__thiscall *const textLength)(const Text *);
extern void (__cdecl *const textFormat)(Text *, const char *, ...);
extern const char pageFormat[];

struct __declspec(dllimport) Text {
    char *data;
    Text();
    __declspec(nothrow) ~Text();
};
struct __declspec(dllimport) Text2 {
    char *data;
    Text2();
    __declspec(nothrow) ~Text2();
};

__forceinline Text::Text() { textConstruct(reinterpret_cast<Text*>(this)); }
__forceinline Text2::Text2() { textConstruct(reinterpret_cast<Text*>(this)); }
struct DC;
typedef unsigned long (__thiscall *DCVirtual)(DC *, unsigned long);

struct DC {
    DCVirtual *table;
    void *output;
    void *attribute;
    unsigned int setAlignment(unsigned int);
    Point moveTo(int, int);
    int lineTo(int, int);
};

struct Page {
    char reserved[20];
    int number;
};

struct PrintInfo {
    char reserved[20];
    int limit;
    Rect area;
};

extern int (__stdcall *const GetTextExtentPoint32A)(
    void *, const char *, int, Size *);
extern int (__stdcall *const ExtTextOutA)(
    void *, int, int, unsigned int, const Rect *,
    const char *, unsigned int, const int *);

extern void __stdcall formatResource(Text2 &, unsigned int, const char *);

void __stdcall drawPage(DC *dc, Page *page, PrintInfo *info)
{
    Text number;
    textFormat(&number, pageFormat, page->number);

    Text2 caption;
    formatResource(caption, 198, textData(reinterpret_cast<Text*>(&number)));

    dc->table[14](dc, 0);
    unsigned int previous = dc->setAlignment(0);

    int height;
    {
        Size extent;
        GetTextExtentPoint32A(
            dc->attribute, textData(reinterpret_cast<Text*>(&caption)), textLength(reinterpret_cast<Text*>(&caption)), &extent);

        height = extent.cy * 2;
        int left = info->area.left;
        Rect rectangle;
        rectangle.top = info->area.bottom - height;
        rectangle.right = info->area.right;
        rectangle.bottom = info->area.bottom;
        int baseline = info->area.bottom - (height * 2) / 3;
        rectangle.left = left;

        ExtTextOutA(
            dc->output, left, baseline, 0, &rectangle,
            textData(reinterpret_cast<Text*>(&caption)), textLength(reinterpret_cast<Text*>(&caption)), 0);
    }

    dc->moveTo(info->area.left, info->area.bottom - height + 5);
    dc->lineTo(info->area.right, info->area.bottom - height + 5);
    dc->setAlignment(previous);

    if (info->limit > info->area.bottom - height)
        info->limit = info->area.bottom - height;
}
}