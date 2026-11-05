// from server: 100% by auto
// roc 2009-12 005ddb70  unit: RBX::AdornG3D  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005ddb70
//
// 005ddb70  83ec08               sub esp, 8
// 005ddb73  53                   push ebx
// 005ddb74  55                   push ebp
// 005ddb75  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 005ddb7b  56                   push esi
// 005ddb7c  8bf1                 mov esi, ecx
// 005ddb7e  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005ddb81  57                   push edi
// 005ddb82  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005ddb85  8bcb                 mov ecx, ebx
// 005ddb87  2bcf                 sub ecx, edi
// 005ddb89  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005ddb8e  f7e9                 imul ecx
// 005ddb90  c1fa02               sar edx, 2
// 005ddb93  8bc2                 mov eax, edx
// 005ddb95  c1e81f               shr eax, 0x1f
// 005ddb98  03c2                 add eax, edx
// 005ddb9a  7504                 jne 0x5ddba0
// 005ddb9c  33ff                 xor edi, edi
// 005ddb9e  eb2d                 jmp 0x5ddbcd
// 005ddba0  3bfb                 cmp edi, ebx
// 005ddba2  7602                 jbe 0x5ddba6
// 005ddba4  ffd5                 call ebp
// 005ddba6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005ddbaa  8b06                 mov eax, dword ptr [esi]
// 005ddbac  85c9                 test ecx, ecx
// 005ddbae  7404                 je 0x5ddbb4
// 005ddbb0  3bc8                 cmp ecx, eax
// 005ddbb2  7402                 je 0x5ddbb6
// 005ddbb4  ffd5                 call ebp
// 005ddbb6  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005ddbba  2bcf                 sub ecx, edi
// 005ddbbc  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005ddbc1  f7e9                 imul ecx
// 005ddbc3  c1fa02               sar edx, 2
// 005ddbc6  8bfa                 mov edi, edx
// 005ddbc8  c1ef1f               shr edi, 0x1f
// 005ddbcb  03fa                 add edi, edx
// 005ddbcd  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005ddbd1  8b542424             mov edx, dword ptr [esp + 0x24]
// 005ddbd5  8b442420             mov eax, dword ptr [esp + 0x20]
// 005ddbd9  51                   push ecx
// 005ddbda  6a01                 push 1
// 005ddbdc  52                   push edx
// 005ddbdd  50                   push eax
// 005ddbde  8bce                 mov ecx, esi
// 005ddbe0  e85bfbffff           call 0x5dd740
// 005ddbe5  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005ddbe8  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 005ddbeb  7602                 jbe 0x5ddbef
// 005ddbed  ffd5                 call ebp
// 005ddbef  8b36                 mov esi, dword ptr [esi]
// 005ddbf1  57                   push edi
// 005ddbf2  8d4c2414             lea ecx, [esp + 0x14]
// 005ddbf6  89742414             mov dword ptr [esp + 0x14], esi
// 005ddbfa  895c2418             mov dword ptr [esp + 0x18], ebx
// 005ddbfe  e81da21b00           call 0x797e20
// 005ddc03  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005ddc07  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005ddc0b  8b542414             mov edx, dword ptr [esp + 0x14]
// 005ddc0f  5f                   pop edi
// 005ddc10  5e                   pop esi
// 005ddc11  5d                   pop ebp
// 005ddc12  8908                 mov dword ptr [eax], ecx
// 005ddc14  895004               mov dword ptr [eax + 4], edx
// 005ddc17  5b                   pop ebx
// 005ddc18  83c408               add esp, 8
// 005ddc1b  c21000               ret 0x10
// standard library vector<pod24> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
