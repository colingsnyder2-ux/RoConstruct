// from server: 100% by auto
// roc 2009-12 004fd2c0  unit: RBX::Network::Player  size: 386 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004fd2c0
//
// 004fd2c0  56                   push esi
// 004fd2c1  57                   push edi
// 004fd2c2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004fd2c6  8bf1                 mov esi, ecx
// 004fd2c8  3bf7                 cmp esi, edi
// 004fd2ca  0f846b010000         je 0x4fd43b
// 004fd2d0  8b470c               mov eax, dword ptr [edi + 0xc]
// 004fd2d3  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004fd2d6  2bc8                 sub ecx, eax
// 004fd2d8  b893244992           mov eax, 0x92492493
// 004fd2dd  f7e9                 imul ecx
// 004fd2df  03d1                 add edx, ecx
// 004fd2e1  55                   push ebp
// 004fd2e2  c1fa04               sar edx, 4
// 004fd2e5  8bea                 mov ebp, edx
// 004fd2e7  c1ed1f               shr ebp, 0x1f
// 004fd2ea  03ea                 add ebp, edx
// 004fd2ec  750f                 jne 0x4fd2fd
// 004fd2ee  8bce                 mov ecx, esi
// 004fd2f0  e81bf1ffff           call 0x4fc410
// 004fd2f5  5d                   pop ebp
// 004fd2f6  5f                   pop edi
// 004fd2f7  8bc6                 mov eax, esi
// 004fd2f9  5e                   pop esi
// 004fd2fa  c20400               ret 4
// 004fd2fd  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004fd300  53                   push ebx
// 004fd301  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004fd304  2bcb                 sub ecx, ebx
// 004fd306  b893244992           mov eax, 0x92492493
// 004fd30b  f7e9                 imul ecx
// 004fd30d  03d1                 add edx, ecx
// 004fd30f  c1fa04               sar edx, 4
// 004fd312  8bca                 mov ecx, edx
// 004fd314  c1e91f               shr ecx, 0x1f
// 004fd317  03ca                 add ecx, edx
// 004fd319  3be9                 cmp ebp, ecx
// 004fd31b  7765                 ja 0x4fd382
// 004fd31d  c644241400           mov byte ptr [esp + 0x14], 0
// 004fd322  8b442414             mov eax, dword ptr [esp + 0x14]
// 004fd326  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004fd32a  8b542414             mov edx, dword ptr [esp + 0x14]
// 004fd32e  50                   push eax
// 004fd32f  8b4710               mov eax, dword ptr [edi + 0x10]
// 004fd332  51                   push ecx
// 004fd333  52                   push edx
// 004fd334  53                   push ebx
// 004fd335  50                   push eax
// 004fd336  8b470c               mov eax, dword ptr [edi + 0xc]
// 004fd339  50                   push eax
// 004fd33a  e8816ff4ff           call 0x4442c0
// 004fd33f  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004fd342  83c418               add esp, 0x18
// 004fd345  51                   push ecx
// 004fd346  50                   push eax
// 004fd347  8bce                 mov ecx, esi
// 004fd349  e882b2f1ff           call 0x4185d0
// 004fd34e  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004fd351  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 004fd354  b893244992           mov eax, 0x92492493
// 004fd359  f7e9                 imul ecx
// 004fd35b  03d1                 add edx, ecx
// 004fd35d  c1fa04               sar edx, 4
// 004fd360  8bc2                 mov eax, edx
// 004fd362  c1e81f               shr eax, 0x1f
// 004fd365  03c2                 add eax, edx
// 004fd367  8d14c500000000       lea edx, [eax*8]
// 004fd36e  2bd0                 sub edx, eax
// 004fd370  8b460c               mov eax, dword ptr [esi + 0xc]
// 004fd373  5b                   pop ebx
// 004fd374  5d                   pop ebp
// 004fd375  8d0c90               lea ecx, [eax + edx*4]
// 004fd378  5f                   pop edi
// 004fd379  894e10               mov dword ptr [esi + 0x10], ecx
// 004fd37c  8bc6                 mov eax, esi
// 004fd37e  5e                   pop esi
// 004fd37f  c20400               ret 4
// 004fd382  85db                 test ebx, ebx
// 004fd384  7504                 jne 0x4fd38a
// 004fd386  33c0                 xor eax, eax
// 004fd388  eb1e                 jmp 0x4fd3a8
// 004fd38a  8b5614               mov edx, dword ptr [esi + 0x14]
// 004fd38d  2bd3                 sub edx, ebx
// 004fd38f  89542414             mov dword ptr [esp + 0x14], edx
// 004fd393  b893244992           mov eax, 0x92492493
// 004fd398  f7ea                 imul edx
// 004fd39a  03542414             add edx, dword ptr [esp + 0x14]
// 004fd39e  c1fa04               sar edx, 4
// 004fd3a1  8bc2                 mov eax, edx
// 004fd3a3  c1e81f               shr eax, 0x1f
// 004fd3a6  03c2                 add eax, edx
// 004fd3a8  3be8                 cmp ebp, eax
// 004fd3aa  7736                 ja 0x4fd3e2
// 004fd3ac  8b470c               mov eax, dword ptr [edi + 0xc]
// 004fd3af  8d14cd00000000       lea edx, [ecx*8]
// 004fd3b6  2bd1                 sub edx, ecx
// 004fd3b8  8d2c90               lea ebp, [eax + edx*4]
// 004fd3bb  53                   push ebx
// 004fd3bc  55                   push ebp
// 004fd3bd  50                   push eax
// 004fd3be  e86d73f4ff           call 0x444730
// 004fd3c3  8b4610               mov eax, dword ptr [esi + 0x10]
// 004fd3c6  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004fd3c9  83c40c               add esp, 0xc
// 004fd3cc  50                   push eax
// 004fd3cd  51                   push ecx
// 004fd3ce  55                   push ebp
// 004fd3cf  8bce                 mov ecx, esi
// 004fd3d1  e89ae2ffff           call 0x4fb670
// 004fd3d6  5b                   pop ebx
// 004fd3d7  5d                   pop ebp
// 004fd3d8  894610               mov dword ptr [esi + 0x10], eax
// 004fd3db  5f                   pop edi
// 004fd3dc  8bc6                 mov eax, esi
// 004fd3de  5e                   pop esi
// 004fd3df  c20400               ret 4
// 004fd3e2  85db                 test ebx, ebx
// 004fd3e4  7418                 je 0x4fd3fe
// 004fd3e6  8b4610               mov eax, dword ptr [esi + 0x10]
// 004fd3e9  50                   push eax
// 004fd3ea  53                   push ebx
// 004fd3eb  8bce                 mov ecx, esi
// 004fd3ed  e8deb1f1ff           call 0x4185d0
// 004fd3f2  8b560c               mov edx, dword ptr [esi + 0xc]
// 004fd3f5  52                   push edx
// 004fd3f6  e85f642f00           call 0x7f385a
// 004fd3fb  83c404               add esp, 4
// 004fd3fe  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004fd401  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 004fd404  b893244992           mov eax, 0x92492493
// 004fd409  f7e9                 imul ecx
// 004fd40b  03d1                 add edx, ecx
// 004fd40d  c1fa04               sar edx, 4
// 004fd410  8bc2                 mov eax, edx
// 004fd412  c1e81f               shr eax, 0x1f
// 004fd415  03c2                 add eax, edx
// 004fd417  50                   push eax
// 004fd418  8bce                 mov ecx, esi
// 004fd41a  e8b177f2ff           call 0x424bd0
// 004fd41f  84c0                 test al, al
// 004fd421  7416                 je 0x4fd439
// 004fd423  8b460c               mov eax, dword ptr [esi + 0xc]
// 004fd426  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004fd429  8b570c               mov edx, dword ptr [edi + 0xc]
// 004fd42c  50                   push eax
// 004fd42d  51                   push ecx
// 004fd42e  52                   push edx
// 004fd42f  8bce                 mov ecx, esi
// 004fd431  e83ae2ffff           call 0x4fb670
// 004fd436  894610               mov dword ptr [esi + 0x10], eax
// 004fd439  5b                   pop ebx
// 004fd43a  5d                   pop ebp
// 004fd43b  5f                   pop edi
// 004fd43c  8bc6                 mov eax, esi
// 004fd43e  5e                   pop esi
// 004fd43f  c20400               ret 4
// standard library vector<string> (function ??4?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEAAV01@ABV01@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
