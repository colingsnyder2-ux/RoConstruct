// from server: 100% by auto
// roc 2011-06 0055d7b0  unit: seg_00550000  size: 4256 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055d7b0
//
// 0055d7b0  83ec10               sub esp, 0x10
// 0055d7b3  837c242000           cmp dword ptr [esp + 0x20], 0
// 0055d7b8  8b442414             mov eax, dword ptr [esp + 0x14]
// 0055d7bc  8b08                 mov ecx, dword ptr [eax]
// 0055d7be  890c24               mov dword ptr [esp], ecx
// 0055d7c1  0f8440100000         je 0x55e807
// 0055d7c7  8a4008               mov al, byte ptr [eax + 8]
// 0055d7ca  55                   push ebp
// 0055d7cb  a804                 test al, 4
// 0055d7cd  7416                 je 0x55d7e5
// 0055d7cf  3c03                 cmp al, 3
// 0055d7d1  0f842f100000         je 0x55e806
// 0055d7d7  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0055d7db  85ed                 test ebp, ebp
// 0055d7dd  0f8423100000         je 0x55e806
// 0055d7e3  eb04                 jmp 0x55d7e9
// 0055d7e5  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0055d7e9  0fb6c0               movzx eax, al
// 0055d7ec  83f806               cmp eax, 6
// 0055d7ef  0f87ce0f0000         ja 0x55e7c3
// 0055d7f5  53                   push ebx
// 0055d7f6  56                   push esi
// 0055d7f7  57                   push edi
// 0055d7f8  ff24850ce85500       jmp dword ptr [eax*4 + 0x55e80c]
// 0055d7ff  8b542424             mov edx, dword ptr [esp + 0x24]
// 0055d803  0fb64209             movzx eax, byte ptr [edx + 9]
// 0055d807  48                   dec eax
// 0055d808  83f80f               cmp eax, 0xf
// 0055d80b  0f87af0f0000         ja 0x55e7c0
// 0055d811  0fb68040e85500       movzx eax, byte ptr [eax + 0x55e840]
// 0055d818  ff248528e85500       jmp dword ptr [eax*4 + 0x55e828]
// 0055d81f  8b742428             mov esi, dword ptr [esp + 0x28]
// 0055d823  ba07000000           mov edx, 7
// 0055d828  85c9                 test ecx, ecx
// 0055d82a  0f86900f0000         jbe 0x55e7c0
// 0055d830  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0055d834  8be9                 mov ebp, ecx
// 0055d836  8a1e                 mov bl, byte ptr [esi]
// 0055d838  8ac3                 mov al, bl
// 0055d83a  8aca                 mov cl, dl
// 0055d83c  d2e8                 shr al, cl
// 0055d83e  2401                 and al, 1
// 0055d840  660fb6c8             movzx cx, al
// 0055d844  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0055d848  663b4808             cmp cx, word ptr [eax + 8]
// 0055d84c  751d                 jne 0x55d86b
// 0055d84e  b907000000           mov ecx, 7
// 0055d853  2bca                 sub ecx, edx
// 0055d855  b87f7f0000           mov eax, 0x7f7f
// 0055d85a  d3f8                 sar eax, cl
// 0055d85c  8bca                 mov ecx, edx
// 0055d85e  22c3                 and al, bl
// 0055d860  8806                 mov byte ptr [esi], al
// 0055d862  8a5f08               mov bl, byte ptr [edi + 8]
// 0055d865  d2e3                 shl bl, cl
// 0055d867  0ad8                 or bl, al
// 0055d869  881e                 mov byte ptr [esi], bl
// 0055d86b  85d2                 test edx, edx
// 0055d86d  7508                 jne 0x55d877
// 0055d86f  ba07000000           mov edx, 7
// 0055d874  46                   inc esi
// 0055d875  eb01                 jmp 0x55d878
// 0055d877  4a                   dec edx
// 0055d878  83ed01               sub ebp, 1
// 0055d87b  75b9                 jne 0x55d836
// 0055d87d  e93e0f0000           jmp 0x55e7c0
// 0055d882  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 0055d886  8b742428             mov esi, dword ptr [esp + 0x28]
// 0055d88a  ba06000000           mov edx, 6
// 0055d88f  85ff                 test edi, edi
// 0055d891  0f8498000000         je 0x55d92f
// 0055d897  85c9                 test ecx, ecx
// 0055d899  0f86210f0000         jbe 0x55e7c0
// 0055d89f  894c2418             mov dword ptr [esp + 0x18], ecx
// 0055d8a3  8a1e                 mov bl, byte ptr [esi]
// 0055d8a5  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0055d8a9  8aca                 mov cl, dl
// 0055d8ab  8ac3                 mov al, bl
// 0055d8ad  d2e8                 shr al, cl
// 0055d8af  2403                 and al, 3
// 0055d8b1  660fb6c8             movzx cx, al
// 0055d8b5  663b4d08             cmp cx, word ptr [ebp + 8]
// 0055d8b9  751f                 jne 0x55d8da
// 0055d8bb  b906000000           mov ecx, 6
// 0055d8c0  2bca                 sub ecx, edx
// 0055d8c2  b83f3f0000           mov eax, 0x3f3f
// 0055d8c7  d3f8                 sar eax, cl
// 0055d8c9  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0055d8cd  22c3                 and al, bl
// 0055d8cf  8806                 mov byte ptr [esi], al
// 0055d8d1  8a5908               mov bl, byte ptr [ecx + 8]
// 0055d8d4  8bca                 mov ecx, edx
// 0055d8d6  d2e3                 shl bl, cl
// 0055d8d8  eb32                 jmp 0x55d90c
// 0055d8da  0fb6c0               movzx eax, al
// 0055d8dd  8d0c8500000000       lea ecx, [eax*4]
// 0055d8e4  0bc8                 or ecx, eax
// 0055d8e6  03c9                 add ecx, ecx
// 0055d8e8  03c9                 add ecx, ecx
// 0055d8ea  0bc8                 or ecx, eax
// 0055d8ec  03c9                 add ecx, ecx
// 0055d8ee  03c9                 add ecx, ecx
// 0055d8f0  0bc8                 or ecx, eax
// 0055d8f2  8a0439               mov al, byte ptr [ecx + edi]
// 0055d8f5  b906000000           mov ecx, 6
// 0055d8fa  2bca                 sub ecx, edx
// 0055d8fc  bb3f3f0000           mov ebx, 0x3f3f
// 0055d901  d3fb                 sar ebx, cl
// 0055d903  c0e806               shr al, 6
// 0055d906  8bca                 mov ecx, edx
// 0055d908  221e                 and bl, byte ptr [esi]
// 0055d90a  d2e0                 shl al, cl
// 0055d90c  0ad8                 or bl, al
// 0055d90e  881e                 mov byte ptr [esi], bl
// 0055d910  85d2                 test edx, edx
// 0055d912  7508                 jne 0x55d91c
// 0055d914  ba06000000           mov edx, 6
// 0055d919  46                   inc esi
// 0055d91a  eb03                 jmp 0x55d91f
// 0055d91c  83ea02               sub edx, 2
// 0055d91f  836c241801           sub dword ptr [esp + 0x18], 1
// 0055d924  0f8579ffffff         jne 0x55d8a3
// 0055d92a  e9910e0000           jmp 0x55e7c0
// 0055d92f  85c9                 test ecx, ecx
// 0055d931  0f86890e0000         jbe 0x55e7c0
// 0055d937  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0055d93b  8be9                 mov ebp, ecx
// 0055d93d  8d4900               lea ecx, [ecx]
// 0055d940  8a1e                 mov bl, byte ptr [esi]
// 0055d942  8ac3                 mov al, bl
// 0055d944  8aca                 mov cl, dl
// 0055d946  d2e8                 shr al, cl
// 0055d948  2403                 and al, 3
// 0055d94a  660fb6c8             movzx cx, al
// 0055d94e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0055d952  663b4808             cmp cx, word ptr [eax + 8]
// 0055d956  751d                 jne 0x55d975
// 0055d958  b906000000           mov ecx, 6
// 0055d95d  2bca                 sub ecx, edx
// 0055d95f  b83f3f0000           mov eax, 0x3f3f
// 0055d964  d3f8                 sar eax, cl
// 0055d966  8bca                 mov ecx, edx
// 0055d968  22c3                 and al, bl
// 0055d96a  8806                 mov byte ptr [esi], al
// 0055d96c  8a5f08               mov bl, byte ptr [edi + 8]
// 0055d96f  d2e3                 shl bl, cl
// 0055d971  0ad8                 or bl, al
// 0055d973  881e                 mov byte ptr [esi], bl
// 0055d975  85d2                 test edx, edx
// 0055d977  7508                 jne 0x55d981
// 0055d979  ba06000000           mov edx, 6
// 0055d97e  46                   inc esi
// 0055d97f  eb03                 jmp 0x55d984
// 0055d981  83ea02               sub edx, 2
// 0055d984  83ed01               sub ebp, 1
// 0055d987  75b7                 jne 0x55d940
// 0055d989  e9320e0000           jmp 0x55e7c0
// 0055d98e  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 0055d992  8b742428             mov esi, dword ptr [esp + 0x28]
// 0055d996  ba04000000           mov edx, 4
// 0055d99b  85ff                 test edi, edi
// 0055d99d  0f8487000000         je 0x55da2a
// 0055d9a3  85c9                 test ecx, ecx
// 0055d9a5  0f86150e0000         jbe 0x55e7c0
// 0055d9ab  894c2418             mov dword ptr [esp + 0x18], ecx
// 0055d9af  90                   nop 
// 0055d9b0  8a1e                 mov bl, byte ptr [esi]
// 0055d9b2  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0055d9b6  8aca                 mov cl, dl
// 0055d9b8  8ac3                 mov al, bl
// 0055d9ba  d2e8                 shr al, cl
// 0055d9bc  240f                 and al, 0xf
// 0055d9be  660fb6c8             movzx cx, al
// 0055d9c2  663b4d08             cmp cx, word ptr [ebp + 8]
// 0055d9c6  751f                 jne 0x55d9e7
// 0055d9c8  b904000000           mov ecx, 4
// 0055d9cd  2bca                 sub ecx, edx
// 0055d9cf  b80f0f0000           mov eax, 0xf0f
// 0055d9d4  d3f8                 sar eax, cl
// 0055d9d6  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0055d9da  22c3                 and al, bl
// 0055d9dc  8806                 mov byte ptr [esi], al
// 0055d9de  8a5908               mov bl, byte ptr [ecx + 8]
// 0055d9e1  8bca                 mov ecx, edx
// 0055d9e3  d2e3                 shl bl, cl
// 0055d9e5  eb24                 jmp 0x55da0b
// 0055d9e7  0fb6c0               movzx eax, al
// 0055d9ea  8bc8                 mov ecx, eax
// 0055d9ec  c1e104               shl ecx, 4
// 0055d9ef  0bc8                 or ecx, eax
// 0055d9f1  8a0439               mov al, byte ptr [ecx + edi]
// 0055d9f4  b904000000           mov ecx, 4
// 0055d9f9  2bca                 sub ecx, edx
// 0055d9fb  bb0f0f0000           mov ebx, 0xf0f
// 0055da00  d3fb                 sar ebx, cl
// 0055da02  c0e804               shr al, 4
// 0055da05  8bca                 mov ecx, edx
// 0055da07  221e                 and bl, byte ptr [esi]
// 0055da09  d2e0                 shl al, cl
// 0055da0b  0ad8                 or bl, al
// 0055da0d  881e                 mov byte ptr [esi], bl
// 0055da0f  85d2                 test edx, edx
// 0055da11  7508                 jne 0x55da1b
// 0055da13  ba04000000           mov edx, 4
// 0055da18  46                   inc esi
// 0055da19  eb03                 jmp 0x55da1e
// 0055da1b  83ea04               sub edx, 4
// 0055da1e  836c241801           sub dword ptr [esp + 0x18], 1
// 0055da23  758b                 jne 0x55d9b0
// 0055da25  e9960d0000           jmp 0x55e7c0
// 0055da2a  85c9                 test ecx, ecx
// 0055da2c  0f868e0d0000         jbe 0x55e7c0
// 0055da32  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0055da36  8be9                 mov ebp, ecx
// 0055da38  8a1e                 mov bl, byte ptr [esi]
// 0055da3a  8ac3                 mov al, bl
// 0055da3c  8aca                 mov cl, dl
// 0055da3e  d2e8                 shr al, cl
// 0055da40  240f                 and al, 0xf
// 0055da42  660fb6c8             movzx cx, al
// 0055da46  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0055da4a  663b4808             cmp cx, word ptr [eax + 8]
// 0055da4e  751d                 jne 0x55da6d
// 0055da50  b904000000           mov ecx, 4
// 0055da55  2bca                 sub ecx, edx
// 0055da57  b80f0f0000           mov eax, 0xf0f
// 0055da5c  d3f8                 sar eax, cl
// 0055da5e  8bca                 mov ecx, edx
// 0055da60  22c3                 and al, bl
// 0055da62  8806                 mov byte ptr [esi], al
// 0055da64  8a5f08               mov bl, byte ptr [edi + 8]
// 0055da67  d2e3                 shl bl, cl
// 0055da69  0ad8                 or bl, al
// 0055da6b  881e                 mov byte ptr [esi], bl
// 0055da6d  85d2                 test edx, edx
// 0055da6f  7508                 jne 0x55da79
// 0055da71  ba04000000           mov edx, 4
// 0055da76  46                   inc esi
// 0055da77  eb03                 jmp 0x55da7c
// 0055da79  83ea04               sub edx, 4
// 0055da7c  83ed01               sub ebp, 1
// 0055da7f  75b7                 jne 0x55da38
// 0055da81  e93a0d0000           jmp 0x55e7c0
// 0055da86  8b742438             mov esi, dword ptr [esp + 0x38]
// 0055da8a  8b442428             mov eax, dword ptr [esp + 0x28]
// 0055da8e  85f6                 test esi, esi
// 0055da90  7432                 je 0x55dac4
// 0055da92  85c9                 test ecx, ecx
// 0055da94  0f86260d0000         jbe 0x55e7c0
// 0055da9a  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0055da9e  8bd1                 mov edx, ecx
// 0055daa0  8a08                 mov cl, byte ptr [eax]
// 0055daa2  660fb6d9             movzx bx, cl
// 0055daa6  663b5d08             cmp bx, word ptr [ebp + 8]
// 0055daaa  7505                 jne 0x55dab1
// 0055daac  8a4f08               mov cl, byte ptr [edi + 8]
// 0055daaf  eb06                 jmp 0x55dab7
// 0055dab1  0fb6c9               movzx ecx, cl
// 0055dab4  8a0c31               mov cl, byte ptr [ecx + esi]
// 0055dab7  8808                 mov byte ptr [eax], cl
// 0055dab9  40                   inc eax
// 0055daba  83ea01               sub edx, 1
// 0055dabd  75e1                 jne 0x55daa0
// 0055dabf  e9fc0c0000           jmp 0x55e7c0
// 0055dac4  85c9                 test ecx, ecx
// 0055dac6  0f86f40c0000         jbe 0x55e7c0
// 0055dacc  8b742430             mov esi, dword ptr [esp + 0x30]
// 0055dad0  660fb610             movzx dx, byte ptr [eax]
// 0055dad4  663b5508             cmp dx, word ptr [ebp + 8]
// 0055dad8  7505                 jne 0x55dadf
// 0055dada  8a5608               mov dl, byte ptr [esi + 8]
// 0055dadd  8810                 mov byte ptr [eax], dl
// 0055dadf  40                   inc eax
// 0055dae0  83e901               sub ecx, 1
// 0055dae3  75eb                 jne 0x55dad0
// 0055dae5  e9d60c0000           jmp 0x55e7c0
// 0055daea  8b742444             mov esi, dword ptr [esp + 0x44]
// 0055daee  8b442428             mov eax, dword ptr [esp + 0x28]
// 0055daf2  85f6                 test esi, esi
// 0055daf4  746b                 je 0x55db61
// 0055daf6  85c9                 test ecx, ecx
// 0055daf8  0f86c20c0000         jbe 0x55e7c0
// 0055dafe  8a5c2450             mov bl, byte ptr [esp + 0x50]
// 0055db02  894c2418             mov dword ptr [esp + 0x18], ecx
// 0055db06  8a10                 mov dl, byte ptr [eax]
// 0055db08  8a4801               mov cl, byte ptr [eax + 1]
// 0055db0b  660fb6fa             movzx di, dl
// 0055db0f  bd00010000           mov ebp, 0x100
// 0055db14  660faffd             imul di, bp
// 0055db18  660fb6e9             movzx bp, cl
// 0055db1c  6603fd               add di, bp
// 0055db1f  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0055db23  663b7d08             cmp di, word ptr [ebp + 8]
// 0055db27  750e                 jne 0x55db37
// 0055db29  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0055db2d  8a5709               mov dl, byte ptr [edi + 9]
// 0055db30  8810                 mov byte ptr [eax], dl
// 0055db32  8a4f08               mov cl, byte ptr [edi + 8]
// 0055db35  eb18                 jmp 0x55db4f
// 0055db37  0fb6f9               movzx edi, cl
// 0055db3a  8acb                 mov cl, bl
// 0055db3c  d3ef                 shr edi, cl
// 0055db3e  0fb6d2               movzx edx, dl
// 0055db41  8b0cbe               mov ecx, dword ptr [esi + edi*4]
// 0055db44  0fb70c51             movzx ecx, word ptr [ecx + edx*2]
// 0055db48  8bd1                 mov edx, ecx
// 0055db4a  c1ea08               shr edx, 8
// 0055db4d  8810                 mov byte ptr [eax], dl
// 0055db4f  884801               mov byte ptr [eax + 1], cl
// 0055db52  83c002               add eax, 2
// 0055db55  836c241801           sub dword ptr [esp + 0x18], 1
// 0055db5a  75aa                 jne 0x55db06
// 0055db5c  e95f0c0000           jmp 0x55e7c0
// 0055db61  85c9                 test ecx, ecx
// 0055db63  0f86570c0000         jbe 0x55e7c0
// 0055db69  8b742430             mov esi, dword ptr [esp + 0x30]
// 0055db6d  8d4900               lea ecx, [ecx]
// 0055db70  660fb610             movzx dx, byte ptr [eax]
// 0055db74  bf00010000           mov edi, 0x100
// 0055db79  660fafd7             imul dx, di
// 0055db7d  660fb67801           movzx di, byte ptr [eax + 1]
// 0055db82  6603d7               add dx, di
// 0055db85  663b5508             cmp dx, word ptr [ebp + 8]
// 0055db89  750d                 jne 0x55db98
// 0055db8b  0fb65609             movzx edx, byte ptr [esi + 9]
// 0055db8f  8810                 mov byte ptr [eax], dl
// 0055db91  0fb65608             movzx edx, byte ptr [esi + 8]
// 0055db95  885001               mov byte ptr [eax + 1], dl
// 0055db98  83c002               add eax, 2
// 0055db9b  83e901               sub ecx, 1
// 0055db9e  75d0                 jne 0x55db70
// 0055dba0  e91b0c0000           jmp 0x55e7c0
// 0055dba5  8b442424             mov eax, dword ptr [esp + 0x24]
// 0055dba9  80780908             cmp byte ptr [eax + 9], 8
// 0055dbad  0f85d2000000         jne 0x55dc85
// 0055dbb3  8b542438             mov edx, dword ptr [esp + 0x38]
// 0055dbb7  85d2                 test edx, edx
// 0055dbb9  7476                 je 0x55dc31
// 0055dbbb  85c9                 test ecx, ecx
// 0055dbbd  0f86fd0b0000         jbe 0x55e7c0
// 0055dbc3  8b442428             mov eax, dword ptr [esp + 0x28]
// 0055dbc7  8b742430             mov esi, dword ptr [esp + 0x30]
// 0055dbcb  83c002               add eax, 2
// 0055dbce  8bf9                 mov edi, ecx
// 0055dbd0  8a48fe               mov cl, byte ptr [eax - 2]
// 0055dbd3  660fb6d9             movzx bx, cl
// 0055dbd7  663b5d02             cmp bx, word ptr [ebp + 2]
// 0055dbdb  7529                 jne 0x55dc06
// 0055dbdd  660fb658ff           movzx bx, byte ptr [eax - 1]
// 0055dbe2  663b5d04             cmp bx, word ptr [ebp + 4]
// 0055dbe6  751e                 jne 0x55dc06
// 0055dbe8  660fb618             movzx bx, byte ptr [eax]
// 0055dbec  663b5d06             cmp bx, word ptr [ebp + 6]
// 0055dbf0  7514                 jne 0x55dc06
// 0055dbf2  0fb64e02             movzx ecx, byte ptr [esi + 2]
// 0055dbf6  8848fe               mov byte ptr [eax - 2], cl
// 0055dbf9  0fb64e04             movzx ecx, byte ptr [esi + 4]
// 0055dbfd  8848ff               mov byte ptr [eax - 1], cl
// 0055dc00  0fb64e06             movzx ecx, byte ptr [esi + 6]
// 0055dc04  eb1c                 jmp 0x55dc22
// 0055dc06  0fb6c9               movzx ecx, cl
// 0055dc09  0fb60c11             movzx ecx, byte ptr [ecx + edx]
// 0055dc0d  8848fe               mov byte ptr [eax - 2], cl
// 0055dc10  0fb648ff             movzx ecx, byte ptr [eax - 1]
// 0055dc14  0fb60c11             movzx ecx, byte ptr [ecx + edx]
// 0055dc18  8848ff               mov byte ptr [eax - 1], cl
// 0055dc1b  0fb608               movzx ecx, byte ptr [eax]
// 0055dc1e  0fb60c11             movzx ecx, byte ptr [ecx + edx]
// 0055dc22  8808                 mov byte ptr [eax], cl
// 0055dc24  83c003               add eax, 3
// 0055dc27  83ef01               sub edi, 1
// 0055dc2a  75a4                 jne 0x55dbd0
// 0055dc2c  e98f0b0000           jmp 0x55e7c0
// 0055dc31  85c9                 test ecx, ecx
// 0055dc33  0f86870b0000         jbe 0x55e7c0
// 0055dc39  8b442428             mov eax, dword ptr [esp + 0x28]
// 0055dc3d  8b742430             mov esi, dword ptr [esp + 0x30]
// 0055dc41  83c002               add eax, 2
// 0055dc44  660fb650fe           movzx dx, byte ptr [eax - 2]
// 0055dc49  663b5502             cmp dx, word ptr [ebp + 2]
// 0055dc4d  7529                 jne 0x55dc78
// 0055dc4f  660fb650ff           movzx dx, byte ptr [eax - 1]
// 0055dc54  663b5504             cmp dx, word ptr [ebp + 4]
// 0055dc58  751e                 jne 0x55dc78
// 0055dc5a  660fb610             movzx dx, byte ptr [eax]
// 0055dc5e  663b5506             cmp dx, word ptr [ebp + 6]
// 0055dc62  7514                 jne 0x55dc78
// 0055dc64  0fb65602             movzx edx, byte ptr [esi + 2]
// 0055dc68  8850fe               mov byte ptr [eax - 2], dl
// 0055dc6b  0fb65604             movzx edx, byte ptr [esi + 4]
// 0055dc6f  8850ff               mov byte ptr [eax - 1], dl
// 0055dc72  0fb65606             movzx edx, byte ptr [esi + 6]
// 0055dc76  8810                 mov byte ptr [eax], dl
// 0055dc78  83c003               add eax, 3
// 0055dc7b  83e901               sub ecx, 1
// 0055dc7e  75c4                 jne 0x55dc44
// 0055dc80  e93b0b0000           jmp 0x55e7c0
// 0055dc85  8b742444             mov esi, dword ptr [esp + 0x44]
// 0055dc89  85f6                 test esi, esi
// 0055dc8b  0f841b010000         je 0x55ddac
// 0055dc91  85c9                 test ecx, ecx
// 0055dc93  0f86270b0000         jbe 0x55e7c0
// 0055dc99  8b442428             mov eax, dword ptr [esp + 0x28]
// 0055dc9d  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0055dca1  83c002               add eax, 2
// 0055dca4  894c2418             mov dword ptr [esp + 0x18], ecx
// 0055dca8  eb06                 jmp 0x55dcb0
// 0055dcaa  8d9b00000000         lea ebx, [ebx]
// 0055dcb0  8a58fe               mov bl, byte ptr [eax - 2]
// 0055dcb3  8a48ff               mov cl, byte ptr [eax - 1]
// 0055dcb6  660fb6d3             movzx dx, bl
// 0055dcba  bd00010000           mov ebp, 0x100
// 0055dcbf  660fafd5             imul dx, bp
// 0055dcc3  660fb6e9             movzx bp, cl
// 0055dcc7  6603d5               add dx, bp
// 0055dcca  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0055dcce  663b5502             cmp dx, word ptr [ebp + 2]
// 0055dcd2  756a                 jne 0x55dd3e
// 0055dcd4  660fb610             movzx dx, byte ptr [eax]
// 0055dcd8  bd00010000           mov ebp, 0x100
// 0055dcdd  660fafd5             imul dx, bp
// 0055dce1  660fb66801           movzx bp, byte ptr [eax + 1]
// 0055dce6  6603d5               add dx, bp
// 0055dce9  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0055dced  663b5504             cmp dx, word ptr [ebp + 4]
// 0055dcf1  754b                 jne 0x55dd3e
// 0055dcf3  660fb65002           movzx dx, byte ptr [eax + 2]
// 0055dcf8  bd00010000           mov ebp, 0x100
// 0055dcfd  660fafd5             imul dx, bp
// 0055dd01  660fb66803           movzx bp, byte ptr [eax + 3]
// 0055dd06  6603d5               add dx, bp
// 0055dd09  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0055dd0d  663b5506             cmp dx, word ptr [ebp + 6]
// 0055dd11  752b                 jne 0x55dd3e
// 0055dd13  0fb64f03             movzx ecx, byte ptr [edi + 3]
// 0055dd17  8848fe               mov byte ptr [eax - 2], cl
// 0055dd1a  0fb65702             movzx edx, byte ptr [edi + 2]
// 0055dd1e  8850ff               mov byte ptr [eax - 1], dl
// 0055dd21  0fb64f05             movzx ecx, byte ptr [edi + 5]
// 0055dd25  8808                 mov byte ptr [eax], cl
// 0055dd27  0fb65704             movzx edx, byte ptr [edi + 4]
// 0055dd2b  885001               mov byte ptr [eax + 1], dl
// 0055dd2e  0fb64f07             movzx ecx, byte ptr [edi + 7]
// 0055dd32  884802               mov byte ptr [eax + 2], cl
// 0055dd35  0fb65706             movzx edx, byte ptr [edi + 6]
// 0055dd39  885003               mov byte ptr [eax + 3], dl
// 0055dd3c  eb5b                 jmp 0x55dd99
// 0055dd3e  0fb6542450           movzx edx, byte ptr [esp + 0x50]
// 0055dd43  0fb6e9               movzx ebp, cl
// 0055dd46  8aca                 mov cl, dl
// 0055dd48  d3ed                 shr ebp, cl
// 0055dd4a  0fb6cb               movzx ecx, bl
// 0055dd4d  8b1cae               mov ebx, dword ptr [esi + ebp*4]
// 0055dd50  0fb70c4b             movzx ecx, word ptr [ebx + ecx*2]
// 0055dd54  8bd9                 mov ebx, ecx
// 0055dd56  c1eb08               shr ebx, 8
// 0055dd59  8858fe               mov byte ptr [eax - 2], bl
// 0055dd5c  0fb65801             movzx ebx, byte ptr [eax + 1]
// 0055dd60  8848ff               mov byte ptr [eax - 1], cl
// 0055dd63  8aca                 mov cl, dl
// 0055dd65  d3eb                 shr ebx, cl
// 0055dd67  0fb608               movzx ecx, byte ptr [eax]
// 0055dd6a  8b1c9e               mov ebx, dword ptr [esi + ebx*4]
// 0055dd6d  0fb70c4b             movzx ecx, word ptr [ebx + ecx*2]
// 0055dd71  8bd9                 mov ebx, ecx
// 0055dd73  c1eb08               shr ebx, 8
// 0055dd76  8818                 mov byte ptr [eax], bl
// 0055dd78  0fb65803             movzx ebx, byte ptr [eax + 3]
// 0055dd7c  884801               mov byte ptr [eax + 1], cl
// 0055dd7f  8aca                 mov cl, dl
// 0055dd81  0fb65002             movzx edx, byte ptr [eax + 2]
// 0055dd85  d3eb                 shr ebx, cl
// 0055dd87  8b0c9e               mov ecx, dword ptr [esi + ebx*4]
// 0055dd8a  0fb70c51             movzx ecx, word ptr [ecx + edx*2]
// 0055dd8e  8bd1                 mov edx, ecx
// 0055dd90  c1ea08               shr edx, 8
// 0055dd93  885002               mov byte ptr [eax + 2], dl
// 0055dd96  884803               mov byte ptr [eax + 3], cl
// 0055dd99  83c006               add eax, 6
// 0055dd9c  836c241801           sub dword ptr [esp + 0x18], 1
// 0055dda1  0f8509ffffff         jne 0x55dcb0
// 0055dda7  e9140a0000           jmp 0x55e7c0
// 0055ddac  85c9                 test ecx, ecx
// 0055ddae  0f860c0a0000         jbe 0x55e7c0
// 0055ddb4  8b442428             mov eax, dword ptr [esp + 0x28]
// 0055ddb8  8b742430             mov esi, dword ptr [esp + 0x30]
// 0055ddbc  83c002               add eax, 2
// 0055ddbf  90                   nop 
// 0055ddc0  660fb650fe           movzx dx, byte ptr [eax - 2]
// 0055ddc5  bf00010000           mov edi, 0x100
// 0055ddca  660fafd7             imul dx, di
// 0055ddce  660fb678ff           movzx di, byte ptr [eax - 1]
// 0055ddd3  6603d7               add dx, di
// 0055ddd6  663b5502             cmp dx, word ptr [ebp + 2]
// 0055ddda  7560                 jne 0x55de3c
// 0055dddc  660fb610             movzx dx, byte ptr [eax]
// 0055dde0  bf00010000           mov edi, 0x100
// 0055dde5  660fafd7             imul dx, di
// 0055dde9  660fb67801           movzx di, byte ptr [eax + 1]
// 0055ddee  6603d7               add dx, di
// 0055ddf1  663b5504             cmp dx, word ptr [ebp + 4]
// 0055ddf5  7545                 jne 0x55de3c
// 0055ddf7  660fb65002           movzx dx, byte ptr [eax + 2]
// 0055ddfc  bf00010000           mov edi, 0x100
// 0055de01  660fafd7             imul dx, di
// 0055de05  660fb67803           movzx di, byte ptr [eax + 3]
// 0055de0a  6603d7               add dx, di
// 0055de0d  663b5506             cmp dx, word ptr [ebp + 6]
// 0055de11  7529                 jne 0x55de3c
// 0055de13  0fb65603             movzx edx, byte ptr [esi + 3]
// 0055de17  8850fe               mov byte ptr [eax - 2], dl
// 0055de1a  0fb65602             movzx edx, byte ptr [esi + 2]
// 0055de1e  8850ff               mov byte ptr [eax - 1], dl
// 0055de21  0fb65605             movzx edx, byte ptr [esi + 5]
// 0055de25  8810                 mov byte ptr [eax], dl
// 0055de27  0fb65604             movzx edx, byte ptr [esi + 4]
// 0055de2b  885001               mov byte ptr [eax + 1], dl
// 0055de2e  0fb65607             movzx edx, byte ptr [esi + 7]
// 0055de32  885002               mov byte ptr [eax + 2], dl
// 0055de35  0fb65606             movzx edx, byte ptr [esi + 6]
// 0055de39  885003               mov byte ptr [eax + 3], dl
// 0055de3c  83c006               add eax, 6
// 0055de3f  83e901               sub ecx, 1
// 0055de42  0f8578ffffff         jne 0x55ddc0
// 0055de48  e973090000           jmp 0x55e7c0
// 0055de4d  8b442424             mov eax, dword ptr [esp + 0x24]
// 0055de51  80780908             cmp byte ptr [eax + 9], 8
// 0055de55  0f852d010000         jne 0x55df88
// 0055de5b  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 0055de5f  85ff                 test edi, edi
// 0055de61  0f84a9000000         je 0x55df10
// 0055de67  837c243c00           cmp dword ptr [esp + 0x3c], 0
// 0055de6c  0f849e000000         je 0x55df10
// 0055de72  837c243800           cmp dword ptr [esp + 0x38], 0
// 0055de77  0f8493000000         je 0x55df10
// 0055de7d  837c241000           cmp dword ptr [esp + 0x10], 0
// 0055de82  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0055de86  8bf1                 mov esi, ecx
// 0055de88  0f8632090000         jbe 0x55e7c0
// 0055de8e  8b542410             mov edx, dword ptr [esp + 0x10]
// 0055de92  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0055de96  89542418             mov dword ptr [esp + 0x18], edx
// 0055de9a  8d9b00000000         lea ebx, [ebx]
// 0055dea0  660fb64101           movzx ax, byte ptr [ecx + 1]
// 0055dea5  0fb7c0               movzx eax, ax
// 0055dea8  baff000000           mov edx, 0xff
// 0055dead  663bc2               cmp ax, dx
// 0055deb0  7509                 jne 0x55debb
// 0055deb2  0fb601               movzx eax, byte ptr [ecx]
// 0055deb5  8b542438             mov edx, dword ptr [esp + 0x38]
// 0055deb9  eb40                 jmp 0x55defb
// 0055debb  6685c0               test ax, ax
// 0055debe  7509                 jne 0x55dec9
// 0055dec0  8b542430             mov edx, dword ptr [esp + 0x30]
// 0055dec4  8a4208               mov al, byte ptr [edx + 8]
// 0055dec7  eb35                 jmp 0x55defe
// 0055dec9  0fb619               movzx ebx, byte ptr [ecx]
// 0055decc  660fb61c3b           movzx bx, byte ptr [ebx + edi]
// 0055ded1  2bd0                 sub edx, eax
// 0055ded3  660fafd8             imul bx, ax
// 0055ded7  660faf5508           imul dx, word ptr [ebp + 8]
// 0055dedc  6603d3               add dx, bx
// 0055dedf  b880000000           mov eax, 0x80
// 0055dee4  6603d0               add dx, ax
// 0055dee7  0fb7c2               movzx eax, dx
// 0055deea  8bd0                 mov edx, eax
// 0055deec  c1ea08               shr edx, 8
// 0055deef  03d0                 add edx, eax
// 0055def1  c1fa08               sar edx, 8
// 0055def4  0fb6c2               movzx eax, dl
// 0055def7  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0055defb  8a0410               mov al, byte ptr [eax + edx]
// 0055defe  8806                 mov byte ptr [esi], al
// 0055df00  83c102               add ecx, 2
// 0055df03  46                   inc esi
// 0055df04  836c241801           sub dword ptr [esp + 0x18], 1
// 0055df09  7595                 jne 0x55dea0
// 0055df0b  e9b0080000           jmp 0x55e7c0
// 0055df10  837c241000           cmp dword ptr [esp + 0x10], 0
// 0055df15  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0055df19  8bf1                 mov esi, ecx
// 0055df1b  0f869f080000         jbe 0x55e7c0
// 0055df21  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0055df25  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0055df29  8da42400000000       lea esp, [esp]
// 0055df30  8a4101               mov al, byte ptr [ecx + 1]
// 0055df33  3cff                 cmp al, 0xff
// 0055df35  7504                 jne 0x55df3b
// 0055df37  8a11                 mov dl, byte ptr [ecx]
// 0055df39  eb3d                 jmp 0x55df78
// 0055df3b  84c0                 test al, al
// 0055df3d  7509                 jne 0x55df48
// 0055df3f  8b442430             mov eax, dword ptr [esp + 0x30]
// 0055df43  8a5008               mov dl, byte ptr [eax + 8]
// 0055df46  eb30                 jmp 0x55df78
// 0055df48  660fb619             movzx bx, byte ptr [ecx]
// 0055df4c  660fb6c0             movzx ax, al
// 0055df50  baff000000           mov edx, 0xff
// 0055df55  660fafd8             imul bx, ax
// 0055df59  2bd0                 sub edx, eax
// 0055df5b  660faf5508           imul dx, word ptr [ebp + 8]
// 0055df60  6603d3               add dx, bx
// 0055df63  b880000000           mov eax, 0x80
// 0055df68  6603d0               add dx, ax
// 0055df6b  0fb7c2               movzx eax, dx
// 0055df6e  8bd0                 mov edx, eax
// 0055df70  c1ea08               shr edx, 8
// 0055df73  03d0                 add edx, eax
// 0055df75  c1fa08               sar edx, 8
// 0055df78  8816                 mov byte ptr [esi], dl
// 0055df7a  83c102               add ecx, 2
// 0055df7d  46                   inc esi
// 0055df7e  83ef01               sub edi, 1
// 0055df81  75ad                 jne 0x55df30
// 0055df83  e938080000           jmp 0x55e7c0
// 0055df88  837c244400           cmp dword ptr [esp + 0x44], 0
// 0055df8d  0f8407010000         je 0x55e09a
// 0055df93  837c244800           cmp dword ptr [esp + 0x48], 0
// 0055df98  0f84fc000000         je 0x55e09a
// 0055df9e  837c244c00           cmp dword ptr [esp + 0x4c], 0
// 0055dfa3  0f84f1000000         je 0x55e09a
// 0055dfa9  8b542428             mov edx, dword ptr [esp + 0x28]
// 0055dfad  8bf2                 mov esi, edx
// 0055dfaf  85c9                 test ecx, ecx
// 0055dfb1  0f8609080000         jbe 0x55e7c0
// 0055dfb7  8a5c2450             mov bl, byte ptr [esp + 0x50]
// 0055dfbb  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0055dfbf  8bc1                 mov eax, ecx
// 0055dfc1  42                   inc edx
// 0055dfc2  89442418             mov dword ptr [esp + 0x18], eax
// 0055dfc6  eb08                 jmp 0x55dfd0
// 0055dfc8  8da42400000000       lea esp, [esp]
// 0055dfcf  90                   nop 
// 0055dfd0  660fb64a01           movzx cx, byte ptr [edx + 1]
// 0055dfd5  b800010000           mov eax, 0x100
// 0055dfda  660fafc8             imul cx, ax
// 0055dfde  660fb64202           movzx ax, byte ptr [edx + 2]
// 0055dfe3  6603c8               add cx, ax
// 0055dfe6  0fb7c1               movzx eax, cx
// 0055dfe9  b9ffff0000           mov ecx, 0xffff
// 0055dfee  663bc1               cmp ax, cx
// 0055dff1  7519                 jne 0x55e00c
// 0055dff3  0fb602               movzx eax, byte ptr [edx]
// 0055dff6  8b6c2444             mov ebp, dword ptr [esp + 0x44]
// 0055dffa  8acb                 mov cl, bl
// 0055dffc  d3e8                 shr eax, cl
// 0055dffe  0fb64aff             movzx ecx, byte ptr [edx - 1]
// 0055e002  8b448500             mov eax, dword ptr [ebp + eax*4]
// 0055e006  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 0055e00a  eb6e                 jmp 0x55e07a
// 0055e00c  6685c0               test ax, ax
// 0055e00f  750d                 jne 0x55e01e
// 0055e011  8a4709               mov al, byte ptr [edi + 9]
// 0055e014  8806                 mov byte ptr [esi], al
// 0055e016  8a4f08               mov cl, byte ptr [edi + 8]
// 0055e019  884e01               mov byte ptr [esi + 1], cl
// 0055e01c  eb66                 jmp 0x55e084
// 0055e01e  0fb63a               movzx edi, byte ptr [edx]
// 0055e021  8b6c244c             mov ebp, dword ptr [esp + 0x4c]
// 0055e025  8acb                 mov cl, bl
// 0055e027  d3ef                 shr edi, cl
// 0055e029  0fb64aff             movzx ecx, byte ptr [edx - 1]
// 0055e02d  8b7cbd00             mov edi, dword ptr [ebp + edi*4]
// 0055e031  0fb70c4f             movzx ecx, word ptr [edi + ecx*2]
// 0055e035  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0055e039  0fb77f08             movzx edi, word ptr [edi + 8]
// 0055e03d  0fb7c0               movzx eax, ax
// 0055e040  0fafc8               imul ecx, eax
// 0055e043  bdffff0000           mov ebp, 0xffff
// 0055e048  2be8                 sub ebp, eax
// 0055e04a  0faffd               imul edi, ebp
// 0055e04d  8d8c3900800000       lea ecx, [ecx + edi + 0x8000]
// 0055e054  8bc1                 mov eax, ecx
// 0055e056  c1e810               shr eax, 0x10
// 0055e059  03c1                 add eax, ecx
// 0055e05b  c1e810               shr eax, 0x10
// 0055e05e  0fb7c0               movzx eax, ax
// 0055e061  0fb6f8               movzx edi, al
// 0055e064  8acb                 mov cl, bl
// 0055e066  d3ef                 shr edi, cl
// 0055e068  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0055e06c  c1e808               shr eax, 8
// 0055e06f  8b0cb9               mov ecx, dword ptr [ecx + edi*4]
// 0055e072  0fb70441             movzx eax, word ptr [ecx + eax*2]
// 0055e076  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0055e07a  8bc8                 mov ecx, eax
// 0055e07c  c1e908               shr ecx, 8
// 0055e07f  884601               mov byte ptr [esi + 1], al
// 0055e082  880e                 mov byte ptr [esi], cl
// 0055e084  83c204               add edx, 4
// 0055e087  83c602               add esi, 2
// 0055e08a  836c241801           sub dword ptr [esp + 0x18], 1
// 0055e08f  0f853bffffff         jne 0x55dfd0
// 0055e095  e926070000           jmp 0x55e7c0
// 0055e09a  837c241000           cmp dword ptr [esp + 0x10], 0
// 0055e09f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0055e0a3  8bf1                 mov esi, ecx
// 0055e0a5  0f8615070000         jbe 0x55e7c0
// 0055e0ab  8b542410             mov edx, dword ptr [esp + 0x10]
// 0055e0af  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0055e0b3  89542418             mov dword ptr [esp + 0x18], edx
// 0055e0b7  8b542430             mov edx, dword ptr [esp + 0x30]
// 0055e0bb  83c103               add ecx, 3
// 0055e0be  8bff                 mov edi, edi
// 0055e0c0  660fb641ff           movzx ax, byte ptr [ecx - 1]
// 0055e0c5  bf00010000           mov edi, 0x100
// 0055e0ca  660fafc7             imul ax, di
// 0055e0ce  660fb639             movzx di, byte ptr [ecx]
// 0055e0d2  6603c7               add ax, di
// 0055e0d5  0fb7c0               movzx eax, ax
// 0055e0d8  bfffff0000           mov edi, 0xffff
// 0055e0dd  663bc7               cmp ax, di
// 0055e0e0  7509                 jne 0x55e0eb
// 0055e0e2  668b41fd             mov ax, word ptr [ecx - 3]
// 0055e0e6  668906               mov word ptr [esi], ax
// 0055e0e9  eb5d                 jmp 0x55e148
// 0055e0eb  6685c0               test ax, ax
// 0055e0ee  750c                 jne 0x55e0fc
// 0055e0f0  0fb64209             movzx eax, byte ptr [edx + 9]
// 0055e0f4  8806                 mov byte ptr [esi], al
// 0055e0f6  0fb64208             movzx eax, byte ptr [edx + 8]
// 0055e0fa  eb49                 jmp 0x55e145
// 0055e0fc  660fb651fd           movzx dx, byte ptr [ecx - 3]
// 0055e101  bf00010000           mov edi, 0x100
// 0055e106  660fafd7             imul dx, di
// 0055e10a  660fb679fe           movzx di, byte ptr [ecx - 2]
// 0055e10f  6603d7               add dx, di
// 0055e112  0fb77d08             movzx edi, word ptr [ebp + 8]
// 0055e116  0fb7c0               movzx eax, ax
// 0055e119  0fb7d2               movzx edx, dx
// 0055e11c  0fafd0               imul edx, eax
// 0055e11f  bbffff0000           mov ebx, 0xffff
// 0055e124  2bd8                 sub ebx, eax
// 0055e126  0faffb               imul edi, ebx
// 0055e129  8d943a00800000       lea edx, [edx + edi + 0x8000]
// 0055e130  8bc2                 mov eax, edx
// 0055e132  c1e810               shr eax, 0x10
// 0055e135  03c2                 add eax, edx
// 0055e137  c1e810               shr eax, 0x10
// 0055e13a  8bd0                 mov edx, eax
// 0055e13c  c1ea08               shr edx, 8
// 0055e13f  8816                 mov byte ptr [esi], dl
// 0055e141  8b542430             mov edx, dword ptr [esp + 0x30]
// 0055e145  884601               mov byte ptr [esi + 1], al
// 0055e148  83c104               add ecx, 4
// 0055e14b  83c602               add esi, 2
// 0055e14e  836c241801           sub dword ptr [esp + 0x18], 1
// 0055e153  0f8567ffffff         jne 0x55e0c0
// 0055e159  e962060000           jmp 0x55e7c0
// 0055e15e  8b442424             mov eax, dword ptr [esp + 0x24]
// 0055e162  80780908             cmp byte ptr [eax + 9], 8
// 0055e166  0f856a020000         jne 0x55e3d6
// 0055e16c  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 0055e170  85ed                 test ebp, ebp
// 0055e172  0f8460010000         je 0x55e2d8
// 0055e178  837c243c00           cmp dword ptr [esp + 0x3c], 0
// 0055e17d  0f8455010000         je 0x55e2d8
// 0055e183  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0055e187  85c9                 test ecx, ecx
// 0055e189  0f8449010000         je 0x55e2d8
// 0055e18f  837c241000           cmp dword ptr [esp + 0x10], 0
// 0055e194  0f8626060000         jbe 0x55e7c0
// 0055e19a  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0055e19e  8b542410             mov edx, dword ptr [esp + 0x10]
// 0055e1a2  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 0055e1a6  8d7702               lea esi, [edi + 2]
// 0055e1a9  89542418             mov dword ptr [esp + 0x18], edx
// 0055e1ad  8b542434             mov edx, dword ptr [esp + 0x34]
// 0055e1b1  47                   inc edi
// 0055e1b2  8a4702               mov al, byte ptr [edi + 2]
// 0055e1b5  3cff                 cmp al, 0xff
// 0055e1b7  7522                 jne 0x55e1db
// 0055e1b9  0fb647ff             movzx eax, byte ptr [edi - 1]
// 0055e1bd  0fb60408             movzx eax, byte ptr [eax + ecx]
// 0055e1c1  8846fe               mov byte ptr [esi - 2], al
// 0055e1c4  0fb607               movzx eax, byte ptr [edi]
// 0055e1c7  0fb60408             movzx eax, byte ptr [eax + ecx]
// 0055e1cb  8846ff               mov byte ptr [esi - 1], al
// 0055e1ce  0fb64701             movzx eax, byte ptr [edi + 1]
// 0055e1d2  0fb60408             movzx eax, byte ptr [eax + ecx]
// 0055e1d6  e9e5000000           jmp 0x55e2c0
// 0055e1db  84c0                 test al, al
// 0055e1dd  7517                 jne 0x55e1f6
// 0055e1df  0fb64302             movzx eax, byte ptr [ebx + 2]
// 0055e1e3  8846fe               mov byte ptr [esi - 2], al
// 0055e1e6  0fb64304             movzx eax, byte ptr [ebx + 4]
// 0055e1ea  8846ff               mov byte ptr [esi - 1], al
// 0055e1ed  0fb64306             movzx eax, byte ptr [ebx + 6]
// 0055e1f1  e9ca000000           jmp 0x55e2c0
// 0055e1f6  0fb65fff             movzx ebx, byte ptr [edi - 1]
// 0055e1fa  0fb61c2b             movzx ebx, byte ptr [ebx + ebp]
// 0055e1fe  668b6a02             mov bp, word ptr [edx + 2]
// 0055e202  660fb6c0             movzx ax, al
// 0055e206  660fafd8             imul bx, ax
// 0055e20a  b9ff000000           mov ecx, 0xff
// 0055e20f  2bc8                 sub ecx, eax
// 0055e211  660fafe9             imul bp, cx
// 0055e215  6603dd               add bx, bp
// 0055e218  bd80000000           mov ebp, 0x80
// 0055e21d  6603dd               add bx, bp
// 0055e220  0fb7db               movzx ebx, bx
// 0055e223  0fb7eb               movzx ebp, bx
// 0055e226  8bdd                 mov ebx, ebp
// 0055e228  c1eb08               shr ebx, 8
// 0055e22b  03dd                 add ebx, ebp
// 0055e22d  8b6c243c             mov ebp, dword ptr [esp + 0x3c]
// 0055e231  c1fb08               sar ebx, 8
// 0055e234  0fb6db               movzx ebx, bl
// 0055e237  0fb61c2b             movzx ebx, byte ptr [ebx + ebp]
// 0055e23b  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 0055e23f  885efe               mov byte ptr [esi - 2], bl
// 0055e242  0fb61f               movzx ebx, byte ptr [edi]
// 0055e245  0fb61c2b             movzx ebx, byte ptr [ebx + ebp]
// 0055e249  668b6a04             mov bp, word ptr [edx + 4]
// 0055e24d  660fafd8             imul bx, ax
// 0055e251  660fafe9             imul bp, cx
// 0055e255  6603dd               add bx, bp
// 0055e258  bd80000000           mov ebp, 0x80
// 0055e25d  6603dd               add bx, bp
// 0055e260  0fb7db               movzx ebx, bx
// 0055e263  0fb7eb               movzx ebp, bx
// 0055e266  8bdd                 mov ebx, ebp
// 0055e268  c1eb08               shr ebx, 8
// 0055e26b  03dd                 add ebx, ebp
// 0055e26d  8b6c243c             mov ebp, dword ptr [esp + 0x3c]
// 0055e271  c1fb08               sar ebx, 8
// 0055e274  0fb6db               movzx ebx, bl
// 0055e277  0fb61c2b             movzx ebx, byte ptr [ebx + ebp]
// 0055e27b  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 0055e27f  885eff               mov byte ptr [esi - 1], bl
// 0055e282  0fb65f01             movzx ebx, byte ptr [edi + 1]
// 0055e286  0fb61c2b             movzx ebx, byte ptr [ebx + ebp]
// 0055e28a  660fafd8             imul bx, ax
// 0055e28e  668b4206             mov ax, word ptr [edx + 6]
// 0055e292  660fafc1             imul ax, cx
// 0055e296  6603d8               add bx, ax
// 0055e299  b980000000           mov ecx, 0x80
// 0055e29e  6603d9               add bx, cx
// 0055e2a1  0fb7c3               movzx eax, bx
// 0055e2a4  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 0055e2a8  8bc8                 mov ecx, eax
// 0055e2aa  c1e908               shr ecx, 8
// 0055e2ad  03c8                 add ecx, eax
// 0055e2af  c1f908               sar ecx, 8
// 0055e2b2  0fb6c1               movzx eax, cl
// 0055e2b5  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0055e2b9  8a0408               mov al, byte ptr [eax + ecx]
// 0055e2bc  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0055e2c0  8806                 mov byte ptr [esi], al
// 0055e2c2  83c704               add edi, 4
// 0055e2c5  83c603               add esi, 3
// 0055e2c8  836c241801           sub dword ptr [esp + 0x18], 1
// 0055e2cd  0f85dffeffff         jne 0x55e1b2
// 0055e2d3  e9e8040000           jmp 0x55e7c0
// 0055e2d8  837c241000           cmp dword ptr [esp + 0x10], 0
// 0055e2dd  0f86dd040000         jbe 0x55e7c0
// 0055e2e3  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0055e2e7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0055e2eb  8b542430             mov edx, dword ptr [esp + 0x30]
// 0055e2ef  8d7702               lea esi, [edi + 2]
// 0055e2f2  47                   inc edi
// 0055e2f3  894c2418             mov dword ptr [esp + 0x18], ecx
// 0055e2f7  8a4702               mov al, byte ptr [edi + 2]
// 0055e2fa  3cff                 cmp al, 0xff
// 0055e2fc  7517                 jne 0x55e315
// 0055e2fe  0fb647ff             movzx eax, byte ptr [edi - 1]
// 0055e302  8846fe               mov byte ptr [esi - 2], al
// 0055e305  8a0f                 mov cl, byte ptr [edi]
// 0055e307  884eff               mov byte ptr [esi - 1], cl
// 0055e30a  0fb64701             movzx eax, byte ptr [edi + 1]
// 0055e30e  8806                 mov byte ptr [esi], al
// 0055e310  e9ab000000           jmp 0x55e3c0
// 0055e315  84c0                 test al, al
// 0055e317  7516                 jne 0x55e32f
// 0055e319  0fb64a02             movzx ecx, byte ptr [edx + 2]
// 0055e31d  884efe               mov byte ptr [esi - 2], cl
// 0055e320  8a4204               mov al, byte ptr [edx + 4]
// 0055e323  8846ff               mov byte ptr [esi - 1], al
// 0055e326  0fb64a06             movzx ecx, byte ptr [edx + 6]
// 0055e32a  e98f000000           jmp 0x55e3be
// 0055e32f  0fb65fff             movzx ebx, byte ptr [edi - 1]
// 0055e333  668b6a02             mov bp, word ptr [edx + 2]
// 0055e337  660fb6c0             movzx ax, al
// 0055e33b  660fafd8             imul bx, ax
// 0055e33f  b9ff000000           mov ecx, 0xff
// 0055e344  2bc8                 sub ecx, eax
// 0055e346  660fafe9             imul bp, cx
// 0055e34a  6603dd               add bx, bp
// 0055e34d  bd80000000           mov ebp, 0x80
// 0055e352  6603dd               add bx, bp
// 0055e355  0fb7db               movzx ebx, bx
// 0055e358  0fb7eb               movzx ebp, bx
// 0055e35b  8bdd                 mov ebx, ebp
// 0055e35d  c1eb08               shr ebx, 8
// 0055e360  03dd                 add ebx, ebp
// 0055e362  c1fb08               sar ebx, 8
// 0055e365  885efe               mov byte ptr [esi - 2], bl
// 0055e368  0fb75a04             movzx ebx, word ptr [edx + 4]
// 0055e36c  660fb62f             movzx bp, byte ptr [edi]
// 0055e370  660fafd9             imul bx, cx
// 0055e374  660fafe8             imul bp, ax
// 0055e378  6603dd               add bx, bp
// 0055e37b  bd80000000           mov ebp, 0x80
// 0055e380  6603dd               add bx, bp
// 0055e383  0fb7db               movzx ebx, bx
// 0055e386  0fb7eb               movzx ebp, bx
// 0055e389  8bdd                 mov ebx, ebp
// 0055e38b  c1eb08               shr ebx, 8
// 0055e38e  03dd                 add ebx, ebp
// 0055e390  c1fb08               sar ebx, 8
// 0055e393  885eff               mov byte ptr [esi - 1], bl
// 0055e396  0fb65f01             movzx ebx, byte ptr [edi + 1]
// 0055e39a  660fafd8             imul bx, ax
// 0055e39e  668b4206             mov ax, word ptr [edx + 6]
// 0055e3a2  660fafc1             imul ax, cx
// 0055e3a6  6603d8               add bx, ax
// 0055e3a9  b980000000           mov ecx, 0x80
// 0055e3ae  6603d9               add bx, cx
// 0055e3b1  0fb7c3               movzx eax, bx
// 0055e3b4  8bc8                 mov ecx, eax
// 0055e3b6  c1e908               shr ecx, 8
// 0055e3b9  03c8                 add ecx, eax
// 0055e3bb  c1f908               sar ecx, 8
// 0055e3be  880e                 mov byte ptr [esi], cl
// 0055e3c0  83c704               add edi, 4
// 0055e3c3  83c603               add esi, 3
// 0055e3c6  836c241801           sub dword ptr [esp + 0x18], 1
// 0055e3cb  0f8526ffffff         jne 0x55e2f7
// 0055e3d1  e9ea030000           jmp 0x55e7c0
// 0055e3d6  8b6c2444             mov ebp, dword ptr [esp + 0x44]
// 0055e3da  85ed                 test ebp, ebp
// 0055e3dc  0f8467020000         je 0x55e649
// 0055e3e2  837c244800           cmp dword ptr [esp + 0x48], 0
// 0055e3e7  0f845c020000         je 0x55e649
// 0055e3ed  837c244c00           cmp dword ptr [esp + 0x4c], 0
// 0055e3f2  0f8451020000         je 0x55e649
// 0055e3f8  85c9                 test ecx, ecx
// 0055e3fa  0f86c0030000         jbe 0x55e7c0
// 0055e400  8b542428             mov edx, dword ptr [esp + 0x28]
// 0055e404  8a5c2450             mov bl, byte ptr [esp + 0x50]
// 0055e408  8d4202               lea eax, [edx + 2]
// 0055e40b  42                   inc edx
// 0055e40c  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0055e410  660fb64a05           movzx cx, byte ptr [edx + 5]
// 0055e415  be00010000           mov esi, 0x100
// 0055e41a  660fafce             imul cx, si
// 0055e41e  660fb67206           movzx si, byte ptr [edx + 6]
// 0055e423  6603ce               add cx, si
// 0055e426  0fb7f1               movzx esi, cx
// 0055e429  b9ffff0000           mov ecx, 0xffff
// 0055e42e  663bf1               cmp si, cx
// 0055e431  0f8583000000         jne 0x55e4ba
// 0055e437  0fb632               movzx esi, byte ptr [edx]
// 0055e43a  0fb6cb               movzx ecx, bl
// 0055e43d  d3ee                 shr esi, cl
// 0055e43f  894c2418             mov dword ptr [esp + 0x18], ecx
// 0055e443  0fb64aff             movzx ecx, byte ptr [edx - 1]
// 0055e447  8b74b500             mov esi, dword ptr [ebp + esi*4]
// 0055e44b  0fb7344e             movzx esi, word ptr [esi + ecx*2]
// 0055e44f  8bce                 mov ecx, esi
// 0055e451  c1e908               shr ecx, 8
// 0055e454  8848fe               mov byte ptr [eax - 2], cl
// 0055e457  89742414             mov dword ptr [esp + 0x14], esi
// 0055e45b  0fb64c2414           movzx ecx, byte ptr [esp + 0x14]
// 0055e460  8848ff               mov byte ptr [eax - 1], cl
// 0055e463  0fb67202             movzx esi, byte ptr [edx + 2]
// 0055e467  0fb64c2418           movzx ecx, byte ptr [esp + 0x18]
// 0055e46c  d3ee                 shr esi, cl
// 0055e46e  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 0055e472  8b74b500             mov esi, dword ptr [ebp + esi*4]
// 0055e476  0fb7344e             movzx esi, word ptr [esi + ecx*2]
// 0055e47a  8bce                 mov ecx, esi
// 0055e47c  c1e908               shr ecx, 8
// 0055e47f  8808                 mov byte ptr [eax], cl
// 0055e481  89742414             mov dword ptr [esp + 0x14], esi
// 0055e485  0fb64c2414           movzx ecx, byte ptr [esp + 0x14]
// 0055e48a  884801               mov byte ptr [eax + 1], cl
// 0055e48d  0fb67204             movzx esi, byte ptr [edx + 4]
// 0055e491  0fb64c2418           movzx ecx, byte ptr [esp + 0x18]
// 0055e496  d3ee                 shr esi, cl
// 0055e498  0fb64a03             movzx ecx, byte ptr [edx + 3]
// 0055e49c  8b74b500             mov esi, dword ptr [ebp + esi*4]
// 0055e4a0  0fb7344e             movzx esi, word ptr [esi + ecx*2]
// 0055e4a4  8bce                 mov ecx, esi
// 0055e4a6  c1e908               shr ecx, 8
// 0055e4a9  89742414             mov dword ptr [esp + 0x14], esi
// 0055e4ad  884802               mov byte ptr [eax + 2], cl
// 0055e4b0  0fb64c2414           movzx ecx, byte ptr [esp + 0x14]
// 0055e4b5  e976010000           jmp 0x55e630
// 0055e4ba  6685f6               test si, si
// 0055e4bd  7543                 jne 0x55e502
// 0055e4bf  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0055e4c3  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 0055e4c7  8848fe               mov byte ptr [eax - 2], cl
// 0055e4ca  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0055e4ce  0fb64902             movzx ecx, byte ptr [ecx + 2]
// 0055e4d2  8848ff               mov byte ptr [eax - 1], cl
// 0055e4d5  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0055e4d9  0fb64905             movzx ecx, byte ptr [ecx + 5]
// 0055e4dd  8808                 mov byte ptr [eax], cl
// 0055e4df  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0055e4e3  0fb64904             movzx ecx, byte ptr [ecx + 4]
// 0055e4e7  884801               mov byte ptr [eax + 1], cl
// 0055e4ea  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0055e4ee  0fb64907             movzx ecx, byte ptr [ecx + 7]
// 0055e4f2  884802               mov byte ptr [eax + 2], cl
// 0055e4f5  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0055e4f9  0fb64906             movzx ecx, byte ptr [ecx + 6]
// 0055e4fd  e92e010000           jmp 0x55e630
// 0055e502  0fb7fe               movzx edi, si
// 0055e505  0fb632               movzx esi, byte ptr [edx]
// 0055e508  0fb6cb               movzx ecx, bl
// 0055e50b  d3ee                 shr esi, cl
// 0055e50d  8b5c244c             mov ebx, dword ptr [esp + 0x4c]
// 0055e511  894c2418             mov dword ptr [esp + 0x18], ecx
// 0055e515  0fb64aff             movzx ecx, byte ptr [edx - 1]
// 0055e519  8b34b3               mov esi, dword ptr [ebx + esi*4]
// 0055e51c  0fb70c4e             movzx ecx, word ptr [esi + ecx*2]
// 0055e520  8b742434             mov esi, dword ptr [esp + 0x34]
// 0055e524  0fafcf               imul ecx, edi
// 0055e527  0fb77602             movzx esi, word ptr [esi + 2]
// 0055e52b  bdffff0000           mov ebp, 0xffff
// 0055e530  2bef                 sub ebp, edi
// 0055e532  0faff5               imul esi, ebp
// 0055e535  8d8c3100800000       lea ecx, [ecx + esi + 0x8000]
// 0055e53c  8bf1                 mov esi, ecx
// 0055e53e  c1ee10               shr esi, 0x10
// 0055e541  03f1                 add esi, ecx
// 0055e543  0fb74c2450           movzx ecx, word ptr [esp + 0x50]
// 0055e548  c1ee10               shr esi, 0x10
// 0055e54b  0fb7de               movzx ebx, si
// 0055e54e  894c2414             mov dword ptr [esp + 0x14], ecx
// 0055e552  0fb6f3               movzx esi, bl
// 0055e555  d3ee                 shr esi, cl
// 0055e557  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0055e55b  c1eb08               shr ebx, 8
// 0055e55e  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 0055e561  0fb70c59             movzx ecx, word ptr [ecx + ebx*2]
// 0055e565  8848ff               mov byte ptr [eax - 1], cl
// 0055e568  8bd9                 mov ebx, ecx
// 0055e56a  0fb64c2418           movzx ecx, byte ptr [esp + 0x18]
// 0055e56f  c1eb08               shr ebx, 8
// 0055e572  8858fe               mov byte ptr [eax - 2], bl
// 0055e575  0fb67202             movzx esi, byte ptr [edx + 2]
// 0055e579  d3ee                 shr esi, cl
// 0055e57b  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 0055e57f  8b5c244c             mov ebx, dword ptr [esp + 0x4c]
// 0055e583  8b34b3               mov esi, dword ptr [ebx + esi*4]
// 0055e586  0fb70c4e             movzx ecx, word ptr [esi + ecx*2]
// 0055e58a  8b742434             mov esi, dword ptr [esp + 0x34]
// 0055e58e  0fafcf               imul ecx, edi
// 0055e591  0fb77604             movzx esi, word ptr [esi + 4]
// 0055e595  0faff5               imul esi, ebp
// 0055e598  8d8c3100800000       lea ecx, [ecx + esi + 0x8000]
// 0055e59f  8bf1                 mov esi, ecx
// 0055e5a1  c1ee10               shr esi, 0x10
// 0055e5a4  03f1                 add esi, ecx
// 0055e5a6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0055e5aa  c1ee10               shr esi, 0x10
// 0055e5ad  0fb7de               movzx ebx, si
// 0055e5b0  0fb6f3               movzx esi, bl
// 0055e5b3  d3ee                 shr esi, cl
// 0055e5b5  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0055e5b9  c1eb08               shr ebx, 8
// 0055e5bc  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 0055e5bf  0fb70c59             movzx ecx, word ptr [ecx + ebx*2]
// 0055e5c3  8bd9                 mov ebx, ecx
// 0055e5c5  884801               mov byte ptr [eax + 1], cl
// 0055e5c8  0fb64c2418           movzx ecx, byte ptr [esp + 0x18]
// 0055e5cd  c1eb08               shr ebx, 8
// 0055e5d0  8818                 mov byte ptr [eax], bl
// 0055e5d2  0fb67204             movzx esi, byte ptr [edx + 4]
// 0055e5d6  8b5c244c             mov ebx, dword ptr [esp + 0x4c]
// 0055e5da  d3ee                 shr esi, cl
// 0055e5dc  0fb64a03             movzx ecx, byte ptr [edx + 3]
// 0055e5e0  8b34b3               mov esi, dword ptr [ebx + esi*4]
// 0055e5e3  0fb70c4e             movzx ecx, word ptr [esi + ecx*2]
// 0055e5e7  8b742434             mov esi, dword ptr [esp + 0x34]
// 0055e5eb  0fafcf               imul ecx, edi
// 0055e5ee  0fb77606             movzx esi, word ptr [esi + 6]
// 0055e5f2  0faff5               imul esi, ebp
// 0055e5f5  8d8c3100800000       lea ecx, [ecx + esi + 0x8000]
// 0055e5fc  8bf1                 mov esi, ecx
// 0055e5fe  c1ee10               shr esi, 0x10
// 0055e601  03f1                 add esi, ecx
// 0055e603  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0055e607  c1ee10               shr esi, 0x10
// 0055e60a  0fb7de               movzx ebx, si
// 0055e60d  0fb6f3               movzx esi, bl
// 0055e610  d3ee                 shr esi, cl
// 0055e612  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0055e616  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 0055e619  8b6c2444             mov ebp, dword ptr [esp + 0x44]
// 0055e61d  c1eb08               shr ebx, 8
// 0055e620  0fb70c59             movzx ecx, word ptr [ecx + ebx*2]
// 0055e624  8bd9                 mov ebx, ecx
// 0055e626  c1eb08               shr ebx, 8
// 0055e629  885802               mov byte ptr [eax + 2], bl
// 0055e62c  8a5c2450             mov bl, byte ptr [esp + 0x50]
// 0055e630  884803               mov byte ptr [eax + 3], cl
// 0055e633  83c208               add edx, 8
// 0055e636  83c006               add eax, 6
// 0055e639  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0055e63e  0f85ccfdffff         jne 0x55e410
// 0055e644  e977010000           jmp 0x55e7c0
// 0055e649  8bd1                 mov edx, ecx
// 0055e64b  85d2                 test edx, edx
// 0055e64d  0f866d010000         jbe 0x55e7c0
// 0055e653  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0055e657  8b742430             mov esi, dword ptr [esp + 0x30]
// 0055e65b  8d4102               lea eax, [ecx + 2]
// 0055e65e  83c107               add ecx, 7
// 0055e661  8954241c             mov dword ptr [esp + 0x1c], edx
// 0055e665  eb09                 jmp 0x55e670
// 0055e667  8da42400000000       lea esp, [esp]
// 0055e66e  8bff                 mov edi, edi
// 0055e670  660fb651ff           movzx dx, byte ptr [ecx - 1]
// 0055e675  bf00010000           mov edi, 0x100
// 0055e67a  660fafd7             imul dx, di
// 0055e67e  660fb639             movzx di, byte ptr [ecx]
// 0055e682  6603d7               add dx, di
// 0055e685  0fb7d2               movzx edx, dx
// 0055e688  bfffff0000           mov edi, 0xffff
// 0055e68d  663bd7               cmp dx, di
// 0055e690  7513                 jne 0x55e6a5
// 0055e692  8b51f9               mov edx, dword ptr [ecx - 7]
// 0055e695  8950fe               mov dword ptr [eax - 2], edx
// 0055e698  668b51fd             mov dx, word ptr [ecx - 3]
// 0055e69c  66895002             mov word ptr [eax + 2], dx
// 0055e6a0  e90a010000           jmp 0x55e7af
// 0055e6a5  6685d2               test dx, dx
// 0055e6a8  752b                 jne 0x55e6d5
// 0055e6aa  0fb65603             movzx edx, byte ptr [esi + 3]
// 0055e6ae  8850fe               mov byte ptr [eax - 2], dl
// 0055e6b1  0fb65602             movzx edx, byte ptr [esi + 2]
// 0055e6b5  8850ff               mov byte ptr [eax - 1], dl
// 0055e6b8  0fb65605             movzx edx, byte ptr [esi + 5]
// 0055e6bc  8810                 mov byte ptr [eax], dl
// 0055e6be  0fb65604             movzx edx, byte ptr [esi + 4]
// 0055e6c2  885001               mov byte ptr [eax + 1], dl
// 0055e6c5  0fb65607             movzx edx, byte ptr [esi + 7]
// 0055e6c9  885002               mov byte ptr [eax + 2], dl
// 0055e6cc  0fb65606             movzx edx, byte ptr [esi + 6]
// 0055e6d0  e9d7000000           jmp 0x55e7ac
// 0055e6d5  0fb671fb             movzx esi, byte ptr [ecx - 5]
// 0055e6d9  bf00010000           mov edi, 0x100
// 0055e6de  660faff7             imul si, di
// 0055e6e2  0fb679fc             movzx edi, byte ptr [ecx - 4]
// 0055e6e6  6603f7               add si, di
// 0055e6e9  0fb7f6               movzx esi, si
// 0055e6ec  89742418             mov dword ptr [esp + 0x18], esi
// 0055e6f0  0fb671fd             movzx esi, byte ptr [ecx - 3]
// 0055e6f4  bf00010000           mov edi, 0x100
// 0055e6f9  660faff7             imul si, di
// 0055e6fd  0fb679fe             movzx edi, byte ptr [ecx - 2]
// 0055e701  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 0055e705  6603f7               add si, di
// 0055e708  0fb7f6               movzx esi, si
// 0055e70b  89742414             mov dword ptr [esp + 0x14], esi
// 0055e70f  0fb7f2               movzx esi, dx
// 0055e712  660fb651f9           movzx dx, byte ptr [ecx - 7]
// 0055e717  bb00010000           mov ebx, 0x100
// 0055e71c  660fafd3             imul dx, bx
// 0055e720  660fb659fa           movzx bx, byte ptr [ecx - 6]
// 0055e725  6603d3               add dx, bx
// 0055e728  0fb75d02             movzx ebx, word ptr [ebp + 2]
// 0055e72c  0fb7d2               movzx edx, dx
// 0055e72f  0fafd6               imul edx, esi
// 0055e732  bfffff0000           mov edi, 0xffff
// 0055e737  2bfe                 sub edi, esi
// 0055e739  0fafdf               imul ebx, edi
// 0055e73c  8d9c1a00800000       lea ebx, [edx + ebx + 0x8000]
// 0055e743  8bd3                 mov edx, ebx
// 0055e745  c1ea10               shr edx, 0x10
// 0055e748  03d3                 add edx, ebx
// 0055e74a  c1ea10               shr edx, 0x10
// 0055e74d  8bda                 mov ebx, edx
// 0055e74f  8850ff               mov byte ptr [eax - 1], dl
// 0055e752  c1eb08               shr ebx, 8
// 0055e755  8858fe               mov byte ptr [eax - 2], bl
// 0055e758  0fb75504             movzx edx, word ptr [ebp + 4]
// 0055e75c  0fb75c2418           movzx ebx, word ptr [esp + 0x18]
// 0055e761  0fafd7               imul edx, edi
// 0055e764  0fafde               imul ebx, esi
// 0055e767  8d9c1a00800000       lea ebx, [edx + ebx + 0x8000]
// 0055e76e  8bd3                 mov edx, ebx
// 0055e770  c1ea10               shr edx, 0x10
// 0055e773  03d3                 add edx, ebx
// 0055e775  c1ea10               shr edx, 0x10
// 0055e778  8bda                 mov ebx, edx
// 0055e77a  885001               mov byte ptr [eax + 1], dl
// 0055e77d  c1eb08               shr ebx, 8
// 0055e780  8818                 mov byte ptr [eax], bl
// 0055e782  0fb75506             movzx edx, word ptr [ebp + 6]
// 0055e786  0fafd7               imul edx, edi
// 0055e789  0fb77c2414           movzx edi, word ptr [esp + 0x14]
// 0055e78e  0faffe               imul edi, esi
// 0055e791  8db43a00800000       lea esi, [edx + edi + 0x8000]
// 0055e798  8bd6                 mov edx, esi
// 0055e79a  c1ea10               shr edx, 0x10
// 0055e79d  03d6                 add edx, esi
// 0055e79f  c1ea10               shr edx, 0x10
// 0055e7a2  8bda                 mov ebx, edx
// 0055e7a4  c1eb08               shr ebx, 8
// 0055e7a7  885802               mov byte ptr [eax + 2], bl
// 0055e7aa  8bf5                 mov esi, ebp
// 0055e7ac  885003               mov byte ptr [eax + 3], dl
// 0055e7af  83c108               add ecx, 8
// 0055e7b2  83c006               add eax, 6
// 0055e7b5  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0055e7ba  0f85b0feffff         jne 0x55e670
// 0055e7c0  5f                   pop edi
// 0055e7c1  5e                   pop esi
// 0055e7c2  5b                   pop ebx
// 0055e7c3  8b542418             mov edx, dword ptr [esp + 0x18]
// 0055e7c7  8a4208               mov al, byte ptr [edx + 8]
// 0055e7ca  a804                 test al, 4
// 0055e7cc  7438                 je 0x55e806
// 0055e7ce  fe4a0a               dec byte ptr [edx + 0xa]
// 0055e7d1  8a4a0a               mov cl, byte ptr [edx + 0xa]
// 0055e7d4  24fb                 and al, 0xfb
// 0055e7d6  884208               mov byte ptr [edx + 8], al
// 0055e7d9  8a4209               mov al, byte ptr [edx + 9]
// 0055e7dc  f6e9                 imul cl
// 0055e7de  88420b               mov byte ptr [edx + 0xb], al
// 0055e7e1  3c08                 cmp al, 8
// 0055e7e3  0fb6c0               movzx eax, al
// 0055e7e6  7210                 jb 0x55e7f8
// 0055e7e8  c1e803               shr eax, 3
// 0055e7eb  0faf442404           imul eax, dword ptr [esp + 4]
// 0055e7f0  894204               mov dword ptr [edx + 4], eax
// 0055e7f3  5d                   pop ebp
// 0055e7f4  83c410               add esp, 0x10
// 0055e7f7  c3                   ret 
// 0055e7f8  0faf442404           imul eax, dword ptr [esp + 4]
// 0055e7fd  83c007               add eax, 7
// 0055e800  c1e803               shr eax, 3
// 0055e803  894204               mov dword ptr [edx + 4], eax
// 0055e806  5d                   pop ebp
// 0055e807  83c410               add esp, 0x10
// 0055e80a  c3                   ret 
// 0055e80b  90                   nop 
// 0055e80c  ffd7                 call edi
// 0055e80e  55                   push ebp
// 0055e80f  00c0                 add al, al
// 0055e811  e755                 out 0x55, eax
// 0055e813  00a5db5500c0         add byte ptr [ebp - 0x3fffaa25], ah
// 0055e819  e755                 out 0x55, eax
// 0055e81b  004dde               add byte ptr [ebp - 0x22], cl
// 0055e81e  55                   push ebp
// 0055e81f  00c0                 add al, al
// 0055e821  e755                 out 0x55, eax
// 0055e823  005ee1               add byte ptr [esi - 0x1f], bl
// 0055e826  55                   push ebp
// 0055e827  001f                 add byte ptr [edi], bl
// 0055e829  d85500               fcom dword ptr [ebp]
// 0055e82c  82d855               sbb al, 0x55
// 0055e82f  008ed9550086         add byte ptr [esi - 0x79ffaa27], cl
// 0055e835  da5500               ficom dword ptr [ebp]
// 0055e838  eada5500c0e755       ljmp 0x55e7:0xc00055da
// 0055e83f  0000                 add byte ptr [eax], al
// 0055e841  010502050505         add dword ptr [0x5050502], eax
// 0055e847  030505050505         add eax, dword ptr [0x5050505]
// library libpng-1.2.6/pngrtran.c (function _png_do_background)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.6 pngrtran.c
