// from server: 100% by auto
// roc 2009-12 0072d140  unit: RBX::ThreadPool::ThreadPoolData  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0072d140
//
// 0072d140  83ec08               sub esp, 8
// 0072d143  53                   push ebx
// 0072d144  55                   push ebp
// 0072d145  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0072d14b  56                   push esi
// 0072d14c  8bf1                 mov esi, ecx
// 0072d14e  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0072d151  57                   push edi
// 0072d152  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0072d155  8bcb                 mov ecx, ebx
// 0072d157  2bcf                 sub ecx, edi
// 0072d159  b867666666           mov eax, 0x66666667
// 0072d15e  f7e9                 imul ecx
// 0072d160  c1fa04               sar edx, 4
// 0072d163  8bc2                 mov eax, edx
// 0072d165  c1e81f               shr eax, 0x1f
// 0072d168  03c2                 add eax, edx
// 0072d16a  7504                 jne 0x72d170
// 0072d16c  33ff                 xor edi, edi
// 0072d16e  eb2d                 jmp 0x72d19d
// 0072d170  3bfb                 cmp edi, ebx
// 0072d172  7602                 jbe 0x72d176
// 0072d174  ffd5                 call ebp
// 0072d176  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0072d17a  8b06                 mov eax, dword ptr [esi]
// 0072d17c  85c9                 test ecx, ecx
// 0072d17e  7404                 je 0x72d184
// 0072d180  3bc8                 cmp ecx, eax
// 0072d182  7402                 je 0x72d186
// 0072d184  ffd5                 call ebp
// 0072d186  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0072d18a  2bcf                 sub ecx, edi
// 0072d18c  b867666666           mov eax, 0x66666667
// 0072d191  f7e9                 imul ecx
// 0072d193  c1fa04               sar edx, 4
// 0072d196  8bfa                 mov edi, edx
// 0072d198  c1ef1f               shr edi, 0x1f
// 0072d19b  03fa                 add edi, edx
// 0072d19d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0072d1a1  8b542424             mov edx, dword ptr [esp + 0x24]
// 0072d1a5  8b442420             mov eax, dword ptr [esp + 0x20]
// 0072d1a9  51                   push ecx
// 0072d1aa  6a01                 push 1
// 0072d1ac  52                   push edx
// 0072d1ad  50                   push eax
// 0072d1ae  8bce                 mov ecx, esi
// 0072d1b0  e80bfaffff           call 0x72cbc0
// 0072d1b5  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0072d1b8  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0072d1bb  7602                 jbe 0x72d1bf
// 0072d1bd  ffd5                 call ebp
// 0072d1bf  8b36                 mov esi, dword ptr [esi]
// 0072d1c1  57                   push edi
// 0072d1c2  8d4c2414             lea ecx, [esp + 0x14]
// 0072d1c6  89742414             mov dword ptr [esp + 0x14], esi
// 0072d1ca  895c2418             mov dword ptr [esp + 0x18], ebx
// 0072d1ce  e87de5ffff           call 0x72b750
// 0072d1d3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0072d1d7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0072d1db  8b542414             mov edx, dword ptr [esp + 0x14]
// 0072d1df  5f                   pop edi
// 0072d1e0  5e                   pop esi
// 0072d1e1  5d                   pop ebp
// 0072d1e2  8908                 mov dword ptr [eax], ecx
// 0072d1e4  895004               mov dword ptr [eax + 4], edx
// 0072d1e7  5b                   pop ebx
// 0072d1e8  83c408               add esp, 8
// 0072d1eb  c21000               ret 0x10
// standard library vector<pod40> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod40>
struct E { int v[10]; };
#include <vector>
template class std::vector<E>;
