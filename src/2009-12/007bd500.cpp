// from server: 100% by auto
// roc 2009-12 007bd500  unit: RBX::GuiLayerCollector  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007bd500
//
// 007bd500  83ec08               sub esp, 8
// 007bd503  53                   push ebx
// 007bd504  55                   push ebp
// 007bd505  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 007bd50b  56                   push esi
// 007bd50c  8bf1                 mov esi, ecx
// 007bd50e  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 007bd511  57                   push edi
// 007bd512  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007bd515  8bcb                 mov ecx, ebx
// 007bd517  2bcf                 sub ecx, edi
// 007bd519  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007bd51e  f7e9                 imul ecx
// 007bd520  c1fa02               sar edx, 2
// 007bd523  8bc2                 mov eax, edx
// 007bd525  c1e81f               shr eax, 0x1f
// 007bd528  03c2                 add eax, edx
// 007bd52a  7504                 jne 0x7bd530
// 007bd52c  33ff                 xor edi, edi
// 007bd52e  eb2d                 jmp 0x7bd55d
// 007bd530  3bfb                 cmp edi, ebx
// 007bd532  7602                 jbe 0x7bd536
// 007bd534  ffd5                 call ebp
// 007bd536  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007bd53a  8b06                 mov eax, dword ptr [esi]
// 007bd53c  85c9                 test ecx, ecx
// 007bd53e  7404                 je 0x7bd544
// 007bd540  3bc8                 cmp ecx, eax
// 007bd542  7402                 je 0x7bd546
// 007bd544  ffd5                 call ebp
// 007bd546  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007bd54a  2bcf                 sub ecx, edi
// 007bd54c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007bd551  f7e9                 imul ecx
// 007bd553  c1fa02               sar edx, 2
// 007bd556  8bfa                 mov edi, edx
// 007bd558  c1ef1f               shr edi, 0x1f
// 007bd55b  03fa                 add edi, edx
// 007bd55d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007bd561  8b542424             mov edx, dword ptr [esp + 0x24]
// 007bd565  8b442420             mov eax, dword ptr [esp + 0x20]
// 007bd569  51                   push ecx
// 007bd56a  6a01                 push 1
// 007bd56c  52                   push edx
// 007bd56d  50                   push eax
// 007bd56e  8bce                 mov ecx, esi
// 007bd570  e82bfcffff           call 0x7bd1a0
// 007bd575  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 007bd578  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 007bd57b  7602                 jbe 0x7bd57f
// 007bd57d  ffd5                 call ebp
// 007bd57f  8b36                 mov esi, dword ptr [esi]
// 007bd581  57                   push edi
// 007bd582  8d4c2414             lea ecx, [esp + 0x14]
// 007bd586  89742414             mov dword ptr [esp + 0x14], esi
// 007bd58a  895c2418             mov dword ptr [esp + 0x18], ebx
// 007bd58e  e88da8fdff           call 0x797e20
// 007bd593  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007bd597  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007bd59b  8b542414             mov edx, dword ptr [esp + 0x14]
// 007bd59f  5f                   pop edi
// 007bd5a0  5e                   pop esi
// 007bd5a1  5d                   pop ebp
// 007bd5a2  8908                 mov dword ptr [eax], ecx
// 007bd5a4  895004               mov dword ptr [eax + 4], edx
// 007bd5a7  5b                   pop ebx
// 007bd5a8  83c408               add esp, 8
// 007bd5ab  c21000               ret 0x10
// standard library vector<pod24> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
