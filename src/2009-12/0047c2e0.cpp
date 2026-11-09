// from server: 100% by auto
// roc 2009-12 0047c2e0  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047c2e0
//
// 0047c2e0  83ec08               sub esp, 8
// 0047c2e3  53                   push ebx
// 0047c2e4  55                   push ebp
// 0047c2e5  56                   push esi
// 0047c2e6  8bf1                 mov esi, ecx
// 0047c2e8  8b4610               mov eax, dword ptr [esi + 0x10]
// 0047c2eb  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0047c2ee  8bc8                 mov ecx, eax
// 0047c2f0  2bcb                 sub ecx, ebx
// 0047c2f2  57                   push edi
// 0047c2f3  f7c1c0ffffff         test ecx, 0xffffffc0
// 0047c2f9  7504                 jne 0x47c2ff
// 0047c2fb  33ff                 xor edi, edi
// 0047c2fd  eb27                 jmp 0x47c326
// 0047c2ff  3bd8                 cmp ebx, eax
// 0047c301  7606                 jbe 0x47c309
// 0047c303  ff1560b79800         call dword ptr [0x98b760]
// 0047c309  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0047c30d  8b06                 mov eax, dword ptr [esi]
// 0047c30f  85c9                 test ecx, ecx
// 0047c311  7404                 je 0x47c317
// 0047c313  3bc8                 cmp ecx, eax
// 0047c315  7406                 je 0x47c31d
// 0047c317  ff1560b79800         call dword ptr [0x98b760]
// 0047c31d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0047c321  2bfb                 sub edi, ebx
// 0047c323  c1ff06               sar edi, 6
// 0047c326  8b542428             mov edx, dword ptr [esp + 0x28]
// 0047c32a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0047c32e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0047c332  52                   push edx
// 0047c333  6a01                 push 1
// 0047c335  50                   push eax
// 0047c336  51                   push ecx
// 0047c337  8bce                 mov ecx, esi
// 0047c339  e882fbffff           call 0x47bec0
// 0047c33e  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0047c341  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0047c344  7606                 jbe 0x47c34c
// 0047c346  ff1560b79800         call dword ptr [0x98b760]
// 0047c34c  8b36                 mov esi, dword ptr [esi]
// 0047c34e  8bee                 mov ebp, esi
// 0047c350  895c2414             mov dword ptr [esp + 0x14], ebx
// 0047c354  85f6                 test esi, esi
// 0047c356  751a                 jne 0x47c372
// 0047c358  ff1560b79800         call dword ptr [0x98b760]
// 0047c35e  33c0                 xor eax, eax
// 0047c360  c1e706               shl edi, 6
// 0047c363  03fb                 add edi, ebx
// 0047c365  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0047c368  7713                 ja 0x47c37d
// 0047c36a  85f6                 test esi, esi
// 0047c36c  7408                 je 0x47c376
// 0047c36e  8b36                 mov esi, dword ptr [esi]
// 0047c370  eb06                 jmp 0x47c378
// 0047c372  8b06                 mov eax, dword ptr [esi]
// 0047c374  ebea                 jmp 0x47c360
// 0047c376  33f6                 xor esi, esi
// 0047c378  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0047c37b  7306                 jae 0x47c383
// 0047c37d  ff1560b79800         call dword ptr [0x98b760]
// 0047c383  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0047c387  897804               mov dword ptr [eax + 4], edi
// 0047c38a  5f                   pop edi
// 0047c38b  5e                   pop esi
// 0047c38c  8928                 mov dword ptr [eax], ebp
// 0047c38e  5d                   pop ebp
// 0047c38f  5b                   pop ebx
// 0047c390  83c408               add esp, 8
// 0047c393  c21000               ret 0x10
// standard library vector<pod64> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
