// from server: 100% by auto
// roc 2012-06 0065bd30  unit: seg_00650000  size: 502 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0065bd30
//
// 0065bd30  56                   push esi
// 0065bd31  8b742408             mov esi, dword ptr [esp + 8]
// 0065bd35  8b4668               mov eax, dword ptr [esi + 0x68]
// 0065bd38  a801                 test al, 1
// 0065bd3a  750d                 jne 0x65bd49
// 0065bd3c  68a0a7b800           push 0xb8a7a0
// 0065bd41  56                   push esi
// 0065bd42  e86924ffff           call 0x64e1b0
// 0065bd47  eb2e                 jmp 0x65bd77
// 0065bd49  a804                 test al, 4
// 0065bd4b  741b                 je 0x65bd68
// 0065bd4d  6888a7b800           push 0xb8a788
// 0065bd52  56                   push esi
// 0065bd53  e80825ffff           call 0x64e260
// 0065bd58  8b442418             mov eax, dword ptr [esp + 0x18]
// 0065bd5c  50                   push eax
// 0065bd5d  56                   push esi
// 0065bd5e  e8edf1ffff           call 0x65af50
// 0065bd63  83c410               add esp, 0x10
// 0065bd66  5e                   pop esi
// 0065bd67  c3                   ret 
// 0065bd68  a802                 test al, 2
// 0065bd6a  740e                 je 0x65bd7a
// 0065bd6c  6870a7b800           push 0xb8a770
// 0065bd71  56                   push esi
// 0065bd72  e8e924ffff           call 0x64e260
// 0065bd77  83c408               add esp, 8
// 0065bd7a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0065bd7e  53                   push ebx
// 0065bd7f  33db                 xor ebx, ebx
// 0065bd81  3bc3                 cmp eax, ebx
// 0065bd83  7425                 je 0x65bdaa
// 0065bd85  f7400800100000       test dword ptr [eax + 8], 0x1000
// 0065bd8c  741c                 je 0x65bdaa
// 0065bd8e  6858a7b800           push 0xb8a758
// 0065bd93  56                   push esi
// 0065bd94  e8c724ffff           call 0x64e260
// 0065bd99  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0065bd9d  51                   push ecx
// 0065bd9e  56                   push esi
// 0065bd9f  e8acf1ffff           call 0x65af50
// 0065bda4  83c410               add esp, 0x10
// 0065bda7  5b                   pop ebx
// 0065bda8  5e                   pop esi
// 0065bda9  c3                   ret 
// 0065bdaa  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0065bdb0  55                   push ebp
// 0065bdb1  57                   push edi
// 0065bdb2  52                   push edx
// 0065bdb3  56                   push esi
// 0065bdb4  e86727ffff           call 0x64e520
// 0065bdb9  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0065bdbd  8d4501               lea eax, [ebp + 1]
// 0065bdc0  50                   push eax
// 0065bdc1  56                   push esi
// 0065bdc2  e8f926ffff           call 0x64e4c0
// 0065bdc7  8bf8                 mov edi, eax
// 0065bdc9  55                   push ebp
// 0065bdca  57                   push edi
// 0065bdcb  56                   push esi
// 0065bdcc  89be88020000         mov dword ptr [esi + 0x288], edi
// 0065bdd2  e81920ffff           call 0x64ddf0
// 0065bdd7  55                   push ebp
// 0065bdd8  57                   push edi
// 0065bdd9  56                   push esi
// 0065bdda  e8b120feff           call 0x63de90
// 0065bddf  53                   push ebx
// 0065bde0  56                   push esi
// 0065bde1  e86af1ffff           call 0x65af50
// 0065bde6  83c430               add esp, 0x30
// 0065bde9  85c0                 test eax, eax
// 0065bdeb  741b                 je 0x65be08
// 0065bded  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 0065bdf3  51                   push ecx
// 0065bdf4  56                   push esi
// 0065bdf5  e82627ffff           call 0x64e520
// 0065bdfa  83c408               add esp, 8
// 0065bdfd  5f                   pop edi
// 0065bdfe  5d                   pop ebp
// 0065bdff  899e88020000         mov dword ptr [esi + 0x288], ebx
// 0065be05  5b                   pop ebx
// 0065be06  5e                   pop esi
// 0065be07  c3                   ret 
// 0065be08  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0065be0e  881c2a               mov byte ptr [edx + ebp], bl
// 0065be11  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0065be17  8bf8                 mov edi, eax
// 0065be19  381f                 cmp byte ptr [edi], bl
// 0065be1b  7408                 je 0x65be25
// 0065be1d  8d4900               lea ecx, [ecx]
// 0065be20  47                   inc edi
// 0065be21  381f                 cmp byte ptr [edi], bl
// 0065be23  75fb                 jne 0x65be20
// 0065be25  47                   inc edi
// 0065be26  8d4c28ff             lea ecx, [eax + ebp - 1]
// 0065be2a  3bf9                 cmp edi, ecx
// 0065be2c  7220                 jb 0x65be4e
// 0065be2e  50                   push eax
// 0065be2f  56                   push esi
// 0065be30  e8eb26ffff           call 0x64e520
// 0065be35  6840a7b800           push 0xb8a740
// 0065be3a  56                   push esi
// 0065be3b  899e88020000         mov dword ptr [esi + 0x288], ebx
// 0065be41  e81a24ffff           call 0x64e260
// 0065be46  83c410               add esp, 0x10
// 0065be49  5f                   pop edi
// 0065be4a  5d                   pop ebp
// 0065be4b  5b                   pop ebx
// 0065be4c  5e                   pop esi
// 0065be4d  c3                   ret 
// 0065be4e  8a07                 mov al, byte ptr [edi]
// 0065be50  47                   inc edi
// 0065be51  84c0                 test al, al
// 0065be53  7410                 je 0x65be65
// 0065be55  6810a7b800           push 0xb8a710
// 0065be5a  56                   push esi
// 0065be5b  e80024ffff           call 0x64e260
// 0065be60  83c408               add esp, 8
// 0065be63  32c0                 xor al, al
// 0065be65  2bbe88020000         sub edi, dword ptr [esi + 0x288]
// 0065be6b  8d542414             lea edx, [esp + 0x14]
// 0065be6f  52                   push edx
// 0065be70  57                   push edi
// 0065be71  0fb6d8               movzx ebx, al
// 0065be74  55                   push ebp
// 0065be75  53                   push ebx
// 0065be76  56                   push esi
// 0065be77  e814e0ffff           call 0x659e90
// 0065be7c  8b442428             mov eax, dword ptr [esp + 0x28]
// 0065be80  8bc8                 mov ecx, eax
// 0065be82  83c414               add esp, 0x14
// 0065be85  2bcf                 sub ecx, edi
// 0065be87  3bf8                 cmp edi, eax
// 0065be89  7771                 ja 0x65befc
// 0065be8b  83f904               cmp ecx, 4
// 0065be8e  726c                 jb 0x65befc
// 0065be90  8bae88020000         mov ebp, dword ptr [esi + 0x288]
// 0065be96  0fb6042f             movzx eax, byte ptr [edi + ebp]
// 0065be9a  8d142f               lea edx, [edi + ebp]
// 0065be9d  0fb67a01             movzx edi, byte ptr [edx + 1]
// 0065bea1  c1e008               shl eax, 8
// 0065bea4  0bc7                 or eax, edi
// 0065bea6  0fb67a02             movzx edi, byte ptr [edx + 2]
// 0065beaa  c1e008               shl eax, 8
// 0065bead  0bc7                 or eax, edi
// 0065beaf  0fb67a03             movzx edi, byte ptr [edx + 3]
// 0065beb3  c1e008               shl eax, 8
// 0065beb6  0bc7                 or eax, edi
// 0065beb8  3bc1                 cmp eax, ecx
// 0065beba  7330                 jae 0x65beec
// 0065bebc  8bc8                 mov ecx, eax
// 0065bebe  8b442418             mov eax, dword ptr [esp + 0x18]
// 0065bec2  51                   push ecx
// 0065bec3  52                   push edx
// 0065bec4  53                   push ebx
// 0065bec5  55                   push ebp
// 0065bec6  50                   push eax
// 0065bec7  56                   push esi
// 0065bec8  e833b1feff           call 0x647000
// 0065becd  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 0065bed3  51                   push ecx
// 0065bed4  56                   push esi
// 0065bed5  e84626ffff           call 0x64e520
// 0065beda  83c420               add esp, 0x20
// 0065bedd  5f                   pop edi
// 0065bede  5d                   pop ebp
// 0065bedf  5b                   pop ebx
// 0065bee0  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 0065beea  5e                   pop esi
// 0065beeb  c3                   ret 
// 0065beec  76d0                 jbe 0x65bebe
// 0065beee  55                   push ebp
// 0065beef  56                   push esi
// 0065bef0  e82b26ffff           call 0x64e520
// 0065bef5  68eca6b800           push 0xb8a6ec
// 0065befa  eb12                 jmp 0x65bf0e
// 0065befc  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0065bf02  52                   push edx
// 0065bf03  56                   push esi
// 0065bf04  e81726ffff           call 0x64e520
// 0065bf09  68c0a6b800           push 0xb8a6c0
// 0065bf0e  56                   push esi
// 0065bf0f  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 0065bf19  e84223ffff           call 0x64e260
// 0065bf1e  83c410               add esp, 0x10
// 0065bf21  5f                   pop edi
// 0065bf22  5d                   pop ebp
// 0065bf23  5b                   pop ebx
// 0065bf24  5e                   pop esi
// 0065bf25  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_iCCP)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
