// from server: 100% by auto
// roc 2012-06 0044e140  unit: COutputView  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044e140
//
// 0044e140  8b442408             mov eax, dword ptr [esp + 8]
// 0044e144  8b08                 mov ecx, dword ptr [eax]
// 0044e146  8b5004               mov edx, dword ptr [eax + 4]
// 0044e149  85c9                 test ecx, ecx
// 0044e14b  7508                 jne 0x44e155
// 0044e14d  81fa00000080         cmp edx, 0x80000000
// 0044e153  741a                 je 0x44e16f
// 0044e155  83f9ff               cmp ecx, -1
// 0044e158  7508                 jne 0x44e162
// 0044e15a  81faffffff7f         cmp edx, 0x7fffffff
// 0044e160  740d                 je 0x44e16f
// 0044e162  83f9fe               cmp ecx, -2
// 0044e165  7551                 jne 0x44e1b8
// 0044e167  81faffffff7f         cmp edx, 0x7fffffff
// 0044e16d  7549                 jne 0x44e1b8
// 0044e16f  8bc2                 mov eax, edx
// 0044e171  83f9fe               cmp ecx, -2
// 0044e174  750b                 jne 0x44e181
// 0044e176  3dffffff7f           cmp eax, 0x7fffffff
// 0044e17b  7504                 jne 0x44e181
// 0044e17d  33c0                 xor eax, eax
// 0044e17f  eb24                 jmp 0x44e1a5
// 0044e181  85c9                 test ecx, ecx
// 0044e183  750c                 jne 0x44e191
// 0044e185  3d00000080           cmp eax, 0x80000000
// 0044e18a  7505                 jne 0x44e191
// 0044e18c  8d4101               lea eax, [ecx + 1]
// 0044e18f  eb14                 jmp 0x44e1a5
// 0044e191  83f9ff               cmp ecx, -1
// 0044e194  750a                 jne 0x44e1a0
// 0044e196  3dffffff7f           cmp eax, 0x7fffffff
// 0044e19b  8d4103               lea eax, [ecx + 3]
// 0044e19e  7405                 je 0x44e1a5
// 0044e1a0  b805000000           mov eax, 5
// 0044e1a5  56                   push esi
// 0044e1a6  8b742408             mov esi, dword ptr [esp + 8]
// 0044e1aa  50                   push eax
// 0044e1ab  56                   push esi
// 0044e1ac  e85fe2fbff           call 0x40c410
// 0044e1b1  83c408               add esp, 8
// 0044e1b4  8bc6                 mov eax, esi
// 0044e1b6  5e                   pop esi
// 0044e1b7  c3                   ret 
// 0044e1b8  6a14                 push 0x14
// 0044e1ba  680060d71d           push 0x1dd76000
// 0044e1bf  8bc2                 mov eax, edx
// 0044e1c1  50                   push eax
// 0044e1c2  51                   push ecx
// 0044e1c3  e8a8545300           call 0x983670
// 0044e1c8  85d2                 test edx, edx
// 0044e1ca  7c06                 jl 0x44e1d2
// 0044e1cc  7f12                 jg 0x44e1e0
// 0044e1ce  85c0                 test eax, eax
// 0044e1d0  730e                 jae 0x44e1e0
// 0044e1d2  f7d8                 neg eax
// 0044e1d4  83d200               adc edx, 0
// 0044e1d7  f7da                 neg edx
// 0044e1d9  f7d8                 neg eax
// 0044e1db  83d200               adc edx, 0
// 0044e1de  f7da                 neg edx
// 0044e1e0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0044e1e4  8901                 mov dword ptr [ecx], eax
// 0044e1e6  895104               mov dword ptr [ecx + 4], edx
// 0044e1e9  8bc1                 mov eax, ecx
// 0044e1eb  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?get_time_of_day@?$counted_time_system@U?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@@date_time@boost@@SA?AVtime_duration@posix_time@3@ABU?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@23@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
