// from server: 100% by auto
// roc 2008-06 004bfbe0  unit: ProfiledRakPeer  size: 323 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bfbe0
//
// 004bfbe0  83ec08               sub esp, 8
// 004bfbe3  53                   push ebx
// 004bfbe4  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004bfbe8  56                   push esi
// 004bfbe9  8bf1                 mov esi, ecx
// 004bfbeb  89742408             mov dword ptr [esp + 8], esi
// 004bfbef  85db                 test ebx, ebx
// 004bfbf1  0f8422010000         je 0x4bfd19
// 004bfbf7  803b00               cmp byte ptr [ebx], 0
// 004bfbfa  0f8419010000         je 0x4bfd19
// 004bfc00  8bc3                 mov eax, ebx
// 004bfc02  8d5001               lea edx, [eax + 1]
// 004bfc05  8a08                 mov cl, byte ptr [eax]
// 004bfc07  40                   inc eax
// 004bfc08  84c9                 test cl, cl
// 004bfc0a  75f9                 jne 0x4bfc05
// 004bfc0c  2bc2                 sub eax, edx
// 004bfc0e  83f80f               cmp eax, 0xf
// 004bfc11  0f8702010000         ja 0x4bfd19
// 004bfc17  57                   push edi
// 004bfc18  33ff                 xor edi, edi
// 004bfc1a  39bea0020000         cmp dword ptr [esi + 0x2a0], edi
// 004bfc20  750b                 jne 0x4bfc2d
// 004bfc22  5f                   pop edi
// 004bfc23  5e                   pop esi
// 004bfc24  32c0                 xor al, al
// 004bfc26  5b                   pop ebx
// 004bfc27  83c408               add esp, 8
// 004bfc2a  c20400               ret 4
// 004bfc2d  55                   push ebp
// 004bfc2e  e8dd9c0000           call 0x4c9910
// 004bfc33  8dae84020000         lea ebp, [esi + 0x284]
// 004bfc39  8bcd                 mov ecx, ebp
// 004bfc3b  89442414             mov dword ptr [esp + 0x14], eax
// 004bfc3f  896c241c             mov dword ptr [esp + 0x1c], ebp
// 004bfc43  e848430100           call 0x4d3f90
// 004bfc48  39bea0020000         cmp dword ptr [esi + 0x2a0], edi
// 004bfc4e  0f869d000000         jbe 0x4bfcf1
// 004bfc54  8dae9c020000         lea ebp, [esi + 0x29c]
// 004bfc5a  8d9b00000000         lea ebx, [ebx]
// 004bfc60  8b4500               mov eax, dword ptr [ebp]
// 004bfc63  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 004bfc66  8b4104               mov eax, dword ptr [ecx + 4]
// 004bfc69  85c0                 test eax, eax
// 004bfc6b  7643                 jbe 0x4bfcb0
// 004bfc6d  3b442414             cmp eax, dword ptr [esp + 0x14]
// 004bfc71  733d                 jae 0x4bfcb0
// 004bfc73  8b4500               mov eax, dword ptr [ebp]
// 004bfc76  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004bfc7a  8b91a0020000         mov edx, dword ptr [ecx + 0x2a0]
// 004bfc80  8b5490fc             mov edx, dword ptr [eax + edx*4 - 4]
// 004bfc84  8b34b8               mov esi, dword ptr [eax + edi*4]
// 004bfc87  8914b8               mov dword ptr [eax + edi*4], edx
// 004bfc8a  8b81a0020000         mov eax, dword ptr [ecx + 0x2a0]
// 004bfc90  48                   dec eax
// 004bfc91  50                   push eax
// 004bfc92  8bcd                 mov ecx, ebp
// 004bfc94  e8f7dcffff           call 0x4bd990
// 004bfc99  8b0e                 mov ecx, dword ptr [esi]
// 004bfc9b  51                   push ecx
// 004bfc9c  e8d9091e00           call 0x6a067a
// 004bfca1  56                   push esi
// 004bfca2  e8d3091e00           call 0x6a067a
// 004bfca7  8b742418             mov esi, dword ptr [esp + 0x18]
// 004bfcab  83c408               add esp, 8
// 004bfcae  eb31                 jmp 0x4bfce1
// 004bfcb0  8b11                 mov edx, dword ptr [ecx]
// 004bfcb2  8a0b                 mov cl, byte ptr [ebx]
// 004bfcb4  33c0                 xor eax, eax
// 004bfcb6  380a                 cmp byte ptr [edx], cl
// 004bfcb8  7514                 jne 0x4bfcce
// 004bfcba  8d9b00000000         lea ebx, [ebx]
// 004bfcc0  84c9                 test cl, cl
// 004bfcc2  7440                 je 0x4bfd04
// 004bfcc4  8a4c1801             mov cl, byte ptr [eax + ebx + 1]
// 004bfcc8  40                   inc eax
// 004bfcc9  380c02               cmp byte ptr [edx + eax], cl
// 004bfccc  74f2                 je 0x4bfcc0
// 004bfcce  8a1402               mov dl, byte ptr [edx + eax]
// 004bfcd1  84d2                 test dl, dl
// 004bfcd3  740b                 je 0x4bfce0
// 004bfcd5  803c1800             cmp byte ptr [eax + ebx], 0
// 004bfcd9  7405                 je 0x4bfce0
// 004bfcdb  80fa2a               cmp dl, 0x2a
// 004bfcde  7424                 je 0x4bfd04
// 004bfce0  47                   inc edi
// 004bfce1  3bbea0020000         cmp edi, dword ptr [esi + 0x2a0]
// 004bfce7  0f8273ffffff         jb 0x4bfc60
// 004bfced  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 004bfcf1  8bcd                 mov ecx, ebp
// 004bfcf3  e8a8420100           call 0x4d3fa0
// 004bfcf8  5d                   pop ebp
// 004bfcf9  5f                   pop edi
// 004bfcfa  5e                   pop esi
// 004bfcfb  32c0                 xor al, al
// 004bfcfd  5b                   pop ebx
// 004bfcfe  83c408               add esp, 8
// 004bfd01  c20400               ret 4
// 004bfd04  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004bfd08  e893420100           call 0x4d3fa0
// 004bfd0d  5d                   pop ebp
// 004bfd0e  5f                   pop edi
// 004bfd0f  5e                   pop esi
// 004bfd10  b001                 mov al, 1
// 004bfd12  5b                   pop ebx
// 004bfd13  83c408               add esp, 8
// 004bfd16  c20400               ret 4
// 004bfd19  5e                   pop esi
// 004bfd1a  32c0                 xor al, al
// 004bfd1c  5b                   pop ebx
// 004bfd1d  83c408               add esp, 8
// 004bfd20  c20400               ret 4
// library openrbx-raknet/RakPeer.cpp (function ?IsBanned@RakPeer@@UAE_NPBD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
