// from server: 100% by auto
// roc 2010-06 00411280  unit: CChildFrame  size: 240 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00411280
//
// 00411280  8b442404             mov eax, dword ptr [esp + 4]
// 00411284  53                   push ebx
// 00411285  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00411289  55                   push ebp
// 0041128a  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0041128e  56                   push esi
// 0041128f  8b742420             mov esi, dword ptr [esp + 0x20]
// 00411293  57                   push edi
// 00411294  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00411298  85c0                 test eax, eax
// 0041129a  7c5e                 jl 0x4112fa
// 0041129c  85ed                 test ebp, ebp
// 0041129e  7c60                 jl 0x411300
// 004112a0  85db                 test ebx, ebx
// 004112a2  7c58                 jl 0x4112fc
// 004112a4  85f6                 test esi, esi
// 004112a6  7c54                 jl 0x4112fc
// 004112a8  7f04                 jg 0x4112ae
// 004112aa  85ff                 test edi, edi
// 004112ac  724e                 jb 0x4112fc
// 004112ae  6a00                 push 0
// 004112b0  99                   cdq 
// 004112b1  6a3c                 push 0x3c
// 004112b3  52                   push edx
// 004112b4  50                   push eax
// 004112b5  e8f6783900           call 0x7a8bb0
// 004112ba  8bc8                 mov ecx, eax
// 004112bc  8bc2                 mov eax, edx
// 004112be  89442414             mov dword ptr [esp + 0x14], eax
// 004112c2  8bc5                 mov eax, ebp
// 004112c4  99                   cdq 
// 004112c5  03c8                 add ecx, eax
// 004112c7  8b442414             mov eax, dword ptr [esp + 0x14]
// 004112cb  6a00                 push 0
// 004112cd  6a3c                 push 0x3c
// 004112cf  13c2                 adc eax, edx
// 004112d1  50                   push eax
// 004112d2  51                   push ecx
// 004112d3  e8d8783900           call 0x7a8bb0
// 004112d8  8bc8                 mov ecx, eax
// 004112da  8bea                 mov ebp, edx
// 004112dc  8bc3                 mov eax, ebx
// 004112de  99                   cdq 
// 004112df  6a00                 push 0
// 004112e1  03c8                 add ecx, eax
// 004112e3  6840420f00           push 0xf4240
// 004112e8  13ea                 adc ebp, edx
// 004112ea  55                   push ebp
// 004112eb  51                   push ecx
// 004112ec  e8bf783900           call 0x7a8bb0
// 004112f1  03c7                 add eax, edi
// 004112f3  5f                   pop edi
// 004112f4  13d6                 adc edx, esi
// 004112f6  5e                   pop esi
// 004112f7  5d                   pop ebp
// 004112f8  5b                   pop ebx
// 004112f9  c3                   ret 
// 004112fa  f7d8                 neg eax
// 004112fc  85ed                 test ebp, ebp
// 004112fe  7d02                 jge 0x411302
// 00411300  f7dd                 neg ebp
// 00411302  85db                 test ebx, ebx
// 00411304  7d02                 jge 0x411308
// 00411306  f7db                 neg ebx
// 00411308  85f6                 test esi, esi
// 0041130a  7f0d                 jg 0x411319
// 0041130c  7c04                 jl 0x411312
// 0041130e  85ff                 test edi, edi
// 00411310  7307                 jae 0x411319
// 00411312  f7df                 neg edi
// 00411314  83d600               adc esi, 0
// 00411317  f7de                 neg esi
// 00411319  6a00                 push 0
// 0041131b  99                   cdq 
// 0041131c  6a3c                 push 0x3c
// 0041131e  52                   push edx
// 0041131f  50                   push eax
// 00411320  e88b783900           call 0x7a8bb0
// 00411325  8bc8                 mov ecx, eax
// 00411327  8bc2                 mov eax, edx
// 00411329  89442414             mov dword ptr [esp + 0x14], eax
// 0041132d  8bc5                 mov eax, ebp
// 0041132f  99                   cdq 
// 00411330  03c8                 add ecx, eax
// 00411332  8b442414             mov eax, dword ptr [esp + 0x14]
// 00411336  6a00                 push 0
// 00411338  6a3c                 push 0x3c
// 0041133a  13c2                 adc eax, edx
// 0041133c  50                   push eax
// 0041133d  51                   push ecx
// 0041133e  e86d783900           call 0x7a8bb0
// 00411343  8bc8                 mov ecx, eax
// 00411345  8bea                 mov ebp, edx
// 00411347  8bc3                 mov eax, ebx
// 00411349  99                   cdq 
// 0041134a  6a00                 push 0
// 0041134c  03c8                 add ecx, eax
// 0041134e  6840420f00           push 0xf4240
// 00411353  13ea                 adc ebp, edx
// 00411355  55                   push ebp
// 00411356  51                   push ecx
// 00411357  e854783900           call 0x7a8bb0
// 0041135c  f7df                 neg edi
// 0041135e  83d600               adc esi, 0
// 00411361  f7de                 neg esi
// 00411363  2bf8                 sub edi, eax
// 00411365  1bf2                 sbb esi, edx
// 00411367  8bc7                 mov eax, edi
// 00411369  5f                   pop edi
// 0041136a  8bd6                 mov edx, esi
// 0041136c  5e                   pop esi
// 0041136d  5d                   pop ebp
// 0041136e  5b                   pop ebx
// 0041136f  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?to_tick_count@?$time_resolution_traits@Utime_resolution_traits_adapted64_impl@date_time@boost@@$04$0PECEA@$05J@date_time@boost@@SA_JJJJ_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
