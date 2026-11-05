// from server: 100% by auto
// roc 2007-08 005cdd00  unit: RBX::BlockBlockContact  size: 437 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005cdd00
//
// 005cdd00  8b442410             mov eax, dword ptr [esp + 0x10]
// 005cdd04  53                   push ebx
// 005cdd05  56                   push esi
// 005cdd06  8bf1                 mov esi, ecx
// 005cdd08  8b08                 mov ecx, dword ptr [eax]
// 005cdd0a  894c2418             mov dword ptr [esp + 0x18], ecx
// 005cdd0e  8b4e04               mov ecx, dword ptr [esi + 4]
// 005cdd11  85c9                 test ecx, ecx
// 005cdd13  57                   push edi
// 005cdd14  7504                 jne 0x5cdd1a
// 005cdd16  33ff                 xor edi, edi
// 005cdd18  eb08                 jmp 0x5cdd22
// 005cdd1a  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005cdd1d  2bf9                 sub edi, ecx
// 005cdd1f  c1ff02               sar edi, 2
// 005cdd22  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 005cdd26  85db                 test ebx, ebx
// 005cdd28  0f8481010000         je 0x5cdeaf
// 005cdd2e  85c9                 test ecx, ecx
// 005cdd30  7504                 jne 0x5cdd36
// 005cdd32  33c0                 xor eax, eax
// 005cdd34  eb08                 jmp 0x5cdd3e
// 005cdd36  8b4608               mov eax, dword ptr [esi + 8]
// 005cdd39  2bc1                 sub eax, ecx
// 005cdd3b  c1f802               sar eax, 2
// 005cdd3e  baffffff3f           mov edx, 0x3fffffff
// 005cdd43  2bd0                 sub edx, eax
// 005cdd45  3bd3                 cmp edx, ebx
// 005cdd47  7305                 jae 0x5cdd4e
// 005cdd49  e8e2efffff           call 0x5ccd30
// 005cdd4e  85c9                 test ecx, ecx
// 005cdd50  7504                 jne 0x5cdd56
// 005cdd52  33c0                 xor eax, eax
// 005cdd54  eb08                 jmp 0x5cdd5e
// 005cdd56  8b4608               mov eax, dword ptr [esi + 8]
// 005cdd59  2bc1                 sub eax, ecx
// 005cdd5b  c1f802               sar eax, 2
// 005cdd5e  03c3                 add eax, ebx
// 005cdd60  3bf8                 cmp edi, eax
// 005cdd62  55                   push ebp
// 005cdd63  0f83b4000000         jae 0x5cde1d
// 005cdd69  8bc7                 mov eax, edi
// 005cdd6b  d1e8                 shr eax, 1
// 005cdd6d  baffffff3f           mov edx, 0x3fffffff
// 005cdd72  2bd0                 sub edx, eax
// 005cdd74  3bd7                 cmp edx, edi
// 005cdd76  7304                 jae 0x5cdd7c
// 005cdd78  33ff                 xor edi, edi
// 005cdd7a  eb02                 jmp 0x5cdd7e
// 005cdd7c  03f8                 add edi, eax
// 005cdd7e  85c9                 test ecx, ecx
// 005cdd80  7504                 jne 0x5cdd86
// 005cdd82  33c0                 xor eax, eax
// 005cdd84  eb08                 jmp 0x5cdd8e
// 005cdd86  8b4608               mov eax, dword ptr [esi + 8]
// 005cdd89  2bc1                 sub eax, ecx
// 005cdd8b  c1f802               sar eax, 2
// 005cdd8e  03c3                 add eax, ebx
// 005cdd90  3bf8                 cmp edi, eax
// 005cdd92  7312                 jae 0x5cdda6
// 005cdd94  85c9                 test ecx, ecx
// 005cdd96  7504                 jne 0x5cdd9c
// 005cdd98  33ff                 xor edi, edi
// 005cdd9a  eb08                 jmp 0x5cdda4
// 005cdd9c  8b7e08               mov edi, dword ptr [esi + 8]
// 005cdd9f  2bf9                 sub edi, ecx
// 005cdda1  c1ff02               sar edi, 2
// 005cdda4  03fb                 add edi, ebx
// 005cdda6  6a00                 push 0
// 005cdda8  57                   push edi
// 005cdda9  e8b21ffeff           call 0x5afd60
// 005cddae  8b4e04               mov ecx, dword ptr [esi + 4]
// 005cddb1  83c408               add esp, 8
// 005cddb4  8be8                 mov ebp, eax
// 005cddb6  8b442418             mov eax, dword ptr [esp + 0x18]
// 005cddba  55                   push ebp
// 005cddbb  50                   push eax
// 005cddbc  51                   push ecx
// 005cddbd  8bce                 mov ecx, esi
// 005cddbf  e8dc4ffeff           call 0x5b2da0
// 005cddc4  8d542420             lea edx, [esp + 0x20]
// 005cddc8  52                   push edx
// 005cddc9  53                   push ebx
// 005cddca  50                   push eax
// 005cddcb  8bce                 mov ecx, esi
// 005cddcd  e86e89faff           call 0x576740
// 005cddd2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005cddd6  50                   push eax
// 005cddd7  8b4608               mov eax, dword ptr [esi + 8]
// 005cddda  50                   push eax
// 005cdddb  51                   push ecx
// 005cdddc  8bce                 mov ecx, esi
// 005cddde  e8bd4ffeff           call 0x5b2da0
// 005cdde3  8b4604               mov eax, dword ptr [esi + 4]
// 005cdde6  85c0                 test eax, eax
// 005cdde8  7504                 jne 0x5cddee
// 005cddea  33c9                 xor ecx, ecx
// 005cddec  eb08                 jmp 0x5cddf6
// 005cddee  8b4e08               mov ecx, dword ptr [esi + 8]
// 005cddf1  2bc8                 sub ecx, eax
// 005cddf3  c1f902               sar ecx, 2
// 005cddf6  03d9                 add ebx, ecx
// 005cddf8  85c0                 test eax, eax
// 005cddfa  7409                 je 0x5cde05
// 005cddfc  50                   push eax
// 005cddfd  e8601e0600           call 0x62fc62
// 005cde02  83c404               add esp, 4
// 005cde05  8d54bd00             lea edx, [ebp + edi*4]
// 005cde09  8d449d00             lea eax, [ebp + ebx*4]
// 005cde0d  896e04               mov dword ptr [esi + 4], ebp
// 005cde10  5d                   pop ebp
// 005cde11  5f                   pop edi
// 005cde12  89560c               mov dword ptr [esi + 0xc], edx
// 005cde15  894608               mov dword ptr [esi + 8], eax
// 005cde18  5e                   pop esi
// 005cde19  5b                   pop ebx
// 005cde1a  c21000               ret 0x10
// 005cde1d  8b6e08               mov ebp, dword ptr [esi + 8]
// 005cde20  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005cde24  8bcd                 mov ecx, ebp
// 005cde26  2bcf                 sub ecx, edi
// 005cde28  c1f902               sar ecx, 2
// 005cde2b  8d049d00000000       lea eax, [ebx*4]
// 005cde32  3bcb                 cmp ecx, ebx
// 005cde34  8944241c             mov dword ptr [esp + 0x1c], eax
// 005cde38  8bce                 mov ecx, esi
// 005cde3a  7346                 jae 0x5cde82
// 005cde3c  03c7                 add eax, edi
// 005cde3e  50                   push eax
// 005cde3f  55                   push ebp
// 005cde40  57                   push edi
// 005cde41  e85a4ffeff           call 0x5b2da0
// 005cde46  8b4608               mov eax, dword ptr [esi + 8]
// 005cde49  8bc8                 mov ecx, eax
// 005cde4b  2bcf                 sub ecx, edi
// 005cde4d  c1f902               sar ecx, 2
// 005cde50  8d542420             lea edx, [esp + 0x20]
// 005cde54  52                   push edx
// 005cde55  2bd9                 sub ebx, ecx
// 005cde57  53                   push ebx
// 005cde58  50                   push eax
// 005cde59  8bce                 mov ecx, esi
// 005cde5b  e8e088faff           call 0x576740
// 005cde60  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005cde64  014608               add dword ptr [esi + 8], eax
// 005cde67  8b7608               mov esi, dword ptr [esi + 8]
// 005cde6a  8d542420             lea edx, [esp + 0x20]
// 005cde6e  52                   push edx
// 005cde6f  2bf0                 sub esi, eax
// 005cde71  56                   push esi
// 005cde72  57                   push edi
// 005cde73  e87892fbff           call 0x5870f0
// 005cde78  83c40c               add esp, 0xc
// 005cde7b  5d                   pop ebp
// 005cde7c  5f                   pop edi
// 005cde7d  5e                   pop esi
// 005cde7e  5b                   pop ebx
// 005cde7f  c21000               ret 0x10
// 005cde82  55                   push ebp
// 005cde83  8bdd                 mov ebx, ebp
// 005cde85  2bd8                 sub ebx, eax
// 005cde87  55                   push ebp
// 005cde88  53                   push ebx
// 005cde89  e8124ffeff           call 0x5b2da0
// 005cde8e  55                   push ebp
// 005cde8f  53                   push ebx
// 005cde90  57                   push edi
// 005cde91  894608               mov dword ptr [esi + 8], eax
// 005cde94  e867120300           call 0x5ff100
// 005cde99  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005cde9d  8d44242c             lea eax, [esp + 0x2c]
// 005cdea1  50                   push eax
// 005cdea2  03cf                 add ecx, edi
// 005cdea4  51                   push ecx
// 005cdea5  57                   push edi
// 005cdea6  e84592fbff           call 0x5870f0
// 005cdeab  83c418               add esp, 0x18
// 005cdeae  5d                   pop ebp
// 005cdeaf  5f                   pop edi
// 005cdeb0  5e                   pop esi
// 005cdeb1  5b                   pop ebx
// 005cdeb2  c21000               ret 0x10
// standard library vector<ptr> (function ?_Insert_n@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@IABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
