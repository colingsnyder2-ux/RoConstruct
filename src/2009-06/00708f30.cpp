// from server: 100% by auto
// roc 2009-06 00708f30  unit: boost::detail::thread_data_base  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00708f30
//
// 00708f30  8b442408             mov eax, dword ptr [esp + 8]
// 00708f34  8b08                 mov ecx, dword ptr [eax]
// 00708f36  8b5004               mov edx, dword ptr [eax + 4]
// 00708f39  85c9                 test ecx, ecx
// 00708f3b  7508                 jne 0x708f45
// 00708f3d  81fa00000080         cmp edx, 0x80000000
// 00708f43  741a                 je 0x708f5f
// 00708f45  83f9ff               cmp ecx, -1
// 00708f48  7508                 jne 0x708f52
// 00708f4a  81faffffff7f         cmp edx, 0x7fffffff
// 00708f50  740d                 je 0x708f5f
// 00708f52  83f9fe               cmp ecx, -2
// 00708f55  7551                 jne 0x708fa8
// 00708f57  81faffffff7f         cmp edx, 0x7fffffff
// 00708f5d  7549                 jne 0x708fa8
// 00708f5f  8bc2                 mov eax, edx
// 00708f61  83f9fe               cmp ecx, -2
// 00708f64  750b                 jne 0x708f71
// 00708f66  3dffffff7f           cmp eax, 0x7fffffff
// 00708f6b  7504                 jne 0x708f71
// 00708f6d  33c0                 xor eax, eax
// 00708f6f  eb24                 jmp 0x708f95
// 00708f71  85c9                 test ecx, ecx
// 00708f73  750c                 jne 0x708f81
// 00708f75  3d00000080           cmp eax, 0x80000000
// 00708f7a  7505                 jne 0x708f81
// 00708f7c  8d4101               lea eax, [ecx + 1]
// 00708f7f  eb14                 jmp 0x708f95
// 00708f81  83f9ff               cmp ecx, -1
// 00708f84  750a                 jne 0x708f90
// 00708f86  3dffffff7f           cmp eax, 0x7fffffff
// 00708f8b  8d4103               lea eax, [ecx + 3]
// 00708f8e  7405                 je 0x708f95
// 00708f90  b805000000           mov eax, 5
// 00708f95  56                   push esi
// 00708f96  8b742408             mov esi, dword ptr [esp + 8]
// 00708f9a  50                   push eax
// 00708f9b  56                   push esi
// 00708f9c  e8df83d0ff           call 0x411380
// 00708fa1  83c408               add esp, 8
// 00708fa4  8bc6                 mov eax, esi
// 00708fa6  5e                   pop esi
// 00708fa7  c3                   ret 
// 00708fa8  6a14                 push 0x14
// 00708faa  680060d71d           push 0x1dd76000
// 00708faf  8bc2                 mov eax, edx
// 00708fb1  50                   push eax
// 00708fb2  51                   push ecx
// 00708fb3  e8f8140100           call 0x71a4b0
// 00708fb8  85d2                 test edx, edx
// 00708fba  7c06                 jl 0x708fc2
// 00708fbc  7f12                 jg 0x708fd0
// 00708fbe  85c0                 test eax, eax
// 00708fc0  730e                 jae 0x708fd0
// 00708fc2  f7d8                 neg eax
// 00708fc4  83d200               adc edx, 0
// 00708fc7  f7da                 neg edx
// 00708fc9  f7d8                 neg eax
// 00708fcb  83d200               adc edx, 0
// 00708fce  f7da                 neg edx
// 00708fd0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00708fd4  8901                 mov dword ptr [ecx], eax
// 00708fd6  895104               mov dword ptr [ecx + 4], edx
// 00708fd9  8bc1                 mov eax, ecx
// 00708fdb  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?get_time_of_day@?$counted_time_system@U?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@@date_time@boost@@SA?AVtime_duration@posix_time@3@ABU?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@23@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
