// from server: 100% by auto
// roc 2009-12 00410c20  unit: CRbxChildFrame  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00410c20
//
// 00410c20  53                   push ebx
// 00410c21  56                   push esi
// 00410c22  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00410c26  57                   push edi
// 00410c27  0fb77e02             movzx edi, word ptr [esi + 2]
// 00410c2b  0fb7c7               movzx eax, di
// 00410c2e  b90e000000           mov ecx, 0xe
// 00410c33  2bc8                 sub ecx, eax
// 00410c35  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00410c3a  f7e9                 imul ecx
// 00410c3c  d1fa                 sar edx, 1
// 00410c3e  8bca                 mov ecx, edx
// 00410c40  c1e91f               shr ecx, 0x1f
// 00410c43  03ca                 add ecx, edx
// 00410c45  668b16               mov dx, word ptr [esi]
// 00410c48  0fb7c1               movzx eax, cx
// 00410c4b  662bd0               sub dx, ax
// 00410c4e  b9c0120000           mov ecx, 0x12c0
// 00410c53  6603d1               add dx, cx
// 00410c56  0fb7ca               movzx ecx, dx
// 00410c59  8d1440               lea edx, [eax + eax*2]
// 00410c5c  8d4497fd             lea eax, [edi + edx*4 - 3]
// 00410c60  0fb7d0               movzx edx, ax
// 00410c63  69d299000000         imul edx, edx, 0x99
// 00410c69  83c202               add edx, 2
// 00410c6c  b867666666           mov eax, 0x66666667
// 00410c71  f7ea                 imul edx
// 00410c73  d1fa                 sar edx, 1
// 00410c75  8bfa                 mov edi, edx
// 00410c77  c1ef1f               shr edi, 0x1f
// 00410c7a  03fa                 add edi, edx
// 00410c7c  b81f85eb51           mov eax, 0x51eb851f
// 00410c81  f7e9                 imul ecx
// 00410c83  c1fa07               sar edx, 7
// 00410c86  03fa                 add edi, edx
// 00410c88  8bda                 mov ebx, edx
// 00410c8a  b81f85eb51           mov eax, 0x51eb851f
// 00410c8f  f7e9                 imul ecx
// 00410c91  c1fa05               sar edx, 5
// 00410c94  c1eb1f               shr ebx, 0x1f
// 00410c97  8bc2                 mov eax, edx
// 00410c99  c1e81f               shr eax, 0x1f
// 00410c9c  03df                 add ebx, edi
// 00410c9e  03c2                 add eax, edx
// 00410ca0  0fb75604             movzx edx, word ptr [esi + 4]
// 00410ca4  2bd8                 sub ebx, eax
// 00410ca6  8bc1                 mov eax, ecx
// 00410ca8  69c06d010000         imul eax, eax, 0x16d
// 00410cae  03da                 add ebx, edx
// 00410cb0  5f                   pop edi
// 00410cb1  03d8                 add ebx, eax
// 00410cb3  c1e902               shr ecx, 2
// 00410cb6  5e                   pop esi
// 00410cb7  8d840bd382ffff       lea eax, [ebx + ecx - 0x7d2d]
// 00410cbe  5b                   pop ebx
// 00410cbf  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?day_number@?$gregorian_calendar_base@U?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@date_time@boost@@K@date_time@boost@@SAKABU?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@23@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
