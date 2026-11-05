// from server: 100% by auto
// roc 2010-06 00975ac0  unit: RBX::RightAngleRampBuilder  size: 326 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00975ac0
//
// 00975ac0  56                   push esi
// 00975ac1  57                   push edi
// 00975ac2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00975ac6  8bf1                 mov esi, ecx
// 00975ac8  3bf7                 cmp esi, edi
// 00975aca  0f842f010000         je 0x975bff
// 00975ad0  8b470c               mov eax, dword ptr [edi + 0xc]
// 00975ad3  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00975ad6  2bc8                 sub ecx, eax
// 00975ad8  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00975add  f7e9                 imul ecx
// 00975adf  55                   push ebp
// 00975ae0  d1fa                 sar edx, 1
// 00975ae2  8bea                 mov ebp, edx
// 00975ae4  c1ed1f               shr ebp, 0x1f
// 00975ae7  03ea                 add ebp, edx
// 00975ae9  750f                 jne 0x975afa
// 00975aeb  8bce                 mov ecx, esi
// 00975aed  e84effffff           call 0x975a40
// 00975af2  5d                   pop ebp
// 00975af3  5f                   pop edi
// 00975af4  8bc6                 mov eax, esi
// 00975af6  5e                   pop esi
// 00975af7  c20400               ret 4
// 00975afa  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00975afd  53                   push ebx
// 00975afe  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00975b01  2bcb                 sub ecx, ebx
// 00975b03  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00975b08  f7e9                 imul ecx
// 00975b0a  d1fa                 sar edx, 1
// 00975b0c  8bca                 mov ecx, edx
// 00975b0e  c1e91f               shr ecx, 0x1f
// 00975b11  03ca                 add ecx, edx
// 00975b13  3be9                 cmp ebp, ecx
// 00975b15  7750                 ja 0x975b67
// 00975b17  c644241400           mov byte ptr [esp + 0x14], 0
// 00975b1c  8b442414             mov eax, dword ptr [esp + 0x14]
// 00975b20  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00975b24  8b542414             mov edx, dword ptr [esp + 0x14]
// 00975b28  50                   push eax
// 00975b29  8b4710               mov eax, dword ptr [edi + 0x10]
// 00975b2c  51                   push ecx
// 00975b2d  52                   push edx
// 00975b2e  53                   push ebx
// 00975b2f  50                   push eax
// 00975b30  8b470c               mov eax, dword ptr [edi + 0xc]
// 00975b33  50                   push eax
// 00975b34  e8b79af6ff           call 0x8df5f0
// 00975b39  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00975b3c  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 00975b3f  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00975b44  f7e9                 imul ecx
// 00975b46  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00975b49  d1fa                 sar edx, 1
// 00975b4b  83c418               add esp, 0x18
// 00975b4e  8bc2                 mov eax, edx
// 00975b50  c1e81f               shr eax, 0x1f
// 00975b53  03c2                 add eax, edx
// 00975b55  5b                   pop ebx
// 00975b56  8d0440               lea eax, [eax + eax*2]
// 00975b59  5d                   pop ebp
// 00975b5a  8d1481               lea edx, [ecx + eax*4]
// 00975b5d  5f                   pop edi
// 00975b5e  895610               mov dword ptr [esi + 0x10], edx
// 00975b61  8bc6                 mov eax, esi
// 00975b63  5e                   pop esi
// 00975b64  c20400               ret 4
// 00975b67  85db                 test ebx, ebx
// 00975b69  7504                 jne 0x975b6f
// 00975b6b  33c0                 xor eax, eax
// 00975b6d  eb15                 jmp 0x975b84
// 00975b6f  8b5614               mov edx, dword ptr [esi + 0x14]
// 00975b72  2bd3                 sub edx, ebx
// 00975b74  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00975b79  f7ea                 imul edx
// 00975b7b  d1fa                 sar edx, 1
// 00975b7d  8bc2                 mov eax, edx
// 00975b7f  c1e81f               shr eax, 0x1f
// 00975b82  03c2                 add eax, edx
// 00975b84  3be8                 cmp ebp, eax
// 00975b86  7730                 ja 0x975bb8
// 00975b88  8b470c               mov eax, dword ptr [edi + 0xc]
// 00975b8b  8d0c49               lea ecx, [ecx + ecx*2]
// 00975b8e  8d2c88               lea ebp, [eax + ecx*4]
// 00975b91  53                   push ebx
// 00975b92  55                   push ebp
// 00975b93  50                   push eax
// 00975b94  e857fdffff           call 0x9758f0
// 00975b99  8b5610               mov edx, dword ptr [esi + 0x10]
// 00975b9c  8b4710               mov eax, dword ptr [edi + 0x10]
// 00975b9f  83c40c               add esp, 0xc
// 00975ba2  52                   push edx
// 00975ba3  50                   push eax
// 00975ba4  55                   push ebp
// 00975ba5  8bce                 mov ecx, esi
// 00975ba7  e8f4fdffff           call 0x9759a0
// 00975bac  5b                   pop ebx
// 00975bad  5d                   pop ebp
// 00975bae  894610               mov dword ptr [esi + 0x10], eax
// 00975bb1  5f                   pop edi
// 00975bb2  8bc6                 mov eax, esi
// 00975bb4  5e                   pop esi
// 00975bb5  c20400               ret 4
// 00975bb8  85db                 test ebx, ebx
// 00975bba  7409                 je 0x975bc5
// 00975bbc  53                   push ebx
// 00975bbd  e8d81de3ff           call 0x7a799a
// 00975bc2  83c404               add esp, 4
// 00975bc5  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00975bc8  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 00975bcb  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00975bd0  f7e9                 imul ecx
// 00975bd2  d1fa                 sar edx, 1
// 00975bd4  8bc2                 mov eax, edx
// 00975bd6  c1e81f               shr eax, 0x1f
// 00975bd9  03c2                 add eax, edx
// 00975bdb  50                   push eax
// 00975bdc  8bce                 mov ecx, esi
// 00975bde  e81de1baff           call 0x523d00
// 00975be3  84c0                 test al, al
// 00975be5  7416                 je 0x975bfd
// 00975be7  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00975bea  8b5710               mov edx, dword ptr [edi + 0x10]
// 00975bed  8b470c               mov eax, dword ptr [edi + 0xc]
// 00975bf0  51                   push ecx
// 00975bf1  52                   push edx
// 00975bf2  50                   push eax
// 00975bf3  8bce                 mov ecx, esi
// 00975bf5  e8a6fdffff           call 0x9759a0
// 00975bfa  894610               mov dword ptr [esi + 0x10], eax
// 00975bfd  5b                   pop ebx
// 00975bfe  5d                   pop ebp
// 00975bff  5f                   pop edi
// 00975c00  8bc6                 mov eax, esi
// 00975c02  5e                   pop esi
// 00975c03  c20400               ret 4
// standard library vector<pod12> (function ??4?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEAAV01@ABV01@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
