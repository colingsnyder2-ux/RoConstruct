// from server: 100% by coldek
// from server: 98% by colin
// roc 2008-06 0062fc00  unit: RBX::Rocket  size: 1225 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0062fc00
//
// 0062fc00  83ec50               sub esp, 0x50
// 0062fc03  57                   push edi
// 0062fc04  8bf9                 mov edi, ecx
// 0062fc06  807f1800             cmp byte ptr [edi + 0x18], 0
// 0062fc0a  0f84b2040000         je 0x6300c2
// 0062fc10  53                   push ebx
// 0062fc11  56                   push esi
// 0062fc12  8d44240c             lea eax, [esp + 0xc]
// 0062fc16  50                   push eax
// 0062fc17  8d4f10               lea ecx, [edi + 0x10]
// 0062fc1a  e8e1aef9ff           call 0x5cab00
// 0062fc1f  8b742410             mov esi, dword ptr [esp + 0x10]
// 0062fc23  8b08                 mov ecx, dword ptr [eax]
// 0062fc25  8b99c8020000         mov ebx, dword ptr [ecx + 0x2c8]
// 0062fc2b  85f6                 test esi, esi
// 0062fc2d  742a                 je 0x62fc59
// 0062fc2f  8d5604               lea edx, [esi + 4]
// 0062fc32  83c8ff               or eax, 0xffffffff
// 0062fc35  f00fc102             lock xadd dword ptr [edx], eax
// 0062fc39  751e                 jne 0x62fc59
// 0062fc3b  8b16                 mov edx, dword ptr [esi]
// 0062fc3d  8b4204               mov eax, dword ptr [edx + 4]
// 0062fc40  8bce                 mov ecx, esi
// 0062fc42  ffd0                 call eax
// 0062fc44  8d4e08               lea ecx, [esi + 8]
// 0062fc47  83caff               or edx, 0xffffffff
// 0062fc4a  f00fc111             lock xadd dword ptr [ecx], edx
// 0062fc4e  7509                 jne 0x62fc59
// 0062fc50  8b06                 mov eax, dword ptr [esi]
// 0062fc52  8b5008               mov edx, dword ptr [eax + 8]
// 0062fc55  8bce                 mov ecx, esi
// 0062fc57  ffd2                 call edx
// 0062fc59  8b4f1c               mov ecx, dword ptr [edi + 0x1c]
// 0062fc5c  8d4724               lea eax, [edi + 0x24]
// 0062fc5f  85c9                 test ecx, ecx
// 0062fc61  7412                 je 0x62fc75
// 0062fc63  50                   push eax
// 0062fc64  8d542448             lea edx, [esp + 0x48]
// 0062fc68  52                   push edx
// 0062fc69  e84290f6ff           call 0x598cb0
// 0062fc6e  8bc8                 mov ecx, eax
// 0062fc70  e82b6ae4ff           call 0x4766a0
// 0062fc75  d900                 fld dword ptr [eax]
// 0062fc77  8bcb                 mov ecx, ebx
// 0062fc79  d95c2420             fstp dword ptr [esp + 0x20]
// 0062fc7d  d94004               fld dword ptr [eax + 4]
// 0062fc80  d95c2424             fstp dword ptr [esp + 0x24]
// 0062fc84  d94008               fld dword ptr [eax + 8]
// 0062fc87  d95c2428             fstp dword ptr [esp + 0x28]
// 0062fc8b  e8d096f6ff           call 0x599360
// 0062fc90  d9442420             fld dword ptr [esp + 0x20]
// 0062fc94  8b7310               mov esi, dword ptr [ebx + 0x10]
// 0062fc97  d8a3b8000000         fsub dword ptr [ebx + 0xb8]
// 0062fc9d  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 0062fca0  d9442424             fld dword ptr [esp + 0x24]
// 0062fca4  d8a3bc000000         fsub dword ptr [ebx + 0xbc]
// 0062fcaa  d9442428             fld dword ptr [esp + 0x28]
// 0062fcae  d8a3c0000000         fsub dword ptr [ebx + 0xc0]
// 0062fcb4  d9c0                 fld st(0)
// 0062fcb6  d8c9                 fmul st(1)
// 0062fcb8  d9c2                 fld st(2)
// 0062fcba  d8cb                 fmul st(3)
// 0062fcbc  dec1                 faddp st(1)
// 0062fcbe  d9c3                 fld st(3)
// 0062fcc0  d8cc                 fmul st(4)
// 0062fcc2  dec1                 faddp st(1)
// 0062fcc4  d9fa                 fsqrt 
// 0062fcc6  d9e8                 fld1 
// 0062fcc8  def1                 fdivrp st(1)
// 0062fcca  d9c0                 fld st(0)
// 0062fccc  d8cc                 fmul st(4)
// 0062fcce  d95c2438             fstp dword ptr [esp + 0x38]
// 0062fcd2  d9c2                 fld st(2)
// 0062fcd4  d8c9                 fmul st(1)
// 0062fcd6  d95c243c             fstp dword ptr [esp + 0x3c]
// 0062fcda  d8c9                 fmul st(1)
// 0062fcdc  d95c2440             fstp dword ptr [esp + 0x40]
// 0062fce0  d9473c               fld dword ptr [edi + 0x3c]
// 0062fce3  d9c0                 fld st(0)
// 0062fce5  decc                 fmulp st(4)
// 0062fce7  d9cb                 fxch st(3)
// 0062fce9  d95c2420             fstp dword ptr [esp + 0x20]
// 0062fced  d9c9                 fxch st(1)
// 0062fcef  d8ca                 fmul st(2)
// 0062fcf1  d95c2424             fstp dword ptr [esp + 0x24]
// 0062fcf5  dec9                 fmulp st(1)
// 0062fcf7  d95c2428             fstp dword ptr [esp + 0x28]
// 0062fcfb  85c9                 test ecx, ecx
// 0062fcfd  7407                 je 0x62fd06
// 0062fcff  e80c020300           call 0x65ff10
// 0062fd04  eb06                 jmp 0x62fd0c
// 0062fd06  d9868c000000         fld dword ptr [esi + 0x8c]
// 0062fd0c  d9442420             fld dword ptr [esp + 0x20]
// 0062fd10  8bce                 mov ecx, esi
// 0062fd12  d8c9                 fmul st(1)
// 0062fd14  d95c2414             fstp dword ptr [esp + 0x14]
// 0062fd18  d9442424             fld dword ptr [esp + 0x24]
// 0062fd1c  d8c9                 fmul st(1)
// 0062fd1e  d95c2418             fstp dword ptr [esp + 0x18]
// 0062fd22  d84c2428             fmul dword ptr [esp + 0x28]
// 0062fd26  d95c241c             fstp dword ptr [esp + 0x1c]
// 0062fd2a  e83196f6ff           call 0x599360
// 0062fd2f  d986cc000000         fld dword ptr [esi + 0xcc]
// 0062fd35  d986c8000000         fld dword ptr [esi + 0xc8]
// 0062fd3b  d986c4000000         fld dword ptr [esi + 0xc4]
// 0062fd41  d94744               fld dword ptr [edi + 0x44]
// 0062fd44  d9c1                 fld st(1)
// 0062fd46  deca                 fmulp st(2)
// 0062fd48  d9c2                 fld st(2)
// 0062fd4a  decb                 fmulp st(3)
// 0062fd4c  d9c9                 fxch st(1)
// 0062fd4e  dec2                 faddp st(2)
// 0062fd50  d9c2                 fld st(2)
// 0062fd52  decb                 fmulp st(3)
// 0062fd54  d9c9                 fxch st(1)
// 0062fd56  dec2                 faddp st(2)
// 0062fd58  dcc8                 fmul st(0), st(0)
// 0062fd5a  ded9                 fcompp 
// 0062fd5c  dfe0                 fnstsw ax
// 0062fd5e  f6c405               test ah, 5
// 0062fd61  0f8a4c010000         jp 0x62feb3
// 0062fd67  8bce                 mov ecx, esi
// 0062fd69  e8f295f6ff           call 0x599360
// 0062fd6e  d986cc000000         fld dword ptr [esi + 0xcc]
// 0062fd74  d986c8000000         fld dword ptr [esi + 0xc8]
// 0062fd7a  d986c4000000         fld dword ptr [esi + 0xc4]
// 0062fd80  dcc8                 fmul st(0), st(0)
// 0062fd82  d9c1                 fld st(1)
// 0062fd84  deca                 fmulp st(2)
// 0062fd86  dec1                 faddp st(1)
// 0062fd88  d9c1                 fld st(1)
// 0062fd8a  deca                 fmulp st(2)
// 0062fd8c  dec1                 faddp st(1)
// 0062fd8e  d9fa                 fsqrt 
// 0062fd90  d9e8                 fld1 
// 0062fd92  def1                 fdivrp st(1)
// 0062fd94  d986c4000000         fld dword ptr [esi + 0xc4]
// 0062fd9a  d8c9                 fmul st(1)
// 0062fd9c  d986c8000000         fld dword ptr [esi + 0xc8]
// 0062fda2  d8ca                 fmul st(2)
// 0062fda4  d986cc000000         fld dword ptr [esi + 0xcc]
// 0062fdaa  decb                 fmulp st(3)
// 0062fdac  d9c2                 fld st(2)
// 0062fdae  d944241c             fld dword ptr [esp + 0x1c]
// 0062fdb2  dcc9                 fmul st(1), st(0)
// 0062fdb4  d9c2                 fld st(2)
// 0062fdb6  d84c2418             fmul dword ptr [esp + 0x18]
// 0062fdba  dec2                 faddp st(2)
// 0062fdbc  d9c3                 fld st(3)
// 0062fdbe  d84c2414             fmul dword ptr [esp + 0x14]
// 0062fdc2  dec2                 faddp st(2)
// 0062fdc4  d9ee                 fldz 
// 0062fdc6  d8da                 fcomp st(2)
// 0062fdc8  dfe0                 fnstsw ax
// 0062fdca  f6c405               test ah, 5
// 0062fdcd  0f8ad6000000         jp 0x62fea9
// 0062fdd3  d9c3                 fld st(3)
// 0062fdd5  8bce                 mov ecx, esi
// 0062fdd7  d8ca                 fmul st(2)
// 0062fdd9  d9c3                 fld st(3)
// 0062fddb  d8cb                 fmul st(3)
// 0062fddd  d9c6                 fld st(6)
// 0062fddf  decc                 fmulp st(4)
// 0062fde1  d9442414             fld dword ptr [esp + 0x14]
// 0062fde5  dee2                 fsubrp st(2)
// 0062fde7  d9c9                 fxch st(1)
// 0062fde9  d95c2414             fstp dword ptr [esp + 0x14]
// 0062fded  d86c2418             fsubr dword ptr [esp + 0x18]
// 0062fdf1  d95c2418             fstp dword ptr [esp + 0x18]
// 0062fdf5  dee1                 fsubrp st(1)
// 0062fdf7  d95c241c             fstp dword ptr [esp + 0x1c]
// 0062fdfb  d94744               fld dword ptr [edi + 0x44]
// 0062fdfe  dcca                 fmul st(2), st(0)
// 0062fe00  d9ca                 fxch st(2)
// 0062fe02  d95c2420             fstp dword ptr [esp + 0x20]
// 0062fe06  d8c9                 fmul st(1)
// 0062fe08  d95c2424             fstp dword ptr [esp + 0x24]
// 0062fe0c  dec9                 fmulp st(1)
// 0062fe0e  d95c2428             fstp dword ptr [esp + 0x28]
// 0062fe12  e84995f6ff           call 0x599360
// 0062fe17  d986c4000000         fld dword ptr [esi + 0xc4]
// 0062fe1d  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 0062fe20  d8642420             fsub dword ptr [esp + 0x20]
// 0062fe24  d95c242c             fstp dword ptr [esp + 0x2c]
// 0062fe28  d986c8000000         fld dword ptr [esi + 0xc8]
// 0062fe2e  d8642424             fsub dword ptr [esp + 0x24]
// 0062fe32  d95c2430             fstp dword ptr [esp + 0x30]
// 0062fe36  d986cc000000         fld dword ptr [esi + 0xcc]
// 0062fe3c  d8642428             fsub dword ptr [esp + 0x28]
// 0062fe40  d95c2434             fstp dword ptr [esp + 0x34]
// 0062fe44  85c9                 test ecx, ecx
// 0062fe46  7407                 je 0x62fe4f
// 0062fe48  e8c3000300           call 0x65ff10
// 0062fe4d  eb06                 jmp 0x62fe55
// 0062fe4f  d9868c000000         fld dword ptr [esi + 0x8c]
// 0062fe55  d944242c             fld dword ptr [esp + 0x2c]
// 0062fe59  51                   push ecx
// 0062fe5a  d8c9                 fmul st(1)
// 0062fe5c  8d442454             lea eax, [esp + 0x54]
// 0062fe60  8d4c2448             lea ecx, [esp + 0x48]
// 0062fe64  d95c2448             fstp dword ptr [esp + 0x48]
// 0062fe68  d9442434             fld dword ptr [esp + 0x34]
// 0062fe6c  d8c9                 fmul st(1)
// 0062fe6e  d95c244c             fstp dword ptr [esp + 0x4c]
// 0062fe72  d84c2438             fmul dword ptr [esp + 0x38]
// 0062fe76  d95c2450             fstp dword ptr [esp + 0x50]
// 0062fe7a  d9442464             fld dword ptr [esp + 0x64]
// 0062fe7e  d91c24               fstp dword ptr [esp]
// 0062fe81  50                   push eax
// 0062fe82  e8b988eeff           call 0x518740
// 0062fe87  d9442414             fld dword ptr [esp + 0x14]
// 0062fe8b  d820                 fsub dword ptr [eax]
// 0062fe8d  d95c2414             fstp dword ptr [esp + 0x14]
// 0062fe91  d9442418             fld dword ptr [esp + 0x18]
// 0062fe95  d86004               fsub dword ptr [eax + 4]
// 0062fe98  d95c2418             fstp dword ptr [esp + 0x18]
// 0062fe9c  d944241c             fld dword ptr [esp + 0x1c]
// 0062fea0  d86008               fsub dword ptr [eax + 8]
// 0062fea3  d95c241c             fstp dword ptr [esp + 0x1c]
// 0062fea7  eb0a                 jmp 0x62feb3
// 0062fea9  ddd9                 fstp st(1)
// 0062feab  ddda                 fstp st(2)
// 0062fead  ddd8                 fstp st(0)
// 0062feaf  ddd9                 fstp st(1)
// 0062feb1  ddd8                 fstp st(0)
// 0062feb3  8bce                 mov ecx, esi
// 0062feb5  e8a694f6ff           call 0x599360
// 0062feba  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 0062febd  85c9                 test ecx, ecx
// 0062febf  7407                 je 0x62fec8
// 0062fec1  e84a000300           call 0x65ff10
// 0062fec6  eb06                 jmp 0x62fece
// 0062fec8  d9868c000000         fld dword ptr [esi + 0x8c]
// 0062fece  d84f40               fmul dword ptr [edi + 0x40]
// 0062fed1  d9c0                 fld st(0)
// 0062fed3  d88ec4000000         fmul dword ptr [esi + 0xc4]
// 0062fed9  d986c8000000         fld dword ptr [esi + 0xc8]
// 0062fedf  d8ca                 fmul st(2)
// 0062fee1  d986cc000000         fld dword ptr [esi + 0xcc]
// 0062fee7  decb                 fmulp st(3)
// 0062fee9  d9442414             fld dword ptr [esp + 0x14]
// 0062feed  dee2                 fsubrp st(2)
// 0062feef  d9c9                 fxch st(1)
// 0062fef1  d9542414             fst dword ptr [esp + 0x14]
// 0062fef5  d9442418             fld dword ptr [esp + 0x18]
// 0062fef9  dee2                 fsubrp st(2)
// 0062fefb  d9c9                 fxch st(1)
// 0062fefd  d9542418             fst dword ptr [esp + 0x18]
// 0062ff01  d944241c             fld dword ptr [esp + 0x1c]
// 0062ff05  dee3                 fsubrp st(3)
// 0062ff07  d9ca                 fxch st(2)
// 0062ff09  d954241c             fst dword ptr [esp + 0x1c]
// 0062ff0d  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0062ff10  8b412c               mov eax, dword ptr [ecx + 0x2c]
// 0062ff13  85c0                 test eax, eax
// 0062ff15  7407                 je 0x62ff1e
// 0062ff17  0584000000           add eax, 0x84
// 0062ff1c  eb29                 jmp 0x62ff47
// 0062ff1e  f60550f0960001       test byte ptr [0x96f050], 1
// 0062ff25  751b                 jne 0x62ff42
// 0062ff27  d9ee                 fldz 
// 0062ff29  830d50f0960001       or dword ptr [0x96f050], 1
// 0062ff30  d91544f09600         fst dword ptr [0x96f044]
// 0062ff36  d91548f09600         fst dword ptr [0x96f048]
// 0062ff3c  d91d4cf09600         fstp dword ptr [0x96f04c]
// 0062ff42  b844f09600           mov eax, 0x96f044
// 0062ff47  d9c9                 fxch st(1)
// 0062ff49  8d542414             lea edx, [esp + 0x14]
// 0062ff4d  d820                 fsub dword ptr [eax]
// 0062ff4f  52                   push edx
// 0062ff50  d95c2418             fstp dword ptr [esp + 0x18]
// 0062ff54  d9c9                 fxch st(1)
// 0062ff56  d86004               fsub dword ptr [eax + 4]
// 0062ff59  d95c241c             fstp dword ptr [esp + 0x1c]
// 0062ff5d  d86008               fsub dword ptr [eax + 8]
// 0062ff60  d95c2420             fstp dword ptr [esp + 0x20]
// 0062ff64  e8d7d9faff           call 0x5dd940
// 0062ff69  d94738               fld dword ptr [edi + 0x38]
// 0062ff6c  83c404               add esp, 4
// 0062ff6f  d95c2444             fstp dword ptr [esp + 0x44]
// 0062ff73  8d442444             lea eax, [esp + 0x44]
// 0062ff77  d94738               fld dword ptr [edi + 0x38]
// 0062ff7a  50                   push eax
// 0062ff7b  d95c244c             fstp dword ptr [esp + 0x4c]
// 0062ff7f  8d4c2430             lea ecx, [esp + 0x30]
// 0062ff83  d94738               fld dword ptr [edi + 0x38]
// 0062ff86  51                   push ecx
// 0062ff87  d95c2454             fstp dword ptr [esp + 0x54]
// 0062ff8b  8d542458             lea edx, [esp + 0x58]
// 0062ff8f  d94738               fld dword ptr [edi + 0x38]
// 0062ff92  52                   push edx
// 0062ff93  d9e0                 fchs 
// 0062ff95  8d4c2420             lea ecx, [esp + 0x20]
// 0062ff99  d9542438             fst dword ptr [esp + 0x38]
// 0062ff9d  d954243c             fst dword ptr [esp + 0x3c]
// 0062ffa1  d95c2440             fstp dword ptr [esp + 0x40]
// 0062ffa5  e85661e7ff           call 0x4a6100
// 0062ffaa  d900                 fld dword ptr [eax]
// 0062ffac  8bce                 mov ecx, esi
// 0062ffae  d95c2414             fstp dword ptr [esp + 0x14]
// 0062ffb2  d94004               fld dword ptr [eax + 4]
// 0062ffb5  d95c2418             fstp dword ptr [esp + 0x18]
// 0062ffb9  d94008               fld dword ptr [eax + 8]
// 0062ffbc  8d442414             lea eax, [esp + 0x14]
// 0062ffc0  50                   push eax
// 0062ffc1  d95c2420             fstp dword ptr [esp + 0x20]
// 0062ffc5  e876e1ffff           call 0x62e140
// 0062ffca  d944241c             fld dword ptr [esp + 0x1c]
// 0062ffce  d9c0                 fld st(0)
// 0062ffd0  d8c9                 fmul st(1)
// 0062ffd2  d9442418             fld dword ptr [esp + 0x18]
// 0062ffd6  d9c0                 fld st(0)
// 0062ffd8  d8c9                 fmul st(1)
// 0062ffda  dec2                 faddp st(2)
// 0062ffdc  d9442414             fld dword ptr [esp + 0x14]
// 0062ffe0  d9c0                 fld st(0)
// 0062ffe2  d8c9                 fmul st(1)
// 0062ffe4  dec3                 faddp st(3)
// 0062ffe6  d905706e8200         fld dword ptr [0x826e70]
// 0062ffec  d8db                 fcomp st(3)
// 0062ffee  dfe0                 fnstsw ax
// 0062fff0  f6c405               test ah, 5
// 0062fff3  7a2a                 jp 0x63001f
// 0062fff5  d9ca                 fxch st(2)
// 0062fff7  8d442444             lea eax, [esp + 0x44]
// 0062fffb  d9fa                 fsqrt 
// 0062fffd  d9e8                 fld1 
// 0062ffff  d9c0                 fld st(0)
// 00630001  def2                 fdivrp st(2)
// 00630003  d9c1                 fld st(1)
// 00630005  decc                 fmulp st(4)
// 00630007  d9cb                 fxch st(3)
// 00630009  d95c2444             fstp dword ptr [esp + 0x44]
// 0063000d  dcc9                 fmul st(1), st(0)
// 0063000f  d9c9                 fxch st(1)
// 00630011  d95c2448             fstp dword ptr [esp + 0x48]
// 00630015  deca                 fmulp st(2)
// 00630017  d9c9                 fxch st(1)
// 00630019  d95c244c             fstp dword ptr [esp + 0x4c]
// 0063001d  eb33                 jmp 0x630052
// 0063001f  f60550f0960001       test byte ptr [0x96f050], 1
// 00630026  ddda                 fstp st(2)
// 00630028  ddda                 fstp st(2)
// 0063002a  ddd9                 fstp st(1)
// 0063002c  ddd8                 fstp st(0)
// 0063002e  751b                 jne 0x63004b
// 00630030  d9ee                 fldz 
// 00630032  830d50f0960001       or dword ptr [0x96f050], 1
// 00630039  d91544f09600         fst dword ptr [0x96f044]
// 0063003f  d91548f09600         fst dword ptr [0x96f048]
// 00630045  d91d4cf09600         fstp dword ptr [0x96f04c]
// 0063004b  d9e8                 fld1 
// 0063004d  b844f09600           mov eax, 0x96f044
// 00630052  d900                 fld dword ptr [eax]
// 00630054  8d4c2444             lea ecx, [esp + 0x44]
// 00630058  d94004               fld dword ptr [eax + 4]
// 0063005b  51                   push ecx
// 0063005c  d94008               fld dword ptr [eax + 8]
// 0063005f  53                   push ebx
// 00630060  d9c3                 fld st(3)
// 00630062  8d542458             lea edx, [esp + 0x58]
// 00630066  d8675c               fsub dword ptr [edi + 0x5c]
// 00630069  52                   push edx
// 0063006a  8d8fd0feffff         lea ecx, [edi - 0x130]
// 00630070  dccb                 fmul st(3), st(0)
// 00630072  dcca                 fmul st(2), st(0)
// 00630074  dec9                 fmulp st(1)
// 00630076  d9475c               fld dword ptr [edi + 0x5c]
// 00630079  d9442444             fld dword ptr [esp + 0x44]
// 0063007d  d8c9                 fmul st(1)
// 0063007f  d9442448             fld dword ptr [esp + 0x48]
// 00630083  d8ca                 fmul st(2)
// 00630085  d944244c             fld dword ptr [esp + 0x4c]
// 00630089  decb                 fmulp st(3)
// 0063008b  d9c9                 fxch st(1)
// 0063008d  dec5                 faddp st(5)
// 0063008f  dec3                 faddp st(3)
// 00630091  dec1                 faddp st(1)
// 00630093  d9c2                 fld st(2)
// 00630095  d8cb                 fmul st(3)
// 00630097  d9c1                 fld st(1)
// 00630099  d8ca                 fmul st(2)
// 0063009b  dec1                 faddp st(1)
// 0063009d  d9c2                 fld st(2)
// 0063009f  d8cb                 fmul st(3)
// 006300a1  dec1                 faddp st(1)
// 006300a3  d9fa                 fsqrt 
// 006300a5  defc                 fdivp st(4)
// 006300a7  d9ca                 fxch st(2)
// 006300a9  d8cb                 fmul st(3)
// 006300ab  d95c2450             fstp dword ptr [esp + 0x50]
// 006300af  d8ca                 fmul st(2)
// 006300b1  d95c2454             fstp dword ptr [esp + 0x54]
// 006300b5  dec9                 fmulp st(1)
// 006300b7  d95c2458             fstp dword ptr [esp + 0x58]
// 006300bb  e870e4ffff           call 0x62e530
// 006300c0  5e                   pop esi
// 006300c1  5b                   pop ebx
// 006300c2  5f                   pop edi
// 006300c3  83c450               add esp, 0x50
// 006300c6  c20800               ret 8

