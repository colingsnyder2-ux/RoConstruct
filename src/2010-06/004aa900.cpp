// from server: 100% by auto
// roc 2010-06 004aa900  unit: RBX::Network::Player  size: 386 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004aa900
//
// 004aa900  56                   push esi
// 004aa901  57                   push edi
// 004aa902  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004aa906  8bf1                 mov esi, ecx
// 004aa908  3bf7                 cmp esi, edi
// 004aa90a  0f846b010000         je 0x4aaa7b
// 004aa910  8b470c               mov eax, dword ptr [edi + 0xc]
// 004aa913  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004aa916  2bc8                 sub ecx, eax
// 004aa918  b893244992           mov eax, 0x92492493
// 004aa91d  f7e9                 imul ecx
// 004aa91f  03d1                 add edx, ecx
// 004aa921  55                   push ebp
// 004aa922  c1fa04               sar edx, 4
// 004aa925  8bea                 mov ebp, edx
// 004aa927  c1ed1f               shr ebp, 0x1f
// 004aa92a  03ea                 add ebp, edx
// 004aa92c  750f                 jne 0x4aa93d
// 004aa92e  8bce                 mov ecx, esi
// 004aa930  e80bf6ffff           call 0x4a9f40
// 004aa935  5d                   pop ebp
// 004aa936  5f                   pop edi
// 004aa937  8bc6                 mov eax, esi
// 004aa939  5e                   pop esi
// 004aa93a  c20400               ret 4
// 004aa93d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004aa940  53                   push ebx
// 004aa941  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004aa944  2bcb                 sub ecx, ebx
// 004aa946  b893244992           mov eax, 0x92492493
// 004aa94b  f7e9                 imul ecx
// 004aa94d  03d1                 add edx, ecx
// 004aa94f  c1fa04               sar edx, 4
// 004aa952  8bca                 mov ecx, edx
// 004aa954  c1e91f               shr ecx, 0x1f
// 004aa957  03ca                 add ecx, edx
// 004aa959  3be9                 cmp ebp, ecx
// 004aa95b  7765                 ja 0x4aa9c2
// 004aa95d  c644241400           mov byte ptr [esp + 0x14], 0
// 004aa962  8b442414             mov eax, dword ptr [esp + 0x14]
// 004aa966  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004aa96a  8b542414             mov edx, dword ptr [esp + 0x14]
// 004aa96e  50                   push eax
// 004aa96f  8b4710               mov eax, dword ptr [edi + 0x10]
// 004aa972  51                   push ecx
// 004aa973  52                   push edx
// 004aa974  53                   push ebx
// 004aa975  50                   push eax
// 004aa976  8b470c               mov eax, dword ptr [edi + 0xc]
// 004aa979  50                   push eax
// 004aa97a  e841adf9ff           call 0x4456c0
// 004aa97f  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004aa982  83c418               add esp, 0x18
// 004aa985  51                   push ecx
// 004aa986  50                   push eax
// 004aa987  8bce                 mov ecx, esi
// 004aa989  e8f2dbf6ff           call 0x418580
// 004aa98e  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004aa991  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 004aa994  b893244992           mov eax, 0x92492493
// 004aa999  f7e9                 imul ecx
// 004aa99b  03d1                 add edx, ecx
// 004aa99d  c1fa04               sar edx, 4
// 004aa9a0  8bc2                 mov eax, edx
// 004aa9a2  c1e81f               shr eax, 0x1f
// 004aa9a5  03c2                 add eax, edx
// 004aa9a7  8d14c500000000       lea edx, [eax*8]
// 004aa9ae  2bd0                 sub edx, eax
// 004aa9b0  8b460c               mov eax, dword ptr [esi + 0xc]
// 004aa9b3  5b                   pop ebx
// 004aa9b4  5d                   pop ebp
// 004aa9b5  8d0c90               lea ecx, [eax + edx*4]
// 004aa9b8  5f                   pop edi
// 004aa9b9  894e10               mov dword ptr [esi + 0x10], ecx
// 004aa9bc  8bc6                 mov eax, esi
// 004aa9be  5e                   pop esi
// 004aa9bf  c20400               ret 4
// 004aa9c2  85db                 test ebx, ebx
// 004aa9c4  7504                 jne 0x4aa9ca
// 004aa9c6  33c0                 xor eax, eax
// 004aa9c8  eb1e                 jmp 0x4aa9e8
// 004aa9ca  8b5614               mov edx, dword ptr [esi + 0x14]
// 004aa9cd  2bd3                 sub edx, ebx
// 004aa9cf  89542414             mov dword ptr [esp + 0x14], edx
// 004aa9d3  b893244992           mov eax, 0x92492493
// 004aa9d8  f7ea                 imul edx
// 004aa9da  03542414             add edx, dword ptr [esp + 0x14]
// 004aa9de  c1fa04               sar edx, 4
// 004aa9e1  8bc2                 mov eax, edx
// 004aa9e3  c1e81f               shr eax, 0x1f
// 004aa9e6  03c2                 add eax, edx
// 004aa9e8  3be8                 cmp ebp, eax
// 004aa9ea  7736                 ja 0x4aaa22
// 004aa9ec  8b470c               mov eax, dword ptr [edi + 0xc]
// 004aa9ef  8d14cd00000000       lea edx, [ecx*8]
// 004aa9f6  2bd1                 sub edx, ecx
// 004aa9f8  8d2c90               lea ebp, [eax + edx*4]
// 004aa9fb  53                   push ebx
// 004aa9fc  55                   push ebp
// 004aa9fd  50                   push eax
// 004aa9fe  e85db0f9ff           call 0x445a60
// 004aaa03  8b4610               mov eax, dword ptr [esi + 0x10]
// 004aaa06  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004aaa09  83c40c               add esp, 0xc
// 004aaa0c  50                   push eax
// 004aaa0d  51                   push ecx
// 004aaa0e  55                   push ebp
// 004aaa0f  8bce                 mov ecx, esi
// 004aaa11  e85ae5ffff           call 0x4a8f70
// 004aaa16  5b                   pop ebx
// 004aaa17  5d                   pop ebp
// 004aaa18  894610               mov dword ptr [esi + 0x10], eax
// 004aaa1b  5f                   pop edi
// 004aaa1c  8bc6                 mov eax, esi
// 004aaa1e  5e                   pop esi
// 004aaa1f  c20400               ret 4
// 004aaa22  85db                 test ebx, ebx
// 004aaa24  7418                 je 0x4aaa3e
// 004aaa26  8b4610               mov eax, dword ptr [esi + 0x10]
// 004aaa29  50                   push eax
// 004aaa2a  53                   push ebx
// 004aaa2b  8bce                 mov ecx, esi
// 004aaa2d  e84edbf6ff           call 0x418580
// 004aaa32  8b560c               mov edx, dword ptr [esi + 0xc]
// 004aaa35  52                   push edx
// 004aaa36  e85fcf2f00           call 0x7a799a
// 004aaa3b  83c404               add esp, 4
// 004aaa3e  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004aaa41  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 004aaa44  b893244992           mov eax, 0x92492493
// 004aaa49  f7e9                 imul ecx
// 004aaa4b  03d1                 add edx, ecx
// 004aaa4d  c1fa04               sar edx, 4
// 004aaa50  8bc2                 mov eax, edx
// 004aaa52  c1e81f               shr eax, 0x1f
// 004aaa55  03c2                 add eax, edx
// 004aaa57  50                   push eax
// 004aaa58  8bce                 mov ecx, esi
// 004aaa5a  e8a1a5f7ff           call 0x425000
// 004aaa5f  84c0                 test al, al
// 004aaa61  7416                 je 0x4aaa79
// 004aaa63  8b460c               mov eax, dword ptr [esi + 0xc]
// 004aaa66  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004aaa69  8b570c               mov edx, dword ptr [edi + 0xc]
// 004aaa6c  50                   push eax
// 004aaa6d  51                   push ecx
// 004aaa6e  52                   push edx
// 004aaa6f  8bce                 mov ecx, esi
// 004aaa71  e8fae4ffff           call 0x4a8f70
// 004aaa76  894610               mov dword ptr [esi + 0x10], eax
// 004aaa79  5b                   pop ebx
// 004aaa7a  5d                   pop ebp
// 004aaa7b  5f                   pop edi
// 004aaa7c  8bc6                 mov eax, esi
// 004aaa7e  5e                   pop esi
// 004aaa7f  c20400               ret 4
// standard library vector<string> (function ??4?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEAAV01@ABV01@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
