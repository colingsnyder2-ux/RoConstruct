// from server: 100% by auto
// roc 2010-06 00704b30  unit: RBX::VInstance::?$NonFactoryProduct  size: 311 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00704b30
//
// 00704b30  56                   push esi
// 00704b31  57                   push edi
// 00704b32  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00704b36  8bf1                 mov esi, ecx
// 00704b38  3bf7                 cmp esi, edi
// 00704b3a  0f8420010000         je 0x704c60
// 00704b40  8b470c               mov eax, dword ptr [edi + 0xc]
// 00704b43  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00704b46  2bc8                 sub ecx, eax
// 00704b48  b8398ee338           mov eax, 0x38e38e39
// 00704b4d  f7e9                 imul ecx
// 00704b4f  55                   push ebp
// 00704b50  c1fa03               sar edx, 3
// 00704b53  8bea                 mov ebp, edx
// 00704b55  c1ed1f               shr ebp, 0x1f
// 00704b58  03ea                 add ebp, edx
// 00704b5a  750f                 jne 0x704b6b
// 00704b5c  8bce                 mov ecx, esi
// 00704b5e  e8ddfeffff           call 0x704a40
// 00704b63  5d                   pop ebp
// 00704b64  5f                   pop edi
// 00704b65  8bc6                 mov eax, esi
// 00704b67  5e                   pop esi
// 00704b68  c20400               ret 4
// 00704b6b  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00704b6e  53                   push ebx
// 00704b6f  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00704b72  2bcb                 sub ecx, ebx
// 00704b74  b8398ee338           mov eax, 0x38e38e39
// 00704b79  f7e9                 imul ecx
// 00704b7b  c1fa03               sar edx, 3
// 00704b7e  8bca                 mov ecx, edx
// 00704b80  c1e91f               shr ecx, 0x1f
// 00704b83  03ca                 add ecx, edx
// 00704b85  3be9                 cmp ebp, ecx
// 00704b87  773d                 ja 0x704bc6
// 00704b89  8b4710               mov eax, dword ptr [edi + 0x10]
// 00704b8c  53                   push ebx
// 00704b8d  50                   push eax
// 00704b8e  8b470c               mov eax, dword ptr [edi + 0xc]
// 00704b91  50                   push eax
// 00704b92  e819f6ffff           call 0x7041b0
// 00704b97  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00704b9a  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 00704b9d  b8398ee338           mov eax, 0x38e38e39
// 00704ba2  f7e9                 imul ecx
// 00704ba4  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00704ba7  c1fa03               sar edx, 3
// 00704baa  83c40c               add esp, 0xc
// 00704bad  8bc2                 mov eax, edx
// 00704baf  c1e81f               shr eax, 0x1f
// 00704bb2  03c2                 add eax, edx
// 00704bb4  5b                   pop ebx
// 00704bb5  8d04c0               lea eax, [eax + eax*8]
// 00704bb8  5d                   pop ebp
// 00704bb9  8d1481               lea edx, [ecx + eax*4]
// 00704bbc  5f                   pop edi
// 00704bbd  895610               mov dword ptr [esi + 0x10], edx
// 00704bc0  8bc6                 mov eax, esi
// 00704bc2  5e                   pop esi
// 00704bc3  c20400               ret 4
// 00704bc6  85db                 test ebx, ebx
// 00704bc8  7504                 jne 0x704bce
// 00704bca  33c0                 xor eax, eax
// 00704bcc  eb16                 jmp 0x704be4
// 00704bce  8b5614               mov edx, dword ptr [esi + 0x14]
// 00704bd1  2bd3                 sub edx, ebx
// 00704bd3  b8398ee338           mov eax, 0x38e38e39
// 00704bd8  f7ea                 imul edx
// 00704bda  c1fa03               sar edx, 3
// 00704bdd  8bc2                 mov eax, edx
// 00704bdf  c1e81f               shr eax, 0x1f
// 00704be2  03c2                 add eax, edx
// 00704be4  3be8                 cmp ebp, eax
// 00704be6  7730                 ja 0x704c18
// 00704be8  8b470c               mov eax, dword ptr [edi + 0xc]
// 00704beb  8d0cc9               lea ecx, [ecx + ecx*8]
// 00704bee  8d2c88               lea ebp, [eax + ecx*4]
// 00704bf1  53                   push ebx
// 00704bf2  55                   push ebp
// 00704bf3  50                   push eax
// 00704bf4  e8b7f5ffff           call 0x7041b0
// 00704bf9  8b5610               mov edx, dword ptr [esi + 0x10]
// 00704bfc  8b4710               mov eax, dword ptr [edi + 0x10]
// 00704bff  83c40c               add esp, 0xc
// 00704c02  52                   push edx
// 00704c03  50                   push eax
// 00704c04  55                   push ebp
// 00704c05  8bce                 mov ecx, esi
// 00704c07  e8f4fcffff           call 0x704900
// 00704c0c  5b                   pop ebx
// 00704c0d  5d                   pop ebp
// 00704c0e  894610               mov dword ptr [esi + 0x10], eax
// 00704c11  5f                   pop edi
// 00704c12  8bc6                 mov eax, esi
// 00704c14  5e                   pop esi
// 00704c15  c20400               ret 4
// 00704c18  85db                 test ebx, ebx
// 00704c1a  7409                 je 0x704c25
// 00704c1c  53                   push ebx
// 00704c1d  e8782d0a00           call 0x7a799a
// 00704c22  83c404               add esp, 4
// 00704c25  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00704c28  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 00704c2b  b8398ee338           mov eax, 0x38e38e39
// 00704c30  f7e9                 imul ecx
// 00704c32  c1fa03               sar edx, 3
// 00704c35  8bc2                 mov eax, edx
// 00704c37  c1e81f               shr eax, 0x1f
// 00704c3a  03c2                 add eax, edx
// 00704c3c  50                   push eax
// 00704c3d  8bce                 mov ecx, esi
// 00704c3f  e84cf4ffff           call 0x704090
// 00704c44  84c0                 test al, al
// 00704c46  7416                 je 0x704c5e
// 00704c48  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00704c4b  8b5710               mov edx, dword ptr [edi + 0x10]
// 00704c4e  8b470c               mov eax, dword ptr [edi + 0xc]
// 00704c51  51                   push ecx
// 00704c52  52                   push edx
// 00704c53  50                   push eax
// 00704c54  8bce                 mov ecx, esi
// 00704c56  e8a5fcffff           call 0x704900
// 00704c5b  894610               mov dword ptr [esi + 0x10], eax
// 00704c5e  5b                   pop ebx
// 00704c5f  5d                   pop ebp
// 00704c60  5f                   pop edi
// 00704c61  8bc6                 mov eax, esi
// 00704c63  5e                   pop esi
// 00704c64  c20400               ret 4
// library ogre-1.6.4/OgreBillboardChain.cpp (function ??4?$vector@VElement@BillboardChain@Ogre@@V?$allocator@VElement@BillboardChain@Ogre@@@std@@@std@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreBillboardChain.cpp