// from server: 97% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Full native Rocket::computeForce; target-observed Instance/Connector/Listener and Body layouts.
#include <math.h>
#include <stddef.h>
#include <intrin.h>
#include <utility>
namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose()=0;
    virtual void destroy(){delete this;}
    long use_count_,weak_count_;
    void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
    void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count():pi_(0){}
    shared_count& operator=(const shared_count& r){sp_counted_base* tmp=r.pi_;if(tmp!=pi_){if(tmp)_InterlockedIncrement(&tmp->use_count_);if(pi_)pi_->release();pi_=tmp;}return *this;}
    void swap(shared_count& r){sp_counted_base* tmp=r.pi_;r.pi_=pi_;pi_=tmp;}
    shared_count(const shared_count& r):pi_(r.pi_){if(pi_)_InterlockedIncrement(&pi_->use_count_);}
    ~shared_count(){if(pi_)pi_->release();}
};
}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    shared_ptr():px(0),pn(){}
    shared_ptr& operator=(const shared_ptr& r){px=r.px;pn=r.pn;return *this;}
    void swap(shared_ptr& r){std::swap(px,r.px);pn.swap(r.pn);}
    void reset(){shared_ptr().swap(*this);}
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type()const{return px==0?0:&shared_ptr::px;}
    shared_ptr(const shared_ptr& r):px(r.px),pn(r.pn){}
    template<class Y> shared_ptr(const shared_ptr<Y>& r):px(r.px),pn(r.pn){}
    T* get()const{return px;}
    T* operator->()const{return px;}
};
template<class T,class U> bool operator==(const shared_ptr<T>& a,const shared_ptr<U>& b){return a.get()==b.get();}
}

