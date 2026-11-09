// from server: 100% by auto
// roc 2012-06 0040bac0  unit: boost::exception_detail::clone_base  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040bac0
//
// 0040bac0  53                   push ebx
// 0040bac1  56                   push esi
// 0040bac2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0040bac6  57                   push edi
// 0040bac7  0fb77e02             movzx edi, word ptr [esi + 2]
// 0040bacb  0fb7c7               movzx eax, di
// 0040bace  b90e000000           mov ecx, 0xe
// 0040bad3  2bc8                 sub ecx, eax
// 0040bad5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0040bada  f7e9                 imul ecx
// 0040badc  d1fa                 sar edx, 1
// 0040bade  8bca                 mov ecx, edx
// 0040bae0  c1e91f               shr ecx, 0x1f
// 0040bae3  03ca                 add ecx, edx
// 0040bae5  668b16               mov dx, word ptr [esi]
// 0040bae8  0fb7c1               movzx eax, cx
// 0040baeb  662bd0               sub dx, ax
// 0040baee  b9c0120000           mov ecx, 0x12c0
// 0040baf3  6603d1               add dx, cx
// 0040baf6  0fb7ca               movzx ecx, dx
// 0040baf9  8d1440               lea edx, [eax + eax*2]
// 0040bafc  8d4497fd             lea eax, [edi + edx*4 - 3]
// 0040bb00  0fb7d0               movzx edx, ax
// 0040bb03  69d299000000         imul edx, edx, 0x99
// 0040bb09  83c202               add edx, 2
// 0040bb0c  b867666666           mov eax, 0x66666667
// 0040bb11  f7ea                 imul edx
// 0040bb13  d1fa                 sar edx, 1
// 0040bb15  8bfa                 mov edi, edx
// 0040bb17  c1ef1f               shr edi, 0x1f
// 0040bb1a  03fa                 add edi, edx
// 0040bb1c  b81f85eb51           mov eax, 0x51eb851f
// 0040bb21  f7e9                 imul ecx
// 0040bb23  c1fa07               sar edx, 7
// 0040bb26  03fa                 add edi, edx
// 0040bb28  8bda                 mov ebx, edx
// 0040bb2a  b81f85eb51           mov eax, 0x51eb851f
// 0040bb2f  f7e9                 imul ecx
// 0040bb31  c1fa05               sar edx, 5
// 0040bb34  c1eb1f               shr ebx, 0x1f
// 0040bb37  8bc2                 mov eax, edx
// 0040bb39  c1e81f               shr eax, 0x1f
// 0040bb3c  03df                 add ebx, edi
// 0040bb3e  03c2                 add eax, edx
// 0040bb40  0fb75604             movzx edx, word ptr [esi + 4]
// 0040bb44  2bd8                 sub ebx, eax
// 0040bb46  8bc1                 mov eax, ecx
// 0040bb48  69c06d010000         imul eax, eax, 0x16d
// 0040bb4e  03da                 add ebx, edx
// 0040bb50  5f                   pop edi
// 0040bb51  03d8                 add ebx, eax
// 0040bb53  c1e902               shr ecx, 2
// 0040bb56  5e                   pop esi
// 0040bb57  8d840bd382ffff       lea eax, [ebx + ecx - 0x7d2d]
// 0040bb5e  5b                   pop ebx
// 0040bb5f  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?day_number@?$gregorian_calendar_base@U?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@date_time@boost@@K@date_time@boost@@SAKABU?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@23@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
