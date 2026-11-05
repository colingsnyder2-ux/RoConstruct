// from server: 100% by auto
// roc 2008-06 00420030  unit: CInsertObjectDialog  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00420030
//
// 00420030  83ec08               sub esp, 8
// 00420033  53                   push ebx
// 00420034  55                   push ebp
// 00420035  56                   push esi
// 00420036  8bf1                 mov esi, ecx
// 00420038  8b4610               mov eax, dword ptr [esi + 0x10]
// 0042003b  57                   push edi
// 0042003c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0042003f  8bc8                 mov ecx, eax
// 00420041  2bcf                 sub ecx, edi
// 00420043  f7c1f8ffffff         test ecx, 0xfffffff8
// 00420049  7504                 jne 0x42004f
// 0042004b  33db                 xor ebx, ebx
// 0042004d  eb27                 jmp 0x420076
// 0042004f  3bf8                 cmp edi, eax
// 00420051  7606                 jbe 0x420059
// 00420053  ff1590288000         call dword ptr [0x802890]
// 00420059  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0042005d  8b06                 mov eax, dword ptr [esi]
// 0042005f  85c9                 test ecx, ecx
// 00420061  7404                 je 0x420067
// 00420063  3bc8                 cmp ecx, eax
// 00420065  7406                 je 0x42006d
// 00420067  ff1590288000         call dword ptr [0x802890]
// 0042006d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00420071  2bdf                 sub ebx, edi
// 00420073  c1fb03               sar ebx, 3
// 00420076  8b542428             mov edx, dword ptr [esp + 0x28]
// 0042007a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0042007e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00420082  52                   push edx
// 00420083  6a01                 push 1
// 00420085  50                   push eax
// 00420086  51                   push ecx
// 00420087  8bce                 mov ecx, esi
// 00420089  e8b221ffff           call 0x412240
// 0042008e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00420091  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00420094  7606                 jbe 0x42009c
// 00420096  ff1590288000         call dword ptr [0x802890]
// 0042009c  8b36                 mov esi, dword ptr [esi]
// 0042009e  8bee                 mov ebp, esi
// 004200a0  897c2414             mov dword ptr [esp + 0x14], edi
// 004200a4  85f6                 test esi, esi
// 004200a6  7518                 jne 0x4200c0
// 004200a8  ff1590288000         call dword ptr [0x802890]
// 004200ae  33c0                 xor eax, eax
// 004200b0  8d3cdf               lea edi, [edi + ebx*8]
// 004200b3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004200b6  7713                 ja 0x4200cb
// 004200b8  85f6                 test esi, esi
// 004200ba  7408                 je 0x4200c4
// 004200bc  8b36                 mov esi, dword ptr [esi]
// 004200be  eb06                 jmp 0x4200c6
// 004200c0  8b06                 mov eax, dword ptr [esi]
// 004200c2  ebec                 jmp 0x4200b0
// 004200c4  33f6                 xor esi, esi
// 004200c6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004200c9  7306                 jae 0x4200d1
// 004200cb  ff1590288000         call dword ptr [0x802890]
// 004200d1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004200d5  897804               mov dword ptr [eax + 4], edi
// 004200d8  5f                   pop edi
// 004200d9  5e                   pop esi
// 004200da  8928                 mov dword ptr [eax], ebp
// 004200dc  5d                   pop ebp
// 004200dd  5b                   pop ebx
// 004200de  83c408               add esp, 8
// 004200e1  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
