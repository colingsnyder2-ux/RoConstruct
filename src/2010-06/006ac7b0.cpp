// from server: 100% by auto
// roc 2010-06 006ac7b0  unit: RBX::PriorityThreadPool::PriorityThreadPoolData  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006ac7b0
//
// 006ac7b0  83ec08               sub esp, 8
// 006ac7b3  53                   push ebx
// 006ac7b4  55                   push ebp
// 006ac7b5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 006ac7bb  56                   push esi
// 006ac7bc  8bf1                 mov esi, ecx
// 006ac7be  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 006ac7c1  57                   push edi
// 006ac7c2  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 006ac7c5  8bcb                 mov ecx, ebx
// 006ac7c7  2bcf                 sub ecx, edi
// 006ac7c9  b867666666           mov eax, 0x66666667
// 006ac7ce  f7e9                 imul ecx
// 006ac7d0  c1fa04               sar edx, 4
// 006ac7d3  8bc2                 mov eax, edx
// 006ac7d5  c1e81f               shr eax, 0x1f
// 006ac7d8  03c2                 add eax, edx
// 006ac7da  7504                 jne 0x6ac7e0
// 006ac7dc  33ff                 xor edi, edi
// 006ac7de  eb2d                 jmp 0x6ac80d
// 006ac7e0  3bfb                 cmp edi, ebx
// 006ac7e2  7602                 jbe 0x6ac7e6
// 006ac7e4  ffd5                 call ebp
// 006ac7e6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006ac7ea  8b06                 mov eax, dword ptr [esi]
// 006ac7ec  85c9                 test ecx, ecx
// 006ac7ee  7404                 je 0x6ac7f4
// 006ac7f0  3bc8                 cmp ecx, eax
// 006ac7f2  7402                 je 0x6ac7f6
// 006ac7f4  ffd5                 call ebp
// 006ac7f6  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006ac7fa  2bcf                 sub ecx, edi
// 006ac7fc  b867666666           mov eax, 0x66666667
// 006ac801  f7e9                 imul ecx
// 006ac803  c1fa04               sar edx, 4
// 006ac806  8bfa                 mov edi, edx
// 006ac808  c1ef1f               shr edi, 0x1f
// 006ac80b  03fa                 add edi, edx
// 006ac80d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006ac811  8b542424             mov edx, dword ptr [esp + 0x24]
// 006ac815  8b442420             mov eax, dword ptr [esp + 0x20]
// 006ac819  51                   push ecx
// 006ac81a  6a01                 push 1
// 006ac81c  52                   push edx
// 006ac81d  50                   push eax
// 006ac81e  8bce                 mov ecx, esi
// 006ac820  e8abf7ffff           call 0x6abfd0
// 006ac825  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 006ac828  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 006ac82b  7602                 jbe 0x6ac82f
// 006ac82d  ffd5                 call ebp
// 006ac82f  8b36                 mov esi, dword ptr [esi]
// 006ac831  57                   push edi
// 006ac832  8d4c2414             lea ecx, [esp + 0x14]
// 006ac836  89742414             mov dword ptr [esp + 0x14], esi
// 006ac83a  895c2418             mov dword ptr [esp + 0x18], ebx
// 006ac83e  e81ddaffff           call 0x6aa260
// 006ac843  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006ac847  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006ac84b  8b542414             mov edx, dword ptr [esp + 0x14]
// 006ac84f  5f                   pop edi
// 006ac850  5e                   pop esi
// 006ac851  5d                   pop ebp
// 006ac852  8908                 mov dword ptr [eax], ecx
// 006ac854  895004               mov dword ptr [eax + 4], edx
// 006ac857  5b                   pop ebx
// 006ac858  83c408               add esp, 8
// 006ac85b  c21000               ret 0x10
// standard library vector<pod40> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod40>
struct E { int v[10]; };
#include <vector>
template class std::vector<E>;