namespace boost {
template<class T>struct weak_ptr {T*px;void*pn;shared_ptr<T>lock()const;};
}

namespace G3D {
struct Vector3 {
 float x,y,z;
 Vector3():x(0),y(0),z(0){}
 Vector3(float a,float b,float c):x(a),y(b),z(c){}
 Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}
 Vector3&operator=(const Vector3&v){x=v.x;y=v.y;z=v.z;return *this;}
 float&operator[](int i){return ((float*)this)[i];}
 const float&operator[](int i)const{return ((const float*)this)[i];}
 float squaredMagnitude()const{return x*x+y*y+z*z;}
 float dot(const Vector3&v)const{double p0=x*v.x;double p1=y*v.y;double p2=z*v.z;return static_cast<float>((p2+p1)+p0);}
 Vector3 direction()const{float n=squaredMagnitude();float inv=1.0f/sqrtf(n);return (*this)*inv;}
 Vector3 fastDirection()const{float n=x*x+y*y+z*z;float inv=1.0f/sqrtf(n);return Vector3(x*inv,y*inv,z*inv);}
 Vector3 operator*(float f)const{return Vector3(x*f,y*f,z*f);}
 Vector3 operator/(float)const;
 Vector3 operator+(const Vector3&v)const{return Vector3(x+v.x,y+v.y,z+v.z);}
 Vector3&operator-=(const Vector3&v){x-=v.x;y-=v.y;z-=v.z;return *this;}
 Vector3 clamp(const Vector3&,const Vector3&)const;
 Vector3 operator-(const Vector3&v)const{return Vector3(x-v.x,y-v.y,z-v.z);}
 Vector3&operator+=(const Vector3&v){x+=v.x;y+=v.y;z+=v.z;return *this;}
 static const Vector3&zero(){static Vector3 v(0,0,0);return v;}
};
struct Matrix3 {
 float elt[3][3];
 Matrix3(){}Matrix3(const Matrix3&);
 Matrix3 transpose()const;
 Vector3 operator*(const Vector3&v)const{
  Vector3 kProd;
  for(int r=0;r<3;++r)kProd[r]=elt[r][0]*v[0]+elt[r][1]*v[1]+elt[r][2]*v[2];
  return kProd;
 }
};
struct CoordinateFrame {
 Matrix3 rotation;Vector3 translation;
 Vector3 pointToWorldSpace(const Vector3&)const;
 Vector3 vectorToObjectSpace(const Vector3&v)const{return rotation.transpose()*v;}
 Vector3 vectorToWorldSpace(const Vector3&v)const{return rotation*v;}
};
}
inline G3D::Vector3 operator*(float f,const G3D::Vector3&v){return v*f;}
namespace RBX {
struct Velocity {G3D::Vector3 linear,rotational;};
struct PV {G3D::CoordinateFrame position;Velocity velocity;};
struct Math {static G3D::Vector3 toDiagonal(const G3D::Matrix3&);static bool fixDenorm(G3D::Vector3&);};
struct Cofm {const G3D::Matrix3&getMoment()const;float getMass()const;};
struct Body;
struct SimBody {
 Body*body;float dt;bool dirty;char unused[0x84-9];G3D::Vector3 force,torque;
 void update();
 void accumulateTorque(const G3D::Vector3&v){if(dirty)update();torque+=v;}
};
struct Body {
 char prefix[0x10];Body*root;
 char unused[0x28-0x14];Cofm*cofm;SimBody*simBody;
 char unused2[0x68-0x30];G3D::Matrix3 moment;float mass;int stateIndex;PV pv;
 void updatePV()const;
 Body*getRoot(){return root;}
 float getBranchMass()const{return cofm?cofm->getMass():mass;}
 const G3D::Vector3&getBranchForce()const{return root->simBody?root->simBody->force:G3D::Vector3::zero();}
 void accumulateForceAtBranchCofm(const G3D::Vector3&);
 const G3D::CoordinateFrame&getCoordinateFrame()const{updatePV();return pv.position;}
 const Velocity&getVelocity()const{updatePV();return pv.velocity;}
 const G3D::Vector3&getBranchTorque()const{return root->simBody?root->simBody->torque:G3D::Vector3::zero();}
 G3D::Matrix3 getBranchIBody()const{return cofm?cofm->getMoment():moment;}
 G3D::Vector3 getBranchIBodyV3()const{return Math::toDiagonal(getBranchIBody());}
 void accumulateTorque(const G3D::Vector3&v){if(root->simBody)root->simBody->accumulateTorque(v);}
};

// The target directly loads the Body link from the locked PartInstance at2c8.
struct PartInstance {char unobserved[0x2c8];Body*body;const G3D::CoordinateFrame&getCoordinateFrame()const;};
struct Instance {virtual ~Instance();char unobserved[0x130-4];};
struct KernelIndex {int kernelIndex;};
struct Connector:KernelIndex {
 virtual ~Connector();virtual void computeForce(float,bool)=0;
 virtual bool canThrottle()const;virtual bool getBroken();virtual float potentialEnergy();
};
struct RunService;struct Stepped {float time,step;};
template<class C,class E>struct Listener {virtual void onEvent(const C*,E)=0;virtual ~Listener();};
struct World;
struct BodyMover:Instance,Connector,Listener<RunService,Stepped> {World*world;boost::weak_ptr<PartInstance>part;};
struct Rocket:BodyMover {
 bool active;boost::shared_ptr<PartInstance>target;G3D::Vector3 targetOffset;float targetRadius;bool firedEvent;
 float maxThrust,kThrustP,kThrustD,maxSpeed,kTurnP,kTurnD;G3D::Vector3 maxTorque;float cartoonFactor;
 virtual void computeForce(float,bool);
 G3D::Vector3 turn(Body*,const G3D::Vector3&);
};
void Rocket::computeForce(const float dt, bool throttling)
	{
		float roc_f0 = 0;
		float roc_f1 = 0;
		float roc_f2 = 0;
		float roc_f3 = 0;
		if (!active)
			return;

		Body* body = part.lock()->body;
		

		G3D::Vector3 targetPos = target.get() ? target->getCoordinateFrame().pointToWorldSpace(targetOffset) : targetOffset;
		G3D::Vector3 targetDelta = targetPos - body->getCoordinateFrame().translation; // fabricated name, may change
		G3D::Vector3 pAccel, targetDir;
		targetDir = targetDelta.direction();
		pAccel = targetDelta * kThrustP;
		Body* root = body->getRoot();

		G3D::Vector3 force = pAccel * root->getBranchMass();

		if (root->getVelocity().linear.squaredMagnitude() > maxSpeed * maxSpeed)
		{
			G3D::Vector3 dir = root->getVelocity().linear.direction();
			float dotProduct = dir.dot(force);
			if (dotProduct > 0.0f)
			{
				force -= dir * dotProduct;
				force -= root->getBranchMass() * (root->getVelocity().linear - maxSpeed * dir) / dt;
			}
		}

		G3D::Vector3 adjustedVelocity = (root->getBranchMass() * kThrustD) * root->getVelocity().linear; // fabricated name, may change
		force -= adjustedVelocity;

		force -= body->getBranchForce();

		Math::fixDenorm(force);

		force=force.clamp(G3D::Vector3(-maxThrust,-maxThrust,-maxThrust),G3D::Vector3(maxThrust,maxThrust,maxThrust));

		root->accumulateForceAtBranchCofm(force);

		G3D::Vector3 unitForce = force.squaredMagnitude() > 0.000001f ? force.fastDirection() : G3D::Vector3::zero(); // fabricated name, may change
		G3D::Vector3 forceCartoon = unitForce * (1.0f - cartoonFactor); // fabricated name, may change
		G3D::Vector3 newDirection = forceCartoon + (targetDir * cartoonFactor); // fabricated name, may change
		turn(body, newDirection.direction());
	}

	
}
typedef char body_pv_offset[offsetof(RBX::Body,pv)==0x94?1:-1];
typedef char bodymover_size[sizeof(RBX::BodyMover)==0x148?1:-1];
typedef char rocket_active_offset[offsetof(RBX::Rocket,active)==0x148?1:-1];
typedef char rocket_target_offset[offsetof(RBX::Rocket,target)==0x14c?1:-1];
typedef char rocket_gain_offset[offsetof(RBX::Rocket,kTurnP)==0x178?1:-1];
typedef char rocket_cartoon_offset[offsetof(RBX::Rocket,cartoonFactor)==0x18c?1:-1];
