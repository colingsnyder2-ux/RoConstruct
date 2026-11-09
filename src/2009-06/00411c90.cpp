// from server: 100% by auto
// roc 2009-06 00411c90  unit: boost::gregorian::Ubad_month::?$error_info_injector  size: 313 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00411c90
//
// 00411c90  8b442408             mov eax, dword ptr [esp + 8]
// 00411c94  8b08                 mov ecx, dword ptr [eax]
// 00411c96  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00411c9a  83ec18               sub esp, 0x18
// 00411c9d  56                   push esi
// 00411c9e  8b7004               mov esi, dword ptr [eax + 4]
// 00411ca1  85c9                 test ecx, ecx
// 00411ca3  7508                 jne 0x411cad
// 00411ca5  81fe00000080         cmp esi, 0x80000000
// 00411cab  7479                 je 0x411d26
// 00411cad  83f9ff               cmp ecx, -1
// 00411cb0  7508                 jne 0x411cba
// 00411cb2  81feffffff7f         cmp esi, 0x7fffffff
// 00411cb8  746c                 je 0x411d26
// 00411cba  83f9fe               cmp ecx, -2
// 00411cbd  7508                 jne 0x411cc7
// 00411cbf  81feffffff7f         cmp esi, 0x7fffffff
// 00411cc5  745f                 je 0x411d26
// 00411cc7  8b0a                 mov ecx, dword ptr [edx]
// 00411cc9  8b7204               mov esi, dword ptr [edx + 4]
// 00411ccc  85c9                 test ecx, ecx
// 00411cce  7508                 jne 0x411cd8
// 00411cd0  81fe00000080         cmp esi, 0x80000000
// 00411cd6  744e                 je 0x411d26
// 00411cd8  83f9ff               cmp ecx, -1
// 00411cdb  7508                 jne 0x411ce5
// 00411cdd  81feffffff7f         cmp esi, 0x7fffffff
// 00411ce3  7441                 je 0x411d26
// 00411ce5  83f9fe               cmp ecx, -2
// 00411ce8  7508                 jne 0x411cf2
// 00411cea  81feffffff7f         cmp esi, 0x7fffffff
// 00411cf0  7434                 je 0x411d26
// 00411cf2  8b08                 mov ecx, dword ptr [eax]
// 00411cf4  8b32                 mov esi, dword ptr [edx]
// 00411cf6  8b4004               mov eax, dword ptr [eax + 4]
// 00411cf9  8b5204               mov edx, dword ptr [edx + 4]
// 00411cfc  2bce                 sub ecx, esi
// 00411cfe  1bc2                 sbb eax, edx
// 00411d00  7806                 js 0x411d08
// 00411d02  7f12                 jg 0x411d16
// 00411d04  85c9                 test ecx, ecx
// 00411d06  730e                 jae 0x411d16
// 00411d08  f7d9                 neg ecx
// 00411d0a  83d000               adc eax, 0
// 00411d0d  f7d8                 neg eax
// 00411d0f  f7d9                 neg ecx
// 00411d11  83d000               adc eax, 0
// 00411d14  f7d8                 neg eax
// 00411d16  8b542420             mov edx, dword ptr [esp + 0x20]
// 00411d1a  894204               mov dword ptr [edx + 4], eax
// 00411d1d  890a                 mov dword ptr [edx], ecx
// 00411d1f  8bc2                 mov eax, edx
// 00411d21  5e                   pop esi
// 00411d22  83c418               add esp, 0x18
// 00411d25  c3                   ret 
// 00411d26  8b0a                 mov ecx, dword ptr [edx]
// 00411d28  8b5204               mov edx, dword ptr [edx + 4]
// 00411d2b  894c2404             mov dword ptr [esp + 4], ecx
// 00411d2f  8b08                 mov ecx, dword ptr [eax]
// 00411d31  89542408             mov dword ptr [esp + 8], edx
// 00411d35  8b5004               mov edx, dword ptr [eax + 4]
// 00411d38  894c240c             mov dword ptr [esp + 0xc], ecx
// 00411d3c  8d442404             lea eax, [esp + 4]
// 00411d40  50                   push eax
// 00411d41  8d4c2418             lea ecx, [esp + 0x18]
// 00411d45  51                   push ecx
// 00411d46  8d4c2414             lea ecx, [esp + 0x14]
// 00411d4a  89542418             mov dword ptr [esp + 0x18], edx
// 00411d4e  e89df7ffff           call 0x4114f0
// 00411d53  8b08                 mov ecx, dword ptr [eax]
// 00411d55  8b4004               mov eax, dword ptr [eax + 4]
// 00411d58  83f9fe               cmp ecx, -2
// 00411d5b  751e                 jne 0x411d7b
// 00411d5d  3dffffff7f           cmp eax, 0x7fffffff
// 00411d62  7517                 jne 0x411d7b
// 00411d64  8b742420             mov esi, dword ptr [esp + 0x20]
// 00411d68  33c0                 xor eax, eax
// 00411d6a  50                   push eax
// 00411d6b  56                   push esi
// 00411d6c  e80ff6ffff           call 0x411380
// 00411d71  83c408               add esp, 8
// 00411d74  8bc6                 mov eax, esi
// 00411d76  5e                   pop esi
// 00411d77  83c418               add esp, 0x18
// 00411d7a  c3                   ret 
// 00411d7b  85c9                 test ecx, ecx
// 00411d7d  7521                 jne 0x411da0
// 00411d7f  3d00000080           cmp eax, 0x80000000
// 00411d84  751a                 jne 0x411da0
// 00411d86  8b742420             mov esi, dword ptr [esp + 0x20]
// 00411d8a  b801000000           mov eax, 1
// 00411d8f  50                   push eax
// 00411d90  56                   push esi
// 00411d91  e8eaf5ffff           call 0x411380
// 00411d96  83c408               add esp, 8
// 00411d99  8bc6                 mov eax, esi
// 00411d9b  5e                   pop esi
// 00411d9c  83c418               add esp, 0x18
// 00411d9f  c3                   ret 
// 00411da0  83f9ff               cmp ecx, -1
// 00411da3  750a                 jne 0x411daf
// 00411da5  3dffffff7f           cmp eax, 0x7fffffff
// 00411daa  8d4103               lea eax, [ecx + 3]
// 00411dad  7405                 je 0x411db4
// 00411daf  b805000000           mov eax, 5
// 00411db4  8b742420             mov esi, dword ptr [esp + 0x20]
// 00411db8  50                   push eax
// 00411db9  56                   push esi
// 00411dba  e8c1f5ffff           call 0x411380
// 00411dbf  83c408               add esp, 8
// 00411dc2  8bc6                 mov eax, esi
// 00411dc4  5e                   pop esi
// 00411dc5  83c418               add esp, 0x18
// 00411dc8  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?subtract_times@?$counted_time_system@U?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@@date_time@boost@@SA?AVtime_duration@posix_time@3@ABU?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@23@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
