// from server: 100% by auto
// roc 2007-08 004cbdb0  unit: CSHA1  size: 350 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004cbdb0
//
// 004cbdb0  83ec14               sub esp, 0x14
// 004cbdb3  53                   push ebx
// 004cbdb4  55                   push ebp
// 004cbdb5  56                   push esi
// 004cbdb6  57                   push edi
// 004cbdb7  894c2414             mov dword ptr [esp + 0x14], ecx
// 004cbdbb  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004cbdc3  66c744241871d9       mov word ptr [esp + 0x18], 0xd971
// 004cbdca  66c744241a6dce       mov word ptr [esp + 0x1a], 0xce6d
// 004cbdd1  66c744241cbf58       mov word ptr [esp + 0x1c], 0x58bf
// 004cbdd8  e863e5ffff           call 0x4ca340
// 004cbddd  88442412             mov byte ptr [esp + 0x12], al
// 004cbde1  8a44242c             mov al, byte ptr [esp + 0x2c]
// 004cbde5  0405                 add al, 5
// 004cbde7  240f                 and al, 0xf
// 004cbde9  b30f                 mov bl, 0xf
// 004cbdeb  2ad8                 sub bl, al
// 004cbded  e84ee5ffff           call 0x4ca340
// 004cbdf2  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004cbdf6  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 004cbdfa  8b542434             mov edx, dword ptr [esp + 0x34]
// 004cbdfe  c0e004               shl al, 4
// 004cbe01  0ac3                 or al, bl
// 004cbe03  0fb6f3               movzx esi, bl
// 004cbe06  88442413             mov byte ptr [esp + 0x13], al
// 004cbe0a  8b442428             mov eax, dword ptr [esp + 0x28]
// 004cbe0e  3bc5                 cmp eax, ebp
// 004cbe10  8d4c3e06             lea ecx, [esi + edi + 6]
// 004cbe14  57                   push edi
// 004cbe15  890a                 mov dword ptr [edx], ecx
// 004cbe17  50                   push eax
// 004cbe18  750d                 jne 0x4cbe27
// 004cbe1a  8d442e06             lea eax, [esi + ebp + 6]
// 004cbe1e  50                   push eax
// 004cbe1f  ff150ce97700         call dword ptr [0x77e90c]
// 004cbe25  eb0a                 jmp 0x4cbe31
// 004cbe27  8d4c2e06             lea ecx, [esi + ebp + 6]
// 004cbe2b  51                   push ecx
// 004cbe2c  e81b4f1600           call 0x630d4c
// 004cbe31  8a54241e             mov dl, byte ptr [esp + 0x1e]
// 004cbe35  8a44241f             mov al, byte ptr [esp + 0x1f]
// 004cbe39  83c40c               add esp, 0xc
// 004cbe3c  33db                 xor ebx, ebx
// 004cbe3e  85f6                 test esi, esi
// 004cbe40  885504               mov byte ptr [ebp + 4], dl
// 004cbe43  884505               mov byte ptr [ebp + 5], al
// 004cbe46  7610                 jbe 0x4cbe58
// 004cbe48  e8f3e4ffff           call 0x4ca340
// 004cbe4d  88442b06             mov byte ptr [ebx + ebp + 6], al
// 004cbe51  83c301               add ebx, 1
// 004cbe54  3bde                 cmp ebx, esi
// 004cbe56  72f0                 jb 0x4cbe48
// 004cbe58  8d4c3e02             lea ecx, [esi + edi + 2]
// 004cbe5c  51                   push ecx
// 004cbe5d  8d4504               lea eax, [ebp + 4]
// 004cbe60  50                   push eax
// 004cbe61  8d4c2420             lea ecx, [esp + 0x20]
// 004cbe65  e8f6140000           call 0x4cd360
// 004cbe6a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004cbe6e  8b542420             mov edx, dword ptr [esp + 0x20]
// 004cbe72  55                   push ebp
// 004cbe73  6a10                 push 0x10
// 004cbe75  55                   push ebp
// 004cbe76  8d8140020000         lea eax, [ecx + 0x240]
// 004cbe7c  51                   push ecx
// 004cbe7d  50                   push eax
// 004cbe7e  895500               mov dword ptr [ebp], edx
// 004cbe81  e80a0e0000           call 0x4ccc90
// 004cbe86  8b442448             mov eax, dword ptr [esp + 0x48]
// 004cbe8a  8b38                 mov edi, dword ptr [eax]
// 004cbe8c  83ef10               sub edi, 0x10
// 004cbe8f  83c414               add esp, 0x14
// 004cbe92  33f6                 xor esi, esi
// 004cbe94  83ff10               cmp edi, 0x10
// 004cbe97  726b                 jb 0x4cbf04
// 004cbe99  8d1c2f               lea ebx, [edi + ebp]
// 004cbe9c  895c242c             mov dword ptr [esp + 0x2c], ebx
// 004cbea0  8bd6                 mov edx, esi
// 004cbea2  33c9                 xor ecx, ecx
// 004cbea4  8bc3                 mov eax, ebx
// 004cbea6  2bd7                 sub edx, edi
// 004cbea8  8d742e02             lea esi, [esi + ebp + 2]
// 004cbeac  8d642400             lea esp, [esp]
// 004cbeb0  0fb61c02             movzx ebx, byte ptr [edx + eax]
// 004cbeb4  3018                 xor byte ptr [eax], bl
// 004cbeb6  0fb65c0eff           movzx ebx, byte ptr [esi + ecx - 1]
// 004cbebb  305801               xor byte ptr [eax + 1], bl
// 004cbebe  0fb61c0e             movzx ebx, byte ptr [esi + ecx]
// 004cbec2  305802               xor byte ptr [eax + 2], bl
// 004cbec5  0fb65c0e01           movzx ebx, byte ptr [esi + ecx + 1]
// 004cbeca  305803               xor byte ptr [eax + 3], bl
// 004cbecd  83c104               add ecx, 4
// 004cbed0  83c004               add eax, 4
// 004cbed3  83f910               cmp ecx, 0x10
// 004cbed6  72d8                 jb 0x4cbeb0
// 004cbed8  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 004cbedc  8b442414             mov eax, dword ptr [esp + 0x14]
// 004cbee0  53                   push ebx
// 004cbee1  6a10                 push 0x10
// 004cbee3  53                   push ebx
// 004cbee4  50                   push eax
// 004cbee5  0540020000           add eax, 0x240
// 004cbeea  50                   push eax
// 004cbeeb  e8a00d0000           call 0x4ccc90
// 004cbef0  8bf7                 mov esi, edi
// 004cbef2  83ef10               sub edi, 0x10
// 004cbef5  83eb10               sub ebx, 0x10
// 004cbef8  83c414               add esp, 0x14
// 004cbefb  83ff10               cmp edi, 0x10
// 004cbefe  895c242c             mov dword ptr [esp + 0x2c], ebx
// 004cbf02  739c                 jae 0x4cbea0
// 004cbf04  5f                   pop edi
// 004cbf05  5e                   pop esi
// 004cbf06  5d                   pop ebp
// 004cbf07  5b                   pop ebx
// 004cbf08  83c414               add esp, 0x14
// 004cbf0b  c21000               ret 0x10
// library openrbx-raknet/DataBlockEncryptor.cpp (function ?Encrypt@DataBlockEncryptor@@QAEXPAEH0PAH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DataBlockEncryptor.cpp
