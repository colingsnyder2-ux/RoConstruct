// from server: 100% by auto
// roc 2010-06 00750510  unit: RBX::Humanoid  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00750510
//
// 00750510  83ec10               sub esp, 0x10
// 00750513  53                   push ebx
// 00750514  55                   push ebp
// 00750515  56                   push esi
// 00750516  8bf1                 mov esi, ecx
// 00750518  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0075051b  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0075051e  8bcb                 mov ecx, ebx
// 00750520  2bcd                 sub ecx, ebp
// 00750522  b893244992           mov eax, 0x92492493
// 00750527  f7e9                 imul ecx
// 00750529  03d1                 add edx, ecx
// 0075052b  c1fa04               sar edx, 4
// 0075052e  8bc2                 mov eax, edx
// 00750530  c1e81f               shr eax, 0x1f
// 00750533  57                   push edi
// 00750534  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00750538  03c2                 add eax, edx
// 0075053a  3bf8                 cmp edi, eax
// 0075053c  7640                 jbe 0x75057e
// 0075053e  3beb                 cmp ebp, ebx
// 00750540  7606                 jbe 0x750548
// 00750542  ff150ca99e00         call dword ptr [0x9ea90c]
// 00750548  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0075054b  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 0075054e  8b2e                 mov ebp, dword ptr [esi]
// 00750550  8d442428             lea eax, [esp + 0x28]
// 00750554  50                   push eax
// 00750555  b893244992           mov eax, 0x92492493
// 0075055a  f7e9                 imul ecx
// 0075055c  03d1                 add edx, ecx
// 0075055e  c1fa04               sar edx, 4
// 00750561  8bca                 mov ecx, edx
// 00750563  c1e91f               shr ecx, 0x1f
// 00750566  03ca                 add ecx, edx
// 00750568  2bf9                 sub edi, ecx
// 0075056a  57                   push edi
// 0075056b  53                   push ebx
// 0075056c  55                   push ebp
// 0075056d  8bce                 mov ecx, esi
// 0075056f  e86cfcffff           call 0x7501e0
// 00750574  5f                   pop edi
// 00750575  5e                   pop esi
// 00750576  5d                   pop ebp
// 00750577  5b                   pop ebx
// 00750578  83c410               add esp, 0x10
// 0075057b  c22000               ret 0x20
// 0075057e  734e                 jae 0x7505ce
// 00750580  3beb                 cmp ebp, ebx
// 00750582  7606                 jbe 0x75058a
// 00750584  ff150ca99e00         call dword ptr [0x9ea90c]
// 0075058a  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0075058d  8b16                 mov edx, dword ptr [esi]
// 0075058f  89542418             mov dword ptr [esp + 0x18], edx
// 00750593  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 00750596  7606                 jbe 0x75059e
// 00750598  ff150ca99e00         call dword ptr [0x9ea90c]
// 0075059e  8b06                 mov eax, dword ptr [esi]
// 007505a0  57                   push edi
// 007505a1  8d4c2414             lea ecx, [esp + 0x14]
// 007505a5  89442414             mov dword ptr [esp + 0x14], eax
// 007505a9  896c2418             mov dword ptr [esp + 0x18], ebp
// 007505ad  e8be38cdff           call 0x423e70
// 007505b2  8b442418             mov eax, dword ptr [esp + 0x18]
// 007505b6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007505ba  8b542410             mov edx, dword ptr [esp + 0x10]
// 007505be  53                   push ebx
// 007505bf  50                   push eax
// 007505c0  51                   push ecx
// 007505c1  52                   push edx
// 007505c2  8d442428             lea eax, [esp + 0x28]
// 007505c6  50                   push eax
// 007505c7  8bce                 mov ecx, esi
// 007505c9  e852fbffff           call 0x750120
// 007505ce  5f                   pop edi
// 007505cf  5e                   pop esi
// 007505d0  5d                   pop ebp
// 007505d1  5b                   pop ebx
// 007505d2  83c410               add esp, 0x10
// 007505d5  c22000               ret 0x20
// standard library vector<pod28> (function ?resize@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIUE@@@Z)

// stl: vector<pod28>
struct E { int v[7]; };
#include <vector>
template class std::vector<E>;
