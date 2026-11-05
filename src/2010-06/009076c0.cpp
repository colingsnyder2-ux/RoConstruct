// from server: 100% by auto
// roc 2010-06 009076c0  unit: RBX::RbxParticleEmitter  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009076c0
//
// 009076c0  83ec08               sub esp, 8
// 009076c3  53                   push ebx
// 009076c4  55                   push ebp
// 009076c5  56                   push esi
// 009076c6  8bf1                 mov esi, ecx
// 009076c8  8b4610               mov eax, dword ptr [esi + 0x10]
// 009076cb  57                   push edi
// 009076cc  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 009076cf  8bc8                 mov ecx, eax
// 009076d1  2bcf                 sub ecx, edi
// 009076d3  f7c1f8ffffff         test ecx, 0xfffffff8
// 009076d9  7504                 jne 0x9076df
// 009076db  33db                 xor ebx, ebx
// 009076dd  eb27                 jmp 0x907706
// 009076df  3bf8                 cmp edi, eax
// 009076e1  7606                 jbe 0x9076e9
// 009076e3  ff150ca99e00         call dword ptr [0x9ea90c]
// 009076e9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 009076ed  8b06                 mov eax, dword ptr [esi]
// 009076ef  85c9                 test ecx, ecx
// 009076f1  7404                 je 0x9076f7
// 009076f3  3bc8                 cmp ecx, eax
// 009076f5  7406                 je 0x9076fd
// 009076f7  ff150ca99e00         call dword ptr [0x9ea90c]
// 009076fd  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00907701  2bdf                 sub ebx, edi
// 00907703  c1fb03               sar ebx, 3
// 00907706  8b542428             mov edx, dword ptr [esp + 0x28]
// 0090770a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0090770e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00907712  52                   push edx
// 00907713  6a01                 push 1
// 00907715  50                   push eax
// 00907716  51                   push ecx
// 00907717  8bce                 mov ecx, esi
// 00907719  e812fbffff           call 0x907230
// 0090771e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00907721  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00907724  7606                 jbe 0x90772c
// 00907726  ff150ca99e00         call dword ptr [0x9ea90c]
// 0090772c  8b36                 mov esi, dword ptr [esi]
// 0090772e  8bee                 mov ebp, esi
// 00907730  897c2414             mov dword ptr [esp + 0x14], edi
// 00907734  85f6                 test esi, esi
// 00907736  7518                 jne 0x907750
// 00907738  ff150ca99e00         call dword ptr [0x9ea90c]
// 0090773e  33c0                 xor eax, eax
// 00907740  8d3cdf               lea edi, [edi + ebx*8]
// 00907743  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00907746  7713                 ja 0x90775b
// 00907748  85f6                 test esi, esi
// 0090774a  7408                 je 0x907754
// 0090774c  8b36                 mov esi, dword ptr [esi]
// 0090774e  eb06                 jmp 0x907756
// 00907750  8b06                 mov eax, dword ptr [esi]
// 00907752  ebec                 jmp 0x907740
// 00907754  33f6                 xor esi, esi
// 00907756  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00907759  7306                 jae 0x907761
// 0090775b  ff150ca99e00         call dword ptr [0x9ea90c]
// 00907761  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00907765  897804               mov dword ptr [eax + 4], edi
// 00907768  5f                   pop edi
// 00907769  5e                   pop esi
// 0090776a  8928                 mov dword ptr [eax], ebp
// 0090776c  5d                   pop ebp
// 0090776d  5b                   pop ebx
// 0090776e  83c408               add esp, 8
// 00907771  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
