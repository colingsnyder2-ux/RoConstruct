// from server: 100% by auto
// roc 2010-06 007897a0  unit: RBX::HUMAN::GettingUp  size: 211 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007897a0
//
// 007897a0  83ec08               sub esp, 8
// 007897a3  53                   push ebx
// 007897a4  55                   push ebp
// 007897a5  56                   push esi
// 007897a6  8bf1                 mov esi, ecx
// 007897a8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 007897ab  57                   push edi
// 007897ac  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007897af  8bcb                 mov ecx, ebx
// 007897b1  2bcf                 sub ecx, edi
// 007897b3  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007897b8  f7e9                 imul ecx
// 007897ba  c1fa03               sar edx, 3
// 007897bd  8bc2                 mov eax, edx
// 007897bf  c1e81f               shr eax, 0x1f
// 007897c2  03c2                 add eax, edx
// 007897c4  7504                 jne 0x7897ca
// 007897c6  33ff                 xor edi, edi
// 007897c8  eb35                 jmp 0x7897ff
// 007897ca  3bfb                 cmp edi, ebx
// 007897cc  7606                 jbe 0x7897d4
// 007897ce  ff150ca99e00         call dword ptr [0x9ea90c]
// 007897d4  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007897d8  8b06                 mov eax, dword ptr [esi]
// 007897da  85c9                 test ecx, ecx
// 007897dc  7404                 je 0x7897e2
// 007897de  3bc8                 cmp ecx, eax
// 007897e0  7406                 je 0x7897e8
// 007897e2  ff150ca99e00         call dword ptr [0x9ea90c]
// 007897e8  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007897ec  2bcf                 sub ecx, edi
// 007897ee  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007897f3  f7e9                 imul ecx
// 007897f5  c1fa03               sar edx, 3
// 007897f8  8bfa                 mov edi, edx
// 007897fa  c1ef1f               shr edi, 0x1f
// 007897fd  03fa                 add edi, edx
// 007897ff  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00789803  8b542424             mov edx, dword ptr [esp + 0x24]
// 00789807  8b442420             mov eax, dword ptr [esp + 0x20]
// 0078980b  51                   push ecx
// 0078980c  6a01                 push 1
// 0078980e  52                   push edx
// 0078980f  50                   push eax
// 00789810  8bce                 mov ecx, esi
// 00789812  e8c9faffff           call 0x7892e0
// 00789817  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0078981a  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0078981d  7606                 jbe 0x789825
// 0078981f  ff150ca99e00         call dword ptr [0x9ea90c]
// 00789825  8b36                 mov esi, dword ptr [esi]
// 00789827  8bee                 mov ebp, esi
// 00789829  895c2414             mov dword ptr [esp + 0x14], ebx
// 0078982d  85f6                 test esi, esi
// 0078982f  751e                 jne 0x78984f
// 00789831  ff150ca99e00         call dword ptr [0x9ea90c]
// 00789837  33c0                 xor eax, eax
// 00789839  8d0c7f               lea ecx, [edi + edi*2]
// 0078983c  c1e104               shl ecx, 4
// 0078983f  8d3c19               lea edi, [ecx + ebx]
// 00789842  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00789845  7713                 ja 0x78985a
// 00789847  85f6                 test esi, esi
// 00789849  7408                 je 0x789853
// 0078984b  8b36                 mov esi, dword ptr [esi]
// 0078984d  eb06                 jmp 0x789855
// 0078984f  8b06                 mov eax, dword ptr [esi]
// 00789851  ebe6                 jmp 0x789839
// 00789853  33f6                 xor esi, esi
// 00789855  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00789858  7306                 jae 0x789860
// 0078985a  ff150ca99e00         call dword ptr [0x9ea90c]
// 00789860  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00789864  897804               mov dword ptr [eax + 4], edi
// 00789867  5f                   pop edi
// 00789868  5e                   pop esi
// 00789869  8928                 mov dword ptr [eax], ebp
// 0078986b  5d                   pop ebp
// 0078986c  5b                   pop ebx
// 0078986d  83c408               add esp, 8
// 00789870  c21000               ret 0x10
// standard library vector<pod48> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod48>
struct E { int v[12]; };
#include <vector>
template class std::vector<E>;
