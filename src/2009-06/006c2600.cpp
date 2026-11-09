// from server: 100% by auto
// roc 2009-06 006c2600  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c2600
//
// 006c2600  83ec08               sub esp, 8
// 006c2603  53                   push ebx
// 006c2604  55                   push ebp
// 006c2605  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 006c260b  56                   push esi
// 006c260c  8bf1                 mov esi, ecx
// 006c260e  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 006c2611  57                   push edi
// 006c2612  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 006c2615  8bcb                 mov ecx, ebx
// 006c2617  2bcf                 sub ecx, edi
// 006c2619  b8abaaaa2a           mov eax, 0x2aaaaaab
// 006c261e  f7e9                 imul ecx
// 006c2620  c1fa02               sar edx, 2
// 006c2623  8bc2                 mov eax, edx
// 006c2625  c1e81f               shr eax, 0x1f
// 006c2628  03c2                 add eax, edx
// 006c262a  7504                 jne 0x6c2630
// 006c262c  33ff                 xor edi, edi
// 006c262e  eb2d                 jmp 0x6c265d
// 006c2630  3bfb                 cmp edi, ebx
// 006c2632  7602                 jbe 0x6c2636
// 006c2634  ffd5                 call ebp
// 006c2636  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006c263a  8b06                 mov eax, dword ptr [esi]
// 006c263c  85c9                 test ecx, ecx
// 006c263e  7404                 je 0x6c2644
// 006c2640  3bc8                 cmp ecx, eax
// 006c2642  7402                 je 0x6c2646
// 006c2644  ffd5                 call ebp
// 006c2646  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006c264a  2bcf                 sub ecx, edi
// 006c264c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 006c2651  f7e9                 imul ecx
// 006c2653  c1fa02               sar edx, 2
// 006c2656  8bfa                 mov edi, edx
// 006c2658  c1ef1f               shr edi, 0x1f
// 006c265b  03fa                 add edi, edx
// 006c265d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006c2661  8b542424             mov edx, dword ptr [esp + 0x24]
// 006c2665  8b442420             mov eax, dword ptr [esp + 0x20]
// 006c2669  51                   push ecx
// 006c266a  6a01                 push 1
// 006c266c  52                   push edx
// 006c266d  50                   push eax
// 006c266e  8bce                 mov ecx, esi
// 006c2670  e8cbfbffff           call 0x6c2240
// 006c2675  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 006c2678  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 006c267b  7602                 jbe 0x6c267f
// 006c267d  ffd5                 call ebp
// 006c267f  8b36                 mov esi, dword ptr [esi]
// 006c2681  57                   push edi
// 006c2682  8d4c2414             lea ecx, [esp + 0x14]
// 006c2686  89742414             mov dword ptr [esp + 0x14], esi
// 006c268a  895c2418             mov dword ptr [esp + 0x18], ebx
// 006c268e  e80df4ffff           call 0x6c1aa0
// 006c2693  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006c2697  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006c269b  8b542414             mov edx, dword ptr [esp + 0x14]
// 006c269f  5f                   pop edi
// 006c26a0  5e                   pop esi
// 006c26a1  5d                   pop ebp
// 006c26a2  8908                 mov dword ptr [eax], ecx
// 006c26a4  895004               mov dword ptr [eax + 4], edx
// 006c26a7  5b                   pop ebx
// 006c26a8  83c408               add esp, 8
// 006c26ab  c21000               ret 0x10
// standard library vector<pod24> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
