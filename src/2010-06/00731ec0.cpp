// from server: 100% by auto
// roc 2010-06 00731ec0  unit: lua_exception  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00731ec0
//
// 00731ec0  83ec08               sub esp, 8
// 00731ec3  53                   push ebx
// 00731ec4  55                   push ebp
// 00731ec5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 00731ecb  56                   push esi
// 00731ecc  8bf1                 mov esi, ecx
// 00731ece  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00731ed1  57                   push edi
// 00731ed2  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00731ed5  8bcb                 mov ecx, ebx
// 00731ed7  2bcf                 sub ecx, edi
// 00731ed9  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00731ede  f7e9                 imul ecx
// 00731ee0  c1fa02               sar edx, 2
// 00731ee3  8bc2                 mov eax, edx
// 00731ee5  c1e81f               shr eax, 0x1f
// 00731ee8  03c2                 add eax, edx
// 00731eea  7504                 jne 0x731ef0
// 00731eec  33ff                 xor edi, edi
// 00731eee  eb2d                 jmp 0x731f1d
// 00731ef0  3bfb                 cmp edi, ebx
// 00731ef2  7602                 jbe 0x731ef6
// 00731ef4  ffd5                 call ebp
// 00731ef6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00731efa  8b06                 mov eax, dword ptr [esi]
// 00731efc  85c9                 test ecx, ecx
// 00731efe  7404                 je 0x731f04
// 00731f00  3bc8                 cmp ecx, eax
// 00731f02  7402                 je 0x731f06
// 00731f04  ffd5                 call ebp
// 00731f06  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00731f0a  2bcf                 sub ecx, edi
// 00731f0c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00731f11  f7e9                 imul ecx
// 00731f13  c1fa02               sar edx, 2
// 00731f16  8bfa                 mov edi, edx
// 00731f18  c1ef1f               shr edi, 0x1f
// 00731f1b  03fa                 add edi, edx
// 00731f1d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00731f21  8b542424             mov edx, dword ptr [esp + 0x24]
// 00731f25  8b442420             mov eax, dword ptr [esp + 0x20]
// 00731f29  51                   push ecx
// 00731f2a  6a01                 push 1
// 00731f2c  52                   push edx
// 00731f2d  50                   push eax
// 00731f2e  8bce                 mov ecx, esi
// 00731f30  e8ebfaffff           call 0x731a20
// 00731f35  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00731f38  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00731f3b  7602                 jbe 0x731f3f
// 00731f3d  ffd5                 call ebp
// 00731f3f  8b36                 mov esi, dword ptr [esi]
// 00731f41  57                   push edi
// 00731f42  8d4c2414             lea ecx, [esp + 0x14]
// 00731f46  89742414             mov dword ptr [esp + 0x14], esi
// 00731f4a  895c2418             mov dword ptr [esp + 0x18], ebx
// 00731f4e  e82de7ffff           call 0x730680
// 00731f53  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00731f57  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00731f5b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00731f5f  5f                   pop edi
// 00731f60  5e                   pop esi
// 00731f61  5d                   pop ebp
// 00731f62  8908                 mov dword ptr [eax], ecx
// 00731f64  895004               mov dword ptr [eax + 4], edx
// 00731f67  5b                   pop ebx
// 00731f68  83c408               add esp, 8
// 00731f6b  c21000               ret 0x10
// standard library vector<pod24> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
