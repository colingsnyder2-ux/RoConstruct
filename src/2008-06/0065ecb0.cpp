// from server: 100% by auto
// roc 2008-06 0065ecb0  unit: seg_00650000  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065ecb0
//
// 0065ecb0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0065ecb4  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 0065ecb7  56                   push esi
// 0065ecb8  85c0                 test eax, eax
// 0065ecba  763c                 jbe 0x65ecf8
// 0065ecbc  8b710c               mov esi, dword ptr [ecx + 0xc]
// 0065ecbf  8bd0                 mov edx, eax
// 0065ecc1  c1e204               shl edx, 4
// 0065ecc4  837c32f800           cmp dword ptr [edx + esi - 8], 0
// 0065ecc9  752d                 jne 0x65ecf8
// 0065eccb  33d2                 xor edx, edx
// 0065eccd  83f801               cmp eax, 1
// 0065ecd0  7622                 jbe 0x65ecf4
// 0065ecd2  57                   push edi
// 0065ecd3  8d0c02               lea ecx, [edx + eax]
// 0065ecd6  d1e9                 shr ecx, 1
// 0065ecd8  8bf9                 mov edi, ecx
// 0065ecda  c1e704               shl edi, 4
// 0065ecdd  837c37f800           cmp dword ptr [edi + esi - 8], 0
// 0065ece2  7504                 jne 0x65ece8
// 0065ece4  8bc1                 mov eax, ecx
// 0065ece6  eb02                 jmp 0x65ecea
// 0065ece8  8bd1                 mov edx, ecx
// 0065ecea  8bc8                 mov ecx, eax
// 0065ecec  2bca                 sub ecx, edx
// 0065ecee  83f901               cmp ecx, 1
// 0065ecf1  77e0                 ja 0x65ecd3
// 0065ecf3  5f                   pop edi
// 0065ecf4  8bc2                 mov eax, edx
// 0065ecf6  5e                   pop esi
// 0065ecf7  c3                   ret 
// 0065ecf8  817910d0c38400       cmp dword ptr [ecx + 0x10], 0x84c3d0
// 0065ecff  74f5                 je 0x65ecf6
// 0065ed01  5e                   pop esi
// 0065ed02  894c2404             mov dword ptr [esp + 4], ecx
// 0065ed06  e905ffffff           jmp 0x65ec10
// library lua-5.1/ltable.c (function _luaH_getn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
