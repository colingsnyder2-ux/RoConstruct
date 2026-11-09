// from server: 100% by auto
// roc 2009-12 0079f3a0  unit: seg_00790000  size: 244 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f3a0
//
// 0079f3a0  56                   push esi
// 0079f3a1  8b742408             mov esi, dword ptr [esp + 8]
// 0079f3a5  6a01                 push 1
// 0079f3a7  56                   push esi
// 0079f3a8  e893b3feff           call 0x78a740
// 0079f3ad  68682b9d00           push 0x9d2b68
// 0079f3b2  6a01                 push 1
// 0079f3b4  56                   push esi
// 0079f3b5  e856aafeff           call 0x789e10
// 0079f3ba  83c414               add esp, 0x14
// 0079f3bd  85c0                 test eax, eax
// 0079f3bf  0f85b2000000         jne 0x79f477
// 0079f3c5  6a01                 push 1
// 0079f3c7  56                   push esi
// 0079f3c8  e8c395feff           call 0x788990
// 0079f3cd  83c408               add esp, 8
// 0079f3d0  83f804               cmp eax, 4
// 0079f3d3  7775                 ja 0x79f44a
// 0079f3d5  ff248580f47900       jmp dword ptr [eax*4 + 0x79f480]
// 0079f3dc  6a00                 push 0
// 0079f3de  6a01                 push 1
// 0079f3e0  56                   push esi
// 0079f3e1  e8ba97feff           call 0x788ba0
// 0079f3e6  50                   push eax
// 0079f3e7  56                   push esi
// 0079f3e8  e8f399feff           call 0x788de0
// 0079f3ed  83c414               add esp, 0x14
// 0079f3f0  b801000000           mov eax, 1
// 0079f3f5  5e                   pop esi
// 0079f3f6  c3                   ret 
// 0079f3f7  6a01                 push 1
// 0079f3f9  56                   push esi
// 0079f3fa  e86195feff           call 0x788960
// 0079f3ff  83c408               add esp, 8
// 0079f402  b801000000           mov eax, 1
// 0079f407  5e                   pop esi
// 0079f408  c3                   ret 
// 0079f409  6a01                 push 1
// 0079f40b  56                   push esi
// 0079f40c  e85f97feff           call 0x788b70
// 0079f411  83c408               add esp, 8
// 0079f414  85c0                 test eax, eax
// 0079f416  b804299c00           mov eax, 0x9c2904
// 0079f41b  7505                 jne 0x79f422
// 0079f41d  b8f4559b00           mov eax, 0x9b55f4
// 0079f422  50                   push eax
// 0079f423  56                   push esi
// 0079f424  e8b799feff           call 0x788de0
// 0079f429  83c408               add esp, 8
// 0079f42c  b801000000           mov eax, 1
// 0079f431  5e                   pop esi
// 0079f432  c3                   ret 
// 0079f433  6a03                 push 3
// 0079f435  6800f99c00           push 0x9cf900
// 0079f43a  56                   push esi
// 0079f43b  e86099feff           call 0x788da0
// 0079f440  83c40c               add esp, 0xc
// 0079f443  b801000000           mov eax, 1
// 0079f448  5e                   pop esi
// 0079f449  c3                   ret 
// 0079f44a  6a01                 push 1
// 0079f44c  56                   push esi
// 0079f44d  e87e98feff           call 0x788cd0
// 0079f452  83c408               add esp, 8
// 0079f455  50                   push eax
// 0079f456  6a01                 push 1
// 0079f458  56                   push esi
// 0079f459  e83295feff           call 0x788990
// 0079f45e  50                   push eax
// 0079f45f  56                   push esi
// 0079f460  e84b95feff           call 0x7889b0
// 0079f465  83c410               add esp, 0x10
// 0079f468  50                   push eax
// 0079f469  6894b69e00           push 0x9eb694
// 0079f46e  56                   push esi
// 0079f46f  e80c9afeff           call 0x788e80
// 0079f474  83c410               add esp, 0x10
// 0079f477  b801000000           mov eax, 1
// 0079f47c  5e                   pop esi
// 0079f47d  c3                   ret 
// 0079f47e  8bff                 mov edi, edi
// 0079f480  33f4                 xor esi, esp
// 0079f482  7900                 jns 0x79f484
// 0079f484  09f4                 or esp, esi
// 0079f486  7900                 jns 0x79f488
// 0079f488  4a                   dec edx
// 0079f489  f4                   hlt 
// 0079f48a  7900                 jns 0x79f48c
// 0079f48c  dcf3                 fdivr st(3), st(0)
// 0079f48e  7900                 jns 0x79f490
// 0079f490  f7f3                 div ebx
// 0079f492  7900                 jns 0x79f494
// library lua-5.1/lbaselib.c (function _luaB_tostring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
