// from server: 100% by auto
// roc 2009-06 00594830  unit: seg_00590000  size: 798 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00594830
//
// 00594830  83ec38               sub esp, 0x38
// 00594833  53                   push ebx
// 00594834  55                   push ebp
// 00594835  56                   push esi
// 00594836  8b742448             mov esi, dword ptr [esp + 0x48]
// 0059483a  33d2                 xor edx, edx
// 0059483c  b804000000           mov eax, 4
// 00594841  b902000000           mov ecx, 2
// 00594846  57                   push edi
// 00594847  bb01000000           mov ebx, 1
// 0059484c  bf08000000           mov edi, 8
// 00594851  56                   push esi
// 00594852  89542430             mov dword ptr [esp + 0x30], edx
// 00594856  89442434             mov dword ptr [esp + 0x34], eax
// 0059485a  89542438             mov dword ptr [esp + 0x38], edx
// 0059485e  894c243c             mov dword ptr [esp + 0x3c], ecx
// 00594862  89542440             mov dword ptr [esp + 0x40], edx
// 00594866  895c2444             mov dword ptr [esp + 0x44], ebx
// 0059486a  89542448             mov dword ptr [esp + 0x48], edx
// 0059486e  897c2414             mov dword ptr [esp + 0x14], edi
// 00594872  897c2418             mov dword ptr [esp + 0x18], edi
// 00594876  8944241c             mov dword ptr [esp + 0x1c], eax
// 0059487a  89442420             mov dword ptr [esp + 0x20], eax
// 0059487e  894c2424             mov dword ptr [esp + 0x24], ecx
// 00594882  894c2428             mov dword ptr [esp + 0x28], ecx
// 00594886  895c242c             mov dword ptr [esp + 0x2c], ebx
// 0059488a  895678               mov dword ptr [esi + 0x78], edx
// 0059488d  e88e30ffff           call 0x587920
// 00594892  83c404               add esp, 4
// 00594895  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 0059489c  7472                 je 0x594910
// 0059489e  f6467002             test byte ptr [esi + 0x70], 2
// 005948a2  7514                 jne 0x5948b8
// 005948a4  8b86cc000000         mov eax, dword ptr [esi + 0xcc]
// 005948aa  83c007               add eax, 7
// 005948ad  c1e803               shr eax, 3
// 005948b0  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 005948b6  eb0c                 jmp 0x5948c4
// 005948b8  8b8ecc000000         mov ecx, dword ptr [esi + 0xcc]
// 005948be  898ed0000000         mov dword ptr [esi + 0xd0], ecx
// 005948c4  0fb68624010000       movzx eax, byte ptr [esi + 0x124]
// 005948cb  8baec8000000         mov ebp, dword ptr [esi + 0xc8]
// 005948d1  03c0                 add eax, eax
// 005948d3  03c0                 add eax, eax
// 005948d5  8b4c0410             mov ecx, dword ptr [esp + eax + 0x10]
// 005948d9  8bd5                 mov edx, ebp
// 005948db  2b54042c             sub edx, dword ptr [esp + eax + 0x2c]
// 005948df  8d440aff             lea eax, [edx + ecx - 1]
// 005948e3  33d2                 xor edx, edx
// 005948e5  f7f1                 div ecx
// 005948e7  8a8e29010000         mov cl, byte ptr [esi + 0x129]
// 005948ed  80f908               cmp cl, 8
// 005948f0  0fb6c9               movzx ecx, cl
// 005948f3  8986e0000000         mov dword ptr [esi + 0xe0], eax
// 005948f9  7209                 jb 0x594904
// 005948fb  c1e903               shr ecx, 3
// 005948fe  0fafc8               imul ecx, eax
// 00594901  41                   inc ecx
// 00594902  eb2c                 jmp 0x594930
// 00594904  0fafc8               imul ecx, eax
// 00594907  83c107               add ecx, 7
// 0059490a  c1e903               shr ecx, 3
// 0059490d  41                   inc ecx
// 0059490e  eb20                 jmp 0x594930
// 00594910  8b86cc000000         mov eax, dword ptr [esi + 0xcc]
// 00594916  8baec8000000         mov ebp, dword ptr [esi + 0xc8]
// 0059491c  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 00594922  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 00594928  89aee0000000         mov dword ptr [esi + 0xe0], ebp
// 0059492e  03cb                 add ecx, ebx
// 00594930  8b5e70               mov ebx, dword ptr [esi + 0x70]
// 00594933  0fb68629010000       movzx eax, byte ptr [esi + 0x129]
// 0059493a  898edc000000         mov dword ptr [esi + 0xdc], ecx
// 00594940  f6c304               test bl, 4
// 00594943  740b                 je 0x594950
// 00594945  80be2701000008       cmp byte ptr [esi + 0x127], 8
// 0059494c  7302                 jae 0x594950
// 0059494e  8bc7                 mov eax, edi
// 00594950  8bfb                 mov edi, ebx
// 00594952  81e700100000         and edi, 0x1000
// 00594958  7460                 je 0x5949ba
// 0059495a  8a8e26010000         mov cl, byte ptr [esi + 0x126]
// 00594960  80f903               cmp cl, 3
// 00594963  7515                 jne 0x59497a
// 00594965  33c0                 xor eax, eax
// 00594967  6639861a010000       cmp word ptr [esi + 0x11a], ax
// 0059496e  0f95c0               setne al
// 00594971  8d04c518000000       lea eax, [eax*8 + 0x18]
// 00594978  eb40                 jmp 0x5949ba
// 0059497a  84c9                 test cl, cl
// 0059497c  7518                 jne 0x594996
// 0059497e  83f808               cmp eax, 8
// 00594981  7d05                 jge 0x594988
// 00594983  b808000000           mov eax, 8
// 00594988  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 00594990  7428                 je 0x5949ba
// 00594992  03c0                 add eax, eax
// 00594994  eb24                 jmp 0x5949ba
// 00594996  80f902               cmp cl, 2
// 00594999  751f                 jne 0x5949ba
// 0059499b  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 005949a3  7415                 je 0x5949ba
// 005949a5  8d0c8500000000       lea ecx, [eax*4]
// 005949ac  b856555555           mov eax, 0x55555556
// 005949b1  f7e9                 imul ecx
// 005949b3  8bc2                 mov eax, edx
// 005949b5  c1e81f               shr eax, 0x1f
// 005949b8  03c2                 add eax, edx
// 005949ba  8bd3                 mov edx, ebx
// 005949bc  81e200800000         and edx, 0x8000
// 005949c2  743d                 je 0x594a01
// 005949c4  8a8e26010000         mov cl, byte ptr [esi + 0x126]
// 005949ca  80f903               cmp cl, 3
// 005949cd  7507                 jne 0x5949d6
// 005949cf  b820000000           mov eax, 0x20
// 005949d4  eb2b                 jmp 0x594a01
// 005949d6  84c9                 test cl, cl
// 005949d8  7511                 jne 0x5949eb
// 005949da  33c9                 xor ecx, ecx
// 005949dc  83f808               cmp eax, 8
// 005949df  0f9fc1               setg cl
// 005949e2  49                   dec ecx
// 005949e3  83e1f0               and ecx, 0xfffffff0
// 005949e6  83c120               add ecx, 0x20
// 005949e9  eb14                 jmp 0x5949ff
// 005949eb  80f902               cmp cl, 2
// 005949ee  7511                 jne 0x594a01
// 005949f0  33c9                 xor ecx, ecx
// 005949f2  83f820               cmp eax, 0x20
// 005949f5  0f9fc1               setg cl
// 005949f8  49                   dec ecx
// 005949f9  83e1e0               and ecx, 0xffffffe0
// 005949fc  83c140               add ecx, 0x40
// 005949ff  8bc1                 mov eax, ecx
// 00594a01  f7c300400000         test ebx, 0x4000
// 00594a07  7455                 je 0x594a5e
// 00594a09  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 00594a11  7404                 je 0x594a17
// 00594a13  85ff                 test edi, edi
// 00594a15  7536                 jne 0x594a4d
// 00594a17  85d2                 test edx, edx
// 00594a19  7532                 jne 0x594a4d
// 00594a1b  8a8e26010000         mov cl, byte ptr [esi + 0x126]
// 00594a21  80f904               cmp cl, 4
// 00594a24  7427                 je 0x594a4d
// 00594a26  83f808               cmp eax, 8
// 00594a29  7f11                 jg 0x594a3c
// 00594a2b  33c0                 xor eax, eax
// 00594a2d  80f906               cmp cl, 6
// 00594a30  0f94c0               sete al
// 00594a33  8d04c518000000       lea eax, [eax*8 + 0x18]
// 00594a3a  eb22                 jmp 0x594a5e
// 00594a3c  33c0                 xor eax, eax
// 00594a3e  80f906               cmp cl, 6
// 00594a41  0f95c0               setne al
// 00594a44  48                   dec eax
// 00594a45  83e010               and eax, 0x10
// 00594a48  83c030               add eax, 0x30
// 00594a4b  eb11                 jmp 0x594a5e
// 00594a4d  33d2                 xor edx, edx
// 00594a4f  83f810               cmp eax, 0x10
// 00594a52  0f9fc2               setg dl
// 00594a55  4a                   dec edx
// 00594a56  83e2e0               and edx, 0xffffffe0
// 00594a59  83c240               add edx, 0x40
// 00594a5c  8bc2                 mov eax, edx
// 00594a5e  f7c300001000         test ebx, 0x100000
// 00594a64  7411                 je 0x594a77
// 00594a66  0fb64e65             movzx ecx, byte ptr [esi + 0x65]
// 00594a6a  0fb65664             movzx edx, byte ptr [esi + 0x64]
// 00594a6e  0fafca               imul ecx, edx
// 00594a71  3bc8                 cmp ecx, eax
// 00594a73  7e02                 jle 0x594a77
// 00594a75  8bc1                 mov eax, ecx
// 00594a77  8d4d07               lea ecx, [ebp + 7]
// 00594a7a  83e1f8               and ecx, 0xfffffff8
// 00594a7d  83f808               cmp eax, 8
// 00594a80  7c0a                 jl 0x594a8c
// 00594a82  8bd0                 mov edx, eax
// 00594a84  c1ea03               shr edx, 3
// 00594a87  0fafd1               imul edx, ecx
// 00594a8a  eb0b                 jmp 0x594a97
// 00594a8c  0fafc8               imul ecx, eax
// 00594a8f  83c107               add ecx, 7
// 00594a92  c1e903               shr ecx, 3
// 00594a95  8bd1                 mov edx, ecx
// 00594a97  83c007               add eax, 7
// 00594a9a  c1f803               sar eax, 3
// 00594a9d  8d441001             lea eax, [eax + edx + 1]
// 00594aa1  8d7840               lea edi, [eax + 0x40]
// 00594aa4  3bbe80020000         cmp edi, dword ptr [esi + 0x280]
// 00594aaa  762c                 jbe 0x594ad8
// 00594aac  8b8650020000         mov eax, dword ptr [esi + 0x250]
// 00594ab2  50                   push eax
// 00594ab3  56                   push esi
// 00594ab4  e8f7a1ffff           call 0x58ecb0
// 00594ab9  57                   push edi
// 00594aba  56                   push esi
// 00594abb  e890a1ffff           call 0x58ec50
// 00594ac0  83c410               add esp, 0x10
// 00594ac3  898650020000         mov dword ptr [esi + 0x250], eax
// 00594ac9  83c020               add eax, 0x20
// 00594acc  8986ec000000         mov dword ptr [esi + 0xec], eax
// 00594ad2  89be80020000         mov dword ptr [esi + 0x280], edi
// 00594ad8  83bed8000000fe       cmp dword ptr [esi + 0xd8], -2
// 00594adf  760e                 jbe 0x594aef
// 00594ae1  68f0208d00           push 0x8d20f0
// 00594ae6  56                   push esi
// 00594ae7  e87496ffff           call 0x58e160
// 00594aec  83c408               add esp, 8
// 00594aef  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 00594af5  40                   inc eax
// 00594af6  3b8684020000         cmp eax, dword ptr [esi + 0x284]
// 00594afc  7631                 jbe 0x594b2f
// 00594afe  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 00594b04  51                   push ecx
// 00594b05  56                   push esi
// 00594b06  e8a5a1ffff           call 0x58ecb0
// 00594b0b  8b96d8000000         mov edx, dword ptr [esi + 0xd8]
// 00594b11  42                   inc edx
// 00594b12  52                   push edx
// 00594b13  56                   push esi
// 00594b14  e837a1ffff           call 0x58ec50
// 00594b19  8986e8000000         mov dword ptr [esi + 0xe8], eax
// 00594b1f  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 00594b25  83c410               add esp, 0x10
// 00594b28  40                   inc eax
// 00594b29  898684020000         mov dword ptr [esi + 0x284], eax
// 00594b2f  50                   push eax
// 00594b30  8b86e8000000         mov eax, dword ptr [esi + 0xe8]
// 00594b36  6a00                 push 0
// 00594b38  50                   push eax
// 00594b39  56                   push esi
// 00594b3a  e8a1a0ffff           call 0x58ebe0
// 00594b3f  83c410               add esp, 0x10
// 00594b42  834e6c40             or dword ptr [esi + 0x6c], 0x40
// 00594b46  5f                   pop edi
// 00594b47  5e                   pop esi
// 00594b48  5d                   pop ebp
// 00594b49  5b                   pop ebx
// 00594b4a  83c438               add esp, 0x38
// 00594b4d  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_read_start_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
