// from server: 100% by auto
// roc 2009-06 004b99b0  unit: RBX::Network::Player  size: 386 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004b99b0
//
// 004b99b0  56                   push esi
// 004b99b1  57                   push edi
// 004b99b2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004b99b6  8bf1                 mov esi, ecx
// 004b99b8  3bf7                 cmp esi, edi
// 004b99ba  0f846b010000         je 0x4b9b2b
// 004b99c0  8b470c               mov eax, dword ptr [edi + 0xc]
// 004b99c3  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004b99c6  2bc8                 sub ecx, eax
// 004b99c8  b893244992           mov eax, 0x92492493
// 004b99cd  f7e9                 imul ecx
// 004b99cf  03d1                 add edx, ecx
// 004b99d1  55                   push ebp
// 004b99d2  c1fa04               sar edx, 4
// 004b99d5  8bea                 mov ebp, edx
// 004b99d7  c1ed1f               shr ebp, 0x1f
// 004b99da  03ea                 add ebp, edx
// 004b99dc  750f                 jne 0x4b99ed
// 004b99de  8bce                 mov ecx, esi
// 004b99e0  e85bf5ffff           call 0x4b8f40
// 004b99e5  5d                   pop ebp
// 004b99e6  5f                   pop edi
// 004b99e7  8bc6                 mov eax, esi
// 004b99e9  5e                   pop esi
// 004b99ea  c20400               ret 4
// 004b99ed  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004b99f0  53                   push ebx
// 004b99f1  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004b99f4  2bcb                 sub ecx, ebx
// 004b99f6  b893244992           mov eax, 0x92492493
// 004b99fb  f7e9                 imul ecx
// 004b99fd  03d1                 add edx, ecx
// 004b99ff  c1fa04               sar edx, 4
// 004b9a02  8bca                 mov ecx, edx
// 004b9a04  c1e91f               shr ecx, 0x1f
// 004b9a07  03ca                 add ecx, edx
// 004b9a09  3be9                 cmp ebp, ecx
// 004b9a0b  7765                 ja 0x4b9a72
// 004b9a0d  c644241400           mov byte ptr [esp + 0x14], 0
// 004b9a12  8b442414             mov eax, dword ptr [esp + 0x14]
// 004b9a16  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004b9a1a  8b542414             mov edx, dword ptr [esp + 0x14]
// 004b9a1e  50                   push eax
// 004b9a1f  8b4710               mov eax, dword ptr [edi + 0x10]
// 004b9a22  51                   push ecx
// 004b9a23  52                   push edx
// 004b9a24  53                   push ebx
// 004b9a25  50                   push eax
// 004b9a26  8b470c               mov eax, dword ptr [edi + 0xc]
// 004b9a29  50                   push eax
// 004b9a2a  e8b161f8ff           call 0x43fbe0
// 004b9a2f  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004b9a32  83c418               add esp, 0x18
// 004b9a35  51                   push ecx
// 004b9a36  50                   push eax
// 004b9a37  8bce                 mov ecx, esi
// 004b9a39  e862e7f5ff           call 0x4181a0
// 004b9a3e  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004b9a41  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 004b9a44  b893244992           mov eax, 0x92492493
// 004b9a49  f7e9                 imul ecx
// 004b9a4b  03d1                 add edx, ecx
// 004b9a4d  c1fa04               sar edx, 4
// 004b9a50  8bc2                 mov eax, edx
// 004b9a52  c1e81f               shr eax, 0x1f
// 004b9a55  03c2                 add eax, edx
// 004b9a57  8d14c500000000       lea edx, [eax*8]
// 004b9a5e  2bd0                 sub edx, eax
// 004b9a60  8b460c               mov eax, dword ptr [esi + 0xc]
// 004b9a63  5b                   pop ebx
// 004b9a64  5d                   pop ebp
// 004b9a65  8d0c90               lea ecx, [eax + edx*4]
// 004b9a68  5f                   pop edi
// 004b9a69  894e10               mov dword ptr [esi + 0x10], ecx
// 004b9a6c  8bc6                 mov eax, esi
// 004b9a6e  5e                   pop esi
// 004b9a6f  c20400               ret 4
// 004b9a72  85db                 test ebx, ebx
// 004b9a74  7504                 jne 0x4b9a7a
// 004b9a76  33c0                 xor eax, eax
// 004b9a78  eb1e                 jmp 0x4b9a98
// 004b9a7a  8b5614               mov edx, dword ptr [esi + 0x14]
// 004b9a7d  2bd3                 sub edx, ebx
// 004b9a7f  89542414             mov dword ptr [esp + 0x14], edx
// 004b9a83  b893244992           mov eax, 0x92492493
// 004b9a88  f7ea                 imul edx
// 004b9a8a  03542414             add edx, dword ptr [esp + 0x14]
// 004b9a8e  c1fa04               sar edx, 4
// 004b9a91  8bc2                 mov eax, edx
// 004b9a93  c1e81f               shr eax, 0x1f
// 004b9a96  03c2                 add eax, edx
// 004b9a98  3be8                 cmp ebp, eax
// 004b9a9a  7736                 ja 0x4b9ad2
// 004b9a9c  8b470c               mov eax, dword ptr [edi + 0xc]
// 004b9a9f  8d14cd00000000       lea edx, [ecx*8]
// 004b9aa6  2bd1                 sub edx, ecx
// 004b9aa8  8d2c90               lea ebp, [eax + edx*4]
// 004b9aab  53                   push ebx
// 004b9aac  55                   push ebp
// 004b9aad  50                   push eax
// 004b9aae  e82d65f8ff           call 0x43ffe0
// 004b9ab3  8b4610               mov eax, dword ptr [esi + 0x10]
// 004b9ab6  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004b9ab9  83c40c               add esp, 0xc
// 004b9abc  50                   push eax
// 004b9abd  51                   push ecx
// 004b9abe  55                   push ebp
// 004b9abf  8bce                 mov ecx, esi
// 004b9ac1  e83adfffff           call 0x4b7a00
// 004b9ac6  5b                   pop ebx
// 004b9ac7  5d                   pop ebp
// 004b9ac8  894610               mov dword ptr [esi + 0x10], eax
// 004b9acb  5f                   pop edi
// 004b9acc  8bc6                 mov eax, esi
// 004b9ace  5e                   pop esi
// 004b9acf  c20400               ret 4
// 004b9ad2  85db                 test ebx, ebx
// 004b9ad4  7418                 je 0x4b9aee
// 004b9ad6  8b4610               mov eax, dword ptr [esi + 0x10]
// 004b9ad9  50                   push eax
// 004b9ada  53                   push ebx
// 004b9adb  8bce                 mov ecx, esi
// 004b9add  e8bee6f5ff           call 0x4181a0
// 004b9ae2  8b560c               mov edx, dword ptr [esi + 0xc]
// 004b9ae5  52                   push edx
// 004b9ae6  e847ef2500           call 0x718a32
// 004b9aeb  83c404               add esp, 4
// 004b9aee  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004b9af1  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 004b9af4  b893244992           mov eax, 0x92492493
// 004b9af9  f7e9                 imul ecx
// 004b9afb  03d1                 add edx, ecx
// 004b9afd  c1fa04               sar edx, 4
// 004b9b00  8bc2                 mov eax, edx
// 004b9b02  c1e81f               shr eax, 0x1f
// 004b9b05  03c2                 add eax, edx
// 004b9b07  50                   push eax
// 004b9b08  8bce                 mov ecx, esi
// 004b9b0a  e8c1a7f6ff           call 0x4242d0
// 004b9b0f  84c0                 test al, al
// 004b9b11  7416                 je 0x4b9b29
// 004b9b13  8b460c               mov eax, dword ptr [esi + 0xc]
// 004b9b16  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004b9b19  8b570c               mov edx, dword ptr [edi + 0xc]
// 004b9b1c  50                   push eax
// 004b9b1d  51                   push ecx
// 004b9b1e  52                   push edx
// 004b9b1f  8bce                 mov ecx, esi
// 004b9b21  e8dadeffff           call 0x4b7a00
// 004b9b26  894610               mov dword ptr [esi + 0x10], eax
// 004b9b29  5b                   pop ebx
// 004b9b2a  5d                   pop ebp
// 004b9b2b  5f                   pop edi
// 004b9b2c  8bc6                 mov eax, esi
// 004b9b2e  5e                   pop esi
// 004b9b2f  c20400               ret 4
// standard library vector<string> (function ??4?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEAAV01@ABV01@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
