// from server: 100% by auto
// roc 2010-06 00578160  unit: seg_00570000  size: 798 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00578160
//
// 00578160  83ec38               sub esp, 0x38
// 00578163  53                   push ebx
// 00578164  55                   push ebp
// 00578165  56                   push esi
// 00578166  8b742448             mov esi, dword ptr [esp + 0x48]
// 0057816a  33d2                 xor edx, edx
// 0057816c  b804000000           mov eax, 4
// 00578171  b902000000           mov ecx, 2
// 00578176  57                   push edi
// 00578177  bb01000000           mov ebx, 1
// 0057817c  bf08000000           mov edi, 8
// 00578181  56                   push esi
// 00578182  89542430             mov dword ptr [esp + 0x30], edx
// 00578186  89442434             mov dword ptr [esp + 0x34], eax
// 0057818a  89542438             mov dword ptr [esp + 0x38], edx
// 0057818e  894c243c             mov dword ptr [esp + 0x3c], ecx
// 00578192  89542440             mov dword ptr [esp + 0x40], edx
// 00578196  895c2444             mov dword ptr [esp + 0x44], ebx
// 0057819a  89542448             mov dword ptr [esp + 0x48], edx
// 0057819e  897c2414             mov dword ptr [esp + 0x14], edi
// 005781a2  897c2418             mov dword ptr [esp + 0x18], edi
// 005781a6  8944241c             mov dword ptr [esp + 0x1c], eax
// 005781aa  89442420             mov dword ptr [esp + 0x20], eax
// 005781ae  894c2424             mov dword ptr [esp + 0x24], ecx
// 005781b2  894c2428             mov dword ptr [esp + 0x28], ecx
// 005781b6  895c242c             mov dword ptr [esp + 0x2c], ebx
// 005781ba  895678               mov dword ptr [esi + 0x78], edx
// 005781bd  e88e2effff           call 0x56b050
// 005781c2  83c404               add esp, 4
// 005781c5  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 005781cc  7472                 je 0x578240
// 005781ce  f6467002             test byte ptr [esi + 0x70], 2
// 005781d2  7514                 jne 0x5781e8
// 005781d4  8b86cc000000         mov eax, dword ptr [esi + 0xcc]
// 005781da  83c007               add eax, 7
// 005781dd  c1e803               shr eax, 3
// 005781e0  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 005781e6  eb0c                 jmp 0x5781f4
// 005781e8  8b8ecc000000         mov ecx, dword ptr [esi + 0xcc]
// 005781ee  898ed0000000         mov dword ptr [esi + 0xd0], ecx
// 005781f4  0fb68624010000       movzx eax, byte ptr [esi + 0x124]
// 005781fb  8baec8000000         mov ebp, dword ptr [esi + 0xc8]
// 00578201  03c0                 add eax, eax
// 00578203  03c0                 add eax, eax
// 00578205  8b4c0410             mov ecx, dword ptr [esp + eax + 0x10]
// 00578209  8bd5                 mov edx, ebp
// 0057820b  2b54042c             sub edx, dword ptr [esp + eax + 0x2c]
// 0057820f  8d440aff             lea eax, [edx + ecx - 1]
// 00578213  33d2                 xor edx, edx
// 00578215  f7f1                 div ecx
// 00578217  8a8e29010000         mov cl, byte ptr [esi + 0x129]
// 0057821d  80f908               cmp cl, 8
// 00578220  0fb6c9               movzx ecx, cl
// 00578223  8986e0000000         mov dword ptr [esi + 0xe0], eax
// 00578229  7209                 jb 0x578234
// 0057822b  c1e903               shr ecx, 3
// 0057822e  0fafc8               imul ecx, eax
// 00578231  41                   inc ecx
// 00578232  eb2c                 jmp 0x578260
// 00578234  0fafc8               imul ecx, eax
// 00578237  83c107               add ecx, 7
// 0057823a  c1e903               shr ecx, 3
// 0057823d  41                   inc ecx
// 0057823e  eb20                 jmp 0x578260
// 00578240  8b86cc000000         mov eax, dword ptr [esi + 0xcc]
// 00578246  8baec8000000         mov ebp, dword ptr [esi + 0xc8]
// 0057824c  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 00578252  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 00578258  89aee0000000         mov dword ptr [esi + 0xe0], ebp
// 0057825e  03cb                 add ecx, ebx
// 00578260  8b5e70               mov ebx, dword ptr [esi + 0x70]
// 00578263  0fb68629010000       movzx eax, byte ptr [esi + 0x129]
// 0057826a  898edc000000         mov dword ptr [esi + 0xdc], ecx
// 00578270  f6c304               test bl, 4
// 00578273  740b                 je 0x578280
// 00578275  80be2701000008       cmp byte ptr [esi + 0x127], 8
// 0057827c  7302                 jae 0x578280
// 0057827e  8bc7                 mov eax, edi
// 00578280  8bfb                 mov edi, ebx
// 00578282  81e700100000         and edi, 0x1000
// 00578288  7460                 je 0x5782ea
// 0057828a  8a8e26010000         mov cl, byte ptr [esi + 0x126]
// 00578290  80f903               cmp cl, 3
// 00578293  7515                 jne 0x5782aa
// 00578295  33c0                 xor eax, eax
// 00578297  6639861a010000       cmp word ptr [esi + 0x11a], ax
// 0057829e  0f95c0               setne al
// 005782a1  8d04c518000000       lea eax, [eax*8 + 0x18]
// 005782a8  eb40                 jmp 0x5782ea
// 005782aa  84c9                 test cl, cl
// 005782ac  7518                 jne 0x5782c6
// 005782ae  83f808               cmp eax, 8
// 005782b1  7d05                 jge 0x5782b8
// 005782b3  b808000000           mov eax, 8
// 005782b8  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 005782c0  7428                 je 0x5782ea
// 005782c2  03c0                 add eax, eax
// 005782c4  eb24                 jmp 0x5782ea
// 005782c6  80f902               cmp cl, 2
// 005782c9  751f                 jne 0x5782ea
// 005782cb  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 005782d3  7415                 je 0x5782ea
// 005782d5  8d0c8500000000       lea ecx, [eax*4]
// 005782dc  b856555555           mov eax, 0x55555556
// 005782e1  f7e9                 imul ecx
// 005782e3  8bc2                 mov eax, edx
// 005782e5  c1e81f               shr eax, 0x1f
// 005782e8  03c2                 add eax, edx
// 005782ea  8bd3                 mov edx, ebx
// 005782ec  81e200800000         and edx, 0x8000
// 005782f2  743d                 je 0x578331
// 005782f4  8a8e26010000         mov cl, byte ptr [esi + 0x126]
// 005782fa  80f903               cmp cl, 3
// 005782fd  7507                 jne 0x578306
// 005782ff  b820000000           mov eax, 0x20
// 00578304  eb2b                 jmp 0x578331
// 00578306  84c9                 test cl, cl
// 00578308  7511                 jne 0x57831b
// 0057830a  33c9                 xor ecx, ecx
// 0057830c  83f808               cmp eax, 8
// 0057830f  0f9fc1               setg cl
// 00578312  49                   dec ecx
// 00578313  83e1f0               and ecx, 0xfffffff0
// 00578316  83c120               add ecx, 0x20
// 00578319  eb14                 jmp 0x57832f
// 0057831b  80f902               cmp cl, 2
// 0057831e  7511                 jne 0x578331
// 00578320  33c9                 xor ecx, ecx
// 00578322  83f820               cmp eax, 0x20
// 00578325  0f9fc1               setg cl
// 00578328  49                   dec ecx
// 00578329  83e1e0               and ecx, 0xffffffe0
// 0057832c  83c140               add ecx, 0x40
// 0057832f  8bc1                 mov eax, ecx
// 00578331  f7c300400000         test ebx, 0x4000
// 00578337  7455                 je 0x57838e
// 00578339  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 00578341  7404                 je 0x578347
// 00578343  85ff                 test edi, edi
// 00578345  7536                 jne 0x57837d
// 00578347  85d2                 test edx, edx
// 00578349  7532                 jne 0x57837d
// 0057834b  8a8e26010000         mov cl, byte ptr [esi + 0x126]
// 00578351  80f904               cmp cl, 4
// 00578354  7427                 je 0x57837d
// 00578356  83f808               cmp eax, 8
// 00578359  7f11                 jg 0x57836c
// 0057835b  33c0                 xor eax, eax
// 0057835d  80f906               cmp cl, 6
// 00578360  0f94c0               sete al
// 00578363  8d04c518000000       lea eax, [eax*8 + 0x18]
// 0057836a  eb22                 jmp 0x57838e
// 0057836c  33c0                 xor eax, eax
// 0057836e  80f906               cmp cl, 6
// 00578371  0f95c0               setne al
// 00578374  48                   dec eax
// 00578375  83e010               and eax, 0x10
// 00578378  83c030               add eax, 0x30
// 0057837b  eb11                 jmp 0x57838e
// 0057837d  33d2                 xor edx, edx
// 0057837f  83f810               cmp eax, 0x10
// 00578382  0f9fc2               setg dl
// 00578385  4a                   dec edx
// 00578386  83e2e0               and edx, 0xffffffe0
// 00578389  83c240               add edx, 0x40
// 0057838c  8bc2                 mov eax, edx
// 0057838e  f7c300001000         test ebx, 0x100000
// 00578394  7411                 je 0x5783a7
// 00578396  0fb64e65             movzx ecx, byte ptr [esi + 0x65]
// 0057839a  0fb65664             movzx edx, byte ptr [esi + 0x64]
// 0057839e  0fafca               imul ecx, edx
// 005783a1  3bc8                 cmp ecx, eax
// 005783a3  7e02                 jle 0x5783a7
// 005783a5  8bc1                 mov eax, ecx
// 005783a7  8d4d07               lea ecx, [ebp + 7]
// 005783aa  83e1f8               and ecx, 0xfffffff8
// 005783ad  83f808               cmp eax, 8
// 005783b0  7c0a                 jl 0x5783bc
// 005783b2  8bd0                 mov edx, eax
// 005783b4  c1ea03               shr edx, 3
// 005783b7  0fafd1               imul edx, ecx
// 005783ba  eb0b                 jmp 0x5783c7
// 005783bc  0fafc8               imul ecx, eax
// 005783bf  83c107               add ecx, 7
// 005783c2  c1e903               shr ecx, 3
// 005783c5  8bd1                 mov edx, ecx
// 005783c7  83c007               add eax, 7
// 005783ca  c1f803               sar eax, 3
// 005783cd  8d441001             lea eax, [eax + edx + 1]
// 005783d1  8d7840               lea edi, [eax + 0x40]
// 005783d4  3bbe80020000         cmp edi, dword ptr [esi + 0x280]
// 005783da  762c                 jbe 0x578408
// 005783dc  8b8650020000         mov eax, dword ptr [esi + 0x250]
// 005783e2  50                   push eax
// 005783e3  56                   push esi
// 005783e4  e817a2ffff           call 0x572600
// 005783e9  57                   push edi
// 005783ea  56                   push esi
// 005783eb  e8b0a1ffff           call 0x5725a0
// 005783f0  83c410               add esp, 0x10
// 005783f3  898650020000         mov dword ptr [esi + 0x250], eax
// 005783f9  83c020               add eax, 0x20
// 005783fc  8986ec000000         mov dword ptr [esi + 0xec], eax
// 00578402  89be80020000         mov dword ptr [esi + 0x280], edi
// 00578408  83bed8000000fe       cmp dword ptr [esi + 0xd8], -2
// 0057840f  760e                 jbe 0x57841f
// 00578411  68f86ca200           push 0xa26cf8
// 00578416  56                   push esi
// 00578417  e89496ffff           call 0x571ab0
// 0057841c  83c408               add esp, 8
// 0057841f  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 00578425  40                   inc eax
// 00578426  3b8684020000         cmp eax, dword ptr [esi + 0x284]
// 0057842c  7631                 jbe 0x57845f
// 0057842e  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 00578434  51                   push ecx
// 00578435  56                   push esi
// 00578436  e8c5a1ffff           call 0x572600
// 0057843b  8b96d8000000         mov edx, dword ptr [esi + 0xd8]
// 00578441  42                   inc edx
// 00578442  52                   push edx
// 00578443  56                   push esi
// 00578444  e857a1ffff           call 0x5725a0
// 00578449  8986e8000000         mov dword ptr [esi + 0xe8], eax
// 0057844f  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 00578455  83c410               add esp, 0x10
// 00578458  40                   inc eax
// 00578459  898684020000         mov dword ptr [esi + 0x284], eax
// 0057845f  50                   push eax
// 00578460  8b86e8000000         mov eax, dword ptr [esi + 0xe8]
// 00578466  6a00                 push 0
// 00578468  50                   push eax
// 00578469  56                   push esi
// 0057846a  e8c1a0ffff           call 0x572530
// 0057846f  83c410               add esp, 0x10
// 00578472  834e6c40             or dword ptr [esi + 0x6c], 0x40
// 00578476  5f                   pop edi
// 00578477  5e                   pop esi
// 00578478  5d                   pop ebp
// 00578479  5b                   pop ebx
// 0057847a  83c438               add esp, 0x38
// 0057847d  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_read_start_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
