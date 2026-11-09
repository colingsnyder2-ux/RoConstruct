// from server: 100% by auto
// roc 2010-06 00975e70  unit: RBX::RightAngleRampBuilder  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00975e70
//
// 00975e70  83ec08               sub esp, 8
// 00975e73  53                   push ebx
// 00975e74  55                   push ebp
// 00975e75  56                   push esi
// 00975e76  8bf1                 mov esi, ecx
// 00975e78  8b4610               mov eax, dword ptr [esi + 0x10]
// 00975e7b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00975e7e  8bc8                 mov ecx, eax
// 00975e80  2bcb                 sub ecx, ebx
// 00975e82  57                   push edi
// 00975e83  f7c1f0ffffff         test ecx, 0xfffffff0
// 00975e89  7504                 jne 0x975e8f
// 00975e8b  33ff                 xor edi, edi
// 00975e8d  eb27                 jmp 0x975eb6
// 00975e8f  3bd8                 cmp ebx, eax
// 00975e91  7606                 jbe 0x975e99
// 00975e93  ff150ca99e00         call dword ptr [0x9ea90c]
// 00975e99  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00975e9d  8b06                 mov eax, dword ptr [esi]
// 00975e9f  85c9                 test ecx, ecx
// 00975ea1  7404                 je 0x975ea7
// 00975ea3  3bc8                 cmp ecx, eax
// 00975ea5  7406                 je 0x975ead
// 00975ea7  ff150ca99e00         call dword ptr [0x9ea90c]
// 00975ead  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00975eb1  2bfb                 sub edi, ebx
// 00975eb3  c1ff04               sar edi, 4
// 00975eb6  8b542428             mov edx, dword ptr [esp + 0x28]
// 00975eba  8b442424             mov eax, dword ptr [esp + 0x24]
// 00975ebe  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00975ec2  52                   push edx
// 00975ec3  6a01                 push 1
// 00975ec5  50                   push eax
// 00975ec6  51                   push ecx
// 00975ec7  8bce                 mov ecx, esi
// 00975ec9  e842fdffff           call 0x975c10
// 00975ece  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00975ed1  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00975ed4  7606                 jbe 0x975edc
// 00975ed6  ff150ca99e00         call dword ptr [0x9ea90c]
// 00975edc  8b36                 mov esi, dword ptr [esi]
// 00975ede  8bee                 mov ebp, esi
// 00975ee0  895c2414             mov dword ptr [esp + 0x14], ebx
// 00975ee4  85f6                 test esi, esi
// 00975ee6  751a                 jne 0x975f02
// 00975ee8  ff150ca99e00         call dword ptr [0x9ea90c]
// 00975eee  33c0                 xor eax, eax
// 00975ef0  c1e704               shl edi, 4
// 00975ef3  03fb                 add edi, ebx
// 00975ef5  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00975ef8  7713                 ja 0x975f0d
// 00975efa  85f6                 test esi, esi
// 00975efc  7408                 je 0x975f06
// 00975efe  8b36                 mov esi, dword ptr [esi]
// 00975f00  eb06                 jmp 0x975f08
// 00975f02  8b06                 mov eax, dword ptr [esi]
// 00975f04  ebea                 jmp 0x975ef0
// 00975f06  33f6                 xor esi, esi
// 00975f08  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00975f0b  7306                 jae 0x975f13
// 00975f0d  ff150ca99e00         call dword ptr [0x9ea90c]
// 00975f13  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00975f17  897804               mov dword ptr [eax + 4], edi
// 00975f1a  5f                   pop edi
// 00975f1b  5e                   pop esi
// 00975f1c  8928                 mov dword ptr [eax], ebp
// 00975f1e  5d                   pop ebp
// 00975f1f  5b                   pop ebx
// 00975f20  83c408               add esp, 8
// 00975f23  c21000               ret 0x10
// standard library vector<pod16> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
