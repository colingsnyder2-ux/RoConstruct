// from server: 100% by auto
// roc 2011-06 00410880  unit: RBX::Reflection::Metadata::VCallbacks::?$FactoryProduct  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00410880
//
// 00410880  83ec10               sub esp, 0x10
// 00410883  56                   push esi
// 00410884  8b742418             mov esi, dword ptr [esp + 0x18]
// 00410888  833eff               cmp dword ptr [esi], -1
// 0041088b  7511                 jne 0x41089e
// 0041088d  817e04ffffff7f       cmp dword ptr [esi + 4], 0x7fffffff
// 00410894  7508                 jne 0x41089e
// 00410896  83c8ff               or eax, 0xffffffff
// 00410899  5e                   pop esi
// 0041089a  83c410               add esp, 0x10
// 0041089d  c3                   ret 
// 0041089e  8d442404             lea eax, [esp + 4]
// 004108a2  6820da4000           push 0x40da20
// 004108a7  50                   push eax
// 004108a8  e833f9ffff           call 0x4101e0
// 004108ad  8b4604               mov eax, dword ptr [esi + 4]
// 004108b0  8b542410             mov edx, dword ptr [esp + 0x10]
// 004108b4  8b0e                 mov ecx, dword ptr [esi]
// 004108b6  83c408               add esp, 8
// 004108b9  3bd0                 cmp edx, eax
// 004108bb  7c11                 jl 0x4108ce
// 004108bd  7f08                 jg 0x4108c7
// 004108bf  8b442404             mov eax, dword ptr [esp + 4]
// 004108c3  3bc1                 cmp eax, ecx
// 004108c5  7207                 jb 0x4108ce
// 004108c7  33c0                 xor eax, eax
// 004108c9  5e                   pop esi
// 004108ca  83c410               add esp, 0x10
// 004108cd  c3                   ret 
// 004108ce  8d4c2404             lea ecx, [esp + 4]
// 004108d2  51                   push ecx
// 004108d3  8d542410             lea edx, [esp + 0x10]
// 004108d7  56                   push esi
// 004108d8  52                   push edx
// 004108d9  e822b6ffff           call 0x40bf00
// 004108de  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004108e2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004108e6  83c40c               add esp, 0xc
// 004108e9  6a00                 push 0
// 004108eb  68e8030000           push 0x3e8
// 004108f0  50                   push eax
// 004108f1  51                   push ecx
// 004108f2  e8e9aa3f00           call 0x80b3e0
// 004108f7  40                   inc eax
// 004108f8  5e                   pop esi
// 004108f9  83c410               add esp, 0x10
// 004108fc  c3                   ret 
// library boost-1.40.0/libs\thread\src\win32\thread.cpp (function ?get_milliseconds_until@detail@boost@@YAKABVptime@posix_time@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/thread/src/win32/thread.cpp
