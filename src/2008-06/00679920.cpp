// from server: 100% by auto
// roc 2008-06 00679920  unit: Ogre::RbxSceneManagerFactory  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00679920
//
// 00679920  83ec08               sub esp, 8
// 00679923  56                   push esi
// 00679924  8bf1                 mov esi, ecx
// 00679926  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00679929  57                   push edi
// 0067992a  85c9                 test ecx, ecx
// 0067992c  7504                 jne 0x679932
// 0067992e  33c0                 xor eax, eax
// 00679930  eb08                 jmp 0x67993a
// 00679932  8b4614               mov eax, dword ptr [esi + 0x14]
// 00679935  2bc1                 sub eax, ecx
// 00679937  c1f802               sar eax, 2
// 0067993a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0067993d  8bd7                 mov edx, edi
// 0067993f  2bd1                 sub edx, ecx
// 00679941  c1fa02               sar edx, 2
// 00679944  3bd0                 cmp edx, eax
// 00679946  7317                 jae 0x67995f
// 00679948  8b442414             mov eax, dword ptr [esp + 0x14]
// 0067994c  d900                 fld dword ptr [eax]
// 0067994e  83c704               add edi, 4
// 00679951  d95ffc               fstp dword ptr [edi - 4]
// 00679954  897e10               mov dword ptr [esi + 0x10], edi
// 00679957  5f                   pop edi
// 00679958  5e                   pop esi
// 00679959  83c408               add esp, 8
// 0067995c  c20400               ret 4
// 0067995f  3bcf                 cmp ecx, edi
// 00679961  7606                 jbe 0x679969
// 00679963  ff1590288000         call dword ptr [0x802890]
// 00679969  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0067996d  8b06                 mov eax, dword ptr [esi]
// 0067996f  51                   push ecx
// 00679970  57                   push edi
// 00679971  50                   push eax
// 00679972  8d542414             lea edx, [esp + 0x14]
// 00679976  52                   push edx
// 00679977  8bce                 mov ecx, esi
// 00679979  e8a2f7ffff           call 0x679120
// 0067997e  5f                   pop edi
// 0067997f  5e                   pop esi
// 00679980  83c408               add esp, 8
// 00679983  c20400               ret 4
// standard library vector<float> (function ?push_back@?$vector@MV?$allocator@M@std@@@std@@QAEXABM@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
