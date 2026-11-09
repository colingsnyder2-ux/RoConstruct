// from server: 100% by auto
// roc 2010-06 00412df0  unit: boost::gregorian::Ubad_month::U?$error_info_injector::?$clone_impl  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00412df0
//
// 00412df0  83ec10               sub esp, 0x10
// 00412df3  56                   push esi
// 00412df4  8b742418             mov esi, dword ptr [esp + 0x18]
// 00412df8  833eff               cmp dword ptr [esi], -1
// 00412dfb  7511                 jne 0x412e0e
// 00412dfd  817e04ffffff7f       cmp dword ptr [esi + 4], 0x7fffffff
// 00412e04  7508                 jne 0x412e0e
// 00412e06  83c8ff               or eax, 0xffffffff
// 00412e09  5e                   pop esi
// 00412e0a  83c410               add esp, 0x10
// 00412e0d  c3                   ret 
// 00412e0e  8d442404             lea eax, [esp + 4]
// 00412e12  68d02a4100           push 0x412ad0
// 00412e17  50                   push eax
// 00412e18  e863feffff           call 0x412c80
// 00412e1d  8b4604               mov eax, dword ptr [esi + 4]
// 00412e20  8b542410             mov edx, dword ptr [esp + 0x10]
// 00412e24  8b0e                 mov ecx, dword ptr [esi]
// 00412e26  83c408               add esp, 8
// 00412e29  3bd0                 cmp edx, eax
// 00412e2b  7c11                 jl 0x412e3e
// 00412e2d  7f08                 jg 0x412e37
// 00412e2f  8b442404             mov eax, dword ptr [esp + 4]
// 00412e33  3bc1                 cmp eax, ecx
// 00412e35  7207                 jb 0x412e3e
// 00412e37  33c0                 xor eax, eax
// 00412e39  5e                   pop esi
// 00412e3a  83c410               add esp, 0x10
// 00412e3d  c3                   ret 
// 00412e3e  8d4c2404             lea ecx, [esp + 4]
// 00412e42  51                   push ecx
// 00412e43  8d542410             lea edx, [esp + 0x10]
// 00412e47  56                   push esi
// 00412e48  52                   push edx
// 00412e49  e892ecffff           call 0x411ae0
// 00412e4e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00412e52  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00412e56  83c40c               add esp, 0xc
// 00412e59  6a00                 push 0
// 00412e5b  68e8030000           push 0x3e8
// 00412e60  50                   push eax
// 00412e61  51                   push ecx
// 00412e62  e8795e3900           call 0x7a8ce0
// 00412e67  40                   inc eax
// 00412e68  5e                   pop esi
// 00412e69  83c410               add esp, 0x10
// 00412e6c  c3                   ret 
// library boost-1.40.0/libs\thread\src\win32\thread.cpp (function ?get_milliseconds_until@detail@boost@@YAKABVptime@posix_time@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/thread/src/win32/thread.cpp
