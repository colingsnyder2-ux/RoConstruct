// from server: 100% by auto
// roc 2012-06 0040c490  unit: RBX::Instance::ICombinedSignalData  size: 240 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040c490
//
// 0040c490  8b442404             mov eax, dword ptr [esp + 4]
// 0040c494  53                   push ebx
// 0040c495  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0040c499  55                   push ebp
// 0040c49a  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0040c49e  56                   push esi
// 0040c49f  8b742420             mov esi, dword ptr [esp + 0x20]
// 0040c4a3  57                   push edi
// 0040c4a4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0040c4a8  85c0                 test eax, eax
// 0040c4aa  7c5e                 jl 0x40c50a
// 0040c4ac  85ed                 test ebp, ebp
// 0040c4ae  7c60                 jl 0x40c510
// 0040c4b0  85db                 test ebx, ebx
// 0040c4b2  7c58                 jl 0x40c50c
// 0040c4b4  85f6                 test esi, esi
// 0040c4b6  7c54                 jl 0x40c50c
// 0040c4b8  7f04                 jg 0x40c4be
// 0040c4ba  85ff                 test edi, edi
// 0040c4bc  724e                 jb 0x40c50c
// 0040c4be  6a00                 push 0
// 0040c4c0  99                   cdq 
// 0040c4c1  6a3c                 push 0x3c
// 0040c4c3  52                   push edx
// 0040c4c4  50                   push eax
// 0040c4c5  e8766e5700           call 0x983340
// 0040c4ca  8bc8                 mov ecx, eax
// 0040c4cc  8bc2                 mov eax, edx
// 0040c4ce  89442414             mov dword ptr [esp + 0x14], eax
// 0040c4d2  8bc5                 mov eax, ebp
// 0040c4d4  99                   cdq 
// 0040c4d5  03c8                 add ecx, eax
// 0040c4d7  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040c4db  6a00                 push 0
// 0040c4dd  6a3c                 push 0x3c
// 0040c4df  13c2                 adc eax, edx
// 0040c4e1  50                   push eax
// 0040c4e2  51                   push ecx
// 0040c4e3  e8586e5700           call 0x983340
// 0040c4e8  8bc8                 mov ecx, eax
// 0040c4ea  8bea                 mov ebp, edx
// 0040c4ec  8bc3                 mov eax, ebx
// 0040c4ee  99                   cdq 
// 0040c4ef  6a00                 push 0
// 0040c4f1  03c8                 add ecx, eax
// 0040c4f3  6840420f00           push 0xf4240
// 0040c4f8  13ea                 adc ebp, edx
// 0040c4fa  55                   push ebp
// 0040c4fb  51                   push ecx
// 0040c4fc  e83f6e5700           call 0x983340
// 0040c501  03c7                 add eax, edi
// 0040c503  5f                   pop edi
// 0040c504  13d6                 adc edx, esi
// 0040c506  5e                   pop esi
// 0040c507  5d                   pop ebp
// 0040c508  5b                   pop ebx
// 0040c509  c3                   ret 
// 0040c50a  f7d8                 neg eax
// 0040c50c  85ed                 test ebp, ebp
// 0040c50e  7d02                 jge 0x40c512
// 0040c510  f7dd                 neg ebp
// 0040c512  85db                 test ebx, ebx
// 0040c514  7d02                 jge 0x40c518
// 0040c516  f7db                 neg ebx
// 0040c518  85f6                 test esi, esi
// 0040c51a  7f0d                 jg 0x40c529
// 0040c51c  7c04                 jl 0x40c522
// 0040c51e  85ff                 test edi, edi
// 0040c520  7307                 jae 0x40c529
// 0040c522  f7df                 neg edi
// 0040c524  83d600               adc esi, 0
// 0040c527  f7de                 neg esi
// 0040c529  6a00                 push 0
// 0040c52b  99                   cdq 
// 0040c52c  6a3c                 push 0x3c
// 0040c52e  52                   push edx
// 0040c52f  50                   push eax
// 0040c530  e80b6e5700           call 0x983340
// 0040c535  8bc8                 mov ecx, eax
// 0040c537  8bc2                 mov eax, edx
// 0040c539  89442414             mov dword ptr [esp + 0x14], eax
// 0040c53d  8bc5                 mov eax, ebp
// 0040c53f  99                   cdq 
// 0040c540  03c8                 add ecx, eax
// 0040c542  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040c546  6a00                 push 0
// 0040c548  6a3c                 push 0x3c
// 0040c54a  13c2                 adc eax, edx
// 0040c54c  50                   push eax
// 0040c54d  51                   push ecx
// 0040c54e  e8ed6d5700           call 0x983340
// 0040c553  8bc8                 mov ecx, eax
// 0040c555  8bea                 mov ebp, edx
// 0040c557  8bc3                 mov eax, ebx
// 0040c559  99                   cdq 
// 0040c55a  6a00                 push 0
// 0040c55c  03c8                 add ecx, eax
// 0040c55e  6840420f00           push 0xf4240
// 0040c563  13ea                 adc ebp, edx
// 0040c565  55                   push ebp
// 0040c566  51                   push ecx
// 0040c567  e8d46d5700           call 0x983340
// 0040c56c  f7df                 neg edi
// 0040c56e  83d600               adc esi, 0
// 0040c571  f7de                 neg esi
// 0040c573  2bf8                 sub edi, eax
// 0040c575  1bf2                 sbb esi, edx
// 0040c577  8bc7                 mov eax, edi
// 0040c579  5f                   pop edi
// 0040c57a  8bd6                 mov edx, esi
// 0040c57c  5e                   pop esi
// 0040c57d  5d                   pop ebp
// 0040c57e  5b                   pop ebx
// 0040c57f  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?to_tick_count@?$time_resolution_traits@Utime_resolution_traits_adapted64_impl@date_time@boost@@$04$0PECEA@$05J@date_time@boost@@SA_JJJJ_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
