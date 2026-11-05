// from server: 100% by auto
// roc 2010-06 00542450  unit: RBX::AggregatingSceneManager  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00542450
//
// 00542450  83ec08               sub esp, 8
// 00542453  53                   push ebx
// 00542454  55                   push ebp
// 00542455  56                   push esi
// 00542456  8bf1                 mov esi, ecx
// 00542458  8b4610               mov eax, dword ptr [esi + 0x10]
// 0054245b  57                   push edi
// 0054245c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0054245f  8bc8                 mov ecx, eax
// 00542461  2bcf                 sub ecx, edi
// 00542463  f7c1fcffffff         test ecx, 0xfffffffc
// 00542469  7504                 jne 0x54246f
// 0054246b  33db                 xor ebx, ebx
// 0054246d  eb27                 jmp 0x542496
// 0054246f  3bf8                 cmp edi, eax
// 00542471  7606                 jbe 0x542479
// 00542473  ff150ca99e00         call dword ptr [0x9ea90c]
// 00542479  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0054247d  8b06                 mov eax, dword ptr [esi]
// 0054247f  85c9                 test ecx, ecx
// 00542481  7404                 je 0x542487
// 00542483  3bc8                 cmp ecx, eax
// 00542485  7406                 je 0x54248d
// 00542487  ff150ca99e00         call dword ptr [0x9ea90c]
// 0054248d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00542491  2bdf                 sub ebx, edi
// 00542493  c1fb02               sar ebx, 2
// 00542496  8b542428             mov edx, dword ptr [esp + 0x28]
// 0054249a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0054249e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005424a2  52                   push edx
// 005424a3  6a01                 push 1
// 005424a5  50                   push eax
// 005424a6  51                   push ecx
// 005424a7  8bce                 mov ecx, esi
// 005424a9  e8e2f6ffff           call 0x541b90
// 005424ae  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005424b1  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 005424b4  7606                 jbe 0x5424bc
// 005424b6  ff150ca99e00         call dword ptr [0x9ea90c]
// 005424bc  8b36                 mov esi, dword ptr [esi]
// 005424be  8bee                 mov ebp, esi
// 005424c0  897c2414             mov dword ptr [esp + 0x14], edi
// 005424c4  85f6                 test esi, esi
// 005424c6  7518                 jne 0x5424e0
// 005424c8  ff150ca99e00         call dword ptr [0x9ea90c]
// 005424ce  33c0                 xor eax, eax
// 005424d0  8d3c9f               lea edi, [edi + ebx*4]
// 005424d3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 005424d6  7713                 ja 0x5424eb
// 005424d8  85f6                 test esi, esi
// 005424da  7408                 je 0x5424e4
// 005424dc  8b36                 mov esi, dword ptr [esi]
// 005424de  eb06                 jmp 0x5424e6
// 005424e0  8b06                 mov eax, dword ptr [esi]
// 005424e2  ebec                 jmp 0x5424d0
// 005424e4  33f6                 xor esi, esi
// 005424e6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 005424e9  7306                 jae 0x5424f1
// 005424eb  ff150ca99e00         call dword ptr [0x9ea90c]
// 005424f1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005424f5  897804               mov dword ptr [eax + 4], edi
// 005424f8  5f                   pop edi
// 005424f9  5e                   pop esi
// 005424fa  8928                 mov dword ptr [eax], ebp
// 005424fc  5d                   pop ebp
// 005424fd  5b                   pop ebx
// 005424fe  83c408               add esp, 8
// 00542501  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
