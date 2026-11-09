// from server: 100% by auto
// roc 2011-06 007f8220  unit: RBX::CircleRadialNormal  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007f8220
//
// 007f8220  8b442408             mov eax, dword ptr [esp + 8]
// 007f8224  8b08                 mov ecx, dword ptr [eax]
// 007f8226  8b5004               mov edx, dword ptr [eax + 4]
// 007f8229  85c9                 test ecx, ecx
// 007f822b  7508                 jne 0x7f8235
// 007f822d  81fa00000080         cmp edx, 0x80000000
// 007f8233  741a                 je 0x7f824f
// 007f8235  83f9ff               cmp ecx, -1
// 007f8238  7508                 jne 0x7f8242
// 007f823a  81faffffff7f         cmp edx, 0x7fffffff
// 007f8240  740d                 je 0x7f824f
// 007f8242  83f9fe               cmp ecx, -2
// 007f8245  7551                 jne 0x7f8298
// 007f8247  81faffffff7f         cmp edx, 0x7fffffff
// 007f824d  7549                 jne 0x7f8298
// 007f824f  8bc2                 mov eax, edx
// 007f8251  83f9fe               cmp ecx, -2
// 007f8254  750b                 jne 0x7f8261
// 007f8256  3dffffff7f           cmp eax, 0x7fffffff
// 007f825b  7504                 jne 0x7f8261
// 007f825d  33c0                 xor eax, eax
// 007f825f  eb24                 jmp 0x7f8285
// 007f8261  85c9                 test ecx, ecx
// 007f8263  750c                 jne 0x7f8271
// 007f8265  3d00000080           cmp eax, 0x80000000
// 007f826a  7505                 jne 0x7f8271
// 007f826c  8d4101               lea eax, [ecx + 1]
// 007f826f  eb14                 jmp 0x7f8285
// 007f8271  83f9ff               cmp ecx, -1
// 007f8274  750a                 jne 0x7f8280
// 007f8276  3dffffff7f           cmp eax, 0x7fffffff
// 007f827b  8d4103               lea eax, [ecx + 3]
// 007f827e  7405                 je 0x7f8285
// 007f8280  b805000000           mov eax, 5
// 007f8285  56                   push esi
// 007f8286  8b742408             mov esi, dword ptr [esp + 8]
// 007f828a  50                   push eax
// 007f828b  56                   push esi
// 007f828c  e82f2ac1ff           call 0x40acc0
// 007f8291  83c408               add esp, 8
// 007f8294  8bc6                 mov eax, esi
// 007f8296  5e                   pop esi
// 007f8297  c3                   ret 
// 007f8298  6a14                 push 0x14
// 007f829a  680060d71d           push 0x1dd76000
// 007f829f  8bc2                 mov eax, edx
// 007f82a1  50                   push eax
// 007f82a2  51                   push ecx
// 007f82a3  e838380100           call 0x80bae0
// 007f82a8  85d2                 test edx, edx
// 007f82aa  7c06                 jl 0x7f82b2
// 007f82ac  7f12                 jg 0x7f82c0
// 007f82ae  85c0                 test eax, eax
// 007f82b0  730e                 jae 0x7f82c0
// 007f82b2  f7d8                 neg eax
// 007f82b4  83d200               adc edx, 0
// 007f82b7  f7da                 neg edx
// 007f82b9  f7d8                 neg eax
// 007f82bb  83d200               adc edx, 0
// 007f82be  f7da                 neg edx
// 007f82c0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007f82c4  8901                 mov dword ptr [ecx], eax
// 007f82c6  895104               mov dword ptr [ecx + 4], edx
// 007f82c9  8bc1                 mov eax, ecx
// 007f82cb  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?get_time_of_day@?$counted_time_system@U?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@@date_time@boost@@SA?AVtime_duration@posix_time@3@ABU?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@23@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
