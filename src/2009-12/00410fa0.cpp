// from server: 100% by auto
// roc 2009-12 00410fa0  unit: CChildFrame  size: 240 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00410fa0
//
// 00410fa0  8b442404             mov eax, dword ptr [esp + 4]
// 00410fa4  53                   push ebx
// 00410fa5  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00410fa9  55                   push ebp
// 00410faa  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00410fae  56                   push esi
// 00410faf  8b742420             mov esi, dword ptr [esp + 0x20]
// 00410fb3  57                   push edi
// 00410fb4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00410fb8  85c0                 test eax, eax
// 00410fba  7c5e                 jl 0x41101a
// 00410fbc  85ed                 test ebp, ebp
// 00410fbe  7c60                 jl 0x411020
// 00410fc0  85db                 test ebx, ebx
// 00410fc2  7c58                 jl 0x41101c
// 00410fc4  85f6                 test esi, esi
// 00410fc6  7c54                 jl 0x41101c
// 00410fc8  7f04                 jg 0x410fce
// 00410fca  85ff                 test edi, edi
// 00410fcc  724e                 jb 0x41101c
// 00410fce  6a00                 push 0
// 00410fd0  99                   cdq 
// 00410fd1  6a3c                 push 0x3c
// 00410fd3  52                   push edx
// 00410fd4  50                   push eax
// 00410fd5  e8963a3e00           call 0x7f4a70
// 00410fda  8bc8                 mov ecx, eax
// 00410fdc  8bc2                 mov eax, edx
// 00410fde  89442414             mov dword ptr [esp + 0x14], eax
// 00410fe2  8bc5                 mov eax, ebp
// 00410fe4  99                   cdq 
// 00410fe5  03c8                 add ecx, eax
// 00410fe7  8b442414             mov eax, dword ptr [esp + 0x14]
// 00410feb  6a00                 push 0
// 00410fed  6a3c                 push 0x3c
// 00410fef  13c2                 adc eax, edx
// 00410ff1  50                   push eax
// 00410ff2  51                   push ecx
// 00410ff3  e8783a3e00           call 0x7f4a70
// 00410ff8  8bc8                 mov ecx, eax
// 00410ffa  8bea                 mov ebp, edx
// 00410ffc  8bc3                 mov eax, ebx
// 00410ffe  99                   cdq 
// 00410fff  6a00                 push 0
// 00411001  03c8                 add ecx, eax
// 00411003  6840420f00           push 0xf4240
// 00411008  13ea                 adc ebp, edx
// 0041100a  55                   push ebp
// 0041100b  51                   push ecx
// 0041100c  e85f3a3e00           call 0x7f4a70
// 00411011  03c7                 add eax, edi
// 00411013  5f                   pop edi
// 00411014  13d6                 adc edx, esi
// 00411016  5e                   pop esi
// 00411017  5d                   pop ebp
// 00411018  5b                   pop ebx
// 00411019  c3                   ret 
// 0041101a  f7d8                 neg eax
// 0041101c  85ed                 test ebp, ebp
// 0041101e  7d02                 jge 0x411022
// 00411020  f7dd                 neg ebp
// 00411022  85db                 test ebx, ebx
// 00411024  7d02                 jge 0x411028
// 00411026  f7db                 neg ebx
// 00411028  85f6                 test esi, esi
// 0041102a  7f0d                 jg 0x411039
// 0041102c  7c04                 jl 0x411032
// 0041102e  85ff                 test edi, edi
// 00411030  7307                 jae 0x411039
// 00411032  f7df                 neg edi
// 00411034  83d600               adc esi, 0
// 00411037  f7de                 neg esi
// 00411039  6a00                 push 0
// 0041103b  99                   cdq 
// 0041103c  6a3c                 push 0x3c
// 0041103e  52                   push edx
// 0041103f  50                   push eax
// 00411040  e82b3a3e00           call 0x7f4a70
// 00411045  8bc8                 mov ecx, eax
// 00411047  8bc2                 mov eax, edx
// 00411049  89442414             mov dword ptr [esp + 0x14], eax
// 0041104d  8bc5                 mov eax, ebp
// 0041104f  99                   cdq 
// 00411050  03c8                 add ecx, eax
// 00411052  8b442414             mov eax, dword ptr [esp + 0x14]
// 00411056  6a00                 push 0
// 00411058  6a3c                 push 0x3c
// 0041105a  13c2                 adc eax, edx
// 0041105c  50                   push eax
// 0041105d  51                   push ecx
// 0041105e  e80d3a3e00           call 0x7f4a70
// 00411063  8bc8                 mov ecx, eax
// 00411065  8bea                 mov ebp, edx
// 00411067  8bc3                 mov eax, ebx
// 00411069  99                   cdq 
// 0041106a  6a00                 push 0
// 0041106c  03c8                 add ecx, eax
// 0041106e  6840420f00           push 0xf4240
// 00411073  13ea                 adc ebp, edx
// 00411075  55                   push ebp
// 00411076  51                   push ecx
// 00411077  e8f4393e00           call 0x7f4a70
// 0041107c  f7df                 neg edi
// 0041107e  83d600               adc esi, 0
// 00411081  f7de                 neg esi
// 00411083  2bf8                 sub edi, eax
// 00411085  1bf2                 sbb esi, edx
// 00411087  8bc7                 mov eax, edi
// 00411089  5f                   pop edi
// 0041108a  8bd6                 mov edx, esi
// 0041108c  5e                   pop esi
// 0041108d  5d                   pop ebp
// 0041108e  5b                   pop ebx
// 0041108f  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?to_tick_count@?$time_resolution_traits@Utime_resolution_traits_adapted64_impl@date_time@boost@@$04$0PECEA@$05J@date_time@boost@@SA_JJJJ_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
