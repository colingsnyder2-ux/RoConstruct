// from server: 100% by auto
// roc 2009-12 00606b90  unit: seg_00600000  size: 1859 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00606b90
//
// 00606b90  83ec2c               sub esp, 0x2c
// 00606b93  8b542434             mov edx, dword ptr [esp + 0x34]
// 00606b97  8b0a                 mov ecx, dword ptr [edx]
// 00606b99  8a5208               mov dl, byte ptr [edx + 8]
// 00606b9c  33c0                 xor eax, eax
// 00606b9e  894c2408             mov dword ptr [esp + 8], ecx
// 00606ba2  89442404             mov dword ptr [esp + 4], eax
// 00606ba6  f6c202               test dl, 2
// 00606ba9  0f8420070000         je 0x6072cf
// 00606baf  8b442430             mov eax, dword ptr [esp + 0x30]
// 00606bb3  53                   push ebx
// 00606bb4  0fb7982e020000       movzx ebx, word ptr [eax + 0x22e]
// 00606bbb  55                   push ebp
// 00606bbc  56                   push esi
// 00606bbd  0fb7b02c020000       movzx esi, word ptr [eax + 0x22c]
// 00606bc4  57                   push edi
// 00606bc5  0fb7b82a020000       movzx edi, word ptr [eax + 0x22a]
// 00606bcc  897c2434             mov dword ptr [esp + 0x34], edi
// 00606bd0  8974241c             mov dword ptr [esp + 0x1c], esi
// 00606bd4  895c2430             mov dword ptr [esp + 0x30], ebx
// 00606bd8  80fa02               cmp dl, 2
// 00606bdb  0f8559030000         jne 0x606f3a
// 00606be1  8b542444             mov edx, dword ptr [esp + 0x44]
// 00606be5  807a0908             cmp byte ptr [edx + 9], 8
// 00606be9  0f853a010000         jne 0x606d29
// 00606bef  83b86801000000       cmp dword ptr [eax + 0x168], 0
// 00606bf6  0f84b5000000         je 0x606cb1
// 00606bfc  83b86c01000000       cmp dword ptr [eax + 0x16c], 0
// 00606c03  0f84a8000000         je 0x606cb1
// 00606c09  8b742448             mov esi, dword ptr [esp + 0x48]
// 00606c0d  89742420             mov dword ptr [esp + 0x20], esi
// 00606c11  85c9                 test ecx, ecx
// 00606c13  0f8625030000         jbe 0x606f3e
// 00606c19  894c2424             mov dword ptr [esp + 0x24], ecx
// 00606c1d  8d4900               lea ecx, [ecx]
// 00606c20  0fb60e               movzx ecx, byte ptr [esi]
// 00606c23  8ba86c010000         mov ebp, dword ptr [eax + 0x16c]
// 00606c29  0fb61429             movzx edx, byte ptr [ecx + ebp]
// 00606c2d  0fb64e01             movzx ecx, byte ptr [esi + 1]
// 00606c31  8a0c29               mov cl, byte ptr [ecx + ebp]
// 00606c34  46                   inc esi
// 00606c35  46                   inc esi
// 00606c36  88542412             mov byte ptr [esp + 0x12], dl
// 00606c3a  0fb616               movzx edx, byte ptr [esi]
// 00606c3d  0fb6142a             movzx edx, byte ptr [edx + ebp]
// 00606c41  88542411             mov byte ptr [esp + 0x11], dl
// 00606c45  8a542412             mov dl, byte ptr [esp + 0x12]
// 00606c49  46                   inc esi
// 00606c4a  884c2413             mov byte ptr [esp + 0x13], cl
// 00606c4e  3ad1                 cmp dl, cl
// 00606c50  7516                 jne 0x606c68
// 00606c52  3a542411             cmp dl, byte ptr [esp + 0x11]
// 00606c56  750c                 jne 0x606c64
// 00606c58  8a4eff               mov cl, byte ptr [esi - 1]
// 00606c5b  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00606c5f  884d00               mov byte ptr [ebp], cl
// 00606c62  eb38                 jmp 0x606c9c
// 00606c64  8a4c2413             mov cl, byte ptr [esp + 0x13]
// 00606c68  0fb6542411           movzx edx, byte ptr [esp + 0x11]
// 00606c6d  0fb6c9               movzx ecx, cl
// 00606c70  0fafd3               imul edx, ebx
// 00606c73  0faf4c241c           imul ecx, dword ptr [esp + 0x1c]
// 00606c78  834c241401           or dword ptr [esp + 0x14], 1
// 00606c7d  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00606c81  03d1                 add edx, ecx
// 00606c83  0fb64c2412           movzx ecx, byte ptr [esp + 0x12]
// 00606c88  0fafcf               imul ecx, edi
// 00606c8b  03d1                 add edx, ecx
// 00606c8d  8b8868010000         mov ecx, dword ptr [eax + 0x168]
// 00606c93  c1ea0f               shr edx, 0xf
// 00606c96  8a140a               mov dl, byte ptr [edx + ecx]
// 00606c99  885500               mov byte ptr [ebp], dl
// 00606c9c  45                   inc ebp
// 00606c9d  836c242401           sub dword ptr [esp + 0x24], 1
// 00606ca2  896c2420             mov dword ptr [esp + 0x20], ebp
// 00606ca6  0f8574ffffff         jne 0x606c20
// 00606cac  e985020000           jmp 0x606f36
// 00606cb1  8b742448             mov esi, dword ptr [esp + 0x48]
// 00606cb5  8bee                 mov ebp, esi
// 00606cb7  85c9                 test ecx, ecx
// 00606cb9  0f867b020000         jbe 0x606f3a
// 00606cbf  894c2424             mov dword ptr [esp + 0x24], ecx
// 00606cc3  0fb60e               movzx ecx, byte ptr [esi]
// 00606cc6  46                   inc esi
// 00606cc7  0fb65601             movzx edx, byte ptr [esi + 1]
// 00606ccb  884c2411             mov byte ptr [esp + 0x11], cl
// 00606ccf  8a0e                 mov cl, byte ptr [esi]
// 00606cd1  46                   inc esi
// 00606cd2  88542412             mov byte ptr [esp + 0x12], dl
// 00606cd6  8a542411             mov dl, byte ptr [esp + 0x11]
// 00606cda  46                   inc esi
// 00606cdb  884c2413             mov byte ptr [esp + 0x13], cl
// 00606cdf  3ad1                 cmp dl, cl
// 00606ce1  7512                 jne 0x606cf5
// 00606ce3  3a542412             cmp dl, byte ptr [esp + 0x12]
// 00606ce7  7508                 jne 0x606cf1
// 00606ce9  8a4eff               mov cl, byte ptr [esi - 1]
// 00606cec  884d00               mov byte ptr [ebp], cl
// 00606cef  eb2b                 jmp 0x606d1c
// 00606cf1  8a4c2413             mov cl, byte ptr [esp + 0x13]
// 00606cf5  0fb6542412           movzx edx, byte ptr [esp + 0x12]
// 00606cfa  0fb6c9               movzx ecx, cl
// 00606cfd  0fafd3               imul edx, ebx
// 00606d00  0faf4c241c           imul ecx, dword ptr [esp + 0x1c]
// 00606d05  834c241401           or dword ptr [esp + 0x14], 1
// 00606d0a  03d1                 add edx, ecx
// 00606d0c  0fb64c2411           movzx ecx, byte ptr [esp + 0x11]
// 00606d11  0fafcf               imul ecx, edi
// 00606d14  03d1                 add edx, ecx
// 00606d16  c1ea0f               shr edx, 0xf
// 00606d19  885500               mov byte ptr [ebp], dl
// 00606d1c  45                   inc ebp
// 00606d1d  836c242401           sub dword ptr [esp + 0x24], 1
// 00606d22  759f                 jne 0x606cc3
// 00606d24  e90d020000           jmp 0x606f36
// 00606d29  83b87801000000       cmp dword ptr [eax + 0x178], 0
// 00606d30  0f843e010000         je 0x606e74
// 00606d36  83b87401000000       cmp dword ptr [eax + 0x174], 0
// 00606d3d  0f8431010000         je 0x606e74
// 00606d43  8b542448             mov edx, dword ptr [esp + 0x48]
// 00606d47  89542420             mov dword ptr [esp + 0x20], edx
// 00606d4b  85c9                 test ecx, ecx
// 00606d4d  0f86e7010000         jbe 0x606f3a
// 00606d53  894c2428             mov dword ptr [esp + 0x28], ecx
// 00606d57  eb07                 jmp 0x606d60
// 00606d59  8da42400000000       lea esp, [esp]
// 00606d60  0fb60a               movzx ecx, byte ptr [edx]
// 00606d63  0fb67201             movzx esi, byte ptr [edx + 1]
// 00606d67  66c1e108             shl cx, 8
// 00606d6b  660bce               or cx, si
// 00606d6e  0fb67203             movzx esi, byte ptr [edx + 3]
// 00606d72  0fb7e9               movzx ebp, cx
// 00606d75  0fb64a02             movzx ecx, byte ptr [edx + 2]
// 00606d79  83c202               add edx, 2
// 00606d7c  66c1e108             shl cx, 8
// 00606d80  660bce               or cx, si
// 00606d83  0fb67203             movzx esi, byte ptr [edx + 3]
// 00606d87  0fb7c9               movzx ecx, cx
// 00606d8a  83c202               add edx, 2
// 00606d8d  894c2424             mov dword ptr [esp + 0x24], ecx
// 00606d91  0fb60a               movzx ecx, byte ptr [edx]
// 00606d94  66c1e108             shl cx, 8
// 00606d98  660bce               or cx, si
// 00606d9b  83c202               add edx, 2
// 00606d9e  0fb7f1               movzx esi, cx
// 00606da1  89542438             mov dword ptr [esp + 0x38], edx
// 00606da5  663b6c2424           cmp bp, word ptr [esp + 0x24]
// 00606daa  750d                 jne 0x606db9
// 00606dac  663bee               cmp bp, si
// 00606daf  7508                 jne 0x606db9
// 00606db1  0fb7f5               movzx esi, bp
// 00606db4  e989000000           jmp 0x606e42
// 00606db9  0fb75c2424           movzx ebx, word ptr [esp + 0x24]
// 00606dbe  0fb78858010000       movzx ecx, word ptr [eax + 0x158]
// 00606dc5  895c242c             mov dword ptr [esp + 0x2c], ebx
// 00606dc9  0fb7dd               movzx ebx, bp
// 00606dcc  0fb6eb               movzx ebp, bl
// 00606dcf  d3ed                 shr ebp, cl
// 00606dd1  0fb7d6               movzx edx, si
// 00606dd4  8bb078010000         mov esi, dword ptr [eax + 0x178]
// 00606dda  8b2cae               mov ebp, dword ptr [esi + ebp*4]
// 00606ddd  c1eb08               shr ebx, 8
// 00606de0  0fb76c5d00           movzx ebp, word ptr [ebp + ebx*2]
// 00606de5  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 00606de9  0fafef               imul ebp, edi
// 00606dec  0fb6fb               movzx edi, bl
// 00606def  d3ef                 shr edi, cl
// 00606df1  c1eb08               shr ebx, 8
// 00606df4  8b3cbe               mov edi, dword ptr [esi + edi*4]
// 00606df7  0fb73c5f             movzx edi, word ptr [edi + ebx*2]
// 00606dfb  0faf7c241c           imul edi, dword ptr [esp + 0x1c]
// 00606e00  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 00606e04  03ef                 add ebp, edi
// 00606e06  0fb6fa               movzx edi, dl
// 00606e09  d3ef                 shr edi, cl
// 00606e0b  c1ea08               shr edx, 8
// 00606e0e  8b34be               mov esi, dword ptr [esi + edi*4]
// 00606e11  0fb71456             movzx edx, word ptr [esi + edx*2]
// 00606e15  0fafd3               imul edx, ebx
// 00606e18  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00606e1c  03ea                 add ebp, edx
// 00606e1e  c1ed0f               shr ebp, 0xf
// 00606e21  0fb7d5               movzx edx, bp
// 00606e24  0fb6f2               movzx esi, dl
// 00606e27  d3ee                 shr esi, cl
// 00606e29  8b8874010000         mov ecx, dword ptr [eax + 0x174]
// 00606e2f  c1ea08               shr edx, 8
// 00606e32  834c241401           or dword ptr [esp + 0x14], 1
// 00606e37  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 00606e3a  0fb73451             movzx esi, word ptr [ecx + edx*2]
// 00606e3e  8b542438             mov edx, dword ptr [esp + 0x38]
// 00606e42  8bce                 mov ecx, esi
// 00606e44  89742424             mov dword ptr [esp + 0x24], esi
// 00606e48  8b742420             mov esi, dword ptr [esp + 0x20]
// 00606e4c  c1e908               shr ecx, 8
// 00606e4f  880e                 mov byte ptr [esi], cl
// 00606e51  8a4c2424             mov cl, byte ptr [esp + 0x24]
// 00606e55  46                   inc esi
// 00606e56  880e                 mov byte ptr [esi], cl
// 00606e58  b901000000           mov ecx, 1
// 00606e5d  89742420             mov dword ptr [esp + 0x20], esi
// 00606e61  014c2420             add dword ptr [esp + 0x20], ecx
// 00606e65  294c2428             sub dword ptr [esp + 0x28], ecx
// 00606e69  0f85f1feffff         jne 0x606d60
// 00606e6f  e9c2000000           jmp 0x606f36
// 00606e74  8b542448             mov edx, dword ptr [esp + 0x48]
// 00606e78  8bf2                 mov esi, edx
// 00606e7a  85c9                 test ecx, ecx
// 00606e7c  0f86b8000000         jbe 0x606f3a
// 00606e82  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00606e86  eb08                 jmp 0x606e90
// 00606e88  8da42400000000       lea esp, [esp]
// 00606e8f  90                   nop 
// 00606e90  0fb60a               movzx ecx, byte ptr [edx]
// 00606e93  660fb66a01           movzx bp, byte ptr [edx + 1]
// 00606e98  66c1e108             shl cx, 8
// 00606e9c  660bcd               or cx, bp
// 00606e9f  660fb66a03           movzx bp, byte ptr [edx + 3]
// 00606ea4  0fb7c9               movzx ecx, cx
// 00606ea7  894c2420             mov dword ptr [esp + 0x20], ecx
// 00606eab  0fb64a02             movzx ecx, byte ptr [edx + 2]
// 00606eaf  83c202               add edx, 2
// 00606eb2  66c1e108             shl cx, 8
// 00606eb6  660bcd               or cx, bp
// 00606eb9  660fb66a03           movzx bp, byte ptr [edx + 3]
// 00606ebe  0fb7c9               movzx ecx, cx
// 00606ec1  894c2424             mov dword ptr [esp + 0x24], ecx
// 00606ec5  0fb64a02             movzx ecx, byte ptr [edx + 2]
// 00606ec9  83c202               add edx, 2
// 00606ecc  66c1e108             shl cx, 8
// 00606ed0  660bcd               or cx, bp
// 00606ed3  0fb7c9               movzx ecx, cx
// 00606ed6  894c2428             mov dword ptr [esp + 0x28], ecx
// 00606eda  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00606ede  83c202               add edx, 2
// 00606ee1  663b4c2424           cmp cx, word ptr [esp + 0x24]
// 00606ee6  7507                 jne 0x606eef
// 00606ee8  663b4c2428           cmp cx, word ptr [esp + 0x28]
// 00606eed  7405                 je 0x606ef4
// 00606eef  834c241401           or dword ptr [esp + 0x14], 1
// 00606ef4  0fb74c2428           movzx ecx, word ptr [esp + 0x28]
// 00606ef9  0fb76c2424           movzx ebp, word ptr [esp + 0x24]
// 00606efe  0fafcb               imul ecx, ebx
// 00606f01  0faf6c241c           imul ebp, dword ptr [esp + 0x1c]
// 00606f06  03cd                 add ecx, ebp
// 00606f08  0fb76c2420           movzx ebp, word ptr [esp + 0x20]
// 00606f0d  0fafef               imul ebp, edi
// 00606f10  03cd                 add ecx, ebp
// 00606f12  c1e90f               shr ecx, 0xf
// 00606f15  0fb7e9               movzx ebp, cx
// 00606f18  8bcd                 mov ecx, ebp
// 00606f1a  c1e908               shr ecx, 8
// 00606f1d  880e                 mov byte ptr [esi], cl
// 00606f1f  896c2438             mov dword ptr [esp + 0x38], ebp
// 00606f23  8a4c2438             mov cl, byte ptr [esp + 0x38]
// 00606f27  46                   inc esi
// 00606f28  880e                 mov byte ptr [esi], cl
// 00606f2a  46                   inc esi
// 00606f2b  836c242c01           sub dword ptr [esp + 0x2c], 1
// 00606f30  0f855affffff         jne 0x606e90
// 00606f36  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00606f3a  8b742448             mov esi, dword ptr [esp + 0x48]
// 00606f3e  8b542444             mov edx, dword ptr [esp + 0x44]
// 00606f42  807a0806             cmp byte ptr [edx + 8], 6
// 00606f46  0f853c030000         jne 0x607288
// 00606f4c  807a0908             cmp byte ptr [edx + 9], 8
// 00606f50  0f8527010000         jne 0x60707d
// 00606f56  83b86801000000       cmp dword ptr [eax + 0x168], 0
// 00606f5d  0f84ad000000         je 0x607010
// 00606f63  83b86c01000000       cmp dword ptr [eax + 0x16c], 0
// 00606f6a  0f84a0000000         je 0x607010
// 00606f70  837c241800           cmp dword ptr [esp + 0x18], 0
// 00606f75  8bee                 mov ebp, esi
// 00606f77  0f8607030000         jbe 0x607284
// 00606f7d  8b542418             mov edx, dword ptr [esp + 0x18]
// 00606f81  8954242c             mov dword ptr [esp + 0x2c], edx
// 00606f85  eb09                 jmp 0x606f90
// 00606f87  8da42400000000       lea esp, [esp]
// 00606f8e  8bff                 mov edi, edi
// 00606f90  0fb616               movzx edx, byte ptr [esi]
// 00606f93  8b886c010000         mov ecx, dword ptr [eax + 0x16c]
// 00606f99  0fb6140a             movzx edx, byte ptr [edx + ecx]
// 00606f9d  46                   inc esi
// 00606f9e  88542413             mov byte ptr [esp + 0x13], dl
// 00606fa2  0fb616               movzx edx, byte ptr [esi]
// 00606fa5  0fb6140a             movzx edx, byte ptr [edx + ecx]
// 00606fa9  46                   inc esi
// 00606faa  88542411             mov byte ptr [esp + 0x11], dl
// 00606fae  0fb616               movzx edx, byte ptr [esi]
// 00606fb1  0fb60c0a             movzx ecx, byte ptr [edx + ecx]
// 00606fb5  884c2412             mov byte ptr [esp + 0x12], cl
// 00606fb9  8a4c2413             mov cl, byte ptr [esp + 0x13]
// 00606fbd  46                   inc esi
// 00606fbe  3a4c2411             cmp cl, byte ptr [esp + 0x11]
// 00606fc2  7506                 jne 0x606fca
// 00606fc4  3a4c2412             cmp cl, byte ptr [esp + 0x12]
// 00606fc8  7405                 je 0x606fcf
// 00606fca  834c241401           or dword ptr [esp + 0x14], 1
// 00606fcf  0fb6542412           movzx edx, byte ptr [esp + 0x12]
// 00606fd4  0fb64c2411           movzx ecx, byte ptr [esp + 0x11]
// 00606fd9  0fafd3               imul edx, ebx
// 00606fdc  0faf4c241c           imul ecx, dword ptr [esp + 0x1c]
// 00606fe1  03d1                 add edx, ecx
// 00606fe3  0fb64c2413           movzx ecx, byte ptr [esp + 0x13]
// 00606fe8  0fafcf               imul ecx, edi
// 00606feb  03d1                 add edx, ecx
// 00606fed  8b8868010000         mov ecx, dword ptr [eax + 0x168]
// 00606ff3  c1ea0f               shr edx, 0xf
// 00606ff6  8a140a               mov dl, byte ptr [edx + ecx]
// 00606ff9  885500               mov byte ptr [ebp], dl
// 00606ffc  8a0e                 mov cl, byte ptr [esi]
// 00606ffe  45                   inc ebp
// 00606fff  884d00               mov byte ptr [ebp], cl
// 00607002  45                   inc ebp
// 00607003  46                   inc esi
// 00607004  836c242c01           sub dword ptr [esp + 0x2c], 1
// 00607009  7585                 jne 0x606f90
// 0060700b  e974020000           jmp 0x607284
// 00607010  8bc6                 mov eax, esi
// 00607012  85c9                 test ecx, ecx
// 00607014  0f866e020000         jbe 0x607288
// 0060701a  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0060701e  8bff                 mov edi, edi
// 00607020  8a08                 mov cl, byte ptr [eax]
// 00607022  0fb65001             movzx edx, byte ptr [eax + 1]
// 00607026  40                   inc eax
// 00607027  40                   inc eax
// 00607028  88542412             mov byte ptr [esp + 0x12], dl
// 0060702c  0fb610               movzx edx, byte ptr [eax]
// 0060702f  40                   inc eax
// 00607030  884c2411             mov byte ptr [esp + 0x11], cl
// 00607034  88542413             mov byte ptr [esp + 0x13], dl
// 00607038  3a4c2412             cmp cl, byte ptr [esp + 0x12]
// 0060703c  7504                 jne 0x607042
// 0060703e  3aca                 cmp cl, dl
// 00607040  7405                 je 0x607047
// 00607042  834c241401           or dword ptr [esp + 0x14], 1
// 00607047  0fb64c2413           movzx ecx, byte ptr [esp + 0x13]
// 0060704c  0fb6542412           movzx edx, byte ptr [esp + 0x12]
// 00607051  0fafcb               imul ecx, ebx
// 00607054  0faf54241c           imul edx, dword ptr [esp + 0x1c]
// 00607059  03ca                 add ecx, edx
// 0060705b  0fb6542411           movzx edx, byte ptr [esp + 0x11]
// 00607060  0fafd7               imul edx, edi
// 00607063  03ca                 add ecx, edx
// 00607065  c1e90f               shr ecx, 0xf
// 00607068  880e                 mov byte ptr [esi], cl
// 0060706a  8a08                 mov cl, byte ptr [eax]
// 0060706c  46                   inc esi
// 0060706d  880e                 mov byte ptr [esi], cl
// 0060706f  46                   inc esi
// 00607070  40                   inc eax
// 00607071  836c242c01           sub dword ptr [esp + 0x2c], 1
// 00607076  75a8                 jne 0x607020
// 00607078  e907020000           jmp 0x607284
// 0060707d  83b87801000000       cmp dword ptr [eax + 0x178], 0
// 00607084  0f8439010000         je 0x6071c3
// 0060708a  83b87401000000       cmp dword ptr [eax + 0x174], 0
// 00607091  0f842c010000         je 0x6071c3
// 00607097  837c241800           cmp dword ptr [esp + 0x18], 0
// 0060709c  8bce                 mov ecx, esi
// 0060709e  89742428             mov dword ptr [esp + 0x28], esi
// 006070a2  0f86dc010000         jbe 0x607284
// 006070a8  8b542418             mov edx, dword ptr [esp + 0x18]
// 006070ac  89542424             mov dword ptr [esp + 0x24], edx
// 006070b0  0fb611               movzx edx, byte ptr [ecx]
// 006070b3  0fb65901             movzx ebx, byte ptr [ecx + 1]
// 006070b7  66c1e208             shl dx, 8
// 006070bb  660bd3               or dx, bx
// 006070be  0fb65903             movzx ebx, byte ptr [ecx + 3]
// 006070c2  0fb7ea               movzx ebp, dx
// 006070c5  0fb65102             movzx edx, byte ptr [ecx + 2]
// 006070c9  83c102               add ecx, 2
// 006070cc  66c1e208             shl dx, 8
// 006070d0  660bd3               or dx, bx
// 006070d3  0fb65903             movzx ebx, byte ptr [ecx + 3]
// 006070d7  0fb7d2               movzx edx, dx
// 006070da  8954242c             mov dword ptr [esp + 0x2c], edx
// 006070de  0fb65102             movzx edx, byte ptr [ecx + 2]
// 006070e2  83c102               add ecx, 2
// 006070e5  66c1e208             shl dx, 8
// 006070e9  660bd3               or dx, bx
// 006070ec  83c102               add ecx, 2
// 006070ef  0fb7d2               movzx edx, dx
// 006070f2  894c2420             mov dword ptr [esp + 0x20], ecx
// 006070f6  663b6c242c           cmp bp, word ptr [esp + 0x2c]
// 006070fb  750d                 jne 0x60710a
// 006070fd  663bea               cmp bp, dx
// 00607100  7508                 jne 0x60710a
// 00607102  0fb7d5               movzx edx, bp
// 00607105  e98b000000           jmp 0x607195
// 0060710a  0fb75c242c           movzx ebx, word ptr [esp + 0x2c]
// 0060710f  0fb78858010000       movzx ecx, word ptr [eax + 0x158]
// 00607116  8bb078010000         mov esi, dword ptr [eax + 0x178]
// 0060711c  895c2438             mov dword ptr [esp + 0x38], ebx
// 00607120  0fb7dd               movzx ebx, bp
// 00607123  0fb6eb               movzx ebp, bl
// 00607126  d3ed                 shr ebp, cl
// 00607128  c1eb08               shr ebx, 8
// 0060712b  0fb7d2               movzx edx, dx
// 0060712e  8b2cae               mov ebp, dword ptr [esi + ebp*4]
// 00607131  0fb76c5d00           movzx ebp, word ptr [ebp + ebx*2]
// 00607136  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 0060713a  0fafef               imul ebp, edi
// 0060713d  0fb6fb               movzx edi, bl
// 00607140  d3ef                 shr edi, cl
// 00607142  c1eb08               shr ebx, 8
// 00607145  8b3cbe               mov edi, dword ptr [esi + edi*4]
// 00607148  0fb73c5f             movzx edi, word ptr [edi + ebx*2]
// 0060714c  0faf7c241c           imul edi, dword ptr [esp + 0x1c]
// 00607151  03ef                 add ebp, edi
// 00607153  0fb6fa               movzx edi, dl
// 00607156  d3ef                 shr edi, cl
// 00607158  c1ea08               shr edx, 8
// 0060715b  8b34be               mov esi, dword ptr [esi + edi*4]
// 0060715e  0fb71456             movzx edx, word ptr [esi + edx*2]
// 00607162  0faf542430           imul edx, dword ptr [esp + 0x30]
// 00607167  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0060716b  03ea                 add ebp, edx
// 0060716d  c1ed0f               shr ebp, 0xf
// 00607170  0fb7d5               movzx edx, bp
// 00607173  0fb6f2               movzx esi, dl
// 00607176  d3ee                 shr esi, cl
// 00607178  8b8874010000         mov ecx, dword ptr [eax + 0x174]
// 0060717e  c1ea08               shr edx, 8
// 00607181  834c241401           or dword ptr [esp + 0x14], 1
// 00607186  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 00607189  0fb71451             movzx edx, word ptr [ecx + edx*2]
// 0060718d  8b742428             mov esi, dword ptr [esp + 0x28]
// 00607191  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00607195  8bda                 mov ebx, edx
// 00607197  c1eb08               shr ebx, 8
// 0060719a  881e                 mov byte ptr [esi], bl
// 0060719c  46                   inc esi
// 0060719d  8816                 mov byte ptr [esi], dl
// 0060719f  0fb611               movzx edx, byte ptr [ecx]
// 006071a2  46                   inc esi
// 006071a3  8816                 mov byte ptr [esi], dl
// 006071a5  0fb65101             movzx edx, byte ptr [ecx + 1]
// 006071a9  41                   inc ecx
// 006071aa  46                   inc esi
// 006071ab  8816                 mov byte ptr [esi], dl
// 006071ad  46                   inc esi
// 006071ae  41                   inc ecx
// 006071af  836c242401           sub dword ptr [esp + 0x24], 1
// 006071b4  89742428             mov dword ptr [esp + 0x28], esi
// 006071b8  0f85f2feffff         jne 0x6070b0
// 006071be  e9c1000000           jmp 0x607284
// 006071c3  837c241800           cmp dword ptr [esp + 0x18], 0
// 006071c8  8bc6                 mov eax, esi
// 006071ca  8bce                 mov ecx, esi
// 006071cc  0f86b2000000         jbe 0x607284
// 006071d2  8b542418             mov edx, dword ptr [esp + 0x18]
// 006071d6  89542430             mov dword ptr [esp + 0x30], edx
// 006071da  8d9b00000000         lea ebx, [ebx]
// 006071e0  0fb630               movzx esi, byte ptr [eax]
// 006071e3  0fb65001             movzx edx, byte ptr [eax + 1]
// 006071e7  66c1e608             shl si, 8
// 006071eb  660bd6               or dx, si
// 006071ee  0fb67002             movzx esi, byte ptr [eax + 2]
// 006071f2  0fb7d2               movzx edx, dx
// 006071f5  83c002               add eax, 2
// 006071f8  660fb66802           movzx bp, byte ptr [eax + 2]
// 006071fd  89542434             mov dword ptr [esp + 0x34], edx
// 00607201  0fb65001             movzx edx, byte ptr [eax + 1]
// 00607205  66c1e608             shl si, 8
// 00607209  83c002               add eax, 2
// 0060720c  660bd6               or dx, si
// 0060720f  0fb67001             movzx esi, byte ptr [eax + 1]
// 00607213  66c1e508             shl bp, 8
// 00607217  660bf5               or si, bp
// 0060721a  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0060721e  0fb7d2               movzx edx, dx
// 00607221  83c002               add eax, 2
// 00607224  0fb7f6               movzx esi, si
// 00607227  663bea               cmp bp, dx
// 0060722a  7505                 jne 0x607231
// 0060722c  663bee               cmp bp, si
// 0060722f  7405                 je 0x607236
// 00607231  834c241401           or dword ptr [esp + 0x14], 1
// 00607236  0fb7d2               movzx edx, dx
// 00607239  0faf54241c           imul edx, dword ptr [esp + 0x1c]
// 0060723e  0fb7f6               movzx esi, si
// 00607241  0faff3               imul esi, ebx
// 00607244  03f2                 add esi, edx
// 00607246  0fb7542434           movzx edx, word ptr [esp + 0x34]
// 0060724b  0fafd7               imul edx, edi
// 0060724e  03f2                 add esi, edx
// 00607250  c1ee0f               shr esi, 0xf
// 00607253  0fb7f6               movzx esi, si
// 00607256  8bd6                 mov edx, esi
// 00607258  c1ea08               shr edx, 8
// 0060725b  8811                 mov byte ptr [ecx], dl
// 0060725d  89742438             mov dword ptr [esp + 0x38], esi
// 00607261  0fb6542438           movzx edx, byte ptr [esp + 0x38]
// 00607266  41                   inc ecx
// 00607267  8811                 mov byte ptr [ecx], dl
// 00607269  0fb610               movzx edx, byte ptr [eax]
// 0060726c  41                   inc ecx
// 0060726d  8811                 mov byte ptr [ecx], dl
// 0060726f  0fb65001             movzx edx, byte ptr [eax + 1]
// 00607273  40                   inc eax
// 00607274  41                   inc ecx
// 00607275  8811                 mov byte ptr [ecx], dl
// 00607277  41                   inc ecx
// 00607278  40                   inc eax
// 00607279  836c243001           sub dword ptr [esp + 0x30], 1
// 0060727e  0f855cffffff         jne 0x6071e0
// 00607284  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00607288  8b742444             mov esi, dword ptr [esp + 0x44]
// 0060728c  80460afe             add byte ptr [esi + 0xa], 0xfe
// 00607290  8a4609               mov al, byte ptr [esi + 9]
// 00607293  8a560a               mov dl, byte ptr [esi + 0xa]
// 00607296  806608fd             and byte ptr [esi + 8], 0xfd
// 0060729a  f6ea                 imul dl
// 0060729c  88460b               mov byte ptr [esi + 0xb], al
// 0060729f  3c08                 cmp al, 8
// 006072a1  0fb6c0               movzx eax, al
// 006072a4  7215                 jb 0x6072bb
// 006072a6  c1e803               shr eax, 3
// 006072a9  0fafc1               imul eax, ecx
// 006072ac  5f                   pop edi
// 006072ad  894604               mov dword ptr [esi + 4], eax
// 006072b0  8b442410             mov eax, dword ptr [esp + 0x10]
// 006072b4  5e                   pop esi
// 006072b5  5d                   pop ebp
// 006072b6  5b                   pop ebx
// 006072b7  83c42c               add esp, 0x2c
// 006072ba  c3                   ret 
// 006072bb  0fafc1               imul eax, ecx
// 006072be  83c007               add eax, 7
// 006072c1  c1e803               shr eax, 3
// 006072c4  5f                   pop edi
// 006072c5  894604               mov dword ptr [esi + 4], eax
// 006072c8  8b442410             mov eax, dword ptr [esp + 0x10]
// 006072cc  5e                   pop esi
// 006072cd  5d                   pop ebp
// 006072ce  5b                   pop ebx
// 006072cf  83c42c               add esp, 0x2c
// 006072d2  c3                   ret 
// library libpng-1.2.6/pngrtran.c (function _png_do_rgb_to_gray)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.6 pngrtran.c
