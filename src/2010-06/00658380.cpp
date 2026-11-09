// from server: 100% by auto
// roc 2010-06 00658380  unit: RBX::VKeyframeSequence::?$FactoryProduct  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00658380
//
// 00658380  83ec18               sub esp, 0x18
// 00658383  53                   push ebx
// 00658384  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00658388  56                   push esi
// 00658389  8bf1                 mov esi, ecx
// 0065838b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0065838e  57                   push edi
// 0065838f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00658392  8bc7                 mov eax, edi
// 00658394  2bc1                 sub eax, ecx
// 00658396  c1f802               sar eax, 2
// 00658399  3bd8                 cmp ebx, eax
// 0065839b  762f                 jbe 0x6583cc
// 0065839d  3bcf                 cmp ecx, edi
// 0065839f  7606                 jbe 0x6583a7
// 006583a1  ff150ca99e00         call dword ptr [0x9ea90c]
// 006583a7  8b5610               mov edx, dword ptr [esi + 0x10]
// 006583aa  2b560c               sub edx, dword ptr [esi + 0xc]
// 006583ad  8b06                 mov eax, dword ptr [esi]
// 006583af  8d4c242c             lea ecx, [esp + 0x2c]
// 006583b3  51                   push ecx
// 006583b4  c1fa02               sar edx, 2
// 006583b7  2bda                 sub ebx, edx
// 006583b9  53                   push ebx
// 006583ba  57                   push edi
// 006583bb  50                   push eax
// 006583bc  8bce                 mov ecx, esi
// 006583be  e8ad022700           call 0x8c8670
// 006583c3  5f                   pop edi
// 006583c4  5e                   pop esi
// 006583c5  5b                   pop ebx
// 006583c6  83c418               add esp, 0x18
// 006583c9  c20800               ret 8
// 006583cc  7352                 jae 0x658420
// 006583ce  3bcf                 cmp ecx, edi
// 006583d0  7606                 jbe 0x6583d8
// 006583d2  ff150ca99e00         call dword ptr [0x9ea90c]
// 006583d8  8b06                 mov eax, dword ptr [esi]
// 006583da  55                   push ebp
// 006583db  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 006583de  89442418             mov dword ptr [esp + 0x18], eax
// 006583e2  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 006583e5  7606                 jbe 0x6583ed
// 006583e7  ff150ca99e00         call dword ptr [0x9ea90c]
// 006583ed  8b0e                 mov ecx, dword ptr [esi]
// 006583ef  53                   push ebx
// 006583f0  8d542424             lea edx, [esp + 0x24]
// 006583f4  894c2414             mov dword ptr [esp + 0x14], ecx
// 006583f8  52                   push edx
// 006583f9  8d4c2418             lea ecx, [esp + 0x18]
// 006583fd  896c241c             mov dword ptr [esp + 0x1c], ebp
// 00658401  e89ae6e8ff           call 0x4e6aa0
// 00658406  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0065840a  8b5004               mov edx, dword ptr [eax + 4]
// 0065840d  8b00                 mov eax, dword ptr [eax]
// 0065840f  57                   push edi
// 00658410  51                   push ecx
// 00658411  52                   push edx
// 00658412  50                   push eax
// 00658413  8d4c2428             lea ecx, [esp + 0x28]
// 00658417  51                   push ecx
// 00658418  8bce                 mov ecx, esi
// 0065841a  e8d1d2ecff           call 0x5256f0
// 0065841f  5d                   pop ebp
// 00658420  5f                   pop edi
// 00658421  5e                   pop esi
// 00658422  5b                   pop ebx
// 00658423  83c418               add esp, 0x18
// 00658426  c20800               ret 8
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXIPAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
