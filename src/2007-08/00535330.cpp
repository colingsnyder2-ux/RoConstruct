// from server: 100% by auto
// roc 2007-08 00535330  unit: std::logic_error  size: 240 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00535330
//
// 00535330  8b442404             mov eax, dword ptr [esp + 4]
// 00535334  85c0                 test eax, eax
// 00535336  53                   push ebx
// 00535337  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0053533b  55                   push ebp
// 0053533c  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00535340  56                   push esi
// 00535341  8b742420             mov esi, dword ptr [esp + 0x20]
// 00535345  57                   push edi
// 00535346  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053534a  7c5e                 jl 0x5353aa
// 0053534c  85ed                 test ebp, ebp
// 0053534e  7c60                 jl 0x5353b0
// 00535350  85db                 test ebx, ebx
// 00535352  7c58                 jl 0x5353ac
// 00535354  85f6                 test esi, esi
// 00535356  7c54                 jl 0x5353ac
// 00535358  7f04                 jg 0x53535e
// 0053535a  85ff                 test edi, edi
// 0053535c  724e                 jb 0x5353ac
// 0053535e  6a00                 push 0
// 00535360  99                   cdq 
// 00535361  6a3c                 push 0x3c
// 00535363  52                   push edx
// 00535364  50                   push eax
// 00535365  e8e6b80f00           call 0x630c50
// 0053536a  8bc8                 mov ecx, eax
// 0053536c  8bc2                 mov eax, edx
// 0053536e  89442414             mov dword ptr [esp + 0x14], eax
// 00535372  8bc5                 mov eax, ebp
// 00535374  99                   cdq 
// 00535375  03c8                 add ecx, eax
// 00535377  8b442414             mov eax, dword ptr [esp + 0x14]
// 0053537b  6a00                 push 0
// 0053537d  6a3c                 push 0x3c
// 0053537f  13c2                 adc eax, edx
// 00535381  50                   push eax
// 00535382  51                   push ecx
// 00535383  e8c8b80f00           call 0x630c50
// 00535388  8bc8                 mov ecx, eax
// 0053538a  8bea                 mov ebp, edx
// 0053538c  8bc3                 mov eax, ebx
// 0053538e  99                   cdq 
// 0053538f  6a00                 push 0
// 00535391  03c8                 add ecx, eax
// 00535393  6840420f00           push 0xf4240
// 00535398  13ea                 adc ebp, edx
// 0053539a  55                   push ebp
// 0053539b  51                   push ecx
// 0053539c  e8afb80f00           call 0x630c50
// 005353a1  03c7                 add eax, edi
// 005353a3  5f                   pop edi
// 005353a4  13d6                 adc edx, esi
// 005353a6  5e                   pop esi
// 005353a7  5d                   pop ebp
// 005353a8  5b                   pop ebx
// 005353a9  c3                   ret 
// 005353aa  f7d8                 neg eax
// 005353ac  85ed                 test ebp, ebp
// 005353ae  7d02                 jge 0x5353b2
// 005353b0  f7dd                 neg ebp
// 005353b2  85db                 test ebx, ebx
// 005353b4  7d02                 jge 0x5353b8
// 005353b6  f7db                 neg ebx
// 005353b8  85f6                 test esi, esi
// 005353ba  7f0d                 jg 0x5353c9
// 005353bc  7c04                 jl 0x5353c2
// 005353be  85ff                 test edi, edi
// 005353c0  7307                 jae 0x5353c9
// 005353c2  f7df                 neg edi
// 005353c4  83d600               adc esi, 0
// 005353c7  f7de                 neg esi
// 005353c9  6a00                 push 0
// 005353cb  99                   cdq 
// 005353cc  6a3c                 push 0x3c
// 005353ce  52                   push edx
// 005353cf  50                   push eax
// 005353d0  e87bb80f00           call 0x630c50
// 005353d5  8bc8                 mov ecx, eax
// 005353d7  8bc2                 mov eax, edx
// 005353d9  89442414             mov dword ptr [esp + 0x14], eax
// 005353dd  8bc5                 mov eax, ebp
// 005353df  99                   cdq 
// 005353e0  03c8                 add ecx, eax
// 005353e2  8b442414             mov eax, dword ptr [esp + 0x14]
// 005353e6  6a00                 push 0
// 005353e8  6a3c                 push 0x3c
// 005353ea  13c2                 adc eax, edx
// 005353ec  50                   push eax
// 005353ed  51                   push ecx
// 005353ee  e85db80f00           call 0x630c50
// 005353f3  8bc8                 mov ecx, eax
// 005353f5  8bea                 mov ebp, edx
// 005353f7  8bc3                 mov eax, ebx
// 005353f9  99                   cdq 
// 005353fa  6a00                 push 0
// 005353fc  03c8                 add ecx, eax
// 005353fe  6840420f00           push 0xf4240
// 00535403  13ea                 adc ebp, edx
// 00535405  55                   push ebp
// 00535406  51                   push ecx
// 00535407  e844b80f00           call 0x630c50
// 0053540c  f7df                 neg edi
// 0053540e  83d600               adc esi, 0
// 00535411  f7de                 neg esi
// 00535413  2bf8                 sub edi, eax
// 00535415  1bf2                 sbb esi, edx
// 00535417  8bc7                 mov eax, edi
// 00535419  5f                   pop edi
// 0053541a  8bd6                 mov edx, esi
// 0053541c  5e                   pop esi
// 0053541d  5d                   pop ebp
// 0053541e  5b                   pop ebx
// 0053541f  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?to_tick_count@?$time_resolution_traits@Utime_resolution_traits_adapted64_impl@date_time@boost@@$04$0PECEA@$05J@date_time@boost@@SA_JJJJ_J@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
