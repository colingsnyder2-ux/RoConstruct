// from server: 100% by auto
// roc 2009-12 004891f0  unit: Ogre::GfxClustererPart  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004891f0
//
// 004891f0  83ec08               sub esp, 8
// 004891f3  53                   push ebx
// 004891f4  55                   push ebp
// 004891f5  56                   push esi
// 004891f6  8bf1                 mov esi, ecx
// 004891f8  8b4610               mov eax, dword ptr [esi + 0x10]
// 004891fb  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004891fe  8bc8                 mov ecx, eax
// 00489200  2bcb                 sub ecx, ebx
// 00489202  57                   push edi
// 00489203  f7c1e0ffffff         test ecx, 0xffffffe0
// 00489209  7504                 jne 0x48920f
// 0048920b  33ff                 xor edi, edi
// 0048920d  eb27                 jmp 0x489236
// 0048920f  3bd8                 cmp ebx, eax
// 00489211  7606                 jbe 0x489219
// 00489213  ff1560b79800         call dword ptr [0x98b760]
// 00489219  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0048921d  8b06                 mov eax, dword ptr [esi]
// 0048921f  85c9                 test ecx, ecx
// 00489221  7404                 je 0x489227
// 00489223  3bc8                 cmp ecx, eax
// 00489225  7406                 je 0x48922d
// 00489227  ff1560b79800         call dword ptr [0x98b760]
// 0048922d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00489231  2bfb                 sub edi, ebx
// 00489233  c1ff05               sar edi, 5
// 00489236  8b542428             mov edx, dword ptr [esp + 0x28]
// 0048923a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0048923e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00489242  52                   push edx
// 00489243  6a01                 push 1
// 00489245  50                   push eax
// 00489246  51                   push ecx
// 00489247  8bce                 mov ecx, esi
// 00489249  e8d2f1ffff           call 0x488420
// 0048924e  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00489251  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00489254  7606                 jbe 0x48925c
// 00489256  ff1560b79800         call dword ptr [0x98b760]
// 0048925c  8b36                 mov esi, dword ptr [esi]
// 0048925e  8bee                 mov ebp, esi
// 00489260  895c2414             mov dword ptr [esp + 0x14], ebx
// 00489264  85f6                 test esi, esi
// 00489266  751a                 jne 0x489282
// 00489268  ff1560b79800         call dword ptr [0x98b760]
// 0048926e  33c0                 xor eax, eax
// 00489270  c1e705               shl edi, 5
// 00489273  03fb                 add edi, ebx
// 00489275  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00489278  7713                 ja 0x48928d
// 0048927a  85f6                 test esi, esi
// 0048927c  7408                 je 0x489286
// 0048927e  8b36                 mov esi, dword ptr [esi]
// 00489280  eb06                 jmp 0x489288
// 00489282  8b06                 mov eax, dword ptr [esi]
// 00489284  ebea                 jmp 0x489270
// 00489286  33f6                 xor esi, esi
// 00489288  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0048928b  7306                 jae 0x489293
// 0048928d  ff1560b79800         call dword ptr [0x98b760]
// 00489293  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00489297  897804               mov dword ptr [eax + 4], edi
// 0048929a  5f                   pop edi
// 0048929b  5e                   pop esi
// 0048929c  8928                 mov dword ptr [eax], ebp
// 0048929e  5d                   pop ebp
// 0048929f  5b                   pop ebx
// 004892a0  83c408               add esp, 8
// 004892a3  c21000               ret 0x10
// standard library vector<pod32> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
