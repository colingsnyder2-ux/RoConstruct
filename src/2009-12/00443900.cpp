// from server: 100% by auto
// roc 2009-12 00443900  unit: RBX::MergeBinder  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00443900
//
// 00443900  83ec08               sub esp, 8
// 00443903  56                   push esi
// 00443904  8bf1                 mov esi, ecx
// 00443906  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00443909  57                   push edi
// 0044390a  85c9                 test ecx, ecx
// 0044390c  7504                 jne 0x443912
// 0044390e  33c0                 xor eax, eax
// 00443910  eb08                 jmp 0x44391a
// 00443912  8b4614               mov eax, dword ptr [esi + 0x14]
// 00443915  2bc1                 sub eax, ecx
// 00443917  c1f804               sar eax, 4
// 0044391a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0044391d  8bd7                 mov edx, edi
// 0044391f  2bd1                 sub edx, ecx
// 00443921  c1fa04               sar edx, 4
// 00443924  3bd0                 cmp edx, eax
// 00443926  7331                 jae 0x443959
// 00443928  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044392c  c644240800           mov byte ptr [esp + 8], 0
// 00443931  8b442408             mov eax, dword ptr [esp + 8]
// 00443935  50                   push eax
// 00443936  8b442418             mov eax, dword ptr [esp + 0x18]
// 0044393a  51                   push ecx
// 0044393b  8d5608               lea edx, [esi + 8]
// 0044393e  52                   push edx
// 0044393f  50                   push eax
// 00443940  6a01                 push 1
// 00443942  57                   push edi
// 00443943  e858f9ffff           call 0x4432a0
// 00443948  83c418               add esp, 0x18
// 0044394b  83c710               add edi, 0x10
// 0044394e  897e10               mov dword ptr [esi + 0x10], edi
// 00443951  5f                   pop edi
// 00443952  5e                   pop esi
// 00443953  83c408               add esp, 8
// 00443956  c20400               ret 4
// 00443959  3bcf                 cmp ecx, edi
// 0044395b  7606                 jbe 0x443963
// 0044395d  ff1560b79800         call dword ptr [0x98b760]
// 00443963  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00443967  8b06                 mov eax, dword ptr [esi]
// 00443969  51                   push ecx
// 0044396a  57                   push edi
// 0044396b  50                   push eax
// 0044396c  8d542414             lea edx, [esp + 0x14]
// 00443970  52                   push edx
// 00443971  8bce                 mov ecx, esi
// 00443973  e818fdffff           call 0x443690
// 00443978  5f                   pop edi
// 00443979  5e                   pop esi
// 0044397a  83c408               add esp, 8
// 0044397d  c20400               ret 4
// standard library vector<pod16> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
