// from server: 100% by auto
// roc 2008-06 004c1b80  unit: ProfiledRakPeer  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c1b80
//
// 004c1b80  8b442408             mov eax, dword ptr [esp + 8]
// 004c1b84  8b542404             mov edx, dword ptr [esp + 4]
// 004c1b88  6a00                 push 0
// 004c1b8a  6a00                 push 0
// 004c1b8c  50                   push eax
// 004c1b8d  52                   push edx
// 004c1b8e  e84de2ffff           call 0x4bfde0
// 004c1b93  8bd0                 mov edx, eax
// 004c1b95  85d2                 test edx, edx
// 004c1b97  7433                 je 0x4c1bcc
// 004c1b99  56                   push esi
// 004c1b9a  33c0                 xor eax, eax
// 004c1b9c  57                   push edi
// 004c1b9d  33c9                 xor ecx, ecx
// 004c1b9f  8db2e4070000         lea esi, [edx + 0x7e4]
// 004c1ba5  0fb716               movzx edx, word ptr [esi]
// 004c1ba8  bfffff0000           mov edi, 0xffff
// 004c1bad  663bd7               cmp dx, di
// 004c1bb0  740e                 je 0x4c1bc0
// 004c1bb2  0fb7d2               movzx edx, dx
// 004c1bb5  41                   inc ecx
// 004c1bb6  03c2                 add eax, edx
// 004c1bb8  83c608               add esi, 8
// 004c1bbb  83f905               cmp ecx, 5
// 004c1bbe  7ce5                 jl 0x4c1ba5
// 004c1bc0  5f                   pop edi
// 004c1bc1  5e                   pop esi
// 004c1bc2  85c9                 test ecx, ecx
// 004c1bc4  7e06                 jle 0x4c1bcc
// 004c1bc6  99                   cdq 
// 004c1bc7  f7f9                 idiv ecx
// 004c1bc9  c20800               ret 8
// 004c1bcc  83c8ff               or eax, 0xffffffff
// 004c1bcf  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?GetAveragePing@RakPeer@@UAEHUSystemAddress@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
