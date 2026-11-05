// from server: 100% by auto
// roc 2010-06 00731e10  unit: lua_exception  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00731e10
//
// 00731e10  83ec08               sub esp, 8
// 00731e13  53                   push ebx
// 00731e14  55                   push ebp
// 00731e15  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 00731e1b  56                   push esi
// 00731e1c  8bf1                 mov esi, ecx
// 00731e1e  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00731e21  57                   push edi
// 00731e22  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00731e25  8bcb                 mov ecx, ebx
// 00731e27  2bcf                 sub ecx, edi
// 00731e29  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00731e2e  f7e9                 imul ecx
// 00731e30  c1fa02               sar edx, 2
// 00731e33  8bc2                 mov eax, edx
// 00731e35  c1e81f               shr eax, 0x1f
// 00731e38  03c2                 add eax, edx
// 00731e3a  7504                 jne 0x731e40
// 00731e3c  33ff                 xor edi, edi
// 00731e3e  eb2d                 jmp 0x731e6d
// 00731e40  3bfb                 cmp edi, ebx
// 00731e42  7602                 jbe 0x731e46
// 00731e44  ffd5                 call ebp
// 00731e46  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00731e4a  8b06                 mov eax, dword ptr [esi]
// 00731e4c  85c9                 test ecx, ecx
// 00731e4e  7404                 je 0x731e54
// 00731e50  3bc8                 cmp ecx, eax
// 00731e52  7402                 je 0x731e56
// 00731e54  ffd5                 call ebp
// 00731e56  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00731e5a  2bcf                 sub ecx, edi
// 00731e5c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00731e61  f7e9                 imul ecx
// 00731e63  c1fa02               sar edx, 2
// 00731e66  8bfa                 mov edi, edx
// 00731e68  c1ef1f               shr edi, 0x1f
// 00731e6b  03fa                 add edi, edx
// 00731e6d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00731e71  8b542424             mov edx, dword ptr [esp + 0x24]
// 00731e75  8b442420             mov eax, dword ptr [esp + 0x20]
// 00731e79  51                   push ecx
// 00731e7a  6a01                 push 1
// 00731e7c  52                   push edx
// 00731e7d  50                   push eax
// 00731e7e  8bce                 mov ecx, esi
// 00731e80  e83bf8ffff           call 0x7316c0
// 00731e85  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00731e88  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00731e8b  7602                 jbe 0x731e8f
// 00731e8d  ffd5                 call ebp
// 00731e8f  8b36                 mov esi, dword ptr [esi]
// 00731e91  57                   push edi
// 00731e92  8d4c2414             lea ecx, [esp + 0x14]
// 00731e96  89742414             mov dword ptr [esp + 0x14], esi
// 00731e9a  895c2418             mov dword ptr [esp + 0x18], ebx
// 00731e9e  e8dde7ffff           call 0x730680
// 00731ea3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00731ea7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00731eab  8b542414             mov edx, dword ptr [esp + 0x14]
// 00731eaf  5f                   pop edi
// 00731eb0  5e                   pop esi
// 00731eb1  5d                   pop ebp
// 00731eb2  8908                 mov dword ptr [eax], ecx
// 00731eb4  895004               mov dword ptr [eax + 4], edx
// 00731eb7  5b                   pop ebx
// 00731eb8  83c408               add esp, 8
// 00731ebb  c21000               ret 0x10
// standard library vector<pod24> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
