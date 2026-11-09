// from server: 100% by auto
// roc 2008-06 005611f0  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005611f0
//
// 005611f0  83ec08               sub esp, 8
// 005611f3  53                   push ebx
// 005611f4  55                   push ebp
// 005611f5  56                   push esi
// 005611f6  8bf1                 mov esi, ecx
// 005611f8  8b4610               mov eax, dword ptr [esi + 0x10]
// 005611fb  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005611fe  8bc8                 mov ecx, eax
// 00561200  2bcb                 sub ecx, ebx
// 00561202  57                   push edi
// 00561203  f7c1e0ffffff         test ecx, 0xffffffe0
// 00561209  7504                 jne 0x56120f
// 0056120b  33ff                 xor edi, edi
// 0056120d  eb27                 jmp 0x561236
// 0056120f  3bd8                 cmp ebx, eax
// 00561211  7606                 jbe 0x561219
// 00561213  ff1590288000         call dword ptr [0x802890]
// 00561219  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0056121d  8b06                 mov eax, dword ptr [esi]
// 0056121f  85c9                 test ecx, ecx
// 00561221  7404                 je 0x561227
// 00561223  3bc8                 cmp ecx, eax
// 00561225  7406                 je 0x56122d
// 00561227  ff1590288000         call dword ptr [0x802890]
// 0056122d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00561231  2bfb                 sub edi, ebx
// 00561233  c1ff05               sar edi, 5
// 00561236  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056123a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0056123e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00561242  52                   push edx
// 00561243  6a01                 push 1
// 00561245  50                   push eax
// 00561246  51                   push ecx
// 00561247  8bce                 mov ecx, esi
// 00561249  e8d2f9ffff           call 0x560c20
// 0056124e  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00561251  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00561254  7606                 jbe 0x56125c
// 00561256  ff1590288000         call dword ptr [0x802890]
// 0056125c  8b36                 mov esi, dword ptr [esi]
// 0056125e  8bee                 mov ebp, esi
// 00561260  895c2414             mov dword ptr [esp + 0x14], ebx
// 00561264  85f6                 test esi, esi
// 00561266  751a                 jne 0x561282
// 00561268  ff1590288000         call dword ptr [0x802890]
// 0056126e  33c0                 xor eax, eax
// 00561270  c1e705               shl edi, 5
// 00561273  03fb                 add edi, ebx
// 00561275  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00561278  7713                 ja 0x56128d
// 0056127a  85f6                 test esi, esi
// 0056127c  7408                 je 0x561286
// 0056127e  8b36                 mov esi, dword ptr [esi]
// 00561280  eb06                 jmp 0x561288
// 00561282  8b06                 mov eax, dword ptr [esi]
// 00561284  ebea                 jmp 0x561270
// 00561286  33f6                 xor esi, esi
// 00561288  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0056128b  7306                 jae 0x561293
// 0056128d  ff1590288000         call dword ptr [0x802890]
// 00561293  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00561297  897804               mov dword ptr [eax + 4], edi
// 0056129a  5f                   pop edi
// 0056129b  5e                   pop esi
// 0056129c  8928                 mov dword ptr [eax], ebp
// 0056129e  5d                   pop ebp
// 0056129f  5b                   pop ebx
// 005612a0  83c408               add esp, 8
// 005612a3  c21000               ret 0x10
// standard library vector<pod32> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
