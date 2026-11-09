// from server: 100% by auto
// roc 2008-06 0055c1f0  unit: RBX::VInstance::?$SignalDesc  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055c1f0
//
// 0055c1f0  53                   push ebx
// 0055c1f1  56                   push esi
// 0055c1f2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0055c1f6  57                   push edi
// 0055c1f7  0fb77e02             movzx edi, word ptr [esi + 2]
// 0055c1fb  0fb7c7               movzx eax, di
// 0055c1fe  b90e000000           mov ecx, 0xe
// 0055c203  2bc8                 sub ecx, eax
// 0055c205  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0055c20a  f7e9                 imul ecx
// 0055c20c  d1fa                 sar edx, 1
// 0055c20e  8bca                 mov ecx, edx
// 0055c210  c1e91f               shr ecx, 0x1f
// 0055c213  03ca                 add ecx, edx
// 0055c215  668b16               mov dx, word ptr [esi]
// 0055c218  0fb7c1               movzx eax, cx
// 0055c21b  662bd0               sub dx, ax
// 0055c21e  b9c0120000           mov ecx, 0x12c0
// 0055c223  6603d1               add dx, cx
// 0055c226  0fb7ca               movzx ecx, dx
// 0055c229  8d1440               lea edx, [eax + eax*2]
// 0055c22c  8d4497fd             lea eax, [edi + edx*4 - 3]
// 0055c230  0fb7d0               movzx edx, ax
// 0055c233  69d299000000         imul edx, edx, 0x99
// 0055c239  83c202               add edx, 2
// 0055c23c  b867666666           mov eax, 0x66666667
// 0055c241  f7ea                 imul edx
// 0055c243  d1fa                 sar edx, 1
// 0055c245  8bfa                 mov edi, edx
// 0055c247  c1ef1f               shr edi, 0x1f
// 0055c24a  03fa                 add edi, edx
// 0055c24c  b81f85eb51           mov eax, 0x51eb851f
// 0055c251  f7e9                 imul ecx
// 0055c253  c1fa07               sar edx, 7
// 0055c256  03fa                 add edi, edx
// 0055c258  8bda                 mov ebx, edx
// 0055c25a  b81f85eb51           mov eax, 0x51eb851f
// 0055c25f  f7e9                 imul ecx
// 0055c261  c1fa05               sar edx, 5
// 0055c264  c1eb1f               shr ebx, 0x1f
// 0055c267  8bc2                 mov eax, edx
// 0055c269  c1e81f               shr eax, 0x1f
// 0055c26c  03df                 add ebx, edi
// 0055c26e  03c2                 add eax, edx
// 0055c270  0fb75604             movzx edx, word ptr [esi + 4]
// 0055c274  2bd8                 sub ebx, eax
// 0055c276  8bc1                 mov eax, ecx
// 0055c278  69c06d010000         imul eax, eax, 0x16d
// 0055c27e  03da                 add ebx, edx
// 0055c280  5f                   pop edi
// 0055c281  03d8                 add ebx, eax
// 0055c283  c1e902               shr ecx, 2
// 0055c286  5e                   pop esi
// 0055c287  8d840bd382ffff       lea eax, [ebx + ecx - 0x7d2d]
// 0055c28e  5b                   pop ebx
// 0055c28f  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?day_number@?$gregorian_calendar_base@U?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@date_time@boost@@K@date_time@boost@@SAKABU?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@23@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
