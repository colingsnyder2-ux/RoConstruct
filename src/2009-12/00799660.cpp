// from server: 100% by auto
// roc 2009-12 00799660  unit: lua_exception  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00799660
//
// 00799660  83ec08               sub esp, 8
// 00799663  53                   push ebx
// 00799664  55                   push ebp
// 00799665  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0079966b  56                   push esi
// 0079966c  8bf1                 mov esi, ecx
// 0079966e  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00799671  57                   push edi
// 00799672  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00799675  8bcb                 mov ecx, ebx
// 00799677  2bcf                 sub ecx, edi
// 00799679  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0079967e  f7e9                 imul ecx
// 00799680  c1fa02               sar edx, 2
// 00799683  8bc2                 mov eax, edx
// 00799685  c1e81f               shr eax, 0x1f
// 00799688  03c2                 add eax, edx
// 0079968a  7504                 jne 0x799690
// 0079968c  33ff                 xor edi, edi
// 0079968e  eb2d                 jmp 0x7996bd
// 00799690  3bfb                 cmp edi, ebx
// 00799692  7602                 jbe 0x799696
// 00799694  ffd5                 call ebp
// 00799696  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0079969a  8b06                 mov eax, dword ptr [esi]
// 0079969c  85c9                 test ecx, ecx
// 0079969e  7404                 je 0x7996a4
// 007996a0  3bc8                 cmp ecx, eax
// 007996a2  7402                 je 0x7996a6
// 007996a4  ffd5                 call ebp
// 007996a6  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007996aa  2bcf                 sub ecx, edi
// 007996ac  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007996b1  f7e9                 imul ecx
// 007996b3  c1fa02               sar edx, 2
// 007996b6  8bfa                 mov edi, edx
// 007996b8  c1ef1f               shr edi, 0x1f
// 007996bb  03fa                 add edi, edx
// 007996bd  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007996c1  8b542424             mov edx, dword ptr [esp + 0x24]
// 007996c5  8b442420             mov eax, dword ptr [esp + 0x20]
// 007996c9  51                   push ecx
// 007996ca  6a01                 push 1
// 007996cc  52                   push edx
// 007996cd  50                   push eax
// 007996ce  8bce                 mov ecx, esi
// 007996d0  e8ebfaffff           call 0x7991c0
// 007996d5  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 007996d8  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 007996db  7602                 jbe 0x7996df
// 007996dd  ffd5                 call ebp
// 007996df  8b36                 mov esi, dword ptr [esi]
// 007996e1  57                   push edi
// 007996e2  8d4c2414             lea ecx, [esp + 0x14]
// 007996e6  89742414             mov dword ptr [esp + 0x14], esi
// 007996ea  895c2418             mov dword ptr [esp + 0x18], ebx
// 007996ee  e82de7ffff           call 0x797e20
// 007996f3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007996f7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007996fb  8b542414             mov edx, dword ptr [esp + 0x14]
// 007996ff  5f                   pop edi
// 00799700  5e                   pop esi
// 00799701  5d                   pop ebp
// 00799702  8908                 mov dword ptr [eax], ecx
// 00799704  895004               mov dword ptr [eax + 4], edx
// 00799707  5b                   pop ebx
// 00799708  83c408               add esp, 8
// 0079970b  c21000               ret 0x10
// standard library vector<pod24> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
