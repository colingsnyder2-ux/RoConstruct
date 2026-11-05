// from server: 100% by auto
// roc 2009-12 004811c0  unit: RBX::AdornRbxGfx  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004811c0
//
// 004811c0  83ec08               sub esp, 8
// 004811c3  53                   push ebx
// 004811c4  55                   push ebp
// 004811c5  56                   push esi
// 004811c6  8bf1                 mov esi, ecx
// 004811c8  8b4610               mov eax, dword ptr [esi + 0x10]
// 004811cb  57                   push edi
// 004811cc  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004811cf  8bc8                 mov ecx, eax
// 004811d1  2bcf                 sub ecx, edi
// 004811d3  f7c1f8ffffff         test ecx, 0xfffffff8
// 004811d9  7504                 jne 0x4811df
// 004811db  33db                 xor ebx, ebx
// 004811dd  eb27                 jmp 0x481206
// 004811df  3bf8                 cmp edi, eax
// 004811e1  7606                 jbe 0x4811e9
// 004811e3  ff1560b79800         call dword ptr [0x98b760]
// 004811e9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004811ed  8b06                 mov eax, dword ptr [esi]
// 004811ef  85c9                 test ecx, ecx
// 004811f1  7404                 je 0x4811f7
// 004811f3  3bc8                 cmp ecx, eax
// 004811f5  7406                 je 0x4811fd
// 004811f7  ff1560b79800         call dword ptr [0x98b760]
// 004811fd  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00481201  2bdf                 sub ebx, edi
// 00481203  c1fb03               sar ebx, 3
// 00481206  8b542428             mov edx, dword ptr [esp + 0x28]
// 0048120a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0048120e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00481212  52                   push edx
// 00481213  6a01                 push 1
// 00481215  50                   push eax
// 00481216  51                   push ecx
// 00481217  8bce                 mov ecx, esi
// 00481219  e842fcffff           call 0x480e60
// 0048121e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00481221  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00481224  7606                 jbe 0x48122c
// 00481226  ff1560b79800         call dword ptr [0x98b760]
// 0048122c  8b36                 mov esi, dword ptr [esi]
// 0048122e  8bee                 mov ebp, esi
// 00481230  897c2414             mov dword ptr [esp + 0x14], edi
// 00481234  85f6                 test esi, esi
// 00481236  7518                 jne 0x481250
// 00481238  ff1560b79800         call dword ptr [0x98b760]
// 0048123e  33c0                 xor eax, eax
// 00481240  8d3cdf               lea edi, [edi + ebx*8]
// 00481243  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00481246  7713                 ja 0x48125b
// 00481248  85f6                 test esi, esi
// 0048124a  7408                 je 0x481254
// 0048124c  8b36                 mov esi, dword ptr [esi]
// 0048124e  eb06                 jmp 0x481256
// 00481250  8b06                 mov eax, dword ptr [esi]
// 00481252  ebec                 jmp 0x481240
// 00481254  33f6                 xor esi, esi
// 00481256  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00481259  7306                 jae 0x481261
// 0048125b  ff1560b79800         call dword ptr [0x98b760]
// 00481261  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00481265  897804               mov dword ptr [eax + 4], edi
// 00481268  5f                   pop edi
// 00481269  5e                   pop esi
// 0048126a  8928                 mov dword ptr [eax], ebp
// 0048126c  5d                   pop ebp
// 0048126d  5b                   pop ebx
// 0048126e  83c408               add esp, 8
// 00481271  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
