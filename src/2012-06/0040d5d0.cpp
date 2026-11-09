// from server: 100% by auto
// roc 2012-06 0040d5d0  unit: RBX::Reflection::H::?$TypedPropertyDescriptor  size: 313 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040d5d0
//
// 0040d5d0  8b442408             mov eax, dword ptr [esp + 8]
// 0040d5d4  8b08                 mov ecx, dword ptr [eax]
// 0040d5d6  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0040d5da  83ec18               sub esp, 0x18
// 0040d5dd  56                   push esi
// 0040d5de  8b7004               mov esi, dword ptr [eax + 4]
// 0040d5e1  85c9                 test ecx, ecx
// 0040d5e3  7508                 jne 0x40d5ed
// 0040d5e5  81fe00000080         cmp esi, 0x80000000
// 0040d5eb  7479                 je 0x40d666
// 0040d5ed  83f9ff               cmp ecx, -1
// 0040d5f0  7508                 jne 0x40d5fa
// 0040d5f2  81feffffff7f         cmp esi, 0x7fffffff
// 0040d5f8  746c                 je 0x40d666
// 0040d5fa  83f9fe               cmp ecx, -2
// 0040d5fd  7508                 jne 0x40d607
// 0040d5ff  81feffffff7f         cmp esi, 0x7fffffff
// 0040d605  745f                 je 0x40d666
// 0040d607  8b0a                 mov ecx, dword ptr [edx]
// 0040d609  8b7204               mov esi, dword ptr [edx + 4]
// 0040d60c  85c9                 test ecx, ecx
// 0040d60e  7508                 jne 0x40d618
// 0040d610  81fe00000080         cmp esi, 0x80000000
// 0040d616  744e                 je 0x40d666
// 0040d618  83f9ff               cmp ecx, -1
// 0040d61b  7508                 jne 0x40d625
// 0040d61d  81feffffff7f         cmp esi, 0x7fffffff
// 0040d623  7441                 je 0x40d666
// 0040d625  83f9fe               cmp ecx, -2
// 0040d628  7508                 jne 0x40d632
// 0040d62a  81feffffff7f         cmp esi, 0x7fffffff
// 0040d630  7434                 je 0x40d666
// 0040d632  8b08                 mov ecx, dword ptr [eax]
// 0040d634  8b32                 mov esi, dword ptr [edx]
// 0040d636  8b4004               mov eax, dword ptr [eax + 4]
// 0040d639  8b5204               mov edx, dword ptr [edx + 4]
// 0040d63c  2bce                 sub ecx, esi
// 0040d63e  1bc2                 sbb eax, edx
// 0040d640  7806                 js 0x40d648
// 0040d642  7f12                 jg 0x40d656
// 0040d644  85c9                 test ecx, ecx
// 0040d646  730e                 jae 0x40d656
// 0040d648  f7d9                 neg ecx
// 0040d64a  83d000               adc eax, 0
// 0040d64d  f7d8                 neg eax
// 0040d64f  f7d9                 neg ecx
// 0040d651  83d000               adc eax, 0
// 0040d654  f7d8                 neg eax
// 0040d656  8b542420             mov edx, dword ptr [esp + 0x20]
// 0040d65a  894204               mov dword ptr [edx + 4], eax
// 0040d65d  890a                 mov dword ptr [edx], ecx
// 0040d65f  8bc2                 mov eax, edx
// 0040d661  5e                   pop esi
// 0040d662  83c418               add esp, 0x18
// 0040d665  c3                   ret 
// 0040d666  8b0a                 mov ecx, dword ptr [edx]
// 0040d668  8b5204               mov edx, dword ptr [edx + 4]
// 0040d66b  894c2404             mov dword ptr [esp + 4], ecx
// 0040d66f  8b08                 mov ecx, dword ptr [eax]
// 0040d671  89542408             mov dword ptr [esp + 8], edx
// 0040d675  8b5004               mov edx, dword ptr [eax + 4]
// 0040d678  894c240c             mov dword ptr [esp + 0xc], ecx
// 0040d67c  8d442404             lea eax, [esp + 4]
// 0040d680  50                   push eax
// 0040d681  8d4c2418             lea ecx, [esp + 0x18]
// 0040d685  51                   push ecx
// 0040d686  8d4c2414             lea ecx, [esp + 0x14]
// 0040d68a  89542418             mov dword ptr [esp + 0x18], edx
// 0040d68e  e84defffff           call 0x40c5e0
// 0040d693  8b08                 mov ecx, dword ptr [eax]
// 0040d695  8b4004               mov eax, dword ptr [eax + 4]
// 0040d698  83f9fe               cmp ecx, -2
// 0040d69b  751e                 jne 0x40d6bb
// 0040d69d  3dffffff7f           cmp eax, 0x7fffffff
// 0040d6a2  7517                 jne 0x40d6bb
// 0040d6a4  8b742420             mov esi, dword ptr [esp + 0x20]
// 0040d6a8  33c0                 xor eax, eax
// 0040d6aa  50                   push eax
// 0040d6ab  56                   push esi
// 0040d6ac  e85fedffff           call 0x40c410
// 0040d6b1  83c408               add esp, 8
// 0040d6b4  8bc6                 mov eax, esi
// 0040d6b6  5e                   pop esi
// 0040d6b7  83c418               add esp, 0x18
// 0040d6ba  c3                   ret 
// 0040d6bb  85c9                 test ecx, ecx
// 0040d6bd  7521                 jne 0x40d6e0
// 0040d6bf  3d00000080           cmp eax, 0x80000000
// 0040d6c4  751a                 jne 0x40d6e0
// 0040d6c6  8b742420             mov esi, dword ptr [esp + 0x20]
// 0040d6ca  b801000000           mov eax, 1
// 0040d6cf  50                   push eax
// 0040d6d0  56                   push esi
// 0040d6d1  e83aedffff           call 0x40c410
// 0040d6d6  83c408               add esp, 8
// 0040d6d9  8bc6                 mov eax, esi
// 0040d6db  5e                   pop esi
// 0040d6dc  83c418               add esp, 0x18
// 0040d6df  c3                   ret 
// 0040d6e0  83f9ff               cmp ecx, -1
// 0040d6e3  750a                 jne 0x40d6ef
// 0040d6e5  3dffffff7f           cmp eax, 0x7fffffff
// 0040d6ea  8d4103               lea eax, [ecx + 3]
// 0040d6ed  7405                 je 0x40d6f4
// 0040d6ef  b805000000           mov eax, 5
// 0040d6f4  8b742420             mov esi, dword ptr [esp + 0x20]
// 0040d6f8  50                   push eax
// 0040d6f9  56                   push esi
// 0040d6fa  e811edffff           call 0x40c410
// 0040d6ff  83c408               add esp, 8
// 0040d702  8bc6                 mov eax, esi
// 0040d704  5e                   pop esi
// 0040d705  83c418               add esp, 0x18
// 0040d708  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?subtract_times@?$counted_time_system@U?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@@date_time@boost@@SA?AVtime_duration@posix_time@3@ABU?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@23@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
