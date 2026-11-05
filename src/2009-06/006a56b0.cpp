// from server: 100% by auto
// roc 2009-06 006a56b0  unit: RBX::VMouse::?$EventDesc  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006a56b0
//
// 006a56b0  83ec08               sub esp, 8
// 006a56b3  53                   push ebx
// 006a56b4  55                   push ebp
// 006a56b5  56                   push esi
// 006a56b6  8bf1                 mov esi, ecx
// 006a56b8  8b4610               mov eax, dword ptr [esi + 0x10]
// 006a56bb  57                   push edi
// 006a56bc  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 006a56bf  8bc8                 mov ecx, eax
// 006a56c1  2bcf                 sub ecx, edi
// 006a56c3  f7c1fcffffff         test ecx, 0xfffffffc
// 006a56c9  7504                 jne 0x6a56cf
// 006a56cb  33db                 xor ebx, ebx
// 006a56cd  eb27                 jmp 0x6a56f6
// 006a56cf  3bf8                 cmp edi, eax
// 006a56d1  7606                 jbe 0x6a56d9
// 006a56d3  ff15ace98900         call dword ptr [0x89e9ac]
// 006a56d9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006a56dd  8b06                 mov eax, dword ptr [esi]
// 006a56df  85c9                 test ecx, ecx
// 006a56e1  7404                 je 0x6a56e7
// 006a56e3  3bc8                 cmp ecx, eax
// 006a56e5  7406                 je 0x6a56ed
// 006a56e7  ff15ace98900         call dword ptr [0x89e9ac]
// 006a56ed  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006a56f1  2bdf                 sub ebx, edi
// 006a56f3  c1fb02               sar ebx, 2
// 006a56f6  8b542428             mov edx, dword ptr [esp + 0x28]
// 006a56fa  8b442424             mov eax, dword ptr [esp + 0x24]
// 006a56fe  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006a5702  52                   push edx
// 006a5703  6a01                 push 1
// 006a5705  50                   push eax
// 006a5706  51                   push ecx
// 006a5707  8bce                 mov ecx, esi
// 006a5709  e862fdffff           call 0x6a5470
// 006a570e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 006a5711  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 006a5714  7606                 jbe 0x6a571c
// 006a5716  ff15ace98900         call dword ptr [0x89e9ac]
// 006a571c  8b36                 mov esi, dword ptr [esi]
// 006a571e  8bee                 mov ebp, esi
// 006a5720  897c2414             mov dword ptr [esp + 0x14], edi
// 006a5724  85f6                 test esi, esi
// 006a5726  7518                 jne 0x6a5740
// 006a5728  ff15ace98900         call dword ptr [0x89e9ac]
// 006a572e  33c0                 xor eax, eax
// 006a5730  8d3c9f               lea edi, [edi + ebx*4]
// 006a5733  3b7810               cmp edi, dword ptr [eax + 0x10]
// 006a5736  7713                 ja 0x6a574b
// 006a5738  85f6                 test esi, esi
// 006a573a  7408                 je 0x6a5744
// 006a573c  8b36                 mov esi, dword ptr [esi]
// 006a573e  eb06                 jmp 0x6a5746
// 006a5740  8b06                 mov eax, dword ptr [esi]
// 006a5742  ebec                 jmp 0x6a5730
// 006a5744  33f6                 xor esi, esi
// 006a5746  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 006a5749  7306                 jae 0x6a5751
// 006a574b  ff15ace98900         call dword ptr [0x89e9ac]
// 006a5751  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006a5755  897804               mov dword ptr [eax + 4], edi
// 006a5758  5f                   pop edi
// 006a5759  5e                   pop esi
// 006a575a  8928                 mov dword ptr [eax], ebp
// 006a575c  5d                   pop ebp
// 006a575d  5b                   pop ebx
// 006a575e  83c408               add esp, 8
// 006a5761  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
