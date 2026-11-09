// from server: 100% by auto
// roc 2009-12 005704d0  unit: CSHA1  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005704d0
//
// 005704d0  a12027b800           mov eax, dword ptr [0xb82720]
// 005704d5  40                   inc eax
// 005704d6  81ec90010000         sub esp, 0x190
// 005704dc  a32027b800           mov dword ptr [0xb82720], eax
// 005704e1  83f801               cmp eax, 1
// 005704e4  750f                 jne 0x5704f5
// 005704e6  8d0424               lea eax, [esp]
// 005704e9  50                   push eax
// 005704ea  6802020000           push 0x202
// 005704ef  ff1538cd9800         call dword ptr [0x98cd38]
// 005704f5  81c490010000         add esp, 0x190
// 005704fb  c3                   ret 
// library raknet-4.081/WSAStartupSingleton.cpp (function ?AddRef@WSAStartupSingleton@@SAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 WSAStartupSingleton.cpp
