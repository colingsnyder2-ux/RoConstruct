// from server: 100% by auto
// roc 2010-06 00482680  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00482680
//
// 00482680  83ec08               sub esp, 8
// 00482683  53                   push ebx
// 00482684  55                   push ebp
// 00482685  56                   push esi
// 00482686  8bf1                 mov esi, ecx
// 00482688  8b4610               mov eax, dword ptr [esi + 0x10]
// 0048268b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0048268e  8bc8                 mov ecx, eax
// 00482690  2bcb                 sub ecx, ebx
// 00482692  57                   push edi
// 00482693  f7c1c0ffffff         test ecx, 0xffffffc0
// 00482699  7504                 jne 0x48269f
// 0048269b  33ff                 xor edi, edi
// 0048269d  eb27                 jmp 0x4826c6
// 0048269f  3bd8                 cmp ebx, eax
// 004826a1  7606                 jbe 0x4826a9
// 004826a3  ff150ca99e00         call dword ptr [0x9ea90c]
// 004826a9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004826ad  8b06                 mov eax, dword ptr [esi]
// 004826af  85c9                 test ecx, ecx
// 004826b1  7404                 je 0x4826b7
// 004826b3  3bc8                 cmp ecx, eax
// 004826b5  7406                 je 0x4826bd
// 004826b7  ff150ca99e00         call dword ptr [0x9ea90c]
// 004826bd  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004826c1  2bfb                 sub edi, ebx
// 004826c3  c1ff06               sar edi, 6
// 004826c6  8b542428             mov edx, dword ptr [esp + 0x28]
// 004826ca  8b442424             mov eax, dword ptr [esp + 0x24]
// 004826ce  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004826d2  52                   push edx
// 004826d3  6a01                 push 1
// 004826d5  50                   push eax
// 004826d6  51                   push ecx
// 004826d7  8bce                 mov ecx, esi
// 004826d9  e882fbffff           call 0x482260
// 004826de  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004826e1  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 004826e4  7606                 jbe 0x4826ec
// 004826e6  ff150ca99e00         call dword ptr [0x9ea90c]
// 004826ec  8b36                 mov esi, dword ptr [esi]
// 004826ee  8bee                 mov ebp, esi
// 004826f0  895c2414             mov dword ptr [esp + 0x14], ebx
// 004826f4  85f6                 test esi, esi
// 004826f6  751a                 jne 0x482712
// 004826f8  ff150ca99e00         call dword ptr [0x9ea90c]
// 004826fe  33c0                 xor eax, eax
// 00482700  c1e706               shl edi, 6
// 00482703  03fb                 add edi, ebx
// 00482705  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00482708  7713                 ja 0x48271d
// 0048270a  85f6                 test esi, esi
// 0048270c  7408                 je 0x482716
// 0048270e  8b36                 mov esi, dword ptr [esi]
// 00482710  eb06                 jmp 0x482718
// 00482712  8b06                 mov eax, dword ptr [esi]
// 00482714  ebea                 jmp 0x482700
// 00482716  33f6                 xor esi, esi
// 00482718  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0048271b  7306                 jae 0x482723
// 0048271d  ff150ca99e00         call dword ptr [0x9ea90c]
// 00482723  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00482727  897804               mov dword ptr [eax + 4], edi
// 0048272a  5f                   pop edi
// 0048272b  5e                   pop esi
// 0048272c  8928                 mov dword ptr [eax], ebp
// 0048272e  5d                   pop ebp
// 0048272f  5b                   pop ebx
// 00482730  83c408               add esp, 8
// 00482733  c21000               ret 0x10
// standard library vector<pod64> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
