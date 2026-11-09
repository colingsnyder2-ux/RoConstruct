// from server: 100% by auto
// roc 2010-06 00797530  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::delete_data  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00797530
//
// 00797530  83ec08               sub esp, 8
// 00797533  53                   push ebx
// 00797534  55                   push ebp
// 00797535  56                   push esi
// 00797536  8bf1                 mov esi, ecx
// 00797538  8b4610               mov eax, dword ptr [esi + 0x10]
// 0079753b  57                   push edi
// 0079753c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0079753f  8bc8                 mov ecx, eax
// 00797541  2bcf                 sub ecx, edi
// 00797543  f7c1fcffffff         test ecx, 0xfffffffc
// 00797549  7504                 jne 0x79754f
// 0079754b  33db                 xor ebx, ebx
// 0079754d  eb27                 jmp 0x797576
// 0079754f  3bf8                 cmp edi, eax
// 00797551  7606                 jbe 0x797559
// 00797553  ff150ca99e00         call dword ptr [0x9ea90c]
// 00797559  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0079755d  8b06                 mov eax, dword ptr [esi]
// 0079755f  85c9                 test ecx, ecx
// 00797561  7404                 je 0x797567
// 00797563  3bc8                 cmp ecx, eax
// 00797565  7406                 je 0x79756d
// 00797567  ff150ca99e00         call dword ptr [0x9ea90c]
// 0079756d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00797571  2bdf                 sub ebx, edi
// 00797573  c1fb02               sar ebx, 2
// 00797576  8b542428             mov edx, dword ptr [esp + 0x28]
// 0079757a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0079757e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00797582  52                   push edx
// 00797583  6a01                 push 1
// 00797585  50                   push eax
// 00797586  51                   push ecx
// 00797587  8bce                 mov ecx, esi
// 00797589  e812faffff           call 0x796fa0
// 0079758e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00797591  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00797594  7606                 jbe 0x79759c
// 00797596  ff150ca99e00         call dword ptr [0x9ea90c]
// 0079759c  8b36                 mov esi, dword ptr [esi]
// 0079759e  8bee                 mov ebp, esi
// 007975a0  897c2414             mov dword ptr [esp + 0x14], edi
// 007975a4  85f6                 test esi, esi
// 007975a6  7518                 jne 0x7975c0
// 007975a8  ff150ca99e00         call dword ptr [0x9ea90c]
// 007975ae  33c0                 xor eax, eax
// 007975b0  8d3c9f               lea edi, [edi + ebx*4]
// 007975b3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 007975b6  7713                 ja 0x7975cb
// 007975b8  85f6                 test esi, esi
// 007975ba  7408                 je 0x7975c4
// 007975bc  8b36                 mov esi, dword ptr [esi]
// 007975be  eb06                 jmp 0x7975c6
// 007975c0  8b06                 mov eax, dword ptr [esi]
// 007975c2  ebec                 jmp 0x7975b0
// 007975c4  33f6                 xor esi, esi
// 007975c6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 007975c9  7306                 jae 0x7975d1
// 007975cb  ff150ca99e00         call dword ptr [0x9ea90c]
// 007975d1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007975d5  897804               mov dword ptr [eax + 4], edi
// 007975d8  5f                   pop edi
// 007975d9  5e                   pop esi
// 007975da  8928                 mov dword ptr [eax], ebp
// 007975dc  5d                   pop ebp
// 007975dd  5b                   pop ebx
// 007975de  83c408               add esp, 8
// 007975e1  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
