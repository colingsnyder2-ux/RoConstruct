// from server: 100% by auto
// roc 2011-06 0040ad40  unit: RBX::Instance::ICombinedSignalData  size: 240 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0040ad40
//
// 0040ad40  8b442404             mov eax, dword ptr [esp + 4]
// 0040ad44  53                   push ebx
// 0040ad45  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0040ad49  55                   push ebp
// 0040ad4a  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0040ad4e  56                   push esi
// 0040ad4f  8b742420             mov esi, dword ptr [esp + 0x20]
// 0040ad53  57                   push edi
// 0040ad54  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0040ad58  85c0                 test eax, eax
// 0040ad5a  7c5e                 jl 0x40adba
// 0040ad5c  85ed                 test ebp, ebp
// 0040ad5e  7c60                 jl 0x40adc0
// 0040ad60  85db                 test ebx, ebx
// 0040ad62  7c58                 jl 0x40adbc
// 0040ad64  85f6                 test esi, esi
// 0040ad66  7c54                 jl 0x40adbc
// 0040ad68  7f04                 jg 0x40ad6e
// 0040ad6a  85ff                 test edi, edi
// 0040ad6c  724e                 jb 0x40adbc
// 0040ad6e  6a00                 push 0
// 0040ad70  99                   cdq 
// 0040ad71  6a3c                 push 0x3c
// 0040ad73  52                   push edx
// 0040ad74  50                   push eax
// 0040ad75  e836054000           call 0x80b2b0
// 0040ad7a  8bc8                 mov ecx, eax
// 0040ad7c  8bc2                 mov eax, edx
// 0040ad7e  89442414             mov dword ptr [esp + 0x14], eax
// 0040ad82  8bc5                 mov eax, ebp
// 0040ad84  99                   cdq 
// 0040ad85  03c8                 add ecx, eax
// 0040ad87  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040ad8b  6a00                 push 0
// 0040ad8d  6a3c                 push 0x3c
// 0040ad8f  13c2                 adc eax, edx
// 0040ad91  50                   push eax
// 0040ad92  51                   push ecx
// 0040ad93  e818054000           call 0x80b2b0
// 0040ad98  8bc8                 mov ecx, eax
// 0040ad9a  8bea                 mov ebp, edx
// 0040ad9c  8bc3                 mov eax, ebx
// 0040ad9e  99                   cdq 
// 0040ad9f  6a00                 push 0
// 0040ada1  03c8                 add ecx, eax
// 0040ada3  6840420f00           push 0xf4240
// 0040ada8  13ea                 adc ebp, edx
// 0040adaa  55                   push ebp
// 0040adab  51                   push ecx
// 0040adac  e8ff044000           call 0x80b2b0
// 0040adb1  03c7                 add eax, edi
// 0040adb3  5f                   pop edi
// 0040adb4  13d6                 adc edx, esi
// 0040adb6  5e                   pop esi
// 0040adb7  5d                   pop ebp
// 0040adb8  5b                   pop ebx
// 0040adb9  c3                   ret 
// 0040adba  f7d8                 neg eax
// 0040adbc  85ed                 test ebp, ebp
// 0040adbe  7d02                 jge 0x40adc2
// 0040adc0  f7dd                 neg ebp
// 0040adc2  85db                 test ebx, ebx
// 0040adc4  7d02                 jge 0x40adc8
// 0040adc6  f7db                 neg ebx
// 0040adc8  85f6                 test esi, esi
// 0040adca  7f0d                 jg 0x40add9
// 0040adcc  7c04                 jl 0x40add2
// 0040adce  85ff                 test edi, edi
// 0040add0  7307                 jae 0x40add9
// 0040add2  f7df                 neg edi
// 0040add4  83d600               adc esi, 0
// 0040add7  f7de                 neg esi
// 0040add9  6a00                 push 0
// 0040addb  99                   cdq 
// 0040addc  6a3c                 push 0x3c
// 0040adde  52                   push edx
// 0040addf  50                   push eax
// 0040ade0  e8cb044000           call 0x80b2b0
// 0040ade5  8bc8                 mov ecx, eax
// 0040ade7  8bc2                 mov eax, edx
// 0040ade9  89442414             mov dword ptr [esp + 0x14], eax
// 0040aded  8bc5                 mov eax, ebp
// 0040adef  99                   cdq 
// 0040adf0  03c8                 add ecx, eax
// 0040adf2  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040adf6  6a00                 push 0
// 0040adf8  6a3c                 push 0x3c
// 0040adfa  13c2                 adc eax, edx
// 0040adfc  50                   push eax
// 0040adfd  51                   push ecx
// 0040adfe  e8ad044000           call 0x80b2b0
// 0040ae03  8bc8                 mov ecx, eax
// 0040ae05  8bea                 mov ebp, edx
// 0040ae07  8bc3                 mov eax, ebx
// 0040ae09  99                   cdq 
// 0040ae0a  6a00                 push 0
// 0040ae0c  03c8                 add ecx, eax
// 0040ae0e  6840420f00           push 0xf4240
// 0040ae13  13ea                 adc ebp, edx
// 0040ae15  55                   push ebp
// 0040ae16  51                   push ecx
// 0040ae17  e894044000           call 0x80b2b0
// 0040ae1c  f7df                 neg edi
// 0040ae1e  83d600               adc esi, 0
// 0040ae21  f7de                 neg esi
// 0040ae23  2bf8                 sub edi, eax
// 0040ae25  1bf2                 sbb esi, edx
// 0040ae27  8bc7                 mov eax, edi
// 0040ae29  5f                   pop edi
// 0040ae2a  8bd6                 mov edx, esi
// 0040ae2c  5e                   pop esi
// 0040ae2d  5d                   pop ebp
// 0040ae2e  5b                   pop ebx
// 0040ae2f  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?to_tick_count@?$time_resolution_traits@Utime_resolution_traits_adapted64_impl@date_time@boost@@$04$0PECEA@$05J@date_time@boost@@SA_JJJJ_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
