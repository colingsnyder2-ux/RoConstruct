// from server: 100% by auto
// roc 2009-12 006c2630  unit: seg_006c0000  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c2630
//
// 006c2630  83ec08               sub esp, 8
// 006c2633  53                   push ebx
// 006c2634  55                   push ebp
// 006c2635  56                   push esi
// 006c2636  8bf1                 mov esi, ecx
// 006c2638  8b4610               mov eax, dword ptr [esi + 0x10]
// 006c263b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 006c263e  8bc8                 mov ecx, eax
// 006c2640  2bcb                 sub ecx, ebx
// 006c2642  57                   push edi
// 006c2643  f7c1e0ffffff         test ecx, 0xffffffe0
// 006c2649  7504                 jne 0x6c264f
// 006c264b  33ff                 xor edi, edi
// 006c264d  eb27                 jmp 0x6c2676
// 006c264f  3bd8                 cmp ebx, eax
// 006c2651  7606                 jbe 0x6c2659
// 006c2653  ff1560b79800         call dword ptr [0x98b760]
// 006c2659  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006c265d  8b06                 mov eax, dword ptr [esi]
// 006c265f  85c9                 test ecx, ecx
// 006c2661  7404                 je 0x6c2667
// 006c2663  3bc8                 cmp ecx, eax
// 006c2665  7406                 je 0x6c266d
// 006c2667  ff1560b79800         call dword ptr [0x98b760]
// 006c266d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 006c2671  2bfb                 sub edi, ebx
// 006c2673  c1ff05               sar edi, 5
// 006c2676  8b542428             mov edx, dword ptr [esp + 0x28]
// 006c267a  8b442424             mov eax, dword ptr [esp + 0x24]
// 006c267e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006c2682  52                   push edx
// 006c2683  6a01                 push 1
// 006c2685  50                   push eax
// 006c2686  51                   push ecx
// 006c2687  8bce                 mov ecx, esi
// 006c2689  e862f6ffff           call 0x6c1cf0
// 006c268e  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 006c2691  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 006c2694  7606                 jbe 0x6c269c
// 006c2696  ff1560b79800         call dword ptr [0x98b760]
// 006c269c  8b36                 mov esi, dword ptr [esi]
// 006c269e  8bee                 mov ebp, esi
// 006c26a0  895c2414             mov dword ptr [esp + 0x14], ebx
// 006c26a4  85f6                 test esi, esi
// 006c26a6  751a                 jne 0x6c26c2
// 006c26a8  ff1560b79800         call dword ptr [0x98b760]
// 006c26ae  33c0                 xor eax, eax
// 006c26b0  c1e705               shl edi, 5
// 006c26b3  03fb                 add edi, ebx
// 006c26b5  3b7810               cmp edi, dword ptr [eax + 0x10]
// 006c26b8  7713                 ja 0x6c26cd
// 006c26ba  85f6                 test esi, esi
// 006c26bc  7408                 je 0x6c26c6
// 006c26be  8b36                 mov esi, dword ptr [esi]
// 006c26c0  eb06                 jmp 0x6c26c8
// 006c26c2  8b06                 mov eax, dword ptr [esi]
// 006c26c4  ebea                 jmp 0x6c26b0
// 006c26c6  33f6                 xor esi, esi
// 006c26c8  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 006c26cb  7306                 jae 0x6c26d3
// 006c26cd  ff1560b79800         call dword ptr [0x98b760]
// 006c26d3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006c26d7  897804               mov dword ptr [eax + 4], edi
// 006c26da  5f                   pop edi
// 006c26db  5e                   pop esi
// 006c26dc  8928                 mov dword ptr [eax], ebp
// 006c26de  5d                   pop ebp
// 006c26df  5b                   pop ebx
// 006c26e0  83c408               add esp, 8
// 006c26e3  c21000               ret 0x10
// standard library vector<pod32> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
