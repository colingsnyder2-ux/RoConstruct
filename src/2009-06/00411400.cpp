// from server: 100% by auto
// roc 2009-06 00411400  unit: CChildFrame  size: 240 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00411400
//
// 00411400  8b442404             mov eax, dword ptr [esp + 4]
// 00411404  53                   push ebx
// 00411405  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00411409  55                   push ebp
// 0041140a  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0041140e  56                   push esi
// 0041140f  8b742420             mov esi, dword ptr [esp + 0x20]
// 00411413  57                   push edi
// 00411414  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00411418  85c0                 test eax, eax
// 0041141a  7c5e                 jl 0x41147a
// 0041141c  85ed                 test ebp, ebp
// 0041141e  7c60                 jl 0x411480
// 00411420  85db                 test ebx, ebx
// 00411422  7c58                 jl 0x41147c
// 00411424  85f6                 test esi, esi
// 00411426  7c54                 jl 0x41147c
// 00411428  7f04                 jg 0x41142e
// 0041142a  85ff                 test edi, edi
// 0041142c  724e                 jb 0x41147c
// 0041142e  6a00                 push 0
// 00411430  99                   cdq 
// 00411431  6a3c                 push 0x3c
// 00411433  52                   push edx
// 00411434  50                   push eax
// 00411435  e806883000           call 0x719c40
// 0041143a  8bc8                 mov ecx, eax
// 0041143c  8bc2                 mov eax, edx
// 0041143e  89442414             mov dword ptr [esp + 0x14], eax
// 00411442  8bc5                 mov eax, ebp
// 00411444  99                   cdq 
// 00411445  03c8                 add ecx, eax
// 00411447  8b442414             mov eax, dword ptr [esp + 0x14]
// 0041144b  6a00                 push 0
// 0041144d  6a3c                 push 0x3c
// 0041144f  13c2                 adc eax, edx
// 00411451  50                   push eax
// 00411452  51                   push ecx
// 00411453  e8e8873000           call 0x719c40
// 00411458  8bc8                 mov ecx, eax
// 0041145a  8bea                 mov ebp, edx
// 0041145c  8bc3                 mov eax, ebx
// 0041145e  99                   cdq 
// 0041145f  6a00                 push 0
// 00411461  03c8                 add ecx, eax
// 00411463  6840420f00           push 0xf4240
// 00411468  13ea                 adc ebp, edx
// 0041146a  55                   push ebp
// 0041146b  51                   push ecx
// 0041146c  e8cf873000           call 0x719c40
// 00411471  03c7                 add eax, edi
// 00411473  5f                   pop edi
// 00411474  13d6                 adc edx, esi
// 00411476  5e                   pop esi
// 00411477  5d                   pop ebp
// 00411478  5b                   pop ebx
// 00411479  c3                   ret 
// 0041147a  f7d8                 neg eax
// 0041147c  85ed                 test ebp, ebp
// 0041147e  7d02                 jge 0x411482
// 00411480  f7dd                 neg ebp
// 00411482  85db                 test ebx, ebx
// 00411484  7d02                 jge 0x411488
// 00411486  f7db                 neg ebx
// 00411488  85f6                 test esi, esi
// 0041148a  7f0d                 jg 0x411499
// 0041148c  7c04                 jl 0x411492
// 0041148e  85ff                 test edi, edi
// 00411490  7307                 jae 0x411499
// 00411492  f7df                 neg edi
// 00411494  83d600               adc esi, 0
// 00411497  f7de                 neg esi
// 00411499  6a00                 push 0
// 0041149b  99                   cdq 
// 0041149c  6a3c                 push 0x3c
// 0041149e  52                   push edx
// 0041149f  50                   push eax
// 004114a0  e89b873000           call 0x719c40
// 004114a5  8bc8                 mov ecx, eax
// 004114a7  8bc2                 mov eax, edx
// 004114a9  89442414             mov dword ptr [esp + 0x14], eax
// 004114ad  8bc5                 mov eax, ebp
// 004114af  99                   cdq 
// 004114b0  03c8                 add ecx, eax
// 004114b2  8b442414             mov eax, dword ptr [esp + 0x14]
// 004114b6  6a00                 push 0
// 004114b8  6a3c                 push 0x3c
// 004114ba  13c2                 adc eax, edx
// 004114bc  50                   push eax
// 004114bd  51                   push ecx
// 004114be  e87d873000           call 0x719c40
// 004114c3  8bc8                 mov ecx, eax
// 004114c5  8bea                 mov ebp, edx
// 004114c7  8bc3                 mov eax, ebx
// 004114c9  99                   cdq 
// 004114ca  6a00                 push 0
// 004114cc  03c8                 add ecx, eax
// 004114ce  6840420f00           push 0xf4240
// 004114d3  13ea                 adc ebp, edx
// 004114d5  55                   push ebp
// 004114d6  51                   push ecx
// 004114d7  e864873000           call 0x719c40
// 004114dc  f7df                 neg edi
// 004114de  83d600               adc esi, 0
// 004114e1  f7de                 neg esi
// 004114e3  2bf8                 sub edi, eax
// 004114e5  1bf2                 sbb esi, edx
// 004114e7  8bc7                 mov eax, edi
// 004114e9  5f                   pop edi
// 004114ea  8bd6                 mov edx, esi
// 004114ec  5e                   pop esi
// 004114ed  5d                   pop ebp
// 004114ee  5b                   pop ebx
// 004114ef  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?to_tick_count@?$time_resolution_traits@Utime_resolution_traits_adapted64_impl@date_time@boost@@$04$0PECEA@$05J@date_time@boost@@SA_JJJJ_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
