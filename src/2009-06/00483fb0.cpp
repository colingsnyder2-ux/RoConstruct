// from server: 100% by auto
// roc 2009-06 00483fb0  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00483fb0
//
// 00483fb0  83ec08               sub esp, 8
// 00483fb3  53                   push ebx
// 00483fb4  55                   push ebp
// 00483fb5  56                   push esi
// 00483fb6  8bf1                 mov esi, ecx
// 00483fb8  8b4610               mov eax, dword ptr [esi + 0x10]
// 00483fbb  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00483fbe  8bc8                 mov ecx, eax
// 00483fc0  2bcb                 sub ecx, ebx
// 00483fc2  57                   push edi
// 00483fc3  f7c1f0ffffff         test ecx, 0xfffffff0
// 00483fc9  7504                 jne 0x483fcf
// 00483fcb  33ff                 xor edi, edi
// 00483fcd  eb27                 jmp 0x483ff6
// 00483fcf  3bd8                 cmp ebx, eax
// 00483fd1  7606                 jbe 0x483fd9
// 00483fd3  ff15ace98900         call dword ptr [0x89e9ac]
// 00483fd9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00483fdd  8b06                 mov eax, dword ptr [esi]
// 00483fdf  85c9                 test ecx, ecx
// 00483fe1  7404                 je 0x483fe7
// 00483fe3  3bc8                 cmp ecx, eax
// 00483fe5  7406                 je 0x483fed
// 00483fe7  ff15ace98900         call dword ptr [0x89e9ac]
// 00483fed  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00483ff1  2bfb                 sub edi, ebx
// 00483ff3  c1ff04               sar edi, 4
// 00483ff6  8b542428             mov edx, dword ptr [esp + 0x28]
// 00483ffa  8b442424             mov eax, dword ptr [esp + 0x24]
// 00483ffe  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00484002  52                   push edx
// 00484003  6a01                 push 1
// 00484005  50                   push eax
// 00484006  51                   push ecx
// 00484007  8bce                 mov ecx, esi
// 00484009  e8c2f3ffff           call 0x4833d0
// 0048400e  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00484011  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00484014  7606                 jbe 0x48401c
// 00484016  ff15ace98900         call dword ptr [0x89e9ac]
// 0048401c  8b36                 mov esi, dword ptr [esi]
// 0048401e  8bee                 mov ebp, esi
// 00484020  895c2414             mov dword ptr [esp + 0x14], ebx
// 00484024  85f6                 test esi, esi
// 00484026  751a                 jne 0x484042
// 00484028  ff15ace98900         call dword ptr [0x89e9ac]
// 0048402e  33c0                 xor eax, eax
// 00484030  c1e704               shl edi, 4
// 00484033  03fb                 add edi, ebx
// 00484035  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00484038  7713                 ja 0x48404d
// 0048403a  85f6                 test esi, esi
// 0048403c  7408                 je 0x484046
// 0048403e  8b36                 mov esi, dword ptr [esi]
// 00484040  eb06                 jmp 0x484048
// 00484042  8b06                 mov eax, dword ptr [esi]
// 00484044  ebea                 jmp 0x484030
// 00484046  33f6                 xor esi, esi
// 00484048  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0048404b  7306                 jae 0x484053
// 0048404d  ff15ace98900         call dword ptr [0x89e9ac]
// 00484053  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00484057  897804               mov dword ptr [eax + 4], edi
// 0048405a  5f                   pop edi
// 0048405b  5e                   pop esi
// 0048405c  8928                 mov dword ptr [eax], ebp
// 0048405e  5d                   pop ebp
// 0048405f  5b                   pop ebx
// 00484060  83c408               add esp, 8
// 00484063  c21000               ret 0x10
// standard library vector<pod16> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
