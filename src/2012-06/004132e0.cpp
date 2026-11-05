// from server: 100% by auto
// roc 2012-06 004132e0  unit: RBX::Reflection::H::?$TypedPropertyDescriptor  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004132e0
//
// 004132e0  83ec10               sub esp, 0x10
// 004132e3  56                   push esi
// 004132e4  8b742418             mov esi, dword ptr [esp + 0x18]
// 004132e8  833eff               cmp dword ptr [esi], -1
// 004132eb  7511                 jne 0x4132fe
// 004132ed  817e04ffffff7f       cmp dword ptr [esi + 4], 0x7fffffff
// 004132f4  7508                 jne 0x4132fe
// 004132f6  83c8ff               or eax, 0xffffffff
// 004132f9  5e                   pop esi
// 004132fa  83c410               add esp, 0x10
// 004132fd  c3                   ret 
// 004132fe  8d442404             lea eax, [esp + 4]
// 00413302  6870f54000           push 0x40f570
// 00413307  50                   push eax
// 00413308  e853f1ffff           call 0x412460
// 0041330d  8b4604               mov eax, dword ptr [esi + 4]
// 00413310  8b542410             mov edx, dword ptr [esp + 0x10]
// 00413314  8b0e                 mov ecx, dword ptr [esi]
// 00413316  83c408               add esp, 8
// 00413319  3bd0                 cmp edx, eax
// 0041331b  7c11                 jl 0x41332e
// 0041331d  7f08                 jg 0x413327
// 0041331f  8b442404             mov eax, dword ptr [esp + 4]
// 00413323  3bc1                 cmp eax, ecx
// 00413325  7207                 jb 0x41332e
// 00413327  33c0                 xor eax, eax
// 00413329  5e                   pop esi
// 0041332a  83c410               add esp, 0x10
// 0041332d  c3                   ret 
// 0041332e  8d4c2404             lea ecx, [esp + 4]
// 00413332  51                   push ecx
// 00413333  8d542410             lea edx, [esp + 0x10]
// 00413337  56                   push esi
// 00413338  52                   push edx
// 00413339  e892a2ffff           call 0x40d5d0
// 0041333e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00413342  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00413346  83c40c               add esp, 0xc
// 00413349  6a00                 push 0
// 0041334b  68e8030000           push 0x3e8
// 00413350  50                   push eax
// 00413351  51                   push ecx
// 00413352  e809015700           call 0x983460
// 00413357  40                   inc eax
// 00413358  5e                   pop esi
// 00413359  83c410               add esp, 0x10
// 0041335c  c3                   ret 
// library boost-1.40.0/libs\thread\src\win32\thread.cpp (function ?get_milliseconds_until@detail@boost@@YAKABVptime@posix_time@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/thread/src/win32/thread.cpp
