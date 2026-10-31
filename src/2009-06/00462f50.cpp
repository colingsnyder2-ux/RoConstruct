// from server: 100% by EspClaude
// roc 2009-06 00462f50  unit: Scintilla::CScintillaView  size: 399 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00462f50
//
// 00462f50  6aff                 push -1
// 00462f52  68e22b8500           push 0x852be2
// 00462f57  64a100000000         mov eax, dword ptr fs:[0]
// 00462f5d  50                   push eax
// 00462f5e  64892500000000       mov dword ptr fs:[0], esp
// 00462f65  83ec20               sub esp, 0x20
// 00462f68  53                   push ebx
// 00462f69  55                   push ebp
// 00462f6a  56                   push esi
// 00462f6b  57                   push edi
// 00462f6c  8d4c2414             lea ecx, [esp + 0x14]
// 00462f70  ff15bcfc8900         call dword ptr [0x89fcbc]
// 00462f76  8b442444             mov eax, dword ptr [esp + 0x44]
// 00462f7a  8b4814               mov ecx, dword ptr [eax + 0x14]
// 00462f7d  51                   push ecx
// 00462f7e  8d542418             lea edx, [esp + 0x18]
// 00462f82  68683b8b00           push 0x8b3b68
// 00462f87  52                   push edx
// 00462f88  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00462f90  ff15c4fc8900         call dword ptr [0x89fcc4]
// 00462f96  83c40c               add esp, 0xc
// 00462f99  8d4c2410             lea ecx, [esp + 0x10]
// 00462f9d  ff15bcfc8900         call dword ptr [0x89fcbc]
// 00462fa3  8d4c2414             lea ecx, [esp + 0x14]
// 00462fa7  c644243801           mov byte ptr [esp + 0x38], 1
// 00462fac  ff15d0fc8900         call dword ptr [0x89fcd0]
// 00462fb2  50                   push eax
// 00462fb3  68c6000000           push 0xc6
// 00462fb8  8d442418             lea eax, [esp + 0x18]
// 00462fbc  50                   push eax
// 00462fbd  e858692b00           call 0x71991a
// 00462fc2  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 00462fc6  8b17                 mov edx, dword ptr [edi]
// 00462fc8  8b4238               mov eax, dword ptr [edx + 0x38]
// 00462fcb  6a00                 push 0
// 00462fcd  8bcf                 mov ecx, edi
// 00462fcf  ffd0                 call eax
// 00462fd1  6a00                 push 0
// 00462fd3  8bcf                 mov ecx, edi
// 00462fd5  e83a692b00           call 0x719914
// 00462fda  8d4c2418             lea ecx, [esp + 0x18]
// 00462fde  51                   push ecx
// 00462fdf  8d4c2414             lea ecx, [esp + 0x14]
// 00462fe3  89442444             mov dword ptr [esp + 0x44], eax
// 00462fe7  ff1554fb8900         call dword ptr [0x89fb54]
// 00462fed  50                   push eax
// 00462fee  8d4c2418             lea ecx, [esp + 0x18]
// 00462ff2  ff15d0fc8900         call dword ptr [0x89fcd0]
// 00462ff8  8b5708               mov edx, dword ptr [edi + 8]
// 00462ffb  50                   push eax
// 00462ffc  52                   push edx
// 00462ffd  ff1550e18900         call dword ptr [0x89e150]
// 00463003  8b742448             mov esi, dword ptr [esp + 0x48]
// 00463007  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0046300a  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0046300e  8b5620               mov edx, dword ptr [esi + 0x20]
// 00463011  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 00463014  8bc1                 mov eax, ecx
// 00463016  03db                 add ebx, ebx
// 00463018  2bc3                 sub eax, ebx
// 0046301a  89442424             mov dword ptr [esp + 0x24], eax
// 0046301e  89542428             mov dword ptr [esp + 0x28], edx
// 00463022  8d141b               lea edx, [ebx + ebx]
// 00463025  b856555555           mov eax, 0x55555556
// 0046302a  f7ea                 imul edx
// 0046302c  8bc2                 mov eax, edx
// 0046302e  c1e81f               shr eax, 0x1f
// 00463031  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00463035  03c2                 add eax, edx
// 00463037  2bc8                 sub ecx, eax
// 00463039  894c2444             mov dword ptr [esp + 0x44], ecx
// 0046303d  6a00                 push 0
// 0046303f  8d4c2414             lea ecx, [esp + 0x14]
// 00463043  896c2424             mov dword ptr [esp + 0x24], ebp
// 00463047  ff1554fb8900         call dword ptr [0x89fb54]
// 0046304d  50                   push eax
// 0046304e  8d4c2418             lea ecx, [esp + 0x18]
// 00463052  ff15d0fc8900         call dword ptr [0x89fcd0]
// 00463058  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 0046305c  50                   push eax
// 0046305d  8d4c242c             lea ecx, [esp + 0x2c]
// 00463061  51                   push ecx
// 00463062  6a00                 push 0
// 00463064  52                   push edx
// 00463065  55                   push ebp
// 00463066  8b4704               mov eax, dword ptr [edi + 4]
// 00463069  50                   push eax
// 0046306a  ff1554e18900         call dword ptr [0x89e154]
// 00463070  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 00463073  8b5618               mov edx, dword ptr [esi + 0x18]
// 00463076  2bcb                 sub ecx, ebx
// 00463078  83c105               add ecx, 5
// 0046307b  51                   push ecx
// 0046307c  52                   push edx
// 0046307d  8d442420             lea eax, [esp + 0x20]
// 00463081  50                   push eax
// 00463082  8bcf                 mov ecx, edi
// 00463084  e885682b00           call 0x71990e
// 00463089  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0046308c  8b5620               mov edx, dword ptr [esi + 0x20]
// 0046308f  2bcb                 sub ecx, ebx
// 00463091  83c105               add ecx, 5
// 00463094  51                   push ecx
// 00463095  52                   push edx
// 00463096  8bcf                 mov ecx, edi
// 00463098  e86b682b00           call 0x719908
// 0046309d  8b442440             mov eax, dword ptr [esp + 0x40]
// 004630a1  50                   push eax
// 004630a2  8bcf                 mov ecx, edi
// 004630a4  e86b682b00           call 0x719914
// 004630a9  8b4624               mov eax, dword ptr [esi + 0x24]
// 004630ac  2bc3                 sub eax, ebx
// 004630ae  394614               cmp dword ptr [esi + 0x14], eax
// 004630b1  7e03                 jle 0x4630b6
// 004630b3  894614               mov dword ptr [esi + 0x14], eax
// 004630b6  8d4c2410             lea ecx, [esp + 0x10]
// 004630ba  ff1510fd8900         call dword ptr [0x89fd10]
// 004630c0  8d4c2414             lea ecx, [esp + 0x14]
// 004630c4  ff1510fd8900         call dword ptr [0x89fd10]
// 004630ca  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004630ce  5f                   pop edi
// 004630cf  5e                   pop esi
// 004630d0  5d                   pop ebp
// 004630d1  5b                   pop ebx
// 004630d2  64890d00000000       mov dword ptr fs:[0], ecx
// 004630d9  83c42c               add esp, 0x2c
// 004630dc  c20c00               ret 0xc
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
