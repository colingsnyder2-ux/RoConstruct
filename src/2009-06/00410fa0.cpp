// from server: 100% by auto
// roc 2009-06 00410fa0  unit: CRbxChildFrame  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00410fa0
//
// 00410fa0  53                   push ebx
// 00410fa1  56                   push esi
// 00410fa2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00410fa6  57                   push edi
// 00410fa7  0fb77e02             movzx edi, word ptr [esi + 2]
// 00410fab  0fb7c7               movzx eax, di
// 00410fae  b90e000000           mov ecx, 0xe
// 00410fb3  2bc8                 sub ecx, eax
// 00410fb5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00410fba  f7e9                 imul ecx
// 00410fbc  d1fa                 sar edx, 1
// 00410fbe  8bca                 mov ecx, edx
// 00410fc0  c1e91f               shr ecx, 0x1f
// 00410fc3  03ca                 add ecx, edx
// 00410fc5  668b16               mov dx, word ptr [esi]
// 00410fc8  0fb7c1               movzx eax, cx
// 00410fcb  662bd0               sub dx, ax
// 00410fce  b9c0120000           mov ecx, 0x12c0
// 00410fd3  6603d1               add dx, cx
// 00410fd6  0fb7ca               movzx ecx, dx
// 00410fd9  8d1440               lea edx, [eax + eax*2]
// 00410fdc  8d4497fd             lea eax, [edi + edx*4 - 3]
// 00410fe0  0fb7d0               movzx edx, ax
// 00410fe3  69d299000000         imul edx, edx, 0x99
// 00410fe9  83c202               add edx, 2
// 00410fec  b867666666           mov eax, 0x66666667
// 00410ff1  f7ea                 imul edx
// 00410ff3  d1fa                 sar edx, 1
// 00410ff5  8bfa                 mov edi, edx
// 00410ff7  c1ef1f               shr edi, 0x1f
// 00410ffa  03fa                 add edi, edx
// 00410ffc  b81f85eb51           mov eax, 0x51eb851f
// 00411001  f7e9                 imul ecx
// 00411003  c1fa07               sar edx, 7
// 00411006  03fa                 add edi, edx
// 00411008  8bda                 mov ebx, edx
// 0041100a  b81f85eb51           mov eax, 0x51eb851f
// 0041100f  f7e9                 imul ecx
// 00411011  c1fa05               sar edx, 5
// 00411014  c1eb1f               shr ebx, 0x1f
// 00411017  8bc2                 mov eax, edx
// 00411019  c1e81f               shr eax, 0x1f
// 0041101c  03df                 add ebx, edi
// 0041101e  03c2                 add eax, edx
// 00411020  0fb75604             movzx edx, word ptr [esi + 4]
// 00411024  2bd8                 sub ebx, eax
// 00411026  8bc1                 mov eax, ecx
// 00411028  69c06d010000         imul eax, eax, 0x16d
// 0041102e  03da                 add ebx, edx
// 00411030  5f                   pop edi
// 00411031  03d8                 add ebx, eax
// 00411033  c1e902               shr ecx, 2
// 00411036  5e                   pop esi
// 00411037  8d840bd382ffff       lea eax, [ebx + ecx - 0x7d2d]
// 0041103e  5b                   pop ebx
// 0041103f  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?day_number@?$gregorian_calendar_base@U?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@date_time@boost@@K@date_time@boost@@SAKABU?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@23@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
