// from server: 100% by auto
// roc 2008-06 0048d850  unit: RBX::Reflection::Z::$$A6AXM::?$TSignalDesc::TSignalInstance  size: 386 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048d850
//
// 0048d850  56                   push esi
// 0048d851  57                   push edi
// 0048d852  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0048d856  8bf1                 mov esi, ecx
// 0048d858  3bf7                 cmp esi, edi
// 0048d85a  0f846b010000         je 0x48d9cb
// 0048d860  8b470c               mov eax, dword ptr [edi + 0xc]
// 0048d863  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 0048d866  2bc8                 sub ecx, eax
// 0048d868  b893244992           mov eax, 0x92492493
// 0048d86d  f7e9                 imul ecx
// 0048d86f  03d1                 add edx, ecx
// 0048d871  55                   push ebp
// 0048d872  c1fa04               sar edx, 4
// 0048d875  8bea                 mov ebp, edx
// 0048d877  c1ed1f               shr ebp, 0x1f
// 0048d87a  03ea                 add ebp, edx
// 0048d87c  750f                 jne 0x48d88d
// 0048d87e  8bce                 mov ecx, esi
// 0048d880  e85bfcffff           call 0x48d4e0
// 0048d885  5d                   pop ebp
// 0048d886  5f                   pop edi
// 0048d887  8bc6                 mov eax, esi
// 0048d889  5e                   pop esi
// 0048d88a  c20400               ret 4
// 0048d88d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0048d890  53                   push ebx
// 0048d891  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0048d894  2bcb                 sub ecx, ebx
// 0048d896  b893244992           mov eax, 0x92492493
// 0048d89b  f7e9                 imul ecx
// 0048d89d  03d1                 add edx, ecx
// 0048d89f  c1fa04               sar edx, 4
// 0048d8a2  8bca                 mov ecx, edx
// 0048d8a4  c1e91f               shr ecx, 0x1f
// 0048d8a7  03ca                 add ecx, edx
// 0048d8a9  3be9                 cmp ebp, ecx
// 0048d8ab  7765                 ja 0x48d912
// 0048d8ad  c644241400           mov byte ptr [esp + 0x14], 0
// 0048d8b2  8b442414             mov eax, dword ptr [esp + 0x14]
// 0048d8b6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0048d8ba  8b542414             mov edx, dword ptr [esp + 0x14]
// 0048d8be  50                   push eax
// 0048d8bf  8b4710               mov eax, dword ptr [edi + 0x10]
// 0048d8c2  51                   push ecx
// 0048d8c3  52                   push edx
// 0048d8c4  53                   push ebx
// 0048d8c5  50                   push eax
// 0048d8c6  8b470c               mov eax, dword ptr [edi + 0xc]
// 0048d8c9  50                   push eax
// 0048d8ca  e8417afbff           call 0x445310
// 0048d8cf  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0048d8d2  83c418               add esp, 0x18
// 0048d8d5  51                   push ecx
// 0048d8d6  50                   push eax
// 0048d8d7  8bce                 mov ecx, esi
// 0048d8d9  e8c29ef7ff           call 0x4077a0
// 0048d8de  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 0048d8e1  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 0048d8e4  b893244992           mov eax, 0x92492493
// 0048d8e9  f7e9                 imul ecx
// 0048d8eb  03d1                 add edx, ecx
// 0048d8ed  c1fa04               sar edx, 4
// 0048d8f0  8bc2                 mov eax, edx
// 0048d8f2  c1e81f               shr eax, 0x1f
// 0048d8f5  03c2                 add eax, edx
// 0048d8f7  8d14c500000000       lea edx, [eax*8]
// 0048d8fe  2bd0                 sub edx, eax
// 0048d900  8b460c               mov eax, dword ptr [esi + 0xc]
// 0048d903  5b                   pop ebx
// 0048d904  5d                   pop ebp
// 0048d905  8d0c90               lea ecx, [eax + edx*4]
// 0048d908  5f                   pop edi
// 0048d909  894e10               mov dword ptr [esi + 0x10], ecx
// 0048d90c  8bc6                 mov eax, esi
// 0048d90e  5e                   pop esi
// 0048d90f  c20400               ret 4
// 0048d912  85db                 test ebx, ebx
// 0048d914  7504                 jne 0x48d91a
// 0048d916  33c0                 xor eax, eax
// 0048d918  eb1e                 jmp 0x48d938
// 0048d91a  8b5614               mov edx, dword ptr [esi + 0x14]
// 0048d91d  2bd3                 sub edx, ebx
// 0048d91f  89542414             mov dword ptr [esp + 0x14], edx
// 0048d923  b893244992           mov eax, 0x92492493
// 0048d928  f7ea                 imul edx
// 0048d92a  03542414             add edx, dword ptr [esp + 0x14]
// 0048d92e  c1fa04               sar edx, 4
// 0048d931  8bc2                 mov eax, edx
// 0048d933  c1e81f               shr eax, 0x1f
// 0048d936  03c2                 add eax, edx
// 0048d938  3be8                 cmp ebp, eax
// 0048d93a  7736                 ja 0x48d972
// 0048d93c  8b470c               mov eax, dword ptr [edi + 0xc]
// 0048d93f  8d14cd00000000       lea edx, [ecx*8]
// 0048d946  2bd1                 sub edx, ecx
// 0048d948  8d2c90               lea ebp, [eax + edx*4]
// 0048d94b  53                   push ebx
// 0048d94c  55                   push ebp
// 0048d94d  50                   push eax
// 0048d94e  e8dd7bfbff           call 0x445530
// 0048d953  8b4610               mov eax, dword ptr [esi + 0x10]
// 0048d956  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 0048d959  83c40c               add esp, 0xc
// 0048d95c  50                   push eax
// 0048d95d  51                   push ecx
// 0048d95e  55                   push ebp
// 0048d95f  8bce                 mov ecx, esi
// 0048d961  e83aefffff           call 0x48c8a0
// 0048d966  5b                   pop ebx
// 0048d967  5d                   pop ebp
// 0048d968  894610               mov dword ptr [esi + 0x10], eax
// 0048d96b  5f                   pop edi
// 0048d96c  8bc6                 mov eax, esi
// 0048d96e  5e                   pop esi
// 0048d96f  c20400               ret 4
// 0048d972  85db                 test ebx, ebx
// 0048d974  7418                 je 0x48d98e
// 0048d976  8b4610               mov eax, dword ptr [esi + 0x10]
// 0048d979  50                   push eax
// 0048d97a  53                   push ebx
// 0048d97b  8bce                 mov ecx, esi
// 0048d97d  e81e9ef7ff           call 0x4077a0
// 0048d982  8b560c               mov edx, dword ptr [esi + 0xc]
// 0048d985  52                   push edx
// 0048d986  e8ef2c2100           call 0x6a067a
// 0048d98b  83c404               add esp, 4
// 0048d98e  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 0048d991  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 0048d994  b893244992           mov eax, 0x92492493
// 0048d999  f7e9                 imul ecx
// 0048d99b  03d1                 add edx, ecx
// 0048d99d  c1fa04               sar edx, 4
// 0048d9a0  8bc2                 mov eax, edx
// 0048d9a2  c1e81f               shr eax, 0x1f
// 0048d9a5  03c2                 add eax, edx
// 0048d9a7  50                   push eax
// 0048d9a8  8bce                 mov ecx, esi
// 0048d9aa  e8a1b4f9ff           call 0x428e50
// 0048d9af  84c0                 test al, al
// 0048d9b1  7416                 je 0x48d9c9
// 0048d9b3  8b460c               mov eax, dword ptr [esi + 0xc]
// 0048d9b6  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 0048d9b9  8b570c               mov edx, dword ptr [edi + 0xc]
// 0048d9bc  50                   push eax
// 0048d9bd  51                   push ecx
// 0048d9be  52                   push edx
// 0048d9bf  8bce                 mov ecx, esi
// 0048d9c1  e8daeeffff           call 0x48c8a0
// 0048d9c6  894610               mov dword ptr [esi + 0x10], eax
// 0048d9c9  5b                   pop ebx
// 0048d9ca  5d                   pop ebp
// 0048d9cb  5f                   pop edi
// 0048d9cc  8bc6                 mov eax, esi
// 0048d9ce  5e                   pop esi
// 0048d9cf  c20400               ret 4
// standard library vector<string> (function ??4?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEAAV01@ABV01@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
