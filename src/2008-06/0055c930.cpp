// from server: 100% by auto
// roc 2008-06 0055c930  unit: RBX::MD5HasherImpl  size: 240 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055c930
//
// 0055c930  8b442404             mov eax, dword ptr [esp + 4]
// 0055c934  53                   push ebx
// 0055c935  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0055c939  55                   push ebp
// 0055c93a  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0055c93e  56                   push esi
// 0055c93f  8b742420             mov esi, dword ptr [esp + 0x20]
// 0055c943  57                   push edi
// 0055c944  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0055c948  85c0                 test eax, eax
// 0055c94a  7c5e                 jl 0x55c9aa
// 0055c94c  85ed                 test ebp, ebp
// 0055c94e  7c60                 jl 0x55c9b0
// 0055c950  85db                 test ebx, ebx
// 0055c952  7c58                 jl 0x55c9ac
// 0055c954  85f6                 test esi, esi
// 0055c956  7c54                 jl 0x55c9ac
// 0055c958  7f04                 jg 0x55c95e
// 0055c95a  85ff                 test edi, edi
// 0055c95c  724e                 jb 0x55c9ac
// 0055c95e  6a00                 push 0
// 0055c960  99                   cdq 
// 0055c961  6a3c                 push 0x3c
// 0055c963  52                   push edx
// 0055c964  50                   push eax
// 0055c965  e8664d1400           call 0x6a16d0
// 0055c96a  8bc8                 mov ecx, eax
// 0055c96c  8bc2                 mov eax, edx
// 0055c96e  89442414             mov dword ptr [esp + 0x14], eax
// 0055c972  8bc5                 mov eax, ebp
// 0055c974  99                   cdq 
// 0055c975  03c8                 add ecx, eax
// 0055c977  8b442414             mov eax, dword ptr [esp + 0x14]
// 0055c97b  6a00                 push 0
// 0055c97d  6a3c                 push 0x3c
// 0055c97f  13c2                 adc eax, edx
// 0055c981  50                   push eax
// 0055c982  51                   push ecx
// 0055c983  e8484d1400           call 0x6a16d0
// 0055c988  8bc8                 mov ecx, eax
// 0055c98a  8bea                 mov ebp, edx
// 0055c98c  8bc3                 mov eax, ebx
// 0055c98e  99                   cdq 
// 0055c98f  6a00                 push 0
// 0055c991  03c8                 add ecx, eax
// 0055c993  6840420f00           push 0xf4240
// 0055c998  13ea                 adc ebp, edx
// 0055c99a  55                   push ebp
// 0055c99b  51                   push ecx
// 0055c99c  e82f4d1400           call 0x6a16d0
// 0055c9a1  03c7                 add eax, edi
// 0055c9a3  5f                   pop edi
// 0055c9a4  13d6                 adc edx, esi
// 0055c9a6  5e                   pop esi
// 0055c9a7  5d                   pop ebp
// 0055c9a8  5b                   pop ebx
// 0055c9a9  c3                   ret 
// 0055c9aa  f7d8                 neg eax
// 0055c9ac  85ed                 test ebp, ebp
// 0055c9ae  7d02                 jge 0x55c9b2
// 0055c9b0  f7dd                 neg ebp
// 0055c9b2  85db                 test ebx, ebx
// 0055c9b4  7d02                 jge 0x55c9b8
// 0055c9b6  f7db                 neg ebx
// 0055c9b8  85f6                 test esi, esi
// 0055c9ba  7f0d                 jg 0x55c9c9
// 0055c9bc  7c04                 jl 0x55c9c2
// 0055c9be  85ff                 test edi, edi
// 0055c9c0  7307                 jae 0x55c9c9
// 0055c9c2  f7df                 neg edi
// 0055c9c4  83d600               adc esi, 0
// 0055c9c7  f7de                 neg esi
// 0055c9c9  6a00                 push 0
// 0055c9cb  99                   cdq 
// 0055c9cc  6a3c                 push 0x3c
// 0055c9ce  52                   push edx
// 0055c9cf  50                   push eax
// 0055c9d0  e8fb4c1400           call 0x6a16d0
// 0055c9d5  8bc8                 mov ecx, eax
// 0055c9d7  8bc2                 mov eax, edx
// 0055c9d9  89442414             mov dword ptr [esp + 0x14], eax
// 0055c9dd  8bc5                 mov eax, ebp
// 0055c9df  99                   cdq 
// 0055c9e0  03c8                 add ecx, eax
// 0055c9e2  8b442414             mov eax, dword ptr [esp + 0x14]
// 0055c9e6  6a00                 push 0
// 0055c9e8  6a3c                 push 0x3c
// 0055c9ea  13c2                 adc eax, edx
// 0055c9ec  50                   push eax
// 0055c9ed  51                   push ecx
// 0055c9ee  e8dd4c1400           call 0x6a16d0
// 0055c9f3  8bc8                 mov ecx, eax
// 0055c9f5  8bea                 mov ebp, edx
// 0055c9f7  8bc3                 mov eax, ebx
// 0055c9f9  99                   cdq 
// 0055c9fa  6a00                 push 0
// 0055c9fc  03c8                 add ecx, eax
// 0055c9fe  6840420f00           push 0xf4240
// 0055ca03  13ea                 adc ebp, edx
// 0055ca05  55                   push ebp
// 0055ca06  51                   push ecx
// 0055ca07  e8c44c1400           call 0x6a16d0
// 0055ca0c  f7df                 neg edi
// 0055ca0e  83d600               adc esi, 0
// 0055ca11  f7de                 neg esi
// 0055ca13  2bf8                 sub edi, eax
// 0055ca15  1bf2                 sbb esi, edx
// 0055ca17  8bc7                 mov eax, edi
// 0055ca19  5f                   pop edi
// 0055ca1a  8bd6                 mov edx, esi
// 0055ca1c  5e                   pop esi
// 0055ca1d  5d                   pop ebp
// 0055ca1e  5b                   pop ebx
// 0055ca1f  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?to_tick_count@?$time_resolution_traits@Utime_resolution_traits_adapted64_impl@date_time@boost@@$04$0PECEA@$05J@date_time@boost@@SA_JJJJ_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
