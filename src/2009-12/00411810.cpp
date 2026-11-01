// from server: 100% by auto
// roc 2009-12 00411810  unit: boost::gregorian::Ubad_month::?$error_info_injector  size: 313 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00411810
//
// 00411810  8b442408             mov eax, dword ptr [esp + 8]
// 00411814  8b08                 mov ecx, dword ptr [eax]
// 00411816  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0041181a  83ec18               sub esp, 0x18
// 0041181d  56                   push esi
// 0041181e  8b7004               mov esi, dword ptr [eax + 4]
// 00411821  85c9                 test ecx, ecx
// 00411823  7508                 jne 0x41182d
// 00411825  81fe00000080         cmp esi, 0x80000000
// 0041182b  7479                 je 0x4118a6
// 0041182d  83f9ff               cmp ecx, -1
// 00411830  7508                 jne 0x41183a
// 00411832  81feffffff7f         cmp esi, 0x7fffffff
// 00411838  746c                 je 0x4118a6
// 0041183a  83f9fe               cmp ecx, -2
// 0041183d  7508                 jne 0x411847
// 0041183f  81feffffff7f         cmp esi, 0x7fffffff
// 00411845  745f                 je 0x4118a6
// 00411847  8b0a                 mov ecx, dword ptr [edx]
// 00411849  8b7204               mov esi, dword ptr [edx + 4]
// 0041184c  85c9                 test ecx, ecx
// 0041184e  7508                 jne 0x411858
// 00411850  81fe00000080         cmp esi, 0x80000000
// 00411856  744e                 je 0x4118a6
// 00411858  83f9ff               cmp ecx, -1
// 0041185b  7508                 jne 0x411865
// 0041185d  81feffffff7f         cmp esi, 0x7fffffff
// 00411863  7441                 je 0x4118a6
// 00411865  83f9fe               cmp ecx, -2
// 00411868  7508                 jne 0x411872
// 0041186a  81feffffff7f         cmp esi, 0x7fffffff
// 00411870  7434                 je 0x4118a6
// 00411872  8b08                 mov ecx, dword ptr [eax]
// 00411874  8b32                 mov esi, dword ptr [edx]
// 00411876  8b4004               mov eax, dword ptr [eax + 4]
// 00411879  8b5204               mov edx, dword ptr [edx + 4]
// 0041187c  2bce                 sub ecx, esi
// 0041187e  1bc2                 sbb eax, edx
// 00411880  7806                 js 0x411888
// 00411882  7f12                 jg 0x411896
// 00411884  85c9                 test ecx, ecx
// 00411886  730e                 jae 0x411896
// 00411888  f7d9                 neg ecx
// 0041188a  83d000               adc eax, 0
// 0041188d  f7d8                 neg eax
// 0041188f  f7d9                 neg ecx
// 00411891  83d000               adc eax, 0
// 00411894  f7d8                 neg eax
// 00411896  8b542420             mov edx, dword ptr [esp + 0x20]
// 0041189a  894204               mov dword ptr [edx + 4], eax
// 0041189d  890a                 mov dword ptr [edx], ecx
// 0041189f  8bc2                 mov eax, edx
// 004118a1  5e                   pop esi
// 004118a2  83c418               add esp, 0x18
// 004118a5  c3                   ret 
// 004118a6  8b0a                 mov ecx, dword ptr [edx]
// 004118a8  8b5204               mov edx, dword ptr [edx + 4]
// 004118ab  894c2404             mov dword ptr [esp + 4], ecx
// 004118af  8b08                 mov ecx, dword ptr [eax]
// 004118b1  89542408             mov dword ptr [esp + 8], edx
// 004118b5  8b5004               mov edx, dword ptr [eax + 4]
// 004118b8  894c240c             mov dword ptr [esp + 0xc], ecx
// 004118bc  8d442404             lea eax, [esp + 4]
// 004118c0  50                   push eax
// 004118c1  8d4c2418             lea ecx, [esp + 0x18]
// 004118c5  51                   push ecx
// 004118c6  8d4c2414             lea ecx, [esp + 0x14]
// 004118ca  89542418             mov dword ptr [esp + 0x18], edx
// 004118ce  e8bdf7ffff           call 0x411090
// 004118d3  8b08                 mov ecx, dword ptr [eax]
// 004118d5  8b4004               mov eax, dword ptr [eax + 4]
// 004118d8  83f9fe               cmp ecx, -2
// 004118db  751e                 jne 0x4118fb
// 004118dd  3dffffff7f           cmp eax, 0x7fffffff
// 004118e2  7517                 jne 0x4118fb
// 004118e4  8b742420             mov esi, dword ptr [esp + 0x20]
// 004118e8  33c0                 xor eax, eax
// 004118ea  50                   push eax
// 004118eb  56                   push esi
// 004118ec  e82ff6ffff           call 0x410f20
// 004118f1  83c408               add esp, 8
// 004118f4  8bc6                 mov eax, esi
// 004118f6  5e                   pop esi
// 004118f7  83c418               add esp, 0x18
// 004118fa  c3                   ret 
// 004118fb  85c9                 test ecx, ecx
// 004118fd  7521                 jne 0x411920
// 004118ff  3d00000080           cmp eax, 0x80000000
// 00411904  751a                 jne 0x411920
// 00411906  8b742420             mov esi, dword ptr [esp + 0x20]
// 0041190a  b801000000           mov eax, 1
// 0041190f  50                   push eax
// 00411910  56                   push esi
// 00411911  e80af6ffff           call 0x410f20
// 00411916  83c408               add esp, 8
// 00411919  8bc6                 mov eax, esi
// 0041191b  5e                   pop esi
// 0041191c  83c418               add esp, 0x18
// 0041191f  c3                   ret 
// 00411920  83f9ff               cmp ecx, -1
// 00411923  750a                 jne 0x41192f
// 00411925  3dffffff7f           cmp eax, 0x7fffffff
// 0041192a  8d4103               lea eax, [ecx + 3]
// 0041192d  7405                 je 0x411934
// 0041192f  b805000000           mov eax, 5
// 00411934  8b742420             mov esi, dword ptr [esp + 0x20]
// 00411938  50                   push eax
// 00411939  56                   push esi
// 0041193a  e8e1f5ffff           call 0x410f20
// 0041193f  83c408               add esp, 8
// 00411942  8bc6                 mov eax, esi
// 00411944  5e                   pop esi
// 00411945  83c418               add esp, 0x18
// 00411948  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?subtract_times@?$counted_time_system@U?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@@date_time@boost@@SA?AVtime_duration@posix_time@3@ABU?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@23@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
