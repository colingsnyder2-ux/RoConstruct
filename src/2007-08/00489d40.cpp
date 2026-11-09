// from server: 100% by auto
// roc 2007-08 00489d40  unit: RBX::Network::VPlayer::?$Notifier  size: 386 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00489d40
//
// 00489d40  55                   push ebp
// 00489d41  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00489d45  56                   push esi
// 00489d46  8bf1                 mov esi, ecx
// 00489d48  3bf5                 cmp esi, ebp
// 00489d4a  0f846b010000         je 0x489ebb
// 00489d50  8b4504               mov eax, dword ptr [ebp + 4]
// 00489d53  85c0                 test eax, eax
// 00489d55  741a                 je 0x489d71
// 00489d57  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00489d5a  2bc8                 sub ecx, eax
// 00489d5c  b893244992           mov eax, 0x92492493
// 00489d61  f7e9                 imul ecx
// 00489d63  03d1                 add edx, ecx
// 00489d65  c1fa04               sar edx, 4
// 00489d68  8bca                 mov ecx, edx
// 00489d6a  c1e91f               shr ecx, 0x1f
// 00489d6d  03ca                 add ecx, edx
// 00489d6f  750e                 jne 0x489d7f
// 00489d71  8bce                 mov ecx, esi
// 00489d73  e8e8fdffff           call 0x489b60
// 00489d78  8bc6                 mov eax, esi
// 00489d7a  5e                   pop esi
// 00489d7b  5d                   pop ebp
// 00489d7c  c20400               ret 4
// 00489d7f  53                   push ebx
// 00489d80  57                   push edi
// 00489d81  8b7e04               mov edi, dword ptr [esi + 4]
// 00489d84  85ff                 test edi, edi
// 00489d86  7504                 jne 0x489d8c
// 00489d88  33c0                 xor eax, eax
// 00489d8a  eb18                 jmp 0x489da4
// 00489d8c  8b5e08               mov ebx, dword ptr [esi + 8]
// 00489d8f  2bdf                 sub ebx, edi
// 00489d91  b893244992           mov eax, 0x92492493
// 00489d96  f7eb                 imul ebx
// 00489d98  03d3                 add edx, ebx
// 00489d9a  c1fa04               sar edx, 4
// 00489d9d  8bc2                 mov eax, edx
// 00489d9f  c1e81f               shr eax, 0x1f
// 00489da2  03c2                 add eax, edx
// 00489da4  3bc8                 cmp ecx, eax
// 00489da6  776b                 ja 0x489e13
// 00489da8  c644241400           mov byte ptr [esp + 0x14], 0
// 00489dad  8b442414             mov eax, dword ptr [esp + 0x14]
// 00489db1  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00489db5  8b542414             mov edx, dword ptr [esp + 0x14]
// 00489db9  50                   push eax
// 00489dba  8b4508               mov eax, dword ptr [ebp + 8]
// 00489dbd  51                   push ecx
// 00489dbe  52                   push edx
// 00489dbf  57                   push edi
// 00489dc0  50                   push eax
// 00489dc1  8b4504               mov eax, dword ptr [ebp + 4]
// 00489dc4  50                   push eax
// 00489dc5  e8f6b1fbff           call 0x444fc0
// 00489dca  8b4e08               mov ecx, dword ptr [esi + 8]
// 00489dcd  83c418               add esp, 0x18
// 00489dd0  51                   push ecx
// 00489dd1  50                   push eax
// 00489dd2  8bce                 mov ecx, esi
// 00489dd4  e867fcf7ff           call 0x409a40
// 00489dd9  8b4504               mov eax, dword ptr [ebp + 4]
// 00489ddc  85c0                 test eax, eax
// 00489dde  7418                 je 0x489df8
// 00489de0  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00489de3  2bc8                 sub ecx, eax
// 00489de5  b893244992           mov eax, 0x92492493
// 00489dea  f7e9                 imul ecx
// 00489dec  03d1                 add edx, ecx
// 00489dee  c1fa04               sar edx, 4
// 00489df1  8bc2                 mov eax, edx
// 00489df3  c1e81f               shr eax, 0x1f
// 00489df6  03c2                 add eax, edx
// 00489df8  8d14c500000000       lea edx, [eax*8]
// 00489dff  2bd0                 sub edx, eax
// 00489e01  8b4604               mov eax, dword ptr [esi + 4]
// 00489e04  5f                   pop edi
// 00489e05  8d0c90               lea ecx, [eax + edx*4]
// 00489e08  5b                   pop ebx
// 00489e09  894e08               mov dword ptr [esi + 8], ecx
// 00489e0c  8bc6                 mov eax, esi
// 00489e0e  5e                   pop esi
// 00489e0f  5d                   pop ebp
// 00489e10  c20400               ret 4
// 00489e13  85ff                 test edi, edi
// 00489e15  7504                 jne 0x489e1b
// 00489e17  33c0                 xor eax, eax
// 00489e19  eb18                 jmp 0x489e33
// 00489e1b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00489e1e  2bdf                 sub ebx, edi
// 00489e20  b893244992           mov eax, 0x92492493
// 00489e25  f7eb                 imul ebx
// 00489e27  03d3                 add edx, ebx
// 00489e29  c1fa04               sar edx, 4
// 00489e2c  8bc2                 mov eax, edx
// 00489e2e  c1e81f               shr eax, 0x1f
// 00489e31  03c2                 add eax, edx
// 00489e33  3bc8                 cmp ecx, eax
// 00489e35  773d                 ja 0x489e74
// 00489e37  8bce                 mov ecx, esi
// 00489e39  e8f217f9ff           call 0x41b630
// 00489e3e  8d14c500000000       lea edx, [eax*8]
// 00489e45  2bd0                 sub edx, eax
// 00489e47  8b4504               mov eax, dword ptr [ebp + 4]
// 00489e4a  8d1c90               lea ebx, [eax + edx*4]
// 00489e4d  57                   push edi
// 00489e4e  53                   push ebx
// 00489e4f  50                   push eax
// 00489e50  e8dbb3fbff           call 0x445230
// 00489e55  8b4608               mov eax, dword ptr [esi + 8]
// 00489e58  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00489e5b  83c40c               add esp, 0xc
// 00489e5e  50                   push eax
// 00489e5f  51                   push ecx
// 00489e60  53                   push ebx
// 00489e61  8bce                 mov ecx, esi
// 00489e63  e898f8ffff           call 0x489700
// 00489e68  5f                   pop edi
// 00489e69  894608               mov dword ptr [esi + 8], eax
// 00489e6c  5b                   pop ebx
// 00489e6d  8bc6                 mov eax, esi
// 00489e6f  5e                   pop esi
// 00489e70  5d                   pop ebp
// 00489e71  c20400               ret 4
// 00489e74  85ff                 test edi, edi
// 00489e76  7418                 je 0x489e90
// 00489e78  8b5608               mov edx, dword ptr [esi + 8]
// 00489e7b  52                   push edx
// 00489e7c  57                   push edi
// 00489e7d  8bce                 mov ecx, esi
// 00489e7f  e8bcfbf7ff           call 0x409a40
// 00489e84  8b4604               mov eax, dword ptr [esi + 4]
// 00489e87  50                   push eax
// 00489e88  e8d55d1a00           call 0x62fc62
// 00489e8d  83c404               add esp, 4
// 00489e90  8bcd                 mov ecx, ebp
// 00489e92  e89917f9ff           call 0x41b630
// 00489e97  50                   push eax
// 00489e98  8bce                 mov ecx, esi
// 00489e9a  e831f0f9ff           call 0x428ed0
// 00489e9f  84c0                 test al, al
// 00489ea1  7416                 je 0x489eb9
// 00489ea3  8b4e04               mov ecx, dword ptr [esi + 4]
// 00489ea6  8b5508               mov edx, dword ptr [ebp + 8]
// 00489ea9  8b4504               mov eax, dword ptr [ebp + 4]
// 00489eac  51                   push ecx
// 00489ead  52                   push edx
// 00489eae  50                   push eax
// 00489eaf  8bce                 mov ecx, esi
// 00489eb1  e84af8ffff           call 0x489700
// 00489eb6  894608               mov dword ptr [esi + 8], eax
// 00489eb9  5f                   pop edi
// 00489eba  5b                   pop ebx
// 00489ebb  8bc6                 mov eax, esi
// 00489ebd  5e                   pop esi
// 00489ebe  5d                   pop ebp
// 00489ebf  c20400               ret 4
// standard library vector<string> (function ??4?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEAAV01@ABV01@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
