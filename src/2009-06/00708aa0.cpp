// from server: 100% by auto
// roc 2009-06 00708aa0  unit: RBX::Log  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00708aa0
//
// 00708aa0  a1fc04a500           mov eax, dword ptr [0xa504fc]
// 00708aa5  85c0                 test eax, eax
// 00708aa7  7422                 je 0x708acb
// 00708aa9  50                   push eax
// 00708aaa  ff15e8e28900         call dword ptr [0x89e2e8]
// 00708ab0  85c0                 test eax, eax
// 00708ab2  7417                 je 0x708acb
// 00708ab4  8b4014               mov eax, dword ptr [eax + 0x14]
// 00708ab7  85c0                 test eax, eax
// 00708ab9  7410                 je 0x708acb
// 00708abb  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00708abf  90                   nop 
// 00708ac0  3908                 cmp dword ptr [eax], ecx
// 00708ac2  740a                 je 0x708ace
// 00708ac4  8b4010               mov eax, dword ptr [eax + 0x10]
// 00708ac7  85c0                 test eax, eax
// 00708ac9  75f5                 jne 0x708ac0
// 00708acb  33c0                 xor eax, eax
// 00708acd  c3                   ret 
// 00708ace  8b400c               mov eax, dword ptr [eax + 0xc]
// 00708ad1  c3                   ret 
// library boost-1.40.0/libs\thread\src\win32\thread.cpp (function ?get_tss_data@detail@boost@@YAPAXPBX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/thread/src/win32/thread.cpp
