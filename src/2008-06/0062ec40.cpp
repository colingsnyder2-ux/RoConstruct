// from server: 100% by EspClaude
// from server: 99% by king_originala_sol_native
// roc 2008-06 0062ec40  unit: RBX::BodyMover  size: 1136 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0062ec40
//
// 0062ec40  83ec58               sub esp, 0x58
// 0062ec43  55                   push ebp
// 0062ec44  8be9                 mov ebp, ecx
// 0062ec46  d98550010000         fld dword ptr [ebp + 0x150]
// 0062ec4c  d9ee                 fldz 
// 0062ec4e  d9c0                 fld st(0)
// 0062ec50  ddea                 fucomp st(2)
// 0062ec52  dfe0                 fnstsw ax
// 0062ec54  f6c444               test ah, 0x44
// 0062ec57  7b29                 jnp 0x62ec82
// 0062ec59  d9c1                 fld st(1)
// 0062ec5b  83ec10               sub esp, 0x10
// 0062ec5e  d9e1                 fabs 
// 0062ec60  dd5c2418             fstp qword ptr [esp + 0x18]
// 0062ec64  dd5c2408             fstp qword ptr [esp + 8]
// 0062ec68  dd1c24               fstp qword ptr [esp]
// 0062ec6b  e81044eeff           call 0x513080
// 0062ec70  dc5c2418             fcomp qword ptr [esp + 0x18]
// 0062ec74  83c410               add esp, 0x10
// 0062ec77  dfe0                 fnstsw ax
// 0062ec79  f6c401               test ah, 1
// 0062ec7c  7526                 jne 0x62eca4
// 0062ec7e  d9ee                 fldz 
// 0062ec80  eb02                 jmp 0x62ec84
// 0062ec82  ddd9                 fstp st(1)
// 0062ec84  83ec10               sub esp, 0x10
// 0062ec87  dd5c2408             fstp qword ptr [esp + 8]
// 0062ec8b  d98558010000         fld dword ptr [ebp + 0x158]
// 0062ec91  dd1c24               fstp qword ptr [esp]
// 0062ec94  e83744eeff           call 0x5130d0
// 0062ec99  83c410               add esp, 0x10
// 0062ec9c  84c0                 test al, al
// 0062ec9e  0f8505040000         jne 0x62f0a9
// 0062eca4  53                   push ebx
// 0062eca5  56                   push esi
// 0062eca6  57                   push edi
// 0062eca7  8b7c246c             mov edi, dword ptr [esp + 0x6c]
// 0062ecab  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 0062ecae  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0062ecb1  8b402c               mov eax, dword ptr [eax + 0x2c]
// 0062ecb4  b901000000           mov ecx, 1
// 0062ecb9  85c0                 test eax, eax
// 0062ecbb  7407                 je 0x62ecc4
// 0062ecbd  0590000000           add eax, 0x90
// 0062ecc2  eb27                 jmp 0x62eceb
// 0062ecc4  840d50f09600         test byte ptr [0x96f050], cl
// 0062ecca  751a                 jne 0x62ece6
// 0062eccc  d9ee                 fldz 
// 0062ecce  090d50f09600         or dword ptr [0x96f050], ecx
// 0062ecd4  d91544f09600         fst dword ptr [0x96f044]
// 0062ecda  d91548f09600         fst dword ptr [0x96f048]
// 0062ece0  d91d4cf09600         fstp dword ptr [0x96f04c]
// 0062ece6  b844f09600           mov eax, 0x96f044
// 0062eceb  d900                 fld dword ptr [eax]
// 0062eced  51                   push ecx
// 0062ecee  d95c2430             fstp dword ptr [esp + 0x30]
// 0062ecf2  8d4c2424             lea ecx, [esp + 0x24]
// 0062ecf6  d94004               fld dword ptr [eax + 4]
// 0062ecf9  51                   push ecx
// 0062ecfa  d95c2438             fstp dword ptr [esp + 0x38]
// 0062ecfe  8d8d5c010000         lea ecx, [ebp + 0x15c]
// 0062ed04  d94008               fld dword ptr [eax + 8]
// 0062ed07  d95c243c             fstp dword ptr [esp + 0x3c]
// 0062ed0b  e83045eeff           call 0x513240
// 0062ed10  8bcf                 mov ecx, edi
// 0062ed12  e849a6f6ff           call 0x599360
// 0062ed17  8d542444             lea edx, [esp + 0x44]
// 0062ed1b  8db794000000         lea esi, [edi + 0x94]
// 0062ed21  52                   push edx
// 0062ed22  8bce                 mov ecx, esi
// 0062ed24  e8e747eeff           call 0x513510
// 0062ed29  d94004               fld dword ptr [eax + 4]
// 0062ed2c  d9442424             fld dword ptr [esp + 0x24]
// 0062ed30  8b4b28               mov ecx, dword ptr [ebx + 0x28]
// 0062ed33  dcc9                 fmul st(1), st(0)
// 0062ed35  d94008               fld dword ptr [eax + 8]
// 0062ed38  d9442428             fld dword ptr [esp + 0x28]
// 0062ed3c  dcc9                 fmul st(1), st(0)
// 0062ed3e  d9cb                 fxch st(3)
// 0062ed40  dec1                 faddp st(1)
// 0062ed42  d900                 fld dword ptr [eax]
// 0062ed44  d9442420             fld dword ptr [esp + 0x20]
// 0062ed48  dcc9                 fmul st(1), st(0)
// 0062ed4a  d9ca                 fxch st(2)
// 0062ed4c  dec1                 faddp st(1)
// 0062ed4e  d95c2414             fstp dword ptr [esp + 0x14]
// 0062ed52  d84818               fmul dword ptr [eax + 0x18]
// 0062ed55  d9401c               fld dword ptr [eax + 0x1c]
// 0062ed58  deca                 fmulp st(2)
// 0062ed5a  dec1                 faddp st(1)
// 0062ed5c  d94020               fld dword ptr [eax + 0x20]
// 0062ed5f  deca                 fmulp st(2)
// 0062ed61  dec1                 faddp st(1)
// 0062ed63  d95c241c             fstp dword ptr [esp + 0x1c]
// 0062ed67  85c9                 test ecx, ecx
// 0062ed69  7407                 je 0x62ed72
// 0062ed6b  e800140300           call 0x660170
// 0062ed70  eb03                 jmp 0x62ed75
// 0062ed72  8d4368               lea eax, [ebx + 0x68]
// 0062ed75  50                   push eax
// 0062ed76  8d4c2448             lea ecx, [esp + 0x48]
// 0062ed7a  e8a144eeff           call 0x513220
// 0062ed7f  8d442444             lea eax, [esp + 0x44]
// 0062ed83  50                   push eax
// 0062ed84  8d4c2424             lea ecx, [esp + 0x24]
// 0062ed88  51                   push ecx
// 0062ed89  e822eefaff           call 0x5ddbb0
// 0062ed8e  d9442428             fld dword ptr [esp + 0x28]
// 0062ed92  d84c2424             fmul dword ptr [esp + 0x24]
// 0062ed96  8b4b28               mov ecx, dword ptr [ebx + 0x28]
// 0062ed99  83c408               add esp, 8
// 0062ed9c  d88d48010000         fmul dword ptr [ebp + 0x148]
// 0062eda2  d95c246c             fstp dword ptr [esp + 0x6c]
// 0062eda6  85c9                 test ecx, ecx
// 0062eda8  7407                 je 0x62edb1
// 0062edaa  e8c1130300           call 0x660170
// 0062edaf  eb03                 jmp 0x62edb4
// 0062edb1  8d4368               lea eax, [ebx + 0x68]
// 0062edb4  50                   push eax
// 0062edb5  8d4c2448             lea ecx, [esp + 0x48]
// 0062edb9  e86244eeff           call 0x513220
// 0062edbe  8d542444             lea edx, [esp + 0x44]
// 0062edc2  52                   push edx
// 0062edc3  8d442424             lea eax, [esp + 0x24]
// 0062edc7  50                   push eax
// 0062edc8  e8e3edfaff           call 0x5ddbb0
// 0062edcd  d9442430             fld dword ptr [esp + 0x30]
// 0062edd1  d84c241c             fmul dword ptr [esp + 0x1c]
// 0062edd5  83c408               add esp, 8
// 0062edd8  8bcf                 mov ecx, edi
// 0062edda  d88d48010000         fmul dword ptr [ebp + 0x148]
// 0062ede0  d9e0                 fchs 
// 0062ede2  d95c2410             fstp dword ptr [esp + 0x10]
// 0062ede6  e875a5f6ff           call 0x599360
// 0062edeb  8d4c2444             lea ecx, [esp + 0x44]
// 0062edef  51                   push ecx
// 0062edf0  8bce                 mov ecx, esi
// 0062edf2  e81947eeff           call 0x513510
// 0062edf7  d94004               fld dword ptr [eax + 4]
// 0062edfa  d9442430             fld dword ptr [esp + 0x30]
// 0062edfe  8b4b28               mov ecx, dword ptr [ebx + 0x28]
// 0062ee01  dcc9                 fmul st(1), st(0)
// 0062ee03  d94008               fld dword ptr [eax + 8]
// 0062ee06  d9442434             fld dword ptr [esp + 0x34]
// 0062ee0a  dcc9                 fmul st(1), st(0)
// 0062ee0c  d9cb                 fxch st(3)
// 0062ee0e  dec1                 faddp st(1)
// 0062ee10  d900                 fld dword ptr [eax]
// 0062ee12  d944242c             fld dword ptr [esp + 0x2c]
// 0062ee16  dcc9                 fmul st(1), st(0)
// 0062ee18  d9ca                 fxch st(2)
// 0062ee1a  dec1                 faddp st(1)
// 0062ee1c  d9542420             fst dword ptr [esp + 0x20]
// 0062ee20  d94010               fld dword ptr [eax + 0x10]
// 0062ee23  d8cb                 fmul st(3)
// 0062ee25  d94014               fld dword ptr [eax + 0x14]
// 0062ee28  d8cd                 fmul st(5)
// 0062ee2a  dec1                 faddp st(1)
// 0062ee2c  d9400c               fld dword ptr [eax + 0xc]
// 0062ee2f  d8cb                 fmul st(3)
// 0062ee31  dec1                 faddp st(1)
// 0062ee33  d95c2424             fstp dword ptr [esp + 0x24]
// 0062ee37  d9401c               fld dword ptr [eax + 0x1c]
// 0062ee3a  decb                 fmulp st(3)
// 0062ee3c  d94020               fld dword ptr [eax + 0x20]
// 0062ee3f  decc                 fmulp st(4)
// 0062ee41  d9ca                 fxch st(2)
// 0062ee43  dec3                 faddp st(3)
// 0062ee45  d84818               fmul dword ptr [eax + 0x18]
// 0062ee48  dec2                 faddp st(2)
// 0062ee4a  d9c9                 fxch st(1)
// 0062ee4c  d95c2428             fstp dword ptr [esp + 0x28]
// 0062ee50  d86c246c             fsubr dword ptr [esp + 0x6c]
// 0062ee54  d9e1                 fabs 
// 0062ee56  d95c2414             fstp dword ptr [esp + 0x14]
// 0062ee5a  85c9                 test ecx, ecx
// 0062ee5c  7407                 je 0x62ee65
// 0062ee5e  e80d130300           call 0x660170
// 0062ee63  eb03                 jmp 0x62ee68
// 0062ee65  8d4368               lea eax, [ebx + 0x68]
// 0062ee68  50                   push eax
// 0062ee69  8d4c2448             lea ecx, [esp + 0x48]
// 0062ee6d  e8ae43eeff           call 0x513220
// 0062ee72  8d542444             lea edx, [esp + 0x44]
// 0062ee76  52                   push edx
// 0062ee77  8d44243c             lea eax, [esp + 0x3c]
// 0062ee7b  50                   push eax
// 0062ee7c  e82fedfaff           call 0x5ddbb0
// 0062ee81  d9442440             fld dword ptr [esp + 0x40]
// 0062ee85  d88d50010000         fmul dword ptr [ebp + 0x150]
// 0062ee8b  83c408               add esp, 8
// 0062ee8e  d85c2414             fcomp dword ptr [esp + 0x14]
// 0062ee92  dfe0                 fnstsw ax
// 0062ee94  f6c441               test ah, 0x41
// 0062ee97  7506                 jne 0x62ee9f
// 0062ee99  d944246c             fld dword ptr [esp + 0x6c]
// 0062ee9d  eb08                 jmp 0x62eea7
// 0062ee9f  d9442420             fld dword ptr [esp + 0x20]
// 0062eea3  d844246c             fadd dword ptr [esp + 0x6c]
// 0062eea7  8b4b28               mov ecx, dword ptr [ebx + 0x28]
// 0062eeaa  d95c2420             fstp dword ptr [esp + 0x20]
// 0062eeae  d9442410             fld dword ptr [esp + 0x10]
// 0062eeb2  d8642428             fsub dword ptr [esp + 0x28]
// 0062eeb6  d9e1                 fabs 
// 0062eeb8  d95c246c             fstp dword ptr [esp + 0x6c]
// 0062eebc  85c9                 test ecx, ecx
// 0062eebe  7407                 je 0x62eec7
// 0062eec0  e8ab120300           call 0x660170
// 0062eec5  eb03                 jmp 0x62eeca
// 0062eec7  8d4368               lea eax, [ebx + 0x68]
// 0062eeca  50                   push eax
// 0062eecb  8d4c2448             lea ecx, [esp + 0x48]
// 0062eecf  e84c43eeff           call 0x513220
// 0062eed4  8d4c2444             lea ecx, [esp + 0x44]
// 0062eed8  51                   push ecx
// 0062eed9  8d54243c             lea edx, [esp + 0x3c]
// 0062eedd  52                   push edx
// 0062eede  e8cdecfaff           call 0x5ddbb0
// 0062eee3  d98558010000         fld dword ptr [ebp + 0x158]
// 0062eee9  d84c2448             fmul dword ptr [esp + 0x48]
// 0062eeed  83c408               add esp, 8
// 0062eef0  d85c246c             fcomp dword ptr [esp + 0x6c]
// 0062eef4  dfe0                 fnstsw ax
// 0062eef6  f6c441               test ah, 0x41
// 0062eef9  7506                 jne 0x62ef01
// 0062eefb  d9442410             fld dword ptr [esp + 0x10]
// 0062eeff  eb08                 jmp 0x62ef09
// 0062ef01  d9442428             fld dword ptr [esp + 0x28]
// 0062ef05  d8442410             fadd dword ptr [esp + 0x10]
// 0062ef09  8bcf                 mov ecx, edi
// 0062ef0b  d95c2428             fstp dword ptr [esp + 0x28]
// 0062ef0f  e84ca4f6ff           call 0x599360
// 0062ef14  8bcf                 mov ecx, edi
// 0062ef16  e845a4f6ff           call 0x599360
// 0062ef1b  8d442444             lea eax, [esp + 0x44]
// 0062ef1f  50                   push eax
// 0062ef20  8bce                 mov ecx, esi
// 0062ef22  e8e945eeff           call 0x513510
// 0062ef27  d94004               fld dword ptr [eax + 4]
// 0062ef2a  d88fd4000000         fmul dword ptr [edi + 0xd4]
// 0062ef30  8b4b28               mov ecx, dword ptr [ebx + 0x28]
// 0062ef33  d94008               fld dword ptr [eax + 8]
// 0062ef36  d88fd8000000         fmul dword ptr [edi + 0xd8]
// 0062ef3c  dec1                 faddp st(1)
// 0062ef3e  d900                 fld dword ptr [eax]
// 0062ef40  d88fd0000000         fmul dword ptr [edi + 0xd0]
// 0062ef46  dec1                 faddp st(1)
// 0062ef48  d95c2414             fstp dword ptr [esp + 0x14]
// 0062ef4c  d9401c               fld dword ptr [eax + 0x1c]
// 0062ef4f  d88fd4000000         fmul dword ptr [edi + 0xd4]
// 0062ef55  d94020               fld dword ptr [eax + 0x20]
// 0062ef58  d88fd8000000         fmul dword ptr [edi + 0xd8]
// 0062ef5e  dec1                 faddp st(1)
// 0062ef60  d94018               fld dword ptr [eax + 0x18]
// 0062ef63  d88fd0000000         fmul dword ptr [edi + 0xd0]
// 0062ef69  dec1                 faddp st(1)
// 0062ef6b  d95c241c             fstp dword ptr [esp + 0x1c]
// 0062ef6f  85c9                 test ecx, ecx
// 0062ef71  7407                 je 0x62ef7a
// 0062ef73  e8f8110300           call 0x660170
// 0062ef78  eb03                 jmp 0x62ef7d
// 0062ef7a  8d4368               lea eax, [ebx + 0x68]
// 0062ef7d  50                   push eax
// 0062ef7e  8d4c2448             lea ecx, [esp + 0x48]
// 0062ef82  e89942eeff           call 0x513220
// 0062ef87  8d4c2444             lea ecx, [esp + 0x44]
// 0062ef8b  51                   push ecx
// 0062ef8c  8d54243c             lea edx, [esp + 0x3c]
// 0062ef90  52                   push edx
// 0062ef91  e81aecfaff           call 0x5ddbb0
// 0062ef96  d9854c010000         fld dword ptr [ebp + 0x14c]
// 0062ef9c  d84c2440             fmul dword ptr [esp + 0x40]
// 0062efa0  8b4b28               mov ecx, dword ptr [ebx + 0x28]
// 0062efa3  83c408               add esp, 8
// 0062efa6  d84c2414             fmul dword ptr [esp + 0x14]
// 0062efaa  d86c2420             fsubr dword ptr [esp + 0x20]
// 0062efae  d95c2420             fstp dword ptr [esp + 0x20]
// 0062efb2  85c9                 test ecx, ecx
// 0062efb4  7407                 je 0x62efbd
// 0062efb6  e8b5110300           call 0x660170
// 0062efbb  eb03                 jmp 0x62efc0
// 0062efbd  8d4368               lea eax, [ebx + 0x68]
// 0062efc0  50                   push eax
// 0062efc1  8d4c2448             lea ecx, [esp + 0x48]
// 0062efc5  e85642eeff           call 0x513220
// 0062efca  8d442444             lea eax, [esp + 0x44]
// 0062efce  50                   push eax
// 0062efcf  8d4c243c             lea ecx, [esp + 0x3c]
// 0062efd3  51                   push ecx
// 0062efd4  e8d7ebfaff           call 0x5ddbb0
// 0062efd9  d9854c010000         fld dword ptr [ebp + 0x14c]
// 0062efdf  d84c2448             fmul dword ptr [esp + 0x48]
// 0062efe3  83c408               add esp, 8
// 0062efe6  8bcf                 mov ecx, edi
// 0062efe8  d84c241c             fmul dword ptr [esp + 0x1c]
// 0062efec  d86c2428             fsubr dword ptr [esp + 0x28]
// 0062eff0  d95c2428             fstp dword ptr [esp + 0x28]
// 0062eff4  e867a3f6ff           call 0x599360
// 0062eff9  d94604               fld dword ptr [esi + 4]
// 0062effc  8b5310               mov edx, dword ptr [ebx + 0x10]
// 0062efff  d9442424             fld dword ptr [esp + 0x24]
// 0062f003  dcc9                 fmul st(1), st(0)
// 0062f005  d94608               fld dword ptr [esi + 8]
// 0062f008  d9442428             fld dword ptr [esp + 0x28]
// 0062f00c  dcc9                 fmul st(1), st(0)
// 0062f00e  d9cb                 fxch st(3)
// 0062f010  dec1                 faddp st(1)
// 0062f012  d906                 fld dword ptr [esi]
// 0062f014  d9442420             fld dword ptr [esp + 0x20]
// 0062f018  dcc9                 fmul st(1), st(0)
// 0062f01a  d9ca                 fxch st(2)
// 0062f01c  dec1                 faddp st(1)
// 0062f01e  d94610               fld dword ptr [esi + 0x10]
// 0062f021  d8cb                 fmul st(3)
// 0062f023  d94614               fld dword ptr [esi + 0x14]
// 0062f026  d8cd                 fmul st(5)
// 0062f028  dec1                 faddp st(1)
// 0062f02a  d9460c               fld dword ptr [esi + 0xc]
// 0062f02d  d8cb                 fmul st(3)
// 0062f02f  dec1                 faddp st(1)
// 0062f031  d9461c               fld dword ptr [esi + 0x1c]
// 0062f034  decc                 fmulp st(4)
// 0062f036  d94620               fld dword ptr [esi + 0x20]
// 0062f039  decd                 fmulp st(5)
// 0062f03b  d9cb                 fxch st(3)
// 0062f03d  dec4                 faddp st(4)
// 0062f03f  d94618               fld dword ptr [esi + 0x18]
// 0062f042  8b722c               mov esi, dword ptr [edx + 0x2c]
// 0062f045  deca                 fmulp st(2)
// 0062f047  d9cb                 fxch st(3)
// 0062f049  dec1                 faddp st(1)
// 0062f04b  d9ca                 fxch st(2)
// 0062f04d  d864242c             fsub dword ptr [esp + 0x2c]
// 0062f051  d95c2420             fstp dword ptr [esp + 0x20]
// 0062f055  d8642430             fsub dword ptr [esp + 0x30]
// 0062f059  d95c2424             fstp dword ptr [esp + 0x24]
// 0062f05d  d8642434             fsub dword ptr [esp + 0x34]
// 0062f061  d95c2428             fstp dword ptr [esp + 0x28]
// 0062f065  85f6                 test esi, esi
// 0062f067  743d                 je 0x62f0a6
// 0062f069  807e0800             cmp byte ptr [esi + 8], 0
// 0062f06d  7407                 je 0x62f076
// 0062f06f  8bce                 mov ecx, esi
// 0062f071  e8aa9c0200           call 0x658d20
// 0062f076  d98690000000         fld dword ptr [esi + 0x90]
// 0062f07c  d8442420             fadd dword ptr [esp + 0x20]
// 0062f080  d99e90000000         fstp dword ptr [esi + 0x90]
// 0062f086  d98694000000         fld dword ptr [esi + 0x94]
// 0062f08c  d8442424             fadd dword ptr [esp + 0x24]
// 0062f090  d99e94000000         fstp dword ptr [esi + 0x94]
// 0062f096  d98698000000         fld dword ptr [esi + 0x98]
// 0062f09c  d8442428             fadd dword ptr [esp + 0x28]
// 0062f0a0  d99e98000000         fstp dword ptr [esi + 0x98]
// 0062f0a6  5f                   pop edi
// 0062f0a7  5e                   pop esi
// 0062f0a8  5b                   pop ebx
// 0062f0a9  5d                   pop ebp
// 0062f0aa  83c458               add esp, 0x58
// 0062f0ad  c20400               ret 4

