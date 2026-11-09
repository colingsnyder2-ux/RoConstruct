// from server: 100% by auto
// roc 2010-06 00410ef0  unit: CRbxChildFrame  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00410ef0
//
// 00410ef0  53                   push ebx
// 00410ef1  56                   push esi
// 00410ef2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00410ef6  57                   push edi
// 00410ef7  0fb77e02             movzx edi, word ptr [esi + 2]
// 00410efb  0fb7c7               movzx eax, di
// 00410efe  b90e000000           mov ecx, 0xe
// 00410f03  2bc8                 sub ecx, eax
// 00410f05  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00410f0a  f7e9                 imul ecx
// 00410f0c  d1fa                 sar edx, 1
// 00410f0e  8bca                 mov ecx, edx
// 00410f10  c1e91f               shr ecx, 0x1f
// 00410f13  03ca                 add ecx, edx
// 00410f15  668b16               mov dx, word ptr [esi]
// 00410f18  0fb7c1               movzx eax, cx
// 00410f1b  662bd0               sub dx, ax
// 00410f1e  b9c0120000           mov ecx, 0x12c0
// 00410f23  6603d1               add dx, cx
// 00410f26  0fb7ca               movzx ecx, dx
// 00410f29  8d1440               lea edx, [eax + eax*2]
// 00410f2c  8d4497fd             lea eax, [edi + edx*4 - 3]
// 00410f30  0fb7d0               movzx edx, ax
// 00410f33  69d299000000         imul edx, edx, 0x99
// 00410f39  83c202               add edx, 2
// 00410f3c  b867666666           mov eax, 0x66666667
// 00410f41  f7ea                 imul edx
// 00410f43  d1fa                 sar edx, 1
// 00410f45  8bfa                 mov edi, edx
// 00410f47  c1ef1f               shr edi, 0x1f
// 00410f4a  03fa                 add edi, edx
// 00410f4c  b81f85eb51           mov eax, 0x51eb851f
// 00410f51  f7e9                 imul ecx
// 00410f53  c1fa07               sar edx, 7
// 00410f56  03fa                 add edi, edx
// 00410f58  8bda                 mov ebx, edx
// 00410f5a  b81f85eb51           mov eax, 0x51eb851f
// 00410f5f  f7e9                 imul ecx
// 00410f61  c1fa05               sar edx, 5
// 00410f64  c1eb1f               shr ebx, 0x1f
// 00410f67  8bc2                 mov eax, edx
// 00410f69  c1e81f               shr eax, 0x1f
// 00410f6c  03df                 add ebx, edi
// 00410f6e  03c2                 add eax, edx
// 00410f70  0fb75604             movzx edx, word ptr [esi + 4]
// 00410f74  2bd8                 sub ebx, eax
// 00410f76  8bc1                 mov eax, ecx
// 00410f78  69c06d010000         imul eax, eax, 0x16d
// 00410f7e  03da                 add ebx, edx
// 00410f80  5f                   pop edi
// 00410f81  03d8                 add ebx, eax
// 00410f83  c1e902               shr ecx, 2
// 00410f86  5e                   pop esi
// 00410f87  8d840bd382ffff       lea eax, [ebx + ecx - 0x7d2d]
// 00410f8e  5b                   pop ebx
// 00410f8f  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?day_number@?$gregorian_calendar_base@U?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@date_time@boost@@K@date_time@boost@@SAKABU?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@23@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
