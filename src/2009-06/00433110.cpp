// from server: 100% by auto
// roc 2009-06 00433110  unit: IIHAAH::?$CMap  size: 884 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00433110
//
// 00433110  83ec14               sub esp, 0x14
// 00433113  53                   push ebx
// 00433114  55                   push ebp
// 00433115  56                   push esi
// 00433116  8bf1                 mov esi, ecx
// 00433118  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0043311c  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0043311f  f7d0                 not eax
// 00433121  57                   push edi
// 00433122  89742414             mov dword ptr [esp + 0x14], esi
// 00433126  a801                 test al, 1
// 00433128  0f847d010000         je 0x4332ab
// 0043312e  8b560c               mov edx, dword ptr [esi + 0xc]
// 00433131  52                   push edx
// 00433132  e88f642e00           call 0x7195c6
// 00433137  837e0c00             cmp dword ptr [esi + 0xc], 0
// 0043313b  0f8439030000         je 0x43347a
// 00433141  33c0                 xor eax, eax
// 00433143  8944241c             mov dword ptr [esp + 0x1c], eax
// 00433147  394608               cmp dword ptr [esi + 8], eax
// 0043314a  0f862a030000         jbe 0x43347a
// 00433150  8b4e04               mov ecx, dword ptr [esi + 4]
// 00433153  8b2c81               mov ebp, dword ptr [ecx + eax*4]
// 00433156  896c2410             mov dword ptr [esp + 0x10], ebp
// 0043315a  85ed                 test ebp, ebp
// 0043315c  0f8422010000         je 0x433284
// 00433162  eb04                 jmp 0x433168
// 00433164  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00433168  8d5504               lea edx, [ebp + 4]
// 0043316b  89542418             mov dword ptr [esp + 0x18], edx
// 0043316f  85ed                 test ebp, ebp
// 00433171  0f8426010000         je 0x43329d
// 00433177  8b442428             mov eax, dword ptr [esp + 0x28]
// 0043317b  8b4818               mov ecx, dword ptr [eax + 0x18]
// 0043317e  f7d1                 not ecx
// 00433180  bf01000000           mov edi, 1
// 00433185  f6c101               test cl, 1
// 00433188  7436                 je 0x4331c0
// 0043318a  8d9b00000000         lea ebx, [ebx]
// 00433190  8bdf                 mov ebx, edi
// 00433192  81ffffffff1f         cmp edi, 0x1fffffff
// 00433198  7205                 jb 0x43319f
// 0043319a  bbffffff1f           mov ebx, 0x1fffffff
// 0043319f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004331a3  8d349d00000000       lea esi, [ebx*4]
// 004331aa  56                   push esi
// 004331ab  55                   push ebp
// 004331ac  e8fd632e00           call 0x7195ae
// 004331b1  2bfb                 sub edi, ebx
// 004331b3  03ee                 add ebp, esi
// 004331b5  85ff                 test edi, edi
// 004331b7  77d7                 ja 0x433190
// 004331b9  eb36                 jmp 0x4331f1
// 004331bb  eb03                 jmp 0x4331c0
// 004331bd  8d4900               lea ecx, [ecx]
// 004331c0  8bdf                 mov ebx, edi
// 004331c2  81ffffffff1f         cmp edi, 0x1fffffff
// 004331c8  7205                 jb 0x4331cf
// 004331ca  bbffffff1f           mov ebx, 0x1fffffff
// 004331cf  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004331d3  8d349d00000000       lea esi, [ebx*4]
// 004331da  56                   push esi
// 004331db  55                   push ebp
// 004331dc  e8c7632e00           call 0x7195a8
// 004331e1  3bc6                 cmp eax, esi
// 004331e3  0f85b9000000         jne 0x4332a2
// 004331e9  2bfb                 sub edi, ebx
// 004331eb  03ee                 add ebp, esi
// 004331ed  85ff                 test edi, edi
// 004331ef  77cf                 ja 0x4331c0
// 004331f1  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004331f5  85ed                 test ebp, ebp
// 004331f7  0f84a0000000         je 0x43329d
// 004331fd  8b542428             mov edx, dword ptr [esp + 0x28]
// 00433201  8b4218               mov eax, dword ptr [edx + 0x18]
// 00433204  f7d0                 not eax
// 00433206  bf01000000           mov edi, 1
// 0043320b  a801                 test al, 1
// 0043320d  7431                 je 0x433240
// 0043320f  90                   nop 
// 00433210  8bdf                 mov ebx, edi
// 00433212  81ffffffff1f         cmp edi, 0x1fffffff
// 00433218  7205                 jb 0x43321f
// 0043321a  bbffffff1f           mov ebx, 0x1fffffff
// 0043321f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00433223  8d349d00000000       lea esi, [ebx*4]
// 0043322a  56                   push esi
// 0043322b  55                   push ebp
// 0043322c  e87d632e00           call 0x7195ae
// 00433231  2bfb                 sub edi, ebx
// 00433233  03ee                 add ebp, esi
// 00433235  85ff                 test edi, edi
// 00433237  77d7                 ja 0x433210
// 00433239  eb32                 jmp 0x43326d
// 0043323b  eb03                 jmp 0x433240
// 0043323d  8d4900               lea ecx, [ecx]
// 00433240  8bdf                 mov ebx, edi
// 00433242  81ffffffff1f         cmp edi, 0x1fffffff
// 00433248  7205                 jb 0x43324f
// 0043324a  bbffffff1f           mov ebx, 0x1fffffff
// 0043324f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00433253  8d349d00000000       lea esi, [ebx*4]
// 0043325a  56                   push esi
// 0043325b  55                   push ebp
// 0043325c  e847632e00           call 0x7195a8
// 00433261  3bc6                 cmp eax, esi
// 00433263  753d                 jne 0x4332a2
// 00433265  2bfb                 sub edi, ebx
// 00433267  03ee                 add ebp, esi
// 00433269  85ff                 test edi, edi
// 0043326b  77d3                 ja 0x433240
// 0043326d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00433271  8b4108               mov eax, dword ptr [ecx + 8]
// 00433274  89442410             mov dword ptr [esp + 0x10], eax
// 00433278  85c0                 test eax, eax
// 0043327a  0f85e4feffff         jne 0x433164
// 00433280  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00433284  8b542414             mov edx, dword ptr [esp + 0x14]
// 00433288  40                   inc eax
// 00433289  8944241c             mov dword ptr [esp + 0x1c], eax
// 0043328d  3b4208               cmp eax, dword ptr [edx + 8]
// 00433290  0f83e4010000         jae 0x43347a
// 00433296  8bf2                 mov esi, edx
// 00433298  e9b3feffff           jmp 0x433150
// 0043329d  e8425a2e00           call 0x718ce4
// 004332a2  6a00                 push 0
// 004332a4  6a03                 push 3
// 004332a6  e8f7622e00           call 0x7195a2
// 004332ab  e810632e00           call 0x7195c0
// 004332b0  89442410             mov dword ptr [esp + 0x10], eax
// 004332b4  85c0                 test eax, eax
// 004332b6  0f84be010000         je 0x43347a
// 004332bc  8d642400             lea esp, [esp]
// 004332c0  8b442428             mov eax, dword ptr [esp + 0x28]
// 004332c4  8b4818               mov ecx, dword ptr [eax + 0x18]
// 004332c7  bd01000000           mov ebp, 1
// 004332cc  296c2410             sub dword ptr [esp + 0x10], ebp
// 004332d0  f7d1                 not ecx
// 004332d2  8d5c241c             lea ebx, [esp + 0x1c]
// 004332d6  f6c101               test cl, 1
// 004332d9  7435                 je 0x433310
// 004332db  8bfd                 mov edi, ebp
// 004332dd  8d4900               lea ecx, [ecx]
// 004332e0  8bef                 mov ebp, edi
// 004332e2  81ffffffff1f         cmp edi, 0x1fffffff
// 004332e8  7205                 jb 0x4332ef
// 004332ea  bdffffff1f           mov ebp, 0x1fffffff
// 004332ef  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004332f3  8d34ad00000000       lea esi, [ebp*4]
// 004332fa  56                   push esi
// 004332fb  53                   push ebx
// 004332fc  e8ad622e00           call 0x7195ae
// 00433301  2bfd                 sub edi, ebp
// 00433303  03de                 add ebx, esi
// 00433305  85ff                 test edi, edi
// 00433307  77d7                 ja 0x4332e0
// 00433309  eb36                 jmp 0x433341
// 0043330b  eb03                 jmp 0x433310
// 0043330d  8d4900               lea ecx, [ecx]
// 00433310  8bfd                 mov edi, ebp
// 00433312  81fdffffff1f         cmp ebp, 0x1fffffff
// 00433318  7205                 jb 0x43331f
// 0043331a  bfffffff1f           mov edi, 0x1fffffff
// 0043331f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00433323  8d34bd00000000       lea esi, [edi*4]
// 0043332a  56                   push esi
// 0043332b  53                   push ebx
// 0043332c  e877622e00           call 0x7195a8
// 00433331  3bc6                 cmp eax, esi
// 00433333  0f8569ffffff         jne 0x4332a2
// 00433339  2bef                 sub ebp, edi
// 0043333b  03de                 add ebx, esi
// 0043333d  85ed                 test ebp, ebp
// 0043333f  77cf                 ja 0x433310
// 00433341  8b542428             mov edx, dword ptr [esp + 0x28]
// 00433345  8b4218               mov eax, dword ptr [edx + 0x18]
// 00433348  f7d0                 not eax
// 0043334a  8d5c2418             lea ebx, [esp + 0x18]
// 0043334e  a801                 test al, 1
// 00433350  7439                 je 0x43338b
// 00433352  bf01000000           mov edi, 1
// 00433357  eb07                 jmp 0x433360
// 00433359  8da42400000000       lea esp, [esp]
// 00433360  8bef                 mov ebp, edi
// 00433362  81ffffffff1f         cmp edi, 0x1fffffff
// 00433368  7205                 jb 0x43336f
// 0043336a  bdffffff1f           mov ebp, 0x1fffffff
// 0043336f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00433373  8d34ad00000000       lea esi, [ebp*4]
// 0043337a  56                   push esi
// 0043337b  53                   push ebx
// 0043337c  e82d622e00           call 0x7195ae
// 00433381  2bfd                 sub edi, ebp
// 00433383  03de                 add ebx, esi
// 00433385  85ff                 test edi, edi
// 00433387  77d7                 ja 0x433360
// 00433389  eb36                 jmp 0x4333c1
// 0043338b  bd01000000           mov ebp, 1
// 00433390  8bfd                 mov edi, ebp
// 00433392  81fdffffff1f         cmp ebp, 0x1fffffff
// 00433398  7205                 jb 0x43339f
// 0043339a  bfffffff1f           mov edi, 0x1fffffff
// 0043339f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004333a3  8d34bd00000000       lea esi, [edi*4]
// 004333aa  56                   push esi
// 004333ab  53                   push ebx
// 004333ac  e8f7612e00           call 0x7195a8
// 004333b1  3bc6                 cmp eax, esi
// 004333b3  0f85e9feffff         jne 0x4332a2
// 004333b9  2bef                 sub ebp, edi
// 004333bb  03de                 add ebx, esi
// 004333bd  85ed                 test ebp, ebp
// 004333bf  77cf                 ja 0x433390
// 004333c1  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 004333c5  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004333c9  8b6f08               mov ebp, dword ptr [edi + 8]
// 004333cc  8bf3                 mov esi, ebx
// 004333ce  c1ee04               shr esi, 4
// 004333d1  33d2                 xor edx, edx
// 004333d3  8bc6                 mov eax, esi
// 004333d5  f7f5                 div ebp
// 004333d7  8b4f04               mov ecx, dword ptr [edi + 4]
// 004333da  89542420             mov dword ptr [esp + 0x20], edx
// 004333de  85c9                 test ecx, ecx
// 004333e0  7422                 je 0x433404
// 004333e2  8b0491               mov eax, dword ptr [ecx + edx*4]
// 004333e5  85c0                 test eax, eax
// 004333e7  7417                 je 0x433400
// 004333e9  8da42400000000       lea esp, [esp]
// 004333f0  39700c               cmp dword ptr [eax + 0xc], esi
// 004333f3  7504                 jne 0x4333f9
// 004333f5  3918                 cmp dword ptr [eax], ebx
// 004333f7  746f                 je 0x433468
// 004333f9  8b4008               mov eax, dword ptr [eax + 8]
// 004333fc  85c0                 test eax, eax
// 004333fe  75f0                 jne 0x4333f0
// 00433400  85c9                 test ecx, ecx
// 00433402  753c                 jne 0x433440
// 00433404  33c9                 xor ecx, ecx
// 00433406  8bc5                 mov eax, ebp
// 00433408  ba04000000           mov edx, 4
// 0043340d  f7e2                 mul edx
// 0043340f  0f90c1               seto cl
// 00433412  f7d9                 neg ecx
// 00433414  0bc8                 or ecx, eax
// 00433416  51                   push ecx
// 00433417  e8fe582e00           call 0x718d1a
// 0043341c  83c404               add esp, 4
// 0043341f  894704               mov dword ptr [edi + 4], eax
// 00433422  85c0                 test eax, eax
// 00433424  0f8473feffff         je 0x43329d
// 0043342a  8d0cad00000000       lea ecx, [ebp*4]
// 00433431  51                   push ecx
// 00433432  6a00                 push 0
// 00433434  50                   push eax
// 00433435  e83a682e00           call 0x719c74
// 0043343a  83c40c               add esp, 0xc
// 0043343d  896f08               mov dword ptr [edi + 8], ebp
// 00433440  837f0400             cmp dword ptr [edi + 4], 0
// 00433444  0f8453feffff         je 0x43329d
// 0043344a  53                   push ebx
// 0043344b  8bcf                 mov ecx, edi
// 0043344d  e8ae243000           call 0x735900
// 00433452  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00433456  89700c               mov dword ptr [eax + 0xc], esi
// 00433459  8b5704               mov edx, dword ptr [edi + 4]
// 0043345c  8b148a               mov edx, dword ptr [edx + ecx*4]
// 0043345f  895008               mov dword ptr [eax + 8], edx
// 00433462  8b5704               mov edx, dword ptr [edi + 4]
// 00433465  89048a               mov dword ptr [edx + ecx*4], eax
// 00433468  837c241000           cmp dword ptr [esp + 0x10], 0
// 0043346d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00433471  894804               mov dword ptr [eax + 4], ecx
// 00433474  0f8546feffff         jne 0x4332c0
// 0043347a  5f                   pop edi
// 0043347b  5e                   pop esi
// 0043347c  5d                   pop ebp
// 0043347d  5b                   pop ebx
// 0043347e  83c414               add esp, 0x14
// 00433481  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPCalendarTheme.cpp (function ?Serialize@?$CMap@IIIAAI@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarTheme.cpp
