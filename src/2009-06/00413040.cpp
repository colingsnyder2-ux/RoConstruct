// from server: 100% by auto
// roc 2009-06 00413040  unit: boost::gregorian::Ubad_month::U?$error_info_injector::?$clone_impl  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00413040
//
// 00413040  83ec10               sub esp, 0x10
// 00413043  56                   push esi
// 00413044  8b742418             mov esi, dword ptr [esp + 0x18]
// 00413048  833eff               cmp dword ptr [esi], -1
// 0041304b  7511                 jne 0x41305e
// 0041304d  817e04ffffff7f       cmp dword ptr [esi + 4], 0x7fffffff
// 00413054  7508                 jne 0x41305e
// 00413056  83c8ff               or eax, 0xffffffff
// 00413059  5e                   pop esi
// 0041305a  83c410               add esp, 0x10
// 0041305d  c3                   ret 
// 0041305e  8d442404             lea eax, [esp + 4]
// 00413062  68802c4100           push 0x412c80
// 00413067  50                   push eax
// 00413068  e863feffff           call 0x412ed0
// 0041306d  8b4604               mov eax, dword ptr [esi + 4]
// 00413070  8b542410             mov edx, dword ptr [esp + 0x10]
// 00413074  8b0e                 mov ecx, dword ptr [esi]
// 00413076  83c408               add esp, 8
// 00413079  3bd0                 cmp edx, eax
// 0041307b  7c11                 jl 0x41308e
// 0041307d  7f08                 jg 0x413087
// 0041307f  8b442404             mov eax, dword ptr [esp + 4]
// 00413083  3bc1                 cmp eax, ecx
// 00413085  7207                 jb 0x41308e
// 00413087  33c0                 xor eax, eax
// 00413089  5e                   pop esi
// 0041308a  83c410               add esp, 0x10
// 0041308d  c3                   ret 
// 0041308e  8d4c2404             lea ecx, [esp + 4]
// 00413092  51                   push ecx
// 00413093  8d542410             lea edx, [esp + 0x10]
// 00413097  56                   push esi
// 00413098  52                   push edx
// 00413099  e8f2ebffff           call 0x411c90
// 0041309e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004130a2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004130a6  83c40c               add esp, 0xc
// 004130a9  6a00                 push 0
// 004130ab  68e8030000           push 0x3e8
// 004130b0  50                   push eax
// 004130b1  51                   push ecx
// 004130b2  e8b96c3000           call 0x719d70
// 004130b7  40                   inc eax
// 004130b8  5e                   pop esi
// 004130b9  83c410               add esp, 0x10
// 004130bc  c3                   ret 
// library boost-1.40.0/libs\thread\src\win32\thread.cpp (function ?get_milliseconds_until@detail@boost@@YAKABVptime@posix_time@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/thread/src/win32/thread.cpp
