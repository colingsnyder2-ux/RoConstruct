// from server: 100% by auto
// roc 2009-12 00570500  unit: CSHA1  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00570500
//
// 00570500  a12027b800           mov eax, dword ptr [0xb82720]
// 00570505  85c0                 test eax, eax
// 00570507  741c                 je 0x570525
// 00570509  83f801               cmp eax, 1
// 0057050c  7e07                 jle 0x570515
// 0057050e  48                   dec eax
// 0057050f  a32027b800           mov dword ptr [0xb82720], eax
// 00570514  c3                   ret 
// 00570515  ff1534cd9800         call dword ptr [0x98cd34]
// 0057051b  c7052027b80000000000 mov dword ptr [0xb82720], 0
// 00570525  c3                   ret 
// library raknet-4.081/WSAStartupSingleton.cpp (function ?Deref@WSAStartupSingleton@@SAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 WSAStartupSingleton.cpp
