// from server: 100% by Yeetserama
// roc 2007-08 0045e2b0  unit: Scintilla::CScintillaView  size: 411 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045e2b0
//
// 0045e2b0  6aff                 push -1
// 0045e2b2  6832267400           push 0x742632
// 0045e2b7  64a100000000         mov eax, dword ptr fs:[0]
// 0045e2bd  50                   push eax
// 0045e2be  83ec20               sub esp, 0x20
// 0045e2c1  53                   push ebx
// 0045e2c2  55                   push ebp
// 0045e2c3  56                   push esi
// 0045e2c4  57                   push edi
// 0045e2c5  a188518b00           mov eax, dword ptr [0x8b5188]
// 0045e2ca  33c4                 xor eax, esp
// 0045e2cc  50                   push eax
// 0045e2cd  8d442434             lea eax, [esp + 0x34]
// 0045e2d1  64a300000000         mov dword ptr fs:[0], eax
// 0045e2d7  8d4c2418             lea ecx, [esp + 0x18]
// 0045e2db  ff15acdd7700         call dword ptr [0x77ddac]
// 0045e2e1  8b442448             mov eax, dword ptr [esp + 0x48]
// 0045e2e5  8b4814               mov ecx, dword ptr [eax + 0x14]
// 0045e2e8  51                   push ecx
// 0045e2e9  8d54241c             lea edx, [esp + 0x1c]
// 0045e2ed  68a0d37800           push 0x78d3a0
// 0045e2f2  52                   push edx
// 0045e2f3  c744244800000000     mov dword ptr [esp + 0x48], 0
// 0045e2fb  ff1594dd7700         call dword ptr [0x77dd94]
// 0045e301  83c40c               add esp, 0xc
// 0045e304  8d4c2414             lea ecx, [esp + 0x14]
// 0045e308  ff15acdd7700         call dword ptr [0x77ddac]
// 0045e30e  8d4c2418             lea ecx, [esp + 0x18]
// 0045e312  c644243c01           mov byte ptr [esp + 0x3c], 1
// 0045e317  ff1598dd7700         call dword ptr [0x77dd98]
// 0045e31d  50                   push eax
// 0045e31e  68c6000000           push 0xc6
// 0045e323  8d44241c             lea eax, [esp + 0x1c]
// 0045e327  50                   push eax
// 0045e328  e85b261d00           call 0x630988
// 0045e32d  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 0045e331  8b17                 mov edx, dword ptr [edi]
// 0045e333  8b4238               mov eax, dword ptr [edx + 0x38]
// 0045e336  6a00                 push 0
// 0045e338  8bcf                 mov ecx, edi
// 0045e33a  ffd0                 call eax
// 0045e33c  6a00                 push 0
// 0045e33e  8bcf                 mov ecx, edi
// 0045e340  e83d261d00           call 0x630982
// 0045e345  8d4c241c             lea ecx, [esp + 0x1c]
// 0045e349  51                   push ecx
// 0045e34a  8d4c2418             lea ecx, [esp + 0x18]
// 0045e34e  89442448             mov dword ptr [esp + 0x48], eax
// 0045e352  ff15c8dc7700         call dword ptr [0x77dcc8]
// 0045e358  50                   push eax
// 0045e359  8d4c241c             lea ecx, [esp + 0x1c]
// 0045e35d  ff1598dd7700         call dword ptr [0x77dd98]
// 0045e363  8b5708               mov edx, dword ptr [edi + 8]
// 0045e366  50                   push eax
// 0045e367  52                   push edx
// 0045e368  ff15b8d07700         call dword ptr [0x77d0b8]
// 0045e36e  8b74244c             mov esi, dword ptr [esp + 0x4c]
// 0045e372  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0045e375  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0045e379  8b5620               mov edx, dword ptr [esi + 0x20]
// 0045e37c  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 0045e37f  8bc1                 mov eax, ecx
// 0045e381  03db                 add ebx, ebx
// 0045e383  2bc3                 sub eax, ebx
// 0045e385  89442428             mov dword ptr [esp + 0x28], eax
// 0045e389  8954242c             mov dword ptr [esp + 0x2c], edx
// 0045e38d  8d141b               lea edx, [ebx + ebx]
// 0045e390  b856555555           mov eax, 0x55555556
// 0045e395  f7ea                 imul edx
// 0045e397  8bc2                 mov eax, edx
// 0045e399  c1e81f               shr eax, 0x1f
// 0045e39c  894c2430             mov dword ptr [esp + 0x30], ecx
// 0045e3a0  03c2                 add eax, edx
// 0045e3a2  2bc8                 sub ecx, eax
// 0045e3a4  894c2448             mov dword ptr [esp + 0x48], ecx
// 0045e3a8  6a00                 push 0
// 0045e3aa  8d4c2418             lea ecx, [esp + 0x18]
// 0045e3ae  896c2428             mov dword ptr [esp + 0x28], ebp
// 0045e3b2  ff15c8dc7700         call dword ptr [0x77dcc8]
// 0045e3b8  50                   push eax
// 0045e3b9  8d4c241c             lea ecx, [esp + 0x1c]
// 0045e3bd  ff1598dd7700         call dword ptr [0x77dd98]
// 0045e3c3  8b542450             mov edx, dword ptr [esp + 0x50]
// 0045e3c7  50                   push eax
// 0045e3c8  8b4704               mov eax, dword ptr [edi + 4]
// 0045e3cb  8d4c2430             lea ecx, [esp + 0x30]
// 0045e3cf  51                   push ecx
// 0045e3d0  6a00                 push 0
// 0045e3d2  52                   push edx
// 0045e3d3  55                   push ebp
// 0045e3d4  50                   push eax
// 0045e3d5  ff15bcd07700         call dword ptr [0x77d0bc]
// 0045e3db  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0045e3de  8b5618               mov edx, dword ptr [esi + 0x18]
// 0045e3e1  2bcb                 sub ecx, ebx
// 0045e3e3  83c105               add ecx, 5
// 0045e3e6  51                   push ecx
// 0045e3e7  52                   push edx
// 0045e3e8  8d442424             lea eax, [esp + 0x24]
// 0045e3ec  50                   push eax
// 0045e3ed  8bcf                 mov ecx, edi
// 0045e3ef  e888251d00           call 0x63097c
// 0045e3f4  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0045e3f7  8b5620               mov edx, dword ptr [esi + 0x20]
// 0045e3fa  2bcb                 sub ecx, ebx
// 0045e3fc  83c105               add ecx, 5
// 0045e3ff  51                   push ecx
// 0045e400  52                   push edx
// 0045e401  8bcf                 mov ecx, edi
// 0045e403  e86e251d00           call 0x630976
// 0045e408  8b442444             mov eax, dword ptr [esp + 0x44]
// 0045e40c  50                   push eax
// 0045e40d  8bcf                 mov ecx, edi
// 0045e40f  e86e251d00           call 0x630982
// 0045e414  8b4624               mov eax, dword ptr [esi + 0x24]
// 0045e417  2bc3                 sub eax, ebx
// 0045e419  394614               cmp dword ptr [esi + 0x14], eax
// 0045e41c  7e03                 jle 0x45e421
// 0045e41e  894614               mov dword ptr [esi + 0x14], eax
// 0045e421  8d4c2414             lea ecx, [esp + 0x14]
// 0045e425  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0045e42b  8d4c2418             lea ecx, [esp + 0x18]
// 0045e42f  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0045e435  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0045e439  64890d00000000       mov dword ptr fs:[0], ecx
// 0045e440  59                   pop ecx
// 0045e441  5f                   pop edi
// 0045e442  5e                   pop esi
// 0045e443  5d                   pop ebp
// 0045e444  5b                   pop ebx
// 0045e445  83c42c               add esp, 0x2c
// 0045e448  c20c00               ret 0xc
// copied from an identical function in another client (function ?drawPage@ns_ROCX000012@@YGXPAUDC@1@PAUPage@1@PAUPrintInfo@1@@Z)

namespace ns_ROCX000012 {
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
