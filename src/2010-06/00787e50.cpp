// from server: 100% by auto
// roc 2010-06 00787e50  unit: RBX::HUMAN::GettingUp  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00787e50
//
// 00787e50  83ec08               sub esp, 8
// 00787e53  53                   push ebx
// 00787e54  55                   push ebp
// 00787e55  56                   push esi
// 00787e56  8bf1                 mov esi, ecx
// 00787e58  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00787e5b  57                   push edi
// 00787e5c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00787e5f  8bcb                 mov ecx, ebx
// 00787e61  2bcf                 sub ecx, edi
// 00787e63  b867666666           mov eax, 0x66666667
// 00787e68  f7e9                 imul ecx
// 00787e6a  c1fa03               sar edx, 3
// 00787e6d  8bc2                 mov eax, edx
// 00787e6f  c1e81f               shr eax, 0x1f
// 00787e72  03c2                 add eax, edx
// 00787e74  7504                 jne 0x787e7a
// 00787e76  33ff                 xor edi, edi
// 00787e78  eb35                 jmp 0x787eaf
// 00787e7a  3bfb                 cmp edi, ebx
// 00787e7c  7606                 jbe 0x787e84
// 00787e7e  ff150ca99e00         call dword ptr [0x9ea90c]
// 00787e84  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00787e88  8b06                 mov eax, dword ptr [esi]
// 00787e8a  85c9                 test ecx, ecx
// 00787e8c  7404                 je 0x787e92
// 00787e8e  3bc8                 cmp ecx, eax
// 00787e90  7406                 je 0x787e98
// 00787e92  ff150ca99e00         call dword ptr [0x9ea90c]
// 00787e98  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00787e9c  2bcf                 sub ecx, edi
// 00787e9e  b867666666           mov eax, 0x66666667
// 00787ea3  f7e9                 imul ecx
// 00787ea5  c1fa03               sar edx, 3
// 00787ea8  8bfa                 mov edi, edx
// 00787eaa  c1ef1f               shr edi, 0x1f
// 00787ead  03fa                 add edi, edx
// 00787eaf  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00787eb3  8b542424             mov edx, dword ptr [esp + 0x24]
// 00787eb7  8b442420             mov eax, dword ptr [esp + 0x20]
// 00787ebb  51                   push ecx
// 00787ebc  6a01                 push 1
// 00787ebe  52                   push edx
// 00787ebf  50                   push eax
// 00787ec0  8bce                 mov ecx, esi
// 00787ec2  e8c9fbffff           call 0x787a90
// 00787ec7  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00787eca  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00787ecd  7606                 jbe 0x787ed5
// 00787ecf  ff150ca99e00         call dword ptr [0x9ea90c]
// 00787ed5  8b36                 mov esi, dword ptr [esi]
// 00787ed7  8bee                 mov ebp, esi
// 00787ed9  895c2414             mov dword ptr [esp + 0x14], ebx
// 00787edd  85f6                 test esi, esi
// 00787edf  751b                 jne 0x787efc
// 00787ee1  ff150ca99e00         call dword ptr [0x9ea90c]
// 00787ee7  33c0                 xor eax, eax
// 00787ee9  8d0cbf               lea ecx, [edi + edi*4]
// 00787eec  8d3c8b               lea edi, [ebx + ecx*4]
// 00787eef  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00787ef2  7713                 ja 0x787f07
// 00787ef4  85f6                 test esi, esi
// 00787ef6  7408                 je 0x787f00
// 00787ef8  8b36                 mov esi, dword ptr [esi]
// 00787efa  eb06                 jmp 0x787f02
// 00787efc  8b06                 mov eax, dword ptr [esi]
// 00787efe  ebe9                 jmp 0x787ee9
// 00787f00  33f6                 xor esi, esi
// 00787f02  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00787f05  7306                 jae 0x787f0d
// 00787f07  ff150ca99e00         call dword ptr [0x9ea90c]
// 00787f0d  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00787f11  897804               mov dword ptr [eax + 4], edi
// 00787f14  5f                   pop edi
// 00787f15  5e                   pop esi
// 00787f16  8928                 mov dword ptr [eax], ebp
// 00787f18  5d                   pop ebp
// 00787f19  5b                   pop ebx
// 00787f1a  83c408               add esp, 8
// 00787f1d  c21000               ret 0x10
// standard library vector<pod20> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
