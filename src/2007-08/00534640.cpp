// from server: 100% by auto
// roc 2007-08 00534640  unit: RBX::ScriptContext  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00534640
//
// 00534640  53                   push ebx
// 00534641  56                   push esi
// 00534642  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00534646  57                   push edi
// 00534647  0fb77e02             movzx edi, word ptr [esi + 2]
// 0053464b  0fb7c7               movzx eax, di
// 0053464e  b90e000000           mov ecx, 0xe
// 00534653  2bc8                 sub ecx, eax
// 00534655  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0053465a  f7e9                 imul ecx
// 0053465c  d1fa                 sar edx, 1
// 0053465e  8bca                 mov ecx, edx
// 00534660  c1e91f               shr ecx, 0x1f
// 00534663  03ca                 add ecx, edx
// 00534665  668b16               mov dx, word ptr [esi]
// 00534668  0fb7c1               movzx eax, cx
// 0053466b  662bd0               sub dx, ax
// 0053466e  6681c2c012           add dx, 0x12c0
// 00534673  8d0440               lea eax, [eax + eax*2]
// 00534676  0fb7ca               movzx ecx, dx
// 00534679  8d5487fd             lea edx, [edi + eax*4 - 3]
// 0053467d  0fb7d2               movzx edx, dx
// 00534680  69d299000000         imul edx, edx, 0x99
// 00534686  83c202               add edx, 2
// 00534689  b867666666           mov eax, 0x66666667
// 0053468e  f7ea                 imul edx
// 00534690  d1fa                 sar edx, 1
// 00534692  8bfa                 mov edi, edx
// 00534694  0fb7c9               movzx ecx, cx
// 00534697  c1ef1f               shr edi, 0x1f
// 0053469a  03fa                 add edi, edx
// 0053469c  b81f85eb51           mov eax, 0x51eb851f
// 005346a1  f7e9                 imul ecx
// 005346a3  c1fa07               sar edx, 7
// 005346a6  03fa                 add edi, edx
// 005346a8  8bda                 mov ebx, edx
// 005346aa  b81f85eb51           mov eax, 0x51eb851f
// 005346af  f7e9                 imul ecx
// 005346b1  c1fa05               sar edx, 5
// 005346b4  c1eb1f               shr ebx, 0x1f
// 005346b7  8bc2                 mov eax, edx
// 005346b9  c1e81f               shr eax, 0x1f
// 005346bc  03df                 add ebx, edi
// 005346be  03c2                 add eax, edx
// 005346c0  0fb75604             movzx edx, word ptr [esi + 4]
// 005346c4  2bd8                 sub ebx, eax
// 005346c6  8bc1                 mov eax, ecx
// 005346c8  69c06d010000         imul eax, eax, 0x16d
// 005346ce  03da                 add ebx, edx
// 005346d0  5f                   pop edi
// 005346d1  03d8                 add ebx, eax
// 005346d3  c1e902               shr ecx, 2
// 005346d6  5e                   pop esi
// 005346d7  8d840bd382ffff       lea eax, [ebx + ecx - 0x7d2d]
// 005346de  5b                   pop ebx
// 005346df  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?day_number@?$gregorian_calendar_base@U?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@date_time@boost@@K@date_time@boost@@SAKABU?$year_month_day_base@Vgreg_year@gregorian@boost@@Vgreg_month@23@Vgreg_day@23@@23@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
