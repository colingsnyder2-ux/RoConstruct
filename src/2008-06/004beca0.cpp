// from server: 100% by auto
// roc 2008-06 004beca0  unit: ProfiledRakPeer  size: 949 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004beca0
//
// 004beca0  55                   push ebp
// 004beca1  8bec                 mov ebp, esp
// 004beca3  83ec28               sub esp, 0x28
// 004beca6  53                   push ebx
// 004beca7  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 004becaa  56                   push esi
// 004becab  8b750c               mov esi, dword ptr [ebp + 0xc]
// 004becae  57                   push edi
// 004becaf  33c0                 xor eax, eax
// 004becb1  b908000000           mov ecx, 8
// 004becb6  8d7dd8               lea edi, [ebp - 0x28]
// 004becb9  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004becbb  f745f400000080       test dword ptr [ebp - 0xc], 0x80000000
// 004becc2  8b7508               mov esi, dword ptr [ebp + 8]
// 004becc5  b908000000           mov ecx, 8
// 004becca  8bfb                 mov edi, ebx
// 004beccc  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004becce  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 004becd1  8907                 mov dword ptr [edi], eax
// 004becd3  894704               mov dword ptr [edi + 4], eax
// 004becd6  894708               mov dword ptr [edi + 8], eax
// 004becd9  89470c               mov dword ptr [edi + 0xc], eax
// 004becdc  894710               mov dword ptr [edi + 0x10], eax
// 004becdf  894714               mov dword ptr [edi + 0x14], eax
// 004bece2  894718               mov dword ptr [edi + 0x18], eax
// 004bece5  89471c               mov dword ptr [edi + 0x1c], eax
// 004bece8  c7450c01000000       mov dword ptr [ebp + 0xc], 1
// 004becef  0f85c5010000         jne 0x4beeba
// 004becf5  8d45d8               lea eax, [ebp - 0x28]
// 004becf8  50                   push eax
// 004becf9  53                   push ebx
// 004becfa  e8c1dbffff           call 0x4bc8c0
// 004becff  83c408               add esp, 8
// 004bed02  84c0                 test al, al
// 004bed04  0f84b0010000         je 0x4beeba
// 004bed0a  b807000000           mov eax, 7
// 004bed0f  90                   nop 
// 004bed10  833c8300             cmp dword ptr [ebx + eax*4], 0
// 004bed14  7505                 jne 0x4bed1b
// 004bed16  83e801               sub eax, 1
// 004bed19  79f5                 jns 0x4bed10
// 004bed1b  8bc8                 mov ecx, eax
// 004bed1d  85c0                 test eax, eax
// 004bed1f  7c28                 jl 0x4bed49
// 004bed21  837c8dd800           cmp dword ptr [ebp + ecx*4 - 0x28], 0
// 004bed26  7505                 jne 0x4bed2d
// 004bed28  83e901               sub ecx, 1
// 004bed2b  79f4                 jns 0x4bed21
// 004bed2d  3bc1                 cmp eax, ecx
// 004bed2f  7418                 je 0x4bed49
// 004bed31  2bc1                 sub eax, ecx
// 004bed33  c1e005               shl eax, 5
// 004bed36  8bf0                 mov esi, eax
// 004bed38  8d4dd8               lea ecx, [ebp - 0x28]
// 004bed3b  56                   push esi
// 004bed3c  51                   push ecx
// 004bed3d  e89edaffff           call 0x4bc7e0
// 004bed42  83c408               add esp, 8
// 004bed45  46                   inc esi
// 004bed46  89750c               mov dword ptr [ebp + 0xc], esi
// 004bed49  f745f400000080       test dword ptr [ebp - 0xc], 0x80000000
// 004bed50  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 004bed53  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004bed56  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 004bed59  8b75e4               mov esi, dword ptr [ebp - 0x1c]
// 004bed5c  0f85ae000000         jne 0x4bee10
// 004bed62  bb07000000           mov ebx, 7
// 004bed67  895d08               mov dword ptr [ebp + 8], ebx
// 004bed6a  8d9b00000000         lea ebx, [ebx]
// 004bed70  8b7d14               mov edi, dword ptr [ebp + 0x14]
// 004bed73  8b3c9f               mov edi, dword ptr [edi + ebx*4]
// 004bed76  8b5c9dd8             mov ebx, dword ptr [ebp + ebx*4 - 0x28]
// 004bed7a  3bfb                 cmp edi, ebx
// 004bed7c  7713                 ja 0x4bed91
// 004bed7e  0f8287000000         jb 0x4bee0b
// 004bed84  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004bed87  83eb01               sub ebx, 1
// 004bed8a  895d08               mov dword ptr [ebp + 8], ebx
// 004bed8d  79e1                 jns 0x4bed70
// 004bed8f  eb7a                 jmp 0x4bee0b
// 004bed91  8b5dd8               mov ebx, dword ptr [ebp - 0x28]
// 004bed94  8bfb                 mov edi, ebx
// 004bed96  03db                 add ebx, ebx
// 004bed98  895dd8               mov dword ptr [ebp - 0x28], ebx
// 004bed9b  8b5ddc               mov ebx, dword ptr [ebp - 0x24]
// 004bed9e  c1ef1f               shr edi, 0x1f
// 004beda1  895d08               mov dword ptr [ebp + 8], ebx
// 004beda4  03db                 add ebx, ebx
// 004beda6  0bdf                 or ebx, edi
// 004beda8  8b7d08               mov edi, dword ptr [ebp + 8]
// 004bedab  895ddc               mov dword ptr [ebp - 0x24], ebx
// 004bedae  8b5de0               mov ebx, dword ptr [ebp - 0x20]
// 004bedb1  c1ef1f               shr edi, 0x1f
// 004bedb4  895d08               mov dword ptr [ebp + 8], ebx
// 004bedb7  03db                 add ebx, ebx
// 004bedb9  0bdf                 or ebx, edi
// 004bedbb  8b7d08               mov edi, dword ptr [ebp + 8]
// 004bedbe  c1ef1f               shr edi, 0x1f
// 004bedc1  ff450c               inc dword ptr [ebp + 0xc]
// 004bedc4  895de0               mov dword ptr [ebp - 0x20], ebx
// 004bedc7  8bdf                 mov ebx, edi
// 004bedc9  8bfe                 mov edi, esi
// 004bedcb  c1ef1f               shr edi, 0x1f
// 004bedce  03f6                 add esi, esi
// 004bedd0  0bf3                 or esi, ebx
// 004bedd2  8bda                 mov ebx, edx
// 004bedd4  03d2                 add edx, edx
// 004bedd6  0bd7                 or edx, edi
// 004bedd8  c1eb1f               shr ebx, 0x1f
// 004beddb  8bf9                 mov edi, ecx
// 004beddd  03c9                 add ecx, ecx
// 004beddf  0bcb                 or ecx, ebx
// 004bede1  c1ef1f               shr edi, 0x1f
// 004bede4  8bd8                 mov ebx, eax
// 004bede6  03c0                 add eax, eax
// 004bede8  0bc7                 or eax, edi
// 004bedea  8b7df4               mov edi, dword ptr [ebp - 0xc]
// 004beded  c1eb1f               shr ebx, 0x1f
// 004bedf0  03ff                 add edi, edi
// 004bedf2  0bfb                 or edi, ebx
// 004bedf4  8975e4               mov dword ptr [ebp - 0x1c], esi
// 004bedf7  8955e8               mov dword ptr [ebp - 0x18], edx
// 004bedfa  894dec               mov dword ptr [ebp - 0x14], ecx
// 004bedfd  8945f0               mov dword ptr [ebp - 0x10], eax
// 004bee00  897df4               mov dword ptr [ebp - 0xc], edi
// 004bee03  85ff                 test edi, edi
// 004bee05  0f8957ffffff         jns 0x4bed62
// 004bee0b  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 004bee0e  8bff                 mov edi, edi
// 004bee10  bf07000000           mov edi, 7
// 004bee15  897d08               mov dword ptr [ebp + 8], edi
// 004bee18  eb06                 jmp 0x4bee20
// 004bee1a  8d9b00000000         lea ebx, [ebx]
// 004bee20  8b1cbb               mov ebx, dword ptr [ebx + edi*4]
// 004bee23  8b7cbdd8             mov edi, dword ptr [ebp + edi*4 - 0x28]
// 004bee27  3bfb                 cmp edi, ebx
// 004bee29  771a                 ja 0x4bee45
// 004bee2b  0f82d0000000         jb 0x4bef01
// 004bee31  8b7d08               mov edi, dword ptr [ebp + 8]
// 004bee34  83ef01               sub edi, 1
// 004bee37  897d08               mov dword ptr [ebp + 8], edi
// 004bee3a  0f88c1000000         js 0x4bef01
// 004bee40  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 004bee43  ebdb                 jmp 0x4bee20
// 004bee45  8b5df4               mov ebx, dword ptr [ebp - 0xc]
// 004bee48  8bfb                 mov edi, ebx
// 004bee4a  d1eb                 shr ebx, 1
// 004bee4c  895df4               mov dword ptr [ebp - 0xc], ebx
// 004bee4f  c1e71f               shl edi, 0x1f
// 004bee52  8bd8                 mov ebx, eax
// 004bee54  c1e31f               shl ebx, 0x1f
// 004bee57  d1e8                 shr eax, 1
// 004bee59  0bc7                 or eax, edi
// 004bee5b  8bf9                 mov edi, ecx
// 004bee5d  c1e71f               shl edi, 0x1f
// 004bee60  d1e9                 shr ecx, 1
// 004bee62  0bcb                 or ecx, ebx
// 004bee64  8bda                 mov ebx, edx
// 004bee66  c1e31f               shl ebx, 0x1f
// 004bee69  d1ea                 shr edx, 1
// 004bee6b  0bd7                 or edx, edi
// 004bee6d  8bfe                 mov edi, esi
// 004bee6f  d1ee                 shr esi, 1
// 004bee71  0bf3                 or esi, ebx
// 004bee73  8b5de0               mov ebx, dword ptr [ebp - 0x20]
// 004bee76  895d08               mov dword ptr [ebp + 8], ebx
// 004bee79  d1eb                 shr ebx, 1
// 004bee7b  c1e71f               shl edi, 0x1f
// 004bee7e  0bdf                 or ebx, edi
// 004bee80  8b7d08               mov edi, dword ptr [ebp + 8]
// 004bee83  895de0               mov dword ptr [ebp - 0x20], ebx
// 004bee86  8b5ddc               mov ebx, dword ptr [ebp - 0x24]
// 004bee89  895d08               mov dword ptr [ebp + 8], ebx
// 004bee8c  d1eb                 shr ebx, 1
// 004bee8e  c1e71f               shl edi, 0x1f
// 004bee91  0bdf                 or ebx, edi
// 004bee93  8b7d08               mov edi, dword ptr [ebp + 8]
// 004bee96  895ddc               mov dword ptr [ebp - 0x24], ebx
// 004bee99  8b5dd8               mov ebx, dword ptr [ebp - 0x28]
// 004bee9c  c1e71f               shl edi, 0x1f
// 004bee9f  d1eb                 shr ebx, 1
// 004beea1  0bdf                 or ebx, edi
// 004beea3  ff4d0c               dec dword ptr [ebp + 0xc]
// 004beea6  8945f0               mov dword ptr [ebp - 0x10], eax
// 004beea9  894dec               mov dword ptr [ebp - 0x14], ecx
// 004beeac  8955e8               mov dword ptr [ebp - 0x18], edx
// 004beeaf  8975e4               mov dword ptr [ebp - 0x1c], esi
// 004beeb2  895dd8               mov dword ptr [ebp - 0x28], ebx
// 004beeb5  e951ffffff           jmp 0x4bee0b
// 004beeba  b807000000           mov eax, 7
// 004beebf  90                   nop 
// 004beec0  8b0c83               mov ecx, dword ptr [ebx + eax*4]
// 004beec3  8b5485d8             mov edx, dword ptr [ebp + eax*4 - 0x28]
// 004beec7  3bd1                 cmp edx, ecx
// 004beec9  7715                 ja 0x4beee0
// 004beecb  7205                 jb 0x4beed2
// 004beecd  83e801               sub eax, 1
// 004beed0  79ee                 jns 0x4beec0
// 004beed2  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 004beed5  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004beed8  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 004beedb  8b75e4               mov esi, dword ptr [ebp - 0x1c]
// 004beede  eb24                 jmp 0x4bef04
// 004beee0  8d55d8               lea edx, [ebp - 0x28]
// 004beee3  52                   push edx
// 004beee4  e877dbffff           call 0x4bca60
// 004beee9  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 004beeec  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004beeef  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 004beef2  8b75e4               mov esi, dword ptr [ebp - 0x1c]
// 004beef5  83c404               add esp, 4
// 004beef8  c7450c00000000       mov dword ptr [ebp + 0xc], 0
// 004beeff  eb03                 jmp 0x4bef04
// 004bef01  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 004bef04  837d0c00             cmp dword ptr [ebp + 0xc], 0
// 004bef08  c7450800000000       mov dword ptr [ebp + 8], 0
// 004bef0f  0f842c010000         je 0x4bf041
// 004bef15  bf01000000           mov edi, 1
// 004bef1a  297d0c               sub dword ptr [ebp + 0xc], edi
// 004bef1d  017d08               add dword ptr [ebp + 8], edi
// 004bef20  bf07000000           mov edi, 7
// 004bef25  897dfc               mov dword ptr [ebp - 4], edi
// 004bef28  eb06                 jmp 0x4bef30
// 004bef2a  8d9b00000000         lea ebx, [ebx]
// 004bef30  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 004bef33  8b1cbb               mov ebx, dword ptr [ebx + edi*4]
// 004bef36  8b7cbdd8             mov edi, dword ptr [ebp + edi*4 - 0x28]
// 004bef3a  3bfb                 cmp edi, ebx
// 004bef3c  0f8785000000         ja 0x4befc7
// 004bef42  720b                 jb 0x4bef4f
// 004bef44  8b7dfc               mov edi, dword ptr [ebp - 4]
// 004bef47  83ef01               sub edi, 1
// 004bef4a  897dfc               mov dword ptr [ebp - 4], edi
// 004bef4d  79e1                 jns 0x4bef30
// 004bef4f  8d45d8               lea eax, [ebp - 0x28]
// 004bef52  8945f8               mov dword ptr [ebp - 8], eax
// 004bef55  c745fc01000000       mov dword ptr [ebp - 4], 1
// 004bef5c  8b75f8               mov esi, dword ptr [ebp - 8]
// 004bef5f  8b7d14               mov edi, dword ptr [ebp + 0x14]
// 004bef62  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004bef65  8b06                 mov eax, dword ptr [esi]
// 004bef67  33d2                 xor edx, edx
// 004bef69  2907                 sub dword ptr [edi], eax
// 004bef6b  8b4604               mov eax, dword ptr [esi + 4]
// 004bef6e  194704               sbb dword ptr [edi + 4], eax
// 004bef71  8b4608               mov eax, dword ptr [esi + 8]
// 004bef74  194708               sbb dword ptr [edi + 8], eax
// 004bef77  8b460c               mov eax, dword ptr [esi + 0xc]
// 004bef7a  19470c               sbb dword ptr [edi + 0xc], eax
// 004bef7d  e322                 jecxz 0x4befa1
// 004bef7f  42                   inc edx
// 004bef80  42                   inc edx
// 004bef81  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004bef84  1904d7               sbb dword ptr [edi + edx*8], eax
// 004bef87  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004bef8b  1944d704             sbb dword ptr [edi + edx*8 + 4], eax
// 004bef8f  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004bef93  1944d708             sbb dword ptr [edi + edx*8 + 8], eax
// 004bef97  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004bef9b  1944d70c             sbb dword ptr [edi + edx*8 + 0xc], eax
// 004bef9f  e2de                 loop 0x4bef7f
// 004befa1  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004befa4  8b7510               mov esi, dword ptr [ebp + 0x10]
// 004befa7  51                   push ecx
// 004befa8  56                   push esi
// 004befa9  e832d8ffff           call 0x4bc7e0
// 004befae  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 004befb1  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004befb4  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 004befb7  83c408               add esp, 8
// 004befba  830e01               or dword ptr [esi], 1
// 004befbd  8b75e4               mov esi, dword ptr [ebp - 0x1c]
// 004befc0  c7450800000000       mov dword ptr [ebp + 8], 0
// 004befc7  8b5df4               mov ebx, dword ptr [ebp - 0xc]
// 004befca  8bfb                 mov edi, ebx
// 004befcc  d1eb                 shr ebx, 1
// 004befce  895df4               mov dword ptr [ebp - 0xc], ebx
// 004befd1  c1e71f               shl edi, 0x1f
// 004befd4  8bd8                 mov ebx, eax
// 004befd6  c1e31f               shl ebx, 0x1f
// 004befd9  d1e8                 shr eax, 1
// 004befdb  0bc7                 or eax, edi
// 004befdd  8bf9                 mov edi, ecx
// 004befdf  c1e71f               shl edi, 0x1f
// 004befe2  d1e9                 shr ecx, 1
// 004befe4  0bcb                 or ecx, ebx
// 004befe6  8bda                 mov ebx, edx
// 004befe8  c1e31f               shl ebx, 0x1f
// 004befeb  d1ea                 shr edx, 1
// 004befed  0bd7                 or edx, edi
// 004befef  8bfe                 mov edi, esi
// 004beff1  d1ee                 shr esi, 1
// 004beff3  0bf3                 or esi, ebx
// 004beff5  8b5de0               mov ebx, dword ptr [ebp - 0x20]
// 004beff8  895dfc               mov dword ptr [ebp - 4], ebx
// 004beffb  d1eb                 shr ebx, 1
// 004beffd  c1e71f               shl edi, 0x1f
// 004bf000  0bdf                 or ebx, edi
// 004bf002  8b7dfc               mov edi, dword ptr [ebp - 4]
// 004bf005  895de0               mov dword ptr [ebp - 0x20], ebx
// 004bf008  8b5ddc               mov ebx, dword ptr [ebp - 0x24]
// 004bf00b  895dfc               mov dword ptr [ebp - 4], ebx
// 004bf00e  d1eb                 shr ebx, 1
// 004bf010  c1e71f               shl edi, 0x1f
// 004bf013  0bdf                 or ebx, edi
// 004bf015  8b7dfc               mov edi, dword ptr [ebp - 4]
// 004bf018  895ddc               mov dword ptr [ebp - 0x24], ebx
// 004bf01b  8b5dd8               mov ebx, dword ptr [ebp - 0x28]
// 004bf01e  c1e71f               shl edi, 0x1f
// 004bf021  d1eb                 shr ebx, 1
// 004bf023  0bdf                 or ebx, edi
// 004bf025  837d0c00             cmp dword ptr [ebp + 0xc], 0
// 004bf029  8945f0               mov dword ptr [ebp - 0x10], eax
// 004bf02c  894dec               mov dword ptr [ebp - 0x14], ecx
// 004bf02f  8955e8               mov dword ptr [ebp - 0x18], edx
// 004bf032  8975e4               mov dword ptr [ebp - 0x1c], esi
// 004bf035  895dd8               mov dword ptr [ebp - 0x28], ebx
// 004bf038  0f85d7feffff         jne 0x4bef15
// 004bf03e  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 004bf041  8b5508               mov edx, dword ptr [ebp + 8]
// 004bf044  52                   push edx
// 004bf045  57                   push edi
// 004bf046  e895d7ffff           call 0x4bc7e0
// 004bf04b  83c408               add esp, 8
// 004bf04e  5f                   pop edi
// 004bf04f  5e                   pop esi
// 004bf050  5b                   pop ebx
// 004bf051  8be5                 mov esp, ebp
// 004bf053  5d                   pop ebp
// 004bf054  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$udivide@$$BY07I@big@@YAXAAY07I000@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
