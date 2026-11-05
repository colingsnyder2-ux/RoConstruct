// from server: 100% by auto
// roc 2011-06 0040a3b0  unit: boost::exception_detail::clone_base  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0040a3b0
//
// 0040a3b0  53                   push ebx
// 0040a3b1  56                   push esi
// 0040a3b2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0040a3b6  57                   push edi
// 0040a3b7  0fb77e02             movzx edi, word ptr [esi + 2]
// 0040a3bb  0fb7c7               movzx eax, di
// 0040a3be  b90e000000           mov ecx, 0xe
// 0040a3c3  2bc8                 sub ecx, eax
// 0040a3c5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0040a3ca  f7e9                 imul ecx
// 0040a3cc  d1fa                 sar edx, 1
// 0040a3ce  8bca                 mov ecx, edx
// 0040a3d0  c1e91f               shr ecx, 0x1f
// 0040a3d3  03ca                 add ecx, edx
// 0040a3d5  668b16               mov dx, word ptr [esi]
// 0040a3d8  0fb7c1               movzx eax, cx
// 0040a3db  662bd0               sub dx, ax
// 0040a3de  b9c0120000           mov ecx, 0x12c0
// 0040a3e3  6603d1               add dx, cx
// 0040a3e6  0fb7ca               movzx ecx, dx
// 0040a3e9  8d1440               lea edx, [eax + eax*2]
// 0040a3ec  8d4497fd             lea eax, [edi + edx*4 - 3]
// 0040a3f0  0fb7d0               movzx edx, ax
// 0040a3f3  69d299000000         imul edx, edx, 0x99
// 0040a3f9  83c202               add edx, 2
// 0040a3fc  b867666666           mov eax, 0x66666667
// 0040a401  f7ea                 imul edx
// 0040a403  d1fa                 sar edx, 1
// 0040a405  8bfa                 mov edi, edx
// 0040a407  c1ef1f               shr edi, 0x1f
// 0040a40a  03fa                 add edi, edx
// 0040a40c  b81f85eb51           mov eax, 0x51eb851f
// 0040a411  f7e9                 imul ecx
// 0040a413  c1fa07               sar edx, 7
// 0040a416  03fa                 add edi, edx
// 0040a418  8bda                 mov ebx, edx
// 0040a41a  b81f85eb51           mov eax, 0x51eb851f
// 0040a41f  f7e9                 imul ecx
// 0040a421  c1fa05               sar edx, 5
// 0040a424  c1eb1f               shr ebx, 0x1f
// 0040a427  8bc2                 mov eax, edx
// 0040a429  c1e81f               shr eax, 0x1f
// 0040a42c  03df                 add ebx, edi
// 0040a42e  03c2                 add eax, edx
// 0040a430  0fb75604             movzx edx, word ptr [esi + 4]
// 0040a434  2bd8                 sub ebx, eax
// 0040a436  8bc1                 mov eax, ecx
// 0040a438  69c06d010000         imul eax, eax, 0x16d
// 0040a43e  03da                 add ebx, edx
// 0040a440  5f                   pop edi
// 0040a441  03d8                 add ebx, eax
// 0040a443  c1e902               shr ecx, 2
// 0040a446  5e                   pop esi
// 0040a447  8d840bd382ffff       lea eax, [ebx + ecx - 0x7d2d]
// 0040a44e  5b                   pop ebx
// 0040a44f  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?day_number@?$gregorian_calendar_base@U?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@date_time@boost@@K@date_time@boost@@SAKABU?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@23@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
