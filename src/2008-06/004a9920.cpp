// from server: 100% by auto
// roc 2008-06 004a9920  unit: seg_004a0000  size: 191 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a9920
//
// 004a9920  83ec24               sub esp, 0x24
// 004a9923  55                   push ebp
// 004a9924  57                   push edi
// 004a9925  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 004a9929  8be9                 mov ebp, ecx
// 004a992b  8a0f                 mov cl, byte ptr [edi]
// 004a992d  33c0                 xor eax, eax
// 004a992f  84c9                 test cl, cl
// 004a9931  7424                 je 0x4a9957
// 004a9933  56                   push esi
// 004a9934  8d742418             lea esi, [esp + 0x18]
// 004a9938  8bd7                 mov edx, edi
// 004a993a  2bf7                 sub esi, edi
// 004a993c  8d642400             lea esp, [esp]
// 004a9940  80f93a               cmp cl, 0x3a
// 004a9943  7411                 je 0x4a9956
// 004a9945  83f816               cmp eax, 0x16
// 004a9948  7d0c                 jge 0x4a9956
// 004a994a  880c16               mov byte ptr [esi + edx], cl
// 004a994d  8a4a01               mov cl, byte ptr [edx + 1]
// 004a9950  42                   inc edx
// 004a9951  40                   inc eax
// 004a9952  84c9                 test cl, cl
// 004a9954  75ea                 jne 0x4a9940
// 004a9956  5e                   pop esi
// 004a9957  803c3800             cmp byte ptr [eax + edi], 0
// 004a995b  c644041400           mov byte ptr [esp + eax + 0x14], 0
// 004a9960  c644240800           mov byte ptr [esp + 8], 0
// 004a9965  7426                 je 0x4a998d
// 004a9967  807c380100           cmp byte ptr [eax + edi + 1], 0
// 004a996c  741f                 je 0x4a998d
// 004a996e  40                   inc eax
// 004a996f  33c9                 xor ecx, ecx
// 004a9971  8a1438               mov dl, byte ptr [eax + edi]
// 004a9974  84d2                 test dl, dl
// 004a9976  7410                 je 0x4a9988
// 004a9978  83f820               cmp eax, 0x20
// 004a997b  7d0b                 jge 0x4a9988
// 004a997d  88540c08             mov byte ptr [esp + ecx + 8], dl
// 004a9981  41                   inc ecx
// 004a9982  40                   inc eax
// 004a9983  83f90a               cmp ecx, 0xa
// 004a9986  7ce9                 jl 0x4a9971
// 004a9988  c6440c0800           mov byte ptr [esp + ecx + 8], 0
// 004a998d  6a09                 push 9
// 004a998f  686c318200           push 0x82316c
// 004a9994  57                   push edi
// 004a9995  ff1530268000         call dword ptr [0x802630]
// 004a999b  83c40c               add esp, 0xc
// 004a999e  85c0                 test eax, eax
// 004a99a0  7507                 jne 0x4a99a9
// 004a99a2  68e82c8200           push 0x822ce8
// 004a99a7  eb0c                 jmp 0x4a99b5
// 004a99a9  807c241400           cmp byte ptr [esp + 0x14], 0
// 004a99ae  740e                 je 0x4a99be
// 004a99b0  8d442414             lea eax, [esp + 0x14]
// 004a99b4  50                   push eax
// 004a99b5  ff15bc2e8000         call dword ptr [0x802ebc]
// 004a99bb  894500               mov dword ptr [ebp], eax
// 004a99be  807c240800           cmp byte ptr [esp + 8], 0
// 004a99c3  7412                 je 0x4a99d7
// 004a99c5  8d4c2408             lea ecx, [esp + 8]
// 004a99c9  51                   push ecx
// 004a99ca  ff1568288000         call dword ptr [0x802868]
// 004a99d0  83c404               add esp, 4
// 004a99d3  66894504             mov word ptr [ebp + 4], ax
// 004a99d7  5f                   pop edi
// 004a99d8  5d                   pop ebp
// 004a99d9  83c424               add esp, 0x24
// 004a99dc  c20400               ret 4
// library openrbx-raknet/RakNetTypes.cpp (function ?SetBinaryAddress@SystemAddress@@QAEXPBD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet RakNetTypes.cpp
