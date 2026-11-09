// from server: 100% by auto
// roc 2010-06 00411ae0  unit: boost::gregorian::Ubad_month::?$error_info_injector  size: 313 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00411ae0
//
// 00411ae0  8b442408             mov eax, dword ptr [esp + 8]
// 00411ae4  8b08                 mov ecx, dword ptr [eax]
// 00411ae6  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00411aea  83ec18               sub esp, 0x18
// 00411aed  56                   push esi
// 00411aee  8b7004               mov esi, dword ptr [eax + 4]
// 00411af1  85c9                 test ecx, ecx
// 00411af3  7508                 jne 0x411afd
// 00411af5  81fe00000080         cmp esi, 0x80000000
// 00411afb  7479                 je 0x411b76
// 00411afd  83f9ff               cmp ecx, -1
// 00411b00  7508                 jne 0x411b0a
// 00411b02  81feffffff7f         cmp esi, 0x7fffffff
// 00411b08  746c                 je 0x411b76
// 00411b0a  83f9fe               cmp ecx, -2
// 00411b0d  7508                 jne 0x411b17
// 00411b0f  81feffffff7f         cmp esi, 0x7fffffff
// 00411b15  745f                 je 0x411b76
// 00411b17  8b0a                 mov ecx, dword ptr [edx]
// 00411b19  8b7204               mov esi, dword ptr [edx + 4]
// 00411b1c  85c9                 test ecx, ecx
// 00411b1e  7508                 jne 0x411b28
// 00411b20  81fe00000080         cmp esi, 0x80000000
// 00411b26  744e                 je 0x411b76
// 00411b28  83f9ff               cmp ecx, -1
// 00411b2b  7508                 jne 0x411b35
// 00411b2d  81feffffff7f         cmp esi, 0x7fffffff
// 00411b33  7441                 je 0x411b76
// 00411b35  83f9fe               cmp ecx, -2
// 00411b38  7508                 jne 0x411b42
// 00411b3a  81feffffff7f         cmp esi, 0x7fffffff
// 00411b40  7434                 je 0x411b76
// 00411b42  8b08                 mov ecx, dword ptr [eax]
// 00411b44  8b32                 mov esi, dword ptr [edx]
// 00411b46  8b4004               mov eax, dword ptr [eax + 4]
// 00411b49  8b5204               mov edx, dword ptr [edx + 4]
// 00411b4c  2bce                 sub ecx, esi
// 00411b4e  1bc2                 sbb eax, edx
// 00411b50  7806                 js 0x411b58
// 00411b52  7f12                 jg 0x411b66
// 00411b54  85c9                 test ecx, ecx
// 00411b56  730e                 jae 0x411b66
// 00411b58  f7d9                 neg ecx
// 00411b5a  83d000               adc eax, 0
// 00411b5d  f7d8                 neg eax
// 00411b5f  f7d9                 neg ecx
// 00411b61  83d000               adc eax, 0
// 00411b64  f7d8                 neg eax
// 00411b66  8b542420             mov edx, dword ptr [esp + 0x20]
// 00411b6a  894204               mov dword ptr [edx + 4], eax
// 00411b6d  890a                 mov dword ptr [edx], ecx
// 00411b6f  8bc2                 mov eax, edx
// 00411b71  5e                   pop esi
// 00411b72  83c418               add esp, 0x18
// 00411b75  c3                   ret 
// 00411b76  8b0a                 mov ecx, dword ptr [edx]
// 00411b78  8b5204               mov edx, dword ptr [edx + 4]
// 00411b7b  894c2404             mov dword ptr [esp + 4], ecx
// 00411b7f  8b08                 mov ecx, dword ptr [eax]
// 00411b81  89542408             mov dword ptr [esp + 8], edx
// 00411b85  8b5004               mov edx, dword ptr [eax + 4]
// 00411b88  894c240c             mov dword ptr [esp + 0xc], ecx
// 00411b8c  8d442404             lea eax, [esp + 4]
// 00411b90  50                   push eax
// 00411b91  8d4c2418             lea ecx, [esp + 0x18]
// 00411b95  51                   push ecx
// 00411b96  8d4c2414             lea ecx, [esp + 0x14]
// 00411b9a  89542418             mov dword ptr [esp + 0x18], edx
// 00411b9e  e8cdf7ffff           call 0x411370
// 00411ba3  8b08                 mov ecx, dword ptr [eax]
// 00411ba5  8b4004               mov eax, dword ptr [eax + 4]
// 00411ba8  83f9fe               cmp ecx, -2
// 00411bab  751e                 jne 0x411bcb
// 00411bad  3dffffff7f           cmp eax, 0x7fffffff
// 00411bb2  7517                 jne 0x411bcb
// 00411bb4  8b742420             mov esi, dword ptr [esp + 0x20]
// 00411bb8  33c0                 xor eax, eax
// 00411bba  50                   push eax
// 00411bbb  56                   push esi
// 00411bbc  e83ff6ffff           call 0x411200
// 00411bc1  83c408               add esp, 8
// 00411bc4  8bc6                 mov eax, esi
// 00411bc6  5e                   pop esi
// 00411bc7  83c418               add esp, 0x18
// 00411bca  c3                   ret 
// 00411bcb  85c9                 test ecx, ecx
// 00411bcd  7521                 jne 0x411bf0
// 00411bcf  3d00000080           cmp eax, 0x80000000
// 00411bd4  751a                 jne 0x411bf0
// 00411bd6  8b742420             mov esi, dword ptr [esp + 0x20]
// 00411bda  b801000000           mov eax, 1
// 00411bdf  50                   push eax
// 00411be0  56                   push esi
// 00411be1  e81af6ffff           call 0x411200
// 00411be6  83c408               add esp, 8
// 00411be9  8bc6                 mov eax, esi
// 00411beb  5e                   pop esi
// 00411bec  83c418               add esp, 0x18
// 00411bef  c3                   ret 
// 00411bf0  83f9ff               cmp ecx, -1
// 00411bf3  750a                 jne 0x411bff
// 00411bf5  3dffffff7f           cmp eax, 0x7fffffff
// 00411bfa  8d4103               lea eax, [ecx + 3]
// 00411bfd  7405                 je 0x411c04
// 00411bff  b805000000           mov eax, 5
// 00411c04  8b742420             mov esi, dword ptr [esp + 0x20]
// 00411c08  50                   push eax
// 00411c09  56                   push esi
// 00411c0a  e8f1f5ffff           call 0x411200
// 00411c0f  83c408               add esp, 8
// 00411c12  8bc6                 mov eax, esi
// 00411c14  5e                   pop esi
// 00411c15  83c418               add esp, 0x18
// 00411c18  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?subtract_times@?$counted_time_system@U?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@@date_time@boost@@SA?AVtime_duration@posix_time@3@ABU?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@23@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
