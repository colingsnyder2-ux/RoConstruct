// from server: 100% by auto
// roc 2010-06 00743510  unit: RBX::VHttp::?$sp_counted_impl_p  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00743510
//
// 00743510  83ec08               sub esp, 8
// 00743513  53                   push ebx
// 00743514  55                   push ebp
// 00743515  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0074351b  56                   push esi
// 0074351c  8bf1                 mov esi, ecx
// 0074351e  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00743521  57                   push edi
// 00743522  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00743525  8bcb                 mov ecx, ebx
// 00743527  2bcf                 sub ecx, edi
// 00743529  b867666666           mov eax, 0x66666667
// 0074352e  f7e9                 imul ecx
// 00743530  c1fa04               sar edx, 4
// 00743533  8bc2                 mov eax, edx
// 00743535  c1e81f               shr eax, 0x1f
// 00743538  03c2                 add eax, edx
// 0074353a  7504                 jne 0x743540
// 0074353c  33ff                 xor edi, edi
// 0074353e  eb2d                 jmp 0x74356d
// 00743540  3bfb                 cmp edi, ebx
// 00743542  7602                 jbe 0x743546
// 00743544  ffd5                 call ebp
// 00743546  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0074354a  8b06                 mov eax, dword ptr [esi]
// 0074354c  85c9                 test ecx, ecx
// 0074354e  7404                 je 0x743554
// 00743550  3bc8                 cmp ecx, eax
// 00743552  7402                 je 0x743556
// 00743554  ffd5                 call ebp
// 00743556  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0074355a  2bcf                 sub ecx, edi
// 0074355c  b867666666           mov eax, 0x66666667
// 00743561  f7e9                 imul ecx
// 00743563  c1fa04               sar edx, 4
// 00743566  8bfa                 mov edi, edx
// 00743568  c1ef1f               shr edi, 0x1f
// 0074356b  03fa                 add edi, edx
// 0074356d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00743571  8b542424             mov edx, dword ptr [esp + 0x24]
// 00743575  8b442420             mov eax, dword ptr [esp + 0x20]
// 00743579  51                   push ecx
// 0074357a  6a01                 push 1
// 0074357c  52                   push edx
// 0074357d  50                   push eax
// 0074357e  8bce                 mov ecx, esi
// 00743580  e8dbf5ffff           call 0x742b60
// 00743585  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00743588  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0074358b  7602                 jbe 0x74358f
// 0074358d  ffd5                 call ebp
// 0074358f  8b36                 mov esi, dword ptr [esi]
// 00743591  57                   push edi
// 00743592  8d4c2414             lea ecx, [esp + 0x14]
// 00743596  89742414             mov dword ptr [esp + 0x14], esi
// 0074359a  895c2418             mov dword ptr [esp + 0x18], ebx
// 0074359e  e8bd6cf6ff           call 0x6aa260
// 007435a3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007435a7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007435ab  8b542414             mov edx, dword ptr [esp + 0x14]
// 007435af  5f                   pop edi
// 007435b0  5e                   pop esi
// 007435b1  5d                   pop ebp
// 007435b2  8908                 mov dword ptr [eax], ecx
// 007435b4  895004               mov dword ptr [eax + 4], edx
// 007435b7  5b                   pop ebx
// 007435b8  83c408               add esp, 8
// 007435bb  c21000               ret 0x10
// standard library vector<pod40> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod40>
struct E { int v[10]; };
#include <vector>
template class std::vector<E>;
