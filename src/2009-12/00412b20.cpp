// from server: 100% by auto
// roc 2009-12 00412b20  unit: boost::gregorian::Ubad_month::U?$error_info_injector::?$clone_impl  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00412b20
//
// 00412b20  83ec10               sub esp, 0x10
// 00412b23  56                   push esi
// 00412b24  8b742418             mov esi, dword ptr [esp + 0x18]
// 00412b28  833eff               cmp dword ptr [esi], -1
// 00412b2b  7511                 jne 0x412b3e
// 00412b2d  817e04ffffff7f       cmp dword ptr [esi + 4], 0x7fffffff
// 00412b34  7508                 jne 0x412b3e
// 00412b36  83c8ff               or eax, 0xffffffff
// 00412b39  5e                   pop esi
// 00412b3a  83c410               add esp, 0x10
// 00412b3d  c3                   ret 
// 00412b3e  8d442404             lea eax, [esp + 4]
// 00412b42  6800284100           push 0x412800
// 00412b47  50                   push eax
// 00412b48  e863feffff           call 0x4129b0
// 00412b4d  8b4604               mov eax, dword ptr [esi + 4]
// 00412b50  8b542410             mov edx, dword ptr [esp + 0x10]
// 00412b54  8b0e                 mov ecx, dword ptr [esi]
// 00412b56  83c408               add esp, 8
// 00412b59  3bd0                 cmp edx, eax
// 00412b5b  7c11                 jl 0x412b6e
// 00412b5d  7f08                 jg 0x412b67
// 00412b5f  8b442404             mov eax, dword ptr [esp + 4]
// 00412b63  3bc1                 cmp eax, ecx
// 00412b65  7207                 jb 0x412b6e
// 00412b67  33c0                 xor eax, eax
// 00412b69  5e                   pop esi
// 00412b6a  83c410               add esp, 0x10
// 00412b6d  c3                   ret 
// 00412b6e  8d4c2404             lea ecx, [esp + 4]
// 00412b72  51                   push ecx
// 00412b73  8d542410             lea edx, [esp + 0x10]
// 00412b77  56                   push esi
// 00412b78  52                   push edx
// 00412b79  e892ecffff           call 0x411810
// 00412b7e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00412b82  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00412b86  83c40c               add esp, 0xc
// 00412b89  6a00                 push 0
// 00412b8b  68e8030000           push 0x3e8
// 00412b90  50                   push eax
// 00412b91  51                   push ecx
// 00412b92  e809203e00           call 0x7f4ba0
// 00412b97  40                   inc eax
// 00412b98  5e                   pop esi
// 00412b99  83c410               add esp, 0x10
// 00412b9c  c3                   ret 
// library boost-1.40.0/libs\thread\src\win32\thread.cpp (function ?get_milliseconds_until@detail@boost@@YAKABVptime@posix_time@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/thread/src/win32/thread.cpp
