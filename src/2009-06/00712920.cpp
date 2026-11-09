// from server: 100% by auto
// roc 2009-06 00712920  unit: W4_D3DFORMAT::?$EnumDesc  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00712920
//
// 00712920  83ec08               sub esp, 8
// 00712923  53                   push ebx
// 00712924  55                   push ebp
// 00712925  56                   push esi
// 00712926  8bf1                 mov esi, ecx
// 00712928  8b4610               mov eax, dword ptr [esi + 0x10]
// 0071292b  57                   push edi
// 0071292c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0071292f  8bc8                 mov ecx, eax
// 00712931  2bcf                 sub ecx, edi
// 00712933  f7c1fcffffff         test ecx, 0xfffffffc
// 00712939  7504                 jne 0x71293f
// 0071293b  33db                 xor ebx, ebx
// 0071293d  eb27                 jmp 0x712966
// 0071293f  3bf8                 cmp edi, eax
// 00712941  7606                 jbe 0x712949
// 00712943  ff15ace98900         call dword ptr [0x89e9ac]
// 00712949  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0071294d  8b06                 mov eax, dword ptr [esi]
// 0071294f  85c9                 test ecx, ecx
// 00712951  7404                 je 0x712957
// 00712953  3bc8                 cmp ecx, eax
// 00712955  7406                 je 0x71295d
// 00712957  ff15ace98900         call dword ptr [0x89e9ac]
// 0071295d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00712961  2bdf                 sub ebx, edi
// 00712963  c1fb02               sar ebx, 2
// 00712966  8b542428             mov edx, dword ptr [esp + 0x28]
// 0071296a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0071296e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00712972  52                   push edx
// 00712973  6a01                 push 1
// 00712975  50                   push eax
// 00712976  51                   push ecx
// 00712977  8bce                 mov ecx, esi
// 00712979  e852fdffff           call 0x7126d0
// 0071297e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00712981  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00712984  7606                 jbe 0x71298c
// 00712986  ff15ace98900         call dword ptr [0x89e9ac]
// 0071298c  8b36                 mov esi, dword ptr [esi]
// 0071298e  8bee                 mov ebp, esi
// 00712990  897c2414             mov dword ptr [esp + 0x14], edi
// 00712994  85f6                 test esi, esi
// 00712996  7518                 jne 0x7129b0
// 00712998  ff15ace98900         call dword ptr [0x89e9ac]
// 0071299e  33c0                 xor eax, eax
// 007129a0  8d3c9f               lea edi, [edi + ebx*4]
// 007129a3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 007129a6  7713                 ja 0x7129bb
// 007129a8  85f6                 test esi, esi
// 007129aa  7408                 je 0x7129b4
// 007129ac  8b36                 mov esi, dword ptr [esi]
// 007129ae  eb06                 jmp 0x7129b6
// 007129b0  8b06                 mov eax, dword ptr [esi]
// 007129b2  ebec                 jmp 0x7129a0
// 007129b4  33f6                 xor esi, esi
// 007129b6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 007129b9  7306                 jae 0x7129c1
// 007129bb  ff15ace98900         call dword ptr [0x89e9ac]
// 007129c1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007129c5  897804               mov dword ptr [eax + 4], edi
// 007129c8  5f                   pop edi
// 007129c9  5e                   pop esi
// 007129ca  8928                 mov dword ptr [eax], ebp
// 007129cc  5d                   pop ebp
// 007129cd  5b                   pop ebx
// 007129ce  83c408               add esp, 8
// 007129d1  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
