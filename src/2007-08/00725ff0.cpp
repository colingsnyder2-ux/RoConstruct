// from server: 100% by auto
// roc 2007-08 00725ff0  unit: boost::thread_resource_error  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00725ff0
//
// 00725ff0  83ec08               sub esp, 8
// 00725ff3  56                   push esi
// 00725ff4  8bf1                 mov esi, ecx
// 00725ff6  8b5604               mov edx, dword ptr [esi + 4]
// 00725ff9  85d2                 test edx, edx
// 00725ffb  7504                 jne 0x726001
// 00725ffd  33c9                 xor ecx, ecx
// 00725fff  eb08                 jmp 0x726009
// 00726001  8b4e08               mov ecx, dword ptr [esi + 8]
// 00726004  2bca                 sub ecx, edx
// 00726006  c1f902               sar ecx, 2
// 00726009  85d2                 test edx, edx
// 0072600b  7424                 je 0x726031
// 0072600d  8b460c               mov eax, dword ptr [esi + 0xc]
// 00726010  2bc2                 sub eax, edx
// 00726012  c1f802               sar eax, 2
// 00726015  3bc8                 cmp ecx, eax
// 00726017  7318                 jae 0x726031
// 00726019  8b4608               mov eax, dword ptr [esi + 8]
// 0072601c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00726020  8b11                 mov edx, dword ptr [ecx]
// 00726022  8910                 mov dword ptr [eax], edx
// 00726024  83c004               add eax, 4
// 00726027  894608               mov dword ptr [esi + 8], eax
// 0072602a  5e                   pop esi
// 0072602b  83c408               add esp, 8
// 0072602e  c20400               ret 4
// 00726031  57                   push edi
// 00726032  8b7e08               mov edi, dword ptr [esi + 8]
// 00726035  3bd7                 cmp edx, edi
// 00726037  7606                 jbe 0x72603f
// 00726039  ff15d8e67700         call dword ptr [0x77e6d8]
// 0072603f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00726043  50                   push eax
// 00726044  57                   push edi
// 00726045  56                   push esi
// 00726046  8d4c2414             lea ecx, [esp + 0x14]
// 0072604a  51                   push ecx
// 0072604b  8bce                 mov ecx, esi
// 0072604d  e8fefcffff           call 0x725d50
// 00726052  5f                   pop edi
// 00726053  5e                   pop esi
// 00726054  83c408               add esp, 8
// 00726057  c20400               ret 4
// standard library vector<ptr> (function ?push_back@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
