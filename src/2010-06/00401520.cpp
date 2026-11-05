// from server: 100% by auto
// roc 2010-06 00401520  unit: std::logic_error  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00401520
//
// 00401520  83ec44               sub esp, 0x44
// 00401523  56                   push esi
// 00401524  57                   push edi
// 00401525  b90c000000           mov ecx, 0xc
// 0040152a  be4c00a000           mov esi, 0xa0004c
// 0040152f  8d7c2408             lea edi, [esp + 8]
// 00401533  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00401535  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 00401539  8d442438             lea eax, [esp + 0x38]
// 0040153d  50                   push eax
// 0040153e  51                   push ecx
// 0040153f  a4                   movsb byte ptr es:[edi], byte ptr [esi]
// 00401540  e8ebfcffff           call 0x401230
// 00401545  83c408               add esp, 8
// 00401548  8d542440             lea edx, [esp + 0x40]
// 0040154c  52                   push edx
// 0040154d  ff15b4a39e00         call dword ptr [0x9ea3b4]
// 00401553  50                   push eax
// 00401554  e857fdffff           call 0x4012b0
// 00401559  83c408               add esp, 8
// 0040155c  8d442408             lea eax, [esp + 8]
// 00401560  50                   push eax
// 00401561  6a00                 push 0
// 00401563  6a00                 push 0
// 00401565  ff15b8a39e00         call dword ptr [0x9ea3b8]
// 0040156b  5f                   pop edi
// 0040156c  5e                   pop esi
// 0040156d  83c444               add esp, 0x44
// 00401570  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?create_once_mutex@detail@boost@@YAPAXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
