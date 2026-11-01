// from server: 100% by auto
// roc 2009-12 0048dcc0  unit: G3D::Shader  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048dcc0
//
// 0048dcc0  83ec08               sub esp, 8
// 0048dcc3  53                   push ebx
// 0048dcc4  55                   push ebp
// 0048dcc5  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0048dccb  56                   push esi
// 0048dccc  8bf1                 mov esi, ecx
// 0048dcce  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0048dcd1  57                   push edi
// 0048dcd2  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0048dcd5  8bcb                 mov ecx, ebx
// 0048dcd7  2bcf                 sub ecx, edi
// 0048dcd9  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0048dcde  f7e9                 imul ecx
// 0048dce0  c1fa02               sar edx, 2
// 0048dce3  8bc2                 mov eax, edx
// 0048dce5  c1e81f               shr eax, 0x1f
// 0048dce8  03c2                 add eax, edx
// 0048dcea  7504                 jne 0x48dcf0
// 0048dcec  33ff                 xor edi, edi
// 0048dcee  eb2d                 jmp 0x48dd1d
// 0048dcf0  3bfb                 cmp edi, ebx
// 0048dcf2  7602                 jbe 0x48dcf6
// 0048dcf4  ffd5                 call ebp
// 0048dcf6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0048dcfa  8b06                 mov eax, dword ptr [esi]
// 0048dcfc  85c9                 test ecx, ecx
// 0048dcfe  7404                 je 0x48dd04
// 0048dd00  3bc8                 cmp ecx, eax
// 0048dd02  7402                 je 0x48dd06
// 0048dd04  ffd5                 call ebp
// 0048dd06  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0048dd0a  2bcf                 sub ecx, edi
// 0048dd0c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0048dd11  f7e9                 imul ecx
// 0048dd13  c1fa02               sar edx, 2
// 0048dd16  8bfa                 mov edi, edx
// 0048dd18  c1ef1f               shr edi, 0x1f
// 0048dd1b  03fa                 add edi, edx
// 0048dd1d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0048dd21  8b542424             mov edx, dword ptr [esp + 0x24]
// 0048dd25  8b442420             mov eax, dword ptr [esp + 0x20]
// 0048dd29  51                   push ecx
// 0048dd2a  6a01                 push 1
// 0048dd2c  52                   push edx
// 0048dd2d  50                   push eax
// 0048dd2e  8bce                 mov ecx, esi
// 0048dd30  e82bf4ffff           call 0x48d160
// 0048dd35  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0048dd38  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0048dd3b  7602                 jbe 0x48dd3f
// 0048dd3d  ffd5                 call ebp
// 0048dd3f  8b36                 mov esi, dword ptr [esi]
// 0048dd41  57                   push edi
// 0048dd42  8d4c2414             lea ecx, [esp + 0x14]
// 0048dd46  89742414             mov dword ptr [esp + 0x14], esi
// 0048dd4a  895c2418             mov dword ptr [esp + 0x18], ebx
// 0048dd4e  e8cda03000           call 0x797e20
// 0048dd53  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048dd57  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0048dd5b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0048dd5f  5f                   pop edi
// 0048dd60  5e                   pop esi
// 0048dd61  5d                   pop ebp
// 0048dd62  8908                 mov dword ptr [eax], ecx
// 0048dd64  895004               mov dword ptr [eax + 4], edx
// 0048dd67  5b                   pop ebx
// 0048dd68  83c408               add esp, 8
// 0048dd6b  c21000               ret 0x10
// standard library vector<pod24> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
