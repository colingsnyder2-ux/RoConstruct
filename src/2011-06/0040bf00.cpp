// from server: 100% by auto
// roc 2011-06 0040bf00  unit: RBX::Reflection::H::?$TypedPropertyDescriptor  size: 313 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0040bf00
//
// 0040bf00  8b442408             mov eax, dword ptr [esp + 8]
// 0040bf04  8b08                 mov ecx, dword ptr [eax]
// 0040bf06  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0040bf0a  83ec18               sub esp, 0x18
// 0040bf0d  56                   push esi
// 0040bf0e  8b7004               mov esi, dword ptr [eax + 4]
// 0040bf11  85c9                 test ecx, ecx
// 0040bf13  7508                 jne 0x40bf1d
// 0040bf15  81fe00000080         cmp esi, 0x80000000
// 0040bf1b  7479                 je 0x40bf96
// 0040bf1d  83f9ff               cmp ecx, -1
// 0040bf20  7508                 jne 0x40bf2a
// 0040bf22  81feffffff7f         cmp esi, 0x7fffffff
// 0040bf28  746c                 je 0x40bf96
// 0040bf2a  83f9fe               cmp ecx, -2
// 0040bf2d  7508                 jne 0x40bf37
// 0040bf2f  81feffffff7f         cmp esi, 0x7fffffff
// 0040bf35  745f                 je 0x40bf96
// 0040bf37  8b0a                 mov ecx, dword ptr [edx]
// 0040bf39  8b7204               mov esi, dword ptr [edx + 4]
// 0040bf3c  85c9                 test ecx, ecx
// 0040bf3e  7508                 jne 0x40bf48
// 0040bf40  81fe00000080         cmp esi, 0x80000000
// 0040bf46  744e                 je 0x40bf96
// 0040bf48  83f9ff               cmp ecx, -1
// 0040bf4b  7508                 jne 0x40bf55
// 0040bf4d  81feffffff7f         cmp esi, 0x7fffffff
// 0040bf53  7441                 je 0x40bf96
// 0040bf55  83f9fe               cmp ecx, -2
// 0040bf58  7508                 jne 0x40bf62
// 0040bf5a  81feffffff7f         cmp esi, 0x7fffffff
// 0040bf60  7434                 je 0x40bf96
// 0040bf62  8b08                 mov ecx, dword ptr [eax]
// 0040bf64  8b32                 mov esi, dword ptr [edx]
// 0040bf66  8b4004               mov eax, dword ptr [eax + 4]
// 0040bf69  8b5204               mov edx, dword ptr [edx + 4]
// 0040bf6c  2bce                 sub ecx, esi
// 0040bf6e  1bc2                 sbb eax, edx
// 0040bf70  7806                 js 0x40bf78
// 0040bf72  7f12                 jg 0x40bf86
// 0040bf74  85c9                 test ecx, ecx
// 0040bf76  730e                 jae 0x40bf86
// 0040bf78  f7d9                 neg ecx
// 0040bf7a  83d000               adc eax, 0
// 0040bf7d  f7d8                 neg eax
// 0040bf7f  f7d9                 neg ecx
// 0040bf81  83d000               adc eax, 0
// 0040bf84  f7d8                 neg eax
// 0040bf86  8b542420             mov edx, dword ptr [esp + 0x20]
// 0040bf8a  894204               mov dword ptr [edx + 4], eax
// 0040bf8d  890a                 mov dword ptr [edx], ecx
// 0040bf8f  8bc2                 mov eax, edx
// 0040bf91  5e                   pop esi
// 0040bf92  83c418               add esp, 0x18
// 0040bf95  c3                   ret 
// 0040bf96  8b0a                 mov ecx, dword ptr [edx]
// 0040bf98  8b5204               mov edx, dword ptr [edx + 4]
// 0040bf9b  894c2404             mov dword ptr [esp + 4], ecx
// 0040bf9f  8b08                 mov ecx, dword ptr [eax]
// 0040bfa1  89542408             mov dword ptr [esp + 8], edx
// 0040bfa5  8b5004               mov edx, dword ptr [eax + 4]
// 0040bfa8  894c240c             mov dword ptr [esp + 0xc], ecx
// 0040bfac  8d442404             lea eax, [esp + 4]
// 0040bfb0  50                   push eax
// 0040bfb1  8d4c2418             lea ecx, [esp + 0x18]
// 0040bfb5  51                   push ecx
// 0040bfb6  8d4c2414             lea ecx, [esp + 0x14]
// 0040bfba  89542418             mov dword ptr [esp + 0x18], edx
// 0040bfbe  e8fdeeffff           call 0x40aec0
// 0040bfc3  8b08                 mov ecx, dword ptr [eax]
// 0040bfc5  8b4004               mov eax, dword ptr [eax + 4]
// 0040bfc8  83f9fe               cmp ecx, -2
// 0040bfcb  751e                 jne 0x40bfeb
// 0040bfcd  3dffffff7f           cmp eax, 0x7fffffff
// 0040bfd2  7517                 jne 0x40bfeb
// 0040bfd4  8b742420             mov esi, dword ptr [esp + 0x20]
// 0040bfd8  33c0                 xor eax, eax
// 0040bfda  50                   push eax
// 0040bfdb  56                   push esi
// 0040bfdc  e8dfecffff           call 0x40acc0
// 0040bfe1  83c408               add esp, 8
// 0040bfe4  8bc6                 mov eax, esi
// 0040bfe6  5e                   pop esi
// 0040bfe7  83c418               add esp, 0x18
// 0040bfea  c3                   ret 
// 0040bfeb  85c9                 test ecx, ecx
// 0040bfed  7521                 jne 0x40c010
// 0040bfef  3d00000080           cmp eax, 0x80000000
// 0040bff4  751a                 jne 0x40c010
// 0040bff6  8b742420             mov esi, dword ptr [esp + 0x20]
// 0040bffa  b801000000           mov eax, 1
// 0040bfff  50                   push eax
// 0040c000  56                   push esi
// 0040c001  e8baecffff           call 0x40acc0
// 0040c006  83c408               add esp, 8
// 0040c009  8bc6                 mov eax, esi
// 0040c00b  5e                   pop esi
// 0040c00c  83c418               add esp, 0x18
// 0040c00f  c3                   ret 
// 0040c010  83f9ff               cmp ecx, -1
// 0040c013  750a                 jne 0x40c01f
// 0040c015  3dffffff7f           cmp eax, 0x7fffffff
// 0040c01a  8d4103               lea eax, [ecx + 3]
// 0040c01d  7405                 je 0x40c024
// 0040c01f  b805000000           mov eax, 5
// 0040c024  8b742420             mov esi, dword ptr [esp + 0x20]
// 0040c028  50                   push eax
// 0040c029  56                   push esi
// 0040c02a  e891ecffff           call 0x40acc0
// 0040c02f  83c408               add esp, 8
// 0040c032  8bc6                 mov eax, esi
// 0040c034  5e                   pop esi
// 0040c035  83c418               add esp, 0x18
// 0040c038  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?subtract_times@?$counted_time_system@U?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@@date_time@boost@@SA?AVtime_duration@posix_time@3@ABU?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@23@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