// from server: 98% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Native Gyro.cpp Rocket::turn, with target-observed Body/SimBody/Rocket offsets.
#include <math.h>
#include <stddef.h>
#include <intrin.h>
namespace G3D {
double eps(double,double);
inline bool fuzzyEq(double a,double b){return(a==b)||(fabs(a-b)<=eps(a,b));}
struct Vector3 {
 float x,y,z;
 Vector3():x(0),y(0),z(0){}
 Vector3(float a,float b,float c):x(a),y(b),z(c){}
 Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}
 Vector3&operator=(const Vector3&v){x=v.x;y=v.y;z=v.z;return *this;}
 float&operator[](int i){return ((float*)this)[i];}
 const float&operator[](int i)const{return ((const float*)this)[i];}
 Vector3 operator-(const Vector3&v)const{return Vector3(x-v.x,y-v.y,z-v.z);}
 Vector3&operator+=(const Vector3&v){float oldX=x;_ReadWriteBarrier();x=oldX+v.x;float oldY=y;_ReadWriteBarrier();y=oldY+v.y;float oldZ=z;_ReadWriteBarrier();z=oldZ+v.z;return *this;}
 static const Vector3&zero(){static Vector3 v(0,0,0);return v;}
};
struct Matrix3 {
 float elt[3][3];
 Matrix3(){}Matrix3(const Matrix3&);
 Matrix3 transpose()const;Vector3 getColumn(int)const;
 Vector3 operator*(const Vector3&v)const{
  Vector3 kProd;
  for(int r=0;r<3;++r)kProd[r]=elt[r][0]*v[0]+elt[r][1]*v[1]+elt[r][2]*v[2];
  return kProd;
 }
};
struct CoordinateFrame {
 Matrix3 rotation;Vector3 translation;
 Vector3 upVector()const{return rotation.getColumn(1);}
 Vector3 vectorToObjectSpace(const Vector3&v)const{return rotation.transpose()*v;}
 Vector3 vectorToWorldSpace(const Vector3&v)const{return rotation*v;}
};
}
namespace RBX {
struct Velocity {G3D::Vector3 linear,rotational;};
struct PV {G3D::CoordinateFrame position;Velocity velocity;};
struct Math {static G3D::Vector3 toDiagonal(const G3D::Matrix3&);};
struct Cofm {const G3D::Matrix3&getMoment()const;};
struct Body;
struct SimBody {
 Body*body;float dt;bool dirty;char unused[0x90-9];G3D::Vector3 torque;
 void update();
 void accumulateTorque(const G3D::Vector3&v){if(dirty)update();torque+=v;}
};
struct Body {
 char prefix[0x10];Body*root;
 char unused[0x28-0x14];Cofm*cofm;SimBody*simBody;
 char unused2[0x68-0x30];G3D::Matrix3 moment;float mass;int stateIndex;PV pv;
 void updatePV()const;
 Body*getRoot(){return root;}
 const G3D::CoordinateFrame&getCoordinateFrame()const{updatePV();return pv.position;}
 const Velocity&getVelocity()const{updatePV();return pv.velocity;}
 const G3D::Vector3&getBranchTorque()const{return root->simBody?root->simBody->torque:G3D::Vector3::zero();}
 G3D::Matrix3 getBranchIBody()const{return cofm?cofm->getMoment():moment;}
 G3D::Vector3 getBranchIBodyV3()const{return Math::toDiagonal(getBranchIBody());}
 void accumulateTorque(const G3D::Vector3&v){if(root->simBody)root->simBody->accumulateTorque(v);}
};
struct BodyGyro {
 char unused[0x148];float kP,kD;G3D::Vector3 maxTorque;G3D::CoordinateFrame cframe;
 void computeBalance(Body*);
};
void BodyGyro::computeBalance(Body* body)
	{
		if (G3D::fuzzyEq(maxTorque.x, 0.0f) && G3D::fuzzyEq(maxTorque.z, 0.0f))
			return;

		Body* root = body->getRoot();
		G3D::Vector3 oldTorqueWorld = root->getBranchTorque();
		G3D::Vector3 localYAxis = body->getCoordinateFrame().vectorToObjectSpace(cframe.upVector());
		float desiredTorqueX = localYAxis.z * root->getBranchIBodyV3().x;
 desiredTorqueX*=kP;
		float desiredTorqueZ = localYAxis.x * root->getBranchIBodyV3().z;
 desiredTorqueZ=-(desiredTorqueZ*kP);

		G3D::Vector3 torqueBody = body->getCoordinateFrame().vectorToObjectSpace(oldTorqueWorld);

		if (fabs(desiredTorqueX - torqueBody.x) < root->getBranchIBodyV3().x * maxTorque.x)
			torqueBody.x = desiredTorqueX;
		else
			torqueBody.x += desiredTorqueX;

		if (fabs(desiredTorqueZ - torqueBody.z) < root->getBranchIBodyV3().z * maxTorque.z)
			torqueBody.z = desiredTorqueZ;
		else
			torqueBody.z += desiredTorqueZ;

		G3D::Vector3 angVelBody = body->getCoordinateFrame().vectorToObjectSpace(body->getVelocity().rotational);
		float unusedY = angVelBody.y;
		torqueBody.x -= kD * root->getBranchIBodyV3().x * angVelBody.x;
		torqueBody.z -= kD * root->getBranchIBodyV3().z * angVelBody.z;

		G3D::Vector3 addedTorque = body->getCoordinateFrame().vectorToWorldSpace(torqueBody) - oldTorqueWorld;

		root->accumulateTorque(addedTorque);
	}

	
}
typedef char body_pv_offset[offsetof(RBX::Body,pv)==0x94?1:-1];
typedef char simbody_torque_offset[offsetof(RBX::SimBody,torque)==0x90?1:-1];
typedef char gyro_gain_offset[offsetof(RBX::BodyGyro,kP)==0x148?1:-1];
typedef char gyro_frame_offset[offsetof(RBX::BodyGyro,cframe)==0x15c?1:-1];
