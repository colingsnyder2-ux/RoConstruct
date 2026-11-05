// from server: 100% by auto
// roc 2010-06 00559620  unit: G3D::BinaryInput  size: 442 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559620
//
// 00559620  83ec08               sub esp, 8
// 00559623  56                   push esi
// 00559624  8bf1                 mov esi, ecx
// 00559626  8b560c               mov edx, dword ptr [esi + 0xc]
// 00559629  57                   push edi
// 0055962a  85d2                 test edx, edx
// 0055962c  7504                 jne 0x559632
// 0055962e  33c9                 xor ecx, ecx
// 00559630  eb0a                 jmp 0x55963c
// 00559632  8b4614               mov eax, dword ptr [esi + 0x14]
// 00559635  2bc2                 sub eax, edx
// 00559637  c1f803               sar eax, 3
// 0055963a  8bc8                 mov ecx, eax
// 0055963c  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00559640  85ff                 test edi, edi
// 00559642  0f848a010000         je 0x5597d2
// 00559648  53                   push ebx
// 00559649  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0055964c  8bc3                 mov eax, ebx
// 0055964e  2bc2                 sub eax, edx
// 00559650  c1f803               sar eax, 3
// 00559653  baffffff1f           mov edx, 0x1fffffff
// 00559658  2bd0                 sub edx, eax
// 0055965a  3bd7                 cmp edx, edi
// 0055965c  7305                 jae 0x559663
// 0055965e  e86d7ff4ff           call 0x4a15d0
// 00559663  8d1438               lea edx, [eax + edi]
// 00559666  55                   push ebp
// 00559667  3bca                 cmp ecx, edx
// 00559669  0f83b7000000         jae 0x559726
// 0055966f  8bc1                 mov eax, ecx
// 00559671  d1e8                 shr eax, 1
// 00559673  bbffffff1f           mov ebx, 0x1fffffff
// 00559678  2bd8                 sub ebx, eax
// 0055967a  3bd9                 cmp ebx, ecx
// 0055967c  730e                 jae 0x55968c
// 0055967e  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00559686  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0055968a  eb06                 jmp 0x559692
// 0055968c  03c8                 add ecx, eax
// 0055968e  894c2410             mov dword ptr [esp + 0x10], ecx
// 00559692  3bca                 cmp ecx, edx
// 00559694  7306                 jae 0x55969c
// 00559696  89542410             mov dword ptr [esp + 0x10], edx
// 0055969a  8bca                 mov ecx, edx
// 0055969c  6a00                 push 0
// 0055969e  51                   push ecx
// 0055969f  e82c78f4ff           call 0x4a0ed0
// 005596a4  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 005596a8  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 005596ab  83c408               add esp, 8
// 005596ae  8be8                 mov ebp, eax
// 005596b0  8b442428             mov eax, dword ptr [esp + 0x28]
// 005596b4  50                   push eax
// 005596b5  c1fb03               sar ebx, 3
// 005596b8  57                   push edi
// 005596b9  8d4cdd00             lea ecx, [ebp + ebx*8]
// 005596bd  51                   push ecx
// 005596be  8bce                 mov ecx, esi
// 005596c0  e8dbfbffff           call 0x5592a0
// 005596c5  8b542420             mov edx, dword ptr [esp + 0x20]
// 005596c9  8b460c               mov eax, dword ptr [esi + 0xc]
// 005596cc  55                   push ebp
// 005596cd  52                   push edx
// 005596ce  50                   push eax
// 005596cf  8bce                 mov ecx, esi
// 005596d1  e80afaffff           call 0x5590e0
// 005596d6  8b5610               mov edx, dword ptr [esi + 0x10]
// 005596d9  8b442420             mov eax, dword ptr [esp + 0x20]
// 005596dd  03df                 add ebx, edi
// 005596df  8d4cdd00             lea ecx, [ebp + ebx*8]
// 005596e3  51                   push ecx
// 005596e4  52                   push edx
// 005596e5  50                   push eax
// 005596e6  8bce                 mov ecx, esi
// 005596e8  e8f3f9ffff           call 0x5590e0
// 005596ed  8b460c               mov eax, dword ptr [esi + 0xc]
// 005596f0  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005596f3  2bc8                 sub ecx, eax
// 005596f5  c1f903               sar ecx, 3
// 005596f8  03f9                 add edi, ecx
// 005596fa  85c0                 test eax, eax
// 005596fc  7409                 je 0x559707
// 005596fe  50                   push eax
// 005596ff  e896e22400           call 0x7a799a
// 00559704  83c404               add esp, 4
// 00559707  8b542410             mov edx, dword ptr [esp + 0x10]
// 0055970b  8d4cfd00             lea ecx, [ebp + edi*8]
// 0055970f  8d44d500             lea eax, [ebp + edx*8]
// 00559713  896e0c               mov dword ptr [esi + 0xc], ebp
// 00559716  5d                   pop ebp
// 00559717  5b                   pop ebx
// 00559718  5f                   pop edi
// 00559719  894614               mov dword ptr [esi + 0x14], eax
// 0055971c  894e10               mov dword ptr [esi + 0x10], ecx
// 0055971f  5e                   pop esi
// 00559720  83c408               add esp, 8
// 00559723  c21000               ret 0x10
// 00559726  8b442420             mov eax, dword ptr [esp + 0x20]
// 0055972a  8bd3                 mov edx, ebx
// 0055972c  2bd0                 sub edx, eax
// 0055972e  c1fa03               sar edx, 3
// 00559731  8d2cfd00000000       lea ebp, [edi*8]
// 00559738  3bd7                 cmp edx, edi
// 0055973a  7358                 jae 0x559794
// 0055973c  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00559740  dd01                 fld qword ptr [ecx]
// 00559742  8d1428               lea edx, [eax + ebp]
// 00559745  52                   push edx
// 00559746  dd5c2414             fstp qword ptr [esp + 0x14]
// 0055974a  53                   push ebx
// 0055974b  50                   push eax
// 0055974c  8bce                 mov ecx, esi
// 0055974e  e88df9ffff           call 0x5590e0
// 00559753  8b4610               mov eax, dword ptr [esi + 0x10]
// 00559756  8bd0                 mov edx, eax
// 00559758  2b542420             sub edx, dword ptr [esp + 0x20]
// 0055975c  8d4c2410             lea ecx, [esp + 0x10]
// 00559760  51                   push ecx
// 00559761  c1fa03               sar edx, 3
// 00559764  2bfa                 sub edi, edx
// 00559766  57                   push edi
// 00559767  50                   push eax
// 00559768  8bce                 mov ecx, esi
// 0055976a  e831fbffff           call 0x5592a0
// 0055976f  016e10               add dword ptr [esi + 0x10], ebp
// 00559772  8b7610               mov esi, dword ptr [esi + 0x10]
// 00559775  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00559779  8d442410             lea eax, [esp + 0x10]
// 0055977d  50                   push eax
// 0055977e  2bf5                 sub esi, ebp
// 00559780  56                   push esi
// 00559781  51                   push ecx
// 00559782  e8a9f8ffff           call 0x559030
// 00559787  83c40c               add esp, 0xc
// 0055978a  5d                   pop ebp
// 0055978b  5b                   pop ebx
// 0055978c  5f                   pop edi
// 0055978d  5e                   pop esi
// 0055978e  83c408               add esp, 8
// 00559791  c21000               ret 0x10
// 00559794  8b542428             mov edx, dword ptr [esp + 0x28]
// 00559798  dd02                 fld qword ptr [edx]
// 0055979a  53                   push ebx
// 0055979b  8bfb                 mov edi, ebx
// 0055979d  dd5c2414             fstp qword ptr [esp + 0x14]
// 005597a1  53                   push ebx
// 005597a2  2bfd                 sub edi, ebp
// 005597a4  57                   push edi
// 005597a5  8bce                 mov ecx, esi
// 005597a7  e834f9ffff           call 0x5590e0
// 005597ac  53                   push ebx
// 005597ad  894610               mov dword ptr [esi + 0x10], eax
// 005597b0  8b442424             mov eax, dword ptr [esp + 0x24]
// 005597b4  57                   push edi
// 005597b5  50                   push eax
// 005597b6  e895f8ffff           call 0x559050
// 005597bb  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005597bf  8d4c241c             lea ecx, [esp + 0x1c]
// 005597c3  51                   push ecx
// 005597c4  03e8                 add ebp, eax
// 005597c6  55                   push ebp
// 005597c7  50                   push eax
// 005597c8  e863f8ffff           call 0x559030
// 005597cd  83c418               add esp, 0x18
// 005597d0  5d                   pop ebp
// 005597d1  5b                   pop ebx
// 005597d2  5f                   pop edi
// 005597d3  5e                   pop esi
// 005597d4  83c408               add esp, 8
// 005597d7  c21000               ret 0x10
// standard library vector<double> (function ?_Insert_n@?$vector@NV?$allocator@N@std@@@std@@IAEXV?$_Vector_const_iterator@NV?$allocator@N@std@@@2@IABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
