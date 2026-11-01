// from server: 100% by auto
// roc 2010-06 00568c60  unit: seg_00560000  size: 4256 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00568c60
//
// 00568c60  83ec10               sub esp, 0x10
// 00568c63  837c242000           cmp dword ptr [esp + 0x20], 0
// 00568c68  8b442414             mov eax, dword ptr [esp + 0x14]
// 00568c6c  8b08                 mov ecx, dword ptr [eax]
// 00568c6e  890c24               mov dword ptr [esp], ecx
// 00568c71  0f8440100000         je 0x569cb7
// 00568c77  8a4008               mov al, byte ptr [eax + 8]
// 00568c7a  55                   push ebp
// 00568c7b  a804                 test al, 4
// 00568c7d  7416                 je 0x568c95
// 00568c7f  3c03                 cmp al, 3
// 00568c81  0f842f100000         je 0x569cb6
// 00568c87  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00568c8b  85ed                 test ebp, ebp
// 00568c8d  0f8423100000         je 0x569cb6
// 00568c93  eb04                 jmp 0x568c99
// 00568c95  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00568c99  0fb6c0               movzx eax, al
// 00568c9c  83f806               cmp eax, 6
// 00568c9f  0f87ce0f0000         ja 0x569c73
// 00568ca5  53                   push ebx
// 00568ca6  56                   push esi
// 00568ca7  57                   push edi
// 00568ca8  ff2485bc9c5600       jmp dword ptr [eax*4 + 0x569cbc]
// 00568caf  8b542424             mov edx, dword ptr [esp + 0x24]
// 00568cb3  0fb64209             movzx eax, byte ptr [edx + 9]
// 00568cb7  48                   dec eax
// 00568cb8  83f80f               cmp eax, 0xf
// 00568cbb  0f87af0f0000         ja 0x569c70
// 00568cc1  0fb680f09c5600       movzx eax, byte ptr [eax + 0x569cf0]
// 00568cc8  ff2485d89c5600       jmp dword ptr [eax*4 + 0x569cd8]
// 00568ccf  8b742428             mov esi, dword ptr [esp + 0x28]
// 00568cd3  ba07000000           mov edx, 7
// 00568cd8  85c9                 test ecx, ecx
// 00568cda  0f86900f0000         jbe 0x569c70
// 00568ce0  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00568ce4  8be9                 mov ebp, ecx
// 00568ce6  8a1e                 mov bl, byte ptr [esi]
// 00568ce8  8ac3                 mov al, bl
// 00568cea  8aca                 mov cl, dl
// 00568cec  d2e8                 shr al, cl
// 00568cee  2401                 and al, 1
// 00568cf0  660fb6c8             movzx cx, al
// 00568cf4  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00568cf8  663b4808             cmp cx, word ptr [eax + 8]
// 00568cfc  751d                 jne 0x568d1b
// 00568cfe  b907000000           mov ecx, 7
// 00568d03  2bca                 sub ecx, edx
// 00568d05  b87f7f0000           mov eax, 0x7f7f
// 00568d0a  d3f8                 sar eax, cl
// 00568d0c  8bca                 mov ecx, edx
// 00568d0e  22c3                 and al, bl
// 00568d10  8806                 mov byte ptr [esi], al
// 00568d12  8a5f08               mov bl, byte ptr [edi + 8]
// 00568d15  d2e3                 shl bl, cl
// 00568d17  0ad8                 or bl, al
// 00568d19  881e                 mov byte ptr [esi], bl
// 00568d1b  85d2                 test edx, edx
// 00568d1d  7508                 jne 0x568d27
// 00568d1f  ba07000000           mov edx, 7
// 00568d24  46                   inc esi
// 00568d25  eb01                 jmp 0x568d28
// 00568d27  4a                   dec edx
// 00568d28  83ed01               sub ebp, 1
// 00568d2b  75b9                 jne 0x568ce6
// 00568d2d  e93e0f0000           jmp 0x569c70
// 00568d32  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 00568d36  8b742428             mov esi, dword ptr [esp + 0x28]
// 00568d3a  ba06000000           mov edx, 6
// 00568d3f  85ff                 test edi, edi
// 00568d41  0f8498000000         je 0x568ddf
// 00568d47  85c9                 test ecx, ecx
// 00568d49  0f86210f0000         jbe 0x569c70
// 00568d4f  894c2418             mov dword ptr [esp + 0x18], ecx
// 00568d53  8a1e                 mov bl, byte ptr [esi]
// 00568d55  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 00568d59  8aca                 mov cl, dl
// 00568d5b  8ac3                 mov al, bl
// 00568d5d  d2e8                 shr al, cl
// 00568d5f  2403                 and al, 3
// 00568d61  660fb6c8             movzx cx, al
// 00568d65  663b4d08             cmp cx, word ptr [ebp + 8]
// 00568d69  751f                 jne 0x568d8a
// 00568d6b  b906000000           mov ecx, 6
// 00568d70  2bca                 sub ecx, edx
// 00568d72  b83f3f0000           mov eax, 0x3f3f
// 00568d77  d3f8                 sar eax, cl
// 00568d79  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00568d7d  22c3                 and al, bl
// 00568d7f  8806                 mov byte ptr [esi], al
// 00568d81  8a5908               mov bl, byte ptr [ecx + 8]
// 00568d84  8bca                 mov ecx, edx
// 00568d86  d2e3                 shl bl, cl
// 00568d88  eb32                 jmp 0x568dbc
// 00568d8a  0fb6c0               movzx eax, al
// 00568d8d  8d0c8500000000       lea ecx, [eax*4]
// 00568d94  0bc8                 or ecx, eax
// 00568d96  03c9                 add ecx, ecx
// 00568d98  03c9                 add ecx, ecx
// 00568d9a  0bc8                 or ecx, eax
// 00568d9c  03c9                 add ecx, ecx
// 00568d9e  03c9                 add ecx, ecx
// 00568da0  0bc8                 or ecx, eax
// 00568da2  8a0439               mov al, byte ptr [ecx + edi]
// 00568da5  b906000000           mov ecx, 6
// 00568daa  2bca                 sub ecx, edx
// 00568dac  bb3f3f0000           mov ebx, 0x3f3f
// 00568db1  d3fb                 sar ebx, cl
// 00568db3  c0e806               shr al, 6
// 00568db6  8bca                 mov ecx, edx
// 00568db8  221e                 and bl, byte ptr [esi]
// 00568dba  d2e0                 shl al, cl
// 00568dbc  0ad8                 or bl, al
// 00568dbe  881e                 mov byte ptr [esi], bl
// 00568dc0  85d2                 test edx, edx
// 00568dc2  7508                 jne 0x568dcc
// 00568dc4  ba06000000           mov edx, 6
// 00568dc9  46                   inc esi
// 00568dca  eb03                 jmp 0x568dcf
// 00568dcc  83ea02               sub edx, 2
// 00568dcf  836c241801           sub dword ptr [esp + 0x18], 1
// 00568dd4  0f8579ffffff         jne 0x568d53
// 00568dda  e9910e0000           jmp 0x569c70
// 00568ddf  85c9                 test ecx, ecx
// 00568de1  0f86890e0000         jbe 0x569c70
// 00568de7  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00568deb  8be9                 mov ebp, ecx
// 00568ded  8d4900               lea ecx, [ecx]
// 00568df0  8a1e                 mov bl, byte ptr [esi]
// 00568df2  8ac3                 mov al, bl
// 00568df4  8aca                 mov cl, dl
// 00568df6  d2e8                 shr al, cl
// 00568df8  2403                 and al, 3
// 00568dfa  660fb6c8             movzx cx, al
// 00568dfe  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00568e02  663b4808             cmp cx, word ptr [eax + 8]
// 00568e06  751d                 jne 0x568e25
// 00568e08  b906000000           mov ecx, 6
// 00568e0d  2bca                 sub ecx, edx
// 00568e0f  b83f3f0000           mov eax, 0x3f3f
// 00568e14  d3f8                 sar eax, cl
// 00568e16  8bca                 mov ecx, edx
// 00568e18  22c3                 and al, bl
// 00568e1a  8806                 mov byte ptr [esi], al
// 00568e1c  8a5f08               mov bl, byte ptr [edi + 8]
// 00568e1f  d2e3                 shl bl, cl
// 00568e21  0ad8                 or bl, al
// 00568e23  881e                 mov byte ptr [esi], bl
// 00568e25  85d2                 test edx, edx
// 00568e27  7508                 jne 0x568e31
// 00568e29  ba06000000           mov edx, 6
// 00568e2e  46                   inc esi
// 00568e2f  eb03                 jmp 0x568e34
// 00568e31  83ea02               sub edx, 2
// 00568e34  83ed01               sub ebp, 1
// 00568e37  75b7                 jne 0x568df0
// 00568e39  e9320e0000           jmp 0x569c70
// 00568e3e  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 00568e42  8b742428             mov esi, dword ptr [esp + 0x28]
// 00568e46  ba04000000           mov edx, 4
// 00568e4b  85ff                 test edi, edi
// 00568e4d  0f8487000000         je 0x568eda
// 00568e53  85c9                 test ecx, ecx
// 00568e55  0f86150e0000         jbe 0x569c70
// 00568e5b  894c2418             mov dword ptr [esp + 0x18], ecx
// 00568e5f  90                   nop 
// 00568e60  8a1e                 mov bl, byte ptr [esi]
// 00568e62  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 00568e66  8aca                 mov cl, dl
// 00568e68  8ac3                 mov al, bl
// 00568e6a  d2e8                 shr al, cl
// 00568e6c  240f                 and al, 0xf
// 00568e6e  660fb6c8             movzx cx, al
// 00568e72  663b4d08             cmp cx, word ptr [ebp + 8]
// 00568e76  751f                 jne 0x568e97
// 00568e78  b904000000           mov ecx, 4
// 00568e7d  2bca                 sub ecx, edx
// 00568e7f  b80f0f0000           mov eax, 0xf0f
// 00568e84  d3f8                 sar eax, cl
// 00568e86  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00568e8a  22c3                 and al, bl
// 00568e8c  8806                 mov byte ptr [esi], al
// 00568e8e  8a5908               mov bl, byte ptr [ecx + 8]
// 00568e91  8bca                 mov ecx, edx
// 00568e93  d2e3                 shl bl, cl
// 00568e95  eb24                 jmp 0x568ebb
// 00568e97  0fb6c0               movzx eax, al
// 00568e9a  8bc8                 mov ecx, eax
// 00568e9c  c1e104               shl ecx, 4
// 00568e9f  0bc8                 or ecx, eax
// 00568ea1  8a0439               mov al, byte ptr [ecx + edi]
// 00568ea4  b904000000           mov ecx, 4
// 00568ea9  2bca                 sub ecx, edx
// 00568eab  bb0f0f0000           mov ebx, 0xf0f
// 00568eb0  d3fb                 sar ebx, cl
// 00568eb2  c0e804               shr al, 4
// 00568eb5  8bca                 mov ecx, edx
// 00568eb7  221e                 and bl, byte ptr [esi]
// 00568eb9  d2e0                 shl al, cl
// 00568ebb  0ad8                 or bl, al
// 00568ebd  881e                 mov byte ptr [esi], bl
// 00568ebf  85d2                 test edx, edx
// 00568ec1  7508                 jne 0x568ecb
// 00568ec3  ba04000000           mov edx, 4
// 00568ec8  46                   inc esi
// 00568ec9  eb03                 jmp 0x568ece
// 00568ecb  83ea04               sub edx, 4
// 00568ece  836c241801           sub dword ptr [esp + 0x18], 1
// 00568ed3  758b                 jne 0x568e60
// 00568ed5  e9960d0000           jmp 0x569c70
// 00568eda  85c9                 test ecx, ecx
// 00568edc  0f868e0d0000         jbe 0x569c70
// 00568ee2  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00568ee6  8be9                 mov ebp, ecx
// 00568ee8  8a1e                 mov bl, byte ptr [esi]
// 00568eea  8ac3                 mov al, bl
// 00568eec  8aca                 mov cl, dl
// 00568eee  d2e8                 shr al, cl
// 00568ef0  240f                 and al, 0xf
// 00568ef2  660fb6c8             movzx cx, al
// 00568ef6  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00568efa  663b4808             cmp cx, word ptr [eax + 8]
// 00568efe  751d                 jne 0x568f1d
// 00568f00  b904000000           mov ecx, 4
// 00568f05  2bca                 sub ecx, edx
// 00568f07  b80f0f0000           mov eax, 0xf0f
// 00568f0c  d3f8                 sar eax, cl
// 00568f0e  8bca                 mov ecx, edx
// 00568f10  22c3                 and al, bl
// 00568f12  8806                 mov byte ptr [esi], al
// 00568f14  8a5f08               mov bl, byte ptr [edi + 8]
// 00568f17  d2e3                 shl bl, cl
// 00568f19  0ad8                 or bl, al
// 00568f1b  881e                 mov byte ptr [esi], bl
// 00568f1d  85d2                 test edx, edx
// 00568f1f  7508                 jne 0x568f29
// 00568f21  ba04000000           mov edx, 4
// 00568f26  46                   inc esi
// 00568f27  eb03                 jmp 0x568f2c
// 00568f29  83ea04               sub edx, 4
// 00568f2c  83ed01               sub ebp, 1
// 00568f2f  75b7                 jne 0x568ee8
// 00568f31  e93a0d0000           jmp 0x569c70
// 00568f36  8b742438             mov esi, dword ptr [esp + 0x38]
// 00568f3a  8b442428             mov eax, dword ptr [esp + 0x28]
// 00568f3e  85f6                 test esi, esi
// 00568f40  7432                 je 0x568f74
// 00568f42  85c9                 test ecx, ecx
// 00568f44  0f86260d0000         jbe 0x569c70
// 00568f4a  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00568f4e  8bd1                 mov edx, ecx
// 00568f50  8a08                 mov cl, byte ptr [eax]
// 00568f52  660fb6d9             movzx bx, cl
// 00568f56  663b5d08             cmp bx, word ptr [ebp + 8]
// 00568f5a  7505                 jne 0x568f61
// 00568f5c  8a4f08               mov cl, byte ptr [edi + 8]
// 00568f5f  eb06                 jmp 0x568f67
// 00568f61  0fb6c9               movzx ecx, cl
// 00568f64  8a0c31               mov cl, byte ptr [ecx + esi]
// 00568f67  8808                 mov byte ptr [eax], cl
// 00568f69  40                   inc eax
// 00568f6a  83ea01               sub edx, 1
// 00568f6d  75e1                 jne 0x568f50
// 00568f6f  e9fc0c0000           jmp 0x569c70
// 00568f74  85c9                 test ecx, ecx
// 00568f76  0f86f40c0000         jbe 0x569c70
// 00568f7c  8b742430             mov esi, dword ptr [esp + 0x30]
// 00568f80  660fb610             movzx dx, byte ptr [eax]
// 00568f84  663b5508             cmp dx, word ptr [ebp + 8]
// 00568f88  7505                 jne 0x568f8f
// 00568f8a  8a5608               mov dl, byte ptr [esi + 8]
// 00568f8d  8810                 mov byte ptr [eax], dl
// 00568f8f  40                   inc eax
// 00568f90  83e901               sub ecx, 1
// 00568f93  75eb                 jne 0x568f80
// 00568f95  e9d60c0000           jmp 0x569c70
// 00568f9a  8b742444             mov esi, dword ptr [esp + 0x44]
// 00568f9e  8b442428             mov eax, dword ptr [esp + 0x28]
// 00568fa2  85f6                 test esi, esi
// 00568fa4  746b                 je 0x569011
// 00568fa6  85c9                 test ecx, ecx
// 00568fa8  0f86c20c0000         jbe 0x569c70
// 00568fae  8a5c2450             mov bl, byte ptr [esp + 0x50]
// 00568fb2  894c2418             mov dword ptr [esp + 0x18], ecx
// 00568fb6  8a10                 mov dl, byte ptr [eax]
// 00568fb8  8a4801               mov cl, byte ptr [eax + 1]
// 00568fbb  660fb6fa             movzx di, dl
// 00568fbf  bd00010000           mov ebp, 0x100
// 00568fc4  660faffd             imul di, bp
// 00568fc8  660fb6e9             movzx bp, cl
// 00568fcc  6603fd               add di, bp
// 00568fcf  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 00568fd3  663b7d08             cmp di, word ptr [ebp + 8]
// 00568fd7  750e                 jne 0x568fe7
// 00568fd9  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00568fdd  8a5709               mov dl, byte ptr [edi + 9]
// 00568fe0  8810                 mov byte ptr [eax], dl
// 00568fe2  8a4f08               mov cl, byte ptr [edi + 8]
// 00568fe5  eb18                 jmp 0x568fff
// 00568fe7  0fb6f9               movzx edi, cl
// 00568fea  8acb                 mov cl, bl
// 00568fec  d3ef                 shr edi, cl
// 00568fee  0fb6d2               movzx edx, dl
// 00568ff1  8b0cbe               mov ecx, dword ptr [esi + edi*4]
// 00568ff4  0fb70c51             movzx ecx, word ptr [ecx + edx*2]
// 00568ff8  8bd1                 mov edx, ecx
// 00568ffa  c1ea08               shr edx, 8
// 00568ffd  8810                 mov byte ptr [eax], dl
// 00568fff  884801               mov byte ptr [eax + 1], cl
// 00569002  83c002               add eax, 2
// 00569005  836c241801           sub dword ptr [esp + 0x18], 1
// 0056900a  75aa                 jne 0x568fb6
// 0056900c  e95f0c0000           jmp 0x569c70
// 00569011  85c9                 test ecx, ecx
// 00569013  0f86570c0000         jbe 0x569c70
// 00569019  8b742430             mov esi, dword ptr [esp + 0x30]
// 0056901d  8d4900               lea ecx, [ecx]
// 00569020  660fb610             movzx dx, byte ptr [eax]
// 00569024  bf00010000           mov edi, 0x100
// 00569029  660fafd7             imul dx, di
// 0056902d  660fb67801           movzx di, byte ptr [eax + 1]
// 00569032  6603d7               add dx, di
// 00569035  663b5508             cmp dx, word ptr [ebp + 8]
// 00569039  750d                 jne 0x569048
// 0056903b  0fb65609             movzx edx, byte ptr [esi + 9]
// 0056903f  8810                 mov byte ptr [eax], dl
// 00569041  0fb65608             movzx edx, byte ptr [esi + 8]
// 00569045  885001               mov byte ptr [eax + 1], dl
// 00569048  83c002               add eax, 2
// 0056904b  83e901               sub ecx, 1
// 0056904e  75d0                 jne 0x569020
// 00569050  e91b0c0000           jmp 0x569c70
// 00569055  8b442424             mov eax, dword ptr [esp + 0x24]
// 00569059  80780908             cmp byte ptr [eax + 9], 8
// 0056905d  0f85d2000000         jne 0x569135
// 00569063  8b542438             mov edx, dword ptr [esp + 0x38]
// 00569067  85d2                 test edx, edx
// 00569069  7476                 je 0x5690e1
// 0056906b  85c9                 test ecx, ecx
// 0056906d  0f86fd0b0000         jbe 0x569c70
// 00569073  8b442428             mov eax, dword ptr [esp + 0x28]
// 00569077  8b742430             mov esi, dword ptr [esp + 0x30]
// 0056907b  83c002               add eax, 2
// 0056907e  8bf9                 mov edi, ecx
// 00569080  8a48fe               mov cl, byte ptr [eax - 2]
// 00569083  660fb6d9             movzx bx, cl
// 00569087  663b5d02             cmp bx, word ptr [ebp + 2]
// 0056908b  7529                 jne 0x5690b6
// 0056908d  660fb658ff           movzx bx, byte ptr [eax - 1]
// 00569092  663b5d04             cmp bx, word ptr [ebp + 4]
// 00569096  751e                 jne 0x5690b6
// 00569098  660fb618             movzx bx, byte ptr [eax]
// 0056909c  663b5d06             cmp bx, word ptr [ebp + 6]
// 005690a0  7514                 jne 0x5690b6
// 005690a2  0fb64e02             movzx ecx, byte ptr [esi + 2]
// 005690a6  8848fe               mov byte ptr [eax - 2], cl
// 005690a9  0fb64e04             movzx ecx, byte ptr [esi + 4]
// 005690ad  8848ff               mov byte ptr [eax - 1], cl
// 005690b0  0fb64e06             movzx ecx, byte ptr [esi + 6]
// 005690b4  eb1c                 jmp 0x5690d2
// 005690b6  0fb6c9               movzx ecx, cl
// 005690b9  0fb60c11             movzx ecx, byte ptr [ecx + edx]
// 005690bd  8848fe               mov byte ptr [eax - 2], cl
// 005690c0  0fb648ff             movzx ecx, byte ptr [eax - 1]
// 005690c4  0fb60c11             movzx ecx, byte ptr [ecx + edx]
// 005690c8  8848ff               mov byte ptr [eax - 1], cl
// 005690cb  0fb608               movzx ecx, byte ptr [eax]
// 005690ce  0fb60c11             movzx ecx, byte ptr [ecx + edx]
// 005690d2  8808                 mov byte ptr [eax], cl
// 005690d4  83c003               add eax, 3
// 005690d7  83ef01               sub edi, 1
// 005690da  75a4                 jne 0x569080
// 005690dc  e98f0b0000           jmp 0x569c70
// 005690e1  85c9                 test ecx, ecx
// 005690e3  0f86870b0000         jbe 0x569c70
// 005690e9  8b442428             mov eax, dword ptr [esp + 0x28]
// 005690ed  8b742430             mov esi, dword ptr [esp + 0x30]
// 005690f1  83c002               add eax, 2
// 005690f4  660fb650fe           movzx dx, byte ptr [eax - 2]
// 005690f9  663b5502             cmp dx, word ptr [ebp + 2]
// 005690fd  7529                 jne 0x569128
// 005690ff  660fb650ff           movzx dx, byte ptr [eax - 1]
// 00569104  663b5504             cmp dx, word ptr [ebp + 4]
// 00569108  751e                 jne 0x569128
// 0056910a  660fb610             movzx dx, byte ptr [eax]
// 0056910e  663b5506             cmp dx, word ptr [ebp + 6]
// 00569112  7514                 jne 0x569128
// 00569114  0fb65602             movzx edx, byte ptr [esi + 2]
// 00569118  8850fe               mov byte ptr [eax - 2], dl
// 0056911b  0fb65604             movzx edx, byte ptr [esi + 4]
// 0056911f  8850ff               mov byte ptr [eax - 1], dl
// 00569122  0fb65606             movzx edx, byte ptr [esi + 6]
// 00569126  8810                 mov byte ptr [eax], dl
// 00569128  83c003               add eax, 3
// 0056912b  83e901               sub ecx, 1
// 0056912e  75c4                 jne 0x5690f4
// 00569130  e93b0b0000           jmp 0x569c70
// 00569135  8b742444             mov esi, dword ptr [esp + 0x44]
// 00569139  85f6                 test esi, esi
// 0056913b  0f841b010000         je 0x56925c
// 00569141  85c9                 test ecx, ecx
// 00569143  0f86270b0000         jbe 0x569c70
// 00569149  8b442428             mov eax, dword ptr [esp + 0x28]
// 0056914d  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00569151  83c002               add eax, 2
// 00569154  894c2418             mov dword ptr [esp + 0x18], ecx
// 00569158  eb06                 jmp 0x569160
// 0056915a  8d9b00000000         lea ebx, [ebx]
// 00569160  8a58fe               mov bl, byte ptr [eax - 2]
// 00569163  8a48ff               mov cl, byte ptr [eax - 1]
// 00569166  660fb6d3             movzx dx, bl
// 0056916a  bd00010000           mov ebp, 0x100
// 0056916f  660fafd5             imul dx, bp
// 00569173  660fb6e9             movzx bp, cl
// 00569177  6603d5               add dx, bp
// 0056917a  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0056917e  663b5502             cmp dx, word ptr [ebp + 2]
// 00569182  756a                 jne 0x5691ee
// 00569184  660fb610             movzx dx, byte ptr [eax]
// 00569188  bd00010000           mov ebp, 0x100
// 0056918d  660fafd5             imul dx, bp
// 00569191  660fb66801           movzx bp, byte ptr [eax + 1]
// 00569196  6603d5               add dx, bp
// 00569199  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0056919d  663b5504             cmp dx, word ptr [ebp + 4]
// 005691a1  754b                 jne 0x5691ee
// 005691a3  660fb65002           movzx dx, byte ptr [eax + 2]
// 005691a8  bd00010000           mov ebp, 0x100
// 005691ad  660fafd5             imul dx, bp
// 005691b1  660fb66803           movzx bp, byte ptr [eax + 3]
// 005691b6  6603d5               add dx, bp
// 005691b9  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 005691bd  663b5506             cmp dx, word ptr [ebp + 6]
// 005691c1  752b                 jne 0x5691ee
// 005691c3  0fb64f03             movzx ecx, byte ptr [edi + 3]
// 005691c7  8848fe               mov byte ptr [eax - 2], cl
// 005691ca  0fb65702             movzx edx, byte ptr [edi + 2]
// 005691ce  8850ff               mov byte ptr [eax - 1], dl
// 005691d1  0fb64f05             movzx ecx, byte ptr [edi + 5]
// 005691d5  8808                 mov byte ptr [eax], cl
// 005691d7  0fb65704             movzx edx, byte ptr [edi + 4]
// 005691db  885001               mov byte ptr [eax + 1], dl
// 005691de  0fb64f07             movzx ecx, byte ptr [edi + 7]
// 005691e2  884802               mov byte ptr [eax + 2], cl
// 005691e5  0fb65706             movzx edx, byte ptr [edi + 6]
// 005691e9  885003               mov byte ptr [eax + 3], dl
// 005691ec  eb5b                 jmp 0x569249
// 005691ee  0fb6542450           movzx edx, byte ptr [esp + 0x50]
// 005691f3  0fb6e9               movzx ebp, cl
// 005691f6  8aca                 mov cl, dl
// 005691f8  d3ed                 shr ebp, cl
// 005691fa  0fb6cb               movzx ecx, bl
// 005691fd  8b1cae               mov ebx, dword ptr [esi + ebp*4]
// 00569200  0fb70c4b             movzx ecx, word ptr [ebx + ecx*2]
// 00569204  8bd9                 mov ebx, ecx
// 00569206  c1eb08               shr ebx, 8
// 00569209  8858fe               mov byte ptr [eax - 2], bl
// 0056920c  0fb65801             movzx ebx, byte ptr [eax + 1]
// 00569210  8848ff               mov byte ptr [eax - 1], cl
// 00569213  8aca                 mov cl, dl
// 00569215  d3eb                 shr ebx, cl
// 00569217  0fb608               movzx ecx, byte ptr [eax]
// 0056921a  8b1c9e               mov ebx, dword ptr [esi + ebx*4]
// 0056921d  0fb70c4b             movzx ecx, word ptr [ebx + ecx*2]
// 00569221  8bd9                 mov ebx, ecx
// 00569223  c1eb08               shr ebx, 8
// 00569226  8818                 mov byte ptr [eax], bl
// 00569228  0fb65803             movzx ebx, byte ptr [eax + 3]
// 0056922c  884801               mov byte ptr [eax + 1], cl
// 0056922f  8aca                 mov cl, dl
// 00569231  0fb65002             movzx edx, byte ptr [eax + 2]
// 00569235  d3eb                 shr ebx, cl
// 00569237  8b0c9e               mov ecx, dword ptr [esi + ebx*4]
// 0056923a  0fb70c51             movzx ecx, word ptr [ecx + edx*2]
// 0056923e  8bd1                 mov edx, ecx
// 00569240  c1ea08               shr edx, 8
// 00569243  885002               mov byte ptr [eax + 2], dl
// 00569246  884803               mov byte ptr [eax + 3], cl
// 00569249  83c006               add eax, 6
// 0056924c  836c241801           sub dword ptr [esp + 0x18], 1
// 00569251  0f8509ffffff         jne 0x569160
// 00569257  e9140a0000           jmp 0x569c70
// 0056925c  85c9                 test ecx, ecx
// 0056925e  0f860c0a0000         jbe 0x569c70
// 00569264  8b442428             mov eax, dword ptr [esp + 0x28]
// 00569268  8b742430             mov esi, dword ptr [esp + 0x30]
// 0056926c  83c002               add eax, 2
// 0056926f  90                   nop 
// 00569270  660fb650fe           movzx dx, byte ptr [eax - 2]
// 00569275  bf00010000           mov edi, 0x100
// 0056927a  660fafd7             imul dx, di
// 0056927e  660fb678ff           movzx di, byte ptr [eax - 1]
// 00569283  6603d7               add dx, di
// 00569286  663b5502             cmp dx, word ptr [ebp + 2]
// 0056928a  7560                 jne 0x5692ec
// 0056928c  660fb610             movzx dx, byte ptr [eax]
// 00569290  bf00010000           mov edi, 0x100
// 00569295  660fafd7             imul dx, di
// 00569299  660fb67801           movzx di, byte ptr [eax + 1]
// 0056929e  6603d7               add dx, di
// 005692a1  663b5504             cmp dx, word ptr [ebp + 4]
// 005692a5  7545                 jne 0x5692ec
// 005692a7  660fb65002           movzx dx, byte ptr [eax + 2]
// 005692ac  bf00010000           mov edi, 0x100
// 005692b1  660fafd7             imul dx, di
// 005692b5  660fb67803           movzx di, byte ptr [eax + 3]
// 005692ba  6603d7               add dx, di
// 005692bd  663b5506             cmp dx, word ptr [ebp + 6]
// 005692c1  7529                 jne 0x5692ec
// 005692c3  0fb65603             movzx edx, byte ptr [esi + 3]
// 005692c7  8850fe               mov byte ptr [eax - 2], dl
// 005692ca  0fb65602             movzx edx, byte ptr [esi + 2]
// 005692ce  8850ff               mov byte ptr [eax - 1], dl
// 005692d1  0fb65605             movzx edx, byte ptr [esi + 5]
// 005692d5  8810                 mov byte ptr [eax], dl
// 005692d7  0fb65604             movzx edx, byte ptr [esi + 4]
// 005692db  885001               mov byte ptr [eax + 1], dl
// 005692de  0fb65607             movzx edx, byte ptr [esi + 7]
// 005692e2  885002               mov byte ptr [eax + 2], dl
// 005692e5  0fb65606             movzx edx, byte ptr [esi + 6]
// 005692e9  885003               mov byte ptr [eax + 3], dl
// 005692ec  83c006               add eax, 6
// 005692ef  83e901               sub ecx, 1
// 005692f2  0f8578ffffff         jne 0x569270
// 005692f8  e973090000           jmp 0x569c70
// 005692fd  8b442424             mov eax, dword ptr [esp + 0x24]
// 00569301  80780908             cmp byte ptr [eax + 9], 8
// 00569305  0f852d010000         jne 0x569438
// 0056930b  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 0056930f  85ff                 test edi, edi
// 00569311  0f84a9000000         je 0x5693c0
// 00569317  837c243c00           cmp dword ptr [esp + 0x3c], 0
// 0056931c  0f849e000000         je 0x5693c0
// 00569322  837c243800           cmp dword ptr [esp + 0x38], 0
// 00569327  0f8493000000         je 0x5693c0
// 0056932d  837c241000           cmp dword ptr [esp + 0x10], 0
// 00569332  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00569336  8bf1                 mov esi, ecx
// 00569338  0f8632090000         jbe 0x569c70
// 0056933e  8b542410             mov edx, dword ptr [esp + 0x10]
// 00569342  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 00569346  89542418             mov dword ptr [esp + 0x18], edx
// 0056934a  8d9b00000000         lea ebx, [ebx]
// 00569350  660fb64101           movzx ax, byte ptr [ecx + 1]
// 00569355  0fb7c0               movzx eax, ax
// 00569358  baff000000           mov edx, 0xff
// 0056935d  663bc2               cmp ax, dx
// 00569360  7509                 jne 0x56936b
// 00569362  0fb601               movzx eax, byte ptr [ecx]
// 00569365  8b542438             mov edx, dword ptr [esp + 0x38]
// 00569369  eb40                 jmp 0x5693ab
// 0056936b  6685c0               test ax, ax
// 0056936e  7509                 jne 0x569379
// 00569370  8b542430             mov edx, dword ptr [esp + 0x30]
// 00569374  8a4208               mov al, byte ptr [edx + 8]
// 00569377  eb35                 jmp 0x5693ae
// 00569379  0fb619               movzx ebx, byte ptr [ecx]
// 0056937c  660fb61c3b           movzx bx, byte ptr [ebx + edi]
// 00569381  2bd0                 sub edx, eax
// 00569383  660fafd8             imul bx, ax
// 00569387  660faf5508           imul dx, word ptr [ebp + 8]
// 0056938c  6603d3               add dx, bx
// 0056938f  b880000000           mov eax, 0x80
// 00569394  6603d0               add dx, ax
// 00569397  0fb7c2               movzx eax, dx
// 0056939a  8bd0                 mov edx, eax
// 0056939c  c1ea08               shr edx, 8
// 0056939f  03d0                 add edx, eax
// 005693a1  c1fa08               sar edx, 8
// 005693a4  0fb6c2               movzx eax, dl
// 005693a7  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 005693ab  8a0410               mov al, byte ptr [eax + edx]
// 005693ae  8806                 mov byte ptr [esi], al
// 005693b0  83c102               add ecx, 2
// 005693b3  46                   inc esi
// 005693b4  836c241801           sub dword ptr [esp + 0x18], 1
// 005693b9  7595                 jne 0x569350
// 005693bb  e9b0080000           jmp 0x569c70
// 005693c0  837c241000           cmp dword ptr [esp + 0x10], 0
// 005693c5  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005693c9  8bf1                 mov esi, ecx
// 005693cb  0f869f080000         jbe 0x569c70
// 005693d1  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005693d5  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 005693d9  8da42400000000       lea esp, [esp]
// 005693e0  8a4101               mov al, byte ptr [ecx + 1]
// 005693e3  3cff                 cmp al, 0xff
// 005693e5  7504                 jne 0x5693eb
// 005693e7  8a11                 mov dl, byte ptr [ecx]
// 005693e9  eb3d                 jmp 0x569428
// 005693eb  84c0                 test al, al
// 005693ed  7509                 jne 0x5693f8
// 005693ef  8b442430             mov eax, dword ptr [esp + 0x30]
// 005693f3  8a5008               mov dl, byte ptr [eax + 8]
// 005693f6  eb30                 jmp 0x569428
// 005693f8  660fb619             movzx bx, byte ptr [ecx]
// 005693fc  660fb6c0             movzx ax, al
// 00569400  baff000000           mov edx, 0xff
// 00569405  660fafd8             imul bx, ax
// 00569409  2bd0                 sub edx, eax
// 0056940b  660faf5508           imul dx, word ptr [ebp + 8]
// 00569410  6603d3               add dx, bx
// 00569413  b880000000           mov eax, 0x80
// 00569418  6603d0               add dx, ax
// 0056941b  0fb7c2               movzx eax, dx
// 0056941e  8bd0                 mov edx, eax
// 00569420  c1ea08               shr edx, 8
// 00569423  03d0                 add edx, eax
// 00569425  c1fa08               sar edx, 8
// 00569428  8816                 mov byte ptr [esi], dl
// 0056942a  83c102               add ecx, 2
// 0056942d  46                   inc esi
// 0056942e  83ef01               sub edi, 1
// 00569431  75ad                 jne 0x5693e0
// 00569433  e938080000           jmp 0x569c70
// 00569438  837c244400           cmp dword ptr [esp + 0x44], 0
// 0056943d  0f8407010000         je 0x56954a
// 00569443  837c244800           cmp dword ptr [esp + 0x48], 0
// 00569448  0f84fc000000         je 0x56954a
// 0056944e  837c244c00           cmp dword ptr [esp + 0x4c], 0
// 00569453  0f84f1000000         je 0x56954a
// 00569459  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056945d  8bf2                 mov esi, edx
// 0056945f  85c9                 test ecx, ecx
// 00569461  0f8609080000         jbe 0x569c70
// 00569467  8a5c2450             mov bl, byte ptr [esp + 0x50]
// 0056946b  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0056946f  8bc1                 mov eax, ecx
// 00569471  42                   inc edx
// 00569472  89442418             mov dword ptr [esp + 0x18], eax
// 00569476  eb08                 jmp 0x569480
// 00569478  8da42400000000       lea esp, [esp]
// 0056947f  90                   nop 
// 00569480  660fb64a01           movzx cx, byte ptr [edx + 1]
// 00569485  b800010000           mov eax, 0x100
// 0056948a  660fafc8             imul cx, ax
// 0056948e  660fb64202           movzx ax, byte ptr [edx + 2]
// 00569493  6603c8               add cx, ax
// 00569496  0fb7c1               movzx eax, cx
// 00569499  b9ffff0000           mov ecx, 0xffff
// 0056949e  663bc1               cmp ax, cx
// 005694a1  7519                 jne 0x5694bc
// 005694a3  0fb602               movzx eax, byte ptr [edx]
// 005694a6  8b6c2444             mov ebp, dword ptr [esp + 0x44]
// 005694aa  8acb                 mov cl, bl
// 005694ac  d3e8                 shr eax, cl
// 005694ae  0fb64aff             movzx ecx, byte ptr [edx - 1]
// 005694b2  8b448500             mov eax, dword ptr [ebp + eax*4]
// 005694b6  0fb70448             movzx eax, word ptr [eax + ecx*2]
// 005694ba  eb6e                 jmp 0x56952a
// 005694bc  6685c0               test ax, ax
// 005694bf  750d                 jne 0x5694ce
// 005694c1  8a4709               mov al, byte ptr [edi + 9]
// 005694c4  8806                 mov byte ptr [esi], al
// 005694c6  8a4f08               mov cl, byte ptr [edi + 8]
// 005694c9  884e01               mov byte ptr [esi + 1], cl
// 005694cc  eb66                 jmp 0x569534
// 005694ce  0fb63a               movzx edi, byte ptr [edx]
// 005694d1  8b6c244c             mov ebp, dword ptr [esp + 0x4c]
// 005694d5  8acb                 mov cl, bl
// 005694d7  d3ef                 shr edi, cl
// 005694d9  0fb64aff             movzx ecx, byte ptr [edx - 1]
// 005694dd  8b7cbd00             mov edi, dword ptr [ebp + edi*4]
// 005694e1  0fb70c4f             movzx ecx, word ptr [edi + ecx*2]
// 005694e5  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 005694e9  0fb77f08             movzx edi, word ptr [edi + 8]
// 005694ed  0fb7c0               movzx eax, ax
// 005694f0  0fafc8               imul ecx, eax
// 005694f3  bdffff0000           mov ebp, 0xffff
// 005694f8  2be8                 sub ebp, eax
// 005694fa  0faffd               imul edi, ebp
// 005694fd  8d8c3900800000       lea ecx, [ecx + edi + 0x8000]
// 00569504  8bc1                 mov eax, ecx
// 00569506  c1e810               shr eax, 0x10
// 00569509  03c1                 add eax, ecx
// 0056950b  c1e810               shr eax, 0x10
// 0056950e  0fb7c0               movzx eax, ax
// 00569511  0fb6f8               movzx edi, al
// 00569514  8acb                 mov cl, bl
// 00569516  d3ef                 shr edi, cl
// 00569518  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0056951c  c1e808               shr eax, 8
// 0056951f  8b0cb9               mov ecx, dword ptr [ecx + edi*4]
// 00569522  0fb70441             movzx eax, word ptr [ecx + eax*2]
// 00569526  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0056952a  8bc8                 mov ecx, eax
// 0056952c  c1e908               shr ecx, 8
// 0056952f  884601               mov byte ptr [esi + 1], al
// 00569532  880e                 mov byte ptr [esi], cl
// 00569534  83c204               add edx, 4
// 00569537  83c602               add esi, 2
// 0056953a  836c241801           sub dword ptr [esp + 0x18], 1
// 0056953f  0f853bffffff         jne 0x569480
// 00569545  e926070000           jmp 0x569c70
// 0056954a  837c241000           cmp dword ptr [esp + 0x10], 0
// 0056954f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00569553  8bf1                 mov esi, ecx
// 00569555  0f8615070000         jbe 0x569c70
// 0056955b  8b542410             mov edx, dword ptr [esp + 0x10]
// 0056955f  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 00569563  89542418             mov dword ptr [esp + 0x18], edx
// 00569567  8b542430             mov edx, dword ptr [esp + 0x30]
// 0056956b  83c103               add ecx, 3
// 0056956e  8bff                 mov edi, edi
// 00569570  660fb641ff           movzx ax, byte ptr [ecx - 1]
// 00569575  bf00010000           mov edi, 0x100
// 0056957a  660fafc7             imul ax, di
// 0056957e  660fb639             movzx di, byte ptr [ecx]
// 00569582  6603c7               add ax, di
// 00569585  0fb7c0               movzx eax, ax
// 00569588  bfffff0000           mov edi, 0xffff
// 0056958d  663bc7               cmp ax, di
// 00569590  7509                 jne 0x56959b
// 00569592  668b41fd             mov ax, word ptr [ecx - 3]
// 00569596  668906               mov word ptr [esi], ax
// 00569599  eb5d                 jmp 0x5695f8
// 0056959b  6685c0               test ax, ax
// 0056959e  750c                 jne 0x5695ac
// 005695a0  0fb64209             movzx eax, byte ptr [edx + 9]
// 005695a4  8806                 mov byte ptr [esi], al
// 005695a6  0fb64208             movzx eax, byte ptr [edx + 8]
// 005695aa  eb49                 jmp 0x5695f5
// 005695ac  660fb651fd           movzx dx, byte ptr [ecx - 3]
// 005695b1  bf00010000           mov edi, 0x100
// 005695b6  660fafd7             imul dx, di
// 005695ba  660fb679fe           movzx di, byte ptr [ecx - 2]
// 005695bf  6603d7               add dx, di
// 005695c2  0fb77d08             movzx edi, word ptr [ebp + 8]
// 005695c6  0fb7c0               movzx eax, ax
// 005695c9  0fb7d2               movzx edx, dx
// 005695cc  0fafd0               imul edx, eax
// 005695cf  bbffff0000           mov ebx, 0xffff
// 005695d4  2bd8                 sub ebx, eax
// 005695d6  0faffb               imul edi, ebx
// 005695d9  8d943a00800000       lea edx, [edx + edi + 0x8000]
// 005695e0  8bc2                 mov eax, edx
// 005695e2  c1e810               shr eax, 0x10
// 005695e5  03c2                 add eax, edx
// 005695e7  c1e810               shr eax, 0x10
// 005695ea  8bd0                 mov edx, eax
// 005695ec  c1ea08               shr edx, 8
// 005695ef  8816                 mov byte ptr [esi], dl
// 005695f1  8b542430             mov edx, dword ptr [esp + 0x30]
// 005695f5  884601               mov byte ptr [esi + 1], al
// 005695f8  83c104               add ecx, 4
// 005695fb  83c602               add esi, 2
// 005695fe  836c241801           sub dword ptr [esp + 0x18], 1
// 00569603  0f8567ffffff         jne 0x569570
// 00569609  e962060000           jmp 0x569c70
// 0056960e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00569612  80780908             cmp byte ptr [eax + 9], 8
// 00569616  0f856a020000         jne 0x569886
// 0056961c  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 00569620  85ed                 test ebp, ebp
// 00569622  0f8460010000         je 0x569788
// 00569628  837c243c00           cmp dword ptr [esp + 0x3c], 0
// 0056962d  0f8455010000         je 0x569788
// 00569633  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00569637  85c9                 test ecx, ecx
// 00569639  0f8449010000         je 0x569788
// 0056963f  837c241000           cmp dword ptr [esp + 0x10], 0
// 00569644  0f8626060000         jbe 0x569c70
// 0056964a  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0056964e  8b542410             mov edx, dword ptr [esp + 0x10]
// 00569652  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 00569656  8d7702               lea esi, [edi + 2]
// 00569659  89542418             mov dword ptr [esp + 0x18], edx
// 0056965d  8b542434             mov edx, dword ptr [esp + 0x34]
// 00569661  47                   inc edi
// 00569662  8a4702               mov al, byte ptr [edi + 2]
// 00569665  3cff                 cmp al, 0xff
// 00569667  7522                 jne 0x56968b
// 00569669  0fb647ff             movzx eax, byte ptr [edi - 1]
// 0056966d  0fb60408             movzx eax, byte ptr [eax + ecx]
// 00569671  8846fe               mov byte ptr [esi - 2], al
// 00569674  0fb607               movzx eax, byte ptr [edi]
// 00569677  0fb60408             movzx eax, byte ptr [eax + ecx]
// 0056967b  8846ff               mov byte ptr [esi - 1], al
// 0056967e  0fb64701             movzx eax, byte ptr [edi + 1]
// 00569682  0fb60408             movzx eax, byte ptr [eax + ecx]
// 00569686  e9e5000000           jmp 0x569770
// 0056968b  84c0                 test al, al
// 0056968d  7517                 jne 0x5696a6
// 0056968f  0fb64302             movzx eax, byte ptr [ebx + 2]
// 00569693  8846fe               mov byte ptr [esi - 2], al
// 00569696  0fb64304             movzx eax, byte ptr [ebx + 4]
// 0056969a  8846ff               mov byte ptr [esi - 1], al
// 0056969d  0fb64306             movzx eax, byte ptr [ebx + 6]
// 005696a1  e9ca000000           jmp 0x569770
// 005696a6  0fb65fff             movzx ebx, byte ptr [edi - 1]
// 005696aa  0fb61c2b             movzx ebx, byte ptr [ebx + ebp]
// 005696ae  668b6a02             mov bp, word ptr [edx + 2]
// 005696b2  660fb6c0             movzx ax, al
// 005696b6  660fafd8             imul bx, ax
// 005696ba  b9ff000000           mov ecx, 0xff
// 005696bf  2bc8                 sub ecx, eax
// 005696c1  660fafe9             imul bp, cx
// 005696c5  6603dd               add bx, bp
// 005696c8  bd80000000           mov ebp, 0x80
// 005696cd  6603dd               add bx, bp
// 005696d0  0fb7db               movzx ebx, bx
// 005696d3  0fb7eb               movzx ebp, bx
// 005696d6  8bdd                 mov ebx, ebp
// 005696d8  c1eb08               shr ebx, 8
// 005696db  03dd                 add ebx, ebp
// 005696dd  8b6c243c             mov ebp, dword ptr [esp + 0x3c]
// 005696e1  c1fb08               sar ebx, 8
// 005696e4  0fb6db               movzx ebx, bl
// 005696e7  0fb61c2b             movzx ebx, byte ptr [ebx + ebp]
// 005696eb  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 005696ef  885efe               mov byte ptr [esi - 2], bl
// 005696f2  0fb61f               movzx ebx, byte ptr [edi]
// 005696f5  0fb61c2b             movzx ebx, byte ptr [ebx + ebp]
// 005696f9  668b6a04             mov bp, word ptr [edx + 4]
// 005696fd  660fafd8             imul bx, ax
// 00569701  660fafe9             imul bp, cx
// 00569705  6603dd               add bx, bp
// 00569708  bd80000000           mov ebp, 0x80
// 0056970d  6603dd               add bx, bp
// 00569710  0fb7db               movzx ebx, bx
// 00569713  0fb7eb               movzx ebp, bx
// 00569716  8bdd                 mov ebx, ebp
// 00569718  c1eb08               shr ebx, 8
// 0056971b  03dd                 add ebx, ebp
// 0056971d  8b6c243c             mov ebp, dword ptr [esp + 0x3c]
// 00569721  c1fb08               sar ebx, 8
// 00569724  0fb6db               movzx ebx, bl
// 00569727  0fb61c2b             movzx ebx, byte ptr [ebx + ebp]
// 0056972b  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 0056972f  885eff               mov byte ptr [esi - 1], bl
// 00569732  0fb65f01             movzx ebx, byte ptr [edi + 1]
// 00569736  0fb61c2b             movzx ebx, byte ptr [ebx + ebp]
// 0056973a  660fafd8             imul bx, ax
// 0056973e  668b4206             mov ax, word ptr [edx + 6]
// 00569742  660fafc1             imul ax, cx
// 00569746  6603d8               add bx, ax
// 00569749  b980000000           mov ecx, 0x80
// 0056974e  6603d9               add bx, cx
// 00569751  0fb7c3               movzx eax, bx
// 00569754  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 00569758  8bc8                 mov ecx, eax
// 0056975a  c1e908               shr ecx, 8
// 0056975d  03c8                 add ecx, eax
// 0056975f  c1f908               sar ecx, 8
// 00569762  0fb6c1               movzx eax, cl
// 00569765  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00569769  8a0408               mov al, byte ptr [eax + ecx]
// 0056976c  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00569770  8806                 mov byte ptr [esi], al
// 00569772  83c704               add edi, 4
// 00569775  83c603               add esi, 3
// 00569778  836c241801           sub dword ptr [esp + 0x18], 1
// 0056977d  0f85dffeffff         jne 0x569662
// 00569783  e9e8040000           jmp 0x569c70
// 00569788  837c241000           cmp dword ptr [esp + 0x10], 0
// 0056978d  0f86dd040000         jbe 0x569c70
// 00569793  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00569797  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056979b  8b542430             mov edx, dword ptr [esp + 0x30]
// 0056979f  8d7702               lea esi, [edi + 2]
// 005697a2  47                   inc edi
// 005697a3  894c2418             mov dword ptr [esp + 0x18], ecx
// 005697a7  8a4702               mov al, byte ptr [edi + 2]
// 005697aa  3cff                 cmp al, 0xff
// 005697ac  7517                 jne 0x5697c5
// 005697ae  0fb647ff             movzx eax, byte ptr [edi - 1]
// 005697b2  8846fe               mov byte ptr [esi - 2], al
// 005697b5  8a0f                 mov cl, byte ptr [edi]
// 005697b7  884eff               mov byte ptr [esi - 1], cl
// 005697ba  0fb64701             movzx eax, byte ptr [edi + 1]
// 005697be  8806                 mov byte ptr [esi], al
// 005697c0  e9ab000000           jmp 0x569870
// 005697c5  84c0                 test al, al
// 005697c7  7516                 jne 0x5697df
// 005697c9  0fb64a02             movzx ecx, byte ptr [edx + 2]
// 005697cd  884efe               mov byte ptr [esi - 2], cl
// 005697d0  8a4204               mov al, byte ptr [edx + 4]
// 005697d3  8846ff               mov byte ptr [esi - 1], al
// 005697d6  0fb64a06             movzx ecx, byte ptr [edx + 6]
// 005697da  e98f000000           jmp 0x56986e
// 005697df  0fb65fff             movzx ebx, byte ptr [edi - 1]
// 005697e3  668b6a02             mov bp, word ptr [edx + 2]
// 005697e7  660fb6c0             movzx ax, al
// 005697eb  660fafd8             imul bx, ax
// 005697ef  b9ff000000           mov ecx, 0xff
// 005697f4  2bc8                 sub ecx, eax
// 005697f6  660fafe9             imul bp, cx
// 005697fa  6603dd               add bx, bp
// 005697fd  bd80000000           mov ebp, 0x80
// 00569802  6603dd               add bx, bp
// 00569805  0fb7db               movzx ebx, bx
// 00569808  0fb7eb               movzx ebp, bx
// 0056980b  8bdd                 mov ebx, ebp
// 0056980d  c1eb08               shr ebx, 8
// 00569810  03dd                 add ebx, ebp
// 00569812  c1fb08               sar ebx, 8
// 00569815  885efe               mov byte ptr [esi - 2], bl
// 00569818  0fb75a04             movzx ebx, word ptr [edx + 4]
// 0056981c  660fb62f             movzx bp, byte ptr [edi]
// 00569820  660fafd9             imul bx, cx
// 00569824  660fafe8             imul bp, ax
// 00569828  6603dd               add bx, bp
// 0056982b  bd80000000           mov ebp, 0x80
// 00569830  6603dd               add bx, bp
// 00569833  0fb7db               movzx ebx, bx
// 00569836  0fb7eb               movzx ebp, bx
// 00569839  8bdd                 mov ebx, ebp
// 0056983b  c1eb08               shr ebx, 8
// 0056983e  03dd                 add ebx, ebp
// 00569840  c1fb08               sar ebx, 8
// 00569843  885eff               mov byte ptr [esi - 1], bl
// 00569846  0fb65f01             movzx ebx, byte ptr [edi + 1]
// 0056984a  660fafd8             imul bx, ax
// 0056984e  668b4206             mov ax, word ptr [edx + 6]
// 00569852  660fafc1             imul ax, cx
// 00569856  6603d8               add bx, ax
// 00569859  b980000000           mov ecx, 0x80
// 0056985e  6603d9               add bx, cx
// 00569861  0fb7c3               movzx eax, bx
// 00569864  8bc8                 mov ecx, eax
// 00569866  c1e908               shr ecx, 8
// 00569869  03c8                 add ecx, eax
// 0056986b  c1f908               sar ecx, 8
// 0056986e  880e                 mov byte ptr [esi], cl
// 00569870  83c704               add edi, 4
// 00569873  83c603               add esi, 3
// 00569876  836c241801           sub dword ptr [esp + 0x18], 1
// 0056987b  0f8526ffffff         jne 0x5697a7
// 00569881  e9ea030000           jmp 0x569c70
// 00569886  8b6c2444             mov ebp, dword ptr [esp + 0x44]
// 0056988a  85ed                 test ebp, ebp
// 0056988c  0f8467020000         je 0x569af9
// 00569892  837c244800           cmp dword ptr [esp + 0x48], 0
// 00569897  0f845c020000         je 0x569af9
// 0056989d  837c244c00           cmp dword ptr [esp + 0x4c], 0
// 005698a2  0f8451020000         je 0x569af9
// 005698a8  85c9                 test ecx, ecx
// 005698aa  0f86c0030000         jbe 0x569c70
// 005698b0  8b542428             mov edx, dword ptr [esp + 0x28]
// 005698b4  8a5c2450             mov bl, byte ptr [esp + 0x50]
// 005698b8  8d4202               lea eax, [edx + 2]
// 005698bb  42                   inc edx
// 005698bc  894c241c             mov dword ptr [esp + 0x1c], ecx
// 005698c0  660fb64a05           movzx cx, byte ptr [edx + 5]
// 005698c5  be00010000           mov esi, 0x100
// 005698ca  660fafce             imul cx, si
// 005698ce  660fb67206           movzx si, byte ptr [edx + 6]
// 005698d3  6603ce               add cx, si
// 005698d6  0fb7f1               movzx esi, cx
// 005698d9  b9ffff0000           mov ecx, 0xffff
// 005698de  663bf1               cmp si, cx
// 005698e1  0f8583000000         jne 0x56996a
// 005698e7  0fb632               movzx esi, byte ptr [edx]
// 005698ea  0fb6cb               movzx ecx, bl
// 005698ed  d3ee                 shr esi, cl
// 005698ef  894c2418             mov dword ptr [esp + 0x18], ecx
// 005698f3  0fb64aff             movzx ecx, byte ptr [edx - 1]
// 005698f7  8b74b500             mov esi, dword ptr [ebp + esi*4]
// 005698fb  0fb7344e             movzx esi, word ptr [esi + ecx*2]
// 005698ff  8bce                 mov ecx, esi
// 00569901  c1e908               shr ecx, 8
// 00569904  8848fe               mov byte ptr [eax - 2], cl
// 00569907  89742414             mov dword ptr [esp + 0x14], esi
// 0056990b  0fb64c2414           movzx ecx, byte ptr [esp + 0x14]
// 00569910  8848ff               mov byte ptr [eax - 1], cl
// 00569913  0fb67202             movzx esi, byte ptr [edx + 2]
// 00569917  0fb64c2418           movzx ecx, byte ptr [esp + 0x18]
// 0056991c  d3ee                 shr esi, cl
// 0056991e  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00569922  8b74b500             mov esi, dword ptr [ebp + esi*4]
// 00569926  0fb7344e             movzx esi, word ptr [esi + ecx*2]
// 0056992a  8bce                 mov ecx, esi
// 0056992c  c1e908               shr ecx, 8
// 0056992f  8808                 mov byte ptr [eax], cl
// 00569931  89742414             mov dword ptr [esp + 0x14], esi
// 00569935  0fb64c2414           movzx ecx, byte ptr [esp + 0x14]
// 0056993a  884801               mov byte ptr [eax + 1], cl
// 0056993d  0fb67204             movzx esi, byte ptr [edx + 4]
// 00569941  0fb64c2418           movzx ecx, byte ptr [esp + 0x18]
// 00569946  d3ee                 shr esi, cl
// 00569948  0fb64a03             movzx ecx, byte ptr [edx + 3]
// 0056994c  8b74b500             mov esi, dword ptr [ebp + esi*4]
// 00569950  0fb7344e             movzx esi, word ptr [esi + ecx*2]
// 00569954  8bce                 mov ecx, esi
// 00569956  c1e908               shr ecx, 8
// 00569959  89742414             mov dword ptr [esp + 0x14], esi
// 0056995d  884802               mov byte ptr [eax + 2], cl
// 00569960  0fb64c2414           movzx ecx, byte ptr [esp + 0x14]
// 00569965  e976010000           jmp 0x569ae0
// 0056996a  6685f6               test si, si
// 0056996d  7543                 jne 0x5699b2
// 0056996f  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00569973  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 00569977  8848fe               mov byte ptr [eax - 2], cl
// 0056997a  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0056997e  0fb64902             movzx ecx, byte ptr [ecx + 2]
// 00569982  8848ff               mov byte ptr [eax - 1], cl
// 00569985  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00569989  0fb64905             movzx ecx, byte ptr [ecx + 5]
// 0056998d  8808                 mov byte ptr [eax], cl
// 0056998f  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00569993  0fb64904             movzx ecx, byte ptr [ecx + 4]
// 00569997  884801               mov byte ptr [eax + 1], cl
// 0056999a  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0056999e  0fb64907             movzx ecx, byte ptr [ecx + 7]
// 005699a2  884802               mov byte ptr [eax + 2], cl
// 005699a5  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 005699a9  0fb64906             movzx ecx, byte ptr [ecx + 6]
// 005699ad  e92e010000           jmp 0x569ae0
// 005699b2  0fb7fe               movzx edi, si
// 005699b5  0fb632               movzx esi, byte ptr [edx]
// 005699b8  0fb6cb               movzx ecx, bl
// 005699bb  d3ee                 shr esi, cl
// 005699bd  8b5c244c             mov ebx, dword ptr [esp + 0x4c]
// 005699c1  894c2418             mov dword ptr [esp + 0x18], ecx
// 005699c5  0fb64aff             movzx ecx, byte ptr [edx - 1]
// 005699c9  8b34b3               mov esi, dword ptr [ebx + esi*4]
// 005699cc  0fb70c4e             movzx ecx, word ptr [esi + ecx*2]
// 005699d0  8b742434             mov esi, dword ptr [esp + 0x34]
// 005699d4  0fafcf               imul ecx, edi
// 005699d7  0fb77602             movzx esi, word ptr [esi + 2]
// 005699db  bdffff0000           mov ebp, 0xffff
// 005699e0  2bef                 sub ebp, edi
// 005699e2  0faff5               imul esi, ebp
// 005699e5  8d8c3100800000       lea ecx, [ecx + esi + 0x8000]
// 005699ec  8bf1                 mov esi, ecx
// 005699ee  c1ee10               shr esi, 0x10
// 005699f1  03f1                 add esi, ecx
// 005699f3  0fb74c2450           movzx ecx, word ptr [esp + 0x50]
// 005699f8  c1ee10               shr esi, 0x10
// 005699fb  0fb7de               movzx ebx, si
// 005699fe  894c2414             mov dword ptr [esp + 0x14], ecx
// 00569a02  0fb6f3               movzx esi, bl
// 00569a05  d3ee                 shr esi, cl
// 00569a07  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 00569a0b  c1eb08               shr ebx, 8
// 00569a0e  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 00569a11  0fb70c59             movzx ecx, word ptr [ecx + ebx*2]
// 00569a15  8848ff               mov byte ptr [eax - 1], cl
// 00569a18  8bd9                 mov ebx, ecx
// 00569a1a  0fb64c2418           movzx ecx, byte ptr [esp + 0x18]
// 00569a1f  c1eb08               shr ebx, 8
// 00569a22  8858fe               mov byte ptr [eax - 2], bl
// 00569a25  0fb67202             movzx esi, byte ptr [edx + 2]
// 00569a29  d3ee                 shr esi, cl
// 00569a2b  0fb64a01             movzx ecx, byte ptr [edx + 1]
// 00569a2f  8b5c244c             mov ebx, dword ptr [esp + 0x4c]
// 00569a33  8b34b3               mov esi, dword ptr [ebx + esi*4]
// 00569a36  0fb70c4e             movzx ecx, word ptr [esi + ecx*2]
// 00569a3a  8b742434             mov esi, dword ptr [esp + 0x34]
// 00569a3e  0fafcf               imul ecx, edi
// 00569a41  0fb77604             movzx esi, word ptr [esi + 4]
// 00569a45  0faff5               imul esi, ebp
// 00569a48  8d8c3100800000       lea ecx, [ecx + esi + 0x8000]
// 00569a4f  8bf1                 mov esi, ecx
// 00569a51  c1ee10               shr esi, 0x10
// 00569a54  03f1                 add esi, ecx
// 00569a56  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00569a5a  c1ee10               shr esi, 0x10
// 00569a5d  0fb7de               movzx ebx, si
// 00569a60  0fb6f3               movzx esi, bl
// 00569a63  d3ee                 shr esi, cl
// 00569a65  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 00569a69  c1eb08               shr ebx, 8
// 00569a6c  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 00569a6f  0fb70c59             movzx ecx, word ptr [ecx + ebx*2]
// 00569a73  8bd9                 mov ebx, ecx
// 00569a75  884801               mov byte ptr [eax + 1], cl
// 00569a78  0fb64c2418           movzx ecx, byte ptr [esp + 0x18]
// 00569a7d  c1eb08               shr ebx, 8
// 00569a80  8818                 mov byte ptr [eax], bl
// 00569a82  0fb67204             movzx esi, byte ptr [edx + 4]
// 00569a86  8b5c244c             mov ebx, dword ptr [esp + 0x4c]
// 00569a8a  d3ee                 shr esi, cl
// 00569a8c  0fb64a03             movzx ecx, byte ptr [edx + 3]
// 00569a90  8b34b3               mov esi, dword ptr [ebx + esi*4]
// 00569a93  0fb70c4e             movzx ecx, word ptr [esi + ecx*2]
// 00569a97  8b742434             mov esi, dword ptr [esp + 0x34]
// 00569a9b  0fafcf               imul ecx, edi
// 00569a9e  0fb77606             movzx esi, word ptr [esi + 6]
// 00569aa2  0faff5               imul esi, ebp
// 00569aa5  8d8c3100800000       lea ecx, [ecx + esi + 0x8000]
// 00569aac  8bf1                 mov esi, ecx
// 00569aae  c1ee10               shr esi, 0x10
// 00569ab1  03f1                 add esi, ecx
// 00569ab3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00569ab7  c1ee10               shr esi, 0x10
// 00569aba  0fb7de               movzx ebx, si
// 00569abd  0fb6f3               movzx esi, bl
// 00569ac0  d3ee                 shr esi, cl
// 00569ac2  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 00569ac6  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 00569ac9  8b6c2444             mov ebp, dword ptr [esp + 0x44]
// 00569acd  c1eb08               shr ebx, 8
// 00569ad0  0fb70c59             movzx ecx, word ptr [ecx + ebx*2]
// 00569ad4  8bd9                 mov ebx, ecx
// 00569ad6  c1eb08               shr ebx, 8
// 00569ad9  885802               mov byte ptr [eax + 2], bl
// 00569adc  8a5c2450             mov bl, byte ptr [esp + 0x50]
// 00569ae0  884803               mov byte ptr [eax + 3], cl
// 00569ae3  83c208               add edx, 8
// 00569ae6  83c006               add eax, 6
// 00569ae9  836c241c01           sub dword ptr [esp + 0x1c], 1
// 00569aee  0f85ccfdffff         jne 0x5698c0
// 00569af4  e977010000           jmp 0x569c70
// 00569af9  8bd1                 mov edx, ecx
// 00569afb  85d2                 test edx, edx
// 00569afd  0f866d010000         jbe 0x569c70
// 00569b03  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00569b07  8b742430             mov esi, dword ptr [esp + 0x30]
// 00569b0b  8d4102               lea eax, [ecx + 2]
// 00569b0e  83c107               add ecx, 7
// 00569b11  8954241c             mov dword ptr [esp + 0x1c], edx
// 00569b15  eb09                 jmp 0x569b20
// 00569b17  8da42400000000       lea esp, [esp]
// 00569b1e  8bff                 mov edi, edi
// 00569b20  660fb651ff           movzx dx, byte ptr [ecx - 1]
// 00569b25  bf00010000           mov edi, 0x100
// 00569b2a  660fafd7             imul dx, di
// 00569b2e  660fb639             movzx di, byte ptr [ecx]
// 00569b32  6603d7               add dx, di
// 00569b35  0fb7d2               movzx edx, dx
// 00569b38  bfffff0000           mov edi, 0xffff
// 00569b3d  663bd7               cmp dx, di
// 00569b40  7513                 jne 0x569b55
// 00569b42  8b51f9               mov edx, dword ptr [ecx - 7]
// 00569b45  8950fe               mov dword ptr [eax - 2], edx
// 00569b48  668b51fd             mov dx, word ptr [ecx - 3]
// 00569b4c  66895002             mov word ptr [eax + 2], dx
// 00569b50  e90a010000           jmp 0x569c5f
// 00569b55  6685d2               test dx, dx
// 00569b58  752b                 jne 0x569b85
// 00569b5a  0fb65603             movzx edx, byte ptr [esi + 3]
// 00569b5e  8850fe               mov byte ptr [eax - 2], dl
// 00569b61  0fb65602             movzx edx, byte ptr [esi + 2]
// 00569b65  8850ff               mov byte ptr [eax - 1], dl
// 00569b68  0fb65605             movzx edx, byte ptr [esi + 5]
// 00569b6c  8810                 mov byte ptr [eax], dl
// 00569b6e  0fb65604             movzx edx, byte ptr [esi + 4]
// 00569b72  885001               mov byte ptr [eax + 1], dl
// 00569b75  0fb65607             movzx edx, byte ptr [esi + 7]
// 00569b79  885002               mov byte ptr [eax + 2], dl
// 00569b7c  0fb65606             movzx edx, byte ptr [esi + 6]
// 00569b80  e9d7000000           jmp 0x569c5c
// 00569b85  0fb671fb             movzx esi, byte ptr [ecx - 5]
// 00569b89  bf00010000           mov edi, 0x100
// 00569b8e  660faff7             imul si, di
// 00569b92  0fb679fc             movzx edi, byte ptr [ecx - 4]
// 00569b96  6603f7               add si, di
// 00569b99  0fb7f6               movzx esi, si
// 00569b9c  89742418             mov dword ptr [esp + 0x18], esi
// 00569ba0  0fb671fd             movzx esi, byte ptr [ecx - 3]
// 00569ba4  bf00010000           mov edi, 0x100
// 00569ba9  660faff7             imul si, di
// 00569bad  0fb679fe             movzx edi, byte ptr [ecx - 2]
// 00569bb1  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 00569bb5  6603f7               add si, di
// 00569bb8  0fb7f6               movzx esi, si
// 00569bbb  89742414             mov dword ptr [esp + 0x14], esi
// 00569bbf  0fb7f2               movzx esi, dx
// 00569bc2  660fb651f9           movzx dx, byte ptr [ecx - 7]
// 00569bc7  bb00010000           mov ebx, 0x100
// 00569bcc  660fafd3             imul dx, bx
// 00569bd0  660fb659fa           movzx bx, byte ptr [ecx - 6]
// 00569bd5  6603d3               add dx, bx
// 00569bd8  0fb75d02             movzx ebx, word ptr [ebp + 2]
// 00569bdc  0fb7d2               movzx edx, dx
// 00569bdf  0fafd6               imul edx, esi
// 00569be2  bfffff0000           mov edi, 0xffff
// 00569be7  2bfe                 sub edi, esi
// 00569be9  0fafdf               imul ebx, edi
// 00569bec  8d9c1a00800000       lea ebx, [edx + ebx + 0x8000]
// 00569bf3  8bd3                 mov edx, ebx
// 00569bf5  c1ea10               shr edx, 0x10
// 00569bf8  03d3                 add edx, ebx
// 00569bfa  c1ea10               shr edx, 0x10
// 00569bfd  8bda                 mov ebx, edx
// 00569bff  8850ff               mov byte ptr [eax - 1], dl
// 00569c02  c1eb08               shr ebx, 8
// 00569c05  8858fe               mov byte ptr [eax - 2], bl
// 00569c08  0fb75504             movzx edx, word ptr [ebp + 4]
// 00569c0c  0fb75c2418           movzx ebx, word ptr [esp + 0x18]
// 00569c11  0fafd7               imul edx, edi
// 00569c14  0fafde               imul ebx, esi
// 00569c17  8d9c1a00800000       lea ebx, [edx + ebx + 0x8000]
// 00569c1e  8bd3                 mov edx, ebx
// 00569c20  c1ea10               shr edx, 0x10
// 00569c23  03d3                 add edx, ebx
// 00569c25  c1ea10               shr edx, 0x10
// 00569c28  8bda                 mov ebx, edx
// 00569c2a  885001               mov byte ptr [eax + 1], dl
// 00569c2d  c1eb08               shr ebx, 8
// 00569c30  8818                 mov byte ptr [eax], bl
// 00569c32  0fb75506             movzx edx, word ptr [ebp + 6]
// 00569c36  0fafd7               imul edx, edi
// 00569c39  0fb77c2414           movzx edi, word ptr [esp + 0x14]
// 00569c3e  0faffe               imul edi, esi
// 00569c41  8db43a00800000       lea esi, [edx + edi + 0x8000]
// 00569c48  8bd6                 mov edx, esi
// 00569c4a  c1ea10               shr edx, 0x10
// 00569c4d  03d6                 add edx, esi
// 00569c4f  c1ea10               shr edx, 0x10
// 00569c52  8bda                 mov ebx, edx
// 00569c54  c1eb08               shr ebx, 8
// 00569c57  885802               mov byte ptr [eax + 2], bl
// 00569c5a  8bf5                 mov esi, ebp
// 00569c5c  885003               mov byte ptr [eax + 3], dl
// 00569c5f  83c108               add ecx, 8
// 00569c62  83c006               add eax, 6
// 00569c65  836c241c01           sub dword ptr [esp + 0x1c], 1
// 00569c6a  0f85b0feffff         jne 0x569b20
// 00569c70  5f                   pop edi
// 00569c71  5e                   pop esi
// 00569c72  5b                   pop ebx
// 00569c73  8b542418             mov edx, dword ptr [esp + 0x18]
// 00569c77  8a4208               mov al, byte ptr [edx + 8]
// 00569c7a  a804                 test al, 4
// 00569c7c  7438                 je 0x569cb6
// 00569c7e  fe4a0a               dec byte ptr [edx + 0xa]
// 00569c81  8a4a0a               mov cl, byte ptr [edx + 0xa]
// 00569c84  24fb                 and al, 0xfb
// 00569c86  884208               mov byte ptr [edx + 8], al
// 00569c89  8a4209               mov al, byte ptr [edx + 9]
// 00569c8c  f6e9                 imul cl
// 00569c8e  88420b               mov byte ptr [edx + 0xb], al
// 00569c91  3c08                 cmp al, 8
// 00569c93  0fb6c0               movzx eax, al
// 00569c96  7210                 jb 0x569ca8
// 00569c98  c1e803               shr eax, 3
// 00569c9b  0faf442404           imul eax, dword ptr [esp + 4]
// 00569ca0  894204               mov dword ptr [edx + 4], eax
// 00569ca3  5d                   pop ebp
// 00569ca4  83c410               add esp, 0x10
// 00569ca7  c3                   ret 
// 00569ca8  0faf442404           imul eax, dword ptr [esp + 4]
// 00569cad  83c007               add eax, 7
// 00569cb0  c1e803               shr eax, 3
// 00569cb3  894204               mov dword ptr [edx + 4], eax
// 00569cb6  5d                   pop ebp
// 00569cb7  83c410               add esp, 0x10
// 00569cba  c3                   ret 
// 00569cbb  90                   nop 
// 00569cbc  af                   scasd eax, dword ptr es:[edi]
// 00569cbd  8c5600               mov word ptr [esi], ss
// 00569cc0  709c                 jo 0x569c5e
// 00569cc2  56                   push esi
// 00569cc3  005590               add byte ptr [ebp - 0x70], dl
// 00569cc6  56                   push esi
// 00569cc7  00709c               add byte ptr [eax - 0x64], dh
// 00569cca  56                   push esi
// 00569ccb  00fd                 add ch, bh
// 00569ccd  92                   xchg edx, eax
// 00569cce  56                   push esi
// 00569ccf  00709c               add byte ptr [eax - 0x64], dh
// 00569cd2  56                   push esi
// 00569cd3  000e                 add byte ptr [esi], cl
// 00569cd5  96                   xchg esi, eax
// 00569cd6  56                   push esi
// 00569cd7  00cf                 add bh, cl
// 00569cd9  8c5600               mov word ptr [esi], ss
// 00569cdc  328d56003e8e         xor cl, byte ptr [ebp - 0x71c1ffaa]
// 00569ce2  56                   push esi
// 00569ce3  0036                 add byte ptr [esi], dh
// library libpng-1.2.6/pngrtran.c (function _png_do_background)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.6 pngrtran.c
