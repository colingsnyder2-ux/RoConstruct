// from server: 100% by auto
// roc 2010-06 0053d9f0  unit: RBX::AdornG3D  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0053d9f0
//
// 0053d9f0  83ec08               sub esp, 8
// 0053d9f3  53                   push ebx
// 0053d9f4  55                   push ebp
// 0053d9f5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0053d9fb  56                   push esi
// 0053d9fc  8bf1                 mov esi, ecx
// 0053d9fe  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0053da01  57                   push edi
// 0053da02  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0053da05  8bcb                 mov ecx, ebx
// 0053da07  2bcf                 sub ecx, edi
// 0053da09  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0053da0e  f7e9                 imul ecx
// 0053da10  c1fa02               sar edx, 2
// 0053da13  8bc2                 mov eax, edx
// 0053da15  c1e81f               shr eax, 0x1f
// 0053da18  03c2                 add eax, edx
// 0053da1a  7504                 jne 0x53da20
// 0053da1c  33ff                 xor edi, edi
// 0053da1e  eb2d                 jmp 0x53da4d
// 0053da20  3bfb                 cmp edi, ebx
// 0053da22  7602                 jbe 0x53da26
// 0053da24  ffd5                 call ebp
// 0053da26  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0053da2a  8b06                 mov eax, dword ptr [esi]
// 0053da2c  85c9                 test ecx, ecx
// 0053da2e  7404                 je 0x53da34
// 0053da30  3bc8                 cmp ecx, eax
// 0053da32  7402                 je 0x53da36
// 0053da34  ffd5                 call ebp
// 0053da36  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0053da3a  2bcf                 sub ecx, edi
// 0053da3c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0053da41  f7e9                 imul ecx
// 0053da43  c1fa02               sar edx, 2
// 0053da46  8bfa                 mov edi, edx
// 0053da48  c1ef1f               shr edi, 0x1f
// 0053da4b  03fa                 add edi, edx
// 0053da4d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0053da51  8b542424             mov edx, dword ptr [esp + 0x24]
// 0053da55  8b442420             mov eax, dword ptr [esp + 0x20]
// 0053da59  51                   push ecx
// 0053da5a  6a01                 push 1
// 0053da5c  52                   push edx
// 0053da5d  50                   push eax
// 0053da5e  8bce                 mov ecx, esi
// 0053da60  e85bfbffff           call 0x53d5c0
// 0053da65  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0053da68  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0053da6b  7602                 jbe 0x53da6f
// 0053da6d  ffd5                 call ebp
// 0053da6f  8b36                 mov esi, dword ptr [esi]
// 0053da71  57                   push edi
// 0053da72  8d4c2414             lea ecx, [esp + 0x14]
// 0053da76  89742414             mov dword ptr [esp + 0x14], esi
// 0053da7a  895c2418             mov dword ptr [esp + 0x18], ebx
// 0053da7e  e8fd2b1f00           call 0x730680
// 0053da83  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053da87  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0053da8b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0053da8f  5f                   pop edi
// 0053da90  5e                   pop esi
// 0053da91  5d                   pop ebp
// 0053da92  8908                 mov dword ptr [eax], ecx
// 0053da94  895004               mov dword ptr [eax + 4], edx
// 0053da97  5b                   pop ebx
// 0053da98  83c408               add esp, 8
// 0053da9b  c21000               ret 0x10
// standard library vector<pod24> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
