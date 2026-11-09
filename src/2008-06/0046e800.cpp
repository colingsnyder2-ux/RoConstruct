// from server: 100% by auto
// roc 2008-06 0046e800  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046e800
//
// 0046e800  83ec08               sub esp, 8
// 0046e803  53                   push ebx
// 0046e804  55                   push ebp
// 0046e805  56                   push esi
// 0046e806  8bf1                 mov esi, ecx
// 0046e808  8b4610               mov eax, dword ptr [esi + 0x10]
// 0046e80b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0046e80e  8bc8                 mov ecx, eax
// 0046e810  2bcb                 sub ecx, ebx
// 0046e812  57                   push edi
// 0046e813  f7c1c0ffffff         test ecx, 0xffffffc0
// 0046e819  7504                 jne 0x46e81f
// 0046e81b  33ff                 xor edi, edi
// 0046e81d  eb27                 jmp 0x46e846
// 0046e81f  3bd8                 cmp ebx, eax
// 0046e821  7606                 jbe 0x46e829
// 0046e823  ff1590288000         call dword ptr [0x802890]
// 0046e829  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0046e82d  8b06                 mov eax, dword ptr [esi]
// 0046e82f  85c9                 test ecx, ecx
// 0046e831  7404                 je 0x46e837
// 0046e833  3bc8                 cmp ecx, eax
// 0046e835  7406                 je 0x46e83d
// 0046e837  ff1590288000         call dword ptr [0x802890]
// 0046e83d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0046e841  2bfb                 sub edi, ebx
// 0046e843  c1ff06               sar edi, 6
// 0046e846  8b542428             mov edx, dword ptr [esp + 0x28]
// 0046e84a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0046e84e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0046e852  52                   push edx
// 0046e853  6a01                 push 1
// 0046e855  50                   push eax
// 0046e856  51                   push ecx
// 0046e857  8bce                 mov ecx, esi
// 0046e859  e8d2fbffff           call 0x46e430
// 0046e85e  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0046e861  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0046e864  7606                 jbe 0x46e86c
// 0046e866  ff1590288000         call dword ptr [0x802890]
// 0046e86c  8b36                 mov esi, dword ptr [esi]
// 0046e86e  8bee                 mov ebp, esi
// 0046e870  895c2414             mov dword ptr [esp + 0x14], ebx
// 0046e874  85f6                 test esi, esi
// 0046e876  751a                 jne 0x46e892
// 0046e878  ff1590288000         call dword ptr [0x802890]
// 0046e87e  33c0                 xor eax, eax
// 0046e880  c1e706               shl edi, 6
// 0046e883  03fb                 add edi, ebx
// 0046e885  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0046e888  7713                 ja 0x46e89d
// 0046e88a  85f6                 test esi, esi
// 0046e88c  7408                 je 0x46e896
// 0046e88e  8b36                 mov esi, dword ptr [esi]
// 0046e890  eb06                 jmp 0x46e898
// 0046e892  8b06                 mov eax, dword ptr [esi]
// 0046e894  ebea                 jmp 0x46e880
// 0046e896  33f6                 xor esi, esi
// 0046e898  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0046e89b  7306                 jae 0x46e8a3
// 0046e89d  ff1590288000         call dword ptr [0x802890]
// 0046e8a3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0046e8a7  897804               mov dword ptr [eax + 4], edi
// 0046e8aa  5f                   pop edi
// 0046e8ab  5e                   pop esi
// 0046e8ac  8928                 mov dword ptr [eax], ebp
// 0046e8ae  5d                   pop ebp
// 0046e8af  5b                   pop ebx
// 0046e8b0  83c408               add esp, 8
// 0046e8b3  c21000               ret 0x10
// standard library vector<pod64> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
