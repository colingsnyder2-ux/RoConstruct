// from server: 100% by auto
// roc 2009-12 004276d0  unit: boost::any::H::?$holder  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004276d0
//
// 004276d0  83ec08               sub esp, 8
// 004276d3  53                   push ebx
// 004276d4  55                   push ebp
// 004276d5  56                   push esi
// 004276d6  8bf1                 mov esi, ecx
// 004276d8  8b4610               mov eax, dword ptr [esi + 0x10]
// 004276db  57                   push edi
// 004276dc  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004276df  8bc8                 mov ecx, eax
// 004276e1  2bcf                 sub ecx, edi
// 004276e3  f7c1f8ffffff         test ecx, 0xfffffff8
// 004276e9  7504                 jne 0x4276ef
// 004276eb  33db                 xor ebx, ebx
// 004276ed  eb27                 jmp 0x427716
// 004276ef  3bf8                 cmp edi, eax
// 004276f1  7606                 jbe 0x4276f9
// 004276f3  ff1560b79800         call dword ptr [0x98b760]
// 004276f9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004276fd  8b06                 mov eax, dword ptr [esi]
// 004276ff  85c9                 test ecx, ecx
// 00427701  7404                 je 0x427707
// 00427703  3bc8                 cmp ecx, eax
// 00427705  7406                 je 0x42770d
// 00427707  ff1560b79800         call dword ptr [0x98b760]
// 0042770d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00427711  2bdf                 sub ebx, edi
// 00427713  c1fb03               sar ebx, 3
// 00427716  8b542428             mov edx, dword ptr [esp + 0x28]
// 0042771a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0042771e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00427722  52                   push edx
// 00427723  6a01                 push 1
// 00427725  50                   push eax
// 00427726  51                   push ecx
// 00427727  8bce                 mov ecx, esi
// 00427729  e872fcffff           call 0x4273a0
// 0042772e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00427731  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00427734  7606                 jbe 0x42773c
// 00427736  ff1560b79800         call dword ptr [0x98b760]
// 0042773c  8b36                 mov esi, dword ptr [esi]
// 0042773e  8bee                 mov ebp, esi
// 00427740  897c2414             mov dword ptr [esp + 0x14], edi
// 00427744  85f6                 test esi, esi
// 00427746  7518                 jne 0x427760
// 00427748  ff1560b79800         call dword ptr [0x98b760]
// 0042774e  33c0                 xor eax, eax
// 00427750  8d3cdf               lea edi, [edi + ebx*8]
// 00427753  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00427756  7713                 ja 0x42776b
// 00427758  85f6                 test esi, esi
// 0042775a  7408                 je 0x427764
// 0042775c  8b36                 mov esi, dword ptr [esi]
// 0042775e  eb06                 jmp 0x427766
// 00427760  8b06                 mov eax, dword ptr [esi]
// 00427762  ebec                 jmp 0x427750
// 00427764  33f6                 xor esi, esi
// 00427766  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00427769  7306                 jae 0x427771
// 0042776b  ff1560b79800         call dword ptr [0x98b760]
// 00427771  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00427775  897804               mov dword ptr [eax + 4], edi
// 00427778  5f                   pop edi
// 00427779  5e                   pop esi
// 0042777a  8928                 mov dword ptr [eax], ebp
// 0042777c  5d                   pop ebp
// 0042777d  5b                   pop ebx
// 0042777e  83c408               add esp, 8
// 00427781  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
